object ADDPOSForm: TADDPOSForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = #22686#21152'POS'#26426#65288#22312#25968#25454#24211#34920#20013#22686#21152#19968#26465#35760#24405#65289
  ClientHeight = 308
  ClientWidth = 494
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clMenuHighlight
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  Scaled = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object cxGroupBox1: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Align = alClient
    Caption = 'POS'#26426#21442#25968
    TabOrder = 0
    Height = 302
    Width = 488
    object Label1: TLabel
      Left = 37
      Top = 32
      Width = 45
      Height = 16
      Caption = #26426#21495#65306
    end
    object Label2: TLabel
      Left = 24
      Top = 60
      Width = 57
      Height = 16
      Caption = #39135#22530'ID'#65306
    end
    object Label3: TLabel
      Left = 21
      Top = 89
      Width = 60
      Height = 16
      Caption = #39135#22530#21517#65306
    end
    object Label4: TLabel
      Left = 6
      Top = 118
      Width = 75
      Height = 16
      Caption = #24037#20316#31449#21495#65306
    end
    object Label5: TLabel
      Left = 6
      Top = 147
      Width = 75
      Height = 16
      Caption = #24037#20316#31449#21517#65306
    end
    object Label7: TLabel
      Left = 21
      Top = 176
      Width = 60
      Height = 16
      Caption = #36890#35759#21475#65306
    end
    object Label8: TLabel
      Left = 229
      Top = 32
      Width = 105
      Height = 16
      Caption = #27599#27425#26368#22823#28040#36153#65306
    end
    object Label9: TLabel
      Left = 265
      Top = 89
      Width = 69
      Height = 16
      Caption = 'POS'#23494#30721#65306
    end
    object Label10: TLabel
      Left = 259
      Top = 118
      Width = 75
      Height = 16
      Caption = #21151#33021#31867#22411#65306
    end
    object Label11: TLabel
      Left = 265
      Top = 147
      Width = 69
      Height = 16
      Caption = 'POS'#26426#22411#65306
    end
    object Label12: TLabel
      Left = 259
      Top = 176
      Width = 75
      Height = 16
      Caption = #26368#22823#22686#20540#65306
    end
    object Label6: TLabel
      Left = 229
      Top = 60
      Width = 105
      Height = 16
      Caption = #27599#26085#26368#22823#28040#36153#65306
    end
    object ADDBTN: TcxButton
      Left = 145
      Top = 267
      Width = 80
      Height = 25
      Caption = #22686'   '#21152
      LookAndFeel.NativeStyle = True
      TabOrder = 0
      OnClick = ADDBTNClick
    end
    object ExitBTN: TcxButton
      Left = 247
      Top = 267
      Width = 80
      Height = 25
      Caption = #36864'   '#20986
      LookAndFeel.NativeStyle = True
      TabOrder = 1
      OnClick = ExitBTNClick
    end
    object cxTextEdit1: TcxTextEdit
      Left = 80
      Top = 29
      Properties.MaxLength = 3
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 2
      OnKeyPress = cxTextEdit1KeyPress
      Width = 145
    end
    object cxTextEdit7: TcxTextEdit
      Left = 333
      Top = 29
      Properties.MaxLength = 4
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 6
      OnKeyPress = cxTextEdit7KeyPress
      Width = 145
    end
    object cxTextEdit8: TcxTextEdit
      Left = 333
      Top = 86
      Properties.MaxLength = 4
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 8
      OnKeyPress = cxTextEdit8KeyPress
      Width = 145
    end
    object cxTextEdit9: TcxTextEdit
      Left = 333
      Top = 115
      Enabled = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleDisabled.TextColor = clBlack
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 10
      Text = '0'
      Width = 145
    end
    object cxTextEdit11: TcxTextEdit
      Left = 333
      Top = 173
      Enabled = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleDisabled.TextColor = clBlack
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 11
      Text = '0'
      Width = 145
    end
    object cxTextEdit12: TcxTextEdit
      Left = 80
      Top = 173
      Properties.MaxLength = 2
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 5
      OnKeyPress = cxTextEdit12KeyPress
      Width = 145
    end
    object cxComboBox1: TcxComboBox
      Left = 80
      Top = 57
      Properties.OnChange = cxComboBox1PropertiesChange
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 3
      OnKeyPress = cxComboBox1KeyPress
      Width = 145
    end
    object cxComboBox2: TcxComboBox
      Left = 80
      Top = 86
      Enabled = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.BorderColor = clWhite
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleDisabled.TextColor = clBlue
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 12
      Width = 145
    end
    object cxComboBox3: TcxComboBox
      Left = 80
      Top = 144
      Enabled = False
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.BorderColor = clWhite
      StyleDisabled.Color = clWhite
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleDisabled.TextColor = clBlue
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 13
      Width = 145
    end
    object cxComboBox4: TcxComboBox
      Left = 80
      Top = 115
      Properties.OnChange = cxComboBox4PropertiesChange
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 4
      OnKeyPress = cxComboBox4KeyPress
      Width = 145
    end
    object cxComboBox5: TcxComboBox
      Left = 333
      Top = 144
      Properties.Items.Strings = (
        #25910#36153#26426
        #35746#39184#26426
        #34917#36148#26426
        #20805#20540#26426
        #25320#27454#26426)
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 9
      Text = #25910#36153#26426
      OnKeyPress = cxComboBox5KeyPress
      Width = 145
    end
    object cxTextEdit2: TcxTextEdit
      Left = 333
      Top = 57
      Properties.MaxLength = 4
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 7
      OnKeyPress = cxTextEdit2KeyPress
      Width = 145
    end
    object CheckBox1: TCheckBox
      Left = 57
      Top = 243
      Width = 153
      Height = 17
      Caption = #26159#21542#35782#21035#35746#39184#26631#24535
      Color = clMoneyGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 14
    end
    object CheckBox2: TCheckBox
      Left = 259
      Top = 243
      Width = 174
      Height = 17
      Caption = #26159#21542#28165#31354#34917#36148#28040#36153#35760#24405
      Color = clMoneyGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 15
    end
    object CheckBox3: TCheckBox
      Left = 57
      Top = 215
      Width = 174
      Height = 17
      Caption = #27599#22825'/'#39184#26368#22823#28040#36153#27425#25968
      Color = clMoneyGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 16
      OnClick = CheckBox3Click
    end
    object MaxCSEdit: TcxTextEdit
      Left = 228
      Top = 211
      Properties.MaxLength = 2
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 17
      OnExit = MaxCSEditExit
      OnKeyPress = MaxCSEditKeyPress
      Width = 45
    end
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 160
    Top = 104
  end
end
