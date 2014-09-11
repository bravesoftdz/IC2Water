object BMQFrm: TBMQFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #37096#38376#28040#36153#26126#32454#26597#35810
  ClientHeight = 437
  ClientWidth = 639
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
    Align = alClient
    Alignment = alCenterCenter
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 0
    Height = 431
    Width = 633
    object cxLabel4: TcxLabel
      Left = 52
      Top = 11
      Caption = #36215#22987#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object BMBeginDateEdit: TcxDateEdit
      Left = 129
      Top = 10
      TabOrder = 1
      OnKeyPress = BMComboBoxKeyPress
      Width = 121
    end
    object cxLabel3: TcxLabel
      Left = 295
      Top = 11
      Caption = #25130#27490#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object BMEndDateEdit: TcxDateEdit
      Left = 372
      Top = 10
      TabOrder = 3
      OnKeyPress = BMComboBoxKeyPress
      Width = 121
    end
    object QueryBTN: TcxButton
      Left = 518
      Top = 50
      Width = 85
      Height = 25
      Caption = #26597'   '#35810
      Colors.Default = clBtnText
      LookAndFeel.NativeStyle = True
      TabOrder = 4
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = QueryBTNClick
    end
    object CTComboBox: TcxComboBox
      Left = 129
      Top = 49
      TabOrder = 5
      OnKeyPress = BMComboBoxKeyPress
      Width = 121
    end
    object cxLabel5: TcxLabel
      Left = 70
      Top = 50
      Caption = #39184'   '#21381':'
      ParentColor = False
      Style.Color = clCream
    end
    object Panel1: TPanel
      Left = 13
      Top = 83
      Width = 605
      Height = 1
      TabOrder = 7
    end
    object CheckBox1: TCheckBox
      Left = 48
      Top = 93
      Width = 97
      Height = 17
      Caption = ' '#26089'  '#39184
      Checked = True
      State = cbChecked
      TabOrder = 8
    end
    object CheckBox2: TCheckBox
      Left = 207
      Top = 92
      Width = 97
      Height = 17
      Caption = ' '#21320'  '#39184
      Checked = True
      State = cbChecked
      TabOrder = 9
    end
    object CheckBox3: TCheckBox
      Left = 366
      Top = 92
      Width = 97
      Height = 17
      Caption = ' '#26202'  '#39184
      Checked = True
      State = cbChecked
      TabOrder = 10
    end
    object CheckBox4: TCheckBox
      Left = 526
      Top = 93
      Width = 97
      Height = 17
      Caption = ' '#22812'  '#23477
      Checked = True
      State = cbChecked
      TabOrder = 11
    end
    object Panel2: TPanel
      Left = 13
      Top = 116
      Width = 605
      Height = 1
      TabOrder = 12
    end
    object cxGroupBox2: TcxGroupBox
      AlignWithMargins = True
      Left = 8
      Top = 138
      Margins.Left = 6
      Margins.Top = 6
      Margins.Right = 6
      Margins.Bottom = 6
      Align = alBottom
      Caption = #26597#35810#32467#26524
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 13
      Height = 285
      Width = 617
      object Label1: TLabel
        Left = 24
        Top = 52
        Width = 57
        Height = 16
        Caption = ' '#26089'  '#39184#65306
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 24
        Top = 92
        Width = 57
        Height = 16
        Caption = ' '#21320'  '#39184#65306
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 24
        Top = 132
        Width = 57
        Height = 16
        Caption = ' '#26202'  '#39184#65306
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 24
        Top = 172
        Width = 57
        Height = 16
        Caption = ' '#22812'  '#23477#65306
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 24
        Top = 212
        Width = 57
        Height = 16
        Caption = ' '#24635'  '#35760#65306
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label6: TLabel
        Left = 111
        Top = 24
        Width = 60
        Height = 16
        Caption = #28040#36153#27425#25968
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label7: TLabel
        Left = 236
        Top = 24
        Width = 75
        Height = 16
        Caption = #28040#36153#24635#37329#39069
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label8: TLabel
        Left = 375
        Top = 24
        Width = 60
        Height = 16
        Caption = #24179#22343#28040#36153
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label9: TLabel
        Left = 510
        Top = 24
        Width = 54
        Height = 16
        Caption = #22791'      '#27880
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object ExportBTN: TcxButton
        Left = 188
        Top = 250
        Width = 75
        Height = 25
        Caption = #23548'   '#20986
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 0
        OnClick = ExportBTNClick
      end
      object PreviewBTN: TcxButton
        Left = 341
        Top = 250
        Width = 75
        Height = 25
        Caption = #25171#21360#39044#35272
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 1
        OnClick = PreviewBTNClick
      end
      object cxTextEdit1: TcxTextEdit
        Left = 81
        Top = 48
        TabOrder = 2
        Width = 121
      end
      object cxTextEdit2: TcxTextEdit
        Left = 213
        Top = 48
        TabOrder = 3
        Width = 121
      end
      object cxTextEdit3: TcxTextEdit
        Left = 345
        Top = 48
        TabOrder = 4
        Width = 121
      end
      object cxTextEdit4: TcxTextEdit
        Left = 478
        Top = 48
        TabOrder = 5
        Width = 121
      end
      object cxTextEdit5: TcxTextEdit
        Left = 81
        Top = 88
        TabOrder = 6
        Width = 121
      end
      object cxTextEdit6: TcxTextEdit
        Left = 213
        Top = 88
        TabOrder = 7
        Width = 121
      end
      object cxTextEdit7: TcxTextEdit
        Left = 345
        Top = 88
        TabOrder = 8
        Width = 121
      end
      object cxTextEdit8: TcxTextEdit
        Left = 478
        Top = 88
        TabOrder = 9
        Width = 121
      end
      object cxTextEdit9: TcxTextEdit
        Left = 81
        Top = 128
        TabOrder = 10
        Width = 121
      end
      object cxTextEdit10: TcxTextEdit
        Left = 213
        Top = 128
        TabOrder = 11
        Width = 121
      end
      object cxTextEdit11: TcxTextEdit
        Left = 345
        Top = 128
        TabOrder = 12
        Width = 121
      end
      object cxTextEdit12: TcxTextEdit
        Left = 478
        Top = 128
        TabOrder = 13
        Width = 121
      end
      object cxTextEdit13: TcxTextEdit
        Left = 81
        Top = 168
        TabOrder = 14
        Width = 121
      end
      object cxTextEdit14: TcxTextEdit
        Left = 213
        Top = 168
        TabOrder = 15
        Width = 121
      end
      object cxTextEdit15: TcxTextEdit
        Left = 345
        Top = 168
        TabOrder = 16
        Width = 121
      end
      object cxTextEdit16: TcxTextEdit
        Left = 478
        Top = 168
        TabOrder = 17
        Width = 121
      end
      object cxTextEdit17: TcxTextEdit
        Left = 81
        Top = 208
        TabOrder = 18
        Width = 121
      end
      object cxTextEdit18: TcxTextEdit
        Left = 213
        Top = 208
        TabOrder = 19
        Width = 121
      end
      object cxTextEdit19: TcxTextEdit
        Left = 345
        Top = 208
        TabOrder = 20
        Width = 121
      end
      object cxTextEdit20: TcxTextEdit
        Left = 478
        Top = 208
        TabOrder = 21
        Width = 121
      end
      object Panel3: TPanel
        Left = 14
        Top = 79
        Width = 590
        Height = 1
        TabOrder = 22
      end
      object Panel4: TPanel
        Left = 14
        Top = 120
        Width = 590
        Height = 1
        TabOrder = 23
      end
      object Panel5: TPanel
        Left = 14
        Top = 159
        Width = 590
        Height = 1
        TabOrder = 24
      end
      object Panel6: TPanel
        Left = 14
        Top = 200
        Width = 590
        Height = 1
        TabOrder = 25
      end
      object Panel7: TPanel
        Left = 14
        Top = 241
        Width = 590
        Height = 1
        TabOrder = 26
      end
    end
    object BMComboBox: TcxComboBox
      Left = 372
      Top = 50
      TabOrder = 14
      OnKeyPress = BMComboBoxKeyPress
      Width = 121
    end
    object lable10: TcxLabel
      Left = 313
      Top = 50
      Caption = #37096'   '#38376':'
      ParentColor = False
      Style.Color = clCream
    end
  end
  object BMADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 96
    Top = 368
  end
  object SaveDialog: TSaveDialog
    Filter = 'xls'
    Left = 504
    Top = 344
  end
  object frxBMTJReport: TfrxReport
    Version = '4.9.32'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 40870.979553125000000000
    ReportOptions.LastChange = 40872.853257916660000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 560
    Top = 368
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
        Height = 525.354670000000000000
        Top = 18.897650000000000000
        Width = 612.283860000000000000
        object Memo2: TfrxMemoView
          Left = 205.448980000000000000
          Width = 200.315090000000000000
          Height = 30.236240000000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #37096#38376#28040#36153#32479#35745#25253#34920)
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          Left = 172.133890000000000000
          Top = 53.031540000000000000
          Width = 66.141732283464600000
          Height = 22.299212600000000000
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
          Left = 238.622140000000000000
          Top = 53.031540000000000000
          Width = 151.181102360000000000
          Height = 22.299212600000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          Left = 390.071120000000000000
          Top = 53.031540000000000000
          Width = 65.385826771653500000
          Height = 22.299212600000000000
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
          Left = 455.559370000000000000
          Top = 53.031540000000000000
          Width = 156.472440940000000000
          Height = 22.299212600000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          Left = 190.181200000000000000
          Top = 30.236240000000000000
          Width = 95.244094490000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #39184#21381)
          ParentFont = False
        end
        object CTM: TfrxMemoView
          Left = 285.669450000000000000
          Top = 30.236240000000000000
          Width = 94.488188980000000000
          Height = 22.677165350000000000
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
          Top = 52.913420000000000000
          Width = 77.102362200000000000
          Height = 22.677165350000000000
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
          Left = 77.488250000000000000
          Top = 52.913420000000000000
          Width = 94.488188980000000000
          Height = 22.677165350000000000
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
          Left = 379.953000000000000000
          Top = 30.236240000000000000
          Width = 75.590551180000000000
          Height = 22.677165350000000000
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
          Left = 455.441250000000000000
          Top = 30.236240000000000000
          Width = 157.228346460000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo13: TfrxMemoView
          Top = 75.590600000000000000
          Width = 612.283464570000000000
          Height = 37.795285350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #30001#20110#22312#26089#39184#12289#21320#39184#12289#26202#39184#12289#22812#23477#26102#38388#27573#20043#22806#20063#26377#21487#33021#26377#28040#36153#35760#24405#65292#25152#20197#24635#35745#21487#33021#19981#26159#20197#19978#22235#20010#25968#25454#30340#24635#21644#9#9#9#9#9#9#9#9#9)
          ParentFont = False
        end
        object Memo14: TfrxMemoView
          Top = 113.385900000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #39184#21035)
          ParentFont = False
        end
        object Memo15: TfrxMemoView
          Left = 122.488250000000000000
          Top = 113.385900000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #28040#36153#27425#25968)
          ParentFont = False
        end
        object Memo16: TfrxMemoView
          Left = 244.976500000000000000
          Top = 113.385900000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #28040#36153#24635#39069)
          ParentFont = False
        end
        object Memo17: TfrxMemoView
          Left = 367.464750000000000000
          Top = 113.385900000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #24179#22343#28040#36153)
          ParentFont = False
        end
        object Memo18: TfrxMemoView
          Left = 489.953000000000000000
          Top = 113.385900000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #22791#27880)
          ParentFont = False
        end
        object Memo19: TfrxMemoView
          Top = 136.063080000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #26089#39184)
          ParentFont = False
        end
        object BFCSM: TfrxMemoView
          Left = 122.488250000000000000
          Top = 136.063080000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object BFZEM: TfrxMemoView
          Left = 244.976500000000000000
          Top = 136.063080000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object BFPJM: TfrxMemoView
          Left = 367.464750000000000000
          Top = 136.063080000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object BFBZM: TfrxMemoView
          Left = 489.953000000000000000
          Top = 136.063080000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object Memo24: TfrxMemoView
          Top = 158.740260000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #21320#39184)
          ParentFont = False
        end
        object LHCSM: TfrxMemoView
          Left = 122.488250000000000000
          Top = 158.740260000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object LHZEM: TfrxMemoView
          Left = 244.976500000000000000
          Top = 158.740260000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object LHPJM: TfrxMemoView
          Left = 367.464750000000000000
          Top = 158.740260000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object LHBZM: TfrxMemoView
          Left = 489.953000000000000000
          Top = 158.740260000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object Memo29: TfrxMemoView
          Top = 181.417440000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #26202#39184)
          ParentFont = False
        end
        object SRCSM: TfrxMemoView
          Left = 122.488250000000000000
          Top = 181.417440000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object SRZEM: TfrxMemoView
          Left = 244.976500000000000000
          Top = 181.417440000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object SRPJM: TfrxMemoView
          Left = 367.464750000000000000
          Top = 181.417440000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object SRBZM: TfrxMemoView
          Left = 489.953000000000000000
          Top = 181.417440000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object Memo34: TfrxMemoView
          Top = 204.094620000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #22812#23477)
          ParentFont = False
        end
        object NTCSM: TfrxMemoView
          Left = 122.488250000000000000
          Top = 204.094620000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object NTZEM: TfrxMemoView
          Left = 244.976500000000000000
          Top = 204.094620000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object NTPJM: TfrxMemoView
          Left = 367.464750000000000000
          Top = 204.094620000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object NTBZM: TfrxMemoView
          Left = 489.953000000000000000
          Top = 204.094620000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
          Top = 226.771800000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #24635#35745)
          ParentFont = False
        end
        object ZJCSM: TfrxMemoView
          Left = 122.488250000000000000
          Top = 226.771800000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object ZJZEM: TfrxMemoView
          Left = 244.976500000000000000
          Top = 226.771800000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object ZJPJM: TfrxMemoView
          Left = 367.464750000000000000
          Top = 226.771800000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object ZJBZM: TfrxMemoView
          Left = 489.953000000000000000
          Top = 226.771800000000000000
          Width = 122.456692910000000000
          Height = 22.677165350000000000
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
        object Memo4: TfrxMemoView
          Top = 30.236240000000000000
          Width = 95.244094490000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #37096#38376)
          ParentFont = False
        end
        object BMM: TfrxMemoView
          Left = 95.488250000000000000
          Top = 30.236240000000000000
          Width = 94.488188980000000000
          Height = 22.677165350000000000
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
      object PageFooter1: TfrxPageFooter
        Height = 22.677180000000000000
        Top = 604.724800000000000000
        Width = 612.283860000000000000
        object Memo1: TfrxMemoView
          Left = 642.520100000000000000
          Width = 75.590600000000000000
          Height = 18.897650000000000000
          ShowHint = False
          HAlign = haRight
          Memo.UTF8W = (
            '[Page#]')
        end
      end
    end
  end
end
