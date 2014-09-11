object XFMXQFrm: TXFMXQFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #28040#36153#26126#32454#26597#35810#26465#20214
  ClientHeight = 237
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
    Height = 231
    Width = 448
    object cxLabel4: TcxLabel
      Left = 13
      Top = 18
      Caption = #36215#22987#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object XFBeginDateEdit: TcxDateEdit
      Left = 90
      Top = 17
      TabOrder = 1
      OnKeyPress = XFCTComboBoxKeyPress
      Width = 121
    end
    object cxLabel3: TcxLabel
      Left = 233
      Top = 18
      Caption = #25130#27490#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object XFEndDateEdit: TcxDateEdit
      Left = 310
      Top = 17
      TabOrder = 3
      OnKeyPress = XFCTComboBoxKeyPress
      Width = 121
    end
    object cxLabel15: TcxLabel
      Left = 31
      Top = 52
      Caption = #21345'   '#21495':'
      ParentColor = False
      Style.Color = clCream
    end
    object XFKHTextEdit: TcxTextEdit
      Left = 90
      Top = 51
      Properties.MaxLength = 9
      TabOrder = 5
      OnKeyPress = XFBHTextEditKeyPress
      Width = 121
    end
    object XFBHTextEdit: TcxTextEdit
      Left = 310
      Top = 51
      Properties.MaxLength = 10
      TabOrder = 6
      OnKeyPress = XFBHTextEditKeyPress
      Width = 121
    end
    object cxLabel17: TcxLabel
      Left = 251
      Top = 52
      Caption = #32534'   '#21495':'
      ParentColor = False
      Style.Color = clCream
    end
    object cxLabel16: TcxLabel
      Left = 255
      Top = 86
      Caption = #22995'  '#21517':'
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
    object XFBMComboBox: TcxComboBox
      Left = 90
      Top = 85
      Properties.OnChange = XFBMComboBoxPropertiesChange
      TabOrder = 10
      OnKeyPress = XFCTComboBoxKeyPress
      Width = 121
    end
    object ReadCardInfoBTN: TcxButton
      Left = 136
      Top = 191
      Width = 75
      Height = 25
      Caption = #35835'  '#21345
      LookAndFeel.NativeStyle = True
      TabOrder = 11
      OnClick = ReadCardInfoBTNClick
    end
    object QueryBTN: TcxButton
      Left = 246
      Top = 191
      Width = 75
      Height = 25
      Caption = #26597'   '#35810
      LookAndFeel.NativeStyle = True
      TabOrder = 12
      OnClick = QueryBTNClick
    end
    object XFXMTextEdit: TcxTextEdit
      Left = 310
      Top = 85
      Properties.MaxLength = 10
      TabOrder = 13
      Width = 121
    end
    object cxLabel2: TcxLabel
      Left = 31
      Top = 156
      Caption = #26426'   '#21495':'
      ParentColor = False
      Style.Color = clCream
    end
    object XFJHTextEdit: TcxTextEdit
      Left = 90
      Top = 155
      Properties.MaxLength = 4
      TabOrder = 15
      OnKeyPress = XFBHTextEditKeyPress
      Width = 121
    end
    object XFCTComboBox: TcxComboBox
      Left = 310
      Top = 155
      TabOrder = 16
      OnKeyPress = XFCTComboBoxKeyPress
      Width = 121
    end
    object cxLabel5: TcxLabel
      Left = 251
      Top = 156
      Caption = #39184'   '#21381':'
      ParentColor = False
      Style.Color = clCream
    end
    object cxLabel6: TcxLabel
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
    object cxLabel7: TcxLabel
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
      OnKeyPress = ZBComboBoxKeyPress
      Width = 121
    end
  end
  object XFADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 80
    Top = 190
  end
  object QADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 368
    Top = 192
  end
end
