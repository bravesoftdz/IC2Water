object DeleteCardInfoFrom: TDeleteCardInfoFrom
  Left = 0
  Top = 0
  Caption = 'DeleteCardInfoFrom'
  ClientHeight = 425
  ClientWidth = 816
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clHighlight
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object DeleteCardInfoMemo: TcxMemo
    Left = 0
    Top = 0
    Align = alClient
    TabOrder = 0
    Height = 360
    Width = 816
  end
  object Panel1: TPanel
    Left = 0
    Top = 360
    Width = 816
    Height = 65
    Align = alBottom
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 1
    object Label1: TLabel
      Left = 0
      Top = 0
      Width = 816
      Height = 24
      Align = alTop
      Alignment = taCenter
      Caption = #27491#22312#20351#29992#30340#21345#19981#35201#36827#34892#35813#25805#20316#65292#21542#21017#20250#20002#22833#25968#25454#65281
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -24
      Font.Name = #40657#20307
      Font.Style = []
      ParentFont = False
      ExplicitWidth = 528
    end
    object DeleteCardInfoBTN: TcxButton
      Left = 0
      Top = 35
      Width = 75
      Height = 25
      Caption = #28165#21345#20869#23481
      LookAndFeel.NativeStyle = True
      TabOrder = 0
      OnClick = DeleteCardInfoBTNClick
    end
    object ExitDeleteCardInfoBTN: TcxButton
      Left = 82
      Top = 35
      Width = 75
      Height = 25
      Caption = #36864'   '#20986
      LookAndFeel.NativeStyle = True
      TabOrder = 1
      OnClick = ExitDeleteCardInfoBTNClick
    end
  end
end
