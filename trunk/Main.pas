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
    btnTest: TButton;
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
    procedure btnTestClick(Sender: TObject);
    procedure menuUpdateClick(Sender: TObject);
    procedure menuAboutClick(Sender: TObject);
    procedure atpgrdrDatabaseFileDone(Sender: TObject; const FileName: String);
    procedure menuOptionClick(Sender: TObject);
    procedure menuUpdateDataClick(Sender: TObject);
    procedure menuSearchClick(Sender: TObject);
    procedure menuHelpClick(Sender: TObject);
    procedure btnClearClick(Sender: TObject);
    procedure btnKeyPress(Sender: TObject; var Key: Char);

  private
    { Private declarations }
    procedure EnableButton(Enable : Boolean);
//    procedure SetDBGrid;
    procedure InitGrid;
  public
    { Public declarations }

  end;

  const
    IniFilename = 'Program.inf';
    DBVersionFilename ='dbVersion.inf';
var
  frmMain: TfrmMain;
  Port : Integer;
  CjryDb: TSQLiteDatabase;
implementation
uses ReadThread, LogHelperUnit, IDCardClass, OptionsForm, StatisForm;
{$R *.dfm}

var
  thRead : TReadThread;

{�¼���������}
procedure TfrmMain.FormCreate(Sender: TObject);
var
  exepath,filename : string;
begin
  EnableButton(False);
  lblMsg.Caption := '';

  exepath := ExtractFilePath(ParamStr(0));
  stat1.Panels[1].Text := '��������δ����������������';

  {�������ļ������ݰ汾�ļ�}
  fileName := exepath+ IniFileName;
  IniOptions.LoadFromFile(fileName);
  fileName := exepath + DBVersionFilename;
  DBVersion.LoadFromFile(fileName);

  {�����汾��Ϣ}
  atpgrdrUpdate.VersionNumber := IniOptions.Version;
  atpgrdrDatabase.VersionNumber := DBVersion.DatabaseVersionVersion;
  frmMain.Caption := frmMain.Caption + '          �汾 ' + atpgrdrUpdate.VersionNumber + '     ����  Ī�⽡ ';

//  SetDBGrid;
  InitGrid;
  thRead := TReadThread.Create(True);
  CjryDb := TSQLiteDatabase.Create(Utf8Encode(ExtractFilepath(application.exename) + IniOptions.DataSource));

  menuOpenPortClick(Self);
  //if Port>0 then btnStart.Click;
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

{�˵��¼�}
procedure TfrmMain.menuOpenPortClick(Sender: TObject);
var
  iPort : Integer;
begin
    for iPort := USBPort1 to USBPort3 do
    begin
      if(SDT_OpenPort(iPort)=$90) then
      begin
        Port := iPort;
        stat1.Panels[0].Text :=Format('������������ USB%d �˿���',[iPort-1000]);
        EnableButton(True);
        Exit;
      end;
    end;
    stat1.Panels[0].Text := 'û�����Ӷ�����';
    ShowMessage(stat1.Panels[0].Text);
end;

procedure TfrmMain.menuOptionClick(Sender: TObject);
begin
//Todo ����ϵͳ���ô���

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
{�����¼�}
procedure TfrmMain.btnStartClick(Sender: TObject);
begin
  if thRead.Suspended then
  begin
    thRead.Resume;
    stat1.Panels[1].Text := '�ȴ�����������������';
  end;
end;

procedure TfrmMain.btnStopClick(Sender: TObject);
begin
{$IFDEF DEBUG}
  tmrReader.Enabled := False;
{$ELSE}
  thRead.Suspend;
{$ENDIF}
  stat1.Panels[1].Text := '��ͣ����������������';
end;

procedure TfrmMain.menuAboutClick(Sender: TObject);
begin
  Application.MessageBox('�������ɹ�����·����������ƿ�������ӭ������ʹ�ã�'
  + #13#10#13#10 +
  '����ʹ�����������⣬�뽫���ⷴ����gytlgac@21cn.com�����С�', '����', MB_OK
  + MB_TOPMOST);
end;

procedure TfrmMain.EnableButton(Enable : Boolean);
begin
  btnStart.Enabled := Enable;
  btnStop.Enabled := Enable;
end;

procedure TfrmMain.btnTestClick(Sender: TObject);
var
  slutb : TSQLiteTable;
  strSQL : string;
  iRow : Integer;
begin
//  if(qryADO.Active = True) then
//  begin
//    qryADO.Active := False;
//  end;
//  if (edtInputName.Text <> '') then
//
//  begin
//    qryADO.SQL.Text := Format(IniOptions.SQLName,['%' + edtInputName.Text + '%']);
//    qryADO.Active := True;
//  end
//  else
//  begin
//    if (edtInputCardNo.Text <> '') then
//    begin
//      qryADO.SQL.Text := Format(IniOptions.SQLIDCard,['%' + edtInputCardNo.Text + '%']);
//      qryADO.Active := True;
//    end;
//  end;
  if (edtInputName.Text <> '') then
  begin
    strSQL := Format(IniOptions.SQLXm,['%' + edtInputName.Text + '%']);
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
    slutb := CjryDb.GetTable(strSQL);
    try
      iRow := 1;
      strngrdResult.RowCount := 2;
      while not slutb.EOF do
      begin
        with slutb do
        begin
          with strngrdResult do
          begin
            RowCount := RowCount +1;
            Cells[0,iRow] := FieldAsString(FieldIndex['id']);
            Cells[1,iRow] := FieldAsString(FieldIndex['idcardno']);
            Cells[2,iRow] := FieldAsString(FieldIndex['Createdtime']);
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
    btnTestClick(Sender);
  end;  
end;

procedure TfrmMain.btnClearClick(Sender: TObject);
begin
  edtInputName.Text := '';
  edtInputCardNo.Text := '';
end;

procedure TfrmMain.atpgrdrDatabaseFileDone(Sender: TObject;
  const FileName: String);
begin
  
  thRead.Terminate;
  //qryADO.Active := False;
  FreeAndNil(CjryDb);
  LogHelper.CleanLog(IniOptions.LogDays);
end;

{�û������¼�}
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
        Application.MessageBox('�������ļ��е��ֶε���Ŀ���ֶο��ȵ���Ŀ��ƥ�䣬'
          + #13#10#13#10 +
          '���������ļ��������˳�',
          '����', MB_OK + MB_ICONSTOP +
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
    end;
  finally
    FreeAndNil(FieldList);
    FreeAndNil(FieldWidthList);
  end;
  
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





end.