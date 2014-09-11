object GoonPWForm: TGoonPWForm
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = #32487#32493#20351#29992#23494#30721'/'#24320#25918#20351#29992#23494#30721#36755#20837
  ClientHeight = 248
  ClientWidth = 531
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
    Left = 21
    Top = 61
    Width = 95
    Height = 16
    Caption = #32487#32493#20351#29992#23494#30721':'
  end
  object Label2: TLabel
    Left = 21
    Top = 160
    Width = 95
    Height = 16
    Caption = #32487#32493#20351#29992#23494#30721':'
  end
  object Edit1: TEdit
    Left = 141
    Top = 58
    Width = 233
    Height = 24
    MaxLength = 12
    PasswordChar = '*'
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 531
    Height = 41
    Align = alTop
    Caption = #35831#36755#20837'12'#20301#30340#32487#32493#20351#29992#23494#30721#65292#24310#26399#20351#29992#19968#20010#26376#65281
    Color = clFuchsia
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 1
  end
  object Button1: TButton
    Left = 402
    Top = 57
    Width = 103
    Height = 25
    Caption = #30830'   '#23450
    TabOrder = 2
    OnClick = Button1Click
  end
  object Panel2: TPanel
    Left = 0
    Top = 96
    Width = 531
    Height = 41
    Caption = #35831#36755#20837'12'#20301#30340#24320#25918#20351#29992#23494#30721#65292#33719#21462#36719#20214#20351#29992#26435#65281
    Color = clInactiveCaption
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 3
  end
  object Edit2: TEdit
    Left = 141
    Top = 157
    Width = 233
    Height = 24
    MaxLength = 12
    PasswordChar = '*'
    TabOrder = 4
  end
  object Button2: TButton
    Left = 402
    Top = 156
    Width = 103
    Height = 25
    Caption = #30830'   '#23450
    TabOrder = 5
    OnClick = Button2Click
  end
  object Panel3: TPanel
    Left = 0
    Top = 197
    Width = 531
    Height = 2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object Button3: TButton
    Left = 198
    Top = 210
    Width = 121
    Height = 25
    Caption = #21462'   '#28040
    TabOrder = 7
    OnClick = Button3Click
  end
end
