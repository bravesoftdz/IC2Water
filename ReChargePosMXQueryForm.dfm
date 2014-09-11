object ReChargePosForm: TReChargePosForm
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = #20805#20540#26426#20805#20540#26126#32454#26597#35810
  ClientHeight = 258
  ClientWidth = 532
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 0
    Top = 0
    Width = 532
    Height = 33
    Align = alTop
    Alignment = taCenter
    Caption = #20805#20540#26426#20805#20540#26126#32454#26597#35810
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ExplicitWidth = 243
  end
  object cxLabel4: TcxLabel
    Left = 53
    Top = 66
    Caption = #36215#22987#26085#26399':'
    ParentColor = False
    Style.Color = clCream
  end
  object CZBeginDateEdit: TcxDateEdit
    Left = 130
    Top = 65
    TabOrder = 1
    Width = 121
  end
  object cxLabel3: TcxLabel
    Left = 273
    Top = 66
    Caption = #25130#27490#26085#26399':'
    ParentColor = False
    Style.Color = clCream
  end
  object CZEndDateEdit: TcxDateEdit
    Left = 350
    Top = 65
    TabOrder = 3
    Width = 121
  end
  object cxLabel1: TcxLabel
    Left = 53
    Top = 103
    Caption = #20805#20540#26426#21495':'
    ParentColor = False
    Style.Color = clCream
  end
  object QueryBTN: TcxButton
    Left = 156
    Top = 212
    Width = 75
    Height = 25
    Caption = #26597'   '#35810
    LookAndFeel.NativeStyle = True
    TabOrder = 5
    OnClick = QueryBTNClick
  end
  object cxButton1: TcxButton
    Left = 297
    Top = 212
    Width = 75
    Height = 25
    Caption = #36864'   '#20986
    LookAndFeel.NativeStyle = True
    TabOrder = 6
    OnClick = cxButton1Click
  end
  object JHComboBox: TcxComboBox
    Left = 130
    Top = 99
    TabOrder = 7
    Width = 121
  end
  object cxLabel15: TcxLabel
    Left = 291
    Top = 103
    Caption = #21345'   '#21495':'
    ParentColor = False
    Style.Color = clCream
  end
  object CZKHTextEdit: TcxTextEdit
    Left = 350
    Top = 99
    Properties.MaxLength = 9
    TabOrder = 9
    OnKeyPress = CZKHTextEditKeyPress
    Width = 121
  end
  object cxLabel17: TcxLabel
    Left = 71
    Top = 135
    Caption = #32534'   '#21495':'
    ParentColor = False
    Style.Color = clCream
  end
  object CZBHTextEdit: TcxTextEdit
    Left = 130
    Top = 134
    Properties.MaxLength = 10
    TabOrder = 11
    OnKeyPress = CZKHTextEditKeyPress
    Width = 121
  end
  object CZBMComboBox: TcxComboBox
    Left = 350
    Top = 134
    Properties.OnChange = CZBMComboBoxPropertiesChange
    TabOrder = 12
    OnKeyPress = CZBMComboBoxKeyPress
    Width = 121
  end
  object cxLabel2: TcxLabel
    Left = 291
    Top = 135
    Caption = #37096'   '#38376':'
    ParentColor = False
    Style.Color = clCream
  end
  object cxLabel5: TcxLabel
    Left = 75
    Top = 169
    Caption = #29677'  '#21035':'
    ParentColor = False
    Style.Color = clCream
  end
  object BBComboBox: TcxComboBox
    Left = 130
    Top = 168
    TabOrder = 15
    OnEnter = BBComboBoxEnter
    OnKeyPress = CZBMComboBoxKeyPress
    Width = 121
  end
  object cxLabel6: TcxLabel
    Left = 291
    Top = 169
    Caption = #32452'   '#21035':'
    ParentColor = False
    Style.Color = clCream
  end
  object ZBComboBox: TcxComboBox
    Left = 350
    Top = 168
    TabOrder = 17
    OnEnter = ZBComboBoxEnter
    OnKeyPress = CZBMComboBoxKeyPress
    Width = 121
  end
  object CZJADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 32
    Top = 200
  end
  object QADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 16
    Top = 136
  end
end
