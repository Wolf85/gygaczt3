unit IniOptionsUnit;

interface

uses
  Classes, SysUtils, IniFiles, Forms, Windows;

const
  csIniProgramSetSection = 'ProgramSet';

  {Section: ProgramSet}
  csIniProgramSetVersion = 'Version';
  csIniProgramSetConnString = 'ConnString';
  csIniProgramSetDataSource = 'Data Source';
  csIniProgramSetSQL = 'SQL';
  csIniProgramSetSQLXm = 'SQLXm';
  csIniProgramSetSQLNumber = 'SQLNumber';
  csIniProgramSetViewFields = 'ViewFields';
  csIniProgramSetViewFieldsWidth = 'ViewFieldsWidth';
  csIniProgramSetPlaySound = 'PlaySound';
  csIniProgramSetAlarmFileA = 'AlarmFileA';
  csIniProgramSetAlarmFileB = 'AlarmFileB';
  csIniProgramSetAlarmFileC = 'AlarmFileC';
  csIniProgramSetPlayPassedSound = 'PlayPassedSound';
  csIniProgramSetPassedSoundFile = 'PassedSoundFile';
  csIniProgramSetSpanInSecs = 'SpanInSecs';
  csIniProgramSetServer = 'Server';
  csIniProgramSetLogFile = 'LogFile';
  csIniProgramSetCreateLogTable = 'CreateLogTable';
  csIniProgramSetLogSQL = 'LogSQL';
  csIniProgramSetLogDays = 'LogDays';
  csIniProgramSetStatisIDCardNoSQL = 'StatisIDCardNoSQL';
  csIniProgramSetStatisDateTimeSQL = 'StatisDateTimeSQL';

type
  TIniOptions = class(TObject)
  private
    {Section: ProgramSet}
    FProgramSetVersion: string;
    FProgramSetConnString: string;
    FProgramSetDataSource: string;
    FProgramSetSQL: string;
    FProgramSetSQLXm: string;
    FProgramSetSQLNumber: string;
    FProgramSetViewFields: string;
    FProgramSetViewFieldsWidth: string;
    FProgramSetPlaySound: Boolean;
    FProgramSetAlarmFileA: string;
    FProgramSetAlarmFileB: string;
    FProgramSetAlarmFileC: string;
    FProgramSetPlayPassedSound: Boolean;
    FProgramSetPassedSoundFile: string;
    FProgramSetSpanInSecs: Integer;
    FProgramSetServer: string;
    FProgramSetLogFile: string;
    FProgramSetCreateLogTable: string;
    FProgramSetLogSQL: string;
    FProgramSetLogDays: Integer;
    FProgramSetStatisIDCardNoSQL: string;
    FProgramSetStatisDateTimeSQL: string;
  public
    procedure LoadSettings(Ini: TIniFile);
    procedure SaveSettings(Ini: TIniFile);
    
    procedure LoadFromFile(const FileName: string);
    procedure SaveToFile(const FileName: string);

    {Section: ProgramSet}
    property Version: string read FProgramSetVersion write FProgramSetVersion;
    property ConnString: string read FProgramSetConnString write FProgramSetConnString;
    property DataSource: string read FProgramSetDataSource write FProgramSetDataSource;
    property SQL: string read FProgramSetSQL write FProgramSetSQL;
    property SQLXm: string read FProgramSetSQLXm write FProgramSetSQLXm;
    property SQLNumber: string read FProgramSetSQLNumber write FProgramSetSQLNumber;
    property ViewFields: string read FProgramSetViewFields write FProgramSetViewFields;
    property ViewFieldsWidth: string read FProgramSetViewFieldsWidth write FProgramSetViewFieldsWidth;
    property PlaySound: Boolean read FProgramSetPlaySound write FProgramSetPlaySound;
    property AlarmFileA: string read FProgramSetAlarmFileA write FProgramSetAlarmFileA;
    property AlarmFileB: string read FProgramSetAlarmFileB write FProgramSetAlarmFileB;
    property AlarmFileC: string read FProgramSetAlarmFileC write FProgramSetAlarmFileC;
    property PlayPassedSound: Boolean read FProgramSetPlayPassedSound write FProgramSetPlayPassedSound;
    property PassedSoundFile: string read FProgramSetPassedSoundFile write FProgramSetPassedSoundFile;
    property SpanInSecs: Integer read FProgramSetSpanInSecs write FProgramSetSpanInSecs;
    property Server: string read FProgramSetServer write FProgramSetServer;
    property LogFile: string read FProgramSetLogFile write FProgramSetLogFile;
    property CreateLogTable: string read FProgramSetCreateLogTable write FProgramSetCreateLogTable;
    property LogSQL: string read FProgramSetLogSQL write FProgramSetLogSQL;
    property LogDays: Integer read FProgramSetLogDays write FProgramSetLogDays;
    property StatisIDCardNoSQL: string read FProgramSetStatisIDCardNoSQL write FProgramSetStatisIDCardNoSQL;
    property StatisDateTimeSQL: string read FProgramSetStatisDateTimeSQL write FProgramSetStatisDateTimeSQL;
  end;

var
  IniOptions: TIniOptions = nil;

implementation

procedure TIniOptions.LoadSettings(Ini: TIniFile);
begin
  if Ini <> nil then
  begin
    {Section: ProgramSet}
    FProgramSetVersion := Ini.ReadString(csIniProgramSetSection, csIniProgramSetVersion, '02.00.00');
    FProgramSetConnString := Ini.ReadString(csIniProgramSetSection, csIniProgramSetConnString, '');
    FProgramSetDataSource := Ini.ReadString(csIniProgramSetSection, csIniProgramSetDataSource, 'cjry.db');
    FProgramSetSQL := Ini.ReadString(csIniProgramSetSection, csIniProgramSetSQL, 'SELECT xm as 姓名, number as 证件号码, jb, lb as 案件类别, ztbh as 在逃编号 FROM ryxx where number= ''%s''');
    FProgramSetSQLXm := Ini.ReadString(csIniProgramSetSection, csIniProgramSetSQLXm, 'SELECT xm as 姓名, number as 证件号码, jb, lb as 案件类别, ztbh as 在逃编号 FROM ryxx where xm Like ''%s''');
    FProgramSetSQLNumber := Ini.ReadString(csIniProgramSetSection, csIniProgramSetSQLNumber, 'SELECT xm as 姓名, number as 证件号码, jb, lb as 案件类别, ztbh as 在逃编号 FROM ryxx where xm Like ''%s''');
    FProgramSetViewFields := Ini.ReadString(csIniProgramSetSection, csIniProgramSetViewFields, '序号,姓名,证件号码,案件类别,在逃编号');
    FProgramSetViewFieldsWidth := Ini.ReadString(csIniProgramSetSection, csIniProgramSetViewFieldsWidth, '50,100,200,160,200');
    FProgramSetPlaySound := Ini.ReadBool(csIniProgramSetSection, csIniProgramSetPlaySound, True);
    FProgramSetAlarmFileA := Ini.ReadString(csIniProgramSetSection, csIniProgramSetAlarmFileA, 'SIREN1.WAV');
    FProgramSetAlarmFileB := Ini.ReadString(csIniProgramSetSection, csIniProgramSetAlarmFileB, 'SIREN1.WAV');
    FProgramSetAlarmFileC := Ini.ReadString(csIniProgramSetSection, csIniProgramSetAlarmFileC, 'SIREN1.WAV');
    FProgramSetPlayPassedSound := Ini.ReadBool(csIniProgramSetSection, csIniProgramSetPlayPassedSound, True);
    FProgramSetPassedSoundFile := Ini.ReadString(csIniProgramSetSection, csIniProgramSetPassedSoundFile, 'passed.wav');
    FProgramSetSpanInSecs := Ini.ReadInteger(csIniProgramSetSection, csIniProgramSetSpanInSecs, 50);
    FProgramSetServer := Ini.ReadString(csIniProgramSetSection, csIniProgramSetServer, 'http://10.4.31.173/');
    FProgramSetLogFile := Ini.ReadString(csIniProgramSetSection, csIniProgramSetLogFile, 'Log.db');
    FProgramSetCreateLogTable := Ini.ReadString(csIniProgramSetSection, csIniProgramSetCreateLogTable, 'CREATE TABLE Logs([ID] INTEGER PRIMARY KEY,[IDCardNo] VARCHAR (50) NOT NULL,[CreatedTime] TimeStamp NOT NULL DEFAULT (datetime(''now'',''localtime'')));');
    FProgramSetLogSQL := Ini.ReadString(csIniProgramSetSection, csIniProgramSetLogSQL, 'INSERT INTO Logs([IDCardNo]) VALUES (''%s'');');
    FProgramSetLogDays := Ini.ReadInteger(csIniProgramSetSection, csIniProgramSetLogDays, 30);
    FProgramSetStatisIDCardNoSQL := Ini.ReadString(csIniProgramSetSection, csIniProgramSetStatisIDCardNoSQL, 'SELECT * FROM Logs where IDCardNo Like ''%%s%''');
    FProgramSetStatisDateTimeSQL := Ini.ReadString(csIniProgramSetSection, csIniProgramSetStatisDateTimeSQL, 'SELECT * FROM Logs where CreatedTime>''%s'' AND CreatedTime<''%s'';');
  end;
end;

procedure TIniOptions.SaveSettings(Ini: TIniFile);
begin
  if Ini <> nil then
  begin
    {Section: ProgramSet}
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetVersion, FProgramSetVersion);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetConnString, FProgramSetConnString);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetDataSource, FProgramSetDataSource);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetSQL, FProgramSetSQL);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetSQLXm, FProgramSetSQLXm);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetSQLNumber, FProgramSetSQLNumber);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetViewFields, FProgramSetViewFields);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetViewFieldsWidth, FProgramSetViewFieldsWidth);
    Ini.WriteBool(csIniProgramSetSection, csIniProgramSetPlaySound, FProgramSetPlaySound);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetAlarmFileA, FProgramSetAlarmFileA);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetAlarmFileB, FProgramSetAlarmFileB);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetAlarmFileC, FProgramSetAlarmFileC);
    Ini.WriteBool(csIniProgramSetSection, csIniProgramSetPlayPassedSound, FProgramSetPlayPassedSound);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetPassedSoundFile, FProgramSetPassedSoundFile);
    Ini.WriteInteger(csIniProgramSetSection, csIniProgramSetSpanInSecs, FProgramSetSpanInSecs);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetServer, FProgramSetServer);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetLogFile, FProgramSetLogFile);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetCreateLogTable, FProgramSetCreateLogTable);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetLogSQL, FProgramSetLogSQL);
    Ini.WriteInteger(csIniProgramSetSection, csIniProgramSetLogDays, FProgramSetLogDays);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetStatisIDCardNoSQL, FProgramSetStatisIDCardNoSQL);
    Ini.WriteString(csIniProgramSetSection, csIniProgramSetStatisDateTimeSQL, FProgramSetStatisDateTimeSQL);
  end;
end;

procedure TIniOptions.LoadFromFile(const FileName: string);
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

procedure TIniOptions.SaveToFile(const FileName: string);
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
  IniOptions := TIniOptions.Create;

finalization
  IniOptions.Free;

end.

