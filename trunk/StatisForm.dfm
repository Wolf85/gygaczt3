object frmStatis: TfrmStatis
  Left = 381
  Top = 196
  Width = 606
  Height = 510
  Caption = #26597#35810#32479#35745
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object spl1: TSplitter
    Left = 0
    Top = 177
    Width = 598
    Height = 3
    Cursor = crVSplit
    Align = alTop
  end
  object pnl1: TPanel
    Left = 0
    Top = 0
    Width = 598
    Height = 177
    Align = alTop
    Caption = 'pnl1'
    TabOrder = 0
    object lblCount: TLabel
      Left = 368
      Top = 132
      Width = 65
      Height = 13
      AutoSize = False
      Caption = #35760#24405#26465#25968#65306
    end
    object grp1: TGroupBox
      Left = 8
      Top = 8
      Width = 329
      Height = 153
      Caption = #26597#35810#26465#20214
      TabOrder = 0
      object lblStart: TLabel
        Left = 8
        Top = 20
        Width = 90
        Height = 13
        Alignment = taCenter
        AutoSize = False
        Caption = #24320#22987#26102#38388#65306
      end
      object lblEnd: TLabel
        Left = 16
        Top = 76
        Width = 73
        Height = 13
        Alignment = taCenter
        AutoSize = False
        Caption = #32467#26463#26102#38388#65306
      end
      object lblIDCardNo: TLabel
        Left = 16
        Top = 120
        Width = 65
        Height = 13
        AutoSize = False
        Caption = #36523#20221#35777#21495#65306
      end
      object dtpStartDate: TDateTimePicker
        Left = 88
        Top = 16
        Width = 121
        Height = 21
        Date = 40379.399424189820000000
        Time = 40379.399424189820000000
        DateFormat = dfLong
        TabOrder = 0
      end
      object dtpStartTime: TDateTimePicker
        Left = 208
        Top = 16
        Width = 97
        Height = 21
        Date = 40379.425858460650000000
        Time = 40379.425858460650000000
        Kind = dtkTime
        TabOrder = 1
      end
      object dtpEndDate: TDateTimePicker
        Left = 88
        Top = 72
        Width = 121
        Height = 21
        Date = 40379.399424189820000000
        Time = 40379.399424189820000000
        DateFormat = dfLong
        TabOrder = 2
      end
      object dtpEndTime: TDateTimePicker
        Left = 208
        Top = 72
        Width = 97
        Height = 21
        Date = 40379.425858460650000000
        Time = 40379.425858460650000000
        Kind = dtkTime
        TabOrder = 3
      end
      object edtIDCardNo: TEdit
        Left = 88
        Top = 116
        Width = 217
        Height = 21
        TabOrder = 4
      end
    end
    object edtCount: TEdit
      Left = 432
      Top = 128
      Width = 121
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
    object btnSearch: TButton
      Left = 416
      Top = 56
      Width = 75
      Height = 25
      Caption = #26597#35810
      TabOrder = 2
      OnClick = btnSearchClick
    end
  end
  object pnl2: TPanel
    Left = 0
    Top = 180
    Width = 598
    Height = 296
    Align = alClient
    Caption = 'pnl2'
    TabOrder = 1
    object strgrd1: TStringGrid
      Left = 1
      Top = 1
      Width = 596
      Height = 294
      Align = alClient
      TabOrder = 0
      RowHeights = (
        24
        24
        24
        24
        24)
    end
  end
end
