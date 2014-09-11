object StopConsumeQFrm: TStopConsumeQFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #38271#26399#20572#27490#28040#36153#21345#20449#24687#26597#35810
  ClientHeight = 189
  ClientWidth = 461
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 16
  object RadioGroup1: TRadioGroup
    Left = 64
    Top = 19
    Width = 337
    Height = 105
    Caption = #26597#35810#36873#39033
    Columns = 2
    ItemIndex = 0
    Items.Strings = (
      #19977#20010#26376#19981#28040#36153
      #19977#20010#26376#19981#20805#20540)
    TabOrder = 0
  end
  object Button1: TButton
    Left = 176
    Top = 143
    Width = 75
    Height = 25
    Caption = #26597'   '#35810
    TabOrder = 1
    OnClick = Button1Click
  end
  object CARDADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 40
    Top = 120
  end
end
