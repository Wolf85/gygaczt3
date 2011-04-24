unit OptionsForm;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, IniOptionsUnit, ComCtrls;

type
  TfrmOptions = class(TForm)
    grp1: TGroupBox;
    chkPlaySound: TCheckBox;
    chkPlayPassedSound: TCheckBox;
    btnUpdate: TButton;
    btnCancel: TButton;
    grp2: TGroupBox;
    lblLogDays: TLabel;
    udLogDays: TUpDown;
    edtLogDays: TEdit;
    procedure FormCreate(Sender: TObject);
    procedure chkPlaySoundClick(Sender: TObject);
    procedure btnUpdateClick(Sender: TObject);
    procedure btnCancelClick(Sender: TObject);
    procedure udLogDaysClick(Sender: TObject; Button: TUDBtnType);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmOptions: TfrmOptions;

implementation

{$R *.dfm}

procedure TfrmOptions.FormCreate(Sender: TObject);
begin
  chkPlayPassedSound.Checked := IniOptions.PlayPassedSound;
  chkPlaySound.Checked := IniOptions.PlaySound;
  chkPlayPassedSound.Enabled := chkPlaySound.Checked;

  {…Ë÷√»’÷æ}
  edtLogDays.Text := IntToStr(IniOptions.LogDays);

end;

procedure TfrmOptions.chkPlaySoundClick(Sender: TObject);
begin                                                
  chkPlayPassedSound.Enabled := chkPlaySound.Checked;
end;

procedure TfrmOptions.btnUpdateClick(Sender: TObject);
begin
  IniOptions.PlayPassedSound := chkPlayPassedSound.Checked;
  IniOptions.PlaySound := chkPlaySound.Checked;
  IniOptions.LogDays := StrToInt( edtLogDays.Text );
  ModalResult := mrOK;  
end;

procedure TfrmOptions.btnCancelClick(Sender: TObject);
begin
  ModalResult := mrCancel;
end;

procedure TfrmOptions.udLogDaysClick(Sender: TObject; Button: TUDBtnType);
var
  i : Integer;
begin

  i := StrToInt(edtLogDays.Text);
  if Button=btNext then
  begin
    if i < udLogDays.Max then Inc(i);
  end
  else
  begin
    if i > udLogDays.Min then Dec(i);
  end;
  edtLogDays.Text := IntToStr(i);
end;

end.
