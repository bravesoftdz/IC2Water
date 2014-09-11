object qxfpform: Tqxfpform
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #26435#38480#20998#37197
  ClientHeight = 620
  ClientWidth = 786
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
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 786
    Height = 65
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 55
      Top = 24
      Width = 75
      Height = 16
      Caption = #24403#21069#29992#25143#65306
    end
    object Label2: TLabel
      Left = 319
      Top = 24
      Width = 90
      Height = 16
      Caption = #25152#23646#29992#25143#32452#65306
    end
    object Edit1: TEdit
      Left = 136
      Top = 21
      Width = 145
      Height = 24
      ReadOnly = True
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 414
      Top = 21
      Width = 145
      Height = 24
      ReadOnly = True
      TabOrder = 1
    end
    object Button1: TButton
      Left = 593
      Top = 19
      Width = 121
      Height = 25
      Caption = #20998#37197#26435#38480
      TabOrder = 2
      OnClick = Button1Click
    end
  end
  object GroupBox1: TGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 68
    Width = 780
    Height = 549
    Align = alClient
    Caption = #26435#38480#36873#25321
    TabOrder = 1
    object CheckBox1: TCheckBox
      Left = 53
      Top = 40
      Width = 113
      Height = 17
      Caption = #31995#32479#21442#25968#35774#32622
      TabOrder = 0
    end
    object CheckBox2: TCheckBox
      Left = 240
      Top = 40
      Width = 97
      Height = 17
      Caption = #25910#36153#26426#21442#25968
      TabOrder = 1
    end
    object CheckBox3: TCheckBox
      Left = 427
      Top = 40
      Width = 97
      Height = 17
      Caption = #26816#27979#35835#20889#22120
      TabOrder = 2
    end
    object CheckBox4: TCheckBox
      Left = 615
      Top = 40
      Width = 107
      Height = 17
      Caption = #37096#38376#20449#24687#31649#29702
      TabOrder = 3
    end
    object Panel2: TPanel
      Left = 21
      Top = 71
      Width = 740
      Height = 1
      TabOrder = 4
    end
    object CheckBox5: TCheckBox
      Left = 52
      Top = 88
      Width = 113
      Height = 17
      Caption = #21457#34892#26032#21345
      TabOrder = 5
    end
    object CheckBox6: TCheckBox
      Left = 240
      Top = 88
      Width = 97
      Height = 17
      Caption = #21345#29255#20805#20540
      TabOrder = 6
    end
    object CheckBox7: TCheckBox
      Left = 427
      Top = 88
      Width = 97
      Height = 17
      Caption = #21345#29255#21462#27454
      TabOrder = 7
    end
    object CheckBox8: TCheckBox
      Left = 615
      Top = 88
      Width = 107
      Height = 17
      Caption = #26597#35810#21345#29255
      TabOrder = 8
    end
    object CheckBox9: TCheckBox
      Left = 52
      Top = 120
      Width = 132
      Height = 17
      Caption = #20462#25913#21345#38480#21046#26102#38388
      TabOrder = 9
    end
    object CheckBox10: TCheckBox
      Left = 240
      Top = 120
      Width = 97
      Height = 17
      Caption = #25209#37327#21457#21345
      TabOrder = 10
    end
    object CheckBox11: TCheckBox
      Left = 427
      Top = 120
      Width = 97
      Height = 17
      Caption = #27491#24120#36864#21345
      TabOrder = 11
    end
    object CheckBox12: TCheckBox
      Left = 615
      Top = 120
      Width = 107
      Height = 17
      Caption = #28784#35760#24405#22788#29702
      TabOrder = 12
    end
    object Panel3: TPanel
      Left = 21
      Top = 180
      Width = 740
      Height = 1
      TabOrder = 13
    end
    object CheckBox13: TCheckBox
      Left = 52
      Top = 196
      Width = 132
      Height = 17
      Caption = #25209#37327#25968#25454#37319#38598
      TabOrder = 14
    end
    object CheckBox14: TCheckBox
      Left = 240
      Top = 196
      Width = 113
      Height = 17
      Caption = #36873#23450#25209#37327#37319#38598
      TabOrder = 15
    end
    object CheckBox15: TCheckBox
      Left = 427
      Top = 196
      Width = 182
      Height = 17
      Caption = #37319#38598#21040#25991#20214'&'#20174#25991#20214#20837#24211
      TabOrder = 16
    end
    object CheckBox16: TCheckBox
      Left = 615
      Top = 196
      Width = 107
      Height = 17
      Caption = #35823#25910#22788#29702
      TabOrder = 17
    end
    object Panel4: TPanel
      Left = 21
      Top = 227
      Width = 740
      Height = 1
      TabOrder = 18
    end
    object CheckBox17: TCheckBox
      Left = 52
      Top = 241
      Width = 131
      Height = 17
      Caption = #25346#22833#30331#35760#19982#25764#38144
      TabOrder = 19
    end
    object CheckBox18: TCheckBox
      Left = 240
      Top = 241
      Width = 182
      Height = 17
      Caption = #25346#22833#35299#25346#20449#24687#19979#36733
      TabOrder = 20
    end
    object CheckBox19: TCheckBox
      Left = 427
      Top = 241
      Width = 181
      Height = 17
      Caption = #65288#22351#21345#65289#25346#22833#34917#21457#26032#21345
      TabOrder = 21
    end
    object CheckBox20: TCheckBox
      Left = 614
      Top = 241
      Width = 132
      Height = 17
      Caption = #26080#21345#36864#21345
      TabOrder = 22
    end
    object CheckBox21: TCheckBox
      Left = 52
      Top = 275
      Width = 132
      Height = 17
      Caption = #25209#37327#25346#22833#30331#35760
      TabOrder = 23
    end
    object Panel5: TPanel
      Left = 21
      Top = 302
      Width = 740
      Height = 1
      TabOrder = 24
    end
    object CheckBox22: TCheckBox
      Left = 52
      Top = 317
      Width = 146
      Height = 17
      Caption = #29983#25104#34917#36148
      TabOrder = 25
    end
    object CheckBox23: TCheckBox
      Left = 240
      Top = 317
      Width = 132
      Height = 17
      Caption = #19979#20256#34917#36148
      TabOrder = 26
    end
    object Panel6: TPanel
      Left = 21
      Top = 346
      Width = 740
      Height = 1
      TabOrder = 27
    end
    object CheckBox24: TCheckBox
      Left = 52
      Top = 362
      Width = 132
      Height = 17
      Caption = #20805#20540#26126#32454#25253#34920
      TabOrder = 28
    end
    object CheckBox25: TCheckBox
      Left = 239
      Top = 362
      Width = 146
      Height = 17
      Caption = #21462#27454#26126#32454#25253#34920
      TabOrder = 29
    end
    object CheckBox26: TCheckBox
      Left = 426
      Top = 362
      Width = 151
      Height = 17
      Caption = #28040#36153#26126#32454#25253#34920
      TabOrder = 30
    end
    object CheckBox27: TCheckBox
      Left = 614
      Top = 362
      Width = 107
      Height = 17
      Caption = #27700#25511#28040#36153#25253#34920
      TabOrder = 31
    end
    object CheckBox28: TCheckBox
      Left = 52
      Top = 392
      Width = 132
      Height = 17
      Caption = #21345#29255#20449#24687#25253#34920
      TabOrder = 32
    end
    object CheckBox29: TCheckBox
      Left = 239
      Top = 392
      Width = 146
      Height = 17
      Caption = #39184#21035#32479#35745#25253#34920
      TabOrder = 33
    end
    object CheckBox30: TCheckBox
      Left = 426
      Top = 392
      Width = 151
      Height = 17
      Caption = #39184#21381#32479#35745#25253#34920
      TabOrder = 34
    end
    object CheckBox31: TCheckBox
      Left = 614
      Top = 392
      Width = 107
      Height = 17
      Caption = #28040#36153#26426#32479#35745#25253#34920
      TabOrder = 35
    end
    object CheckBox32: TCheckBox
      Left = 52
      Top = 423
      Width = 132
      Height = 17
      Caption = #37096#38376#32479#35745#25253#34920
      TabOrder = 36
    end
    object CheckBox33: TCheckBox
      Left = 239
      Top = 423
      Width = 146
      Height = 17
      Caption = #21345#20313#39069#25253#34920
      TabOrder = 37
    end
    object CheckBox34: TCheckBox
      Left = 426
      Top = 423
      Width = 151
      Height = 17
      Caption = #36864#21345#32479#35745#25253#34920
      TabOrder = 38
    end
    object CheckBox35: TCheckBox
      Left = 614
      Top = 423
      Width = 107
      Height = 17
      Caption = #34917#21345#26126#32454#32479#35745
      TabOrder = 39
    end
    object CheckBox36: TCheckBox
      Left = 52
      Top = 453
      Width = 107
      Height = 17
      Caption = #25346#22833#32479#35745#25253#34920
      TabOrder = 40
    end
    object CheckBox37: TCheckBox
      Left = 239
      Top = 453
      Width = 151
      Height = 17
      Caption = #38750#27491#24120#35760#24405#25253#34920
      TabOrder = 41
    end
    object CheckBox38: TCheckBox
      Left = 426
      Top = 453
      Width = 146
      Height = 17
      Caption = #25910#25903#27719#24635#25253#34920
      TabOrder = 42
    end
    object CheckBox39: TCheckBox
      Left = 614
      Top = 453
      Width = 132
      Height = 17
      Caption = #28040#36153#32479#35745#25253#34920
      TabOrder = 43
    end
    object CheckBox40: TCheckBox
      Left = 52
      Top = 483
      Width = 132
      Height = 17
      Caption = #25805#20316#21592#26085#24535#25253#34920
      TabOrder = 44
    end
    object CheckBox41: TCheckBox
      Left = 239
      Top = 483
      Width = 146
      Height = 17
      Caption = #35823#25910#22788#29702#25253#34920
      TabOrder = 45
    end
    object CheckBox42: TCheckBox
      Left = 426
      Top = 483
      Width = 151
      Height = 17
      Caption = #34917#36148#20449#24687#23548#20986
      TabOrder = 46
    end
    object CheckBox43: TCheckBox
      Left = 614
      Top = 483
      Width = 107
      Height = 17
      Caption = #34917#36148#20351#29992#24773#20917
      TabOrder = 47
    end
    object CheckBox44: TCheckBox
      Left = 52
      Top = 512
      Width = 132
      Height = 17
      Caption = #25805#20316#21592#25910#25903#25253#34920
      TabOrder = 48
    end
    object CheckBox45: TCheckBox
      Left = 52
      Top = 151
      Width = 132
      Height = 17
      Caption = #28165#21345#20869#23481
      TabOrder = 49
    end
    object CheckBox46: TCheckBox
      Left = 240
      Top = 512
      Width = 151
      Height = 17
      Caption = #20010#20154#28040#36153#20449#24687#25253#34920
      TabOrder = 50
    end
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 720
    Top = 80
  end
end
