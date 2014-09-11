object SZHZQFrm: TSZHZQFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #25910#25903#27719#24635#24773#20917
  ClientHeight = 729
  ClientWidth = 784
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
    Height = 70
    Width = 778
    object ZHBeginDateEdit: TcxDateEdit
      Left = 99
      Top = 11
      TabOrder = 0
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
      Top = 12
      Caption = #25130#27490#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object ZHEndDateEdit: TcxDateEdit
      Left = 325
      Top = 11
      TabOrder = 3
      Width = 121
    end
    object QueryBTN: TcxButton
      Left = 677
      Top = 11
      Width = 75
      Height = 25
      Caption = #26597'   '#35810
      LookAndFeel.NativeStyle = True
      TabOrder = 4
      OnClick = QueryBTNClick
    end
    object BMComboBox: TcxComboBox
      Left = 532
      Top = 11
      TabOrder = 5
      Width = 121
    end
    object cxLabel1: TcxLabel
      Left = 472
      Top = 12
      Caption = #21333'   '#20301':'
      ParentColor = False
      Style.Color = clCream
    end
    object Panel1: TPanel
      Left = 2
      Top = 38
      Width = 774
      Height = 30
      Align = alBottom
      Caption = #26597#35810#36807#31243#32791#26102#36739#38271#65292#35831#32784#24515#31561#24453#65281
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      ExplicitTop = 35
    end
  end
  object cxGroupBox3: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 551
    Align = alClient
    Caption = #21508#28040#36153#28857#33829#19994#24773#20917#27719#24635
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 1
    ExplicitTop = 559
    ExplicitHeight = 188
    Height = 175
    Width = 778
    object Label14: TLabel
      Left = 177
      Top = 16
      Width = 68
      Height = 19
      Caption = #39184#21381#21517#31216
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label15: TLabel
      Left = 355
      Top = 16
      Width = 68
      Height = 19
      Caption = #28040#36153#37329#39069
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label16: TLabel
      Left = 539
      Top = 16
      Width = 68
      Height = 19
      Caption = #28040#36153#20154#27425
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ExportBTN: TcxButton
      Left = 209
      Top = 140
      Width = 85
      Height = 25
      Caption = #23548'      '#20986
      Enabled = False
      LookAndFeel.NativeStyle = True
      TabOrder = 0
      OnClick = ExportBTNClick
    end
    object PreviewBTN: TcxButton
      Left = 355
      Top = 140
      Width = 85
      Height = 25
      Caption = #25171#21360#39044#35272
      Enabled = False
      LookAndFeel.NativeStyle = True
      TabOrder = 1
      OnClick = PreviewBTNClick
    end
    object ExitBTN: TcxButton
      Left = 497
      Top = 140
      Width = 85
      Height = 25
      Caption = #36864'      '#20986
      LookAndFeel.NativeStyle = True
      TabOrder = 2
      OnClick = ExitBTNClick
    end
    object cxMemo1: TcxMemo
      Left = 130
      Top = 41
      Properties.ScrollBars = ssVertical
      TabOrder = 3
      OnKeyPress = cxMemo1KeyPress
      Height = 93
      Width = 525
    end
  end
  object cxGroupBox2: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 79
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
    TabOrder = 2
    ExplicitTop = 87
    Height = 466
    Width = 778
    object Label1: TLabel
      Left = 20
      Top = 26
      Width = 68
      Height = 19
      Caption = #31995#32479#36816#34892
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 257
      Top = 26
      Width = 102
      Height = 19
      Caption = #26412#21306#36134#25143#20154#25968
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 381
      Top = 26
      Width = 119
      Height = 19
      Caption = #26412#21306#36134#25143#24635#20313#39069
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 652
      Top = 26
      Width = 102
      Height = 19
      Caption = #26412#21306#29616#37329#24635#39069
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label17: TLabel
      Left = 521
      Top = 26
      Width = 102
      Height = 19
      Caption = #26412#21306#25276#37329#24635#39069
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 9
      Top = 151
      Width = 102
      Height = 19
      Caption = #26412#21306#21464#21270#26126#32454
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 241
      Top = 151
      Width = 102
      Height = 19
      Caption = #36134#25143#22686#20943#20154#25968
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label7: TLabel
      Left = 365
      Top = 151
      Width = 136
      Height = 19
      Caption = #36134#25143#29616#20313#39069#22686#21152#39069
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 530
      Top = 151
      Width = 85
      Height = 19
      Caption = #25276#37329#22686#21152#39069
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label9: TLabel
      Left = 660
      Top = 151
      Width = 85
      Height = 19
      Caption = #29616#37329#22686#21152#39069
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label10: TLabel
      Left = 137
      Top = 151
      Width = 68
      Height = 19
      Caption = #21457#29983#20154#27425
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label11: TLabel
      Left = 37
      Top = 55
      Width = 51
      Height = 19
      Caption = #29616#29366#24577
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label12: TLabel
      Left = 37
      Top = 86
      Width = 51
      Height = 19
      Caption = #21407#29366#24577
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 20
      Top = 117
      Width = 68
      Height = 19
      Caption = #24635#21464#21270#37327
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label18: TLabel
      Left = 13
      Top = 246
      Width = 85
      Height = 19
      Caption = #20805#20540#26426#20805#20540
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label19: TLabel
      Left = 13
      Top = 214
      Width = 85
      Height = 19
      Caption = #35835#21345#22120#23384#27454
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label20: TLabel
      Left = 20
      Top = 183
      Width = 68
      Height = 19
      Caption = #21345#29255#28040#36153
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label21: TLabel
      Left = 24
      Top = 341
      Width = 64
      Height = 19
      Caption = #24320'      '#25143
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label22: TLabel
      Left = 24
      Top = 309
      Width = 64
      Height = 19
      Caption = #21462'      '#27454
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label23: TLabel
      Left = 24
      Top = 278
      Width = 64
      Height = 19
      Caption = #34917'      '#36148
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label24: TLabel
      Left = 24
      Top = 373
      Width = 64
      Height = 19
      Caption = #36864'      '#21345
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label25: TLabel
      Left = 24
      Top = 405
      Width = 64
      Height = 19
      Caption = #34917'      '#21345
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label26: TLabel
      Left = 24
      Top = 437
      Width = 64
      Height = 19
      Caption = #24635'      '#35745
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clPurple
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object cxTextEdit1: TcxTextEdit
      Left = 248
      Top = 50
      TabOrder = 0
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit2: TcxTextEdit
      Left = 380
      Top = 50
      TabOrder = 1
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit3: TcxTextEdit
      Left = 512
      Top = 50
      TabOrder = 2
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit4: TcxTextEdit
      Left = 644
      Top = 50
      TabOrder = 3
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit5: TcxTextEdit
      Left = 248
      Top = 81
      TabOrder = 4
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit6: TcxTextEdit
      Left = 380
      Top = 81
      TabOrder = 5
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit7: TcxTextEdit
      Left = 512
      Top = 81
      TabOrder = 6
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit8: TcxTextEdit
      Left = 644
      Top = 81
      TabOrder = 7
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit9: TcxTextEdit
      Left = 248
      Top = 112
      TabOrder = 8
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit10: TcxTextEdit
      Left = 380
      Top = 112
      TabOrder = 9
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit11: TcxTextEdit
      Left = 512
      Top = 112
      TabOrder = 10
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit12: TcxTextEdit
      Left = 644
      Top = 112
      TabOrder = 11
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit13: TcxTextEdit
      Left = 116
      Top = 181
      TabOrder = 12
      OnKeyPress = cxTextEdit1KeyPress
      Width = 110
    end
    object cxTextEdit15: TcxTextEdit
      Left = 365
      Top = 181
      TabOrder = 13
      OnKeyPress = cxTextEdit1KeyPress
      Width = 140
    end
    object cxTextEdit22: TcxTextEdit
      Left = 644
      Top = 212
      TabOrder = 14
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit20: TcxTextEdit
      Left = 365
      Top = 212
      TabOrder = 15
      OnKeyPress = cxTextEdit1KeyPress
      Width = 140
    end
    object cxTextEdit18: TcxTextEdit
      Left = 116
      Top = 212
      TabOrder = 16
      OnKeyPress = cxTextEdit1KeyPress
      Width = 110
    end
    object cxTextEdit23: TcxTextEdit
      Left = 116
      Top = 244
      TabOrder = 17
      OnKeyPress = cxTextEdit1KeyPress
      Width = 110
    end
    object cxTextEdit25: TcxTextEdit
      Left = 365
      Top = 244
      TabOrder = 18
      OnKeyPress = cxTextEdit1KeyPress
      Width = 140
    end
    object cxTextEdit27: TcxTextEdit
      Left = 644
      Top = 244
      TabOrder = 19
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit28: TcxTextEdit
      Left = 116
      Top = 276
      TabOrder = 20
      OnKeyPress = cxTextEdit1KeyPress
      Width = 110
    end
    object cxTextEdit30: TcxTextEdit
      Left = 365
      Top = 276
      TabOrder = 21
      OnKeyPress = cxTextEdit1KeyPress
      Width = 140
    end
    object cxTextEdit32: TcxTextEdit
      Left = 644
      Top = 276
      TabOrder = 22
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit33: TcxTextEdit
      Left = 116
      Top = 307
      TabOrder = 23
      OnKeyPress = cxTextEdit1KeyPress
      Width = 110
    end
    object cxTextEdit35: TcxTextEdit
      Left = 365
      Top = 307
      TabOrder = 24
      OnKeyPress = cxTextEdit1KeyPress
      Width = 140
    end
    object cxTextEdit37: TcxTextEdit
      Left = 644
      Top = 307
      TabOrder = 25
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit38: TcxTextEdit
      Left = 116
      Top = 339
      TabOrder = 26
      OnKeyPress = cxTextEdit1KeyPress
      Width = 110
    end
    object cxTextEdit39: TcxTextEdit
      Left = 235
      Top = 339
      TabOrder = 27
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit40: TcxTextEdit
      Left = 365
      Top = 339
      TabOrder = 28
      OnKeyPress = cxTextEdit1KeyPress
      Width = 140
    end
    object cxTextEdit41: TcxTextEdit
      Left = 514
      Top = 339
      TabOrder = 29
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit42: TcxTextEdit
      Left = 644
      Top = 339
      TabOrder = 30
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit43: TcxTextEdit
      Left = 116
      Top = 371
      TabOrder = 31
      OnKeyPress = cxTextEdit1KeyPress
      Width = 110
    end
    object cxTextEdit44: TcxTextEdit
      Left = 235
      Top = 371
      TabOrder = 32
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit45: TcxTextEdit
      Left = 365
      Top = 371
      TabOrder = 33
      OnKeyPress = cxTextEdit1KeyPress
      Width = 140
    end
    object cxTextEdit46: TcxTextEdit
      Left = 514
      Top = 371
      TabOrder = 34
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit47: TcxTextEdit
      Left = 644
      Top = 371
      TabOrder = 35
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit48: TcxTextEdit
      Left = 116
      Top = 403
      TabOrder = 36
      OnKeyPress = cxTextEdit1KeyPress
      Width = 110
    end
    object cxTextEdit52: TcxTextEdit
      Left = 644
      Top = 403
      TabOrder = 37
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit53: TcxTextEdit
      Left = 116
      Top = 435
      TabOrder = 38
      OnKeyPress = cxTextEdit1KeyPress
      Width = 110
    end
    object cxTextEdit54: TcxTextEdit
      Left = 235
      Top = 435
      TabOrder = 39
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit55: TcxTextEdit
      Left = 365
      Top = 435
      TabOrder = 40
      OnKeyPress = cxTextEdit1KeyPress
      Width = 140
    end
    object cxTextEdit56: TcxTextEdit
      Left = 514
      Top = 435
      TabOrder = 41
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit57: TcxTextEdit
      Left = 644
      Top = 435
      TabOrder = 42
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
    object cxTextEdit51: TcxTextEdit
      Left = 514
      Top = 403
      TabOrder = 43
      OnKeyPress = cxTextEdit1KeyPress
      Width = 121
    end
  end
  object ZHDataSource: TDataSource
    DataSet = ZHADOQuery
    Left = 744
    Top = 408
  end
  object ZHADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 744
    Top = 464
  end
  object frxZHReport: TfrxReport
    Version = '4.9.32'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 40881.930915428200000000
    ReportOptions.LastChange = 40896.521620729160000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 744
    Top = 520
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
        Height = 873.071430000000000000
        Top = 18.897650000000000000
        Width = 612.283860000000000000
        object Memo1: TfrxMemoView
          Width = 612.283860000000000000
          Height = 41.574830000000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -35
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #25910#25903#27719#24635#25253#34920)
          ParentFont = False
        end
        object Memo2: TfrxMemoView
          Left = 415.543600000000000000
          Top = 41.574830000000000000
          Width = 94.488188980000000000
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
            #25253#34920#25805#20316#21592':')
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          Left = 283.464750000000000000
          Top = 64.252010000000000000
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
            #26597#35810#21333#20301#65306)
          ParentFont = False
        end
        object BMstr: TfrxMemoView
          Left = 359.393940000000000000
          Top = 64.252010000000000000
          Width = 253.228441650000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CZY: TfrxMemoView
          Left = 510.575140000000000000
          Top = 41.574830000000000000
          Width = 102.047241650000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo6: TfrxMemoView
          Left = -0.661410000000000000
          Top = 41.574830000000000000
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
            #36215#22987#26102#38388)
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          Left = 207.110390000000000000
          Top = 41.574830000000000000
          Width = 76.346456692913400000
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
            #25130#27490#26102#38388)
          ParentFont = False
        end
        object Beginstr: TfrxMemoView
          Left = 75.165430000000000000
          Top = 41.574830000000000000
          Width = 132.283464570000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Endstr: TfrxMemoView
          Left = 282.937230000000000000
          Top = 41.574830000000000000
          Width = 132.283464570000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo10: TfrxMemoView
          Top = 64.252010000000000000
          Width = 102.047244090000000000
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
            #25253#34920#29983#25104#26102#38388)
          ParentFont = False
        end
        object SCRQ: TfrxMemoView
          Left = 102.047310000000000000
          Top = 64.252010000000000000
          Width = 181.417322830000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          Top = 86.929190000000000000
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
            #31995#32479#36816#34892)
          ParentFont = False
        end
        object Memo13: TfrxMemoView
          Left = 75.590600000000000000
          Top = 86.929190000000000000
          Width = 105.826791180000000000
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
            #26412#21306#36134#25143#20154#25968)
          ParentFont = False
        end
        object Memo14: TfrxMemoView
          Left = 181.417440000000000000
          Top = 86.929190000000000000
          Width = 162.519741180000000000
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
            #26412#21306#36134#25143#24635#20313#39069)
          ParentFont = False
        end
        object Memo15: TfrxMemoView
          Left = 343.937230000000000000
          Top = 86.929190000000000000
          Width = 128.503971180000000000
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
            #26412#21306#25276#37329#24635#39069)
          ParentFont = False
        end
        object Memo16: TfrxMemoView
          Left = 472.441250000000000000
          Top = 86.929190000000000000
          Width = 139.842561180000000000
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
            #26412#21306#29616#37329#24635#39069)
          ParentFont = False
        end
        object Memo17: TfrxMemoView
          Top = 109.606370000000000000
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
            #29616#29366#24577)
          ParentFont = False
        end
        object XZT1str: TfrxMemoView
          Left = 75.590600000000000000
          Top = 109.606370000000000000
          Width = 105.826791180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object XZT2str: TfrxMemoView
          Left = 181.417440000000000000
          Top = 109.606370000000000000
          Width = 162.519741180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object XZT3str: TfrxMemoView
          Left = 343.937230000000000000
          Top = 109.606370000000000000
          Width = 128.503971180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object XZT4str: TfrxMemoView
          Left = 472.441250000000000000
          Top = 109.606370000000000000
          Width = 139.842561180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo22: TfrxMemoView
          Top = 132.283550000000000000
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
            #21407#29366#24577)
          ParentFont = False
        end
        object YZT1str: TfrxMemoView
          Left = 75.590600000000000000
          Top = 132.283550000000000000
          Width = 105.826791180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object YZT2str: TfrxMemoView
          Left = 181.417440000000000000
          Top = 132.283550000000000000
          Width = 162.519741180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object YZT3str: TfrxMemoView
          Left = 343.937230000000000000
          Top = 132.283550000000000000
          Width = 128.503971180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object YZT4str: TfrxMemoView
          Left = 472.441250000000000000
          Top = 132.283550000000000000
          Width = 139.842561180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo27: TfrxMemoView
          Top = 154.960730000000000000
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
            #24635#21464#21270#37327)
          ParentFont = False
        end
        object ZBHL1str: TfrxMemoView
          Left = 75.590600000000000000
          Top = 154.960730000000000000
          Width = 105.826791180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ZBHL2str: TfrxMemoView
          Left = 181.417440000000000000
          Top = 154.960730000000000000
          Width = 162.519741180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ZBHL3str: TfrxMemoView
          Left = 343.937230000000000000
          Top = 154.960730000000000000
          Width = 128.503971180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ZBHL4str: TfrxMemoView
          Left = 472.441250000000000000
          Top = 154.960730000000000000
          Width = 139.842561180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo32: TfrxMemoView
          Top = 177.637910000000000000
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
            #21464#21270#26126#32454)
          ParentFont = False
        end
        object Memo33: TfrxMemoView
          Left = 75.590600000000000000
          Top = 177.637910000000000000
          Width = 86.929133860000000000
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
            #21457#29983#20154#27425)
          ParentFont = False
        end
        object Memo34: TfrxMemoView
          Left = 162.417440000000000000
          Top = 177.637910000000000000
          Width = 102.047248980000000000
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
            #36134#25143#22686#20943#20154#25968)
          ParentFont = False
        end
        object Memo35: TfrxMemoView
          Left = 400.630180000000000000
          Top = 177.637910000000000000
          Width = 102.047261180000000000
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
            #25276#37329#22686#21152#39069)
          ParentFont = False
        end
        object Memo36: TfrxMemoView
          Left = 502.677490000000000000
          Top = 177.637910000000000000
          Width = 109.606321180000000000
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
            #29616#37329#22686#21152#39069)
          ParentFont = False
        end
        object Memo37: TfrxMemoView
          Left = 264.567100000000000000
          Top = 177.637910000000000000
          Width = 136.063031180000000000
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
            #36134#25143#29616#20313#39069#22686#21152#39069)
          ParentFont = False
        end
        object Memo38: TfrxMemoView
          Top = 200.315090000000000000
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
            #21345#29255#28040#36153)
          ParentFont = False
        end
        object KPXF1str: TfrxMemoView
          Left = 75.590600000000000000
          Top = 200.315090000000000000
          Width = 86.929133860000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo40: TfrxMemoView
          Left = 162.417440000000000000
          Top = 200.315090000000000000
          Width = 102.047248980000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo41: TfrxMemoView
          Left = 400.630180000000000000
          Top = 200.315090000000000000
          Width = 102.047261180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo42: TfrxMemoView
          Left = 502.677490000000000000
          Top = 200.315090000000000000
          Width = 109.606321180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object KPXF2str: TfrxMemoView
          Left = 264.567100000000000000
          Top = 200.315090000000000000
          Width = 136.063031180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo44: TfrxMemoView
          Top = 222.992270000000000000
          Width = 75.590551180000000000
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
            #35835#21345#22120#23384#27454)
          ParentFont = False
        end
        object DKQCK1str: TfrxMemoView
          Left = 75.590600000000000000
          Top = 222.992270000000000000
          Width = 86.929133860000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo46: TfrxMemoView
          Left = 162.417440000000000000
          Top = 222.992270000000000000
          Width = 102.047248980000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo47: TfrxMemoView
          Left = 400.630180000000000000
          Top = 222.992270000000000000
          Width = 102.047261180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object DKQCK3str: TfrxMemoView
          Left = 502.677490000000000000
          Top = 222.992270000000000000
          Width = 109.606321180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object DKQCK2str: TfrxMemoView
          Left = 264.567100000000000000
          Top = 222.992270000000000000
          Width = 136.063031180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo50: TfrxMemoView
          Top = 245.669450000000000000
          Width = 75.590551180000000000
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
            #20805#20540#26426#20805#20540)
          ParentFont = False
        end
        object CZJCZ1str: TfrxMemoView
          Left = 75.590600000000000000
          Top = 245.669450000000000000
          Width = 86.929133860000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo52: TfrxMemoView
          Left = 162.417440000000000000
          Top = 245.669450000000000000
          Width = 102.047248980000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo53: TfrxMemoView
          Left = 400.630180000000000000
          Top = 245.669450000000000000
          Width = 102.047261180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CZJCZ3str: TfrxMemoView
          Left = 502.677490000000000000
          Top = 245.669450000000000000
          Width = 109.606321180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CZJCZ2str: TfrxMemoView
          Left = 264.567100000000000000
          Top = 245.669450000000000000
          Width = 136.063031180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo56: TfrxMemoView
          Top = 268.346630000000000000
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
            #34917'      '#36148)
          ParentFont = False
        end
        object BT1str: TfrxMemoView
          Left = 75.590600000000000000
          Top = 268.346630000000000000
          Width = 86.929133860000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo58: TfrxMemoView
          Left = 162.417440000000000000
          Top = 268.346630000000000000
          Width = 102.047248980000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo59: TfrxMemoView
          Left = 400.630180000000000000
          Top = 268.346630000000000000
          Width = 102.047261180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object BT3str: TfrxMemoView
          Left = 502.677490000000000000
          Top = 268.346630000000000000
          Width = 109.606321180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object BT2str: TfrxMemoView
          Left = 264.567100000000000000
          Top = 268.346630000000000000
          Width = 136.063031180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo62: TfrxMemoView
          Top = 291.023810000000000000
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
            #21462'      '#27454)
          ParentFont = False
        end
        object QK1str: TfrxMemoView
          Left = 75.590600000000000000
          Top = 291.023810000000000000
          Width = 86.929133860000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo64: TfrxMemoView
          Left = 162.417440000000000000
          Top = 291.023810000000000000
          Width = 102.047248980000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo65: TfrxMemoView
          Left = 400.630180000000000000
          Top = 291.023810000000000000
          Width = 102.047261180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object QK3str: TfrxMemoView
          Left = 502.677490000000000000
          Top = 291.023810000000000000
          Width = 109.606321180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object QK2str: TfrxMemoView
          Left = 264.567100000000000000
          Top = 291.023810000000000000
          Width = 136.063031180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo68: TfrxMemoView
          Top = 313.700990000000000000
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
            #24320'      '#25143)
          ParentFont = False
        end
        object KH1str: TfrxMemoView
          Left = 75.590600000000000000
          Top = 313.700990000000000000
          Width = 86.929133860000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object KH2str: TfrxMemoView
          Left = 162.417440000000000000
          Top = 313.700990000000000000
          Width = 102.047248980000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object KH4str: TfrxMemoView
          Left = 400.630180000000000000
          Top = 313.700990000000000000
          Width = 102.047261180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object KH5str: TfrxMemoView
          Left = 502.677490000000000000
          Top = 313.700990000000000000
          Width = 109.606321180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object KH3str: TfrxMemoView
          Left = 264.567100000000000000
          Top = 313.700990000000000000
          Width = 136.063031180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo74: TfrxMemoView
          Top = 336.378170000000000000
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
            #36864'      '#21345)
          ParentFont = False
        end
        object TK1str: TfrxMemoView
          Left = 75.590600000000000000
          Top = 336.378170000000000000
          Width = 86.929133860000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object TK2str: TfrxMemoView
          Left = 162.417440000000000000
          Top = 336.378170000000000000
          Width = 102.047248980000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object TK4str: TfrxMemoView
          Left = 400.630180000000000000
          Top = 336.378170000000000000
          Width = 102.047261180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object TK5str: TfrxMemoView
          Left = 502.677490000000000000
          Top = 336.378170000000000000
          Width = 109.606321180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object TK3str: TfrxMemoView
          Left = 264.567100000000000000
          Top = 336.378170000000000000
          Width = 136.063031180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo80: TfrxMemoView
          Top = 359.055350000000000000
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
            #34917'      '#21345)
          ParentFont = False
        end
        object BK1str: TfrxMemoView
          Left = 75.590600000000000000
          Top = 359.055350000000000000
          Width = 86.929133860000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo82: TfrxMemoView
          Left = 162.417440000000000000
          Top = 359.055350000000000000
          Width = 102.047248980000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object BK2str: TfrxMemoView
          Left = 400.630180000000000000
          Top = 359.055350000000000000
          Width = 102.047261180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object BK3str: TfrxMemoView
          Left = 502.677490000000000000
          Top = 359.055350000000000000
          Width = 109.606321180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo85: TfrxMemoView
          Left = 264.567100000000000000
          Top = 359.055350000000000000
          Width = 136.063031180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo86: TfrxMemoView
          Top = 381.732530000000000000
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
            #24635'      '#35745)
          ParentFont = False
        end
        object ZJ1str: TfrxMemoView
          Left = 75.590600000000000000
          Top = 381.732530000000000000
          Width = 86.929133860000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ZJ2str: TfrxMemoView
          Left = 162.417440000000000000
          Top = 381.732530000000000000
          Width = 102.047248980000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ZJ4str: TfrxMemoView
          Left = 400.630180000000000000
          Top = 381.732530000000000000
          Width = 102.047261180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ZJ5str: TfrxMemoView
          Left = 502.677490000000000000
          Top = 381.732530000000000000
          Width = 109.606321180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ZJ3str: TfrxMemoView
          Left = 264.567100000000000000
          Top = 381.732530000000000000
          Width = 136.063031180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo92: TfrxMemoView
          Top = 404.409710000000000000
          Width = 612.283860000000000000
          Height = 34.015770000000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -27
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #21508#28040#36153#28857#33829#19994#24773#20917#27719#24635)
          ParentFont = False
        end
        object Memo93: TfrxMemoView
          Left = 207.874150000000000000
          Top = 438.425480000000000000
          Width = 234.330811180000000000
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
            #28040#36153#37329#39069)
          ParentFont = False
        end
        object Memo94: TfrxMemoView
          Left = 442.205010000000000000
          Top = 438.425480000000000000
          Width = 170.078801180000000000
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
        object Memo95: TfrxMemoView
          Top = 438.425480000000000000
          Width = 207.874101180000000000
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
            #39184#21381#21517#31216)
          ParentFont = False
        end
        object SFZE1: TfrxMemoView
          Left = 207.874150000000000000
          Top = 461.102660000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS1: TfrxMemoView
          Left = 442.205010000000000000
          Top = 461.102660000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT1: TfrxMemoView
          Top = 461.102660000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE2: TfrxMemoView
          Left = 207.874150000000000000
          Top = 483.779840000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS2: TfrxMemoView
          Left = 442.205010000000000000
          Top = 483.779840000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT2: TfrxMemoView
          Top = 483.779840000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE3: TfrxMemoView
          Left = 207.874150000000000000
          Top = 506.457020000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS3: TfrxMemoView
          Left = 442.205010000000000000
          Top = 506.457020000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT3: TfrxMemoView
          Top = 506.457020000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE4: TfrxMemoView
          Left = 207.874150000000000000
          Top = 529.134200000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS4: TfrxMemoView
          Left = 442.205010000000000000
          Top = 529.134200000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT4: TfrxMemoView
          Top = 529.134200000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE5: TfrxMemoView
          Left = 207.874150000000000000
          Top = 551.811380000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS5: TfrxMemoView
          Left = 442.205010000000000000
          Top = 551.811380000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT5: TfrxMemoView
          Top = 551.811380000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE6: TfrxMemoView
          Left = 207.874150000000000000
          Top = 574.488560000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS6: TfrxMemoView
          Left = 442.205010000000000000
          Top = 574.488560000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT6: TfrxMemoView
          Top = 574.488560000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE7: TfrxMemoView
          Left = 207.874150000000000000
          Top = 597.165740000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS7: TfrxMemoView
          Left = 442.205010000000000000
          Top = 597.165740000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT7: TfrxMemoView
          Top = 597.165740000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE8: TfrxMemoView
          Left = 207.874150000000000000
          Top = 619.842920000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS8: TfrxMemoView
          Left = 442.205010000000000000
          Top = 619.842920000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT8: TfrxMemoView
          Top = 619.842920000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE9: TfrxMemoView
          Left = 207.874150000000000000
          Top = 642.520100000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS9: TfrxMemoView
          Left = 442.205010000000000000
          Top = 642.520100000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT9: TfrxMemoView
          Top = 642.520100000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE10: TfrxMemoView
          Left = 207.874150000000000000
          Top = 665.197280000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS10: TfrxMemoView
          Left = 442.205010000000000000
          Top = 665.197280000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT10: TfrxMemoView
          Top = 665.197280000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE11: TfrxMemoView
          Left = 207.874150000000000000
          Top = 687.874460000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS11: TfrxMemoView
          Left = 442.205010000000000000
          Top = 687.874460000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT11: TfrxMemoView
          Top = 687.874460000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE12: TfrxMemoView
          Left = 207.874150000000000000
          Top = 710.551640000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS12: TfrxMemoView
          Left = 442.205010000000000000
          Top = 710.551640000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT12: TfrxMemoView
          Top = 710.551640000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE13: TfrxMemoView
          Left = 207.874150000000000000
          Top = 733.228820000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS13: TfrxMemoView
          Left = 442.205010000000000000
          Top = 733.228820000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT13: TfrxMemoView
          Top = 733.228820000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE14: TfrxMemoView
          Left = 207.874150000000000000
          Top = 755.906000000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS14: TfrxMemoView
          Left = 442.205010000000000000
          Top = 755.906000000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT14: TfrxMemoView
          Top = 755.906000000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE15: TfrxMemoView
          Left = 207.874150000000000000
          Top = 778.583180000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS15: TfrxMemoView
          Left = 442.205010000000000000
          Top = 778.583180000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT15: TfrxMemoView
          Top = 778.583180000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE16: TfrxMemoView
          Left = 207.874150000000000000
          Top = 801.260360000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS16: TfrxMemoView
          Left = 442.205010000000000000
          Top = 801.260360000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT16: TfrxMemoView
          Top = 801.260360000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE17: TfrxMemoView
          Left = 207.874150000000000000
          Top = 823.937540000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS17: TfrxMemoView
          Left = 442.205010000000000000
          Top = 823.937540000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT17: TfrxMemoView
          Top = 823.937540000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SFZE18: TfrxMemoView
          Left = 207.874150000000000000
          Top = 846.614720000000000000
          Width = 234.330811180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CS18: TfrxMemoView
          Left = 442.205010000000000000
          Top = 846.614720000000000000
          Width = 170.078801180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CT18: TfrxMemoView
          Top = 846.614720000000000000
          Width = 207.874101180000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
      end
    end
  end
  object SaveDialog: TSaveDialog
    FileName = #37325#21629#21517
    Filter = 'xls'
    Left = 744
    Top = 632
  end
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    DataSource = ZHDataSource
    BCDToCurrency = False
    Left = 744
    Top = 576
  end
  object STADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 648
    Top = 520
  end
  object ADOQuery1: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 576
    Top = 456
  end
  object ADOQuery2: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 584
    Top = 520
  end
end
