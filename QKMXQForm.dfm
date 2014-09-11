object QKMXQFrm: TQKMXQFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #21462#27454#26126#32454#26597#35810#26465#20214
  ClientHeight = 239
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
    Height = 233
    Width = 448
    object cxLabel4: TcxLabel
      Left = 13
      Top = 18
      Caption = #36215#22987#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object QKBeginDateEdit: TcxDateEdit
      Left = 90
      Top = 17
      TabOrder = 1
      OnKeyPress = QKBMComboBoxKeyPress
      Width = 121
    end
    object cxLabel3: TcxLabel
      Left = 233
      Top = 18
      Caption = #25130#27490#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object QKEndDateEdit: TcxDateEdit
      Left = 310
      Top = 17
      TabOrder = 3
      OnKeyPress = QKBMComboBoxKeyPress
      Width = 121
    end
    object cxLabel15: TcxLabel
      Left = 31
      Top = 52
      Caption = #21345'   '#21495':'
      ParentColor = False
      Style.Color = clCream
    end
    object QKKHTextEdit: TcxTextEdit
      Left = 90
      Top = 51
      ParentShowHint = False
      Properties.MaxLength = 9
      ShowHint = True
      TabOrder = 5
      OnKeyPress = QKKHTextEditKeyPress
      Width = 121
    end
    object QKBHTextEdit: TcxTextEdit
      Left = 310
      Top = 51
      Properties.MaxLength = 10
      TabOrder = 6
      OnKeyPress = QKBHTextEditKeyPress
      Width = 121
    end
    object cxLabel17: TcxLabel
      Left = 251
      Top = 52
      Caption = #32534'   '#21495':'
      ParentColor = False
      Style.Color = clCream
    end
    object QKCZYComboBox: TcxComboBox
      Left = 310
      Top = 85
      TabOrder = 8
      OnKeyPress = QKCZYComboBoxKeyPress
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
    object QKBMComboBox: TcxComboBox
      Left = 90
      Top = 85
      Properties.OnChange = QKBMComboBoxPropertiesChange
      TabOrder = 11
      OnKeyPress = QKBMComboBoxKeyPress
      Width = 121
    end
    object ReadCardInfoBTN: TcxButton
      Left = 134
      Top = 191
      Width = 75
      Height = 25
      Caption = #35835'  '#21345
      LookAndFeel.NativeStyle = True
      TabOrder = 12
      OnClick = ReadCardInfoBTNClick
    end
    object cxCheckBox1: TcxCheckBox
      Left = 90
      Top = 157
      Caption = #35835#21345#22120#21462#27454
      State = cbsChecked
      TabOrder = 13
      Width = 121
    end
    object cxCheckBox2: TcxCheckBox
      Left = 256
      Top = 157
      Caption = #36864#21345#21462#27454
      State = cbsChecked
      TabOrder = 14
      Width = 100
    end
    object QueryBTN: TcxButton
      Left = 244
      Top = 191
      Width = 75
      Height = 25
      Caption = #26597'   '#35810
      LookAndFeel.NativeStyle = True
      TabOrder = 15
      OnClick = QueryBTNClick
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
      TabOrder = 17
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
      TabOrder = 19
      OnEnter = ZBComboBoxEnter
      OnKeyPress = ZBComboBoxKeyPress
      Width = 121
    end
  end
  object QKADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 24
    Top = 176
  end
  object QADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 64
    Top = 176
  end
end
