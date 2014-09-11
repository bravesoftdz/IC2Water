object CZYJSQFrm: TCZYJSQFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #25805#20316#21592#25910#25903#26126#32454#26597#35810
  ClientHeight = 571
  ClientWidth = 779
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object cxGroupBox1: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Align = alTop
    Alignment = alCenterCenter
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 0
    Height = 46
    Width = 773
    object JSBeginDateEdit: TcxDateEdit
      Left = 99
      Top = 11
      TabOrder = 0
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxLabel4: TcxLabel
      Left = 22
      Top = 12
      Caption = #36215#22987#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object cxLabel3: TcxLabel
      Left = 250
      Top = 14
      Caption = #25130#27490#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object JSEndDateEdit: TcxDateEdit
      Left = 325
      Top = 11
      TabOrder = 3
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object QueryBTN: TcxButton
      Left = 683
      Top = 10
      Width = 75
      Height = 25
      Caption = #26597'   '#35810
      LookAndFeel.NativeStyle = True
      TabOrder = 4
      OnClick = QueryBTNClick
    end
    object USERComboBox: TcxComboBox
      Left = 532
      Top = 11
      TabOrder = 5
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxLabel1: TcxLabel
      Left = 472
      Top = 12
      Caption = #29992#25143#21517':'
      ParentColor = False
      Style.Color = clCream
    end
  end
  object cxGroupBox2: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 55
    Align = alTop
    Caption = #32467#31639#20449#24687#24635#27719
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clWindowText
    Style.Font.Height = -13
    Style.Font.Name = 'Tahoma'
    Style.Font.Style = []
    Style.LookAndFeel.NativeStyle = True
    Style.TextColor = clBlack
    Style.TransparentBorder = True
    Style.IsFontAssigned = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 1
    Height = 330
    Width = 773
    object Label1: TLabel
      Left = 72
      Top = 26
      Width = 85
      Height = 19
      Caption = #25805#20316#31867#22411#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 182
      Top = 26
      Width = 85
      Height = 19
      Caption = #20132#26131#20154#27425#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 319
      Top = 26
      Width = 177
      Height = 19
      Caption = #20132#26131#25104#26412#65288#21333#20301'-'#20803#65289#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 532
      Top = 26
      Width = 211
      Height = 19
      Caption = #20132#26131#29616#37329#37329#39069#65288#21333#20301'-'#20803#65289#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 106
      Top = 57
      Width = 51
      Height = 19
      Caption = #24320#25143#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 55
      Top = 87
      Width = 102
      Height = 19
      Caption = #35835#21345#22120#20805#20540#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label7: TLabel
      Left = 55
      Top = 117
      Width = 102
      Height = 19
      Caption = #20805#20540#26426#20805#20540#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 21
      Top = 147
      Width = 136
      Height = 19
      Caption = #22351#21345#12289#25346#22833#34917#21345#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label9: TLabel
      Left = 106
      Top = 177
      Width = 51
      Height = 19
      Caption = #21462#27454#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label10: TLabel
      Left = 55
      Top = 207
      Width = 102
      Height = 19
      Caption = #20805#20540#31649#29702#36153#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label11: TLabel
      Left = 72
      Top = 237
      Width = 85
      Height = 19
      Caption = #27491#24120#36864#21345#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label12: TLabel
      Left = 72
      Top = 267
      Width = 85
      Height = 19
      Caption = #26080#21345#36864#21345#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 106
      Top = 297
      Width = 51
      Height = 19
      Caption = #21512#35745#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object cxTextEdit1: TcxTextEdit
      Left = 163
      Top = 57
      TabOrder = 0
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit2: TcxTextEdit
      Left = 320
      Top = 57
      TabOrder = 1
      OnKeyPress = cxTextEdit1KeyPress
      Width = 176
    end
    object cxTextEdit3: TcxTextEdit
      Left = 532
      Top = 57
      TabOrder = 2
      OnKeyPress = cxTextEdit1KeyPress
      Width = 211
    end
    object cxTextEdit7: TcxTextEdit
      Left = 163
      Top = 117
      TabOrder = 3
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit8: TcxTextEdit
      Left = 320
      Top = 117
      TabOrder = 4
      OnKeyPress = cxTextEdit1KeyPress
      Width = 176
    end
    object cxTextEdit9: TcxTextEdit
      Left = 532
      Top = 117
      TabOrder = 5
      OnKeyPress = cxTextEdit1KeyPress
      Width = 211
    end
    object cxTextEdit10: TcxTextEdit
      Left = 163
      Top = 147
      TabOrder = 6
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit11: TcxTextEdit
      Left = 320
      Top = 147
      TabOrder = 7
      OnKeyPress = cxTextEdit1KeyPress
      Width = 176
    end
    object cxTextEdit12: TcxTextEdit
      Left = 532
      Top = 147
      TabOrder = 8
      OnKeyPress = cxTextEdit1KeyPress
      Width = 211
    end
    object cxTextEdit13: TcxTextEdit
      Left = 163
      Top = 177
      TabOrder = 9
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit14: TcxTextEdit
      Left = 320
      Top = 177
      TabOrder = 10
      OnKeyPress = cxTextEdit1KeyPress
      Width = 176
    end
    object cxTextEdit15: TcxTextEdit
      Left = 532
      Top = 177
      TabOrder = 11
      OnKeyPress = cxTextEdit1KeyPress
      Width = 211
    end
    object cxTextEdit16: TcxTextEdit
      Left = 163
      Top = 207
      TabOrder = 12
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit17: TcxTextEdit
      Left = 320
      Top = 207
      TabOrder = 13
      OnKeyPress = cxTextEdit1KeyPress
      Width = 176
    end
    object cxTextEdit18: TcxTextEdit
      Left = 532
      Top = 207
      TabOrder = 14
      OnKeyPress = cxTextEdit1KeyPress
      Width = 211
    end
    object cxTextEdit19: TcxTextEdit
      Left = 163
      Top = 237
      TabOrder = 15
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit20: TcxTextEdit
      Left = 320
      Top = 237
      TabOrder = 16
      OnKeyPress = cxTextEdit1KeyPress
      Width = 176
    end
    object cxTextEdit21: TcxTextEdit
      Left = 532
      Top = 237
      TabOrder = 17
      OnKeyPress = cxTextEdit1KeyPress
      Width = 211
    end
    object cxTextEdit22: TcxTextEdit
      Left = 163
      Top = 267
      TabOrder = 18
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit23: TcxTextEdit
      Left = 320
      Top = 267
      TabOrder = 19
      OnKeyPress = cxTextEdit1KeyPress
      Width = 176
    end
    object cxTextEdit24: TcxTextEdit
      Left = 532
      Top = 267
      TabOrder = 20
      OnKeyPress = cxTextEdit1KeyPress
      Width = 211
    end
    object cxTextEdit25: TcxTextEdit
      Left = 163
      Top = 297
      TabOrder = 21
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit26: TcxTextEdit
      Left = 320
      Top = 297
      TabOrder = 22
      OnKeyPress = cxTextEdit1KeyPress
      Width = 176
    end
    object cxTextEdit27: TcxTextEdit
      Left = 532
      Top = 297
      TabOrder = 23
      OnKeyPress = cxTextEdit1KeyPress
      Width = 211
    end
    object cxTextEdit4: TcxTextEdit
      Left = 163
      Top = 87
      TabOrder = 24
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit5: TcxTextEdit
      Left = 320
      Top = 87
      TabOrder = 25
      OnKeyPress = cxTextEdit1KeyPress
      Width = 176
    end
    object cxTextEdit6: TcxTextEdit
      Left = 532
      Top = 87
      TabOrder = 26
      OnKeyPress = cxTextEdit1KeyPress
      Width = 211
    end
  end
  object cxGroupBox3: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 391
    Align = alClient
    Caption = #32467#31639#37329#39069
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 2
    Height = 177
    Width = 773
    object Label14: TLabel
      Left = 67
      Top = 27
      Width = 329
      Height = 19
      Caption = #25903#20986#23567#32467'('#21462#27454#37329#39069'+'#36864#21345#37329#39069'+'#36864#21345#25104#26412')'#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label15: TLabel
      Left = 67
      Top = 67
      Width = 329
      Height = 19
      Caption = #25910#20837#23567#32467'('#20805#20540#37329#39069'+'#24320#25143#37329#39069'+'#34917#21345#25104#26412')'#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label16: TLabel
      Left = 154
      Top = 107
      Width = 242
      Height = 19
      Caption = #25910#25903#32467#31639'('#25910#20837#23567#32467'-'#25903#20986#23567#32467')'#65306
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object cxTextEdit28: TcxTextEdit
      Left = 395
      Top = 25
      TabOrder = 0
      OnKeyPress = cxTextEdit1KeyPress
      Width = 316
    end
    object cxTextEdit29: TcxTextEdit
      Left = 395
      Top = 65
      TabOrder = 1
      OnKeyPress = cxTextEdit1KeyPress
      Width = 316
    end
    object cxTextEdit30: TcxTextEdit
      Left = 395
      Top = 105
      TabOrder = 2
      OnKeyPress = cxTextEdit1KeyPress
      Width = 316
    end
    object ExportBTN: TcxButton
      Left = 207
      Top = 142
      Width = 85
      Height = 25
      Caption = #23548'      '#20986
      Enabled = False
      LookAndFeel.NativeStyle = True
      TabOrder = 3
      OnClick = ExportBTNClick
    end
    object PreviewBTN: TcxButton
      Left = 351
      Top = 142
      Width = 85
      Height = 25
      Caption = #25171#21360#39044#35272
      Enabled = False
      LookAndFeel.NativeStyle = True
      TabOrder = 4
      OnClick = PreviewBTNClick
    end
    object ExitBTN: TcxButton
      Left = 495
      Top = 142
      Width = 85
      Height = 25
      Caption = #36864'      '#20986
      LookAndFeel.NativeStyle = True
      TabOrder = 5
      OnClick = ExitBTNClick
    end
  end
  object JSDataSource: TDataSource
    DataSet = JSADOQuery
    Left = 592
    Top = 376
  end
  object JSADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 720
    Top = 376
  end
  object SaveDialog: TSaveDialog
    FileName = #37325#21629#21517
    Filter = 'xls'
    Left = 728
    Top = 520
  end
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    DataSource = JSDataSource
    BCDToCurrency = False
    Left = 656
    Top = 520
  end
  object frxJSReport: TfrxReport
    Version = '4.9.32'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 40878.427799479200000000
    ReportOptions.LastChange = 40878.447947048610000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 728
    Top = 448
    Datasets = <>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 182.000000000000000000
      PaperHeight = 257.000000000000000000
      PaperSize = 256
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      object ReportTitle1: TfrxReportTitle
        Height = 638.740555350000000000
        Top = 18.897650000000000000
        Width = 612.283860000000000000
        object HeadM: TfrxMemoView
          Width = 616.063390000000000000
          Height = 45.354330710000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -32
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          Left = 263.842610000000000000
          Top = 45.354360000000000000
          Width = 66.141732280000000000
          Height = 28.724409450000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #36215#22987#26085#26399)
          ParentFont = False
        end
        object QSRQM: TfrxMemoView
          Left = 330.330860000000000000
          Top = 45.354360000000000000
          Width = 286.110236220000000000
          Height = 28.724409450000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          Left = 264.346630000000000000
          Top = 74.031540000000000000
          Width = 66.141732280000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #25130#33267#26085#26399)
          ParentFont = False
        end
        object JZRQM: TfrxMemoView
          Left = 329.834880000000000000
          Top = 74.031540000000000000
          Width = 286.110236220000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo9: TfrxMemoView
          Left = 0.677180000000000000
          Top = 45.456710000000000000
          Width = 74.834645670000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #25253#34920#25805#20316#21592)
          ParentFont = False
        end
        object BBCZYM: TfrxMemoView
          Left = 75.504020000000000000
          Top = 45.236240000000000000
          Width = 188.976377950000000000
          Height = 28.724409450000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo11: TfrxMemoView
          Left = -0.259740000000000000
          Top = 73.913420000000000000
          Width = 75.590551180000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #29983#25104#26085#26399)
          ParentFont = False
        end
        object SCRQM: TfrxMemoView
          Left = 75.228510000000000000
          Top = 73.913420000000000000
          Width = 188.976377950000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo1: TfrxMemoView
          Left = 264.606370000000000000
          Top = 102.504020000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #20132#26131#25104#26412#65288#21333#20301'-'#20803#65289#65306)
          ParentFont = False
        end
        object Memo2: TfrxMemoView
          Left = 440.094620000000000000
          Top = 102.504020000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #20132#26131#29616#37329#37329#39069#65288#21333#20301'-'#20803#65289#65306)
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          Top = 102.385900000000000000
          Width = 151.181102360000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #25805#20316#31867#22411)
          ParentFont = False
        end
        object Memo15: TfrxMemoView
          Left = 151.078850000000000000
          Top = 102.385900000000000000
          Width = 113.385826770000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #20132#26131#27425#25968)
          ParentFont = False
        end
        object KCBM: TfrxMemoView
          Left = 264.606370000000000000
          Top = 131.685220000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object KZEM: TfrxMemoView
          Left = 440.094620000000000000
          Top = 131.685220000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo39: TfrxMemoView
          Top = 131.567100000000000000
          Width = 151.181102360000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8W = (
            #24320#25143#65306)
          ParentFont = False
        end
        object KCSM: TfrxMemoView
          Left = 151.078850000000000000
          Top = 131.567100000000000000
          Width = 113.385826770000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ACBM: TfrxMemoView
          Left = 264.606370000000000000
          Top = 160.362400000000000000
          Width = 175.748031500000000000
          Height = 27.968503940000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object AZEM: TfrxMemoView
          Left = 440.094620000000000000
          Top = 160.362400000000000000
          Width = 175.748031500000000000
          Height = 27.968503940000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo43: TfrxMemoView
          Top = 160.244280000000000000
          Width = 151.181102360000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8W = (
            #35835#21345#22120#20805#20540#65306)
          ParentFont = False
        end
        object ACSM: TfrxMemoView
          Left = 151.078850000000000000
          Top = 160.244280000000000000
          Width = 113.385826770000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ICBM: TfrxMemoView
          Left = 264.606370000000000000
          Top = 187.968770000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object IZEM: TfrxMemoView
          Left = 440.094620000000000000
          Top = 187.968770000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo47: TfrxMemoView
          Top = 187.850650000000000000
          Width = 151.181102360000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8W = (
            #20805#20540#26426#20805#20540#65306)
          ParentFont = False
        end
        object ICSM: TfrxMemoView
          Left = 151.078850000000000000
          Top = 187.850650000000000000
          Width = 113.385826770000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object GCBM: TfrxMemoView
          Left = 264.606370000000000000
          Top = 216.645950000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object GZEM: TfrxMemoView
          Left = 440.094620000000000000
          Top = 216.645950000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo51: TfrxMemoView
          Top = 216.527830000000000000
          Width = 151.181102360000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8W = (
            #22351#21345#12289#25346#22833#34917#21345#65306)
          ParentFont = False
        end
        object GCSM: TfrxMemoView
          Left = 151.078850000000000000
          Top = 216.527830000000000000
          Width = 113.385826770000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object DCBM: TfrxMemoView
          Left = 264.606370000000000000
          Top = 245.661720000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object DZEM: TfrxMemoView
          Left = 440.094620000000000000
          Top = 245.661720000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo55: TfrxMemoView
          Top = 245.543600000000000000
          Width = 151.181102360000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8W = (
            #21462#27454#65306)
          ParentFont = False
        end
        object DCSM: TfrxMemoView
          Left = 151.078850000000000000
          Top = 245.543600000000000000
          Width = 113.385826770000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CCBM: TfrxMemoView
          Left = 264.606370000000000000
          Top = 274.338900000000000000
          Width = 175.748031500000000000
          Height = 27.968503940000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CZEM: TfrxMemoView
          Left = 440.094620000000000000
          Top = 274.338900000000000000
          Width = 175.748031500000000000
          Height = 27.968503940000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo59: TfrxMemoView
          Top = 274.220780000000000000
          Width = 151.181102360000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8W = (
            #20805#20540#31649#29702#36153#65306)
          ParentFont = False
        end
        object CCSM: TfrxMemoView
          Left = 151.078850000000000000
          Top = 274.220780000000000000
          Width = 113.385826770000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object TCBM: TfrxMemoView
          Left = 264.606370000000000000
          Top = 301.945270000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object TZEM: TfrxMemoView
          Left = 440.094620000000000000
          Top = 301.945270000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo63: TfrxMemoView
          Top = 301.827150000000000000
          Width = 151.181102360000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8W = (
            #27491#24120#36864#21345#65306)
          ParentFont = False
        end
        object TCSM: TfrxMemoView
          Left = 151.078850000000000000
          Top = 301.827150000000000000
          Width = 113.385826770000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object QCBM: TfrxMemoView
          Left = 264.606370000000000000
          Top = 330.622450000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object QZEM: TfrxMemoView
          Left = 440.094620000000000000
          Top = 330.622450000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo67: TfrxMemoView
          Top = 330.504330000000000000
          Width = 151.181102360000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8W = (
            #26080#21345#36864#21345#65306)
          ParentFont = False
        end
        object QCSM: TfrxMemoView
          Left = 151.078850000000000000
          Top = 330.504330000000000000
          Width = 113.385826770000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object JSCBM: TfrxMemoView
          Left = 264.606370000000000000
          Top = 359.614410000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object JSZEM: TfrxMemoView
          Left = 440.094620000000000000
          Top = 359.614410000000000000
          Width = 175.748031500000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          Top = 359.496290000000000000
          Width = 151.181102360000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haRight
          Memo.UTF8W = (
            #21512#35745#65306)
          ParentFont = False
        end
        object JSCSM: TfrxMemoView
          Left = 151.078850000000000000
          Top = 359.496290000000000000
          Width = 113.385826770000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          Top = 388.291590000000000000
          Width = 332.598542360000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #25903#20986#23567#32467'('#21462#27454#37329#39069'+'#36864#21345#37329#39069'+'#36864#21345#25104#26412')'#65306)
          ParentFont = False
        end
        object ZCXJM: TfrxMemoView
          Left = 332.598640000000000000
          Top = 388.291590000000000000
          Width = 283.464566930000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo14: TfrxMemoView
          Top = 416.527830000000000000
          Width = 332.598542360000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #25910#20837#23567#32467'('#20805#20540#37329#39069'+'#24320#25143#37329#39069'+'#34917#21345#25104#26412')'#65306)
          ParentFont = False
        end
        object SRXJM: TfrxMemoView
          Left = 332.598640000000000000
          Top = 416.527830000000000000
          Width = 283.464566930000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo17: TfrxMemoView
          Top = 444.984540000000000000
          Width = 332.598542360000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #25910#25903#32467#31639'('#25910#20837#23567#32467'-'#25903#20986#23567#32467')'#65306)
          ParentFont = False
        end
        object JSM: TfrxMemoView
          Left = 332.598640000000000000
          Top = 444.984540000000000000
          Width = 283.464566930000000000
          Height = 28.346456690000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
      end
    end
  end
end
