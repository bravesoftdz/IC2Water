object FixTitleForm: TFixTitleForm
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = #26631#39064#20869#23481#20462#25913
  ClientHeight = 72
  ClientWidth = 722
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
  object cxTextEdit1: TcxTextEdit
    Left = 8
    Top = 8
    TabOrder = 0
    Width = 706
  end
  object cxButton1: TcxButton
    Left = 227
    Top = 38
    Width = 75
    Height = 25
    Caption = #20462'   '#25913
    LookAndFeel.NativeStyle = True
    TabOrder = 1
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 403
    Top = 38
    Width = 75
    Height = 25
    Caption = #21462'   '#28040
    LookAndFeel.NativeStyle = True
    TabOrder = 2
    OnClick = cxButton2Click
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 544
    Top = 40
  end
end
