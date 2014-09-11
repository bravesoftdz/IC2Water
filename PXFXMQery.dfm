object PXFXMForm: TPXFXMForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #20010#20154#28040#36153#20449#24687#26597#35810
  ClientHeight = 133
  ClientWidth = 457
  Color = clCream
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
  object cxGroupBox1: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Align = alClient
    Alignment = alCenterCenter
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 0
    Height = 127
    Width = 451
    object cxLabel4: TcxLabel
      Left = 13
      Top = 18
      Caption = #36215#22987#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object XFBeginDateEdit: TcxDateEdit
      Left = 90
      Top = 17
      TabOrder = 1
      Width = 121
    end
    object cxLabel3: TcxLabel
      Left = 233
      Top = 18
      Caption = #25130#27490#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object XFEndDateEdit: TcxDateEdit
      Left = 310
      Top = 17
      TabOrder = 3
      Width = 121
    end
    object cxLabel15: TcxLabel
      Left = 31
      Top = 52
      Caption = #21345'   '#21495':'
      ParentColor = False
      Style.Color = clCream
    end
    object XFKHTextEdit: TcxTextEdit
      Left = 90
      Top = 51
      Properties.MaxLength = 9
      TabOrder = 5
      Width = 121
    end
    object cxLabel16: TcxLabel
      Left = 251
      Top = 52
      Caption = #22995'   '#21517':'
      ParentColor = False
      Style.Color = clCream
    end
    object ReadCardInfoBTN: TcxButton
      Left = 136
      Top = 87
      Width = 75
      Height = 25
      Caption = #35835'  '#21345
      LookAndFeel.NativeStyle = True
      TabOrder = 7
      OnClick = ReadCardInfoBTNClick
    end
    object QueryBTN: TcxButton
      Left = 246
      Top = 87
      Width = 75
      Height = 25
      Caption = #26597'   '#35810
      LookAndFeel.NativeStyle = True
      TabOrder = 8
      OnClick = QueryBTNClick
    end
    object XFXMTextEdit: TcxTextEdit
      Left = 310
      Top = 51
      Properties.MaxLength = 10
      TabOrder = 9
      Width = 121
    end
  end
  object XFADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 56
    Top = 72
  end
end
