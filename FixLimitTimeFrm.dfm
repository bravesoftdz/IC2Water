object FixLimitTimeForm: TFixLimitTimeForm
  Left = 0
  Top = 0
  Caption = 'FixLimitTimeForm'
  ClientHeight = 243
  ClientWidth = 527
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
  object UseDateEdit: TcxDateEdit
    Left = 140
    Top = 51
    TabOrder = 0
    Width = 183
  end
  object cxLabel16: TcxLabel
    Left = 46
    Top = 55
    Caption = #21345#38480#21046#26102#38388#65306
  end
  object cxButton1: TcxButton
    Left = 46
    Top = 98
    Width = 75
    Height = 25
    Caption = #35835#21345#26102#38388
    LookAndFeel.NativeStyle = True
    TabOrder = 2
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 148
    Top = 98
    Width = 75
    Height = 25
    Caption = #20462#25913#26102#38388
    Enabled = False
    LookAndFeel.NativeStyle = True
    TabOrder = 3
    OnClick = cxButton2Click
  end
  object cxButton3: TcxButton
    Left = 248
    Top = 98
    Width = 75
    Height = 25
    Caption = #36864'   '#20986
    LookAndFeel.NativeStyle = True
    TabOrder = 4
    OnClick = cxButton3Click
  end
  object ADOCardInfoQuery: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 400
    Top = 96
  end
end
