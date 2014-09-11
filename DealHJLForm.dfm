object DealHJLFRM: TDealHJLFRM
  Left = 0
  Top = 0
  Caption = 'DealHJLFRM'
  ClientHeight = 489
  ClientWidth = 625
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
  object cxButton1: TcxButton
    Left = 390
    Top = 304
    Width = 75
    Height = 25
    Caption = #36864'   '#20986
    LookAndFeel.NativeStyle = True
    TabOrder = 0
    OnClick = cxButton1Click
  end
  object cxGroupBox1: TcxGroupBox
    Left = 8
    Top = 8
    Caption = #20805#20540#35748#35777
    ParentBackground = False
    ParentColor = False
    Style.Color = clSkyBlue
    TabOrder = 1
    Height = 195
    Width = 457
    object cxButton2: TcxButton
      Left = 16
      Top = 144
      Width = 425
      Height = 41
      Caption = #35835#21345#35748#35777#20805#20540#37329#39069
      Colors.Default = clRed
      LookAndFeel.NativeStyle = True
      TabOrder = 0
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = cxButton2Click
    end
    object cxMemo1: TcxMemo
      Left = 16
      Top = 19
      TabOrder = 1
      Height = 120
      Width = 425
    end
  end
  object cxGroupBox2: TcxGroupBox
    Left = 8
    Top = 204
    Caption = #22788#29702#28784#35760#24405
    ParentBackground = False
    ParentColor = False
    Style.Color = clMoneyGreen
    TabOrder = 2
    Height = 92
    Width = 457
    object cxProgressBar1: TcxProgressBar
      Left = 16
      Top = 24
      AutoSize = False
      TabOrder = 0
      Height = 30
      Width = 425
    end
    object cxButton3: TcxButton
      Left = 352
      Top = 60
      Width = 89
      Height = 25
      Caption = #22788#29702#28784#35760#24405
      LookAndFeel.NativeStyle = True
      TabOrder = 1
      OnClick = cxButton3Click
    end
  end
  object ADOCardInfoQuery: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 304
    Top = 312
  end
  object DHJLADOQuery: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 304
    Top = 384
  end
  object Query2: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 472
    Top = 424
  end
  object Query1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 376
    Top = 432
  end
  object ADOReChargeQuery: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 432
    Top = 368
  end
end
