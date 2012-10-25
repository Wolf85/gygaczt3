object frmMain: TfrmMain
  Left = 173
  Top = 94
  Width = 808
  Height = 650
  Caption = #36149#38451#38081#36335#20844#23433#22788#20154#21592#27604#23545#31995#32479
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object spl1: TSplitter
    Left = 0
    Top = 337
    Width = 800
    Height = 3
    Cursor = crVSplit
    Align = alTop
  end
  object pnlTop: TPanel
    Left = 0
    Top = 0
    Width = 800
    Height = 337
    Align = alTop
    Caption = 'pnlTop'
    TabOrder = 0
    object lblMsg: TLabel
      Left = 192
      Top = 304
      Width = 48
      Height = 16
      Caption = 'lblMsg'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -16
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
    end
    object grp1: TGroupBox
      Left = 8
      Top = 8
      Width = 457
      Height = 249
      Caption = #36523#20221#35777#22522#26412#20449#24687
      TabOrder = 0
      object lblName: TLabel
        Left = 40
        Top = 45
        Width = 32
        Height = 15
        Caption = #22995#21517
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblBorn: TLabel
        Left = 8
        Top = 93
        Width = 64
        Height = 15
        Caption = #20986#29983#26085#26399
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblIDCardNO: TLabel
        Left = 8
        Top = 141
        Width = 64
        Height = 15
        Caption = #36523#20221#35777#21495
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblAddress: TLabel
        Left = 32
        Top = 189
        Width = 32
        Height = 15
        Caption = #20303#22336
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblSex: TLabel
        Left = 216
        Top = 48
        Width = 32
        Height = 15
        Caption = #24615#21035
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblNotion: TLabel
        Left = 216
        Top = 96
        Width = 32
        Height = 15
        Caption = #27665#26063
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = [fsBold]
        ParentFont = False
      end
      object img1: TImage
        Left = 336
        Top = 40
        Width = 104
        Height = 128
      end
      object edtName: TEdit
        Left = 80
        Top = 40
        Width = 121
        Height = 23
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 0
      end
      object edtBorn: TEdit
        Left = 80
        Top = 88
        Width = 121
        Height = 23
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 1
      end
      object edtIDCardNO: TEdit
        Left = 80
        Top = 136
        Width = 225
        Height = 23
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 2
      end
      object edtAddress: TEdit
        Left = 80
        Top = 184
        Width = 361
        Height = 23
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 3
      end
      object edtSex: TEdit
        Left = 256
        Top = 40
        Width = 49
        Height = 23
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 4
      end
      object edtNation: TEdit
        Left = 256
        Top = 88
        Width = 49
        Height = 23
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 5
      end
      object btnStart: TButton
        Left = 120
        Top = 216
        Width = 75
        Height = 25
        Caption = #24320#22987
        TabOrder = 6
        Visible = False
        OnClick = btnStartClick
      end
      object btnStop: TButton
        Left = 216
        Top = 216
        Width = 75
        Height = 25
        Caption = #20572#27490
        TabOrder = 7
        Visible = False
        OnClick = btnStopClick
      end
    end
    object grp2: TGroupBox
      Left = 472
      Top = 16
      Width = 321
      Height = 89
      Caption = #20854#23427#20449#24687
      TabOrder = 1
      object lblGrantdept: TLabel
        Left = 8
        Top = 21
        Width = 64
        Height = 15
        Caption = #31614#21457#26426#20851
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = [fsBold]
        ParentFont = False
        Visible = False
      end
      object lblUserLifeEnd: TLabel
        Left = 8
        Top = 21
        Width = 64
        Height = 15
        Caption = #26377#25928#26399#38480
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblNewAddress: TLabel
        Left = 8
        Top = 53
        Width = 64
        Height = 15
        Caption = #26368#26032#20303#22336
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = [fsBold]
        ParentFont = False
      end
      object edtGrantdept: TEdit
        Left = 80
        Top = 16
        Width = 217
        Height = 23
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 0
        Visible = False
      end
      object edtUserLifeEnd: TEdit
        Left = 80
        Top = 16
        Width = 217
        Height = 23
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 1
      end
      object edtNewAddress: TEdit
        Left = 80
        Top = 48
        Width = 217
        Height = 23
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 2
      end
    end
    object grp3: TGroupBox
      Left = 472
      Top = 112
      Width = 321
      Height = 145
      Caption = #25163#24037#26680#26597
      TabOrder = 2
      object lblInputCardNo: TLabel
        Left = 3
        Top = 68
        Width = 118
        Height = 21
        AutoSize = False
        Caption = #36755#20837#36523#20221#35777#21495#65306
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblInputName: TLabel
        Left = 32
        Top = 28
        Width = 81
        Height = 21
        AutoSize = False
        Caption = #36755#20837#22995#21517#65306
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object edtInputCardNo: TEdit
        Left = 120
        Top = 64
        Width = 177
        Height = 21
        TabOrder = 1
        OnKeyPress = btnKeyPress
      end
      object edtInputName: TEdit
        Left = 120
        Top = 24
        Width = 177
        Height = 21
        TabOrder = 0
        OnKeyPress = btnKeyPress
      end
      object btnSearch: TButton
        Left = 70
        Top = 112
        Width = 75
        Height = 25
        Caption = #26597#35810'(&S)'
        TabOrder = 2
        OnClick = btnSearchClick
      end
      object btnClear: TButton
        Left = 190
        Top = 112
        Width = 75
        Height = 25
        Caption = #28165#31354'(&C)'
        TabOrder = 3
        OnClick = btnClearClick
      end
    end
  end
  object pnlBottom: TPanel
    Left = 0
    Top = 340
    Width = 800
    Height = 264
    Align = alClient
    Caption = 'pnlBottom'
    TabOrder = 1
    object stat1: TStatusBar
      Left = 1
      Top = 232
      Width = 798
      Height = 31
      Panels = <
        item
          Width = 240
        end
        item
          Width = 50
        end>
    end
    object strngrdResult: TStringGrid
      Left = 1
      Top = 1
      Width = 798
      Height = 231
      Align = alClient
      ColCount = 3
      RowCount = 2
      FixedRows = 0
      TabOrder = 1
      OnDrawCell = strngrdResultDrawCell
      RowHeights = (
        24
        24)
    end
  end
  object MainMenu1: TMainMenu
    Left = 728
    Top = 65528
    object N1: TMenuItem
      Caption = #31995#32479#31649#29702
      object menuOpenPort: TMenuItem
        Caption = #25171#24320#31471#21475
        OnClick = menuOpenPortClick
      end
      object menuOption: TMenuItem
        Caption = #31995#32479#35774#32622
        OnClick = menuOptionClick
      end
      object menuTestSound: TMenuItem
        Caption = #27979#35797#22768#38899
        OnClick = menuTestSoundClick
      end
      object menuExit: TMenuItem
        Caption = #36864#20986#31995#32479
        OnClick = menuExitClick
      end
    end
    object N3: TMenuItem
      Caption = '|'
      RadioItem = True
    end
    object menuSearch: TMenuItem
      Caption = #26597#35810
      OnClick = menuSearchClick
    end
    object N5: TMenuItem
      Caption = '|'
    end
    object N2: TMenuItem
      Caption = #25805#20316
      object menuUpdate: TMenuItem
        Caption = #26816#26597#26356#26032
        OnClick = menuUpdateClick
      end
      object menuUpdateData: TMenuItem
        Caption = #26816#26597#25968#25454#26356#26032
        OnClick = menuUpdateDataClick
      end
    end
    object N4: TMenuItem
      Caption = #24110#21161
      object menuHelp: TMenuItem
        Caption = #20351#29992#24110#21161
        OnClick = menuHelpClick
      end
      object menuAbout: TMenuItem
        Caption = #20851#20110
        OnClick = menuAboutClick
      end
    end
  end
  object dsResult: TDataSource
    Left = 136
    Top = 524
  end
  object atpgrdrUpdate: TauAutoUpgrader
    ThreadPriority = tpLower
    AutoCheck = True
    InfoFile.UpgradeMsg = 'first release'
    InfoFileURL = 'http://10.4.12.17/gygac_zt/AutoUpgrader.inf'
    VersionControl = byNumber
    VersionDate = '10/24/2012'
    VersionDateAutoSet = True
    VersionNumber = '01.02.00'
    ShowMessages = [mAskUpgrade, mConnLost, mHostUnreachable, mLostFile, mNoInfoFile, mNoUpdateAvailable, mPasswordRequest]
    Left = 624
    Top = 65528
  end
  object atpgrdrDatabase: TauAutoUpgrader
    AutoCheck = True
    InfoFile.UpgradeMsg = 'first release'
    InfoFileURL = 'http://10.4.12.17/gygac_zt/db/AutoUpgrader.inf'
    VersionControl = byNumber
    VersionDate = '10/24/2012'
    VersionDateAutoSet = True
    VersionNumber = '01.02.00'
    ShowMessages = [mAskUpgrade, mConnLost, mHostUnreachable, mLostFile, mNoInfoFile, mNoUpdateAvailable, mPasswordRequest]
    Wizard.Language = wlChineseSimplified
    OnDoOwnCloseAppMethod = atpgrdrDatabaseDoOwnCloseAppMethod
    Left = 568
    Top = 65520
  end
end
