object BatchLaunchCardProcessForm: TBatchLaunchCardProcessForm
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = #25209#37327#21457#21345#31383#21475
  ClientHeight = 325
  ClientWidth = 549
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poDesktopCenter
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
    Height = 269
    Width = 543
    object cxLabel1: TcxLabel
      Left = 59
      Top = 100
      Caption = #22995#21517#65306
    end
    object cxLabel2: TcxLabel
      Left = 307
      Top = 141
      Caption = #37096#38376#65306
    end
    object cxLabel3: TcxLabel
      Left = 307
      Top = 100
      Caption = #37329#39069#65306
    end
    object NameTextEdit: TcxTextEdit
      Left = 114
      Top = 99
      Properties.ReadOnly = True
      TabOrder = 3
      Width = 121
    end
    object MoneyTextEdit: TcxTextEdit
      Left = 362
      Top = 99
      Properties.ReadOnly = True
      TabOrder = 4
      Width = 121
    end
    object GroupTextEdit: TcxTextEdit
      Left = 362
      Top = 140
      Properties.ReadOnly = True
      TabOrder = 5
      Width = 121
    end
    object Panel1: TPanel
      Left = 2
      Top = 2
      Width = 539
      Height = 41
      Align = alTop
      BevelOuter = bvNone
      Caption = #24403#21069#21457#21345#22522#26412#20449#24687
      Color = clSkyBlue
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = #24494#36719#38597#40657
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 6
    end
    object cxButton1: TcxButton
      Left = 175
      Top = 223
      Width = 85
      Height = 25
      Caption = #24320#22987#21457#21345
      LookAndFeel.NativeStyle = True
      TabOrder = 7
      OnClick = cxButton1Click
    end
    object cxButton2: TcxButton
      Left = 282
      Top = 223
      Width = 85
      Height = 25
      Caption = #36864'    '#20986
      LookAndFeel.NativeStyle = True
      TabOrder = 8
      OnClick = cxButton2Click
    end
    object cxLabel5: TcxLabel
      Left = 59
      Top = 141
      Caption = #24615#21035#65306
    end
    object ZWTextEdit: TcxTextEdit
      Left = 114
      Top = 140
      Properties.ReadOnly = True
      TabOrder = 10
      Width = 121
    end
    object UseDateEdit: TcxDateEdit
      Left = 362
      Top = 181
      EditValue = 42582d
      TabOrder = 11
      Width = 121
    end
    object cxLabel6: TcxLabel
      Left = 307
      Top = 182
      Caption = #26399#38480#65306
    end
    object ClassTextEdit: TcxTextEdit
      Left = 114
      Top = 181
      Properties.ReadOnly = True
      TabOrder = 13
      Width = 121
    end
    object cxLabel4: TcxLabel
      Left = 59
      Top = 182
      Caption = #29677#21035#65306
    end
    object cxLabel7: TcxLabel
      Left = 59
      Top = 60
      Caption = #21345#21495#65306
    end
    object KHTextEdit: TcxTextEdit
      Left = 114
      Top = 59
      Properties.ReadOnly = True
      TabOrder = 16
      Width = 121
    end
    object cxLabel8: TcxLabel
      Left = 307
      Top = 60
      Caption = #32534#21495#65306
    end
    object BHTextEdit: TcxTextEdit
      Left = 362
      Top = 59
      Properties.ReadOnly = True
      TabOrder = 18
      Width = 121
    end
    object CheckBox1: TCheckBox
      Left = 288
      Top = 184
      Width = 13
      Height = 17
      TabOrder = 19
    end
  end
  object cxGroupBox2: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 278
    Align = alBottom
    Alignment = alCenterCenter
    TabOrder = 1
    Height = 44
    Width = 543
    object Panel2: TPanel
      Left = 2
      Top = 2
      Width = 539
      Height = 40
      Align = alClient
      BevelOuter = bvNone
      Caption = #35831#25918#32622#19968#24352#31354#30333#21345#20110#21457#21345#22120#19978'!'
      Color = clSkyBlue
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -27
      Font.Name = #24188#22278
      Font.Style = [fsBold]
      ParentBackground = False
      ParentFont = False
      TabOrder = 0
    end
  end
  object BLTime: TTimer
    Enabled = False
    OnTimer = BLTimeTimer
    Left = 464
    Top = 224
  end
  object BLCADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 24
    Top = 160
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 488
    Top = 176
  end
  object ADOQuery2: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 496
    Top = 136
  end
end
