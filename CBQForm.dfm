object CBQFrm: TCBQFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #39184#21035#26126#32454#26597#35810#26465#20214
  ClientHeight = 130
  ClientWidth = 637
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
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
    Height = 124
    Width = 631
    object cxLabel4: TcxLabel
      Left = 13
      Top = 16
      Caption = #36215#22987#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object CBBeginDateEdit: TcxDateEdit
      Left = 90
      Top = 15
      TabOrder = 1
      OnKeyPress = CBEndDateEditKeyPress
      Width = 121
    end
    object cxLabel3: TcxLabel
      Left = 225
      Top = 16
      Caption = #25130#27490#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object CBEndDateEdit: TcxDateEdit
      Left = 302
      Top = 15
      TabOrder = 3
      OnKeyPress = CBEndDateEditKeyPress
      Width = 121
    end
    object QueryBTN: TcxButton
      Left = 282
      Top = 90
      Width = 75
      Height = 25
      Caption = #26597'   '#35810
      Enabled = False
      LookAndFeel.NativeStyle = True
      TabOrder = 4
      OnClick = QueryBTNClick
    end
    object CBCTComboBox: TcxComboBox
      Left = 497
      Top = 15
      TabOrder = 5
      OnKeyPress = CBEndDateEditKeyPress
      Width = 121
    end
    object cxLabel5: TcxLabel
      Left = 438
      Top = 16
      Caption = #39184'   '#21381':'
      ParentColor = False
      Style.Color = clCream
    end
    object Panel1: TPanel
      Left = 13
      Top = 52
      Width = 605
      Height = 1
      TabOrder = 7
    end
    object CheckBox1: TCheckBox
      Left = 53
      Top = 67
      Width = 97
      Height = 17
      Caption = ' '#26089'  '#39184
      Checked = True
      State = cbChecked
      TabOrder = 8
    end
    object CheckBox2: TCheckBox
      Left = 207
      Top = 67
      Width = 97
      Height = 17
      Caption = ' '#21320'  '#39184
      Checked = True
      State = cbChecked
      TabOrder = 9
    end
    object CheckBox3: TCheckBox
      Left = 361
      Top = 67
      Width = 97
      Height = 17
      Caption = ' '#26202'  '#39184
      Checked = True
      State = cbChecked
      TabOrder = 10
    end
    object CheckBox4: TCheckBox
      Left = 515
      Top = 67
      Width = 97
      Height = 17
      Caption = ' '#22812'  '#23477
      Checked = True
      State = cbChecked
      TabOrder = 11
    end
  end
  object CBADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 136
    Top = 72
  end
end
