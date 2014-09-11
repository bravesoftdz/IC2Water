object CZMXQFrm: TCZMXQFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #20805#20540#26126#32454#26597#35810#26465#20214
  ClientHeight = 217
  ClientWidth = 454
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
    ExplicitHeight = 234
    Height = 211
    Width = 448
    object cxLabel4: TcxLabel
      Left = 13
      Top = 18
      Caption = #36215#22987#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object CZBeginDateEdit: TcxDateEdit
      Left = 90
      Top = 17
      TabOrder = 1
      OnKeyPress = CZBeginDateEditKeyPress
      Width = 121
    end
    object cxLabel3: TcxLabel
      Left = 233
      Top = 18
      Caption = #25130#27490#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object CZEndDateEdit: TcxDateEdit
      Left = 310
      Top = 17
      TabOrder = 3
      OnKeyPress = CZEndDateEditKeyPress
      Width = 121
    end
    object cxLabel15: TcxLabel
      Left = 31
      Top = 52
      Caption = #21345'   '#21495':'
      ParentColor = False
      Style.Color = clCream
    end
    object CZKHTextEdit: TcxTextEdit
      Left = 90
      Top = 51
      Properties.MaxLength = 9
      TabOrder = 5
      OnKeyPress = CZKHTextEditKeyPress
      Width = 121
    end
    object CZBHTextEdit: TcxTextEdit
      Left = 310
      Top = 51
      Properties.MaxLength = 10
      TabOrder = 6
      OnKeyPress = CZBHTextEditKeyPress
      Width = 121
    end
    object cxLabel17: TcxLabel
      Left = 251
      Top = 52
      Caption = #32534'   '#21495':'
      ParentColor = False
      Style.Color = clCream
    end
    object CZCZYComboBox: TcxComboBox
      Left = 310
      Top = 85
      TabOrder = 8
      OnKeyPress = CZCZYComboBoxKeyPress
      Width = 121
    end
    object cxLabel16: TcxLabel
      Left = 248
      Top = 86
      Caption = #25805#20316#21592':'
      ParentColor = False
      Style.Color = clCream
    end
    object cxLabel1: TcxLabel
      Left = 31
      Top = 86
      Caption = #37096'   '#38376':'
      ParentColor = False
      Style.Color = clCream
    end
    object CZBMComboBox: TcxComboBox
      Left = 90
      Top = 85
      Properties.OnChange = CZBMComboBoxPropertiesChange
      TabOrder = 11
      OnKeyPress = CZBMComboBoxKeyPress
      Width = 121
    end
    object ReadCardInfoBTN: TcxButton
      Left = 136
      Top = 176
      Width = 75
      Height = 25
      Caption = #35835'  '#21345
      LookAndFeel.NativeStyle = True
      TabOrder = 12
      OnClick = ReadCardInfoBTNClick
    end
    object cxCheckBox1: TcxCheckBox
      Left = 105
      Top = 150
      Caption = #35835#21345#22120#20805#20540
      State = cbsChecked
      TabOrder = 13
      Width = 121
    end
    object cxCheckBox2: TcxCheckBox
      Left = 178
      Top = 242
      Caption = 'POS'#26426#20805#20540
      State = cbsChecked
      TabOrder = 14
      Visible = False
      Width = 121
    end
    object cxCheckBox3: TcxCheckBox
      Left = 251
      Top = 150
      Caption = #21457#21345#20805#20540
      State = cbsChecked
      TabOrder = 15
      Width = 100
    end
    object QueryBTN: TcxButton
      Left = 232
      Top = 176
      Width = 75
      Height = 25
      Caption = #26597'   '#35810
      LookAndFeel.NativeStyle = True
      TabOrder = 16
      OnClick = QueryBTNClick
    end
    object cxButton1: TcxButton
      Left = 39
      Top = 242
      Width = 133
      Height = 25
      Caption = #20805#20540#26426#26126#32454#26597#35810
      Enabled = False
      LookAndFeel.NativeStyle = True
      TabOrder = 17
      Visible = False
      OnClick = cxButton1Click
    end
    object cxLabel2: TcxLabel
      Left = 35
      Top = 121
      Caption = #29677'  '#21035':'
      ParentColor = False
      Style.Color = clCream
    end
    object BBComboBox: TcxComboBox
      Left = 90
      Top = 120
      TabOrder = 19
      OnEnter = BBComboBoxEnter
      OnKeyPress = BBComboBoxKeyPress
      Width = 121
    end
    object cxLabel5: TcxLabel
      Left = 251
      Top = 121
      Caption = #32452'   '#21035':'
      ParentColor = False
      Style.Color = clCream
    end
    object ZBComboBox: TcxComboBox
      Left = 310
      Top = 120
      TabOrder = 21
      OnEnter = ZBComboBoxEnter
      OnKeyPress = BBComboBoxKeyPress
      Width = 121
    end
  end
  object CKADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 8
    Top = 160
  end
  object QADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 8
    Top = 104
  end
end
