object CZNoticForm: TCZNoticForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #20805#20540#25552#37266
  ClientHeight = 114
  ClientWidth = 439
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 16
  object cxButton1: TcxButton
    Left = 160
    Top = 72
    Width = 97
    Height = 25
    Caption = #30830'     '#23450
    LookAndFeel.NativeStyle = True
    TabOrder = 0
    OnClick = cxButton1Click
  end
  object Panel1: TPanel
    Left = 8
    Top = 18
    Width = 421
    Height = 41
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -24
    Font.Name = #40657#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
end
