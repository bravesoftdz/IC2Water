object SectionInfoFixFROM: TSectionInfoFixFROM
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'SectionInfoFixFROM'
  ClientHeight = 102
  ClientWidth = 219
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object cxLabel1: TcxLabel
    Left = 8
    Top = 8
    Caption = #37096#38376#21517#31216#65306
  end
  object ConfirmSIFBTN: TcxButton
    Left = 19
    Top = 67
    Width = 75
    Height = 25
    Caption = #30830'   '#23450
    TabOrder = 1
    OnClick = ConfirmSIFBTNClick
  end
  object CancelSIFBTN: TcxButton
    Left = 118
    Top = 67
    Width = 75
    Height = 25
    Caption = #21462'   '#28040
    TabOrder = 2
    OnClick = CancelSIFBTNClick
  end
  object SectionInfoFixEdit: TcxTextEdit
    Left = 8
    Top = 34
    TabOrder = 3
    Width = 203
  end
end
