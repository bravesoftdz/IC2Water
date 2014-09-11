object ChangeFRM: TChangeFRM
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #25913#21464#31383#21475
  ClientHeight = 183
  ClientWidth = 428
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 92
    Top = 44
    Width = 60
    Height = 16
    Caption = #21407#21517#31216#65306
  end
  object Label2: TLabel
    Left = 77
    Top = 92
    Width = 75
    Height = 16
    Caption = #25913#21464#21517#31216#65306
  end
  object cxTextEdit1: TcxTextEdit
    Left = 157
    Top = 41
    Properties.MaxLength = 32
    Properties.ReadOnly = True
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 0
    Width = 201
  end
  object cxTextEdit2: TcxTextEdit
    Left = 157
    Top = 89
    Properties.MaxLength = 32
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 1
    Width = 201
  end
  object cxButton1: TcxButton
    Left = 96
    Top = 136
    Width = 100
    Height = 25
    Caption = #30830#23450#20462#25913
    LookAndFeel.NativeStyle = True
    TabOrder = 2
  end
  object cxButton2: TcxButton
    Left = 234
    Top = 136
    Width = 100
    Height = 25
    Caption = #21462#28040#20462#25913
    LookAndFeel.NativeStyle = True
    TabOrder = 3
  end
end
