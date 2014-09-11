object TKQFrm: TTKQFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = #36864#21345#26126#32454#26597#35810
  ClientHeight = 648
  ClientWidth = 806
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
    Height = 126
    Width = 800
    object cxLabel15: TcxLabel
      Left = 25
      Top = 53
      Caption = #21345'   '#21495':'
      ParentColor = False
      Style.Color = clCream
    end
    object KHTextEdit: TcxTextEdit
      Left = 84
      Top = 52
      Properties.MaxLength = 9
      TabOrder = 1
      OnKeyPress = BHTextEditKeyPress
      Width = 121
    end
    object BHTextEdit: TcxTextEdit
      Left = 289
      Top = 52
      Properties.MaxLength = 10
      TabOrder = 2
      OnKeyPress = BHTextEditKeyPress
      Width = 121
    end
    object cxLabel17: TcxLabel
      Left = 232
      Top = 53
      Caption = #32534'   '#21495':'
      ParentColor = False
      Style.Color = clCream
    end
    object cxLabel16: TcxLabel
      Left = 427
      Top = 53
      Caption = #22995'  '#21517':'
      ParentColor = False
      Style.Color = clCream
    end
    object cxLabel1: TcxLabel
      Left = 612
      Top = 14
      Caption = #37096'   '#38376':'
      ParentColor = False
      Style.Color = clCream
    end
    object BMComboBox: TcxComboBox
      Left = 671
      Top = 13
      TabOrder = 6
      OnKeyPress = TKBeginDateEditKeyPress
      Width = 121
    end
    object XMTextEdit: TcxTextEdit
      Left = 480
      Top = 52
      Properties.MaxLength = 10
      TabOrder = 7
      Width = 121
    end
    object CZYComboBox: TcxComboBox
      Left = 480
      Top = 13
      TabOrder = 8
      OnKeyPress = TKBeginDateEditKeyPress
      Width = 121
    end
    object cxLabel2: TcxLabel
      Left = 420
      Top = 14
      Caption = #25805#20316#21592':'
      ParentColor = False
      Style.Color = clCream
    end
    object TKBeginDateEdit: TcxDateEdit
      Left = 84
      Top = 13
      TabOrder = 10
      OnKeyPress = TKBeginDateEditKeyPress
      Width = 121
    end
    object cxLabel4: TcxLabel
      Left = 7
      Top = 14
      Caption = #36215#22987#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object cxLabel3: TcxLabel
      Left = 214
      Top = 14
      Caption = #25130#27490#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object TKEndDateEdit: TcxDateEdit
      Left = 289
      Top = 13
      TabOrder = 13
      OnKeyPress = TKBeginDateEditKeyPress
      Width = 121
    end
    object QueryBTN: TcxButton
      Left = 655
      Top = 51
      Width = 75
      Height = 25
      Caption = #26597'   '#35810
      LookAndFeel.NativeStyle = True
      TabOrder = 14
      OnClick = QueryBTNClick
    end
    object Panel3: TPanel
      Left = 10
      Top = 82
      Width = 782
      Height = 1
      TabOrder = 15
    end
    object cxLabel5: TcxLabel
      Left = 64
      Top = 93
      Caption = #36864#21345#27425#25968':'
      ParentColor = False
      Style.Color = clCream
    end
    object AllTKCSTextEdit: TcxTextEdit
      Left = 141
      Top = 92
      Properties.MaxLength = 9
      TabOrder = 17
      OnKeyPress = BHTextEditKeyPress
      Width = 121
    end
    object cxLabel6: TcxLabel
      Left = 306
      Top = 93
      Caption = #36864#21345#37329#39069':'
      ParentColor = False
      Style.Color = clCream
    end
    object AllTKJETextEdit: TcxTextEdit
      Left = 383
      Top = 92
      Properties.MaxLength = 10
      TabOrder = 19
      OnKeyPress = BHTextEditKeyPress
      Width = 121
    end
    object cxLabel7: TcxLabel
      Left = 548
      Top = 93
      Caption = #36864#21345#25104#26412':'
      ParentColor = False
      Style.Color = clCream
    end
    object AllTKCBTextEdit: TcxTextEdit
      Left = 624
      Top = 92
      Properties.MaxLength = 10
      TabOrder = 21
      Width = 121
    end
  end
  object cxGroupBox2: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 135
    Align = alClient
    Alignment = alCenterCenter
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 1
    Height = 510
    Width = 800
    object cxGroupBox3: TcxGroupBox
      AlignWithMargins = True
      Left = 2
      Top = 2
      Margins.Left = 0
      Margins.Top = 0
      Margins.Right = 0
      Margins.Bottom = 2
      Align = alClient
      Alignment = alCenterCenter
      TabOrder = 0
      Height = 393
      Width = 796
      object DataGrid: TcxGrid
        AlignWithMargins = True
        Left = 5
        Top = 5
        Width = 786
        Height = 383
        Align = alClient
        TabOrder = 0
        object DataGridDBTV: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsCustomize.ColumnFiltering = False
          OptionsCustomize.ColumnSorting = False
          OptionsData.CancelOnExit = False
          OptionsData.Deleting = False
          OptionsData.DeletingConfirmation = False
          OptionsData.Editing = False
          OptionsData.Inserting = False
          OptionsSelection.CellSelect = False
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          Styles.StyleSheet = GridTableViewStyleSheetDevExpress
        end
        object DataGridLL: TcxGridLevel
          GridView = DataGridDBTV
        end
      end
    end
    object cxGroupBox4: TcxGroupBox
      AlignWithMargins = True
      Left = 2
      Top = 399
      Margins.Left = 0
      Margins.Top = 2
      Margins.Right = 0
      Margins.Bottom = 2
      Align = alBottom
      Alignment = alCenterCenter
      TabOrder = 1
      Height = 35
      Width = 796
      object TKExportProgressBar: TcxProgressBar
        Left = 2
        Top = 2
        Align = alClient
        Properties.ShowTextStyle = cxtsText
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.Color = clLime
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 0
        ExplicitHeight = 21
        Width = 792
      end
    end
    object cxGroupBox5: TcxGroupBox
      AlignWithMargins = True
      Left = 2
      Top = 473
      Margins.Left = 0
      Margins.Top = 2
      Margins.Right = 0
      Margins.Bottom = 0
      Align = alBottom
      Alignment = alCenterCenter
      TabOrder = 2
      Height = 35
      Width = 796
      object Panel2: TPanel
        Left = 14
        Top = 2
        Width = 780
        Height = 31
        Align = alRight
        BevelOuter = bvNone
        Color = clWhite
        ParentBackground = False
        TabOrder = 0
        object TKExportBTN: TcxButton
          Left = 527
          Top = 3
          Width = 75
          Height = 25
          Caption = #23548'   '#20986
          Enabled = False
          LookAndFeel.NativeStyle = True
          TabOrder = 0
          OnClick = TKExportBTNClick
        end
        object TKExitBTN: TcxButton
          Left = 695
          Top = 3
          Width = 75
          Height = 25
          Caption = #36864'   '#20986
          LookAndFeel.NativeStyle = True
          TabOrder = 1
          OnClick = TKExitBTNClick
        end
        object PreviewBTN: TcxButton
          Left = 611
          Top = 3
          Width = 75
          Height = 25
          Caption = #25171#21360#39044#35272
          Enabled = False
          LookAndFeel.NativeStyle = True
          TabOrder = 2
          OnClick = PreviewBTNClick
        end
      end
    end
    object cxGroupBox6: TcxGroupBox
      Left = 2
      Top = 436
      Align = alBottom
      Alignment = alCenterCenter
      TabOrder = 3
      Height = 35
      Width = 796
      object Panel1: TPanel
        Left = 2
        Top = 2
        Width = 792
        Height = 31
        Align = alClient
        BevelOuter = bvNone
        Caption = #23548#20986#25968#25454#38656#35201'XLS'#36719#20214#25903#25345#65292#35831#30830#35748#31995#32479#20013#23433#35013'XLS'#36719#20214#65292#21542#21017#26080#27861#23436#25104#23548#20986'!'
        Color = 8421631
        ParentBackground = False
        TabOrder = 0
      end
    end
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 80
    Top = 344
    PixelsPerInch = 96
    object cxStyle1: TcxStyle
      AssignedValues = [svColor]
      Color = 15451300
    end
    object cxStyle2: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 16247513
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle3: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 16247513
      TextColor = clBlack
    end
    object cxStyle4: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 16247513
      TextColor = clBlack
    end
    object cxStyle5: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 14811135
      TextColor = clBlack
    end
    object cxStyle6: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 14811135
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clNavy
    end
    object cxStyle7: TcxStyle
      AssignedValues = [svColor]
      Color = 14872561
    end
    object cxStyle8: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 4707838
      TextColor = clBlack
    end
    object cxStyle9: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 12937777
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle10: TcxStyle
      AssignedValues = [svColor]
      Color = 15451300
    end
    object cxStyle11: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 4707838
      TextColor = clBlack
    end
    object cxStyle12: TcxStyle
      AssignedValues = [svColor]
      Color = 15451300
    end
    object cxStyle13: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 14811135
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clNavy
    end
    object cxStyle14: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 12937777
      TextColor = clWhite
    end
    object GridTableViewStyleSheetDevExpress: TcxGridTableViewStyleSheet
      Caption = 'DevExpress'
      Styles.Background = cxStyle1
      Styles.Content = cxStyle2
      Styles.ContentEven = cxStyle3
      Styles.ContentOdd = cxStyle4
      Styles.FilterBox = cxStyle5
      Styles.Inactive = cxStyle10
      Styles.IncSearch = cxStyle11
      Styles.Selection = cxStyle14
      Styles.Footer = cxStyle6
      Styles.Group = cxStyle7
      Styles.GroupByBox = cxStyle8
      Styles.Header = cxStyle9
      Styles.Indicator = cxStyle12
      Styles.Preview = cxStyle13
      BuiltIn = True
    end
  end
  object TKADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 80
    Top = 288
  end
  object TKDataSource: TDataSource
    DataSet = TKADOQuery
    Left = 80
    Top = 232
  end
  object SaveDialog: TSaveDialog
    FileName = #37325#21629#21517
    Filter = 'xls'
    Left = 192
    Top = 408
  end
  object ADOQInThread: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 80
    Top = 408
  end
  object frxTKReport: TfrxReport
    Version = '4.9.32'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 40866.701952210600000000
    ReportOptions.LastChange = 41102.637862048610000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 544
    Top = 224
    Datasets = <
      item
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      Orientation = poLandscape
      PaperWidth = 257.000000000000000000
      PaperHeight = 182.000000000000000000
      PaperSize = 256
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      object ReportTitle1: TfrxReportTitle
        Height = 120.267765350000000000
        Top = 18.897650000000000000
        Width = 895.748610000000000000
        object Memo2: TfrxMemoView
          Left = 360.834880000000000000
          Width = 173.858380000000000000
          Height = 34.015770000000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -27
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #36864#21345#26126#32454#25253#34920)
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          Top = 34.015770000000010000
          Width = 76.346456692913400000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #21345#21495)
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          Left = 0.456710000000000000
          Top = 55.472480000000010000
          Width = 75.590600000000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #22995#21517)
          ParentFont = False
        end
        object KHMemo: TfrxMemoView
          Left = 76.590600000000000000
          Top = 34.015770000000010000
          Width = 94.488188980000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          Left = 171.181200000000000000
          Top = 34.015770000000010000
          Width = 75.590600000000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #32534#21495)
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          Left = 170.842610000000000000
          Top = 55.472480000000010000
          Width = 76.346456690000000000
          Height = 20.787401570000000000
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
        object XMMemo: TfrxMemoView
          Left = 75.897650000000000000
          Top = 55.692949999999990000
          Width = 95.244094490000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object BMMemo: TfrxMemoView
          Left = 247.433210000000000000
          Top = 55.472480000000010000
          Width = 157.228346460000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object BHMemo: TfrxMemoView
          Left = 247.078850000000000000
          Top = 34.015770000000010000
          Width = 94.488188980000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo23: TfrxMemoView
          Left = 665.079160000000000000
          Top = 34.015770000000010000
          Width = 75.590600000000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #24320#22987#26102#38388)
          ParentFont = False
        end
        object Memo24: TfrxMemoView
          Left = 509.976810000000000000
          Top = 34.472480000000000000
          Width = 75.590600000000000000
          Height = 20.787401570000000000
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
        object QSSJM: TfrxMemoView
          Left = 740.669760000000000000
          Top = 34.015770000000010000
          Width = 154.960629920000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object CZYMemo: TfrxMemoView
          Left = 585.567410000000000000
          Top = 34.472480000000000000
          Width = 79.370078740000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo28: TfrxMemoView
          Top = 97.590600000000000000
          Width = 894.992125980000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #36864#21345#35814#32454#24773#20917)
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          Left = 340.937230000000000000
          Top = 34.015770000000010000
          Width = 75.590600000000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #36864#21345#25805#20316#21592)
          ParentFont = False
        end
        object TKCZYM: TfrxMemoView
          Left = 415.834880000000000000
          Top = 34.015770000000010000
          Width = 94.488188980000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo9: TfrxMemoView
          Left = 665.016080000000000000
          Top = 54.913420000000000000
          Width = 75.590600000000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #25130#27490#26102#38388)
          ParentFont = False
        end
        object JZSJM: TfrxMemoView
          Left = 740.606680000000000000
          Top = 54.913420000000000000
          Width = 154.960629920000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo11: TfrxMemoView
          Left = 404.598640000000000000
          Top = 54.913420000000000000
          Width = 105.826840000000000000
          Height = 21.165354330000000000
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
        object BBSRM: TfrxMemoView
          Left = 510.425480000000000000
          Top = 54.913420000000000000
          Width = 154.960629920000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo6: TfrxMemoView
          Top = 76.149660000000000000
          Width = 113.385826770000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #36864#21345#24635#27425#25968)
          ParentFont = False
        end
        object TKZCSM: TfrxMemoView
          Left = 113.385900000000000000
          Top = 76.149660000000000000
          Width = 185.196850390000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          Left = 596.220780000000000000
          Top = 76.590600000000000000
          Width = 113.385826770000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #36864#21345#24635#25104#26412)
          ParentFont = False
        end
        object TKZCBM: TfrxMemoView
          Left = 709.606680000000000000
          Top = 76.590600000000000000
          Width = 185.196850390000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo14: TfrxMemoView
          Left = 298.196970000000000000
          Top = 76.590600000000000000
          Width = 113.385826770000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #36864#21345#24635#37329#39069)
          ParentFont = False
        end
        object TKZJEM: TfrxMemoView
          Left = 411.023810000000000000
          Top = 76.590600000000000000
          Width = 185.196850390000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
      end
      object MasterData1: TfrxMasterData
        Height = 20.787401570000000000
        Top = 245.669450000000000000
        Width = 895.748610000000000000
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
        RowCount = 0
        object KH: TfrxMemoView
          Width = 94.488188980000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object BH: TfrxMemoView
          Left = 94.590600000000000000
          Width = 94.488188980000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object XM: TfrxMemoView
          Left = 189.181200000000000000
          Width = 83.149606300000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object TKJE: TfrxMemoView
          Left = 309.771800000000000000
          Width = 83.149606300000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object XB: TfrxMemoView
          Left = 272.362400000000000000
          Width = 37.795275590000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object BM: TfrxMemoView
          Left = 475.953000000000000000
          Width = 113.385826770000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object TKCB: TfrxMemoView
          Left = 393.134200000000000000
          Width = 83.149606300000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object TKOperator: TfrxMemoView
          Left = 686.165740000000000000
          Width = 53.669291338582700000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ZW: TfrxMemoView
          Left = 589.197280000000000000
          Width = 56.692913390000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ZT: TfrxMemoView
          Left = 646.228820000000000000
          Width = 40.440944880000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object TKRQ: TfrxMemoView
          Left = 739.921770000000000000
          Width = 154.960629920000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        Height = 22.677180000000000000
        Top = 328.819110000000000000
        Width = 895.748610000000000000
        object Memo1: TfrxMemoView
          Left = 819.158010000000000000
          Top = 2.779530000000022000
          Width = 75.590600000000000000
          Height = 18.897650000000000000
          ShowHint = False
          HAlign = haRight
          Memo.UTF8W = (
            '[Page#]')
        end
      end
      object PageHeader1: TfrxPageHeader
        Height = 20.787401570000000000
        Top = 162.519790000000000000
        Width = 895.748610000000000000
        object Memo29: TfrxMemoView
          Width = 94.488188980000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #21345#21495)
          ParentFont = False
        end
        object Memo30: TfrxMemoView
          Left = 94.590600000000000000
          Width = 94.488188980000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #32534#21495)
          ParentFont = False
        end
        object Memo31: TfrxMemoView
          Left = 189.181200000000000000
          Width = 83.149606299212600000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #22995#21517)
          ParentFont = False
        end
        object Memo32: TfrxMemoView
          Left = 309.771800000000000000
          Width = 83.149606299212600000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #36864#21345#37329#39069)
          ParentFont = False
        end
        object Memo33: TfrxMemoView
          Left = 272.362400000000000000
          Width = 37.795275590000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #24615#21035)
          ParentFont = False
        end
        object Memo34: TfrxMemoView
          Left = 475.953000000000000000
          Width = 113.385826770000000000
          Height = 20.787401570000000000
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
        object Memo36: TfrxMemoView
          Left = 393.134200000000000000
          Width = 83.149606300000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #36864#21345#25104#26412)
          ParentFont = False
        end
        object Memo37: TfrxMemoView
          Left = 686.165740000000000000
          Width = 53.669291338582700000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #25805#20316#21592)
          ParentFont = False
        end
        object Memo38: TfrxMemoView
          Left = 589.197280000000000000
          Width = 56.692913390000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #32844#21153)
          ParentFont = False
        end
        object Memo39: TfrxMemoView
          Left = 646.228820000000000000
          Width = 40.440944880000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #29366#24577)
          ParentFont = False
        end
        object Memo40: TfrxMemoView
          Left = 739.921770000000000000
          Width = 154.960629920000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #36864#21345#26085#26399)
          ParentFont = False
        end
      end
    end
  end
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    DataSource = TKDataSource
    BCDToCurrency = False
    Left = 544
    Top = 312
  end
  object TJADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 272
    Top = 312
  end
end
