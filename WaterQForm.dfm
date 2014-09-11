object SKMXQFrm: TSKMXQFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #27700#25511#28040#36153#26597#35810
  ClientHeight = 534
  ClientWidth = 509
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object cxLabel4: TcxLabel
    Left = 13
    Top = 17
    Caption = #32479#35745#25253#35686#37329#39069#19979#38480':'
    ParentColor = False
    Style.Color = clCream
  end
  object cxLabel3: TcxLabel
    Left = 294
    Top = 17
    Caption = #26597#35810#26376#20221':'
    ParentColor = False
    Style.Color = clCream
  end
  object QueryBTN: TcxButton
    Left = 154
    Top = 54
    Width = 75
    Height = 25
    Caption = #26597'   '#35810
    LookAndFeel.NativeStyle = True
    TabOrder = 2
    OnClick = QueryBTNClick
  end
  object cxButton1: TcxButton
    Left = 290
    Top = 54
    Width = 75
    Height = 25
    Caption = #36864'   '#20986
    LookAndFeel.NativeStyle = True
    TabOrder = 3
    OnClick = cxButton1Click
  end
  object WarmTextEdit: TcxTextEdit
    Left = 149
    Top = 16
    Properties.MaxLength = 6
    TabOrder = 4
    Text = '100'
    OnKeyPress = WarmTextEditKeyPress
    Width = 121
  end
  object YFComboBox: TcxComboBox
    Left = 371
    Top = 16
    Properties.Items.Strings = (
      #19968#26376#20221
      #20108#26376#20221
      #19977#26376#20221
      #22235#26376#20221
      #20116#26376#20221
      #20845#26376#20221
      #19971#26376#20221
      #20843#26376#20221
      #20061#26376#20221
      #21313#26376#20221
      #21313#19968#26376#20221
      #21313#20108#26376#20221)
    TabOrder = 5
    OnKeyPress = YFComboBoxKeyPress
    Width = 121
  end
  object ListView1: TListView
    AlignWithMargins = True
    Left = 1
    Top = 94
    Width = 505
    Height = 348
    Columns = <
      item
        Caption = #27700#25511#26426#21495
        Width = 150
      end
      item
        Caption = #24403#26376#28040#36153#24635#39069
        Width = 260
      end>
    ReadOnly = True
    RowSelect = True
    TabOrder = 6
    ViewStyle = vsReport
    OnCustomDrawSubItem = ListView1CustomDrawSubItem
  end
  object GroupBox1: TGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 448
    Width = 503
    Height = 83
    Align = alBottom
    Caption = #32479#35745#19982#23548#20986
    TabOrder = 7
    object Label2: TLabel
      Left = 103
      Top = 25
      Width = 75
      Height = 16
      Caption = #28040#36153#24635#39069#65306
    end
    object Edit2: TEdit
      Left = 184
      Top = 21
      Width = 121
      Height = 24
      ReadOnly = True
      TabOrder = 0
    end
    object ProgressBar1: TProgressBar
      Left = 7
      Top = 54
      Width = 490
      Height = 19
      TabOrder = 1
    end
    object Button1: TButton
      Left = 320
      Top = 19
      Width = 75
      Height = 25
      Caption = #23548'   '#20986
      Enabled = False
      TabOrder = 2
      OnClick = Button1Click
    end
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 32
    Top = 48
  end
  object ADOQuery2: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 456
    Top = 48
  end
  object ADOQuery3: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 400
    Top = 48
  end
  object SaveDialog1: TSaveDialog
    Filter = 'XLS|*.xls'
    Left = 248
    Top = 80
  end
end
