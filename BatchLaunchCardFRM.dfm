object BatchLaunchCardForm: TBatchLaunchCardForm
  Left = 0
  Top = 0
  ClientHeight = 575
  ClientWidth = 824
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object cxGroupBox1: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Align = alClient
    Alignment = alCenterCenter
    TabOrder = 0
    Height = 285
    Width = 818
    object cxListView1: TcxListView
      AlignWithMargins = True
      Left = 5
      Top = 5
      Width = 808
      Height = 275
      Align = alClient
      Columns = <>
      ParentFont = False
      RowSelect = True
      Style.Color = clSkyBlue
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -16
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.LookAndFeel.NativeStyle = False
      Style.LookAndFeel.SkinName = 'Office2007Pink'
      Style.IsFontAssigned = True
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.SkinName = 'Office2007Pink'
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.SkinName = 'Office2007Pink'
      StyleHot.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.SkinName = 'Office2007Pink'
      TabOrder = 0
      ViewStyle = vsReport
    end
  end
  object cxGroupBox2: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 294
    Align = alBottom
    Alignment = alCenterCenter
    TabOrder = 1
    Height = 40
    Width = 818
    object Panel1: TPanel
      Left = 2
      Top = 2
      Width = 524
      Height = 36
      Align = alClient
      BevelOuter = bvNone
      Caption = #35831#20808#28857#20987'"'#23548#20837#25968#25454'"'#36827#34892#25968#25454#23548#20837'!'
      Color = 8716287
      ParentBackground = False
      TabOrder = 0
    end
    object Panel2: TPanel
      Left = 526
      Top = 2
      Width = 290
      Height = 36
      Align = alRight
      BevelOuter = bvNone
      Color = clPurple
      ParentBackground = False
      TabOrder = 1
      object ImportDataBTN: TcxButton
        Left = 10
        Top = 5
        Width = 85
        Height = 25
        Caption = #23548#20837#25968#25454
        LookAndFeel.NativeStyle = True
        TabOrder = 0
        OnClick = ImportDataBTNClick
      end
      object BatchBTN: TcxButton
        Left = 104
        Top = 5
        Width = 85
        Height = 25
        Caption = #21457'    '#21345
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 1
        OnClick = BatchBTNClick
      end
      object ExitBTN: TcxButton
        Left = 198
        Top = 5
        Width = 85
        Height = 25
        Caption = #36864'    '#20986
        LookAndFeel.NativeStyle = True
        TabOrder = 2
        OnClick = ExitBTNClick
      end
    end
  end
  object cxGroupBox3: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 340
    Align = alBottom
    Alignment = alCenterCenter
    TabOrder = 2
    Height = 232
    Width = 818
    object cxMemo1: TcxMemo
      AlignWithMargins = True
      Left = 5
      Top = 40
      Align = alClient
      Lines.Strings = (
        '***********'#215#215#215#215#215#215#215#215#215#215#215#215#215#215#215#215#215#25209#37327#21457#21345#27880#24847#20107#39033#21450#27969#31243#215#215#215#215#215#215#215#215#215#215#215#215#215
        #215#215#215#215'***********'
        '1'#12289'"'#25209#37327#21457#21345'"'#21151#33021#20197'XLS'#25991#20214#25968#25454#20026#21457#21345#26631#20934#65292#25152#20197#25805#20316#31995#32479#20013#24517#39035#25353#29031'Microsoft office Excel'#12290
        '2'#12289'"'#23548#20837#25968#25454'"'#21151#33021#23558#25171#24320#19968#20010'XLS'#25991#20214#65292#35813#25991#20214#20197#21345#29255#20449#24687#20026#27169#26495#65292#35831#26681#25454#25991#20214#20013#31532#19968#34892#30340#21517#31216#36827#34892#36755#20837#12290
        '3'#12289'"'#23548#20837#25968#25454'"'#35831#20445#35777#25968#25454#30340#23436#25972#65292#21345#21495#19982#32534#21495#31995#32479#23558#33258#21160#29983#25104#65292#26080#38656#20154#24037#36755#20837#12290
        '4'#12289'"'#21457#21345'"'#21151#33021#23558#36830#32493#30340#21457#21345#65292#27599#21457#23436#19968#24352#21345#65292#21457#21345#22120#23558#21457#22768#25253#21578#65292#36825#26102#35831#26356#25442#26032#21345#12290
        '5'#12289#25209#37327#21457#21345#32467#26463#21518#31995#32479#20250#23558#21457#21345#26410#25104#21151#30340#20154#21592#20449#24687#25253#21578#32473#29992#25143#65292#35831#21450#26102#22788#29702#36825#26679#20449#24687#12290
        '6'#12289#23545#20110#25209#37327#21457#21345#26410#25104#21151#30340#20154#21592#20449#24687#35831#21450#26102#35843#25972#65292#20197#28385#36275#21457#21345#26465#20214#12290
        '7'#12289'"'#36864#20986'"'#21151#33021#23558#32467#26463#25209#37327#21457#21345#21151#33021#12290)
      ParentFont = False
      Properties.Alignment = taLeftJustify
      Properties.ReadOnly = True
      Style.Color = clMoneyGreen
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -16
      Style.Font.Name = #24494#36719#38597#40657
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
      TabOrder = 0
      Height = 187
      Width = 808
    end
    object Panel3: TPanel
      Left = 2
      Top = 2
      Width = 814
      Height = 35
      Align = alTop
      BevelOuter = bvNone
      Caption = #36827#34892#25209#37327#21457#21345#21069#65292#35831#20180#32454#38405#35835#20197#19979#12298#25209#37327#21457#21345#27880#24847#20107#39033#21450#27969#31243#12299
      Color = clRed
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = #24494#36719#38597#40657
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 1
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = 'xls|*.xls'
    Left = 376
    Top = 88
  end
end
