object DealMistakeForm: TDealMistakeForm
  Left = 0
  Top = 0
  BorderIcons = []
  Caption = 'DealMistakeForm'
  ClientHeight = 566
  ClientWidth = 899
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object cxGroupBox1: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Align = alTop
    Caption = #25805#20316#35828#26126
    TabOrder = 0
    Height = 105
    Width = 893
    object Memo1: TMemo
      AlignWithMargins = True
      Left = 5
      Top = 24
      Width = 883
      Height = 76
      Align = alClient
      BevelInner = bvNone
      BevelOuter = bvNone
      BorderStyle = bsNone
      Color = clCream
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      Lines.Strings = (
        '1'#12289#35823#25910#22788#29702#20197'POS'#26426#28040#36153#35760#24405#20026#20381#25454#65292#24517#39035#30830#20445#25152#26377#28040#36153#35760#24405#24050#32463#37319#38598#65292#21542#21017#26080#27861#36827#34892#35823#25910#22788#29702#12290
        '2'#12289#20808#36827#34892#35835#21345#65292#28982#21518#27491#30830#30340#22635#20889'POS'#26426#21495#21450#22823#27010#28040#36153#26102#38388#27573#65292#36827#34892#28040#36153#35760#24405#26597#35810#12290
        '3'#12289#20462#27491#37329#39069#20026#27491#20540#34920#31034#24448#21345#19978#20805#20540#65292#36127#20540#34920#31034#20174#21345#19978#25187#27454#65292#28857#20987#8220#20889#21345#8221#23436#25104#25805#20316#12290)
      ParentFont = False
      TabOrder = 0
    end
  end
  object cxGroupBox2: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 114
    Align = alTop
    Caption = #28040#36153#26126#32454#26597#35810
    TabOrder = 1
    Height = 327
    Width = 893
    object Panel1: TPanel
      AlignWithMargins = True
      Left = 5
      Top = 24
      Width = 883
      Height = 44
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
      object Label1: TLabel
        Left = 9
        Top = 16
        Width = 75
        Height = 16
        Caption = #28040#36153#26085#26399#65306
      end
      object Label2: TLabel
        Left = 193
        Top = 16
        Width = 105
        Height = 16
        Caption = #28040#36153#26102#38388#19978#38480#65306
      end
      object Label3: TLabel
        Left = 407
        Top = 16
        Width = 105
        Height = 16
        Caption = #28040#36153#26102#38388#19979#38480#65306
      end
      object Label5: TLabel
        Left = 629
        Top = 19
        Width = 75
        Height = 16
        Caption = #28040#36153#26426#21495#65306
      end
      object cxDateEdit1: TcxDateEdit
        Left = 83
        Top = 13
        Properties.ReadOnly = False
        TabOrder = 0
        Width = 100
      end
      object cxTimeEdit1: TcxTimeEdit
        Left = 297
        Top = 13
        EditValue = 0d
        Properties.ReadOnly = False
        TabOrder = 1
        Width = 100
      end
      object cxTimeEdit2: TcxTimeEdit
        Left = 510
        Top = 13
        EditValue = 0d
        Properties.ReadOnly = False
        TabOrder = 2
        Width = 100
      end
      object cxButton4: TcxButton
        Left = 805
        Top = 12
        Width = 75
        Height = 25
        Caption = #26597'   '#35810
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 3
        OnClick = cxButton4Click
      end
      object cxTextEdit2: TcxTextEdit
        Left = 702
        Top = 13
        TabOrder = 4
        OnKeyPress = cxTextEdit2KeyPress
        Width = 70
      end
    end
    object DataGrid: TcxGrid
      AlignWithMargins = True
      Left = 5
      Top = 74
      Width = 883
      Height = 248
      Align = alClient
      TabOrder = 1
      object DataGridDBTV: TcxGridDBTableView
        NavigatorButtons.ConfirmDelete = False
        DataController.DataSource = DataSource1
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
        object DataGridDBTVColumn1: TcxGridDBColumn
          Caption = #21345#21495
          DataBinding.FieldName = 'KH'
        end
        object DataGridDBTVColumn2: TcxGridDBColumn
          Caption = #32534#21495
          DataBinding.FieldName = 'BH'
        end
        object DataGridDBTVColumn3: TcxGridDBColumn
          Caption = #28040#36153#37329#39069
          DataBinding.FieldName = 'SFJE'
        end
        object DataGridDBTVColumn4: TcxGridDBColumn
          Caption = #28040#36153#26085#26399
          DataBinding.FieldName = 'SFRQ'
        end
        object DataGridDBTVColumn5: TcxGridDBColumn
          Caption = #28040#36153#26426#21495
          DataBinding.FieldName = 'JYNO'
        end
      end
      object DataGridLL: TcxGridLevel
        GridView = DataGridDBTV
      end
    end
  end
  object cxGroupBox3: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 447
    Align = alTop
    Caption = #35823#25910#22788#29702
    TabOrder = 2
    Height = 61
    Width = 893
    object Label4: TLabel
      Left = 29
      Top = 27
      Width = 75
      Height = 16
      Caption = #20462#27491#37329#39069#65306
    end
    object cxButton1: TcxButton
      Left = 536
      Top = 24
      Width = 75
      Height = 25
      Caption = #36864'   '#20986
      LookAndFeel.NativeStyle = True
      TabOrder = 0
      OnClick = cxButton1Click
    end
    object cxTextEdit1: TcxTextEdit
      Left = 110
      Top = 24
      TabOrder = 1
      OnKeyPress = cxTextEdit1KeyPress
      Width = 150
    end
    object cxButton2: TcxButton
      Left = 307
      Top = 24
      Width = 75
      Height = 25
      Caption = #35835'   '#21345
      LookAndFeel.NativeStyle = True
      TabOrder = 2
      OnClick = cxButton2Click
    end
    object cxButton3: TcxButton
      Left = 418
      Top = 24
      Width = 75
      Height = 25
      Caption = #20889'   '#21345
      Enabled = False
      LookAndFeel.NativeStyle = True
      TabOrder = 3
      OnClick = cxButton3Click
    end
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 176
    Top = 288
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
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 440
    Top = 240
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 536
    Top = 248
  end
  object ADOTable1: TADOTable
    Connection = SDIAppForm.ADOConnection1
    Left = 448
    Top = 320
  end
end
