{****************************************************************************
USAGE:
  Upgrader4.exe [exename] +[arguments][upgrade method ID]
  [exename] is original exe-file with full path (without quotes)
  [arguments] is command-line arguments required for restarting of main app
  [upgrade method ID] "0" or "1". If "1", then we should copy setup program
                      to the temporary folder and start it from there
                      skipping normal upgrade.
EXAMPLE:
  Upgrader4.exe c:\Program Files\My Company\My Program\Prog.exe +/restart1
-----------------------------------------------------------------------------
How does it works?
 1. Read queue file (Temp\UpgraderQueue.txt) to locate files outside of
    main Program directory.
 2. Locate program directory by exe-name transmitted as command-line parameter
 2.1. Check whether the AutoUpgrader uses the external setup program (#method=1)
 2.2. Split the file name and parameters
 2.3. Split the file name and path
 3. Test whether an exe-file exists + get the filename with correct charcase
 4. Awaiting for termination of the main program
 5. Test whether newer (downloaded) exe-file exists
 6. Rename/replace downloaded files outside of main program directory
 7. Find all (.uTMP) files downloaded to main program directory
 7.1. If this is executable AND newest exe still not found -- trying to
      use another suitable EXE. (This may happends if program was renamed
      by user, or local update should be done by external setup.)
 7.2. Rename .uTMP file to its normal name
 8. Re-execute main program (or setup file).
 9. Delete the queue file (if exists)
 10. IF the local update should be done by external setup THEN (else terminate)
 10.1. Wait until termination of setup program
 10.2. Delete the setup (we don't need it anymore after installation?)
 10.3. Restart the original main app
-----------------------------------------------------------------------------
(c) 2001-2007, Utilmind Solutions (http://www.utilmind.com)
Built with Virtual Pascal v2.1 (http://www.vpascal.com), although can be easily
recompiled with ANY win32 version of Delphi. (Just rename this .PAS to .DPR and
go on!)
NOTE: must be compiled to Win32 platform and linked as GUI application.
*****************************************************************************}
{$Optimise+}  // Optimisation enabled
{$SmartLink+} // Decrease executable size due to smart linking
{$Speed-}     // Optimisation for size (speed is not important)
{$AlignCode-} // Don't align code
{$AlignData-} // Don't align data
{$H+}         // Huge strings (PChar) allowed
{$X+}         // Extended syntax allowed (discard results of functions)
{$D-}         // Debug information disabled
{$S-}         // Stack overflow checking disabled
{$R VistaUAC.res} // embed the UAC manifest into application's executable
program Upgrader4;

uses Windows;

var
  I: Integer;
  ExeFound: Boolean = False;
  ExeFileName: String = '';
  OriginalExeFileName,
  ExePath, ExeName, Params, QueueFile, Queue, St: String;
  UseExternalSetup: Boolean;
  FindHandle: THandle;
  FindData: TWin32FindData;

  { reads file and returns it as string (see also HTTPReadString from acHTTP unit) }
  function FileReadString(const FileName: String): String;
  var
    FileHandle: hFile;
    FileSize, Dummy: DWord;
    Buffer: PChar;
  begin
    Result := '';
    FileHandle := CreateFile(PChar(FileName), GENERIC_READ, FILE_SHARE_READ or FILE_SHARE_WRITE, nil,
                             OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if FileHandle <> INVALID_HANDLE_VALUE then
     begin
      FileSize := GetFileSize(FileHandle, @Dummy);
      GetMem(Buffer, FileSize);
      try
        if ReadFile(FileHandle, Buffer^, FileSize, Dummy, nil) then
         begin
          SetLength(Result, FileSize);
          Move(Buffer^, Result[1], FileSize);
         end;
      finally
        FreeMEM(Buffer);
      end;
      CloseHandle(FileHandle);
     end;
  end;

  function GetTempDir: String;
  var
    PC: Array[0..MAX_PATH + 1] of Char;
  begin
    GetTempPath(MAX_PATH, PC);
    Result := PC;
    // include trailing backslash
    if (Result[Length(Result)] <> '\') then
      Result := Result + '\'
  end;

  procedure WaitForTermination;
  var
    Msg: TMsg;
    FileHandle: THandle;
//    iPriorityClass,
    iPriority: Integer;
  begin
//    SetPriorityClass(GetCurrentProcess, IDLE_PRIORITY_CLASS);
    SetThreadPriority(GetCurrentThread, THREAD_PRIORITY_LOWEST);
    repeat
      Sleep(1);
      { 'Application.ProcessMessages' emulation }
      while PeekMessage(Msg, 0, 0, 0, PM_REMOVE) do
      begin
        TranslateMessage(Msg);
        DispatchMessage(Msg);
      end;
      FileHandle := CreateFile(PChar(ExeFileName), GENERIC_WRITE, FILE_SHARE_WRITE, nil,
                               OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    until FileHandle <> INVALID_HANDLE_VALUE;
    SetThreadPriority(GetCurrentThread, iPriority);
//    SetPriorityClass(GetCurrentProcess, iPriorityClass);
    CloseHandle(FileHandle);
  end;

  procedure StartMainApp;
  begin
    WinExec(PChar(ExeFileName + ' ' + Params), SW_SHOWNORMAL);
  end;

begin
  I := ParamCount;
  if I = 0 then
  begin
    MessageBox(0, PChar('Self-upgrading mechanism for AutoUpgrader component.'#13#10 +
                        '(c) 1999-2007, Utilmind Solutions (www.appcontrols.com)'),
               'Upgrader v4.0', MB_OK or MB_ICONINFORMATION);
    Halt;
  end;

  { 1. Read queue file (Temp\UpgraderQueue.txt) to locate files outside of main Program directory. }
  QueueFile := GetTempDir + 'UpgraderQueue.txt';
  Queue := FileReadString(QueueFile);

  { 2. Locate program directory by exe-name transmitted as command-line parameter }
  for I := 1 to I do ExeFileName := ExeFileName + ParamStr(I) + #32;

  { 2.1. Check whether the AutoUpgrader uses the external setup program (#method=1) }
  UseExternalSetup := ExeFileName[Length(ExeFileName) - 1] = '1';

  { 2.2. split the file name and parameters }
  I := Pos('+', ExeFileName);
  if I <> 0 then
  begin
    Params := Copy(ExeFileName, I + 1, Length(ExeFileName) - I - 2); // -1
    SetLength(ExeFileName, I - 1); // add 1 byte for upgrade methid ID
  end;


  { 2.3. split the file path and name }
  for I := Length(ExeFileName) downto 1 do
   if ExeFileName[I] = '\' then
   begin
     ExePath := Copy(ExeFileName, 1, I);
     Break;
   end;

  { 3. test whether an exe-file exists + getting the filename in correct charcase }
  FindHandle := FindFirstFile(PChar(ExeFileName), FindData);
  if FindHandle <> INVALID_HANDLE_VALUE then
  begin
    ExeName := FindData.cFileName; { exe-name match case }
    FindClose(FindHandle);

    { 4. awaiting for its termination }
    WaitForTermination;
  end
  else
    { if main app already terminated -- getting the file name from argument string }
    ExeName := Copy(ExeFileName, I + 1, Length(ExeFileName) - I);

  { 5. Test whether newer (downloaded) exe-file exists }
  FindHandle := FindFirstFile(PChar(ExeFileName + '.uTMP'), FindData);
  if FindHandle <> INVALID_HANDLE_VALUE then
  begin
    FindClose(FindHandle);
    ExeFound := True;
  end;

  { 6. Rename/replace downloaded files outside of main program directory }
  if Queue <> '' then
    repeat
      I := Pos(#13#10, Queue);
      if I <> 0 then
      begin
        St := Copy(Queue, 1, I - 1);
        Queue := Copy(Queue, I + 2, Length(Queue) - I);
      end
      else
        St := Queue;

      { rename and normalize attributes }
      if MoveFileEx(PChar(St + '.uTMP'), PChar(St), MOVEFILE_REPLACE_EXISTING) then
        SetFileAttributes(PChar(St), FILE_ATTRIBUTE_ARCHIVE);
    until I = 0;

  { 7. Find all (.uTMP) files downloaded to main program directory }
  FindHandle := FindFirstFile(PChar(ExePath + '*.uTMP'), FindData);
  if FindHandle <> INVALID_HANDLE_VALUE then
  begin
    repeat
      St := FindData.cFileName;
      St := Copy(St, 1, Length(St) - 5);
      { 7.1. If this is executable AND newer exe still not found --
             trying to use another suitable EXE (this may happends
             if program was renamed by user, or local update done by
             external setup) }
      if not ExeFound and (Copy(St, Length(St) - 2, 3) = 'exe') then
       begin
        if not UseExternalSetup then
          St := ExeName
        else
         begin
          OriginalExeFileName := ExeFileName;
          ExeFileName := ExePath + St;
         end;
        ExeFound := True;
       end;

      { 7.2. Rename .uTMP file to its normal name. }
      St := ExePath + St;
      { delete old file first }
      SetFileAttributes(PChar(St), FILE_ATTRIBUTE_NORMAL);
      DeleteFile(PChar(St));
      { rename! }
      MoveFile(PChar(ExePath + FindData.cFileName), PChar(St));
      { set normal file attributes (unhide it) }

      if UseExternalSetup and (St = ExeFileName) then
        SetFileAttributes(PChar(St), FILE_ATTRIBUTE_HIDDEN or FILE_ATTRIBUTE_ARCHIVE)
      else
        SetFileAttributes(PChar(St), FILE_ATTRIBUTE_ARCHIVE);
    until not FindNextFile(FindHandle, FindData);

    FindClose(FindHandle);
  end;

  { 8. Restart main program (or setup-file) }
  StartMainApp;

  { 9. Delete the queue file (if exists) }
  DeleteFile(PChar(QueueFile));

  { 10. IF the local update should be done by external setup THEN (else terminate) }
  if UseExternalSetup then
   begin
    { 10.1. Wait until termination of setup program }
    WaitForTermination;

    { 10.2. Delete the setup (we don't need it anymore after installation?) }
    DeleteFile(PChar(ExeFileName));

    { 10.3. Restart the original main app }
    ExeFileName := OriginalExeFileName;
    StartMainApp;
   end;
end.
