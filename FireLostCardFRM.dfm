object FireLostCardInfoFRM: TFireLostCardInfoFRM
  Left = 0
  Top = 0
  Caption = 'FireLostCardInfoFRM'
  ClientHeight = 629
  ClientWidth = 643
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clMenuHighlight
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object cxGroupBox1: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Margins.Bottom = 0
    Align = alTop
    Caption = #26597#35810#26465#20214
    TabOrder = 0
    Height = 153
    Width = 637
    object cxRadioButton1: TcxRadioButton
      Left = 24
      Top = 32
      Width = 57
      Height = 17
      Caption = #32534#21495#65306
      TabOrder = 0
      OnClick = cxRadioButton1Click
    end
    object cxRadioButton2: TcxRadioButton
      Left = 24
      Top = 61
      Width = 57
      Height = 17
      Caption = #21345#21495#65306
      TabOrder = 1
      OnClick = cxRadioButton2Click
    end
    object cxRadioButton3: TcxRadioButton
      Left = 24
      Top = 90
      Width = 57
      Height = 17
      Caption = #22995#21517#65306
      TabOrder = 2
      OnClick = cxRadioButton3Click
    end
    object cxRadioButton4: TcxRadioButton
      Left = 24
      Top = 120
      Width = 57
      Height = 17
      Caption = #35777#21495#65306
      TabOrder = 3
      OnClick = cxRadioButton4Click
    end
    object cxTextEdit1: TcxTextEdit
      Left = 87
      Top = 25
      Enabled = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 4
      OnExit = cxTextEdit1Exit
      OnKeyPress = cxTextEdit1KeyPress
      Width = 186
    end
    object cxTextEdit2: TcxTextEdit
      Left = 87
      Top = 54
      Enabled = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 5
      OnKeyPress = cxTextEdit2KeyPress
      Width = 186
    end
    object cxTextEdit3: TcxTextEdit
      Left = 87
      Top = 83
      Enabled = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 6
      Width = 186
    end
    object cxTextEdit4: TcxTextEdit
      Left = 87
      Top = 113
      Enabled = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 7
      Width = 186
    end
    object cxButton1: TcxButton
      Left = 293
      Top = 25
      Width = 75
      Height = 25
      Caption = #26597'   '#35810
      LookAndFeel.NativeStyle = True
      TabOrder = 8
      OnClick = cxButton1Click
    end
  end
  object cxGroupBox2: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 159
    Align = alTop
    Caption = #21345#29255#20449#24687
    TabOrder = 1
    Height = 297
    Width = 637
    object cxTextEdit5: TcxTextEdit
      Left = 87
      Top = 30
      Enabled = False
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 0
      OnKeyPress = cxTextEdit18KeyPress
      Width = 185
    end
    object cxLabel1: TcxLabel
      Left = 39
      Top = 34
      Caption = #32534#21495#65306
    end
    object cxLabel2: TcxLabel
      Left = 39
      Top = 67
      Caption = #22995#21517#65306
    end
    object cxTextEdit6: TcxTextEdit
      Left = 87
      Top = 63
      Enabled = False
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 3
      OnKeyPress = cxTextEdit18KeyPress
      Width = 185
    end
    object cxTextEdit16: TcxTextEdit
      Left = 367
      Top = 63
      Enabled = False
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 4
      OnKeyPress = cxTextEdit18KeyPress
      Width = 185
    end
    object cxLabel8: TcxLabel
      Left = 319
      Top = 67
      Caption = #24615#21035#65306
    end
    object cxTextEdit19: TcxTextEdit
      Left = 367
      Top = 96
      Enabled = False
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 6
      OnKeyPress = cxTextEdit18KeyPress
      Width = 185
    end
    object cxLabel9: TcxLabel
      Left = 319
      Top = 100
      Caption = #29677#21035#65306
    end
    object cxTextEdit7: TcxTextEdit
      Left = 87
      Top = 96
      Enabled = False
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 8
      OnKeyPress = cxTextEdit18KeyPress
      Width = 185
    end
    object cxLabel3: TcxLabel
      Left = 39
      Top = 100
      Caption = #37096#38376#65306
    end
    object cxLabel4: TcxLabel
      Left = 39
      Top = 132
      Caption = #36523#20221#65306
    end
    object cxTextEdit8: TcxTextEdit
      Left = 87
      Top = 128
      Enabled = False
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 11
      OnKeyPress = cxTextEdit18KeyPress
      Width = 185
    end
    object cxLabel10: TcxLabel
      Left = 319
      Top = 132
      Caption = #32452#21035#65306
    end
    object cxTextEdit10: TcxTextEdit
      Left = 367
      Top = 128
      Enabled = False
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 13
      OnKeyPress = cxTextEdit18KeyPress
      Width = 185
    end
    object cxTextEdit11: TcxTextEdit
      Left = 367
      Top = 161
      Enabled = False
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 14
      OnKeyPress = cxTextEdit18KeyPress
      Width = 185
    end
    object cxLabel11: TcxLabel
      Left = 319
      Top = 165
      Caption = #35777#21495#65306
    end
    object cxTextEdit9: TcxTextEdit
      Left = 87
      Top = 161
      Enabled = False
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 16
      OnKeyPress = cxTextEdit18KeyPress
      Width = 185
    end
    object cxLabel5: TcxLabel
      Left = 39
      Top = 165
      Caption = #21345#31867#65306
    end
    object cxLabel6: TcxLabel
      Left = 39
      Top = 198
      Caption = #32423#21035#65306
    end
    object cxTextEdit13: TcxTextEdit
      Left = 87
      Top = 194
      Enabled = False
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 19
      OnKeyPress = cxTextEdit18KeyPress
      Width = 185
    end
    object cxLabel12: TcxLabel
      Left = 319
      Top = 198
      Caption = #23494#30721#65306
    end
    object cxTextEdit12: TcxTextEdit
      Left = 367
      Top = 194
      Enabled = False
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 21
      OnKeyPress = cxTextEdit18KeyPress
      Width = 185
    end
    object cxTextEdit17: TcxTextEdit
      Left = 367
      Top = 227
      Enabled = False
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 22
      OnKeyPress = cxTextEdit18KeyPress
      Width = 185
    end
    object cxTextEdit15: TcxTextEdit
      Left = 87
      Top = 227
      Enabled = False
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 23
      OnKeyPress = cxTextEdit18KeyPress
      Width = 185
    end
    object cxLabel15: TcxLabel
      Left = 39
      Top = 231
      Caption = #36153#29575#65306
    end
    object cxLabel13: TcxLabel
      Left = 319
      Top = 231
      Caption = #21345#20313#65306
    end
    object cxLabel14: TcxLabel
      Left = 319
      Top = 265
      Caption = #25276#37329#65306
    end
    object cxTextEdit18: TcxTextEdit
      Left = 367
      Top = 261
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 27
      OnKeyPress = cxTextEdit18KeyPress
      Width = 185
    end
  end
  object cxButton2: TcxButton
    Left = 370
    Top = 512
    Width = 96
    Height = 25
    Caption = #26080#21345#36864#21345
    LookAndFeel.NativeStyle = True
    TabOrder = 2
    OnClick = cxButton2Click
  end
  object cxButton3: TcxButton
    Left = 480
    Top = 512
    Width = 75
    Height = 25
    Caption = #36864'   '#20986
    LookAndFeel.NativeStyle = True
    TabOrder = 3
    OnClick = cxButton3Click
  end
  object NextBTN: TcxButton
    Left = 260
    Top = 512
    Width = 96
    Height = 25
    Caption = #19979#19968#26465#35760#24405
    Enabled = False
    LookAndFeel.NativeStyle = True
    TabOrder = 4
    Visible = False
    OnClick = NextBTNClick
  end
  object cxTextEdit14: TcxTextEdit
    Left = 370
    Top = 189
    Enabled = False
    Properties.ReadOnly = True
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.Color = clWhite
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 5
    OnKeyPress = cxTextEdit18KeyPress
    Width = 185
  end
  object cxLabel7: TcxLabel
    Left = 322
    Top = 193
    Caption = #21345#21495#65306
  end
  object Panel1: TPanel
    AlignWithMargins = True
    Left = 3
    Top = 462
    Width = 637
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    Caption = #36827#34892#8220#26080#21345#36864#21345#8221#21069#21153#24517#36827#34892#21345#29255#25346#22833#65281#26080#38656#36864#25276#37329#65281
    Color = clRed
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 7
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 360
    Top = 104
  end
  object ADOQuery2: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 432
    Top = 104
  end
  object InDatabaseADOQuery: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 520
    Top = 104
  end
  object ADOQuery3: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 424
    Top = 56
  end
end
