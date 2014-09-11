object PreorderdealForm: TPreorderdealForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #35746#39184#21442#25968#35774#23450
  ClientHeight = 304
  ClientWidth = 456
  Color = clCream
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object cxGroupBox5: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Align = alClient
    Caption = #35746#39184#35774#23450
    TabOrder = 0
    Height = 298
    Width = 450
    object GroupBox2: TGroupBox
      AlignWithMargins = True
      Left = 5
      Top = 21
      Width = 440
      Height = 272
      Margins.Top = 0
      Align = alClient
      TabOrder = 0
      object Label1: TLabel
        Left = 32
        Top = 24
        Width = 105
        Height = 16
        Caption = #26089#39184#24320#22987#26102#38388#65306
      end
      object Label2: TLabel
        Left = 32
        Top = 49
        Width = 105
        Height = 16
        Caption = #26089#39184#32467#26463#26102#38388#65306
      end
      object Label3: TLabel
        Left = 227
        Top = 25
        Width = 105
        Height = 16
        Caption = #20013#39184#24320#22987#26102#38388#65306
      end
      object Label4: TLabel
        Left = 227
        Top = 51
        Width = 105
        Height = 16
        Caption = #20013#39184#32467#26463#26102#38388#65306
      end
      object Label5: TLabel
        Left = 32
        Top = 86
        Width = 105
        Height = 16
        Caption = #26202#39184#24320#22987#26102#38388#65306
      end
      object Label6: TLabel
        Left = 32
        Top = 112
        Width = 105
        Height = 16
        Caption = #26202#39184#32467#26463#26102#38388#65306
      end
      object Label7: TLabel
        Left = 227
        Top = 86
        Width = 105
        Height = 16
        Caption = #22812#23477#24320#22987#26102#38388#65306
      end
      object Label8: TLabel
        Left = 227
        Top = 112
        Width = 105
        Height = 16
        Caption = #22812#23477#32467#26463#26102#38388#65306
      end
      object Label9: TLabel
        Left = 10
        Top = 178
        Width = 90
        Height = 16
        Caption = #35746#39184#28040#36153#39069#65306
      end
      object Label10: TLabel
        Left = 10
        Top = 204
        Width = 90
        Height = 16
        Caption = #23454#38469#28040#36153#39069#65306
      end
      object Label17: TLabel
        Left = 116
        Top = 151
        Width = 30
        Height = 16
        Caption = #26089#39184
      end
      object Label18: TLabel
        Left = 196
        Top = 151
        Width = 30
        Height = 16
        Caption = #21320#39184
      end
      object Label19: TLabel
        Left = 279
        Top = 151
        Width = 30
        Height = 16
        Caption = #26202#39184
      end
      object Label20: TLabel
        Left = 359
        Top = 151
        Width = 30
        Height = 16
        Caption = #22812#23477
      end
      object cxTimeEdit1: TcxTimeEdit
        Left = 133
        Top = 21
        EditValue = 0d
        Properties.TimeFormat = tfHour
        TabOrder = 0
        Width = 75
      end
      object cxTimeEdit2: TcxTimeEdit
        Left = 133
        Top = 46
        EditValue = 0d
        Properties.TimeFormat = tfHour
        TabOrder = 1
        Width = 75
      end
      object cxTimeEdit3: TcxTimeEdit
        Left = 328
        Top = 21
        EditValue = 0d
        Properties.TimeFormat = tfHour
        TabOrder = 2
        Width = 75
      end
      object cxTimeEdit4: TcxTimeEdit
        Left = 328
        Top = 46
        EditValue = 0d
        Properties.TimeFormat = tfHour
        TabOrder = 3
        Width = 75
      end
      object cxTimeEdit5: TcxTimeEdit
        Left = 133
        Top = 82
        EditValue = 0d
        Properties.TimeFormat = tfHour
        TabOrder = 4
        Width = 75
      end
      object cxTimeEdit6: TcxTimeEdit
        Left = 133
        Top = 107
        EditValue = 0d
        Properties.TimeFormat = tfHour
        TabOrder = 5
        Width = 75
      end
      object cxTimeEdit7: TcxTimeEdit
        Left = 328
        Top = 80
        EditValue = 0d
        Properties.TimeFormat = tfHour
        TabOrder = 6
        Width = 75
      end
      object cxTimeEdit8: TcxTimeEdit
        Left = 328
        Top = 106
        EditValue = 0d
        Properties.TimeFormat = tfHour
        TabOrder = 7
        Width = 75
      end
      object cxButton1: TcxButton
        Left = 285
        Top = 240
        Width = 134
        Height = 25
        Caption = #20449#24687#20837#24211
        LookAndFeel.NativeStyle = True
        TabOrder = 8
        OnClick = cxButton1Click
      end
      object cxTextEdit1: TcxTextEdit
        Left = 96
        Top = 175
        Properties.MaxLength = 4
        TabOrder = 9
        OnExit = cxTextEdit1Exit
        Width = 75
      end
      object cxTextEdit2: TcxTextEdit
        Left = 96
        Top = 201
        Properties.MaxLength = 4
        TabOrder = 10
        OnExit = cxTextEdit1Exit
        Width = 75
      end
      object Panel3: TPanel
        Left = 9
        Top = 76
        Width = 410
        Height = 1
        TabOrder = 11
      end
      object Panel6: TPanel
        Left = 10
        Top = 138
        Width = 410
        Height = 1
        TabOrder = 12
      end
      object cxTextEdit3: TcxTextEdit
        Left = 177
        Top = 175
        Properties.MaxLength = 4
        TabOrder = 13
        OnExit = cxTextEdit1Exit
        Width = 75
      end
      object cxTextEdit4: TcxTextEdit
        Left = 177
        Top = 201
        Properties.MaxLength = 4
        TabOrder = 14
        OnExit = cxTextEdit1Exit
        Width = 75
      end
      object cxTextEdit5: TcxTextEdit
        Left = 258
        Top = 175
        Properties.MaxLength = 4
        TabOrder = 15
        OnExit = cxTextEdit1Exit
        Width = 75
      end
      object cxTextEdit6: TcxTextEdit
        Left = 258
        Top = 201
        Properties.MaxLength = 4
        TabOrder = 16
        OnExit = cxTextEdit1Exit
        Width = 75
      end
      object cxTextEdit7: TcxTextEdit
        Left = 339
        Top = 175
        Properties.MaxLength = 4
        TabOrder = 17
        OnExit = cxTextEdit1Exit
        Width = 75
      end
      object cxTextEdit8: TcxTextEdit
        Left = 339
        Top = 201
        Properties.MaxLength = 4
        TabOrder = 18
        OnExit = cxTextEdit1Exit
        Width = 75
      end
      object Panel5: TPanel
        Left = 10
        Top = 231
        Width = 410
        Height = 1
        TabOrder = 19
      end
    end
  end
  object ADOTable1: TADOTable
    Connection = SDIAppForm.ADOConnection1
    TableName = 'PreOderMEAlINFO'
    Left = 116
    Top = 251
  end
end
