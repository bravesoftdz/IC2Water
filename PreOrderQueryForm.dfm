object PreOrderQFrm: TPreOrderQFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #35746#39184#26126#32454#26597#35810
  ClientHeight = 185
  ClientWidth = 507
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
    Height = 179
    Width = 501
    object cxLabel4: TcxLabel
      Left = 35
      Top = 16
      Caption = #36215#22987#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object POBeginDateEdit: TcxDateEdit
      Left = 112
      Top = 15
      TabOrder = 1
      OnKeyPress = POBeginDateEditKeyPress
      Width = 121
    end
    object cxLabel3: TcxLabel
      Left = 266
      Top = 16
      Caption = #25130#27490#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object POEndDateEdit: TcxDateEdit
      Left = 343
      Top = 15
      TabOrder = 3
      OnKeyPress = POBeginDateEditKeyPress
      Width = 121
    end
    object QueryBTN: TcxButton
      Left = 210
      Top = 139
      Width = 75
      Height = 25
      Caption = #26597'   '#35810
      Enabled = False
      LookAndFeel.NativeStyle = True
      TabOrder = 4
      OnClick = QueryBTNClick
    end
    object POCTComboBox: TcxComboBox
      Left = 343
      Top = 54
      TabOrder = 5
      OnKeyPress = POBeginDateEditKeyPress
      Width = 121
    end
    object cxLabel5: TcxLabel
      Left = 284
      Top = 55
      Caption = #39184'   '#21381':'
      ParentColor = False
      Style.Color = clCream
    end
    object Panel1: TPanel
      Left = 13
      Top = 91
      Width = 476
      Height = 1
      TabOrder = 7
    end
    object CheckBox1: TCheckBox
      Left = 35
      Top = 111
      Width = 97
      Height = 17
      Caption = ' '#26089'  '#39184
      Checked = True
      State = cbChecked
      TabOrder = 8
    end
    object CheckBox2: TCheckBox
      Left = 154
      Top = 111
      Width = 97
      Height = 17
      Caption = ' '#21320'  '#39184
      Checked = True
      State = cbChecked
      TabOrder = 9
    end
    object CheckBox3: TCheckBox
      Left = 280
      Top = 111
      Width = 97
      Height = 17
      Caption = ' '#26202'  '#39184
      Checked = True
      State = cbChecked
      TabOrder = 10
    end
    object CheckBox4: TCheckBox
      Left = 402
      Top = 111
      Width = 97
      Height = 17
      Caption = ' '#22812'  '#23477
      Checked = True
      State = cbChecked
      TabOrder = 11
    end
    object cxLabel1: TcxLabel
      Left = 53
      Top = 53
      Caption = #37096'   '#38376':'
      ParentColor = False
      Style.Color = clCream
    end
    object POBMComboBox: TcxComboBox
      Left = 113
      Top = 52
      TabOrder = 13
      OnKeyPress = POBeginDateEditKeyPress
      Width = 121
    end
  end
  object PreOADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 16
    Top = 64
  end
end
