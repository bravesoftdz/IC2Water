object RecordLostCardFRM: TRecordLostCardFRM
  Left = 0
  Top = 0
  Caption = 'RecordLostCardFRM'
  ClientHeight = 601
  ClientWidth = 802
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
    Align = alTop
    Caption = #26597#35810#26465#20214
    TabOrder = 0
    Height = 153
    Width = 796
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
      Left = 84
      Top = 28
      Enabled = False
      Properties.MaxLength = 10
      Properties.ReadOnly = False
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
      Left = 84
      Top = 58
      Enabled = False
      Properties.MaxLength = 10
      Properties.ReadOnly = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 5
      OnKeyPress = cxTextEdit2KeyPress
      Width = 186
    end
    object cxTextEdit3: TcxTextEdit
      Left = 84
      Top = 87
      Enabled = False
      Properties.MaxLength = 10
      Properties.ReadOnly = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 6
      Width = 186
    end
    object cxTextEdit4: TcxTextEdit
      Left = 87
      Top = 117
      Enabled = False
      Properties.MaxLength = 10
      Properties.ReadOnly = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 7
      OnKeyPress = cxTextEdit4KeyPress
      Width = 186
    end
    object cxRadioGroup1: TcxRadioGroup
      Left = 319
      Top = 28
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
    Top = 203
    Align = alTop
    Caption = #21345#29255#20449#24687
    TabOrder = 1
    Height = 270
    Width = 796
    object cxTextEdit5: TcxTextEdit
      Left = 87
      Top = 30
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 0
      OnKeyPress = cxTextEdit5KeyPress
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
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 3
      OnKeyPress = cxTextEdit5KeyPress
      Width = 185
    end
    object cxTextEdit16: TcxTextEdit
      Left = 367
      Top = 63
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 4
      OnKeyPress = cxTextEdit5KeyPress
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
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 6
      OnKeyPress = cxTextEdit5KeyPress
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
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 8
      OnKeyPress = cxTextEdit5KeyPress
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
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 11
      OnKeyPress = cxTextEdit5KeyPress
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
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 13
      OnKeyPress = cxTextEdit5KeyPress
      Width = 185
    end
    object cxTextEdit11: TcxTextEdit
      Left = 367
      Top = 161
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 14
      OnKeyPress = cxTextEdit5KeyPress
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
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 16
      OnKeyPress = cxTextEdit5KeyPress
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
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 19
      OnKeyPress = cxTextEdit5KeyPress
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
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 21
      OnKeyPress = cxTextEdit5KeyPress
      Width = 185
    end
    object cxTextEdit17: TcxTextEdit
      Left = 367
      Top = 227
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 22
      OnKeyPress = cxTextEdit5KeyPress
      Width = 185
    end
    object cxTextEdit15: TcxTextEdit
      Left = 87
      Top = 227
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 23
      OnKeyPress = cxTextEdit5KeyPress
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
    object cxLabel7: TcxLabel
      Left = 319
      Top = 34
      Caption = #21345#21495#65306
    end
    object cxTextEdit14: TcxTextEdit
      Left = 367
      Top = 30
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 27
      OnKeyPress = cxTextEdit5KeyPress
      Width = 185
    end
  end
  object QueryBTN: TcxButton
    Left = 237
    Top = 486
    Width = 75
    Height = 25
    Caption = #26597'   '#35810
    LookAndFeel.NativeStyle = True
    TabOrder = 2
    OnClick = QueryBTNClick
  end
  object PutLostInfoBTN: TcxButton
    Left = 318
    Top = 486
    Width = 75
    Height = 25
    Caption = #25346#22833#30331#35760
    Enabled = False
    LookAndFeel.NativeStyle = True
    TabOrder = 3
    OnClick = PutLostInfoBTNClick
  end
  object DelLostInfoBTN: TcxButton
    Left = 400
    Top = 486
    Width = 75
    Height = 25
    Caption = #35299#25346#30331#35760
    Enabled = False
    LookAndFeel.NativeStyle = True
    TabOrder = 4
    OnClick = DelLostInfoBTNClick
  end
  object NextBTN: TcxButton
    Left = 96
    Top = 486
    Width = 96
    Height = 25
    Caption = #19979#19968#26465#35760#24405
    Enabled = False
    LookAndFeel.NativeStyle = True
    TabOrder = 5
    Visible = False
    OnClick = NextBTNClick
  end
  object cxButton1: TcxButton
    Left = 481
    Top = 486
    Width = 75
    Height = 25
    Caption = #36864'   '#20986
    LookAndFeel.NativeStyle = True
    TabOrder = 6
    OnClick = cxButton1Click
  end
  object Panel1: TPanel
    AlignWithMargins = True
    Left = 3
    Top = 159
    Width = 796
    Height = 41
    Margins.Top = 0
    Margins.Bottom = 0
    Align = alTop
    Caption = #8220#25346#22833#30331#35760#8221#19982#8220#35299#25346#30331#35760#8221#25805#20316#23436#25104#21518#35831#21450#26102#36827#34892#8220#25346#22833#35299#25346#20449#24687#19979#36733#8221#20197#20351#30446#26631#21345#29255#22833#25928#25110#29983#25928#65281
    Color = clTeal
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -17
    Font.Name = #24494#36719#38597#40657
    Font.Style = [fsBold]
    ParentBackground = False
    ParentFont = False
    TabOrder = 7
  end
  object LostCardADOQuery: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 592
    Top = 40
  end
  object InDatabaseADOQuery: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 608
    Top = 272
  end
end
