object XFTJQFrm: TXFTJQFrm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #28040#36153#32479#35745#26126#32454#26597#35810
  ClientHeight = 668
  ClientWidth = 913
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
  object cxPageControl1: TcxPageControl
    AlignWithMargins = True
    Left = 3
    Top = 99
    Width = 907
    Height = 533
    ActivePage = cxTabSheet1
    Align = alClient
    LookAndFeel.NativeStyle = True
    TabOrder = 0
    ClientRectBottom = 529
    ClientRectLeft = 2
    ClientRectRight = 903
    ClientRectTop = 25
    object cxTabSheet1: TcxTabSheet
      Caption = #28040#36153#32479#35745#65288#20840#37096#65289
      ImageIndex = 0
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object cxGroupBox2: TcxGroupBox
        AlignWithMargins = True
        Left = 0
        Top = 0
        Margins.Left = 0
        Margins.Top = 0
        Margins.Right = 0
        Margins.Bottom = 2
        Align = alClient
        Alignment = alCenterCenter
        TabOrder = 0
        Height = 281
        Width = 901
        object ALLDataGrid: TcxGrid
          AlignWithMargins = True
          Left = 5
          Top = 5
          Width = 891
          Height = 271
          Align = alClient
          TabOrder = 0
          object ALLDataGridDBTV: TcxGridDBTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.DataSource = ALLMXDataSource
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsCustomize.ColumnFiltering = False
            OptionsCustomize.ColumnSorting = False
            OptionsData.CancelOnExit = False
            OptionsData.Deleting = False
            OptionsData.DeletingConfirmation = False
            OptionsData.Editing = False
            OptionsData.Inserting = False
            OptionsSelection.CellSelect = False
            OptionsView.CellAutoHeight = True
            OptionsView.GroupByBox = False
            Styles.StyleSheet = GridTableViewStyleSheetSpruce
            object RQCol: TcxGridDBColumn
              Caption = #26085#26399
              MinWidth = 140
              Width = 140
            end
            object ZECol: TcxGridDBColumn
              Caption = #28040#36153#24635#39069
              MinWidth = 120
              Width = 120
            end
            object ZCSCol: TcxGridDBColumn
              Caption = #24635#27425#25968
              MinWidth = 100
              Width = 100
            end
            object BFZECol: TcxGridDBColumn
              Caption = #26089#39184#37329#39069
              MinWidth = 100
              Width = 100
            end
            object BFZCSCol: TcxGridDBColumn
              Caption = #26089#39184#27425#25968
              MinWidth = 100
              Width = 100
            end
            object LHZECol: TcxGridDBColumn
              Caption = #21320#39184#37329#39069
              MinWidth = 100
              Width = 100
            end
            object LHZCSCol: TcxGridDBColumn
              Caption = #21320#39184#27425#25968
              MinWidth = 100
              Width = 100
            end
            object SRZECol: TcxGridDBColumn
              Caption = #26202#39184#37329#39069
              MinWidth = 100
              Width = 100
            end
            object SRZCSCol: TcxGridDBColumn
              Caption = #26202#39184#27425#25968
              MinWidth = 100
              Width = 100
            end
            object NTZECol: TcxGridDBColumn
              Caption = #22812#23477#37329#39069
              MinWidth = 100
              Width = 100
            end
            object NTZCSCol: TcxGridDBColumn
              Caption = #22812#23477#27425#25968
              MinWidth = 100
              Width = 100
            end
          end
          object ALLDataGridLL: TcxGridLevel
            GridView = ALLDataGridDBTV
          end
        end
      end
      object cxGroupBox3: TcxGroupBox
        AlignWithMargins = True
        Left = 0
        Top = 285
        Margins.Left = 0
        Margins.Top = 2
        Margins.Right = 0
        Margins.Bottom = 2
        Align = alBottom
        Alignment = alCenterCenter
        TabOrder = 1
        Height = 35
        Width = 901
        object ALLMXExportProgressBar: TcxProgressBar
          Left = 2
          Top = 2
          Align = alClient
          Properties.ShowTextStyle = cxtsText
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.Color = clLime
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 0
          ExplicitHeight = 21
          Width = 897
        end
      end
      object cxGroupBox4: TcxGroupBox
        AlignWithMargins = True
        Left = 0
        Top = 469
        Margins.Left = 0
        Margins.Top = 2
        Margins.Right = 0
        Margins.Bottom = 0
        Align = alBottom
        Alignment = alCenterCenter
        TabOrder = 2
        Height = 35
        Width = 901
        object Panel2: TPanel
          Left = 68
          Top = 2
          Width = 831
          Height = 31
          Align = alRight
          BevelOuter = bvNone
          Color = clCream
          ParentBackground = False
          TabOrder = 0
          object ALLMXExportBTN: TcxButton
            Left = 642
            Top = 3
            Width = 75
            Height = 25
            Caption = #23548'   '#20986
            LookAndFeel.NativeStyle = True
            TabOrder = 0
            OnClick = ALLMXExportBTNClick
          end
          object ALLPreviewBTN: TcxButton
            Left = 736
            Top = 3
            Width = 75
            Height = 25
            Caption = #25171#21360#39044#35272
            LookAndFeel.NativeStyle = True
            TabOrder = 1
            OnClick = ALLPreviewBTNClick
          end
        end
      end
      object cxGroupBox5: TcxGroupBox
        Left = 0
        Top = 322
        Align = alBottom
        Alignment = alCenterCenter
        TabOrder = 3
        Height = 35
        Width = 901
        object Panel3: TPanel
          Left = 2
          Top = 2
          Width = 897
          Height = 31
          Align = alClient
          BevelOuter = bvNone
          Caption = #23548#20986#25968#25454#38656#35201'XLS'#36719#20214#25903#25345#65292#35831#30830#35748#31995#32479#20013#23433#35013'XLS'#36719#20214#65292#21542#21017#26080#27861#23436#25104#23548#20986'!'
          Color = 8421631
          ParentBackground = False
          TabOrder = 0
        end
      end
      object cxGroupBox6: TcxGroupBox
        Left = 0
        Top = 357
        Align = alBottom
        Caption = #20449#24687#32479#35745
        TabOrder = 4
        Height = 110
        Width = 901
        object cxGroupBox10: TcxGroupBox
          Left = 182
          Top = 21
          Align = alLeft
          Caption = #26089#39184#32479#35745
          TabOrder = 0
          Height = 87
          Width = 179
          object Label9: TLabel
            Left = 15
            Top = 59
            Width = 30
            Height = 16
            Caption = #27425#25968
          end
          object Label10: TLabel
            Left = 16
            Top = 27
            Width = 30
            Height = 16
            Caption = #37329#39069
          end
          object ABFCSTextEdit: TcxTextEdit
            Left = 51
            Top = 55
            TabOrder = 0
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
          object ABFZETextEdit: TcxTextEdit
            Left = 51
            Top = 23
            TabOrder = 1
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
        end
        object cxGroupBox9: TcxGroupBox
          Left = 361
          Top = 21
          Align = alLeft
          Caption = #21320#39184#32479#35745
          TabOrder = 1
          Height = 87
          Width = 179
          object Label7: TLabel
            Left = 15
            Top = 59
            Width = 30
            Height = 16
            Caption = #27425#25968
          end
          object Label8: TLabel
            Left = 15
            Top = 27
            Width = 30
            Height = 16
            Caption = #37329#39069
          end
          object ALHCSTextEdit: TcxTextEdit
            Left = 51
            Top = 55
            TabOrder = 0
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
          object ALHZETextEdit: TcxTextEdit
            Left = 51
            Top = 23
            TabOrder = 1
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
        end
        object cxGroupBox8: TcxGroupBox
          Left = 540
          Top = 21
          Align = alLeft
          Caption = #26202#39184#32479#35745
          TabOrder = 2
          Height = 87
          Width = 179
          object Label4: TLabel
            Left = 15
            Top = 59
            Width = 30
            Height = 16
            Caption = #27425#25968
          end
          object Label6: TLabel
            Left = 15
            Top = 27
            Width = 30
            Height = 16
            Caption = #37329#39069
          end
          object ASRCSTextEdit: TcxTextEdit
            Left = 51
            Top = 55
            TabOrder = 0
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
          object ASRZETextEdit: TcxTextEdit
            Left = 51
            Top = 23
            TabOrder = 1
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
        end
        object cxGroupBox1: TcxGroupBox
          Left = 719
          Top = 21
          Align = alLeft
          Caption = #22812#23477#32479#35745
          TabOrder = 3
          Height = 87
          Width = 179
          object Label2: TLabel
            Left = 15
            Top = 59
            Width = 30
            Height = 16
            Caption = #27425#25968
          end
          object Label3: TLabel
            Left = 15
            Top = 27
            Width = 30
            Height = 16
            Caption = #37329#39069
          end
          object ANTCSTextEdit: TcxTextEdit
            Left = 51
            Top = 55
            TabOrder = 0
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
          object ANTZETextEdit: TcxTextEdit
            Left = 51
            Top = 23
            TabOrder = 1
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
        end
        object cxGroupBox11: TcxGroupBox
          Left = 2
          Top = 21
          Align = alLeft
          Caption = #24635#21644#32479#35745
          TabOrder = 4
          Height = 87
          Width = 180
          object Label1: TLabel
            Left = 15
            Top = 59
            Width = 30
            Height = 16
            Caption = #27425#25968
          end
          object Label5: TLabel
            Left = 15
            Top = 27
            Width = 30
            Height = 16
            Caption = #37329#39069
          end
          object AZCSTextEdit: TcxTextEdit
            Left = 51
            Top = 55
            TabOrder = 0
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
          object AZZETextEdit: TcxTextEdit
            Left = 51
            Top = 23
            TabOrder = 1
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
        end
      end
    end
    object cxTabSheet2: TcxTabSheet
      Caption = #28040#36153#32479#35745#65288#25353#20010#20154#65289
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object cxGroupBox12: TcxGroupBox
        AlignWithMargins = True
        Left = 0
        Top = 0
        Margins.Left = 0
        Margins.Top = 0
        Margins.Right = 0
        Margins.Bottom = 2
        Align = alClient
        Alignment = alCenterCenter
        TabOrder = 0
        Height = 390
        Width = 901
        object GRDataGrid: TcxGrid
          AlignWithMargins = True
          Left = 5
          Top = 5
          Width = 891
          Height = 380
          Align = alClient
          TabOrder = 0
          object GRDataGridTV: TcxGridDBTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.DataSource = GRDataSource
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsCustomize.ColumnFiltering = False
            OptionsCustomize.ColumnSorting = False
            OptionsData.CancelOnExit = False
            OptionsData.Deleting = False
            OptionsData.DeletingConfirmation = False
            OptionsData.Editing = False
            OptionsData.Inserting = False
            OptionsSelection.CellSelect = False
            OptionsView.CellAutoHeight = True
            OptionsView.ColumnAutoWidth = True
            OptionsView.GroupByBox = False
            Styles.StyleSheet = GridTableViewStyleSheetMaple
            object GRRQCol: TcxGridDBColumn
              Caption = #26085#26399
              MinWidth = 140
            end
            object GRXMCol: TcxGridDBColumn
              Caption = #22995#21517
              MinWidth = 140
            end
            object GRBHCol: TcxGridDBColumn
              Caption = #32534#21495
              MinWidth = 140
            end
            object GRXFCSCol: TcxGridDBColumn
              Caption = #28040#36153#27425#25968
              MinWidth = 140
            end
            object GRXFZECol: TcxGridDBColumn
              Caption = #28040#36153#24635#39069
              MinWidth = 140
            end
            object GRBMCol: TcxGridDBColumn
              Caption = #37096#38376
              MinWidth = 200
            end
          end
          object GRDataGridLL: TcxGridLevel
            GridView = GRDataGridTV
          end
        end
      end
      object cxGroupBox13: TcxGroupBox
        AlignWithMargins = True
        Left = 0
        Top = 394
        Margins.Left = 0
        Margins.Top = 2
        Margins.Right = 0
        Margins.Bottom = 2
        Align = alBottom
        Alignment = alCenterCenter
        TabOrder = 1
        Height = 35
        Width = 901
        object GRProgressBar: TcxProgressBar
          Left = 2
          Top = 2
          Align = alClient
          Properties.ShowTextStyle = cxtsText
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.Color = clLime
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 0
          ExplicitHeight = 21
          Width = 897
        end
      end
      object cxGroupBox14: TcxGroupBox
        AlignWithMargins = True
        Left = 0
        Top = 468
        Margins.Left = 0
        Margins.Top = 2
        Margins.Right = 0
        Margins.Bottom = 0
        Align = alBottom
        Alignment = alCenterCenter
        TabOrder = 2
        Height = 36
        Width = 901
        object Panel4: TPanel
          Left = 68
          Top = 2
          Width = 831
          Height = 32
          Align = alRight
          BevelOuter = bvNone
          Color = clCream
          ParentBackground = False
          TabOrder = 0
          object Label11: TLabel
            Left = 211
            Top = 8
            Width = 75
            Height = 16
            Caption = #24635#28040#36153#27425#25968
          end
          object Label12: TLabel
            Left = 430
            Top = 7
            Width = 60
            Height = 16
            Caption = #28040#36153#24635#39069
          end
          object GRExportBTN: TcxButton
            Left = 644
            Top = 3
            Width = 75
            Height = 25
            Caption = #23548'   '#20986
            LookAndFeel.NativeStyle = True
            TabOrder = 0
            OnClick = GRExportBTNClick
          end
          object GRPreviewBTN: TcxButton
            Left = 738
            Top = 3
            Width = 75
            Height = 25
            Caption = #25171#21360#39044#35272
            LookAndFeel.NativeStyle = True
            TabOrder = 1
            OnClick = GRPreviewBTNClick
          end
          object GRZCSTextEdit: TcxTextEdit
            Left = 293
            Top = 4
            TabOrder = 2
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
          object GRZETextEdit: TcxTextEdit
            Left = 496
            Top = 4
            TabOrder = 3
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
        end
      end
      object cxGroupBox15: TcxGroupBox
        Left = 0
        Top = 431
        Align = alBottom
        Alignment = alCenterCenter
        TabOrder = 3
        Height = 35
        Width = 901
        object Panel5: TPanel
          Left = 2
          Top = 2
          Width = 897
          Height = 31
          Align = alClient
          BevelOuter = bvNone
          Caption = #23548#20986#25968#25454#38656#35201'XLS'#36719#20214#25903#25345#65292#35831#30830#35748#31995#32479#20013#23433#35013'XLS'#36719#20214#65292#21542#21017#26080#27861#23436#25104#23548#20986'!'
          Color = 8421631
          ParentBackground = False
          TabOrder = 0
        end
      end
    end
    object cxTabSheet3: TcxTabSheet
      Caption = #28040#36153#32479#35745#65288#25353#20010#20154#21450#39184#27425#65289
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object cxGroupBox7: TcxGroupBox
        AlignWithMargins = True
        Left = 0
        Top = 0
        Margins.Left = 0
        Margins.Top = 0
        Margins.Right = 0
        Margins.Bottom = 2
        Align = alClient
        Alignment = alCenterCenter
        TabOrder = 0
        Height = 281
        Width = 901
        object CCDataGrid: TcxGrid
          AlignWithMargins = True
          Left = 5
          Top = 5
          Width = 891
          Height = 271
          Align = alClient
          TabOrder = 0
          object CCDataGridTV: TcxGridDBTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.DataSource = CCDataSource
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsCustomize.ColumnFiltering = False
            OptionsCustomize.ColumnSorting = False
            OptionsData.CancelOnExit = False
            OptionsData.Deleting = False
            OptionsData.DeletingConfirmation = False
            OptionsData.Editing = False
            OptionsData.Inserting = False
            OptionsSelection.CellSelect = False
            OptionsView.CellAutoHeight = True
            OptionsView.ColumnAutoWidth = True
            OptionsView.GroupByBox = False
            Styles.StyleSheet = GridTableViewStyleSheetRose
            object CCBHCol: TcxGridDBColumn
              Caption = #32534#21495
              MinWidth = 100
              Width = 131
            end
            object CCXMCol: TcxGridDBColumn
              Caption = #22995#21517
              MinWidth = 100
            end
            object CCKHCol: TcxGridDBColumn
              Caption = #21345#21495
              MinWidth = 100
            end
            object CCZECol: TcxGridDBColumn
              Caption = #28040#36153#24635#39069
              MinWidth = 110
            end
            object CCZCSCol: TcxGridDBColumn
              Caption = #28040#36153#27425#25968
              MinWidth = 90
            end
            object CCBFZECol: TcxGridDBColumn
              Caption = #26089#39184#37329#39069
              MinWidth = 100
            end
            object CCBFCSCol: TcxGridDBColumn
              Caption = #26089#39184#27425#25968
              MinWidth = 80
            end
            object CCLHZECol: TcxGridDBColumn
              Caption = #21320#39184#37329#39069
              MinWidth = 100
            end
            object CCLHCSCol: TcxGridDBColumn
              Caption = #21320#39184#27425#25968
              MinWidth = 80
            end
            object CCSRZECol: TcxGridDBColumn
              Caption = #26202#39184#37329#39069
              MinWidth = 100
            end
            object CCSRCSCol: TcxGridDBColumn
              Caption = #26202#39184#27425#25968
              MinWidth = 80
            end
            object CCNTZECol: TcxGridDBColumn
              Caption = #22812#23477#37329#39069
              MinWidth = 100
            end
            object CCNTCSCol: TcxGridDBColumn
              Caption = #22812#23477#27425#25968
              MinWidth = 80
            end
          end
          object CCDataGridLL: TcxGridLevel
            GridView = CCDataGridTV
          end
        end
      end
      object cxGroupBox17: TcxGroupBox
        AlignWithMargins = True
        Left = 0
        Top = 285
        Margins.Left = 0
        Margins.Top = 2
        Margins.Right = 0
        Margins.Bottom = 2
        Align = alBottom
        Alignment = alCenterCenter
        TabOrder = 1
        Height = 35
        Width = 901
        object CCProgressBar: TcxProgressBar
          Left = 2
          Top = 2
          Align = alClient
          Properties.ShowTextStyle = cxtsText
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.Color = clLime
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 0
          ExplicitHeight = 21
          Width = 897
        end
      end
      object cxGroupBox18: TcxGroupBox
        AlignWithMargins = True
        Left = 0
        Top = 469
        Margins.Left = 0
        Margins.Top = 2
        Margins.Right = 0
        Margins.Bottom = 0
        Align = alBottom
        Alignment = alCenterCenter
        TabOrder = 2
        Height = 35
        Width = 901
        object Panel6: TPanel
          Left = 68
          Top = 2
          Width = 831
          Height = 31
          Align = alRight
          BevelOuter = bvNone
          Color = clCream
          ParentBackground = False
          TabOrder = 0
          object CCExportBTN: TcxButton
            Left = 643
            Top = 3
            Width = 75
            Height = 25
            Caption = #23548'   '#20986
            LookAndFeel.NativeStyle = True
            TabOrder = 0
            OnClick = CCExportBTNClick
          end
          object CCPreviewBTN: TcxButton
            Left = 737
            Top = 3
            Width = 75
            Height = 25
            Caption = #25171#21360#39044#35272
            LookAndFeel.NativeStyle = True
            TabOrder = 1
            OnClick = CCPreviewBTNClick
          end
        end
      end
      object cxGroupBox19: TcxGroupBox
        Left = 0
        Top = 322
        Align = alBottom
        Alignment = alCenterCenter
        TabOrder = 3
        Height = 35
        Width = 901
        object Panel7: TPanel
          Left = 2
          Top = 2
          Width = 897
          Height = 31
          Align = alClient
          BevelOuter = bvNone
          Caption = #23548#20986#25968#25454#38656#35201'XLS'#36719#20214#25903#25345#65292#35831#30830#35748#31995#32479#20013#23433#35013'XLS'#36719#20214#65292#21542#21017#26080#27861#23436#25104#23548#20986'!'
          Color = 8421631
          ParentBackground = False
          TabOrder = 0
        end
      end
      object cxGroupBox20: TcxGroupBox
        Left = 0
        Top = 357
        Align = alBottom
        Caption = #20449#24687#32479#35745
        TabOrder = 4
        Height = 110
        Width = 901
        object cxGroupBox21: TcxGroupBox
          Left = 182
          Top = 21
          Align = alLeft
          Caption = #26089#39184#32479#35745
          TabOrder = 0
          Height = 87
          Width = 179
          object Label13: TLabel
            Left = 15
            Top = 59
            Width = 30
            Height = 16
            Caption = #27425#25968
          end
          object Label14: TLabel
            Left = 15
            Top = 27
            Width = 30
            Height = 16
            Caption = #37329#39069
          end
          object CBFCSTextEdit: TcxTextEdit
            Left = 51
            Top = 56
            TabOrder = 0
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
          object CSBFZETextEdit: TcxTextEdit
            Left = 51
            Top = 23
            TabOrder = 1
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
        end
        object cxGroupBox22: TcxGroupBox
          Left = 361
          Top = 21
          Align = alLeft
          Caption = #21320#39184#32479#35745
          TabOrder = 1
          Height = 87
          Width = 179
          object Label15: TLabel
            Left = 15
            Top = 59
            Width = 30
            Height = 16
            Caption = #27425#25968
          end
          object Label16: TLabel
            Left = 15
            Top = 27
            Width = 30
            Height = 16
            Caption = #37329#39069
          end
          object CLHCSTextEdit: TcxTextEdit
            Left = 51
            Top = 55
            TabOrder = 0
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
          object CLHZETextEdit: TcxTextEdit
            Left = 51
            Top = 23
            TabOrder = 1
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
        end
        object cxGroupBox23: TcxGroupBox
          Left = 540
          Top = 21
          Align = alLeft
          Caption = #26202#39184#32479#35745
          TabOrder = 2
          Height = 87
          Width = 179
          object Label17: TLabel
            Left = 15
            Top = 59
            Width = 30
            Height = 16
            Caption = #27425#25968
          end
          object Label18: TLabel
            Left = 15
            Top = 27
            Width = 30
            Height = 16
            Caption = #37329#39069
          end
          object CSRCSTextEdit: TcxTextEdit
            Left = 51
            Top = 55
            TabOrder = 0
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
          object CSRZETextEdit: TcxTextEdit
            Left = 51
            Top = 23
            TabOrder = 1
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
        end
        object cxGroupBox24: TcxGroupBox
          Left = 719
          Top = 21
          Align = alLeft
          Caption = #22812#23477#32479#35745
          TabOrder = 3
          Height = 87
          Width = 179
          object Label19: TLabel
            Left = 15
            Top = 59
            Width = 30
            Height = 16
            Caption = #27425#25968
          end
          object Label20: TLabel
            Left = 15
            Top = 27
            Width = 30
            Height = 16
            Caption = #37329#39069
          end
          object CNTCSTextEdit: TcxTextEdit
            Left = 51
            Top = 55
            TabOrder = 0
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
          object CNTZETextEdit: TcxTextEdit
            Left = 51
            Top = 23
            TabOrder = 1
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
        end
        object cxGroupBox25: TcxGroupBox
          Left = 2
          Top = 21
          Align = alLeft
          Caption = #24635#21644#32479#35745
          TabOrder = 4
          Height = 87
          Width = 180
          object Label21: TLabel
            Left = 15
            Top = 59
            Width = 30
            Height = 16
            Caption = #27425#25968
          end
          object Label22: TLabel
            Left = 15
            Top = 27
            Width = 30
            Height = 16
            Caption = #37329#39069
          end
          object CZCSTextEdit: TcxTextEdit
            Left = 51
            Top = 55
            TabOrder = 0
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
          object CZZETextEdit: TcxTextEdit
            Left = 51
            Top = 23
            TabOrder = 1
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
        end
      end
    end
    object cxTabSheet4: TcxTabSheet
      Caption = #25353#20010#20154#27719#24635#32479#35745
      ImageIndex = 3
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object cxGroupBox26: TcxGroupBox
        AlignWithMargins = True
        Left = 0
        Top = 0
        Margins.Left = 0
        Margins.Top = 0
        Margins.Right = 0
        Margins.Bottom = 2
        Align = alClient
        Alignment = alCenterCenter
        TabOrder = 0
        Height = 390
        Width = 901
        object GRHZDataGrid: TcxGrid
          AlignWithMargins = True
          Left = 5
          Top = 5
          Width = 891
          Height = 380
          Align = alClient
          TabOrder = 0
          object GRHZDataGridTV: TcxGridDBTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.DataSource = GRHZDataSource
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsCustomize.ColumnFiltering = False
            OptionsCustomize.ColumnSorting = False
            OptionsData.CancelOnExit = False
            OptionsData.Deleting = False
            OptionsData.DeletingConfirmation = False
            OptionsData.Editing = False
            OptionsData.Inserting = False
            OptionsSelection.CellSelect = False
            OptionsView.CellAutoHeight = True
            OptionsView.GroupByBox = False
            Styles.StyleSheet = GridTableViewStyleSheetEggplant
            object HZBHCol: TcxGridDBColumn
              Caption = #32534#21495
              MinWidth = 80
              Width = 140
            end
            object HZXMCol: TcxGridDBColumn
              Caption = #22995#21517
              MinWidth = 80
              Width = 119
            end
            object HZKHCol: TcxGridDBColumn
              Caption = #21345#21495
              MinWidth = 80
              Width = 159
            end
            object HZXFCSCol: TcxGridDBColumn
              Caption = #28040#36153#24635#27425#25968
              MinWidth = 80
              Width = 152
            end
            object HZXFZECol: TcxGridDBColumn
              Caption = #28040#36153#24635#39069
              MinWidth = 80
              Width = 140
            end
            object HZBMCol: TcxGridDBColumn
              Caption = #37096#38376
              MinWidth = 80
              Width = 196
            end
          end
          object GRHZDataGridLL: TcxGridLevel
            GridView = GRHZDataGridTV
          end
        end
      end
      object cxGroupBox27: TcxGroupBox
        AlignWithMargins = True
        Left = 0
        Top = 394
        Margins.Left = 0
        Margins.Top = 2
        Margins.Right = 0
        Margins.Bottom = 2
        Align = alBottom
        Alignment = alCenterCenter
        TabOrder = 1
        Height = 35
        Width = 901
        object GRHZProgressBar: TcxProgressBar
          Left = 2
          Top = 2
          Align = alClient
          Properties.ShowTextStyle = cxtsText
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.Color = clLime
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 0
          ExplicitHeight = 21
          Width = 897
        end
      end
      object cxGroupBox28: TcxGroupBox
        AlignWithMargins = True
        Left = 0
        Top = 468
        Margins.Left = 0
        Margins.Top = 2
        Margins.Right = 0
        Margins.Bottom = 0
        Align = alBottom
        Alignment = alCenterCenter
        TabOrder = 2
        Height = 36
        Width = 901
        object Panel8: TPanel
          Left = 68
          Top = 2
          Width = 831
          Height = 32
          Align = alRight
          BevelOuter = bvNone
          Color = clCream
          ParentBackground = False
          TabOrder = 0
          object Label23: TLabel
            Left = 210
            Top = 8
            Width = 75
            Height = 16
            Caption = #24635#28040#36153#27425#25968
          end
          object Label24: TLabel
            Left = 429
            Top = 7
            Width = 60
            Height = 16
            Caption = #28040#36153#24635#39069
          end
          object GRHZExportBTN: TcxButton
            Left = 643
            Top = 3
            Width = 75
            Height = 25
            Caption = #23548'   '#20986
            LookAndFeel.NativeStyle = True
            TabOrder = 0
            OnClick = GRHZExportBTNClick
          end
          object GRHZPreviewBTN: TcxButton
            Left = 737
            Top = 3
            Width = 75
            Height = 25
            Caption = #25171#21360#39044#35272
            LookAndFeel.NativeStyle = True
            TabOrder = 1
            OnClick = GRHZPreviewBTNClick
          end
          object GRHZZCSTextEdit: TcxTextEdit
            Left = 292
            Top = 4
            TabOrder = 2
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
          object GRHZZETextEdit: TcxTextEdit
            Left = 495
            Top = 4
            TabOrder = 3
            OnKeyPress = ABFCSTextEditKeyPress
            Width = 121
          end
        end
      end
      object cxGroupBox29: TcxGroupBox
        Left = 0
        Top = 431
        Align = alBottom
        Alignment = alCenterCenter
        TabOrder = 3
        Height = 35
        Width = 901
        object Panel9: TPanel
          Left = 2
          Top = 2
          Width = 897
          Height = 31
          Align = alClient
          BevelOuter = bvNone
          Caption = #23548#20986#25968#25454#38656#35201'XLS'#36719#20214#25903#25345#65292#35831#30830#35748#31995#32479#20013#23433#35013'XLS'#36719#20214#65292#21542#21017#26080#27861#23436#25104#23548#20986'!'
          Color = 8421631
          ParentBackground = False
          TabOrder = 0
        end
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 635
    Width = 913
    Height = 33
    Align = alBottom
    Alignment = taLeftJustify
    BevelOuter = bvNone
    BiDiMode = bdLeftToRight
    Caption = '            '#35813#21151#33021#21253#25324#22235#24352#25253#34920#65292#35831#22312#20013#38388#21306#22495#36827#34892#36873#25321#65292#26597#35810#38656#35201#36739#38271#26102#38388#65292#35831#32784#24515#31561#24453#65281
    Color = clCream
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -16
    Font.Name = #40657#20307
    Font.Style = []
    ParentBiDiMode = False
    ParentBackground = False
    ParentFont = False
    TabOrder = 1
    object ExitBTN: TcxButton
      Left = 812
      Top = 3
      Width = 75
      Height = 25
      Caption = #36864'   '#20986
      LookAndFeel.NativeStyle = True
      TabOrder = 0
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = ExitBTNClick
    end
  end
  object cxGroupBox16: TcxGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Align = alTop
    Caption = #26597#35810#26465#20214
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 2
    Height = 90
    Width = 907
    object cxLabel9: TcxLabel
      Left = 116
      Top = 24
      Caption = #36215#22987#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object BeginDateEdit: TcxDateEdit
      Left = 193
      Top = 23
      TabOrder = 1
      OnKeyPress = ABFCSTextEditKeyPress
      Width = 121
    end
    object cxLabel10: TcxLabel
      Left = 351
      Top = 24
      Caption = #25130#27490#26085#26399':'
      ParentColor = False
      Style.Color = clCream
    end
    object EndDateEdit: TcxDateEdit
      Left = 426
      Top = 23
      TabOrder = 3
      OnKeyPress = ABFCSTextEditKeyPress
      Width = 121
    end
    object cxLabel11: TcxLabel
      Left = 366
      Top = 54
      Caption = #21333'   '#20301':'
      ParentColor = False
      Style.Color = clCream
    end
    object BMComboBox: TcxComboBox
      Left = 426
      Top = 53
      TabOrder = 5
      OnKeyPress = ABFCSTextEditKeyPress
      Width = 121
    end
    object cxLabel12: TcxLabel
      Left = 594
      Top = 24
      Caption = #32534'   '#21495':'
      ParentColor = False
      Style.Color = clCream
    end
    object BHTextEdit: TcxTextEdit
      Left = 651
      Top = 23
      Properties.MaxLength = 10
      TabOrder = 7
      OnKeyPress = BHTextEditKeyPress
      Width = 121
    end
    object QueryBTN: TcxButton
      Left = 651
      Top = 53
      Width = 121
      Height = 25
      Caption = #26597'   '#35810
      LookAndFeel.NativeStyle = True
      TabOrder = 8
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = QueryBTNClick
    end
    object cxLabel1: TcxLabel
      Left = 133
      Top = 54
      Caption = #39184'   '#21381':'
      ParentColor = False
      Style.Color = clCream
    end
    object CTComboBox: TcxComboBox
      Left = 193
      Top = 53
      TabOrder = 10
      OnKeyPress = ABFCSTextEditKeyPress
      Width = 121
    end
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 48
    Top = 216
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
    object cxStyle51: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle52: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 12307669
      TextColor = clBlack
    end
    object cxStyle53: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 14542570
      TextColor = clBlack
    end
    object cxStyle54: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 12307669
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle55: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 6852002
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle56: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 6852002
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle57: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 12307669
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle58: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clTeal
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle59: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 12307669
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle60: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clTeal
    end
    object cxStyle61: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clTeal
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle15: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle16: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 11458790
      TextColor = clBlack
    end
    object cxStyle17: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 14150898
      TextColor = clBlack
    end
    object cxStyle18: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 11458790
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle19: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 4630214
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = 14150898
    end
    object cxStyle20: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle21: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 11458790
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle22: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 4630214
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle23: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 11458790
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle24: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clMaroon
    end
    object cxStyle25: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 4630214
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle26: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 15461375
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle27: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 15461375
      TextColor = clBlack
    end
    object cxStyle28: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 15461375
      TextColor = clBlack
    end
    object cxStyle29: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 13158655
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle30: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 3552892
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = 14540253
    end
    object cxStyle31: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 3552892
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle32: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 13158655
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle33: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 5855675
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle34: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 13158655
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Times New Roman'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle35: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = 7364767
    end
    object cxStyle36: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 5855675
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle37: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 15136253
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 7346457
      Font.Height = -12
      Font.Name = 'Arial Narrow'
      Font.Style = []
      TextColor = 7346457
    end
    object cxStyle38: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 16436871
      TextColor = clBlack
    end
    object cxStyle39: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 8036607
      TextColor = clBlack
    end
    object cxStyle40: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 8894686
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle41: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 12180223
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle42: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 1262987
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle43: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 8894686
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -12
      Font.Name = 'Arial Narrow'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle44: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clNavy
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -12
      Font.Name = 'Arial Narrow'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle45: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 8894686
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Arial Narrow'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle46: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clBlue
    end
    object cxStyle47: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clNavy
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -12
      Font.Name = 'Arial Narrow'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle48: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle49: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 11055248
      TextColor = clBlack
    end
    object cxStyle50: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 14211272
      TextColor = clBlack
    end
    object cxStyle62: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 11055248
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle63: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 7897176
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 524288
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      TextColor = 524288
    end
    object cxStyle64: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 4194368
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle65: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 11055248
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle66: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 7897176
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle67: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 11055248
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle68: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 7897176
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      TextColor = 7897176
    end
    object cxStyle69: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 7897176
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle70: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle71: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 11126946
      TextColor = clBlack
    end
    object cxStyle72: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 13886416
      TextColor = clBlack
    end
    object cxStyle73: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 11126946
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle74: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 6592345
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = 13886416
    end
    object cxStyle75: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 2178849
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle76: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 11126946
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle77: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 6592345
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle78: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 11126946
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle79: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = 6592345
    end
    object cxStyle80: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 6592345
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
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
    object GridTableViewStyleSheetDesert: TcxGridTableViewStyleSheet
      Caption = 'Desert'
      Styles.Content = cxStyle51
      Styles.ContentEven = cxStyle52
      Styles.ContentOdd = cxStyle53
      Styles.Inactive = cxStyle58
      Styles.Selection = cxStyle61
      Styles.Footer = cxStyle54
      Styles.Group = cxStyle55
      Styles.GroupByBox = cxStyle56
      Styles.Header = cxStyle57
      Styles.Indicator = cxStyle59
      Styles.Preview = cxStyle60
      BuiltIn = True
    end
    object GridTableViewStyleSheetMaple: TcxGridTableViewStyleSheet
      Caption = 'Maple'
      Styles.Content = cxStyle15
      Styles.ContentEven = cxStyle16
      Styles.ContentOdd = cxStyle17
      Styles.Inactive = cxStyle22
      Styles.Selection = cxStyle25
      Styles.Footer = cxStyle18
      Styles.Group = cxStyle19
      Styles.GroupByBox = cxStyle20
      Styles.Header = cxStyle21
      Styles.Indicator = cxStyle23
      Styles.Preview = cxStyle24
      BuiltIn = True
    end
    object GridTableViewStyleSheetRose: TcxGridTableViewStyleSheet
      Caption = 'Rose'
      Styles.Content = cxStyle26
      Styles.ContentEven = cxStyle27
      Styles.ContentOdd = cxStyle28
      Styles.Inactive = cxStyle33
      Styles.Selection = cxStyle36
      Styles.Footer = cxStyle29
      Styles.Group = cxStyle30
      Styles.GroupByBox = cxStyle31
      Styles.Header = cxStyle32
      Styles.Indicator = cxStyle34
      Styles.Preview = cxStyle35
      BuiltIn = True
    end
    object GridTableViewStyleSheetUserFormat1: TcxGridTableViewStyleSheet
      Caption = 'UserFormat1'
      Styles.Content = cxStyle37
      Styles.ContentEven = cxStyle38
      Styles.ContentOdd = cxStyle39
      Styles.Inactive = cxStyle44
      Styles.Selection = cxStyle47
      Styles.Footer = cxStyle40
      Styles.Group = cxStyle41
      Styles.GroupByBox = cxStyle42
      Styles.Header = cxStyle43
      Styles.Indicator = cxStyle45
      Styles.Preview = cxStyle46
      BuiltIn = True
    end
    object GridTableViewStyleSheetEggplant: TcxGridTableViewStyleSheet
      Caption = 'Eggplant'
      Styles.Content = cxStyle48
      Styles.ContentEven = cxStyle49
      Styles.ContentOdd = cxStyle50
      Styles.Inactive = cxStyle66
      Styles.Selection = cxStyle69
      Styles.Footer = cxStyle62
      Styles.Group = cxStyle63
      Styles.GroupByBox = cxStyle64
      Styles.Header = cxStyle65
      Styles.Indicator = cxStyle67
      Styles.Preview = cxStyle68
      BuiltIn = True
    end
    object GridTableViewStyleSheetSpruce: TcxGridTableViewStyleSheet
      Caption = 'Spruce'
      Styles.Content = cxStyle70
      Styles.ContentEven = cxStyle71
      Styles.ContentOdd = cxStyle72
      Styles.Inactive = cxStyle77
      Styles.Selection = cxStyle80
      Styles.Footer = cxStyle73
      Styles.Group = cxStyle74
      Styles.GroupByBox = cxStyle75
      Styles.Header = cxStyle76
      Styles.Indicator = cxStyle78
      Styles.Preview = cxStyle79
      BuiltIn = True
    end
  end
  object ALLMXADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 48
    Top = 166
  end
  object ALLMXDataSource: TDataSource
    DataSet = ALLMXADOQuery
    Left = 48
    Top = 118
  end
  object ALLSaveDialog: TSaveDialog
    FileName = #37325#21629#21517
    Filter = 'xls'
    Left = 48
    Top = 328
  end
  object ALLADOQInThread: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 48
    Top = 272
  end
  object frxALLMXReport: TfrxReport
    Version = '4.9.32'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 40866.570706550900000000
    ReportOptions.LastChange = 41094.635932974540000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 48
    Top = 384
    Datasets = <
      item
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      Orientation = poLandscape
      PaperWidth = 257.000000000000000000
      PaperHeight = 182.000000000000000000
      PaperSize = 256
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      object ReportTitle1: TfrxReportTitle
        Height = 164.078835350000000000
        Top = 18.897650000000000000
        Width = 895.748610000000000000
        object Memo2: TfrxMemoView
          Left = 340.834880000000000000
          Width = 222.992270000000000000
          Height = 34.015770000000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -27
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #28040#36153#32479#35745#26126#32454#25253#34920)
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          Top = 78.606370000000000000
          Width = 76.346456692913400000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #32479#35745)
          ParentFont = False
        end
        object LHZEMemo: TfrxMemoView
          Left = 403.543600000000000000
          Top = 99.283550000000000000
          Width = 164.031496060000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          Left = -0.031540000000000000
          Top = 119.960730000000000000
          Width = 76.346456692913400000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #28040#36153#27425#25968)
          ParentFont = False
        end
        object BFCSMemo: TfrxMemoView
          Left = 237.858380000000000000
          Top = 119.960730000000000000
          Width = 165.543307086614000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object LHCSMemo: TfrxMemoView
          Left = 403.496290000000000000
          Top = 119.960730000000000000
          Width = 164.031496060000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object SRCSMemo: TfrxMemoView
          Left = 567.118430000000000000
          Top = 119.740260000000000000
          Width = 164.031496060000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo19: TfrxMemoView
          Top = 99.504020000000000000
          Width = 76.346456692913400000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #28040#36153#37329#39069)
          ParentFont = False
        end
        object Memo20: TfrxMemoView
          Left = 441.165740000000000000
          Top = 57.385900000000010000
          Width = 75.590600000000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #29983#25104#26085#26399)
          ParentFont = False
        end
        object BFZEMemo: TfrxMemoView
          Left = 238.669450000000000000
          Top = 99.504020000000000000
          Width = 164.787401574803000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object SCRQMemo: TfrxMemoView
          Left = 516.756340000000000000
          Top = 57.385900000000010000
          Width = 151.181102360000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo23: TfrxMemoView
          Left = 668.244590000000000000
          Top = 35.929190000000000000
          Width = 76.346456692913400000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #36215#22987#26085#26399)
          ParentFont = False
        end
        object Memo24: TfrxMemoView
          Left = 668.260360000000000000
          Top = 57.385900000000010000
          Width = 75.590600000000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #25130#27490#26085#26399)
          ParentFont = False
        end
        object QSRQMemo: TfrxMemoView
          Left = 744.528140000000000000
          Top = 35.929190000000000000
          Width = 150.425196850394000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object JZRQMemo: TfrxMemoView
          Left = 743.850960000000000000
          Top = 57.385900000000010000
          Width = 151.181102360000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo28: TfrxMemoView
          Left = -0.220470000000000000
          Top = 141.401670000000000000
          Width = 894.992125980000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #27599#26085#35814#32454#28040#36153#24773#20917)
          ParentFont = False
        end
        object SRZEMemo: TfrxMemoView
          Left = 566.961040000000000000
          Top = 99.504020000000000000
          Width = 164.031496060000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object NTZEMemo: TfrxMemoView
          Left = 730.803650000000000000
          Top = 99.283550000000000000
          Width = 164.031496060000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object NTCSMemo: TfrxMemoView
          Left = 730.827150000000000000
          Top = 119.740260000000000000
          Width = 164.031496060000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object ZZEMemo: TfrxMemoView
          Left = 75.944960000000000000
          Top = 99.283550000000000000
          Width = 162.141732283465000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object ZCSMemo: TfrxMemoView
          Left = 75.881880000000000000
          Top = 119.960730000000000000
          Width = 162.141732283465000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo41: TfrxMemoView
          Left = -0.220470000000000000
          Top = 57.692950000000000000
          Width = 76.346456690000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #25253#34920#25805#20316#21592)
          ParentFont = False
        end
        object BBCZYMemo: TfrxMemoView
          Left = 76.133890000000000000
          Top = 57.692950000000000000
          Width = 123.968503937008000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          Left = 76.590600000000000000
          Top = 78.606370000000000000
          Width = 161.385826771654000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #25152#26377#39184#27425)
          ParentFont = False
        end
        object Memo6: TfrxMemoView
          Left = 237.889920000000000000
          Top = 78.606370000000000000
          Width = 165.543307086614000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #26089#39184)
          ParentFont = False
        end
        object Memo9: TfrxMemoView
          Left = 403.409710000000000000
          Top = 77.826840000000000000
          Width = 164.031496060000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #21320#39184)
          ParentFont = False
        end
        object Memo11: TfrxMemoView
          Left = 566.929500000000000000
          Top = 77.826840000000000000
          Width = 164.031496060000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #26202#39184)
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          Left = 731.228820000000000000
          Top = 77.826840000000000000
          Width = 164.031496060000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #22812#23477)
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          Left = 200.071120000000000000
          Top = 35.795300000000000000
          Width = 76.346456690000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #37096#38376)
          ParentFont = False
        end
        object BMMemo: TfrxMemoView
          Left = 276.661720000000000000
          Top = 35.795300000000000000
          Width = 391.559055118110000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          Top = 36.015770000000010000
          Width = 76.346456690000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #32534#21495)
          ParentFont = False
        end
        object BHMemo: TfrxMemoView
          Left = 76.354360000000000000
          Top = 36.015770000000010000
          Width = 123.968503937008000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo10: TfrxMemoView
          Left = 200.315090000000000000
          Top = 57.692950000000000000
          Width = 76.346456690000000000
          Height = 20.787401574803100000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #39184#21381)
          ParentFont = False
        end
        object CTMemo: TfrxMemoView
          Left = 275.905690000000000000
          Top = 57.692950000000000000
          Width = 165.543307090000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
      end
      object MasterData1: TfrxMasterData
        Height = 20.787401570000000000
        Top = 287.244280000000000000
        Width = 895.748610000000000000
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
        RowCount = 0
        object RQ: TfrxMemoView
          Width = 79.748031500000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ZZE: TfrxMemoView
          Left = 80.590600000000000000
          Width = 86.929133860000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ZCS: TfrxMemoView
          Left = 167.181200000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object BZE: TfrxMemoView
          Left = 242.771800000000000000
          Width = 86.929133860000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object BZCS: TfrxMemoView
          Left = 329.362400000000000000
          Width = 76.346456690000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object LZE: TfrxMemoView
          Left = 405.953000000000000000
          Width = 86.929133860000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object LZCS: TfrxMemoView
          Left = 493.134200000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SZE: TfrxMemoView
          Left = 569.165740000000000000
          Width = 86.929133860000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SZCS: TfrxMemoView
          Left = 656.197280000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object NZE: TfrxMemoView
          Left = 732.228820000000000000
          Width = 86.929133860000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object NZCS: TfrxMemoView
          Left = 818.732840000000000000
          Width = 76.346456690000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        Height = 22.677180000000000000
        Top = 370.393940000000000000
        Width = 895.748610000000000000
        object Memo1: TfrxMemoView
          Left = 819.158010000000000000
          Top = 2.779530000000022000
          Width = 75.590600000000000000
          Height = 18.897650000000000000
          ShowHint = False
          HAlign = haRight
          Memo.UTF8W = (
            '[Page#]')
        end
      end
      object PageHeader1: TfrxPageHeader
        Height = 20.787401570000000000
        Top = 204.094620000000000000
        Width = 895.748610000000000000
        object Memo29: TfrxMemoView
          Width = 79.748031500000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #26085#26399)
          ParentFont = False
        end
        object Memo30: TfrxMemoView
          Left = 80.590600000000000000
          Width = 86.929133860000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #28040#36153#24635#39069)
          ParentFont = False
        end
        object Memo31: TfrxMemoView
          Left = 167.181200000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #27425#25968)
          ParentFont = False
        end
        object Memo32: TfrxMemoView
          Left = 242.771800000000000000
          Width = 86.929133860000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #26089#39184#28040#36153#39069)
          ParentFont = False
        end
        object Memo33: TfrxMemoView
          Left = 329.362400000000000000
          Width = 76.346456690000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #27425#25968)
          ParentFont = False
        end
        object Memo34: TfrxMemoView
          Left = 405.953000000000000000
          Width = 86.929133860000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #21320#39184#28040#36153#39069)
          ParentFont = False
        end
        object Memo36: TfrxMemoView
          Left = 493.134200000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #27425#25968)
          ParentFont = False
        end
        object Memo37: TfrxMemoView
          Left = 569.165740000000000000
          Width = 86.929133860000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #26202#39184#28040#36153#39069)
          ParentFont = False
        end
        object Memo38: TfrxMemoView
          Left = 656.197280000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #27425#25968)
          ParentFont = False
        end
        object Memo39: TfrxMemoView
          Left = 732.228820000000000000
          Width = 86.929133860000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #22812#23477#28040#36153#39069)
          ParentFont = False
        end
        object Memo40: TfrxMemoView
          Left = 819.173780000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #27425#25968)
          ParentFont = False
        end
      end
    end
  end
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    DataSource = ALLMXDataSource
    BCDToCurrency = False
    Left = 48
    Top = 448
  end
  object GRDataSource: TDataSource
    DataSet = GRADOQuery
    Left = 176
    Top = 118
  end
  object GRADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 176
    Top = 166
  end
  object GRADOQInThread: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 176
    Top = 272
  end
  object GRSaveDialog: TSaveDialog
    FileName = #37325#21629#21517
    Filter = 'xls'
    Left = 176
    Top = 328
  end
  object frxGRMXReport: TfrxReport
    Version = '4.9.32'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 40884.931528611100000000
    ReportOptions.LastChange = 41094.636308773150000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 176
    Top = 384
    Datasets = <
      item
        DataSet = frxDBDataset2
        DataSetName = 'frxDBDataset2'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 182.000000000000000000
      PaperHeight = 257.000000000000000000
      PaperSize = 256
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      object ReportTitle1: TfrxReportTitle
        Height = 128.826825350000000000
        Top = 18.897650000000000000
        Width = 612.283860000000000000
        object Memo2: TfrxMemoView
          Width = 612.283860000000000000
          Height = 37.795300000000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -32
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #28040#36153#32479#35745'('#25353#20010#20154')')
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          Top = 37.795300000000000000
          Width = 86.929133860000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #32534#21495)
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          Top = 60.472480000000000000
          Width = 86.929133858267700000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #25253#34920#25805#20316#21592)
          ParentFont = False
        end
        object GRBHMemo: TfrxMemoView
          Left = 87.488250000000000000
          Top = 37.795300000000000000
          Width = 109.606370000000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object GRBBCZYMemo: TfrxMemoView
          Left = 87.488250000000000000
          Top = 60.472480000000000000
          Width = 109.606370000000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          Left = 197.094620000000000000
          Top = 37.795300000000000000
          Width = 68.031496060000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #21333#20301)
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          Left = 197.094620000000000000
          Top = 60.472480000000000000
          Width = 68.031496060000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #29983#25104#26085#26399)
          ParentFont = False
        end
        object GRBMMemo: TfrxMemoView
          Left = 265.582870000000000000
          Top = 37.795300000000000000
          Width = 139.086614170000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object GRSCRQMemo: TfrxMemoView
          Left = 265.582870000000000000
          Top = 60.472480000000000000
          Width = 139.086614170000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo11: TfrxMemoView
          Top = 106.149660000000000000
          Width = 86.929133860000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #36215#22987#26085#26399)
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          Left = 306.228510000000000000
          Top = 106.149660000000000000
          Width = 68.031496060000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #25130#33267#26085#26399)
          ParentFont = False
        end
        object GRQSRQMemo: TfrxMemoView
          Left = 87.692950000000000000
          Top = 106.149660000000000000
          Width = 218.456692910000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object GRJZRQMemo: TfrxMemoView
          Left = 374.260050000000000000
          Top = 106.149660000000000000
          Width = 238.110299690000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo15: TfrxMemoView
          Left = 404.409710000000000000
          Top = 37.795300000000000000
          Width = 83.149606299212600000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #24635#28040#36153#39069)
          ParentFont = False
        end
        object Memo16: TfrxMemoView
          Left = 404.409710000000000000
          Top = 60.472480000000000000
          Width = 83.149606299212600000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #24635#28040#36153#27425#25968)
          ParentFont = False
        end
        object GRXFZEMemo: TfrxMemoView
          Left = 487.559370000000000000
          Top = 37.795300000000000000
          Width = 124.724409450000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object GRXFZCSMemo: TfrxMemoView
          Left = 487.559370000000000000
          Top = 60.472480000000000000
          Width = 124.724409450000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          Top = 83.149660000000000000
          Width = 86.929133860000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #39184#21381)
          ParentFont = False
        end
        object CTMemo: TfrxMemoView
          Left = 87.488250000000000000
          Top = 83.149660000000000000
          Width = 524.598425196850000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
      end
      object MasterData1: TfrxMasterData
        Height = 22.677180000000000000
        Top = 253.228510000000000000
        Width = 612.283860000000000000
        DataSet = frxDBDataset2
        DataSetName = 'frxDBDataset2'
        RowCount = 0
        object GRRQM: TfrxMemoView
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object GRXMM: TfrxMemoView
          Left = 97.929190000000000000
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object GRBHM: TfrxMemoView
          Left = 195.858380000000000000
          Width = 113.385826770000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object GRXFCSM: TfrxMemoView
          Left = 308.921460000000000000
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object GRXFZEM: TfrxMemoView
          Left = 407.189240000000000000
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object GRBMM: TfrxMemoView
          Left = 505.457020000000000000
          Width = 106.582677170000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        Height = 22.677180000000000000
        Top = 336.378170000000000000
        Width = 612.283860000000000000
        object Memo1: TfrxMemoView
          Left = 642.520100000000000000
          Width = 75.590600000000000000
          Height = 18.897650000000000000
          ShowHint = False
          HAlign = haRight
          Memo.UTF8W = (
            '[Page#]')
        end
        object Memo25: TfrxMemoView
          Left = 514.016080000000000000
          Top = 1.000000000000000000
          Width = 75.590600000000000000
          Height = 18.897650000000000000
          ShowHint = False
          HAlign = haRight
          Memo.UTF8W = (
            '[Page#]')
        end
      end
      object PageHeader1: TfrxPageHeader
        Height = 22.677180000000000000
        Top = 170.078850000000000000
        Width = 612.283860000000000000
        object Memo19: TfrxMemoView
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #26085#26399)
          ParentFont = False
        end
        object Memo20: TfrxMemoView
          Left = 97.929190000000000000
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #22995#21517)
          ParentFont = False
        end
        object Memo21: TfrxMemoView
          Left = 195.858380000000000000
          Width = 113.385826770000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #32534#21495)
          ParentFont = False
        end
        object Memo22: TfrxMemoView
          Left = 308.921460000000000000
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #28040#36153#27425#25968)
          ParentFont = False
        end
        object Memo23: TfrxMemoView
          Left = 407.189240000000000000
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #28040#36153#24635#39069)
          ParentFont = False
        end
        object Memo24: TfrxMemoView
          Left = 505.457020000000000000
          Width = 106.582677165354000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #37096#38376)
          ParentFont = False
        end
      end
    end
  end
  object frxDBDataset2: TfrxDBDataset
    UserName = 'frxDBDataset2'
    CloseDataSource = False
    DataSource = GRDataSource
    BCDToCurrency = False
    Left = 176
    Top = 448
  end
  object CCDataSource: TDataSource
    DataSet = CCADOQuery
    Left = 304
    Top = 117
  end
  object CCADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 304
    Top = 165
  end
  object CCADOQInThread: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 304
    Top = 271
  end
  object CCSaveDialog: TSaveDialog
    FileName = #37325#21629#21517
    Filter = 'xls'
    Left = 304
    Top = 327
  end
  object frxCCReport: TfrxReport
    Version = '4.9.32'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 40885.442788807900000000
    ReportOptions.LastChange = 41094.446752025500000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 304
    Top = 383
    Datasets = <
      item
        DataSet = frxDBDataset3
        DataSetName = 'frxDBDataset3'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      Orientation = poLandscape
      PaperWidth = 257.000000000000000000
      PaperHeight = 182.000000000000000000
      PaperSize = 256
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      object ReportTitle1: TfrxReportTitle
        Height = 164.078835350000000000
        Top = 18.897650000000000000
        Width = 895.748610000000000000
        object Memo2: TfrxMemoView
          Left = 251.464750000000000000
          Width = 400.630180000000000000
          Height = 34.015770000000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -27
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #28040#36153#32479#35745#26126#32454#25253#34920'('#25353#20010#20154#21450#39184#27425')')
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          Top = 78.606370000000000000
          Width = 76.346456692913400000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #32479#35745)
          ParentFont = False
        end
        object LHZEMemo: TfrxMemoView
          Left = 403.543600000000000000
          Top = 99.283550000000000000
          Width = 164.031496060000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          Left = -0.031540000000000000
          Top = 119.960730000000000000
          Width = 76.346456692913400000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #28040#36153#27425#25968)
          ParentFont = False
        end
        object BFCSMemo: TfrxMemoView
          Left = 237.858380000000000000
          Top = 119.960730000000000000
          Width = 165.543307086614000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object LHCSMemo: TfrxMemoView
          Left = 403.496290000000000000
          Top = 119.960730000000000000
          Width = 164.031496060000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object SRCSMemo: TfrxMemoView
          Left = 567.118430000000000000
          Top = 119.740260000000000000
          Width = 164.031496060000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo19: TfrxMemoView
          Top = 99.504020000000000000
          Width = 76.346456692913400000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #28040#36153#37329#39069)
          ParentFont = False
        end
        object Memo20: TfrxMemoView
          Left = 449.165740000000000000
          Top = 57.385900000000010000
          Width = 75.590600000000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #29983#25104#26085#26399)
          ParentFont = False
        end
        object BFZEMemo: TfrxMemoView
          Left = 238.669450000000000000
          Top = 99.504020000000000000
          Width = 164.787401574803000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object SCRQMemo: TfrxMemoView
          Left = 524.756340000000000000
          Top = 57.385900000000010000
          Width = 143.622047240000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo23: TfrxMemoView
          Left = 668.244590000000000000
          Top = 35.929190000000000000
          Width = 75.590600000000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #36215#22987#26085#26399)
          ParentFont = False
        end
        object Memo24: TfrxMemoView
          Left = 668.260360000000000000
          Top = 57.385900000000010000
          Width = 75.590600000000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #25130#27490#26085#26399)
          ParentFont = False
        end
        object QSRQMemo: TfrxMemoView
          Left = 743.835190000000000000
          Top = 35.929190000000000000
          Width = 151.181102360000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object JZRQMemo: TfrxMemoView
          Left = 743.850960000000000000
          Top = 57.385900000000010000
          Width = 151.181102360000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo28: TfrxMemoView
          Left = -0.220470000000000000
          Top = 141.401670000000000000
          Width = 894.992125980000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #35814#32454#28040#36153#24773#20917)
          ParentFont = False
        end
        object SRZEMemo: TfrxMemoView
          Left = 566.961040000000000000
          Top = 99.504020000000000000
          Width = 164.031496060000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object NTZEMemo: TfrxMemoView
          Left = 730.803650000000000000
          Top = 99.283550000000000000
          Width = 164.031496060000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object NTCSMemo: TfrxMemoView
          Left = 730.827150000000000000
          Top = 119.740260000000000000
          Width = 164.031496060000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object ZZEMemo: TfrxMemoView
          Left = 75.944960000000000000
          Top = 99.283550000000000000
          Width = 162.141732283465000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object ZCSMemo: TfrxMemoView
          Left = 75.881880000000000000
          Top = 119.960730000000000000
          Width = 162.141732283465000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo41: TfrxMemoView
          Left = -0.220470000000000000
          Top = 57.692950000000000000
          Width = 76.346456690000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            #25253#34920#25805#20316#21592)
          ParentFont = False
        end
        object BBCZYMemo: TfrxMemoView
          Left = 76.133890000000000000
          Top = 57.692950000000000000
          Width = 161.763816140000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          Left = 76.590600000000000000
          Top = 78.606370000000000000
          Width = 161.385826771654000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #25152#26377#39184#27425)
          ParentFont = False
        end
        object Memo6: TfrxMemoView
          Left = 237.889920000000000000
          Top = 78.606370000000000000
          Width = 165.543307086614000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #26089#39184)
          ParentFont = False
        end
        object Memo9: TfrxMemoView
          Left = 403.409710000000000000
          Top = 77.826840000000000000
          Width = 164.031496060000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #21320#39184)
          ParentFont = False
        end
        object Memo11: TfrxMemoView
          Left = 566.929500000000000000
          Top = 77.826840000000000000
          Width = 164.031496060000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #26202#39184)
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          Left = 731.228820000000000000
          Top = 77.826840000000000000
          Width = 164.031496060000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #22812#23477)
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          Left = 238.071120000000000000
          Top = 35.795300000000000000
          Width = 76.346456690000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #37096#38376)
          ParentFont = False
        end
        object BMMemo: TfrxMemoView
          Left = 314.661720000000000000
          Top = 35.795300000000000000
          Width = 353.763779530000000000
          Height = 21.165354330000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          Top = 36.015770000000010000
          Width = 76.346456690000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #32534#21495)
          ParentFont = False
        end
        object BHMemo: TfrxMemoView
          Left = 76.354360000000000000
          Top = 36.015770000000010000
          Width = 161.763816140000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo14: TfrxMemoView
          Left = 238.110390000000000000
          Top = 57.692950000000000000
          Width = 76.346456690000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #39184#21381)
          ParentFont = False
        end
        object CTMemo: TfrxMemoView
          Left = 314.700990000000000000
          Top = 57.692950000000000000
          Width = 134.551181100000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
      end
      object MasterData1: TfrxMasterData
        Height = 20.787401570000000000
        Top = 287.244280000000000000
        Width = 895.748610000000000000
        DataSet = frxDBDataset3
        DataSetName = 'frxDBDataset3'
        RowCount = 0
        object BH: TfrxMemoView
          Width = 69.921259840000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ZZE: TfrxMemoView
          Left = 211.590600000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object ZCS: TfrxMemoView
          Left = 287.181200000000000000
          Width = 59.716535430000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object BZE: TfrxMemoView
          Left = 347.315090000000000000
          Width = 77.102362200000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object BZCS: TfrxMemoView
          Left = 423.905690000000000000
          Width = 60.472440940000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object LZE: TfrxMemoView
          Left = 483.953000000000000000
          Width = 76.346456690000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object LZCS: TfrxMemoView
          Left = 560.134200000000000000
          Width = 61.228346460000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SZE: TfrxMemoView
          Left = 621.165740000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object SZCS: TfrxMemoView
          Left = 697.197280000000000000
          Width = 61.228346460000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object NZE: TfrxMemoView
          Left = 758.228820000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object NZCS: TfrxMemoView
          Left = 833.732840000000000000
          Width = 61.228346460000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object XM: TfrxMemoView
          Left = 69.811070000000000000
          Width = 69.921259840000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object KH: TfrxMemoView
          Left = 140.622140000000000000
          Width = 71.055118110000000000
          Height = 20.787401570000000000
          ShowHint = False
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        Height = 22.677180000000000000
        Top = 370.393940000000000000
        Width = 895.748610000000000000
        object Memo1: TfrxMemoView
          Left = 819.158010000000000000
          Top = 2.779530000000022000
          Width = 75.590600000000000000
          Height = 18.897650000000000000
          ShowHint = False
          HAlign = haRight
          Memo.UTF8W = (
            '[Page#]')
        end
      end
      object PageHeader1: TfrxPageHeader
        Height = 20.787401570000000000
        Top = 204.094620000000000000
        Width = 895.748610000000000000
        object Memo29: TfrxMemoView
          Width = 69.921259842519710000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #32534#21495)
          ParentFont = False
        end
        object Memo30: TfrxMemoView
          Left = 211.590600000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #28040#36153#24635#39069)
          ParentFont = False
        end
        object Memo31: TfrxMemoView
          Left = 287.181200000000000000
          Width = 60.472440940000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #27425#25968)
          ParentFont = False
        end
        object Memo32: TfrxMemoView
          Left = 347.315090000000000000
          Width = 77.102362204724400000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #26089#39184#28040#36153#39069)
          ParentFont = False
        end
        object Memo33: TfrxMemoView
          Left = 423.905690000000000000
          Width = 60.472440940000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #27425#25968)
          ParentFont = False
        end
        object Memo34: TfrxMemoView
          Left = 483.953000000000000000
          Width = 76.346456692913400000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #21320#39184#28040#36153#39069)
          ParentFont = False
        end
        object Memo36: TfrxMemoView
          Left = 560.134200000000000000
          Width = 61.228346456692900000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #27425#25968)
          ParentFont = False
        end
        object Memo37: TfrxMemoView
          Left = 621.165740000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #26202#39184#28040#36153#39069)
          ParentFont = False
        end
        object Memo38: TfrxMemoView
          Left = 697.197280000000000000
          Width = 61.228346456692900000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #27425#25968)
          ParentFont = False
        end
        object Memo39: TfrxMemoView
          Left = 758.228820000000000000
          Width = 75.590551180000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #22812#23477#28040#36153#39069)
          ParentFont = False
        end
        object Memo40: TfrxMemoView
          Left = 834.173780000000000000
          Width = 61.228346460000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #27425#25968)
          ParentFont = False
        end
        object Memo10: TfrxMemoView
          Left = 70.370130000000000000
          Width = 69.921259840000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #22995#21517)
          ParentFont = False
        end
        object Memo13: TfrxMemoView
          Left = 139.740260000000000000
          Width = 71.811023620000000000
          Height = 20.787401570000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #21345#21495)
          ParentFont = False
        end
      end
    end
  end
  object frxDBDataset3: TfrxDBDataset
    UserName = 'frxDBDataset3'
    CloseDataSource = False
    DataSource = CCDataSource
    BCDToCurrency = False
    Left = 304
    Top = 447
  end
  object GRHZDataSource: TDataSource
    DataSet = GRHZADOQuery
    Left = 408
    Top = 117
  end
  object GRHZADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 408
    Top = 165
  end
  object GRHZADOQInThread: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 408
    Top = 271
  end
  object GRHZSaveDialog: TSaveDialog
    FileName = #37325#21629#21517
    Filter = 'xls'
    Left = 408
    Top = 327
  end
  object frxGRHZReport: TfrxReport
    Version = '4.9.32'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 40885.641003680600000000
    ReportOptions.LastChange = 41094.449595810200000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 408
    Top = 383
    Datasets = <
      item
        DataSet = frxDBDataset4
        DataSetName = 'frxDBDataset4'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 182.000000000000000000
      PaperHeight = 257.000000000000000000
      PaperSize = 256
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      object ReportTitle1: TfrxReportTitle
        Height = 128.826825350000000000
        Top = 18.897650000000000000
        Width = 612.283860000000000000
        object Memo2: TfrxMemoView
          Width = 612.283860000000000000
          Height = 37.795300000000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -32
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #28040#36153#27719#24635#25253#34920'('#25353#20010#20154')')
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          Top = 37.795300000000000000
          Width = 86.929133860000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #32534#21495)
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          Top = 60.472480000000000000
          Width = 86.929133858267700000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #25253#34920#25805#20316#21592)
          ParentFont = False
        end
        object HZBHMemo: TfrxMemoView
          Left = 87.488250000000000000
          Top = 37.795300000000000000
          Width = 109.606370000000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object HZBBCZYMemo: TfrxMemoView
          Left = 87.488250000000000000
          Top = 60.472480000000000000
          Width = 109.606370000000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          Left = 197.094620000000000000
          Top = 37.795300000000000000
          Width = 68.031496060000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #21333#20301)
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          Left = 197.094620000000000000
          Top = 60.472480000000000000
          Width = 68.031496060000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #29983#25104#26085#26399)
          ParentFont = False
        end
        object HZBMMemo: TfrxMemoView
          Left = 265.582870000000000000
          Top = 37.795300000000000000
          Width = 139.086614170000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object HZSCRQMemo: TfrxMemoView
          Left = 265.582870000000000000
          Top = 60.472480000000000000
          Width = 139.086614170000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo11: TfrxMemoView
          Top = 106.149660000000000000
          Width = 86.929133860000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #36215#22987#26085#26399)
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          Left = 306.228510000000000000
          Top = 106.149660000000000000
          Width = 68.031496060000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #25130#33267#26085#26399)
          ParentFont = False
        end
        object HZQSRQMemo: TfrxMemoView
          Left = 87.692950000000000000
          Top = 106.149660000000000000
          Width = 218.456692910000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object HZJZRQMemo: TfrxMemoView
          Left = 374.260050000000000000
          Top = 106.149660000000000000
          Width = 238.110299690000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo15: TfrxMemoView
          Left = 404.409710000000000000
          Top = 37.795300000000000000
          Width = 83.149606299212600000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #24635#28040#36153#39069)
          ParentFont = False
        end
        object Memo16: TfrxMemoView
          Left = 404.409710000000000000
          Top = 60.472480000000000000
          Width = 83.149606299212600000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #24635#28040#36153#27425#25968)
          ParentFont = False
        end
        object HZXFZEMemo: TfrxMemoView
          Left = 487.559370000000000000
          Top = 37.795300000000000000
          Width = 124.724409450000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object HZXFZCSMemo: TfrxMemoView
          Left = 487.559370000000000000
          Top = 60.472480000000000000
          Width = 124.724409450000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          Top = 83.149660000000000000
          Width = 86.929146060000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #39184#21381)
          ParentFont = False
        end
        object CTMemo: TfrxMemoView
          Left = 87.385900000000000000
          Top = 83.149660000000000000
          Width = 524.598674170000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
      end
      object MasterData1: TfrxMasterData
        Height = 22.677180000000000000
        Top = 253.228510000000000000
        Width = 612.283860000000000000
        DataSet = frxDBDataset4
        DataSetName = 'frxDBDataset4'
        RowCount = 0
        object HZBHM: TfrxMemoView
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset4
          DataSetName = 'frxDBDataset4'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object HZXMM: TfrxMemoView
          Left = 97.929190000000000000
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset4
          DataSetName = 'frxDBDataset4'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object HZKHM: TfrxMemoView
          Left = 195.858380000000000000
          Width = 113.385826770000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset4
          DataSetName = 'frxDBDataset4'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object HZXFCSM: TfrxMemoView
          Left = 308.921460000000000000
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset4
          DataSetName = 'frxDBDataset4'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object HZXFZEM: TfrxMemoView
          Left = 407.189240000000000000
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset4
          DataSetName = 'frxDBDataset4'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
        object HZBMM: TfrxMemoView
          Left = 505.457020000000000000
          Width = 106.582677170000000000
          Height = 22.677165350000000000
          ShowHint = False
          DataSet = frxDBDataset4
          DataSetName = 'frxDBDataset4'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        Height = 22.677180000000000000
        Top = 336.378170000000000000
        Width = 612.283860000000000000
        object Memo1: TfrxMemoView
          Left = 642.520100000000000000
          Width = 75.590600000000000000
          Height = 18.897650000000000000
          ShowHint = False
          HAlign = haRight
          Memo.UTF8W = (
            '[Page#]')
        end
        object Memo25: TfrxMemoView
          Left = 514.016080000000000000
          Top = 1.000000000000000000
          Width = 75.590600000000000000
          Height = 18.897650000000000000
          ShowHint = False
          HAlign = haRight
          Memo.UTF8W = (
            '[Page#]')
        end
      end
      object PageHeader1: TfrxPageHeader
        Height = 22.677180000000000000
        Top = 170.078850000000000000
        Width = 612.283860000000000000
        object Memo19: TfrxMemoView
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #32534#21495)
          ParentFont = False
        end
        object Memo20: TfrxMemoView
          Left = 97.929190000000000000
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #22995#21517)
          ParentFont = False
        end
        object Memo21: TfrxMemoView
          Left = 195.858380000000000000
          Width = 113.385826770000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #21345#21495)
          ParentFont = False
        end
        object Memo22: TfrxMemoView
          Left = 308.921460000000000000
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #28040#36153#27425#25968)
          ParentFont = False
        end
        object Memo23: TfrxMemoView
          Left = 407.189240000000000000
          Width = 98.267716540000000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #28040#36153#24635#39069)
          ParentFont = False
        end
        object Memo24: TfrxMemoView
          Left = 505.457020000000000000
          Width = 106.582677165354000000
          Height = 22.677165350000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #37096#38376)
          ParentFont = False
        end
      end
    end
  end
  object frxDBDataset4: TfrxDBDataset
    UserName = 'frxDBDataset4'
    CloseDataSource = False
    DataSource = GRHZDataSource
    BCDToCurrency = False
    Left = 408
    Top = 447
  end
  object InitADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 672
    Top = 118
  end
  object ALLTJADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 672
    Top = 182
  end
  object AGRTJADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 672
    Top = 238
  end
  object CCTJADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 768
    Top = 182
  end
  object GRHZTJADOQuery: TADOQuery
    AutoCalcFields = False
    Connection = SDIAppForm.ADOConnection1
    CommandTimeout = 100
    Parameters = <>
    Left = 768
    Top = 238
  end
end
