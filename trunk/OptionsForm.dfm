object frmOptions: TfrmOptions
  Left = 365
  Top = 231
  Width = 422
  Height = 362
  Caption = #31995#32479#35774#32622
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object grp1: TGroupBox
    Left = 48
    Top = 16
    Width = 313
    Height = 105
    Caption = '  '#22768#38899#35774#32622'   '
    TabOrder = 0
    object chkPlaySound: TCheckBox
      Left = 32
      Top = 32
      Width = 121
      Height = 17
      Caption = #20801#35768#25773#25918#22768#38899
      TabOrder = 0
      OnClick = chkPlaySoundClick
    end
    object chkPlayPassedSound: TCheckBox
      Left = 32
      Top = 64
      Width = 153
      Height = 17
      Caption = #20801#35768#25773#25918#35835#21345#22768#38899
      TabOrder = 1
    end
  end
  object btnUpdate: TButton
    Left = 80
    Top = 264
    Width = 75
    Height = 25
    Caption = #26356#26032
    TabOrder = 1
    OnClick = btnUpdateClick
  end
  object btnCancel: TButton
    Left = 224
    Top = 264
    Width = 75
    Height = 25
    Caption = #21462#28040
    TabOrder = 2
    OnClick = btnCancelClick
  end
  object grp2: TGroupBox
    Left = 48
    Top = 144
    Width = 313
    Height = 105
    Caption = #20854#23427#35774#32622#39033
    TabOrder = 3
    object lblLogDays: TLabel
      Left = 16
      Top = 30
      Width = 89
      Height = 13
      AutoSize = False
      Caption = #26085#24535#20445#23384#22825#25968#65306
    end
    object udLogDays: TUpDown
      Left = 160
      Top = 24
      Width = 17
      Height = 25
      Min = 1
      Position = 1
      TabOrder = 0
      OnClick = udLogDaysClick
    end
    object edtLogDays: TEdit
      Left = 112
      Top = 24
      Width = 41
      Height = 27
      ReadOnly = True
      TabOrder = 1
      Text = 'edtLogDays'
    end
  end
end
