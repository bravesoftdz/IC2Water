object CARDQFrm: TCARDQFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #21345#29255#26126#32454#26597#35810#26465#20214
  ClientHeight = 157
  ClientWidth = 446
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
    Height = 151
    Width = 440
    object cxLabel15: TcxLabel
      Left = 23
      Top = 12
      Caption = #21345'  '#21495':'
      ParentColor = False
      Style.Color = clCream
    end
    object KHTextEdit: TcxTextEdit
      Left = 78
      Top = 11
      Properties.MaxLength = 9
      TabOrder = 1
      OnKeyPress = KHTextEditKeyPress
      Width = 121
    end
    object BHTextEdit: TcxTextEdit
      Left = 298
      Top = 11
      Properties.MaxLength = 10
      TabOrder = 2
      OnKeyPress = KHTextEditKeyPress
      Width = 121
    end
    object cxLabel17: TcxLabel
      Left = 239
      Top = 12
      Caption = #32534'   '#21495':'
      ParentColor = False
      Style.Color = clCream
    end
    object cxLabel16: TcxLabel
      Left = 239
      Top = 46
      Caption = #37096'   '#38376':'
      ParentColor = False
      Style.Color = clCream
    end
    object cxLabel1: TcxLabel
      Left = 23
      Top = 46
      Caption = #22995'  '#21517':'
      ParentColor = False
      Style.Color = clCream
    end
    object BMComboBox: TcxComboBox
      Left = 298
      Top = 45
      Properties.OnChange = BMComboBoxPropertiesChange
      TabOrder = 6
      OnKeyPress = BMComboBoxKeyPress
      Width = 121
    end
    object QueryBTN: TcxButton
      Left = 182
      Top = 116
      Width = 75
      Height = 25
      Caption = #26597'   '#35810
      LookAndFeel.NativeStyle = True
      TabOrder = 7
      OnClick = QueryBTNClick
    end
    object XMTextEdit: TcxTextEdit
      Left = 78
      Top = 45
      Properties.MaxLength = 10
      TabOrder = 8
      Width = 121
    end
    object cxLabel2: TcxLabel
      Left = 23
      Top = 80
      Caption = #29677'  '#21035':'
      ParentColor = False
      Style.Color = clCream
    end
    object ZBComboBox: TcxComboBox
      Left = 298
      Top = 79
      TabOrder = 10
      OnEnter = ZBComboBoxEnter
      OnKeyPress = BMComboBoxKeyPress
      Width = 121
    end
    object cxLabel5: TcxLabel
      Left = 239
      Top = 80
      Caption = #32452'   '#21035':'
      ParentColor = False
      Style.Color = clCream
    end
    object BBComboBox: TcxComboBox
      Left = 78
      Top = 79
      TabOrder = 12
      OnEnter = BBComboBoxEnter
      OnKeyPress = BMComboBoxKeyPress
      Width = 121
    end
  end
  object CARDADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 72
    Top = 112
  end
  object QADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 136
    Top = 112
  end
end
