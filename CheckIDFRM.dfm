object CheckIDForm: TCheckIDForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = #36229#32423#26435#38480#23494#30721
  ClientHeight = 130
  ClientWidth = 555
  Color = clInactiveCaptionText
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 19
  object Label1: TLabel
    Left = 32
    Top = 35
    Width = 143
    Height = 26
    Caption = #36229#32423#26435#38480#23494#30721':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Impact'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object SuperIDTextEdit: TcxTextEdit
    Left = 192
    Top = 35
    Properties.EchoMode = eemPassword
    Properties.MaxLength = 12
    Properties.PasswordChar = '*'
    TabOrder = 0
    OnKeyPress = SuperIDTextEditKeyPress
    Width = 329
  end
  object cxButton1: TcxButton
    Left = 97
    Top = 88
    Width = 85
    Height = 25
    Caption = #30830'   '#23450
    LookAndFeel.NativeStyle = True
    TabOrder = 1
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 241
    Top = 88
    Width = 85
    Height = 25
    Caption = #21462'   '#28040
    LookAndFeel.NativeStyle = True
    TabOrder = 2
    OnClick = cxButton2Click
  end
  object cxButton3: TcxButton
    Left = 385
    Top = 88
    Width = 120
    Height = 25
    Caption = #20462#25913#36229#32423#23494#30721
    LookAndFeel.NativeStyle = True
    TabOrder = 3
    OnClick = cxButton3Click
  end
end
