unit DBVersionUnit;

interface

uses
  Classes, SysUtils, IniFiles, Forms, Windows;

const
  csIniDatabaseVersionSection = 'DatabaseVersion';

  {Section: DatabaseVersion}
  csIniDatabaseVersionVersion = 'Version';

type
  TDBVersion = class(TObject)
  private
    {Section: DatabaseVersion}
    FDatabaseVersionVersion: string;
  public
    procedure LoadSettings(Ini: TIniFile);
    procedure SaveSettings(Ini: TIniFile);
    
    procedure LoadFromFile(const FileName: string);
    procedure SaveToFile(const FileName: string);

    {Section: DatabaseVersion}
    property DatabaseVersionVersion: string read FDatabaseVersionVersion write FDatabaseVersionVersion;
  end;

var
  DBVersion: TDBVersion = nil;

implementation

procedure TDBVersion.LoadSettings(Ini: TIniFile);
begin
  if Ini <> nil then
  begin
    {Section: DatabaseVersion}
    FDatabaseVersionVersion := Ini.ReadString(csIniDatabaseVersionSection, csIniDatabaseVersionVersion, '2010.6.12');
  end;
end;

procedure TDBVersion.SaveSettings(Ini: TIniFile);
begin
  if Ini <> nil then
  begin
    {Section: DatabaseVersion}
    Ini.WriteString(csIniDatabaseVersionSection, csIniDatabaseVersionVersion, FDatabaseVersionVersion);
  end;
end;

procedure TDBVersion.LoadFromFile(const FileName: string);
var
  Ini: TIniFile;
begin
  if FileExists(FileName) then
  begin
    Ini := TIniFile.Create(FileName);
    try
      LoadSettings(Ini);
    finally
      Ini.Free;
    end;
  end;
end;

procedure TDBVersion.SaveToFile(const FileName: string);
var
  Ini: TIniFile;
begin
  Ini := TIniFile.Create(FileName);
  try
    SaveSettings(Ini);
  finally
    Ini.Free;
  end;
end;

initialization
  DBVersion := TDBVersion.Create;

finalization
  DBVersion.Free;

end.

