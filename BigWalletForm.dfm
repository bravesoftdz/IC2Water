object BigWalletFrm: TBigWalletFrm
  Left = 0
  Top = 0
  Caption = 'BigWalletFrm'
  ClientHeight = 578
  ClientWidth = 781
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
  object cxGroupBox1: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Align = alTop
    Caption = #22823#38065#21253#20805#20540
    TabOrder = 0
    Height = 110
    Width = 775
    object Label1: TLabel
      Left = 24
      Top = 32
      Width = 45
      Height = 16
      Caption = #21345#21495#65306
    end
    object Label2: TLabel
      Left = 264
      Top = 32
      Width = 45
      Height = 16
      Caption = #32534#21495#65306
    end
    object Label3: TLabel
      Left = 24
      Top = 72
      Width = 45
      Height = 16
      Caption = #23494#30721#65306
    end
    object Label4: TLabel
      Left = 235
      Top = 72
      Width = 75
      Height = 16
      Caption = #30830#35748#23494#30721#65306
    end
    object Label5: TLabel
      Left = 500
      Top = 32
      Width = 75
      Height = 16
      Caption = #20805#20540#37329#39069#65306
    end
    object cxTextEdit1: TcxTextEdit
      Left = 67
      Top = 29
      TabOrder = 0
      OnKeyPress = cxTextEdit1KeyPress
      Width = 158
    end
    object cxTextEdit2: TcxTextEdit
      Left = 307
      Top = 29
      TabOrder = 1
      OnKeyPress = cxTextEdit1KeyPress
      Width = 158
    end
    object cxTextEdit3: TcxTextEdit
      Left = 67
      Top = 69
      Enabled = False
      Properties.EchoMode = eemPassword
      Properties.MaxLength = 6
      TabOrder = 2
      Width = 158
    end
    object cxTextEdit4: TcxTextEdit
      Left = 307
      Top = 69
      Enabled = False
      Properties.EchoMode = eemPassword
      Properties.MaxLength = 6
      TabOrder = 3
      Width = 158
    end
    object cxTextEdit5: TcxTextEdit
      Left = 572
      Top = 29
      TabOrder = 4
      OnKeyPress = cxTextEdit1KeyPress
      Width = 158
    end
    object cxButton2: TcxButton
      Left = 604
      Top = 68
      Width = 75
      Height = 25
      Caption = #20805'   '#20540
      LookAndFeel.NativeStyle = True
      TabOrder = 5
      OnClick = cxButton2Click
    end
    object cxButton3: TcxButton
      Left = 502
      Top = 68
      Width = 75
      Height = 25
      Caption = #35774#32622#23494#30721
      Enabled = False
      LookAndFeel.NativeStyle = True
      TabOrder = 6
      OnClick = cxButton3Click
    end
  end
  object cxGroupBox3: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 119
    Align = alTop
    Caption = #22823#38065#21253#36716#23384
    TabOrder = 1
    Height = 106
    Width = 775
    object Label6: TLabel
      Left = 24
      Top = 32
      Width = 45
      Height = 16
      Caption = #21345#21495#65306
    end
    object Label7: TLabel
      Left = 264
      Top = 32
      Width = 45
      Height = 16
      Caption = #32534#21495#65306
    end
    object Label8: TLabel
      Left = 235
      Top = 72
      Width = 75
      Height = 16
      Caption = #36716#23384#37329#39069#65306
    end
    object Label9: TLabel
      Left = 24
      Top = 72
      Width = 45
      Height = 16
      Caption = #23494#30721#65306
    end
    object cxTextEdit6: TcxTextEdit
      Left = 67
      Top = 29
      Properties.ReadOnly = True
      TabOrder = 0
      OnKeyPress = cxTextEdit1KeyPress
      Width = 158
    end
    object cxTextEdit7: TcxTextEdit
      Left = 307
      Top = 29
      Properties.ReadOnly = True
      TabOrder = 1
      OnKeyPress = cxTextEdit1KeyPress
      Width = 158
    end
    object cxTextEdit8: TcxTextEdit
      Left = 307
      Top = 69
      Enabled = False
      TabOrder = 2
      OnKeyPress = cxTextEdit1KeyPress
      Width = 158
    end
    object cxTextEdit9: TcxTextEdit
      Left = 67
      Top = 69
      Enabled = False
      Properties.EchoMode = eemPassword
      TabOrder = 3
      Width = 158
    end
    object cxButton4: TcxButton
      Left = 604
      Top = 68
      Width = 75
      Height = 25
      Caption = #36716'   '#23384
      Enabled = False
      LookAndFeel.NativeStyle = True
      TabOrder = 4
      OnClick = cxButton4Click
    end
    object cxButton5: TcxButton
      Left = 502
      Top = 68
      Width = 75
      Height = 25
      Caption = #35835'   '#21345
      LookAndFeel.NativeStyle = True
      TabOrder = 5
      OnClick = cxButton5Click
    end
  end
  object cxButton1: TcxButton
    Left = 607
    Top = 233
    Width = 75
    Height = 25
    Caption = #36864'   '#20986
    LookAndFeel.NativeStyle = True
    TabOrder = 2
    OnClick = cxButton1Click
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 480
    Top = 320
  end
end
