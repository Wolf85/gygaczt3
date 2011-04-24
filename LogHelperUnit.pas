unit LogHelperUnit;

interface

uses
  SQLiteTable3, IniOptionsUnit;


const
  cstLogFilename = 'log.db';
  cstTableName = 'Logs';
{ TLogHelper }
type
  TLogHelper = class(TObject)
  private
    sldb: TSQLiteDatabase;
//    sltb: TSQLIteTable;
  protected

  public
    constructor Create;
    destructor Destroy; override;

    procedure Write(const idcardno : string);
    procedure CleanLog(const days : Integer);
  published

  end;

var
  LogHelper : TLogHelper = nil;

implementation

uses
  SysUtils, Windows, DateUtils;

constructor TLogHelper.Create;
var
  strLogFilepath,strSQL : string;


begin
  strLogFilepath := ExtractFilePath(ParamStr(0)) + cstLogFilename;

  sldb := TSQLiteDatabase.Create(Utf8Encode(strLogFilepath));
  try
    if not sldb.TableExists(cstTableName) then
    begin
      strSQL := 'CREATE TABLE Logs([ID] INTEGER PRIMARY KEY,[IDCardNo] VARCHAR (50) NOT NULL,[CreatedTime] TimeStamp NOT NULL DEFAULT (datetime(''now'',''localtime'')));';
      sldb.execsql(strSQL);
      sldb.execsql('CREATE INDEX IDX_IDCardNo ON [' + cstTableName + ']([IDCardNo]);');
    end;
  finally

  end;

end;

destructor TLogHelper.Destroy;
begin
  sldb.Free;
  inherited;
end;

procedure TLogHelper.Write(const idcardno : string);
var
  strSQL : string;
begin
  { TODO -oAdministrator -c : 写日志流程 2010-6-24 18:09:32 }
  try
    strSQL := Format(IniOptions.LogSQL,[idcardno]);
    sldb.ExecSQL(strSQL);
  except

  end;
end;

procedure TLogHelper.CleanLog(const days : Integer);
var
  strSQL : string;
begin
  strSQL := 'DELETE FROM Logs where CreatedTime<''' + FormatDateTime('yyyy-MM-dd hh:mm:ss',IncDay(Now(),-days))+ '''';
  sldb.ExecSQL(strSQL);
end;

initialization
  LogHelper := TLogHelper.Create;
finalization
  FreeAndNil(LogHelper);
end.
