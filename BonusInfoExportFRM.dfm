object BonusInfoExportForm: TBonusInfoExportForm
  Left = 0
  Top = 0
  Caption = 'BonusInfoExportForm'
  ClientHeight = 600
  ClientWidth = 870
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object cxGroupBox1: TcxGroupBox
    AlignWithMargins = True
    Left = 0
    Top = 0
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 2
    Align = alClient
    Alignment = alCenterCenter
    TabOrder = 0
    Height = 487
    Width = 870
    object DataGrid: TcxGrid
      AlignWithMargins = True
      Left = 5
      Top = 5
      Width = 860
      Height = 477
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
  object cxGroupBox2: TcxGroupBox
    AlignWithMargins = True
    Left = 0
    Top = 526
    Margins.Left = 0
    Margins.Top = 2
    Margins.Right = 0
    Margins.Bottom = 2
    Align = alBottom
    Alignment = alCenterCenter
    TabOrder = 1
    Height = 35
    Width = 870
    object BTExportProgressBar: TcxProgressBar
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
      Width = 866
    end
  end
  object cxGroupBox3: TcxGroupBox
    AlignWithMargins = True
    Left = 0
    Top = 565
    Margins.Left = 0
    Margins.Top = 2
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alBottom
    Alignment = alCenterCenter
    TabOrder = 2
    Height = 35
    Width = 870
    object Panel2: TPanel
      Left = 10
      Top = 2
      Width = 858
      Height = 31
      Align = alRight
      BevelOuter = bvNone
      Color = clWhite
      ParentBackground = False
      TabOrder = 0
      object CSBTBTN: TcxButton
        Left = 508
        Top = 3
        Width = 105
        Height = 25
        Caption = #27425#25968#34917#36148#26126#32454
        LookAndFeel.NativeStyle = True
        TabOrder = 0
        OnClick = CSBTBTNClick
      end
      object BTExportBTN: TcxButton
        Left = 618
        Top = 3
        Width = 75
        Height = 25
        Caption = #23548'   '#20986
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 1
        OnClick = BTExportBTNClick
      end
      object BTExitBTN: TcxButton
        Left = 778
        Top = 3
        Width = 75
        Height = 25
        Caption = #36864'   '#20986
        LookAndFeel.NativeStyle = True
        TabOrder = 2
        OnClick = BTExitBTNClick
      end
      object cxLabel1: TcxLabel
        Left = 3
        Top = 6
        Caption = #36215#22987#26085#26399':'
      end
      object cxLabel2: TcxLabel
        Left = 200
        Top = 6
        Caption = #25130#27490#26085#26399':'
      end
      object BeginDateEdit: TcxDateEdit
        Left = 76
        Top = 3
        TabOrder = 5
        Width = 121
      end
      object EndDateEdit: TcxDateEdit
        Left = 271
        Top = 3
        TabOrder = 6
        Width = 121
      end
      object PrintInfoBTN: TcxButton
        Left = 698
        Top = 3
        Width = 75
        Height = 25
        Caption = #25171#21360#39044#35272
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 7
        OnClick = PrintInfoBTNClick
      end
      object JBBTBTN: TcxButton
        Left = 398
        Top = 3
        Width = 105
        Height = 25
        Caption = #32423#21035#34917#36148#26126#32454
        LookAndFeel.NativeStyle = True
        TabOrder = 8
        OnClick = JBBTBTNClick
      end
    end
  end
  object cxGroupBox4: TcxGroupBox
    Left = 0
    Top = 489
    Align = alBottom
    Alignment = alCenterCenter
    TabOrder = 3
    Height = 35
    Width = 870
    object Panel1: TPanel
      Left = 2
      Top = 2
      Width = 866
      Height = 31
      Align = alClient
      BevelOuter = bvNone
      Caption = #23548#20986#25968#25454#38656#35201'XLS'#36719#20214#25903#25345#65292#35831#30830#35748#31995#32479#20013#23433#35013'XLS'#36719#20214#65292#21542#21017#26080#27861#23436#25104#23548#20986'!'
      Color = 8421631
      ParentBackground = False
      TabOrder = 0
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
  object BTExportADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 80
    Top = 288
  end
  object BTExportDataSource: TDataSource
    DataSet = BTExportADOQuery
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
  object frxBTReport: TfrxReport
    Version = '4.9.32'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 40812.717952835700000000
    ReportOptions.LastChange = 40812.726272060200000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 376
    Top = 336
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
        Height = 56.692950000000000000
        Top = 18.897650000000000000
        Width = 895.748610000000000000
        object Memo1: TfrxMemoView
          Left = 370.173470000000000000
          Top = 5.220470000000000000
          Width = 166.299320000000000000
          Height = 37.795300000000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -27
          Font.Name = #24494#36719#38597#40657
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #32844#21153#34917#36148#20449#24687)
          ParentFont = False
        end
      end
      object PageHeader1: TfrxPageHeader
        Height = 26.456692910000000000
        Top = 98.267780000000000000
        Width = 895.748610000000000000
        object Memo2: TfrxMemoView
          Left = 1.000000000000000000
          Width = 102.047244090000000000
          Height = 26.456692910000000000
          ShowHint = False
          Color = clScrollBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #32534#21495)
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          Left = 205.330662280000000000
          Width = 75.590551180000000000
          Height = 26.456692910000000000
          ShowHint = False
          Color = clScrollBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #34917#36148#25968)
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          Left = 103.110390000000000000
          Width = 102.047244090000000000
          Height = 26.456692910000000000
          ShowHint = False
          Color = clScrollBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #21345#21495)
          ParentFont = False
        end
        object Memo6: TfrxMemoView
          Left = 337.732530000000000000
          Width = 132.283464570000000000
          Height = 26.456692910000000000
          ShowHint = False
          Color = clScrollBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #29983#25104#26102#38388)
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          Left = 537.063390000000000000
          Width = 49.889763780000000000
          Height = 26.456692910000000000
          ShowHint = False
          Color = clScrollBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #26426#21495)
          ParentFont = False
        end
        object Memo9: TfrxMemoView
          Left = 762.583180000000000000
          Width = 132.283464570000000000
          Height = 26.456692910000000000
          ShowHint = False
          Color = clScrollBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #20837#24211#26085#26399)
          ParentFont = False
        end
        object Memo11: TfrxMemoView
          Left = 281.480314960000000000
          Width = 56.692913390000000000
          Height = 26.456692910000000000
          ShowHint = False
          Color = clScrollBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #32844#21153)
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          Left = 686.961040000000000000
          Width = 75.590551180000000000
          Height = 26.456692910000000000
          ShowHint = False
          Color = clScrollBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #25805#20316#21592)
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        Height = 22.677180000000000000
        Top = 268.346630000000000000
        Width = 895.748610000000000000
        object Memo3: TfrxMemoView
          Left = 801.260360000000000000
          Width = 94.488250000000000000
          Height = 22.677180000000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Memo.UTF8W = (
            '[Page#]')
          ParentFont = False
        end
      end
      object MasterData1: TfrxMasterData
        Height = 22.677165350000000000
        Top = 185.196970000000000000
        Width = 895.748610000000000000
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
        RowCount = 0
        object BH: TfrxMemoView
          Left = 1.000000000000000000
          Width = 102.047244090000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object KH: TfrxMemoView
          Left = 103.551134720000000000
          Width = 101.291338580000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object SF_YE: TfrxMemoView
          Left = 205.362204720000000000
          Width = 75.590551181102400000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object SYCS: TfrxMemoView
          Left = 280.708695590000000000
          Width = 56.692913390000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object SFRQ: TfrxMemoView
          Left = 337.417415590000000000
          Width = 132.283464570000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object JYNO: TfrxMemoView
          Left = 537.700965590000000000
          Width = 49.133858270000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object CZY: TfrxMemoView
          Left = 687.079160000000000000
          Width = 75.590551180000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object SCRQ: TfrxMemoView
          Left = 763.008350000000000000
          Width = 132.283464570000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
      end
    end
  end
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    DataSource = BTExportDataSource
    BCDToCurrency = False
    Left = 376
    Top = 400
  end
end
