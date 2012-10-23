{$DEFINE DEBUG}
{*******************************************************}
{                                                       }
{       ׷��ϵͳ                                        }
{                                                       }
{       ��Ȩ���� (C) 2010 ����������                    }
{                                                       }
{*******************************************************}
unit ReadThread;

interface

uses
  Classes, SysUtils, Windows, Main, mmsystem, IniOptionsUnit, IDCardClass, RyxxClass;

type

  TReadThread = class(TThread)
  private
    { Private declarations }
    IDCard : TIDCardClass;
    FRecno : Integer;
    FRyxx : TRyxx;
  private
    function GetCardmsg(const cardmsg : TIDCardData;const filename:string): TIDCardClass;
    procedure PlayHintSound(const Recno :Integer); overload;
    procedure PlayHintSound(const ryxx :TRyxx); overload;
    //function Search(const idcardno : string): Integer; //����-1��û�в鵽����������н�����أ�����洢��Recno��
    procedure Search ;   //����-1��û�в鵽����������н�����أ�����洢��FRecno��FRyxx��
    procedure ShowMsg;
  protected
    procedure Execute; override;
  end;

implementation
uses
  LogHelperUnit, SQLiteTable3, QGraphics;
{ Important: Methods and properties of objects in visual components can only be
used in a method called using Synchronize, for example,

    Synchronize(UpdateCaption);

and UpdateCaption could look like,

  procedure TReadThread.UpdateCaption;
  begin
    Form1.Caption := 'Updated in a thread';
  end; }

{ TReadThread }

procedure TReadThread.Execute;
var

  pucIIN: array[0..3] of Byte;
  pucSN: array[0..7] of Byte;
{$IFDEF DEBUG}
  pucPHMsg : array[0..1023] of Byte;
  fsPhoto : TFileStream;
{$ELSE}
  UnTypedFile: file of TIDCardData;
{$ENDIF}
  uiCHMsgLen, uiPHMsgLen: Cardinal;
  cardmsg: TIDCardData;
  strFilename: string;
begin

  strFilename := ExtractFilePath(ParamStr(0)) + cstInfoFileName;
  while (not Terminated) do
  begin
        if SDT_StartFindIDCard(Port, @pucIIN, cstIfOpen) = SDT_FINDCARD_OK then
        begin
          if SDT_SelectIDCard(Port, @pucSN, cstIfOpen) = SDT_SUCCESS then
          begin
              if SDT_ReadBaseMsg(Port, @cardmsg, @uiCHMsgLen, @pucPHMsg, @uiPHMsgLen, cstIfOpen) = SDT_SUCCESS then
              begin
{$IFDEF DEBUG}
                strFilename := ExtractFilePath(ParamStr(0)) + cstPhotoFileName;
                fsPhoto := TFileStream.Create(strFilename,fmCreate);
                try
                  fsPhoto.Position:=0;
                  fsPhoto.Write(pucPHMsg,uiPHMsgLen);
                finally
                  FreeAndNil(fsPhoto);
                end;
{$ELSE}
                if fileExists(strFilename) then
                begin
                  assignfile(UnTypedFile, strFilename);
                  reset(UnTypedFile);
                  try
                    if not Eof(UnTypedFile) then
                      read(UnTypedFile, cardmsg);
                  finally
                    CloseFile(UnTypedFile);
                  end;
                end;
{$ENDIF}
                IDCard := GetCardmsg(cardmsg,cstPhotoFileName);
                try
                  Synchronize(ShowMsg);
                  Synchronize(Search); 
                  PlayHintSound(FRyxx);
                  LogHelper.Write(IDCard.Idcardno);
                finally
                  FreeAndNil(IDCard);
                  FreeAndNil(FRyxx);
                end;

              end;
            end;
          end;
    Sleep(IniOptions.SpanInSecs);
  end;
end;

procedure TReadThread.ShowMsg;
begin
  if IDCard <> nil then
  begin
    with frmMain do
    begin
      edtName.Text := IDCard.Name;
      edtSex.Text := IDCard.sex;
      edtNation.Text := IDCard.Nation;
      edtBorn.Text := IDCard.Born;
      edtAddress.Text := IDCard.Address;
      edtIDCardNO.Text := IDCard.Idcardno;
      edtUserLifeEnd.Text := IDCard.UserLifeEnd;
      edtGrantdept.Text := IDCard.Grantdept;
      if fileExists(cstBmpFileName) then
      begin
        with img1 do
        begin
          picture.bitmap.loadfromfile(cstBmpFileName);
          picture.bitmap.transparent := true;
          picture.bitmap.transparentcolor := picture.bitmap.canvas.pixels[5, 3];
        end;
      end;
    end;
  end;
end;



procedure TReadThread.Search;
var
  strSQL : string;
  slutb : TSQLiteTable;
  iRow : Integer;
begin
  FRyxx := nil;
  FRecno := -1;


  frmMain.ClearstrnGrid;
  strSQL := UTF8Encode(Format(IniOptions.SQL, [IDCard.Idcardno]));
  slutb := CjryDb.GetTable(strSQL);
  try
    with slutb do
    begin
      frmMain.strngrdResult.RowCount := slutb.RowCount +1;
      if RowCount > 0 then
      begin
        FRecno := slutb.RowCount;

        FRyxx := TRyxx.Create();
        iRow := 1;
        while not slutb.EOF do
        begin
          with FRyxx do
          begin
            if((Level ='') or (Level>UTF8Decode(FieldAsString(FieldIndex['Level']))) ) then   //������Ա�ļ������
            begin
              Id	:=	UTF8Decode(FieldAsString(FieldIndex['Id']));
              Name	:=	UTF8Decode(FieldAsString(FieldIndex['Name']));
              IdCardNo	:=	UTF8Decode(FieldAsString(FieldIndex['IdCardNo']));
              Sex	:=	UTF8Decode(FieldAsString(FieldIndex['Sex']));
              Height	:=	UTF8Decode(FieldAsString(FieldIndex['Height']));
              Sponsor	:=	UTF8Decode(FieldAsString(FieldIndex['Sponsor']));
              Contact	:=	UTF8Decode(FieldAsString(FieldIndex['Contact']));
              Phone	:=	UTF8Decode(FieldAsString(FieldIndex['Phone']));
              Number	:=	UTF8Decode(FieldAsString(FieldIndex['Number']));
              Level	:=	UTF8Decode(FieldAsString(FieldIndex['Level']));
              Category	:=	UTF8Decode(FieldAsString(FieldIndex['Category']));

            end;
          end;
          with frmMain.strngrdResult do
          begin
            Cells[0,iRow] := IntToStr(iRow);  
            Cells[1,iRow] := UTF8Decode(FieldAsString(FieldIndex['Name']));
            Cells[2,iRow] := UTF8Decode(FieldAsString(FieldIndex['IdCardNo']));
            Cells[3,iRow] := UTF8Decode(FieldAsString(FieldIndex['Sex']));
            Cells[4,iRow] := UTF8Decode(FieldAsString(FieldIndex['Height']));
            Cells[5,iRow] := UTF8Decode(FieldAsString(FieldIndex['Sponsor']));
            Cells[6,iRow] := UTF8Decode(FieldAsString(FieldIndex['Contact']));
            Cells[7,iRow] := UTF8Decode(FieldAsString(FieldIndex['Phone']));
            Cells[8,iRow] := UTF8Decode(FieldAsString(FieldIndex['Number']));
            Cells[9,iRow] := UTF8Decode(FieldAsString(FieldIndex['Level']));
            Cells[10,iRow] := UTF8Decode(FieldAsString(FieldIndex['Category']));
          end;
          Inc(iRow);
          Next;
        end;
      end;
    end;
  finally
    FreeAndNil(slutb);
  end;
end;

{-------------------------------------------------------------------------------
  ������:    TReadThread.GetCardmsg
  ����:      Administrator
  ����:      2010.06.12
  ����:      cardmsg : TIDCardData
  ����ֵ:    ��
-------------------------------------------------------------------------------}
function TReadThread.GetCardmsg(const cardmsg : TIDCardData; const filename:string) : TIDCardClass; 
begin
  GetBmp(PChar(filename), 2);
  Result := TIDCardClass.Create(cardmsg);
end;

{-------------------------------------------------------------------------------
  ������:    TReadThread.PlaySound
  ����:      Administrator
  ����:      2010.06.12
  ����:      Recno :Integer ��ѯ���ؽ������>0��ʾ�н��
  ����ֵ:    ��
-------------------------------------------------------------------------------}
procedure TReadThread.PlayHintSound(const Recno :Integer);
begin
  if Recno>0 then
    PlaySound(PChar(IniOptions.AlarmFileA), 0, 0)
  else
    if IniOptions.PlayPassedSound then
        PlaySound(PChar(IniOptions.PassedSoundFile), 0, 0);
end;

procedure TReadThread.PlayHintSound(const ryxx :TRyxx);
var
  soundfile : string;
begin
  soundfile := IniOptions.PassedSoundFile;        //Ĭ�ϲ���ͨ������
  if (ryxx<>nil) then
  begin
    soundfile := IniOptions.AlarmFileA;
    with ryxx do
    begin

      if LowerCase(Level) = 'a' then
        soundfile := IniOptions.AlarmFileB
      else
        if LowerCase(Level) = 'b' then
          soundfile := IniOptions.AlarmFileB
        else
          if LowerCase(Level) = 'c' then
            soundfile := IniOptions.AlarmFileC 
        else
            soundfile := IniOptions.AlarmFileB ;
    end;
  end;
  if (IniOptions.PlaySound) then
    PlaySound(PChar(soundfile), 0, 0);
end;
 
end.

