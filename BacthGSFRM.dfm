object BatchGSForm: TBatchGSForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'BatchGSForm'
  ClientHeight = 484
  ClientWidth = 848
  Color = clCream
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
    Left = 3
    Top = 3
    Align = alTop
    Caption = #26597#35810#26465#20214
    TabOrder = 0
    Height = 70
    Width = 842
    object Label1: TLabel
      Left = 24
      Top = 32
      Width = 45
      Height = 16
      Caption = #37096#38376#65306
    end
    object Label2: TLabel
      Left = 296
      Top = 32
      Width = 45
      Height = 16
      Caption = #29677#32423#65306
    end
    object cxComboBox1: TcxComboBox
      Left = 67
      Top = 29
      Properties.ReadOnly = False
      TabOrder = 0
      OnEnter = cxComboBox1Enter
      OnExit = cxComboBox1Exit
      OnKeyPress = cxComboBox1KeyPress
      Width = 200
    end
    object cxComboBox2: TcxComboBox
      Left = 339
      Top = 29
      Properties.ReadOnly = False
      TabOrder = 1
      OnEnter = cxComboBox2Enter
      OnKeyPress = cxComboBox1KeyPress
      Width = 200
    end
    object cxButton1: TcxButton
      Left = 560
      Top = 29
      Width = 75
      Height = 25
      Caption = #26597'   '#35810
      LookAndFeel.NativeStyle = True
      TabOrder = 2
      OnClick = cxButton1Click
    end
  end
  object cxGroupBox2: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 79
    Align = alClient
    Caption = #25346#22833#21517#21333
    TabOrder = 1
    Height = 331
    Width = 842
    object DataGrid: TcxGrid
      AlignWithMargins = True
      Left = 5
      Top = 24
      Width = 832
      Height = 302
      Align = alClient
      TabOrder = 0
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
          Caption = #22995#21517
          DataBinding.FieldName = 'XM'
        end
        object DataGridDBTVColumn4: TcxGridDBColumn
          Caption = #37096#38376
          DataBinding.FieldName = 'BM'
        end
        object DataGridDBTVColumn5: TcxGridDBColumn
          Caption = #29677#21035
          DataBinding.FieldName = 'BZ'
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
    Top = 416
    Align = alBottom
    Caption = #25346#22833#36827#24230
    TabOrder = 2
    Height = 65
    Width = 842
    object Panel1: TPanel
      Left = 2
      Top = 21
      Width = 652
      Height = 42
      Align = alClient
      BevelOuter = bvNone
      Color = clCream
      ParentBackground = False
      TabOrder = 0
      object cxProgressBar1: TcxProgressBar
        AlignWithMargins = True
        Left = 3
        Top = 3
        Align = alClient
        TabOrder = 0
        Width = 646
      end
    end
    object Panel2: TPanel
      Left = 654
      Top = 21
      Width = 186
      Height = 42
      Align = alRight
      BevelOuter = bvNone
      Color = clCream
      ParentBackground = False
      TabOrder = 1
      object cxButton2: TcxButton
        Left = 11
        Top = 8
        Width = 75
        Height = 25
        Caption = #25346'   '#22833
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 0
        OnClick = cxButton2Click
      end
      object cxButton3: TcxButton
        Left = 96
        Top = 8
        Width = 75
        Height = 25
        Caption = #36864'   '#20986
        LookAndFeel.NativeStyle = True
        TabOrder = 1
        OnClick = cxButton3Click
      end
    end
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 600
    Top = 112
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 96
    Top = 248
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
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 424
    Top = 152
  end
  object ADOQuery2: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 608
    Top = 200
  end
  object ADOQThread: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 520
    Top = 288
  end
  object ADOQuery3: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 520
    Top = 344
  end
end
