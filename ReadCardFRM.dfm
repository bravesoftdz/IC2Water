object ReadCardInfoFRM: TReadCardInfoFRM
  Left = 0
  Top = 0
  Caption = 'ReadCardInfoFRM'
  ClientHeight = 543
  ClientWidth = 686
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
    Height = 537
    Width = 680
    object cxLabel1: TcxLabel
      Left = 16
      Top = 24
      Caption = #21345#21495#65306
    end
    object cxTextEdit1: TcxTextEdit
      Left = 67
      Top = 20
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 1
      Width = 185
    end
    object cxLabel7: TcxLabel
      Left = 296
      Top = 24
      Caption = #32534#21495#65306
    end
    object cxTextEdit7: TcxTextEdit
      Left = 344
      Top = 20
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 3
      Width = 185
    end
    object cxLabel15: TcxLabel
      Left = 9
      Top = 393
      Caption = #36153#29575#65306
    end
    object cxTextEdit15: TcxTextEdit
      Left = 57
      Top = 389
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 5
      Width = 185
    end
    object cxLabel16: TcxLabel
      Left = 259
      Top = 393
      Caption = #20351#29992#27425#25968#65306
    end
    object cxTextEdit16: TcxTextEdit
      Left = 337
      Top = 389
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 7
      Width = 185
    end
    object ReadCardInfoBTN: TcxButton
      Left = 167
      Top = 424
      Width = 75
      Height = 25
      Caption = #35835'   '#21345
      LookAndFeel.NativeStyle = True
      TabOrder = 8
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMenuHighlight
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = ReadCardInfoBTNClick
    end
    object CloseFormBTN: TcxButton
      Left = 359
      Top = 424
      Width = 75
      Height = 25
      Caption = #36864'   '#20986
      LookAndFeel.NativeStyle = True
      TabOrder = 9
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMenuHighlight
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = CloseFormBTNClick
    end
    object cxTextEdit17: TcxTextEdit
      Left = 57
      Top = 356
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 10
      Width = 185
    end
    object cxLabel13: TcxLabel
      Left = 9
      Top = 360
      Caption = #25276#37329#65306
    end
    object cxTextEdit18: TcxTextEdit
      Left = 337
      Top = 356
      Properties.ReadOnly = True
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 12
      Width = 185
    end
    object cxGroupBox2: TcxGroupBox
      Left = 11
      Top = 58
      Caption = #21487#20462#25913#20449#24687
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 13
      Height = 207
      Width = 529
      object cxLabel10: TcxLabel
        Left = 286
        Top = 97
        Caption = #32452#21035#65306
      end
      object cxLabel11: TcxLabel
        Left = 286
        Top = 130
        Caption = #35777#21495#65306
      end
      object cxLabel12: TcxLabel
        Left = 8
        Top = 216
        Caption = #23494#30721#65306
        Enabled = False
        Visible = False
      end
      object cxLabel2: TcxLabel
        Left = 6
        Top = 39
        Caption = #22995#21517#65306
      end
      object cxLabel3: TcxLabel
        Left = 6
        Top = 88
        Caption = #37096#38376#65306
      end
      object cxLabel4: TcxLabel
        Left = 6
        Top = 130
        Caption = #36523#20221#65306
      end
      object cxLabel8: TcxLabel
        Left = 286
        Top = 31
        Caption = #24615#21035#65306
      end
      object cxLabel9: TcxLabel
        Left = 286
        Top = 64
        Caption = #29677#21035#65306
      end
      object cxTextEdit10: TcxTextEdit
        Left = 326
        Top = 318
        Properties.MaxLength = 64
        Properties.ReadOnly = False
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 8
        Width = 185
      end
      object cxTextEdit11: TcxTextEdit
        Left = 334
        Top = 126
        Properties.MaxLength = 18
        Properties.ReadOnly = False
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 9
        Width = 185
      end
      object cxTextEdit12: TcxTextEdit
        Left = 56
        Top = 212
        Enabled = False
        Properties.MaxLength = 4
        Properties.ReadOnly = False
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 10
        Visible = False
        Width = 185
      end
      object cxTextEdit2: TcxTextEdit
        Left = 54
        Top = 27
        AutoSize = False
        ParentFont = False
        Properties.MaxLength = 10
        Properties.ReadOnly = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clMenuHighlight
        Style.Font.Height = -27
        Style.Font.Name = 'Tahoma'
        Style.Font.Style = []
        Style.LookAndFeel.NativeStyle = True
        Style.IsFontAssigned = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 11
        Height = 40
        Width = 185
      end
      object cxTextEdit3: TcxTextEdit
        Left = 28
        Top = 287
        Properties.MaxLength = 64
        Properties.ReadOnly = False
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 12
        Width = 185
      end
      object cxTextEdit4: TcxTextEdit
        Left = 28
        Top = 318
        Properties.MaxLength = 8
        Properties.ReadOnly = False
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 13
        Width = 185
      end
      object cxTextEdit9: TcxTextEdit
        Left = 326
        Top = 288
        Properties.MaxLength = 64
        Properties.ReadOnly = False
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 14
        Width = 185
      end
      object cxButton1: TcxButton
        Left = 219
        Top = 166
        Width = 100
        Height = 25
        Caption = #20462#25913#20449#24687
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 15
        OnClick = cxButton1Click
      end
      object SectionNameComboBox: TcxComboBox
        Left = 54
        Top = 78
        AutoSize = False
        ParentFont = False
        Properties.OnChange = SectionNameComboBoxPropertiesChange
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clMenuHighlight
        Style.Font.Height = -27
        Style.Font.Name = 'Tahoma'
        Style.Font.Style = []
        Style.LookAndFeel.NativeStyle = True
        Style.IsFontAssigned = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 16
        OnEnter = SectionNameComboBoxEnter
        OnExit = SectionNameComboBoxExit
        Height = 40
        Width = 185
      end
      object ClassNameComboBox: TcxComboBox
        Left = 334
        Top = 61
        Properties.OnChange = ClassNameComboBoxPropertiesChange
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 17
        OnEnter = ClassNameComboBoxEnter
        OnExit = ClassNameComboBoxExit
        Width = 185
      end
      object GroupNameComboBox: TcxComboBox
        Left = 334
        Top = 93
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 18
        OnEnter = GroupNameComboBoxEnter
        OnExit = GroupNameComboBoxExit
        Width = 185
      end
      object DegreeComboBox: TcxComboBox
        Left = 54
        Top = 126
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 19
        OnEnter = DegreeComboBoxEnter
        OnExit = DegreeComboBoxExit
        Width = 185
      end
      object SexComboBox: TcxComboBox
        Left = 334
        Top = 27
        Properties.Items.Strings = (
          #30007
          #22899)
        Properties.OnChange = ClassNameComboBoxPropertiesChange
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 20
        Text = #30007
        Width = 185
      end
      object cxLabel18: TcxLabel
        Left = 288
        Top = 216
        Caption = #30005#35805#65306
        Enabled = False
        Visible = False
      end
      object cxTextEdit8: TcxTextEdit
        Left = 336
        Top = 212
        Enabled = False
        Properties.MaxLength = 20
        Properties.ReadOnly = False
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 22
        Visible = False
        Width = 185
      end
    end
    object MXBTN: TcxButton
      Left = 263
      Top = 424
      Width = 75
      Height = 25
      Caption = #28040#36153#26126#32454
      Enabled = False
      LookAndFeel.NativeStyle = True
      TabOrder = 14
      OnClick = MXBTNClick
    end
    object cxGroupBox3: TcxGroupBox
      Left = 11
      Top = 272
      Caption = #20462#25913#32423#21035
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 15
      Height = 70
      Width = 529
      object cxLabel6: TcxLabel
        Left = 57
        Top = 32
        Caption = #32423#21035#65306
      end
      object cxTextEdit6: TcxTextEdit
        Left = 105
        Top = 28
        Properties.ReadOnly = False
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 1
        OnKeyPress = cxTextEdit6KeyPress
        Width = 185
      end
      object cxLabel5: TcxLabel
        Left = 238
        Top = 80
        Caption = #20998#32452#65306
      end
      object cxTextEdit5: TcxTextEdit
        Left = 286
        Top = 76
        Properties.MaxLength = 1
        Properties.ReadOnly = False
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 3
        OnKeyPress = cxTextEdit6KeyPress
        Width = 185
      end
      object cxButton2: TcxButton
        Left = 309
        Top = 27
        Width = 100
        Height = 25
        Caption = #20462#25913#32423#21035
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 4
        OnClick = cxButton2Click
      end
    end
    object cxLabel17: TcxLabel
      Left = 274
      Top = 360
      Caption = #21345#20313#39069#65306
    end
  end
  object ADOCardInfoQuery: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 616
    Top = 304
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 592
    Top = 384
  end
end
