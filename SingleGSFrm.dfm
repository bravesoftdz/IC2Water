object SingleGSForm: TSingleGSForm
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = #21333#26465#25346#22833#35760#24405#19979#20256
  ClientHeight = 546
  ClientWidth = 381
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
  object Label1: TLabel
    Left = 84
    Top = 11
    Width = 90
    Height = 16
    Caption = #24453#25346#22833#21345#21495#65306
  end
  object cxTextEdit1: TcxTextEdit
    Left = 173
    Top = 8
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 0
    OnKeyPress = cxTextEdit1KeyPress
    Width = 121
  end
  object GSBTN: TcxButton
    Left = 87
    Top = 513
    Width = 75
    Height = 25
    Caption = #25346'   '#22833
    Enabled = False
    LookAndFeel.NativeStyle = True
    TabOrder = 1
    OnClick = GSBTNClick
  end
  object ExitBTN: TcxButton
    Left = 221
    Top = 513
    Width = 75
    Height = 25
    Caption = #21462'   '#28040
    LookAndFeel.NativeStyle = True
    TabOrder = 2
    OnClick = ExitBTNClick
  end
  object cxListView1: TcxListView
    Left = 16
    Top = 38
    Width = 349
    Height = 465
    Columns = <
      item
        Caption = 'POS'#26426
        Width = 100
      end
      item
        Caption = #25346#22833#29366#24577#26174#31034
        Width = 200
      end>
    ReadOnly = True
    RowSelect = True
    TabOrder = 3
    ViewStyle = vsReport
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 344
    Top = 344
  end
  object ADOInThread: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 264
    Top = 408
  end
end
