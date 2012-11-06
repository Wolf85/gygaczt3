{*******************************************************}
{                                                       }
{       人员查询系统                                    }
{                                                       }
{       版权所有 (C) 2012 贵阳铁路公安处                }
{                                                       }
{*******************************************************}


unit Main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Menus, StdCtrls, ExtCtrls, Grids, DBGrids, DB, ADODB, mmsystem,
  auHTTP, auAutoUpgrader, ComCtrls, IniOptionsUnit, DBVersionUnit, SQLiteTable3;

type
  TfrmMain = class(TForm)
    MainMenu1: TMainMenu;
    N1: TMenuItem;
    menuOpenPort: TMenuItem;
    menuOption: TMenuItem;
    menuTestSound: TMenuItem;
    menuExit: TMenuItem;
    N2: TMenuItem;
    N4: TMenuItem;
    menuUpdate: TMenuItem;
    pnlTop: TPanel;
    pnlBottom: TPanel;
    spl1: TSplitter;
    grp1: TGroupBox;
    grp2: TGroupBox;
    lblName: TLabel;
    lblBorn: TLabel;
    lblIDCardNO: TLabel;
    lblAddress: TLabel;
    lblSex: TLabel;
    lblNotion: TLabel;
    edtName: TEdit;
    edtBorn: TEdit;
    edtIDCardNO: TEdit;
    edtAddress: TEdit;
    edtSex: TEdit;
    edtNation: TEdit;
    img1: TImage;
    lblGrantdept: TLabel;
    edtGrantdept: TEdit;
    lblUserLifeEnd: TLabel;
    edtUserLifeEnd: TEdit;
    lblNewAddress: TLabel;
    edtNewAddress: TEdit;
    lblMsg: TLabel;
    dsResult: TDataSource;
    atpgrdrUpdate: TauAutoUpgrader;
    N3: TMenuItem;
    menuHelp: TMenuItem;
    menuAbout: TMenuItem;
    stat1: TStatusBar;
    menuUpdateData: TMenuItem;
    atpgrdrDatabase: TauAutoUpgrader;
    menuSearch: TMenuItem;
    N5: TMenuItem;
    grp3: TGroupBox;
    lblInputCardNo: TLabel;
    edtInputCardNo: TEdit;
    edtInputName: TEdit;
    lblInputName: TLabel;
    btnSearch: TButton;
    btnClear: TButton;
    btnStart: TButton;
    btnStop: TButton;
    strngrdResult: TStringGrid;


    procedure FormCreate(Sender: TObject);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure FormDestroy(Sender: TObject);
    procedure menuOpenPortClick(Sender: TObject);
    procedure menuExitClick(Sender: TObject);
    procedure btnStartClick(Sender: TObject);
    procedure btnStopClick(Sender: TObject);
    procedure menuTestSoundClick(Sender: TObject);
    procedure btnSearchClick(Sender: TObject);
    procedure menuUpdateClick(Sender: TObject);
    procedure menuAboutClick(Sender: TObject);
    procedure menuOptionClick(Sender: TObject);
    procedure menuUpdateDataClick(Sender: TObject);
    procedure menuSearchClick(Sender: TObject);
    procedure menuHelpClick(Sender: TObject);
    procedure btnClearClick(Sender: TObject);
    procedure btnKeyPress(Sender: TObject; var Key: Char);
    procedure atpgrdrDatabaseDoOwnCloseAppMethod(Sender: TObject);
    procedure strngrdResultDrawCell(Sender: TObject; ACol, ARow: Integer;
      Rect: TRect; State: TGridDrawState);

  private
    { Private declarations }
    FExepath : string;
    procedure EnableButton(Enable : Boolean);
//    procedure SetDBGrid;
    procedure InitGrid;
  public
    { Public declarations }
    property ExePath : string read FExepath;
    procedure ClearstrnGrid;
  end;

  const
    IniFilename = 'Program.inf';
    DBVersionFilename ='dbVersion.inf';
 
var
  frmMain: TfrmMain;
  Port : Integer;
  CjryDb: TSQLiteDatabase;
implementation
uses ReadThread, LogHelperUnit, IDCardClass, OptionsForm, StatisForm, Global, sevenzip;
{$R *.dfm}

var
  thRead : TReadThread;

{事件处理函数}
procedure TfrmMain.FormCreate(Sender: TObject);
var
  filename : string;
begin
  EnableButton(False);
  lblMsg.Caption := '';

  FExepath := ExtractFilePath(ParamStr(0));
  stat1.Panels[1].Text := '读卡工作未启动。。。。。。';

  {读配置文件和数据版本文件}
  fileName := Exepath+ IniFileName;
  IniOptions.LoadFromFile(fileName);
  fileName := Exepath + DBVersionFilename;
  DBVersion.LoadFromFile(fileName);

  {处理版本信息}
  atpgrdrUpdate.VersionNumber := IniOptions.Version;
  atpgrdrDatabase.VersionNumber := DBVersion.DatabaseVersionVersion;
  frmMain.Caption := frmMain.Caption + '          版本 ' + atpgrdrUpdate.VersionNumber + '     作者  莫光健 ';

//  SetDBGrid;
  InitGrid;
  thRead := TReadThread.Create(True);
  CjryDb := TSQLiteDatabase.Create(Utf8Encode(ExtractFilepath(application.exename) + IniOptions.DataSource));
  menuOpenPortClick(Self);
  if Port>0 then btnStart.Click;
end;

procedure TfrmMain.FormCloseQuery(Sender: TObject; var CanClose: Boolean);
begin
  thRead.Terminate;
  frmOptions.Close;
  FreeAndNil(CjryDB);
end;

procedure TfrmMain.FormDestroy(Sender: TObject);
begin
  thRead.Free;
end;

{菜单事件}
procedure TfrmMain.menuOpenPortClick(Sender: TObject);
var
  iPort : Integer;
begin
    for iPort := USBPort1 to USBPort3 do
    begin
      if(SDT_OpenPort(iPort)=$90) then
      begin
        Port := iPort;
        stat1.Panels[0].Text :=Format('读卡器连接在 USB%d 端口上',[iPort-1000]);
        EnableButton(True);
        Exit;
      end;
    end;
    stat1.Panels[0].Text := '没有连接读卡器';
    ShowMessage(stat1.Panels[0].Text);
end;

procedure TfrmMain.menuOptionClick(Sender: TObject);
begin
//Todo 加入系统设置窗口

  if frmOptions.ShowModal= mrOk then
  begin
    IniOptions.SaveToFile(ExtractFilePath(ParamStr(0)) + IniFilename);
  end;
end;

procedure TfrmMain.menuExitClick(Sender: TObject);
begin
  Close;
end;

procedure TfrmMain.menuTestSoundClick(Sender: TObject);
begin
  PlaySound(PChar(IniOptions.AlarmFileA),0,0)
end;


procedure TfrmMain.menuUpdateClick(Sender: TObject);
begin
  atpgrdrUpdate.CheckUpdate;
end;

procedure TfrmMain.menuUpdateDataClick(Sender: TObject);
begin
  atpgrdrDatabase.CheckUpdate;
end;
{按键事件}
procedure TfrmMain.btnStartClick(Sender: TObject);
begin
  if thRead.Suspended then
  begin
    thRead.Resume;
    stat1.Panels[1].Text := '等待读卡。。。。。。';
  end;
end;

procedure TfrmMain.btnStopClick(Sender: TObject);
begin
{$IFDEF DEBUG}
  tmrReader.Enabled := False;
{$ELSE}
  thRead.Suspend;
{$ENDIF}
  stat1.Panels[1].Text := '暂停读卡。。。。。。';
end;

procedure TfrmMain.menuAboutClick(Sender: TObject);
begin
  Application.MessageBox('本程序由贵阳铁路公安处网监科开发，欢迎大家免费使用，'
  + #13#10#13#10 +
  '如在使用中遇到问题，请将问题反馈到gytlgac@21cn.com邮箱中。', '关于', MB_OK
  + MB_TOPMOST);
end;

procedure TfrmMain.EnableButton(Enable : Boolean);
begin
  btnStart.Enabled := Enable;
  btnStop.Enabled := Enable;
end;

procedure TfrmMain.btnSearchClick(Sender: TObject);
var
  slutb : TSQLiteTable;
  strSQL : string;
  iRow : Integer;
{$IFDEF DEBUG}
  fieldCount : Integer;
  iCol : Integer;
{$ENDIF}
begin
{$IFDEF DEBUG}
  fieldCount := strngrdResult.Cols.Count;
{$ENDIF}

  if (edtInputName.Text <> '') then
  begin
    strSQL := Format(IniOptions.SQLXm,[edtInputName.Text + '%']);
  end
  else
  begin
    if (edtInputCardNo.Text <> '') then
    begin
      strSQL := Format(IniOptions.SQLNumber,['%' + edtInputCardNo.Text + '%']);
    end;
  end;
  if (strSQL <> '') then
  begin

    slutb := CjryDb.GetTable(UTF8Encode(strSQL));
    try
      iRow := 1;
      strngrdResult.RowCount := slutb.RowCount + 1;
      while not slutb.EOF do
      begin
        with slutb do
        begin
          with strngrdResult do
          begin
{$IFDEF DEBUG}
          for iCol := 0 to fieldCount -1 do
          begin
              Cells[iCol,iRow] := UTF8Decode(FieldAsString(FieldIndex[iCol]));

          end;

{$ELSE}
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
            
{$ENDIF}
          end;
          Inc(iRow);
          Next;
        end;
      end;
    finally
      FreeAndNil(slutb);
    end;      
  end;  
end;

procedure TfrmMain.btnKeyPress(Sender: TObject; var Key: Char);
begin
  if Key = #13 then
  begin
    btnSearchClick(Sender);
  end;  
end;

procedure TfrmMain.btnClearClick(Sender: TObject);
begin
  edtInputName.Text := '';
  edtInputCardNo.Text := '';
end;

procedure TfrmMain.atpgrdrDatabaseDoOwnCloseAppMethod(Sender: TObject);
var
  filename : string;
begin
  thRead.Terminate;
  FreeAndNil(CjryDb);
  filename := Exepath + IniOptions.DefaultDataFilename;
  if(FileExists(filename)) then
  begin        
    with CreateInArchive(CLSID_CFormat7z) do
    begin
      OpenFile(filename);
      ExtractTo(ExePath);
    end;
    Sleep(1000);
  end;
  LogHelper.CleanLog(IniOptions.LogDays);
  if Assigned(Application.MainForm) then
    Application.MainForm.Close;
  Application.Terminate;      
end;

procedure TfrmMain.menuSearchClick(Sender: TObject);
begin
  frmStatis.InitDatetimePicker;
  frmStatis.ShowModal;
end;

procedure TfrmMain.menuHelpClick(Sender: TObject);
begin
  Winexec(PChar('explorer help.mht'),SW_SHOWNORMAL);

end;

{用户定义事件}
procedure TfrmMain.InitGrid;
var
  FieldList,FieldWidthList:TStringList;
  i:Integer;
begin
  FieldList := TStringList.Create;
  FieldWidthList := TStringList.Create;
  try
    FieldList.Delimiter := ',';
    FieldList.DelimitedText := IniOptions.ViewFields;

    FieldWidthList.Delimiter := ',';
    FieldWidthList.DelimitedText := IniOptions.ViewFieldsWidth;
    if not (FieldList.Count = FieldWidthList.Count) then
    begin
        Application.MessageBox('在配置文件中的字段的数目与字段宽度的数目不匹配，'
          + #13#10#13#10 +
          '请检查配置文件，程序将退出',
          '错误', MB_OK + MB_ICONSTOP +
          MB_TOPMOST);
    end
    else
    begin
      strngrdResult.ColCount := FieldList.Count;
      for i:= 0 to FieldList.Count-1 do
      begin
        with strngrdResult   do
        begin
          ColWidths[i] := StrToInt(FieldWidthList.Strings[i]);
          Cells[i,0] :=  FieldList.Strings[i];
        end;
      end;
      strngrdResult.FixedRows := 1;
    end;
  finally
    FreeAndNil(FieldList);
    FreeAndNil(FieldWidthList);
  end;

end;

procedure TfrmMain.ClearstrnGrid;
var
  i : Integer;
begin
  with strngrdResult do
  begin
    RowCount := 2;
    for i:=0 to ColCount do
    begin
      Cells[i,1] := '';
    end;  
  end;
end;
  
procedure TfrmMain.strngrdResultDrawCell(Sender: TObject; ACol,
  ARow: Integer; Rect: TRect; State: TGridDrawState);
begin

//  if LowerCase(TStringGrid(Sender).Cells[3,ARow])='在逃人员' then
//  begin
//    TStringGrid(Sender).Canvas.Font.Color := $000000ff;
//  end;
end;

end.
