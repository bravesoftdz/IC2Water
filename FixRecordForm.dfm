object FixRecordFRM: TFixRecordFRM
  Left = 0
  Top = 0
  Caption = 'FixRecordFRM'
  ClientHeight = 461
  ClientWidth = 1034
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
  object GroupBox1: TGroupBox
    Left = 8
    Top = 0
    Width = 817
    Height = 177
    TabOrder = 0
    object Panel1: TPanel
      Left = 2
      Top = 18
      Width = 813
      Height = 57
      Align = alTop
      BevelOuter = bvNone
      Caption = #20462#27491#21069#35831#23558#25968#25454#37319#38598#23436#27605#65292#20462#27491#36807#31243#36739#24930#35831#32784#24515#31561#20505'!'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = #24494#36719#38597#40657
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      ExplicitWidth = 965
    end
    object GroupBox3: TGroupBox
      AlignWithMargins = True
      Left = 5
      Top = 78
      Width = 807
      Height = 87
      Align = alTop
      Caption = #20462#22797#36807#31243#26174#31034
      TabOrder = 1
      ExplicitWidth = 959
      object ProgressBar1: TProgressBar
        Left = 17
        Top = 32
        Width = 568
        Height = 33
        TabOrder = 0
      end
      object Button3: TButton
        Left = 610
        Top = 32
        Width = 80
        Height = 33
        Caption = #24320#22987#20462#22797
        TabOrder = 1
        OnClick = Button3Click
      end
      object Button1: TButton
        Left = 707
        Top = 32
        Width = 80
        Height = 33
        Caption = #36864'   '#20986
        TabOrder = 2
        OnClick = Button1Click
      end
    end
  end
  object XPManifest1: TXPManifest
    Left = 608
    Top = 120
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 616
    Top = 48
  end
  object ADOQuery2: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 512
    Top = 48
  end
  object ADOQuery3: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 368
    Top = 48
  end
end
