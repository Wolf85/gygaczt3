unit StatisForm;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, StdCtrls, ComCtrls, Grids, SQLiteTable3, DateUtils;

const
  cstLogFilename = 'log.db';
  cstTableName = 'Logs';
type
  TfrmStatis = class(TForm)
    pnl1: TPanel;
    spl1: TSplitter;
    pnl2: TPanel;
    grp1: TGroupBox;
    lblStart: TLabel;
    dtpStartDate: TDateTimePicker;
    dtpStartTime: TDateTimePicker;
    lblEnd: TLabel;
    dtpEndDate: TDateTimePicker;
    dtpEndTime: TDateTimePicker;
    lblIDCardNo: TLabel;
    edtIDCardNo: TEdit;
    lblCount: TLabel;
    edtCount: TEdit;
    btnSearch: TButton;
    strgrd1: TStringGrid;
    procedure FormCreate(Sender: TObject);
    procedure btnSearchClick(Sender: TObject);
  private
    { Private declarations }
    sldb: TSQLiteDatabase;
  private
    procedure InitGrid;
  public
    { Public declarations }
    procedure InitDatetimePicker;
  end;

var
  frmStatis: TfrmStatis;

implementation

{$R *.dfm}

procedure TfrmStatis.FormCreate(Sender: TObject);
begin
  { TODO -oAdministrator -c :  2010-7-20 10:49:54 }
  InitGrid;      
end;

procedure TfrmStatis.btnSearchClick(Sender: TObject);
var
  strStartDatetime,strEndDatetime : string;
  strSQL : string;
  slutb : TSQLiteUniTable;
  iRow : Integer;
begin
  { TODO -oAdministrator -c :  2010-7-20 10:56:28 }

  dtpStartDate.Time := dtpStartTime.Time;
  strStartDatetime := FormatDateTime('yyyy-MM-dd hh:mm:ss',dtpStartDate.DateTime);

  dtpEndDate.Time := dtpEndTime.Time;
  strEndDatetime := FormatDateTime('yyyy-MM-dd hh:mm:ss',dtpEndDate.DateTime);

  sldb := TSQLiteDatabase.Create(Utf8Encode(ExtractFilepath(application.exename) + cstLogFilename));
  try
    if edtIDCardNo.Text <> '' then
      strSQL := 'SELECT * FROM Logs where IDCardNo Like ''%' + edtIDCardNo.Text + '%'''
    else
      strSQL := 'SELECT * FROM Logs where CreatedTime>''' + strStartDatetime+ ''' AND CreatedTime<''' + strEndDatetime +'''';
    slutb := slDb.GetUniTable(strSQL);
    try
      strgrd1.ColCount := slutb.ColCount;
      iRow := 1;
      strgrd1.RowCount := 2;
      while not slutb.EOF do
      begin
        with slutb do
        begin
          with strgrd1 do
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
      edtCount.Text := IntToStr(iRow-1);
    finally
      FreeAndNil(slutb);
    end;
  finally
    FreeAndNil(sldb);
  end;

end;

{Customer Code}
procedure TfrmStatis.InitGrid;
begin
  with strgrd1 do
  begin
    ColWidths[0] := 50;
    ColWidths[1] := 120;
    ColWidths[2] := 150;
    Cells[0,0] := '序号';
    Cells[1,0] := '身份证号';
    Cells[2,0] := '记录时间';
  end;

end;

procedure TfrmStatis.InitDatetimePicker;
begin
  dtpStartDate.DateTime := IncDay(Now(),-1);
  dtpStartTime.DateTime := Now();
  dtpEndDate.DateTime := Now();
  dtpEndTime.DateTime := Now();
  edtIDCardNo.Text := '';
end;

end.
