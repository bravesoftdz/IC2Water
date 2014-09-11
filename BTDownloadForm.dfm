object BTDownloadFrm: TBTDownloadFrm
  Left = 0
  Top = 0
  Caption = 'BTDownloadFrm'
  ClientHeight = 591
  ClientWidth = 859
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object ExitBTN: TcxButton
    Left = 304
    Top = 538
    Width = 249
    Height = 33
    Caption = #36864#20986#19979#20256#34917#36148#30028#38754
    Colors.Default = clBlack
    LookAndFeel.NativeStyle = True
    TabOrder = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -21
    Font.Name = #24494#36719#38597#40657
    Font.Style = [fsBold]
    ParentFont = False
    OnClick = ExitBTNClick
  end
  object cxGroupBox1: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Align = alTop
    Alignment = alTopCenter
    Caption = #34917#36148#19979#20256#27880#24847#20107#39033#65292#25805#20316#35831#35831#20180#32454#38405#35835#65281
    ParentBackground = False
    ParentColor = False
    ParentFont = False
    Style.Color = clCream
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clRed
    Style.Font.Height = -27
    Style.Font.Name = #24494#36719#38597#40657
    Style.Font.Style = []
    Style.TextColor = clTeal
    Style.IsFontAssigned = True
    TabOrder = 1
    Height = 190
    Width = 853
    object cxMemo1: TcxMemo
      AlignWithMargins = True
      Left = 5
      Top = 43
      Align = alClient
      Lines.Strings = (
        '1'#12289#35813#21151#33021#21482#33021#30001#29087#24713#26412#31995#32479#30340#31649#29702#21592#36827#34892#25805#20316#65292#21516#26102#24517#39035#29087#35835#25805#20316#35268#31243#65292#22914#19981#25353#35201#27714#36827#34892#25805#20316#65292#25152#36896#25104#30340#32463#27982#25439#22833#25105
        #26041#19981#36127#20219#20309#36131#20219#12290
        '2'#12289#26412#31995#32479#20013#21482#33021#23433#35013#19968#21488#34917#36148#26426#65292#22914#22810#20110#19968#21488#21017#26080#27861#36827#34892#34917#36148#19979#20256#65292#21516#26102#65292#20877#27425#19979#20256#34917#36148#20250#23558#19978#19968#27425#30340#34917#36148#28165#31354#65292#25152
        #20197#65292#19979#20256#34917#36148#21518#35831#21450#26102#36890#30693#29992#25143#21040#34917#36148#26426#36827#34892#34917#36148#20805#20540#12290
        '3'#12289#26080#35770#36827#34892#20219#20309#27169#24335#30340#34917#36148#19979#20256#65292#21482#26377#26368#21518#19968#27425#19979#20256#30340#34917#36148#29983#25928#65292#20197#21069#19979#20256#30340#34917#36148#23558#34987#28165#31354#12290
        '4'#12289#8220#34917#36148#26426#21442#25968#8221#25913#21464#21518#24517#39035#20808#20445#23384#20877#19979#20256#65292#21542#21017#19979#20256#30340#21442#25968#20026#26410#25913#21464#21069#30340#21442#25968#12290)
      ParentFont = False
      Style.Color = clInfoBk
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clRed
      Style.Font.Height = -16
      Style.Font.Name = #24494#36719#38597#40657
      Style.Font.Style = []
      Style.TextColor = clTeal
      Style.IsFontAssigned = True
      TabOrder = 0
      Height = 142
      Width = 843
    end
  end
  object cxGroupBox2: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 338
    Align = alTop
    Caption = #19979#20256#25353#28040#36153#27425#25968#29983#25104#30340#34917#36148#35760#24405#65306
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 2
    Height = 93
    Width = 853
    object Panel6: TPanel
      Left = 2
      Top = 56
      Width = 849
      Height = 35
      Align = alBottom
      BevelOuter = bvNone
      Color = clCream
      ParentBackground = False
      TabOrder = 0
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 699
        Height = 35
        Align = alClient
        BevelOuter = bvNone
        Color = clCream
        ParentBackground = False
        TabOrder = 0
        object CSProgressBar: TcxProgressBar
          Left = 0
          Top = 0
          Align = alClient
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 0
          Width = 699
        end
      end
      object Panel2: TPanel
        Left = 699
        Top = 0
        Width = 150
        Height = 35
        Align = alRight
        BevelOuter = bvNone
        Color = clMoneyGreen
        ParentBackground = False
        TabOrder = 1
        object CSBTDownBTN: TcxButton
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 144
          Height = 29
          Align = alClient
          Caption = #19979#20256#28040#36153#27425#25968#34917#36148
          LookAndFeel.NativeStyle = True
          TabOrder = 0
          OnClick = CSBTDownBTNClick
        end
      end
    end
    object CSPanel: TPanel
      Left = 2
      Top = 21
      Width = 849
      Height = 35
      Align = alClient
      BevelOuter = bvNone
      Caption = #19979#20256#25353#28040#36153#27425#25968#29983#25104#30340#34917#36148#65292#35831#28857#20987#8220#19979#20256#28040#36153#27425#25968#34917#36148#8221#65281
      Color = clSkyBlue
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ParentBackground = False
      ParentFont = False
      TabOrder = 1
    end
  end
  object cxGroupBox3: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 437
    Align = alTop
    Caption = #19979#20256#25353#32423#21035#29983#25104#30340#34917#36148#35760#24405#65306
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 3
    Height = 93
    Width = 853
    object Panel8: TPanel
      Left = 2
      Top = 56
      Width = 849
      Height = 35
      Align = alBottom
      Caption = 'Panel8'
      TabOrder = 0
      object Panel3: TPanel
        Left = 1
        Top = 1
        Width = 697
        Height = 33
        Align = alClient
        BevelOuter = bvNone
        Color = clCream
        ParentBackground = False
        TabOrder = 0
        object JBProgressBar: TcxProgressBar
          Left = 0
          Top = 0
          Align = alClient
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 0
          Width = 697
        end
      end
      object Panel4: TPanel
        Left = 698
        Top = 1
        Width = 150
        Height = 33
        Align = alRight
        BevelOuter = bvNone
        Color = clMoneyGreen
        ParentBackground = False
        TabOrder = 1
        object JBBTDownBTN: TcxButton
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 144
          Height = 27
          Align = alClient
          Caption = #19979#20256#32844#21153#34917#36148
          LookAndFeel.NativeStyle = True
          TabOrder = 0
          OnClick = JBBTDownBTNClick
        end
      end
    end
    object JBPanel: TPanel
      Left = 2
      Top = 21
      Width = 849
      Height = 35
      Align = alClient
      BevelOuter = bvNone
      Caption = #19979#20256#25353#32844#21153#29983#25104#30340#34917#36148#65292#35831#28857#20987#8220#19979#20256#32844#21153#34917#36148#8221#65281
      Color = clSkyBlue
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = #24494#36719#38597#40657
      Font.Style = [fsBold]
      ParentBackground = False
      ParentFont = False
      TabOrder = 1
    end
  end
  object Panel5: TPanel
    AlignWithMargins = True
    Left = 0
    Top = 199
    Width = 859
    Height = 41
    Margins.Left = 0
    Margins.Right = 0
    Align = alTop
    Caption = #27880#24847#65281#20004#31181#34917#36148#21482#26377#26368#21518#19968#27425#19979#20256#30340#26377#25928#65281
    Color = clTeal
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -24
    Font.Name = #24494#36719#38597#40657
    Font.Style = [fsBold]
    ParentBackground = False
    ParentFont = False
    TabOrder = 4
  end
  object cxGroupBox4: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 246
    Align = alTop
    Caption = #34917#36148#26426#21442#25968#35774#23450
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 5
    Height = 86
    Width = 853
    object cxLabel1: TcxLabel
      Left = 35
      Top = 25
      Caption = #20018#21475#21495#65306
    end
    object ComNoEdit: TcxTextEdit
      Left = 99
      Top = 24
      Properties.MaxLength = 2
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 1
      OnKeyPress = ComNoEditKeyPress
      Width = 137
    end
    object cxLabel2: TcxLabel
      Left = 263
      Top = 25
      Caption = #26426#22120#21495#65306
    end
    object MachNOEdit: TcxTextEdit
      Left = 329
      Top = 24
      Properties.MaxLength = 2
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 3
      OnKeyPress = MachNOEditKeyPress
      Width = 137
    end
    object SaveBTJPARAMBTN: TcxButton
      Left = 482
      Top = 54
      Width = 122
      Height = 25
      Caption = #20445#23384#34917#36148#26426#21442#25968
      LookAndFeel.NativeStyle = True
      TabOrder = 4
      OnClick = SaveBTJPARAMBTNClick
    end
    object PasswordEdit: TcxTextEdit
      Left = 328
      Top = 53
      Properties.MaxLength = 4
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 5
      OnKeyPress = PasswordEditKeyPress
      Width = 137
    end
    object cxLabel3: TcxLabel
      Left = 278
      Top = 54
      Caption = #23494#30721#65306
    end
    object cxLabel4: TcxLabel
      Left = 20
      Top = 54
      Caption = #26368#22823#28040#36153#65306
    end
    object MaxXFEdit: TcxTextEdit
      Left = 99
      Top = 53
      Properties.MaxLength = 6
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 8
      OnKeyPress = MaxXFEditKeyPress
      Width = 137
    end
    object MaxNumEdit: TcxTextEdit
      Left = 594
      Top = 24
      Properties.MaxLength = 9
      Style.LookAndFeel.NativeStyle = True
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 9
      OnKeyPress = MaxNumEditKeyPress
      Width = 137
    end
    object cxLabel5: TcxLabel
      Left = 482
      Top = 28
      Caption = #26368#22823#34917#36148#26465#25968#65306
    end
    object DownBTJPARAMBTN: TcxButton
      Left = 609
      Top = 54
      Width = 122
      Height = 25
      Caption = #19979#20256#34917#36148#26426#21442#25968
      LookAndFeel.NativeStyle = True
      TabOrder = 11
      OnClick = DownBTJPARAMBTNClick
    end
  end
  object JBBTDownADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 696
    Top = 536
  end
  object CSBTADownDOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 616
    Top = 544
  end
  object BTJPARAMADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 216
    Top = 544
  end
end
