object ConfirmDataFrm: TConfirmDataFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #35831#36755#20837#36229#32423#26435#38480#23494#30721
  ClientHeight = 93
  ClientWidth = 651
  Color = 9033902
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 52
    Top = 20
    Width = 182
    Height = 25
    Caption = #36229#32423#26435#38480#23494#30721#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -25
    Font.Name = #40657#20307
    Font.Style = []
    ParentFont = False
  end
  object cxTextEdit1: TcxTextEdit
    Left = 224
    Top = 16
    AutoSize = False
    Properties.EchoMode = eemPassword
    Properties.MaxLength = 12
    Properties.PasswordChar = '*'
    TabOrder = 0
    OnKeyPress = cxTextEdit1KeyPress
    Height = 30
    Width = 365
  end
  object cxButton1: TcxButton
    Left = 192
    Top = 57
    Width = 75
    Height = 25
    Caption = #30830'   '#23450
    LookAndFeel.NativeStyle = True
    TabOrder = 1
    OnClick = cxButton1Click
  end
  object cxButton3: TcxButton
    Left = 384
    Top = 57
    Width = 75
    Height = 25
    Caption = #21462'   '#28040
    LookAndFeel.NativeStyle = True
    TabOrder = 2
    OnClick = cxButton3Click
  end
end
