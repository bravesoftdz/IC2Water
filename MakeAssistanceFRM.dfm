object MakeAssistancedFRM: TMakeAssistancedFRM
  Left = 0
  Top = 0
  Margins.Top = 0
  Caption = 'MakeAssistancedFRM'
  ClientHeight = 638
  ClientWidth = 982
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clMenuHighlight
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object cxGroupBox1: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Align = alTop
    Alignment = alTopCenter
    Caption = #34917#36148#29983#25104#27880#24847#20107#39033#65292#25805#20316#35831#35831#20180#32454#38405#35835#65281
    ParentBackground = False
    ParentColor = False
    ParentFont = False
    Style.Color = clCream
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clRed
    Style.Font.Height = -27
    Style.Font.Name = #24494#36719#38597#40657
    Style.Font.Style = []
    Style.IsFontAssigned = True
    TabOrder = 0
    Height = 134
    Width = 976
    object cxMemo1: TcxMemo
      AlignWithMargins = True
      Left = 5
      Top = 43
      Align = alClient
      Lines.Strings = (
        '1'#12289#35813#21151#33021#21482#33021#30001#29087#24713#26412#31995#32479#30340#31649#29702#21592#36827#34892#25805#20316#65292#21516#26102#24517#39035#29087#35835#25805#20316#35268#31243#65292#22914#19981#25353#35201#27714#36827#34892#25805#20316#65292#25152#36896#25104#30340#32463#27982#25439#22833#25105#26041#19981#36127#20219#20309#36131#20219#12290
        '2'#12289#34917#36148#29983#25104#21518#65292#22914#20877#27425#29983#25104#34917#36148#20250#23558#19978#19968#27425#30340#34917#36148#28165#31354#65292#25152#20197#65292#29983#25104#34917#36148#21518#35831#21450#26102#19979#20256#21040#34917#36148#26426#12290
        '3'#12289#34917#36148#30340#29983#25104#26412#31995#32479#35774#35745#20026#20004#31181#29983#25104#27169#24335#65292#29983#25104#34917#36148#26102#21482#33021#36873#25321#20004#31181#27169#24335#20013#30340#19968#20010#65292#22914#37325#22797#29983#25104#65292#21482#26377#26368#21518#36873#25321#30340#27169#24335#36215#25928#12290
        '4'#12289#25353#28040#36153#27425#25968#29983#25104#65306#25353#29031#22312#26576#20010#26102#38388#27573#31867#30340#28040#36153#27425#25968#29983#25104#34917#36148#65292#36229#36807#19968#23450#28040#36153#27425#25968#19978#38480#65292#34917#36148#20026#19968#22266#23450#37329#39069#12290
        '5'#12289#25353#32423#21035#27599#26376#29983#25104#65306#25353#29031#28040#36153#32773#30340#32423#21035#65292#29983#25104#25351#23450#26376#20221#30340#19981#21516#32423#21035#30340#34917#36148#12290)
      ParentFont = False
      Style.Color = clInfoBk
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clRed
      Style.Font.Height = -16
      Style.Font.Name = #24494#36719#38597#40657
      Style.Font.Style = []
      Style.IsFontAssigned = True
      TabOrder = 0
      Height = 86
      Width = 966
    end
  end
  object cxGroupBox2: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 143
    Align = alTop
    Caption = #25353#28040#36153#27425#25968#29983#25104#34917#36148#65306
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clMenuHighlight
    Style.Font.Height = -16
    Style.Font.Name = 'Tahoma'
    Style.Font.Style = []
    Style.LookAndFeel.NativeStyle = True
    Style.IsFontAssigned = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 1
    Height = 134
    Width = 976
    object Panel1: TPanel
      Left = 2
      Top = 97
      Width = 972
      Height = 35
      Align = alTop
      BevelOuter = bvNone
      ParentColor = True
      TabOrder = 0
      object CSBTProgressBar: TcxProgressBar
        AlignWithMargins = True
        Left = 1
        Top = 1
        Margins.Left = 1
        Margins.Top = 1
        Margins.Right = 1
        Margins.Bottom = 1
        Align = alClient
        ParentColor = False
        Properties.BarStyle = cxbsGradientLEDs
        Style.Color = clWhite
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 0
        Width = 970
      end
    end
    object Panel2: TPanel
      Left = 2
      Top = 24
      Width = 972
      Height = 73
      Align = alTop
      BevelOuter = bvNone
      ParentColor = True
      TabOrder = 1
      object Label1: TLabel
        Left = 39
        Top = 7
        Width = 80
        Height = 19
        Caption = #36215#22987#26102#38388#65306
        Color = clCream
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object Label2: TLabel
        Left = 279
        Top = 7
        Width = 80
        Height = 19
        Caption = #25130#33267#26102#38388#65306
        Color = clCream
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object Label3: TLabel
        Left = 7
        Top = 43
        Width = 112
        Height = 19
        Caption = #27599#27425#34917#36148#37329#39069#65306
        Color = clCream
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object Label4: TLabel
        Left = 247
        Top = 43
        Width = 112
        Height = 19
        Caption = #34917#36148#27425#25968#19978#38480#65306
        Color = clCream
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object BeginDateEdit: TcxDateEdit
        Left = 117
        Top = 4
        TabOrder = 0
        Width = 121
      end
      object EndDateEdit: TcxDateEdit
        Left = 356
        Top = 4
        TabOrder = 1
        Width = 121
      end
      object BTJETextEdit: TcxTextEdit
        Left = 117
        Top = 40
        TabOrder = 2
        OnKeyPress = BTJETextEditKeyPress
        Width = 121
      end
      object BTCSUTextEdit: TcxTextEdit
        Left = 356
        Top = 40
        TabOrder = 3
        OnKeyPress = BTCSUTextEditKeyPress
        Width = 121
      end
      object CSBTBTN: TcxButton
        Left = 489
        Top = 41
        Width = 85
        Height = 25
        Caption = #29983#25104#34917#36148
        LookAndFeel.NativeStyle = True
        TabOrder = 4
        OnClick = CSBTBTNClick
      end
    end
  end
  object cxGroupBox3: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 330
    Align = alTop
    Caption = #25353#32423#21035#27599#26376#29983#25104#34917#36148#65306
    ParentBackground = False
    ParentColor = False
    ParentFont = False
    Style.Color = clCream
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clMaroon
    Style.Font.Height = -16
    Style.Font.Name = 'Tahoma'
    Style.Font.Style = []
    Style.LookAndFeel.Kind = lfUltraFlat
    Style.LookAndFeel.NativeStyle = True
    Style.LookAndFeel.SkinName = ''
    Style.Shadow = False
    Style.IsFontAssigned = True
    StyleDisabled.LookAndFeel.Kind = lfUltraFlat
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.SkinName = ''
    StyleFocused.LookAndFeel.Kind = lfUltraFlat
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.SkinName = ''
    StyleHot.LookAndFeel.Kind = lfUltraFlat
    StyleHot.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.SkinName = ''
    TabOrder = 2
    Height = 199
    Width = 976
    object Panel3: TPanel
      Left = 2
      Top = 24
      Width = 972
      Height = 73
      Align = alTop
      BevelOuter = bvNone
      ParentColor = True
      TabOrder = 0
      object Label5: TLabel
        Left = 39
        Top = 8
        Width = 80
        Height = 19
        Caption = #34917#36148#32423#21035#65306
      end
      object Label6: TLabel
        Left = 279
        Top = 8
        Width = 80
        Height = 19
        Caption = #34917#36148#37329#39069#65306
      end
      object BTGComboBox: TcxComboBox
        Left = 117
        Top = 5
        TabOrder = 0
        Width = 121
      end
      object BTJEGTextEdit: TcxTextEdit
        Left = 356
        Top = 5
        TabOrder = 1
        OnKeyPress = BTJEGTextEditKeyPress
        Width = 121
      end
      object JBBTBTN: TcxButton
        Left = 489
        Top = 41
        Width = 85
        Height = 25
        Caption = #29983#25104#34917#36148
        LookAndFeel.NativeStyle = True
        TabOrder = 2
        OnClick = JBBTBTNClick
      end
      object JBJEBTN: TcxButton
        Left = 489
        Top = 6
        Width = 150
        Height = 25
        Caption = #30830#23450#32423#21035#34917#36148#37329#39069
        LookAndFeel.NativeStyle = True
        TabOrder = 3
        OnClick = JBJEBTNClick
      end
    end
    object Panel4: TPanel
      Left = 2
      Top = 97
      Width = 972
      Height = 63
      Align = alTop
      BevelOuter = bvNone
      ParentColor = True
      TabOrder = 1
      object JBRQCheckGroup: TcxCheckGroup
        AlignWithMargins = True
        Left = 3
        Top = 0
        Margins.Top = 0
        Align = alClient
        Caption = #26376#20221#36873#25321
        ParentFont = False
        Properties.Columns = 12
        Properties.Items = <
          item
            Caption = #19968#26376
          end
          item
            Caption = #20108#26376
          end
          item
            Caption = #19977#26376
          end
          item
            Caption = #22235#26376
          end
          item
            Caption = #20116#26376
          end
          item
            Caption = #20845#26376
          end
          item
            Caption = #19971#26376
          end
          item
            Caption = #20843#26376
          end
          item
            Caption = #20061#26376
          end
          item
            Caption = #21313#26376
          end
          item
            Caption = #21313#19968#26376
          end
          item
            Caption = #21313#20108#26376
          end>
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clMaroon
        Style.Font.Height = -16
        Style.Font.Name = 'Tahoma'
        Style.Font.Style = []
        Style.LookAndFeel.NativeStyle = False
        Style.IsFontAssigned = True
        StyleDisabled.LookAndFeel.NativeStyle = False
        StyleFocused.LookAndFeel.NativeStyle = False
        StyleHot.LookAndFeel.NativeStyle = False
        TabOrder = 0
        Height = 60
        Width = 966
      end
    end
    object Panel5: TPanel
      Left = 2
      Top = 160
      Width = 972
      Height = 35
      Align = alTop
      BevelOuter = bvNone
      ParentColor = True
      TabOrder = 2
      object JBBTProgressBar: TcxProgressBar
        AlignWithMargins = True
        Left = 1
        Top = 1
        Margins.Left = 1
        Margins.Top = 1
        Margins.Right = 1
        Margins.Bottom = 1
        Align = alClient
        ParentColor = False
        Properties.BarStyle = cxbsGradientLEDs
        Style.Color = clWhite
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 0
        Width = 970
      end
    end
  end
  object BTExitBTN: TcxButton
    Left = 424
    Top = 571
    Width = 220
    Height = 49
    Caption = #36864#20986#29983#25104#34917#36148
    LookAndFeel.NativeStyle = True
    TabOrder = 3
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMenuHighlight
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    OnClick = BTExitBTNClick
  end
  object Panel6: TPanel
    AlignWithMargins = True
    Left = 0
    Top = 283
    Width = 982
    Height = 41
    Margins.Left = 0
    Margins.Right = 0
    Align = alTop
    BevelOuter = bvNone
    Caption = #35831#36873#25321#24744#38656#35201#30340#34917#36148#29983#25104#27169#24335#36827#34892#34917#36148#29983#25104#65281
    Color = clTeal
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 4
  end
  object BTZWADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 112
    Top = 520
  end
  object CSBTADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 224
    Top = 520
  end
  object CSBTinBaseADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 224
    Top = 576
  end
  object JBBTADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 360
    Top = 520
  end
  object JBBTinBaseADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 360
    Top = 576
  end
end
