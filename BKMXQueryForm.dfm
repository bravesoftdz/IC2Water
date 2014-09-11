object BKMXQForm: TBKMXQForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #34917#21345#26126#32454#26597#35810
  ClientHeight = 128
  ClientWidth = 469
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
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
    Height = 122
    Width = 463
    object cxLabel4: TcxLabel
      Left = 13
      Top = 18
      Caption = #36215#22987#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object CZBeginDateEdit: TcxDateEdit
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
    object CZEndDateEdit: TcxDateEdit
      Left = 310
      Top = 17
      TabOrder = 3
      Width = 121
    end
    object CZCZYComboBox: TcxComboBox
      Left = 90
      Top = 61
      TabOrder = 4
      Width = 121
    end
    object cxLabel16: TcxLabel
      Left = 28
      Top = 62
      Caption = #25805#20316#21592':'
      ParentColor = False
      Style.Color = clCream
    end
  end
  object QueryBTN: TcxButton
    Left = 267
    Top = 61
    Width = 126
    Height = 25
    Caption = #26597'   '#35810
    LookAndFeel.NativeStyle = True
    TabOrder = 1
    OnClick = QueryBTNClick
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 224
    Top = 72
  end
end
