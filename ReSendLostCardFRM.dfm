object ResendLostCardnewFRM: TResendLostCardnewFRM
  Left = 0
  Top = 0
  Caption = 'ResendLostCardnewFRM'
  ClientHeight = 597
  ClientWidth = 734
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clMenuHighlight
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
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
    Visible = False
    Height = 0
    Width = 728
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
      StyleDisabled.Color = clBtnFace
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
      StyleDisabled.Color = clBtnFace
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
      StyleDisabled.Color = clBtnFace
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
      StyleDisabled.Color = clBtnFace
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 7
      Width = 186
    end
    object cxRadioGroup1: TcxRadioGroup
      Left = 315
      Top = 25
      Caption = #21345#29366#24577
      Properties.Items = <
        item
          Caption = #22312#29992
        end
        item
          Caption = #25346#22833
        end>
      ItemIndex = 0
      TabOrder = 8
      Height = 105
      Width = 76
    end
  end
  object cxGroupBox2: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 114
    Align = alTop
    Caption = #21345#29255#20449#24687
    TabOrder = 1
    Height = 272
    Width = 728
    object cxTextEdit5: TcxTextEdit
      Left = 87
      Top = 30
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 0
      OnKeyPress = cxTextEdit14KeyPress
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
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 3
      OnKeyPress = cxTextEdit14KeyPress
      Width = 185
    end
    object cxTextEdit16: TcxTextEdit
      Left = 367
      Top = 63
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 4
      OnKeyPress = cxTextEdit14KeyPress
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
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 6
      OnKeyPress = cxTextEdit14KeyPress
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
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 8
      OnKeyPress = cxTextEdit14KeyPress
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
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 11
      OnKeyPress = cxTextEdit14KeyPress
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
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 13
      OnKeyPress = cxTextEdit14KeyPress
      Width = 185
    end
    object cxTextEdit11: TcxTextEdit
      Left = 367
      Top = 161
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 14
      OnKeyPress = cxTextEdit14KeyPress
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
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 16
      OnKeyPress = cxTextEdit14KeyPress
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
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 19
      OnKeyPress = cxTextEdit14KeyPress
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
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 21
      OnKeyPress = cxTextEdit14KeyPress
      Width = 185
    end
    object cxTextEdit17: TcxTextEdit
      Left = 367
      Top = 227
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 22
      OnKeyPress = cxTextEdit14KeyPress
      Width = 185
    end
    object cxTextEdit15: TcxTextEdit
      Left = 87
      Top = 227
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 23
      OnKeyPress = cxTextEdit14KeyPress
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
    object cxLabel17: TcxLabel
      Left = 289
      Top = 34
      Caption = #20351#29992#26399#38480#65306
    end
    object UseDateEdit: TcxDateEdit
      Left = 367
      Top = 30
      EditValue = 42582d
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 27
      Width = 185
    end
  end
  object cxButton1: TcxButton
    Left = 318
    Top = 551
    Width = 75
    Height = 25
    Caption = #26597'   '#35810
    Enabled = False
    LookAndFeel.NativeStyle = True
    TabOrder = 2
    Visible = False
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 623
    Top = 551
    Width = 75
    Height = 25
    Caption = #25346#22833#30331#35760
    Enabled = False
    LookAndFeel.NativeStyle = True
    TabOrder = 3
    Visible = False
    OnClick = cxButton2Click
  end
  object cxGroupBox3: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 6
    Margins.Bottom = 0
    Align = alTop
    Caption = #34917#21150#25163#32493
    TabOrder = 4
    Height = 58
    Width = 728
    object cxLabel7: TcxLabel
      Left = 12
      Top = 23
      Caption = #21407#21345#21495#65306
    end
    object cxTextEdit14: TcxTextEdit
      Left = 75
      Top = 20
      Properties.ReadOnly = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 1
      OnKeyPress = cxTextEdit14KeyPress
      Width = 185
    end
    object cxLabel14: TcxLabel
      Left = 276
      Top = 23
      Caption = #34917#21345#21495#65306
    end
    object cxTextEdit18: TcxTextEdit
      Left = 336
      Top = 20
      Properties.MaxLength = 6
      Properties.ReadOnly = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 3
      OnKeyPress = cxTextEdit2KeyPress
      Width = 185
    end
    object cxLabel16: TcxLabel
      Left = 536
      Top = 23
      Caption = #34917#21345#36153#65306
    end
    object cxTextEdit20: TcxTextEdit
      Left = 599
      Top = 20
      Properties.MaxLength = 2
      Properties.ReadOnly = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 5
      OnKeyPress = cxTextEdit2KeyPress
      Width = 111
    end
  end
  object NextBTN: TcxButton
    Left = 193
    Top = 551
    Width = 96
    Height = 25
    Caption = #19979#19968#26465#35760#24405
    Enabled = False
    LookAndFeel.NativeStyle = True
    TabOrder = 5
    Visible = False
    OnClick = NextBTNClick
  end
  object cxButton3: TcxButton
    Left = 400
    Top = 399
    Width = 75
    Height = 25
    Caption = #34917#21457#26032#21345
    Enabled = False
    LookAndFeel.NativeStyle = True
    TabOrder = 6
    OnClick = cxButton3Click
  end
  object cxButton4: TcxButton
    Left = 481
    Top = 399
    Width = 75
    Height = 25
    Caption = #36864'   '#20986
    LookAndFeel.NativeStyle = True
    TabOrder = 7
    OnClick = cxButton4Click
  end
  object Panel1: TPanel
    AlignWithMargins = True
    Left = 3
    Top = 70
    Width = 728
    Height = 41
    Margins.Top = 6
    Margins.Bottom = 0
    Align = alTop
    Caption = #34917#21457#26032#21345#26102#24517#39035#25910#21462#34917#21345#36153'!'
    Color = clRed
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -27
    Font.Name = #24494#36719#38597#40657
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 8
  end
  object cxButton5: TcxButton
    Left = 319
    Top = 399
    Width = 75
    Height = 25
    Caption = #26597'   '#35810
    LookAndFeel.NativeStyle = True
    TabOrder = 9
    OnClick = cxButton5Click
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 648
    Top = 272
  end
  object InDatabaseADOQuery: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 648
    Top = 328
  end
  object ADOQuery2: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 648
    Top = 392
  end
  object ADOQuery3: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 648
    Top = 464
  end
end
