object QKMXShowFrm: TQKMXShowFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #21462#27454#26126#32454#26174#31034#31383#21475
  ClientHeight = 520
  ClientWidth = 845
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
    Left = 0
    Top = 0
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 2
    Align = alClient
    Alignment = alCenterCenter
    TabOrder = 0
    Height = 407
    Width = 845
    object DataGrid: TcxGrid
      AlignWithMargins = True
      Left = 5
      Top = 5
      Width = 835
      Height = 397
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
    Top = 446
    Margins.Left = 0
    Margins.Top = 2
    Margins.Right = 0
    Margins.Bottom = 2
    Align = alBottom
    Alignment = alCenterCenter
    TabOrder = 1
    Height = 35
    Width = 845
    object QKMXExportProgressBar: TcxProgressBar
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
      Width = 841
    end
  end
  object cxGroupBox3: TcxGroupBox
    AlignWithMargins = True
    Left = 0
    Top = 485
    Margins.Left = 0
    Margins.Top = 2
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alBottom
    Alignment = alCenterCenter
    TabOrder = 2
    Height = 35
    Width = 845
    object Panel2: TPanel
      Left = 12
      Top = 2
      Width = 831
      Height = 31
      Align = alRight
      BevelOuter = bvNone
      Color = clWhite
      ParentBackground = False
      TabOrder = 0
      object Label1: TLabel
        Left = 316
        Top = 8
        Width = 75
        Height = 16
        Caption = #21462#27454#24635#39069#65306
      end
      object Label2: TLabel
        Left = 39
        Top = 8
        Width = 90
        Height = 16
        Caption = #21462#27454#24635#27425#25968#65306
      end
      object QKMXExportBTN: TcxButton
        Left = 587
        Top = 3
        Width = 75
        Height = 25
        Caption = #23548'   '#20986
        LookAndFeel.NativeStyle = True
        TabOrder = 0
        OnClick = QKMXExportBTNClick
      end
      object QKMXExitBTN: TcxButton
        Left = 749
        Top = 3
        Width = 75
        Height = 25
        Caption = #36864'   '#20986
        LookAndFeel.NativeStyle = True
        TabOrder = 1
        OnClick = QKMXExitBTNClick
      end
      object PreviewBTN: TcxButton
        Left = 668
        Top = 3
        Width = 75
        Height = 25
        Caption = #25171#21360#39044#35272
        LookAndFeel.NativeStyle = True
        TabOrder = 2
        OnClick = PreviewBTNClick
      end
      object AllQKTextEdit: TcxTextEdit
        Left = 388
        Top = 4
        Properties.ReadOnly = True
        TabOrder = 3
        OnKeyPress = AllQKTextEditKeyPress
        Width = 177
      end
      object AllQCSTextEdit: TcxTextEdit
        Left = 125
        Top = 4
        Properties.ReadOnly = True
        TabOrder = 4
        OnKeyPress = AllQKTextEditKeyPress
        Width = 177
      end
    end
  end
  object cxGroupBox4: TcxGroupBox
    Left = 0
    Top = 409
    Align = alBottom
    Alignment = alCenterCenter
    TabOrder = 3
    Height = 35
    Width = 845
    object Panel1: TPanel
      Left = 2
      Top = 2
      Width = 841
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
  object QKMXADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 80
    Top = 288
  end
  object QKMXDataSource: TDataSource
    DataSet = QKMXADOQuery
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
  object frxQKMXReport: TfrxReport
    Version = '4.9.32'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 40865.663176539400000000
    ReportOptions.LastChange = 41716.940406458340000000
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
        Height = 161.842595350000000000
        Top = 18.897650000000000000
        Width = 895.748610000000000000
        object Memo2: TfrxMemoView
          Left = 362.834880000000000000
          Width = 173.858380000000000000
          Height = 34.015770000000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -27
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #21462#27454#26126#32454#25253#34920)
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          Top = 34.015770000000000000
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
            #21345#21495)
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          Left = 416.205010000000000000
          Top = 33.795300000000000000
          Width = 75.590600000000000000
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
            #37096#38376)
          ParentFont = False
        end
        object KHMemo: TfrxMemoView
          Left = 75.590600000000000000
          Top = 34.015770000000000000
          Width = 132.283464570000000000
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
        object QKCZYMemo: TfrxMemoView
          Left = 283.803340000000000000
          Top = 76.370130000000000000
          Width = 132.283464570000000000
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
          Left = 208.181200000000000000
          Top = 34.015770000000000000
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
          Left = -0.031540000000000000
          Top = 55.472480000000000000
          Width = 75.590600000000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #35835#21345#22120#21462#27454)
          ParentFont = False
        end
        object BHMemo: TfrxMemoView
          Left = 283.771800000000000000
          Top = 34.015770000000000000
          Width = 132.283464570000000000
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
        object DKQQKMemo: TfrxMemoView
          Left = 75.559060000000000000
          Top = 55.472480000000000000
          Width = 132.283464570000000000
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
        object Memo11: TfrxMemoView
          Left = 208.149660000000000000
          Top = 76.590600000000000000
          Width = 75.590600000000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #21462#27454#25805#20316#21592)
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          Left = 208.149660000000000000
          Top = 55.472480000000000000
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
            #36864#21345#21462#27454)
          ParentFont = False
        end
        object BMMemo: TfrxMemoView
          Left = 491.953000000000000000
          Top = 34.015770000000000000
          Width = 132.283464570000000000
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
        object TKQKMemo: TfrxMemoView
          Left = 283.740260000000000000
          Top = 55.472480000000000000
          Width = 132.283464570000000000
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
        object Memo16: TfrxMemoView
          Left = 416.362400000000000000
          Top = 55.472480000000000000
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
            #21462#27454#24635#39069)
          ParentFont = False
        end
        object QKZEMemo: TfrxMemoView
          Left = 492.173470000000000000
          Top = 55.692950000000000000
          Width = 132.283464570000000000
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
        object Memo19: TfrxMemoView
          Top = 76.590600000000000000
          Width = 75.590600000000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #25253#34920#25805#20316#21592)
          ParentFont = False
        end
        object Memo20: TfrxMemoView
          Left = 623.976810000000000000
          Top = 76.370130000000000000
          Width = 74.834645670000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #29983#25104#26085#26399)
          ParentFont = False
        end
        object BBCZYMemo: TfrxMemoView
          Left = 75.590600000000000000
          Top = 76.590600000000000000
          Width = 132.283464570000000000
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
        object SCRQMemo: TfrxMemoView
          Left = 699.567410000000000000
          Top = 76.370130000000000000
          Width = 195.779527560000000000
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
          Left = 623.976810000000000000
          Top = 34.015770000000000000
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
            #36215#22987#26085#26399)
          ParentFont = False
        end
        object Memo24: TfrxMemoView
          Left = 623.976810000000000000
          Top = 55.472480000000000000
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
            #25130#27490#26085#26399)
          ParentFont = False
        end
        object QSRQMemo: TfrxMemoView
          Left = 699.567410000000000000
          Top = 34.015770000000000000
          Width = 195.779527560000000000
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
        object JZRQMemo: TfrxMemoView
          Left = 699.567410000000000000
          Top = 55.472480000000000000
          Width = 195.779527560000000000
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
        object Memo27: TfrxMemoView
          Top = 118.267780000000000000
          Width = 894.992125980000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #27880#37322#65306#20805#20540#31867#22411#20013#23383#27597#39' d '#39','#39' D '#39#20195#34920#8220#35835#21345#22120#21462#27454#8221#65292#39' t '#39','#39' T '#39#20195#34920#8220#36864#21345#21462#27454#8221)
          ParentFont = False
        end
        object Memo28: TfrxMemoView
          Top = 139.165430000000000000
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
            #35814#32454#21462#27454#24773#20917)
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          Left = 415.748300000000000000
          Top = 76.590600000000000000
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
            #21462#27454#27425#25968)
          ParentFont = False
        end
        object QKZCSMemo: TfrxMemoView
          Left = 491.559370000000000000
          Top = 75.811070000000000000
          Width = 132.283464570000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo6: TfrxMemoView
          Top = 97.267780000000000000
          Width = 75.590600000000000000
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
            #29677#21035)
          ParentFont = False
        end
        object BBMemo: TfrxMemoView
          Left = 74.747990000000000000
          Top = 97.488250000000000000
          Width = 133.039370080000000000
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
        object Memo10: TfrxMemoView
          Left = 207.874150000000000000
          Top = 97.267780000000000000
          Width = 75.590600000000000000
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
            #32452#21035)
          ParentFont = False
        end
        object ZBMemo: TfrxMemoView
          Left = 283.622140000000000000
          Top = 97.488250000000000000
          Width = 132.283464570000000000
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
      end
      object MasterData1: TfrxMasterData
        Height = 20.787401570000000000
        Top = 287.244280000000000000
        Width = 895.748610000000000000
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
        RowCount = 0
        object KH: TfrxMemoView
          Width = 86.929133860000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object BH: TfrxMemoView
          Left = 87.590600000000000000
          Width = 86.929133860000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object XM: TfrxMemoView
          Left = 174.181200000000000000
          Width = 68.031496060000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object BM: TfrxMemoView
          Left = 241.771800000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object CKJE: TfrxMemoView
          Left = 468.362400000000000000
          Width = 68.031496060000000000
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
        object SFYE: TfrxMemoView
          Left = 535.953000000000000000
          Width = 68.031496060000000000
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
        object SFLX: TfrxMemoView
          Left = 604.134200000000000000
          Width = 37.795275590000000000
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
        object JYNO: TfrxMemoView
          Left = 642.165740000000000000
          Width = 37.795275590000000000
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
        object CZY: TfrxMemoView
          Left = 680.197280000000000000
          Width = 68.031496060000000000
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
        object PKEY: TfrxMemoView
          Left = 748.228820000000000000
          Width = 52.913385830000000000
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
        object SFSJ: TfrxMemoView
          Left = 800.921770000000000000
          Width = 94.488188980000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -8
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object BB: TfrxMemoView
          Left = 317.378170000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ZB: TfrxMemoView
          Left = 393.071120000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        Height = 22.677180000000000000
        Top = 370.393940000000000000
        Width = 895.748610000000000000
        object Memo1: TfrxMemoView
          Left = 819.158010000000000000
          Top = 2.779530000000020000
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
        Top = 204.094620000000000000
        Width = 895.748610000000000000
        object Memo29: TfrxMemoView
          Width = 86.929133860000000000
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
          Left = 87.590600000000000000
          Width = 86.929133860000000000
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
          Left = 174.181200000000000000
          Width = 68.031496062992100000
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
          Left = 241.771800000000000000
          Width = 75.590551180000000000
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
        object Memo33: TfrxMemoView
          Left = 468.362400000000000000
          Width = 68.031496060000000000
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
            #21462#27454#37329#39069)
          ParentFont = False
        end
        object Memo34: TfrxMemoView
          Left = 535.953000000000000000
          Width = 68.031496060000000000
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
            #21345#20313#39069)
          ParentFont = False
        end
        object Memo36: TfrxMemoView
          Left = 604.134200000000000000
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
            #31867#22411)
          ParentFont = False
        end
        object Memo37: TfrxMemoView
          Left = 642.165740000000000000
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
            #26426#21495)
          ParentFont = False
        end
        object Memo38: TfrxMemoView
          Left = 680.197280000000000000
          Width = 68.031496060000000000
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
        object Memo39: TfrxMemoView
          Left = 748.228820000000000000
          Width = 52.913385830000000000
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
            #27969#27700#21495)
          ParentFont = False
        end
        object Memo40: TfrxMemoView
          Left = 800.921770000000000000
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
            #21462#27454#26102#38388)
          ParentFont = False
        end
        object Memo13: TfrxMemoView
          Left = 317.378170000000000000
          Width = 75.590551180000000000
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
            #29677#21035)
          ParentFont = False
        end
        object Memo15: TfrxMemoView
          Left = 393.071120000000000000
          Width = 75.590551180000000000
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
            #32452#21035)
          ParentFont = False
        end
      end
    end
  end
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    DataSource = QKMXDataSource
    BCDToCurrency = False
    Left = 544
    Top = 312
  end
end
