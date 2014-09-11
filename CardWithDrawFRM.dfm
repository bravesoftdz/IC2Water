object CardWithDrawMoneyFRM: TCardWithDrawMoneyFRM
  Left = 0
  Top = 0
  Caption = 'CardWithDrawMoneyFRM'
  ClientHeight = 480
  ClientWidth = 670
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
    Align = alClient
    Alignment = alCenterCenter
    TabOrder = 0
    Height = 474
    Width = 664
    object ReadCardBTN: TcxButton
      Left = 287
      Top = 408
      Width = 75
      Height = 25
      Caption = #35835'  '#21345
      LookAndFeel.NativeStyle = True
      TabOrder = 0
      OnClick = ReadCardBTNClick
    end
    object WithDrawBTN: TcxButton
      Left = 371
      Top = 408
      Width = 75
      Height = 25
      Caption = #21462'   '#27454
      Enabled = False
      LookAndFeel.NativeStyle = True
      TabOrder = 1
      OnClick = WithDrawBTNClick
    end
    object ExitWithDrawBTN: TcxButton
      Left = 454
      Top = 408
      Width = 75
      Height = 25
      Caption = #36864'   '#20986
      LookAndFeel.NativeStyle = True
      TabOrder = 2
      OnClick = ExitWithDrawBTNClick
    end
    object cxGroupBox2: TcxGroupBox
      Left = 16
      Top = 281
      Caption = #24555#36895#21462#27454
      TabOrder = 3
      Height = 120
      Width = 513
      object WithDraw5BTN: TcxButton
        Left = 70
        Top = 26
        Width = 75
        Height = 25
        Caption = '5'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 0
        OnClick = WithDraw5BTNClick
      end
      object WithDraw10BTN: TcxButton
        Left = 144
        Top = 26
        Width = 75
        Height = 25
        Caption = '10'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 1
        OnClick = WithDraw10BTNClick
      end
      object WithDraw20BTN: TcxButton
        Left = 218
        Top = 26
        Width = 75
        Height = 25
        Caption = '20'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 2
        OnClick = WithDraw20BTNClick
      end
      object WithDraw30BTN: TcxButton
        Left = 292
        Top = 26
        Width = 75
        Height = 25
        Caption = '30'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 3
        OnClick = WithDraw30BTNClick
      end
      object WithDraw40BTN: TcxButton
        Left = 366
        Top = 26
        Width = 75
        Height = 25
        Caption = '40'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 4
        OnClick = WithDraw40BTNClick
      end
      object WithDraw90BTN: TcxButton
        Left = 366
        Top = 50
        Width = 75
        Height = 25
        Caption = '90'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 5
        OnClick = WithDraw90BTNClick
      end
      object WithDraw80BTN: TcxButton
        Left = 292
        Top = 50
        Width = 75
        Height = 25
        Caption = '80'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 6
        OnClick = WithDraw80BTNClick
      end
      object WithDraw70BTN: TcxButton
        Left = 218
        Top = 50
        Width = 75
        Height = 25
        Caption = '70'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 7
        OnClick = WithDraw70BTNClick
      end
      object WithDraw60BTN: TcxButton
        Left = 144
        Top = 50
        Width = 75
        Height = 25
        Caption = '60'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 8
        OnClick = WithDraw60BTNClick
      end
      object WithDraw50BTN: TcxButton
        Left = 70
        Top = 50
        Width = 75
        Height = 25
        Caption = '50'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 9
        OnClick = WithDraw50BTNClick
      end
      object WithDraw1000BTN: TcxButton
        Left = 366
        Top = 74
        Width = 75
        Height = 25
        Caption = '1000'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 10
        OnClick = WithDraw1000BTNClick
      end
      object WithDraw500BTN: TcxButton
        Left = 292
        Top = 74
        Width = 75
        Height = 25
        Caption = '500'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 11
        OnClick = WithDraw500BTNClick
      end
      object WithDraw200BTN: TcxButton
        Left = 218
        Top = 74
        Width = 75
        Height = 25
        Caption = '200'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 12
        OnClick = WithDraw200BTNClick
      end
      object WithDraw150BTN: TcxButton
        Left = 144
        Top = 74
        Width = 75
        Height = 25
        Caption = '150'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 13
        OnClick = WithDraw150BTNClick
      end
      object WithDraw100BTN: TcxButton
        Left = 70
        Top = 74
        Width = 75
        Height = 25
        Caption = '100'
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 14
        OnClick = WithDraw100BTNClick
      end
    end
    object cxLabel1: TcxLabel
      Left = 16
      Top = 24
      Caption = #21345#21495#65306
    end
    object cxLabel10: TcxLabel
      Left = 296
      Top = 123
      Caption = #32452#21035#65306
    end
    object cxLabel11: TcxLabel
      Left = 296
      Top = 156
      Caption = #35777#21495#65306
    end
    object cxLabel12: TcxLabel
      Left = 296
      Top = 189
      Caption = #23494#30721#65306
    end
    object cxLabel13: TcxLabel
      Left = 16
      Top = 222
      Caption = #25276#37329#65306
    end
    object cxLabel14: TcxLabel
      Left = 296
      Top = 222
      Caption = #21345#20313#65306
    end
    object cxLabel15: TcxLabel
      Left = 16
      Top = 255
      Caption = #36153#29575#65306
    end
    object cxLabel16: TcxLabel
      Left = 266
      Top = 255
      Caption = #21462#27454#37329#39069#65306
    end
    object cxLabel2: TcxLabel
      Left = 16
      Top = 57
      Caption = #22995#21517#65306
    end
    object cxLabel3: TcxLabel
      Left = 16
      Top = 90
      Caption = #37096#38376#65306
    end
    object cxLabel4: TcxLabel
      Left = 16
      Top = 123
      Caption = #36523#20221#65306
    end
    object cxLabel5: TcxLabel
      Left = 16
      Top = 156
      Caption = #20998#32452#65306
    end
    object cxLabel6: TcxLabel
      Left = 16
      Top = 189
      Caption = #32423#21035#65306
    end
    object cxLabel7: TcxLabel
      Left = 296
      Top = 24
      Caption = #32534#21495#65306
    end
    object cxLabel8: TcxLabel
      Left = 296
      Top = 57
      Caption = #24615#21035#65306
    end
    object cxLabel9: TcxLabel
      Left = 296
      Top = 90
      Caption = #29677#21035#65306
    end
    object cxTextEdit1: TcxTextEdit
      Left = 64
      Top = 20
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 20
      Width = 185
    end
    object cxTextEdit10: TcxTextEdit
      Left = 344
      Top = 119
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 21
      Width = 185
    end
    object cxTextEdit11: TcxTextEdit
      Left = 344
      Top = 152
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 22
      Width = 185
    end
    object cxTextEdit12: TcxTextEdit
      Left = 344
      Top = 185
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 23
      Width = 185
    end
    object cxTextEdit15: TcxTextEdit
      Left = 64
      Top = 251
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 24
      Width = 185
    end
    object cxTextEdit16: TcxTextEdit
      Left = 344
      Top = 251
      Properties.ReadOnly = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 25
      OnExit = cxTextEdit16Exit
      OnKeyPress = cxTextEdit16KeyPress
      Width = 185
    end
    object cxTextEdit17: TcxTextEdit
      Left = 64
      Top = 218
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 26
      Width = 185
    end
    object cxTextEdit18: TcxTextEdit
      Left = 344
      Top = 218
      ParentFont = False
      Properties.ReadOnly = True
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clRed
      Style.Font.Height = -13
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.LookAndFeel.NativeStyle = True
      Style.IsFontAssigned = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 27
      Width = 185
    end
    object cxTextEdit2: TcxTextEdit
      Left = 64
      Top = 53
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 28
      Width = 185
    end
    object cxTextEdit3: TcxTextEdit
      Left = 64
      Top = 86
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 29
      Width = 185
    end
    object cxTextEdit4: TcxTextEdit
      Left = 64
      Top = 119
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 30
      Width = 185
    end
    object cxTextEdit5: TcxTextEdit
      Left = 64
      Top = 152
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 31
      Width = 185
    end
    object cxTextEdit6: TcxTextEdit
      Left = 64
      Top = 185
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 32
      Width = 185
    end
    object cxTextEdit7: TcxTextEdit
      Left = 344
      Top = 20
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 33
      Width = 185
    end
    object cxTextEdit8: TcxTextEdit
      Left = 344
      Top = 53
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 34
      Width = 185
    end
    object cxTextEdit9: TcxTextEdit
      Left = 344
      Top = 86
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 35
      Width = 185
    end
  end
  object ADOWithDrawQuery: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 88
    Top = 424
  end
  object HJLADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 224
    Top = 416
  end
  object ADOTable1: TADOTable
    Connection = SDIAppForm.ADOConnection1
    Left = 168
    Top = 416
  end
end
