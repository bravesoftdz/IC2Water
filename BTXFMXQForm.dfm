object BTFXMXQFrm: TBTFXMXQFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #34917#36148#26126#32454#26597#35810#26465#20214
  ClientHeight = 208
  ClientWidth = 460
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
  object GroupBox1: TGroupBox
    Left = 8
    Top = 84
    Width = 443
    Height = 74
    Caption = #26102#38388#26465#20214
    TabOrder = 0
    object cxLabel3: TcxLabel
      Left = 229
      Top = 31
      Caption = #25130#27490#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object cxLabel4: TcxLabel
      Left = 9
      Top = 31
      Caption = #36215#22987#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object XFBeginDateEdit: TcxDateEdit
      Left = 86
      Top = 27
      TabOrder = 2
      Width = 121
    end
    object XFEndDateEdit: TcxDateEdit
      Left = 306
      Top = 27
      TabOrder = 3
      Width = 121
    end
  end
  object Button1: TButton
    Left = 120
    Top = 170
    Width = 75
    Height = 25
    Caption = #26597'   '#35810
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 271
    Top = 170
    Width = 75
    Height = 25
    Caption = #36864'   '#20986
    TabOrder = 2
    OnClick = Button2Click
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 8
    Width = 444
    Height = 70
    BiDiMode = bdLeftToRight
    Caption = #26597#35810#26465#20214
    Columns = 2
    Items.Strings = (
      #34917#36148#28040#36153#24773#20917#26597#35810
      #34917#36148#21457#25918#24773#20917#26597#35810)
    ParentBiDiMode = False
    TabOrder = 3
  end
  object XFADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 64
    Top = 152
  end
end
