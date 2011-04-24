program gygac_zt;

uses
  Forms,
  Main in 'Main.pas' {frmMain},
  ReadThread in 'ReadThread.pas',
  DBVersionUnit in 'DBVersionUnit.pas',
  OptionsForm in 'OptionsForm.pas' {frmOptions},
  IDCardClass in 'IDCardClass.pas',
  SQLiteTable3 in 'SQLiteTable3.pas',
  SQLite3 in 'SQLite3.pas',
  LogHelperUnit in 'LogHelperUnit.pas',
  StatisForm in 'StatisForm.pas' {frmStatis},
  IniOptionsUnit in 'IniOptionsUnit.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TfrmMain, frmMain);
  Application.CreateForm(TfrmOptions, frmOptions);
  Application.CreateForm(TfrmStatis, frmStatis);
  Application.Run;
end.
