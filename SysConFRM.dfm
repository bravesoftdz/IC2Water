object SystemConfigFRM: TSystemConfigFRM
  Left = 0
  Top = 0
  Caption = #31995#32479#21442#25968#35774#32622
  ClientHeight = 778
  ClientWidth = 878
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clMenuHighlight
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object Panel1: TPanel
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 381
    Height = 772
    Align = alClient
    Anchors = [akLeft]
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 0
    object cxGroupBox1: TcxGroupBox
      Left = 0
      Top = 0
      Align = alTop
      Caption = #21333#20301#21517#31216#23494#30721
      TabOrder = 0
      Height = 215
      Width = 381
      object TECancelCardDeposit: TcxTextEdit
        Left = 85
        Top = 84
        Properties.MaxLength = 2
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 0
        OnKeyDown = TEUsingSectorKeyDown
        OnKeyPress = TECancelCardDepositKeyPress
        Width = 200
      end
      object cxLabel11: TcxLabel
        Left = 15
        Top = 88
        Caption = #36864#21345#25104#26412
      end
      object cxLabel12: TcxLabel
        Left = 15
        Top = 57
        Caption = #26032#21345#25104#26412
      end
      object TEDeliverCardDeposit: TcxTextEdit
        Left = 85
        Top = 53
        Properties.MaxLength = 2
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 3
        OnKeyDown = TEUsingSectorKeyDown
        OnKeyPress = TEDeliverCardDepositKeyPress
        Width = 200
      end
      object TEUnitName: TcxTextEdit
        Left = 85
        Top = 21
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 4
        OnKeyDown = TEUsingSectorKeyDown
        Width = 200
      end
      object TEUnitPassword: TcxTextEdit
        Left = 85
        Top = 229
        Enabled = False
        Properties.EchoMode = eemPassword
        Properties.MaxLength = 4
        Properties.PasswordChar = #9679
        Properties.ReadOnly = True
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 5
        Visible = False
        OnExit = TEUnitPasswordExit
        OnKeyDown = TEUsingSectorKeyDown
        OnKeyPress = TEUnitPasswordKeyPress
        Width = 200
      end
      object cxLabel13: TcxLabel
        Left = 15
        Top = 233
        Caption = #21333#20301#23494#30721
        Enabled = False
        Visible = False
      end
      object cxLabel14: TcxLabel
        Left = 15
        Top = 25
        Caption = #21333#20301#21517#31216
      end
      object BTUnitName: TcxButton
        Left = 294
        Top = 20
        Width = 75
        Height = 25
        Caption = #35774'   '#32622
        Colors.Normal = clBtnFace
        Colors.Pressed = clBlack
        LookAndFeel.NativeStyle = True
        TabOrder = 8
        OnClick = BTUnitNameClick
      end
      object TBUnitPassword: TcxButton
        Left = 294
        Top = 228
        Width = 75
        Height = 25
        Caption = #20462'   '#25913
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 9
        Visible = False
        OnClick = TBUnitPasswordClick
      end
      object TBDeliverCardDeposit: TcxButton
        Left = 294
        Top = 52
        Width = 75
        Height = 25
        Caption = #35774'   '#32622
        LookAndFeel.NativeStyle = True
        TabOrder = 10
        OnClick = TBDeliverCardDepositClick
      end
      object TBCancelCardDeposit: TcxButton
        Left = 294
        Top = 83
        Width = 75
        Height = 25
        Caption = #35774'   '#32622
        LookAndFeel.NativeStyle = True
        TabOrder = 11
        OnClick = TBCancelCardDepositClick
      end
      object cxLabel6: TcxLabel
        Left = 15
        Top = 119
        Caption = #21345#29255#23494#30721
      end
      object TECardPassword: TcxTextEdit
        Left = 85
        Top = 115
        Properties.EchoMode = eemPassword
        Properties.MaxLength = 12
        Properties.PasswordChar = #9679
        Properties.ReadOnly = True
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 13
        OnExit = TECardPasswordExit
        OnKeyDown = TECardPasswordKeyDown
        OnKeyPress = TECardPasswordKeyPress
        Width = 200
      end
      object TBCardPassWord: TcxButton
        Left = 294
        Top = 114
        Width = 75
        Height = 25
        Caption = #20462'   '#25913
        LookAndFeel.NativeStyle = True
        TabOrder = 14
        OnClick = TBCardPassWordClick
      end
      object cxLabel7: TcxLabel
        Left = 15
        Top = 151
        Caption = #23494#30721#29256#26412
      end
      object TEPasswordEdtion: TcxTextEdit
        Left = 85
        Top = 147
        Properties.MaxLength = 2
        Properties.PasswordChar = #9679
        Properties.ReadOnly = False
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 16
        OnExit = TEPasswordEdtionExit
        OnKeyDown = TEPasswordEdtionKeyDown
        OnKeyPress = TEPasswordEdtionKeyPress
        Width = 200
      end
      object TBPasswordEdtion: TcxButton
        Left = 294
        Top = 146
        Width = 75
        Height = 25
        Caption = #35774'   '#32622
        LookAndFeel.NativeStyle = True
        TabOrder = 17
        OnClick = TBPasswordEdtionClick
      end
      object cxLabel8: TcxLabel
        Left = 15
        Top = 259
        Caption = #31995#32479#21517#31216
        Enabled = False
        Visible = False
      end
      object SystemNameBTN: TcxButton
        Left = 294
        Top = 255
        Width = 75
        Height = 25
        Caption = #35774'   '#32622
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 19
        Visible = False
        OnClick = SystemNameBTNClick
      end
      object SystemNameTextEdit: TcxTextEdit
        Left = 85
        Top = 255
        Enabled = False
        Properties.MaxLength = 20
        Properties.ReadOnly = True
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 20
        Text = 'IC'#21345#25910#36153#31649#29702#31995#32479
        Visible = False
        OnExit = TEPasswordEdtionExit
        Width = 200
      end
      object cxLabel16: TcxLabel
        Left = 15
        Top = 183
        Caption = #20351#29992#25159#21306
      end
      object TEUsingSector: TcxTextEdit
        Left = 85
        Top = 179
        Properties.MaxLength = 2
        Properties.ReadOnly = False
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 22
        OnExit = TEUsingSectorExit
        OnKeyDown = TEUsingSectorKeyDown
        OnKeyPress = TEUsingSectorKeyPress
        Width = 200
      end
      object TBUsingSector: TcxButton
        Left = 294
        Top = 178
        Width = 75
        Height = 25
        Caption = #35774'   '#32622
        LookAndFeel.NativeStyle = True
        TabOrder = 23
        OnClick = TBUsingSectorClick
      end
    end
    object cxGroupBox3: TcxGroupBox
      Left = 0
      Top = 622
      Align = alClient
      Caption = #21442#25968#35774#23450#35268#21017
      TabOrder = 1
      Height = 150
      Width = 381
      object cxMemo1: TcxMemo
        AlignWithMargins = True
        Left = 6
        Top = 21
        Margins.Left = 4
        Margins.Top = 0
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        Lines.Strings = (
          '1'#12289#21482#26377#31995#32479#31649#29702#21592#25165#33021#20351#29992#31995#32479#35774#32622#30340#25152#26377#21151#33021#12290
          '2'#12289#22914#26080#29305#27530#38656#35201#65292#35831#19981#35201#25913#21464#21345#29255#23494#30721#19982#23494#30721#29256#26412#12290
          '3'#12289#21345#29255#23494#30721#24517#39035#20026'12'#20301#65292#23383#31526#38598#20026#65306'0-9'#65292'a-f'#65292'A-F'#12290
          '4'#12289#23494#30721#29256#26412#24517#39035#23567#20110#20004#20301#65292#23383#31526#38598#20026#65306'0-9'#12290
          '5'#12289#24517#39035#35774#32622#21457#21345#25276#37329#19982#36864#21345#25276#37329#12290)
        Style.BorderColor = clBlack
        TabOrder = 0
        Height = 123
        Width = 369
      end
    end
    object cxGroupBox4: TcxGroupBox
      AlignWithMargins = True
      Left = 0
      Top = 218
      Margins.Left = 0
      Margins.Right = 0
      Margins.Bottom = 0
      Align = alTop
      Caption = #25910#36153#36153#29575
      TabOrder = 2
      Height = 404
      Width = 381
      object Panel4: TPanel
        Left = 2
        Top = 364
        Width = 377
        Height = 38
        Align = alBottom
        BevelOuter = bvNone
        Color = clWhite
        ParentBackground = False
        TabOrder = 0
        object cxButton8: TcxButton
          Left = 7
          Top = 7
          Width = 75
          Height = 25
          Caption = #36864'   '#20986
          LookAndFeel.NativeStyle = True
          TabOrder = 0
          OnClick = cxButton8Click
        end
      end
      object FLGrid: TcxGrid
        AlignWithMargins = True
        Left = 10
        Top = 21
        Width = 361
        Height = 340
        Margins.Left = 8
        Margins.Top = 0
        Margins.Right = 8
        Align = alClient
        TabOrder = 1
        object FLGridTV: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.DataSource = DataSource1
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          Styles.StyleSheet = GridTableViewStyleSheetDevExpress
          object FLGridTVDM: TcxGridDBColumn
            Caption = #20195#30721
            DataBinding.FieldName = 'DM'
            Options.Editing = False
            Options.Filtering = False
          end
          object FLGridTVFL: TcxGridDBColumn
            Caption = #36153#29575
            DataBinding.FieldName = 'FL'
            Options.Editing = False
            Options.Filtering = False
          end
        end
        object FLGridLL: TcxGridLevel
          GridView = FLGridTV
        end
      end
    end
  end
  object Panel2: TPanel
    AlignWithMargins = True
    Left = 390
    Top = 3
    Width = 485
    Height = 772
    Align = alRight
    Anchors = [akLeft, akRight]
    BevelOuter = bvNone
    Color = clWhite
    ParentBackground = False
    TabOrder = 1
    object Label23: TLabel
      Left = 256
      Top = 480
      Width = 4
      Height = 16
    end
    object cxGroupBox5: TcxGroupBox
      Left = 0
      Top = 0
      Align = alTop
      Caption = #20998#39184#27425#35774#23450
      TabOrder = 0
      Visible = False
      Height = 513
      Width = 485
      object GroupBox2: TGroupBox
        AlignWithMargins = True
        Left = 5
        Top = 21
        Width = 475
        Height = 487
        Margins.Top = 0
        Align = alClient
        TabOrder = 0
        OnExit = cxTextEdit1Exit
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
          Left = 216
          Top = 25
          Width = 105
          Height = 16
          Caption = #20013#39184#24320#22987#26102#38388#65306
        end
        object Label4: TLabel
          Left = 216
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
          Left = 216
          Top = 86
          Width = 105
          Height = 16
          Caption = #22812#23477#24320#22987#26102#38388#65306
        end
        object Label8: TLabel
          Left = 216
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
          Caption = #26089#39184#19968#28040#36153#65306
        end
        object Label10: TLabel
          Left = 10
          Top = 204
          Width = 90
          Height = 16
          Caption = #26089#39184#20108#28040#36153#65306
        end
        object Label11: TLabel
          Left = 10
          Top = 241
          Width = 90
          Height = 16
          Caption = #20013#39184#19968#28040#36153#65306
        end
        object Label12: TLabel
          Left = 10
          Top = 267
          Width = 90
          Height = 16
          Caption = #20013#39184#20108#28040#36153#65306
        end
        object Label13: TLabel
          Left = 10
          Top = 303
          Width = 90
          Height = 16
          Caption = #26202#39184#19968#28040#36153#65306
        end
        object Label14: TLabel
          Left = 10
          Top = 329
          Width = 90
          Height = 16
          Caption = #26202#39184#20108#28040#36153#65306
        end
        object Label15: TLabel
          Left = 10
          Top = 366
          Width = 90
          Height = 16
          Caption = #22812#23477#19968#28040#36153#65306
        end
        object Label16: TLabel
          Left = 10
          Top = 392
          Width = 90
          Height = 16
          Caption = #22812#23477#20108#28040#36153#65306
        end
        object Label17: TLabel
          Left = 112
          Top = 151
          Width = 45
          Height = 16
          Caption = #20998#32452#19968
        end
        object Label18: TLabel
          Left = 192
          Top = 151
          Width = 45
          Height = 16
          Caption = #20998#32452#20108
        end
        object Label19: TLabel
          Left = 272
          Top = 151
          Width = 45
          Height = 16
          Caption = #20998#32452#19977
        end
        object Label20: TLabel
          Left = 352
          Top = 151
          Width = 45
          Height = 16
          Caption = #20998#32452#22235
        end
        object Label24: TLabel
          Left = 10
          Top = 433
          Width = 180
          Height = 16
          Caption = #28040#36153#37329#39069#25353#39184#27425#33258#21160#21464#21270#65306
        end
        object Label25: TLabel
          Left = 25
          Top = 462
          Width = 165
          Height = 16
          Caption = #25353#39184#27425#38480#21046#28040#36153#26102#38388#27573#65306
        end
        object cxTimeEdit1: TcxTimeEdit
          Left = 133
          Top = 21
          EditValue = 0d
          Properties.TimeFormat = tfHourMin
          TabOrder = 0
          Width = 75
        end
        object cxTimeEdit2: TcxTimeEdit
          Left = 133
          Top = 46
          EditValue = 0d
          Properties.TimeFormat = tfHourMin
          TabOrder = 1
          Width = 75
        end
        object cxTimeEdit3: TcxTimeEdit
          Left = 317
          Top = 21
          EditValue = 0d
          Properties.TimeFormat = tfHourMin
          TabOrder = 2
          Width = 75
        end
        object cxTimeEdit4: TcxTimeEdit
          Left = 317
          Top = 46
          EditValue = 0d
          Properties.TimeFormat = tfHourMin
          TabOrder = 3
          Width = 75
        end
        object cxTimeEdit5: TcxTimeEdit
          Left = 133
          Top = 82
          EditValue = 0d
          Properties.TimeFormat = tfHourMin
          TabOrder = 4
          Width = 75
        end
        object cxTimeEdit6: TcxTimeEdit
          Left = 133
          Top = 107
          EditValue = 0d
          Properties.TimeFormat = tfHourMin
          TabOrder = 5
          Width = 75
        end
        object cxTimeEdit7: TcxTimeEdit
          Left = 317
          Top = 80
          EditValue = 0d
          Properties.TimeFormat = tfHourMin
          TabOrder = 6
          Width = 75
        end
        object cxTimeEdit8: TcxTimeEdit
          Left = 317
          Top = 106
          EditValue = 0d
          Properties.TimeFormat = tfHourMin
          TabOrder = 7
          Width = 75
        end
        object cxButton1: TcxButton
          Left = 243
          Top = 455
          Width = 134
          Height = 25
          Caption = #20449#24687#20837#24211
          Enabled = False
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
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit2: TcxTextEdit
          Left = 96
          Top = 201
          Properties.MaxLength = 4
          TabOrder = 10
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit3: TcxTextEdit
          Left = 96
          Top = 238
          Properties.MaxLength = 4
          TabOrder = 11
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit4: TcxTextEdit
          Left = 96
          Top = 264
          Properties.MaxLength = 4
          TabOrder = 12
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit5: TcxTextEdit
          Left = 96
          Top = 300
          Properties.MaxLength = 4
          TabOrder = 13
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit6: TcxTextEdit
          Left = 96
          Top = 326
          Properties.MaxLength = 4
          TabOrder = 14
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit7: TcxTextEdit
          Left = 96
          Top = 363
          Properties.MaxLength = 4
          TabOrder = 15
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit8: TcxTextEdit
          Left = 96
          Top = 389
          Properties.MaxLength = 4
          TabOrder = 16
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object Panel3: TPanel
          Left = 9
          Top = 76
          Width = 410
          Height = 1
          TabOrder = 17
        end
        object Panel6: TPanel
          Left = 10
          Top = 138
          Width = 410
          Height = 1
          TabOrder = 18
        end
        object cxTextEdit9: TcxTextEdit
          Left = 177
          Top = 175
          Properties.MaxLength = 4
          TabOrder = 19
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit10: TcxTextEdit
          Left = 177
          Top = 201
          Properties.MaxLength = 4
          TabOrder = 20
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit11: TcxTextEdit
          Left = 177
          Top = 238
          Properties.MaxLength = 4
          TabOrder = 21
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit12: TcxTextEdit
          Left = 177
          Top = 264
          Properties.MaxLength = 4
          TabOrder = 22
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit13: TcxTextEdit
          Left = 177
          Top = 300
          Properties.MaxLength = 4
          TabOrder = 23
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit14: TcxTextEdit
          Left = 177
          Top = 326
          Properties.MaxLength = 4
          TabOrder = 24
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit15: TcxTextEdit
          Left = 177
          Top = 363
          Properties.MaxLength = 4
          TabOrder = 25
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit16: TcxTextEdit
          Left = 177
          Top = 389
          Properties.MaxLength = 4
          TabOrder = 26
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit17: TcxTextEdit
          Left = 258
          Top = 175
          Properties.MaxLength = 4
          TabOrder = 27
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit18: TcxTextEdit
          Left = 258
          Top = 201
          Properties.MaxLength = 4
          TabOrder = 28
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit19: TcxTextEdit
          Left = 258
          Top = 238
          Properties.MaxLength = 4
          TabOrder = 29
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit20: TcxTextEdit
          Left = 258
          Top = 264
          Properties.MaxLength = 4
          TabOrder = 30
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit21: TcxTextEdit
          Left = 258
          Top = 300
          Properties.MaxLength = 4
          TabOrder = 31
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit22: TcxTextEdit
          Left = 258
          Top = 326
          Properties.MaxLength = 4
          TabOrder = 32
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit23: TcxTextEdit
          Left = 258
          Top = 363
          Properties.MaxLength = 4
          TabOrder = 33
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit24: TcxTextEdit
          Left = 258
          Top = 389
          Properties.MaxLength = 4
          TabOrder = 34
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit25: TcxTextEdit
          Left = 339
          Top = 175
          Properties.MaxLength = 4
          TabOrder = 35
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit26: TcxTextEdit
          Left = 339
          Top = 201
          Properties.MaxLength = 4
          TabOrder = 36
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit27: TcxTextEdit
          Left = 339
          Top = 238
          Properties.MaxLength = 4
          TabOrder = 37
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit28: TcxTextEdit
          Left = 339
          Top = 264
          Properties.MaxLength = 4
          TabOrder = 38
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit29: TcxTextEdit
          Left = 339
          Top = 300
          Properties.MaxLength = 4
          TabOrder = 39
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit30: TcxTextEdit
          Left = 339
          Top = 326
          Properties.MaxLength = 4
          TabOrder = 40
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit31: TcxTextEdit
          Left = 339
          Top = 363
          Properties.MaxLength = 4
          TabOrder = 41
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object cxTextEdit32: TcxTextEdit
          Left = 339
          Top = 389
          Properties.MaxLength = 4
          TabOrder = 42
          OnExit = cxTextEdit1Exit
          OnKeyPress = cxTextEdit1KeyPress
          Width = 75
        end
        object Panel5: TPanel
          Left = 10
          Top = 231
          Width = 410
          Height = 1
          TabOrder = 43
        end
        object Panel7: TPanel
          Left = 9
          Top = 293
          Width = 410
          Height = 1
          TabOrder = 44
        end
        object Panel8: TPanel
          Left = 10
          Top = 355
          Width = 410
          Height = 1
          TabOrder = 45
        end
        object Panel9: TPanel
          Left = 10
          Top = 420
          Width = 410
          Height = 1
          TabOrder = 46
        end
        object CheckBox6: TCheckBox
          Left = 196
          Top = 433
          Width = 17
          Height = 17
          TabOrder = 47
          OnClick = CheckBox6Click
        end
        object CheckBox7: TCheckBox
          Left = 196
          Top = 461
          Width = 17
          Height = 17
          TabOrder = 48
          OnClick = CheckBox7Click
        end
        object cxButton2: TcxButton
          Left = 243
          Top = 426
          Width = 134
          Height = 25
          Caption = #35746#39184#26426#21442#25968#35774#32622
          Enabled = False
          LookAndFeel.NativeStyle = True
          TabOrder = 49
          OnClick = cxButton2Click
        end
      end
    end
    object cxGroupBox2: TcxGroupBox
      AlignWithMargins = True
      Left = 0
      Top = 516
      Margins.Left = 0
      Margins.Right = 0
      Margins.Bottom = 0
      Align = alTop
      Caption = 'POS'#26426#26368#22823#28040#36153#35774#32622
      TabOrder = 1
      Visible = False
      Height = 226
      Width = 485
      object Label22: TLabel
        Left = 15
        Top = 28
        Width = 150
        Height = 16
        Caption = #27599#22825#38480#39069#25353#20998#32452#38480#21046#65306
      end
      object TEDailyMaxConsumption4: TcxTextEdit
        Left = 130
        Top = 153
        Properties.MaxLength = 3
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 0
        OnKeyDown = TEUsingSectorKeyDown
        OnKeyPress = TEDailyMaxConsumption4KeyPress
        Width = 155
      end
      object cxLabel1: TcxLabel
        Left = 15
        Top = 154
        Caption = #20998#32452#22235#27599#22825#38480#39069
      end
      object cxLabel2: TcxLabel
        Left = 15
        Top = 120
        Caption = #20998#32452#19977#27599#22825#38480#39069
      end
      object TEDailyMaxConsumption3: TcxTextEdit
        Left = 130
        Top = 119
        Properties.MaxLength = 3
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 3
        OnKeyDown = TEUsingSectorKeyDown
        OnKeyPress = TEDailyMaxConsumption3KeyPress
        Width = 155
      end
      object TEDailyMaxConsumption2: TcxTextEdit
        Left = 130
        Top = 84
        Properties.MaxLength = 3
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 4
        OnKeyDown = TEUsingSectorKeyDown
        OnKeyPress = TEDailyMaxConsumption2KeyPress
        Width = 155
      end
      object cxLabel3: TcxLabel
        Left = 15
        Top = 86
        Caption = #20998#32452#20108#27599#22825#38480#39069
      end
      object cxLabel4: TcxLabel
        Left = 15
        Top = 52
        Caption = #20998#32452#19968#27599#22825#38480#39069
      end
      object TEDailyMaxConsumption1: TcxTextEdit
        Left = 130
        Top = 50
        Properties.MaxLength = 3
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 7
        OnKeyDown = TEUsingSectorKeyDown
        OnKeyPress = TEDailyMaxConsumption1KeyPress
        Width = 155
      end
      object TEDailyMaxConsumption: TcxTextEdit
        Left = 85
        Top = 237
        Enabled = False
        Properties.MaxLength = 4
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 8
        Visible = False
        OnKeyDown = TEUsingSectorKeyDown
        OnKeyPress = TEDailyMaxConsumptionKeyPress
        Width = 200
      end
      object cxLabel15: TcxLabel
        Left = 15
        Top = 240
        Caption = #27599#22825#38480#39069
        Enabled = False
        Visible = False
      end
      object TBDailyMaxConsumption: TcxButton
        Left = 294
        Top = 236
        Width = 75
        Height = 25
        Caption = #35774'   '#32622
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 10
        Visible = False
        OnClick = TBDailyMaxConsumptionClick
      end
      object cxLabel5: TcxLabel
        Left = 15
        Top = 189
        Caption = #26368#22823#26426#22120#25968
      end
      object TEMaxPosNUM: TcxTextEdit
        Left = 100
        Top = 188
        Properties.MaxLength = 3
        Style.LookAndFeel.NativeStyle = True
        StyleDisabled.LookAndFeel.NativeStyle = True
        StyleFocused.LookAndFeel.NativeStyle = True
        StyleHot.LookAndFeel.NativeStyle = True
        TabOrder = 12
        OnKeyDown = TEUsingSectorKeyDown
        OnKeyPress = TEMaxPosNUMKeyPress
        Width = 185
      end
      object TBMaxPosNUM: TcxButton
        Left = 294
        Top = 188
        Width = 75
        Height = 25
        Caption = #35774'   '#32622
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 13
        OnClick = TBMaxPosNUMClick
      end
      object TBDailyMaxConsumption1: TcxButton
        Left = 294
        Top = 49
        Width = 75
        Height = 25
        Caption = #35774'   '#32622
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 14
        OnClick = TBDailyMaxConsumption1Click
      end
      object TBDailyMaxConsumption2: TcxButton
        Left = 294
        Top = 83
        Width = 75
        Height = 25
        Caption = #35774'   '#32622
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 15
        OnClick = TBDailyMaxConsumption2Click
      end
      object TBDailyMaxConsumption3: TcxButton
        Left = 294
        Top = 118
        Width = 75
        Height = 25
        Caption = #35774'   '#32622
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 16
        OnClick = TBDailyMaxConsumption3Click
      end
      object TBDailyMaxConsumption4: TcxButton
        Left = 294
        Top = 153
        Width = 75
        Height = 25
        Caption = #35774'   '#32622
        Enabled = False
        LookAndFeel.NativeStyle = True
        TabOrder = 17
        OnClick = TBDailyMaxConsumption4Click
      end
      object CheckBox5: TCheckBox
        Left = 171
        Top = 27
        Width = 17
        Height = 17
        TabOrder = 18
        OnClick = CheckBox5Click
      end
      object Panel10: TPanel
        Left = 15
        Top = 307
        Width = 350
        Height = 1
        TabOrder = 19
      end
    end
  end
  object ADOTable1: TADOTable
    Connection = SDIAppForm.ADOConnection1
    CursorType = ctStatic
    TableName = 'SFFL'
    Left = 632
    Top = 664
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 528
    Top = 600
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 528
    Top = 664
    PixelsPerInch = 96
    object cxStyle1: TcxStyle
      AssignedValues = [svColor]
      Color = 15451300
    end
    object cxStyle2: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 16247513
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle3: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 16247513
      TextColor = clBlack
    end
    object cxStyle4: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 16247513
      TextColor = clBlack
    end
    object cxStyle5: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 14811135
      TextColor = clBlack
    end
    object cxStyle6: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 14811135
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clNavy
    end
    object cxStyle7: TcxStyle
      AssignedValues = [svColor]
      Color = 14872561
    end
    object cxStyle8: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 4707838
      TextColor = clBlack
    end
    object cxStyle9: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 12937777
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle10: TcxStyle
      AssignedValues = [svColor]
      Color = 15451300
    end
    object cxStyle11: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 4707838
      TextColor = clBlack
    end
    object cxStyle12: TcxStyle
      AssignedValues = [svColor]
      Color = 15451300
    end
    object cxStyle13: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 14811135
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clNavy
    end
    object cxStyle14: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 12937777
      TextColor = clWhite
    end
    object GridTableViewStyleSheetDevExpress: TcxGridTableViewStyleSheet
      Caption = 'DevExpress'
      Styles.Background = cxStyle1
      Styles.Content = cxStyle2
      Styles.ContentEven = cxStyle3
      Styles.ContentOdd = cxStyle4
      Styles.FilterBox = cxStyle5
      Styles.Inactive = cxStyle10
      Styles.IncSearch = cxStyle11
      Styles.Selection = cxStyle14
      Styles.Footer = cxStyle6
      Styles.Group = cxStyle7
      Styles.GroupByBox = cxStyle8
      Styles.Header = cxStyle9
      Styles.Indicator = cxStyle12
      Styles.Preview = cxStyle13
      BuiltIn = True
    end
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 424
    Top = 600
  end
  object ADOTable2: TADOTable
    Connection = SDIAppForm.ADOConnection1
    CursorType = ctStatic
    TableName = 'SUBMEALINFO'
    Left = 424
    Top = 664
  end
end
