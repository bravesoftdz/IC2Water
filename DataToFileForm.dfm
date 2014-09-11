object DataToFileFrm: TDataToFileFrm
  Left = 0
  Top = 0
  Caption = 'DataToFileFrm'
  ClientHeight = 635
  ClientWidth = 710
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
  object cxGroupBox1: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 95
    Align = alTop
    Caption = #37319#38598#25968#25454#21040#25991#20214
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 0
    Height = 142
    Width = 704
    object Panel1: TPanel
      Left = 2
      Top = 21
      Width = 700
      Height = 84
      Align = alTop
      BevelOuter = bvNone
      Color = clCream
      ParentBackground = False
      TabOrder = 0
      object Label1: TLabel
        Left = 8
        Top = 11
        Width = 105
        Height = 16
        Caption = #25991#20214#23384#20648#36335#24452#65306
      end
      object Label2: TLabel
        Left = 29
        Top = 51
        Width = 84
        Height = 16
        Caption = 'POS'#26426#26426#21495#65306
      end
      object Label3: TLabel
        Left = 279
        Top = 51
        Width = 96
        Height = 16
        Caption = 'POS'#26426'COM'#21475#65306
      end
      object cxButton2: TcxButton
        Left = 538
        Top = 7
        Width = 75
        Height = 25
        Caption = #30830#23450#36335#24452
        LookAndFeel.NativeStyle = True
        TabOrder = 0
        OnClick = cxButton2Click
      end
      object cxTextEdit1: TcxTextEdit
        Left = 111
        Top = 7
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 1
        OnKeyPress = cxTextEdit1KeyPress
        Width = 420
      end
      object cxButton3: TcxButton
        Left = 538
        Top = 46
        Width = 75
        Height = 25
        Caption = #24320#22987#37319#38598
        LookAndFeel.NativeStyle = True
        TabOrder = 2
        OnClick = cxButton3Click
      end
      object cxTextEdit2: TcxTextEdit
        Left = 111
        Top = 47
        Properties.MaxLength = 2
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 3
        OnKeyPress = cxTextEdit2KeyPress
        Width = 160
      end
      object cxTextEdit3: TcxTextEdit
        Left = 371
        Top = 47
        Properties.MaxLength = 2
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 4
        OnKeyPress = cxTextEdit3KeyPress
        Width = 160
      end
    end
    object Panel8: TPanel
      Left = 2
      Top = 105
      Width = 700
      Height = 35
      Align = alClient
      BevelOuter = bvNone
      Color = clCream
      ParentBackground = False
      TabOrder = 1
      object CollectProgressBar: TcxProgressBar
        Left = 0
        Top = 0
        Align = alClient
        Properties.AnimationSpeed = 5
        Properties.BarStyle = cxbsAnimationLEDs
        Properties.BeginColor = 54056
        Properties.BorderWidth = 1
        Properties.Max = 100.000000000000000000
        Properties.ShowTextStyle = cxtsText
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 0
        Width = 700
      end
    end
  end
  object cxGroupBox2: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 243
    Align = alTop
    Caption = #20174#25991#20214#25968#25454#20837#24211
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 1
    Height = 98
    Width = 704
    object Panel2: TPanel
      Left = 2
      Top = 21
      Width = 700
      Height = 40
      Align = alTop
      BevelOuter = bvNone
      Color = clCream
      ParentBackground = False
      TabOrder = 0
      object Label4: TLabel
        Left = 8
        Top = 11
        Width = 105
        Height = 16
        Caption = #25991#20214#23384#20648#36335#24452#65306
      end
      object cxButton4: TcxButton
        Left = 538
        Top = 7
        Width = 75
        Height = 25
        Caption = #25171#24320#25991#20214
        LookAndFeel.NativeStyle = True
        TabOrder = 0
        OnClick = cxButton4Click
      end
      object cxTextEdit4: TcxTextEdit
        Left = 111
        Top = 7
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 1
        OnKeyPress = cxTextEdit4KeyPress
        Width = 420
      end
      object cxButton5: TcxButton
        Left = 619
        Top = 7
        Width = 75
        Height = 25
        Caption = #24320#22987#20837#24211
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 2
        OnClick = cxButton5Click
      end
    end
    object Panel3: TPanel
      Left = 2
      Top = 61
      Width = 700
      Height = 35
      Align = alClient
      BevelOuter = bvNone
      Color = clCream
      ParentBackground = False
      TabOrder = 1
      object cxProgressBar1: TcxProgressBar
        Left = 0
        Top = 0
        Align = alClient
        Properties.AnimationSpeed = 5
        Properties.BarStyle = cxbsAnimationLEDs
        Properties.BeginColor = 54056
        Properties.BorderWidth = 1
        Properties.Max = 100.000000000000000000
        Properties.ShowTextStyle = cxtsText
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 0
        Width = 700
      end
    end
  end
  object Memo1: TMemo
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 704
    Height = 86
    Align = alTop
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = clMoneyGreen
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -16
    Font.Name = #24494#36719#38597#40657
    Font.Style = []
    Lines.Strings = (
      '1'#12289#8220#37319#38598#25968#25454#21040#25991#20214#8221#20027#35201#29992#20110#21333#29420#37319#38598#19968#21488'pos'#26426#65292#37319#38598#30340#25968#25454#19981#20837#24211#24182#20445#23384#21040#25351#23450#30340#25991#20214#12290
      '2'#12289#8220#20174#25991#20214#25968#25454#20837#24211#8221#20027#35201#29992#20110#25226#37319#38598#21040#30340#25968#25454#25991#20214#36827#34892#25968#25454#20837#24211#12290
      '3'#12289#36825#20004#39033#21151#33021#21482#33021#34987#31649#29702#21592#20351#29992#65292#36890#24120#22312'POS'#26426#36827#34892#32500#20462#30340#26102#20505#20351#29992#12290
      '4'#12289#26080#29305#27530#24773#20917#35831#19981#35201#20351#29992#32773#20004#39033#21151#33021#65292#20197#30830#20445#31995#32479#30340#27491#24120#36816#34892#21450#25968#25454#30340#23436#22791#24615#12290
      '5 '#12289#27880#24847#19981#35201#37325#22797#30340#36827#34892#25968#25454#30340#20837#24211#65292#37325#22797#23545#21516#19968#25991#20214#36827#34892#23548#20837#23558#25805#20316#25968#25454#20887#20313#12290)
    ParentFont = False
    TabOrder = 2
    OnKeyPress = Memo1KeyPress
  end
  object cxButton1: TcxButton
    Left = 543
    Top = 371
    Width = 75
    Height = 25
    Caption = #36864'   '#20986
    LookAndFeel.NativeStyle = True
    TabOrder = 3
    OnClick = cxButton1Click
  end
  object OpenDialog1: TOpenDialog
    Filter = 'dbt|*.dbt|bak|*.bak'
    Left = 392
    Top = 376
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 480
    Top = 384
  end
end
