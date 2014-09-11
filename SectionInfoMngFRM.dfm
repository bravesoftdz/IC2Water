object SectionInfoManageFRM: TSectionInfoManageFRM
  Left = 0
  Top = 0
  Caption = 'SectionInfoManagefrom'
  ClientHeight = 551
  ClientWidth = 746
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clMenuHighlight
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 0
    Width = 746
    Height = 551
    ActivePage = cxTabSheet1
    Align = alClient
    ShowFrame = True
    Style = 9
    TabOrder = 0
    OnClick = cxPageControl1Click
    ClientRectBottom = 550
    ClientRectLeft = 1
    ClientRectRight = 745
    ClientRectTop = 23
    object cxTabSheet1: TcxTabSheet
      Caption = #37096#38376#36164#26009
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMenuHighlight
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageIndex = 0
      ParentFont = False
      OnShow = cxTabSheet1Show
      object Panel1: TPanel
        Left = 0
        Top = 462
        Width = 744
        Height = 65
        Align = alBottom
        BevelOuter = bvNone
        Color = clWhite
        ParentBackground = False
        TabOrder = 0
        object Label1: TLabel
          Left = 15
          Top = 5
          Width = 105
          Height = 16
          Caption = #22686#21152#37096#38376#21517#31216#65306
        end
        object Label2: TLabel
          Left = 15
          Top = 35
          Width = 105
          Height = 16
          Caption = #20462#25913#37096#38376#21517#31216#65306
        end
        object SectionInfoFixBTN: TcxButton
          Left = 271
          Top = 31
          Width = 75
          Height = 25
          Caption = #20462'   '#25913
          LookAndFeel.NativeStyle = True
          TabOrder = 0
          OnClick = SectionInfoFixBTNClick
        end
        object cxButton3: TcxButton
          Left = 431
          Top = 0
          Width = 75
          Height = 25
          Caption = #21024'   '#38500
          LookAndFeel.NativeStyle = True
          TabOrder = 1
          OnClick = cxButton3Click
        end
        object cxButton4: TcxButton
          Left = 271
          Top = 0
          Width = 75
          Height = 25
          Caption = #22686'   '#21152
          LookAndFeel.NativeStyle = True
          TabOrder = 2
          OnClick = cxButton4Click
        end
        object cxButton6: TcxButton
          Left = 431
          Top = 31
          Width = 75
          Height = 25
          Caption = #36864'   '#20986
          LookAndFeel.NativeStyle = True
          TabOrder = 3
          OnClick = cxButton6Click
        end
        object cxTextEdit1: TcxTextEdit
          Left = 120
          Top = 1
          Properties.MaxLength = 32
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 4
          Width = 145
        end
        object cxDBTextEdit1: TcxDBTextEdit
          Left = 528
          Top = 31
          DataBinding.DataField = 'BUMEN'
          DataBinding.DataSource = SectionInfoDS
          Properties.OnChange = cxDBTextEdit1PropertiesChange
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 5
          Visible = False
          Width = 145
        end
        object cxTextEdit8: TcxTextEdit
          Left = 120
          Top = 31
          Properties.MaxLength = 32
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 6
          Width = 145
        end
      end
      object SectionInfoGrid: TcxGrid
        AlignWithMargins = True
        Left = 8
        Top = 8
        Width = 728
        Height = 446
        Margins.Left = 8
        Margins.Top = 8
        Margins.Right = 8
        Margins.Bottom = 8
        Align = alClient
        TabOrder = 1
        object SectionInfoGridTV: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.DataSource = SectionInfoDS
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsSelection.CellSelect = False
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          OptionsView.HeaderAutoHeight = True
          Styles.StyleSheet = GridTableViewStyleSheetDevExpress
          object SectionInfoGridTVDM: TcxGridDBColumn
            Caption = #24207#21495
            DataBinding.FieldName = 'DM'
            HeaderAlignmentHorz = taRightJustify
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
          end
          object SectionInfoGridTVBUMEN: TcxGridDBColumn
            Caption = #37096#38376#21517#31216
            DataBinding.FieldName = 'BUMEN'
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
          end
        end
        object SectionInfoGridLL: TcxGridLevel
          GridView = SectionInfoGridTV
        end
      end
    end
    object cxTabSheet2: TcxTabSheet
      Caption = #20998#37096#38376#36164#26009
      ImageIndex = 1
      object TPanel
        Left = 0
        Top = 462
        Width = 744
        Height = 65
        Align = alBottom
        BevelOuter = bvNone
        Color = clWhite
        ParentBackground = False
        TabOrder = 0
        object Label3: TLabel
          Left = 16
          Top = 5
          Width = 120
          Height = 16
          Caption = #22686#21152#20998#37096#38376#21517#31216#65306
        end
        object Label4: TLabel
          Left = 16
          Top = 35
          Width = 120
          Height = 16
          Caption = #20462#25913#20998#37096#38376#21517#31216#65306
        end
        object cxButton7: TcxButton
          Left = 294
          Top = 31
          Width = 75
          Height = 25
          Caption = #20462'   '#25913
          LookAndFeel.NativeStyle = True
          TabOrder = 0
          OnClick = cxButton7Click
        end
        object cxButton10: TcxButton
          Left = 294
          Top = 0
          Width = 75
          Height = 25
          Caption = #22686'   '#21152
          LookAndFeel.NativeStyle = True
          TabOrder = 1
          OnClick = cxButton10Click
        end
        object cxButton11: TcxButton
          Left = 412
          Top = 0
          Width = 75
          Height = 25
          Caption = #21024'   '#38500
          LookAndFeel.NativeStyle = True
          TabOrder = 2
          OnClick = cxButton11Click
        end
        object cxButton12: TcxButton
          Left = 412
          Top = 31
          Width = 75
          Height = 25
          Caption = #36864'   '#20986
          LookAndFeel.NativeStyle = True
          TabOrder = 3
          OnClick = cxButton12Click
        end
        object cxTextEdit3: TcxTextEdit
          Left = 136
          Top = 1
          Properties.MaxLength = 32
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 4
          Width = 149
        end
        object cxDBTextEdit2: TcxDBTextEdit
          Left = 537
          Top = 30
          DataBinding.DataSource = SubSectionInfoDS
          Properties.OnChange = cxDBTextEdit2PropertiesChange
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 5
          Visible = False
          Width = 149
        end
        object cxTextEdit9: TcxTextEdit
          Left = 136
          Top = 31
          Properties.MaxLength = 32
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 6
          Width = 149
        end
      end
      object SubSectionInfoGrid: TcxGrid
        AlignWithMargins = True
        Left = 8
        Top = 56
        Width = 728
        Height = 398
        Margins.Left = 8
        Margins.Top = 8
        Margins.Right = 8
        Margins.Bottom = 8
        Align = alClient
        TabOrder = 1
        object SubSectionInfoGridTV: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.DataSource = SubSectionInfoDS
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsBehavior.DragScrolling = False
          OptionsBehavior.CopyPreviewToClipboard = False
          OptionsCustomize.ColumnFiltering = False
          OptionsSelection.CellSelect = False
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          Styles.StyleSheet = GridTableViewStyleSheetDevExpress
          object SubSectionInfoGridTVNUMCol: TcxGridDBColumn
            Caption = #24207#21495
            HeaderAlignmentHorz = taRightJustify
          end
          object SubSectionInfoGridTVSNameCol: TcxGridDBColumn
            Caption = #37096#38376#21517#31216
          end
          object SubSectionInfoGridTVBnameCol: TcxGridDBColumn
            Caption = #29677#21035#21517#31216
          end
        end
        object SubSectionInfoGridLL: TcxGridLevel
          GridView = SubSectionInfoGridTV
        end
      end
      object cxGroupBox1: TcxGroupBox
        AlignWithMargins = True
        Left = 8
        Top = 8
        Margins.Left = 8
        Margins.Top = 8
        Margins.Right = 8
        Margins.Bottom = 0
        Align = alTop
        Alignment = alCenterCenter
        TabOrder = 2
        Height = 40
        Width = 728
        object SectionNameComboBox: TcxComboBox
          Left = 92
          Top = 8
          Properties.OnChange = e
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 0
          Width = 200
        end
        object cxLabel1: TcxLabel
          Left = 12
          Top = 9
          Caption = #37096#38376#21517#31216#65306
        end
        object cxLabel2: TcxLabel
          Left = 315
          Top = 9
          Caption = #20998#37096#38376#21517#31216#65306
        end
        object ClassNameDBTextEdit: TcxDBTextEdit
          Left = 410
          Top = 8
          DataBinding.DataSource = SubSectionInfoDS
          Properties.ReadOnly = True
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 3
          Width = 209
        end
      end
    end
    object cxTabSheet3: TcxTabSheet
      Caption = #32452#21035#36164#26009
      ImageIndex = 2
      object Panel3: TPanel
        Left = 0
        Top = 462
        Width = 744
        Height = 65
        Align = alBottom
        BevelOuter = bvNone
        Color = clWhite
        ParentBackground = False
        TabOrder = 0
        object Label5: TLabel
          Left = 16
          Top = 5
          Width = 105
          Height = 16
          Caption = #22686#21152#32452#21035#21517#31216#65306
        end
        object Label6: TLabel
          Left = 16
          Top = 35
          Width = 105
          Height = 16
          Caption = #20462#25913#32452#21035#21517#31216#65306
        end
        object cxButton13: TcxButton
          Left = 281
          Top = 31
          Width = 75
          Height = 25
          Caption = #20462'   '#25913
          LookAndFeel.NativeStyle = True
          TabOrder = 0
          OnClick = cxButton13Click
        end
        object cxButton16: TcxButton
          Left = 281
          Top = 0
          Width = 75
          Height = 25
          Caption = #22686'   '#21152
          LookAndFeel.NativeStyle = True
          TabOrder = 1
          OnClick = cxButton16Click
        end
        object cxButton17: TcxButton
          Left = 418
          Top = 0
          Width = 75
          Height = 25
          Caption = #21024'   '#38500
          LookAndFeel.NativeStyle = True
          TabOrder = 2
          OnClick = cxButton17Click
        end
        object cxButton18: TcxButton
          Left = 418
          Top = 31
          Width = 75
          Height = 25
          Caption = #36864'   '#20986
          LookAndFeel.NativeStyle = True
          TabOrder = 3
          OnClick = cxButton18Click
        end
        object cxTextEdit2: TcxTextEdit
          Left = 121
          Top = 1
          Properties.MaxLength = 32
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 4
          Width = 149
        end
        object cxDBTextEdit3: TcxDBTextEdit
          Left = 545
          Top = 31
          DataBinding.DataSource = GroupInfoDS
          Properties.ReadOnly = True
          Properties.OnChange = cxDBTextEdit3PropertiesChange
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 5
          Visible = False
          Width = 149
        end
        object cxTextEdit10: TcxTextEdit
          Left = 121
          Top = 31
          Properties.MaxLength = 32
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 6
          Width = 149
        end
      end
      object cxGroupBox2: TcxGroupBox
        AlignWithMargins = True
        Left = 8
        Top = 8
        Margins.Left = 8
        Margins.Top = 8
        Margins.Right = 8
        Margins.Bottom = 8
        Align = alTop
        Alignment = alCenterCenter
        TabOrder = 1
        Height = 40
        Width = 728
        object cxLabel3: TcxLabel
          Left = 12
          Top = 9
          Caption = #37096#38376#21517#31216#65306
        end
        object SectionNameComboBox1: TcxComboBox
          Left = 88
          Top = 8
          Properties.ReadOnly = False
          Properties.OnChange = SectionNameComboBox1PropertiesChange
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 1
          Width = 145
        end
        object cxLabel4: TcxLabel
          Left = 243
          Top = 9
          Caption = #20998#37096#38376#21517#31216#65306
        end
        object ClassNameComboBox: TcxComboBox
          Left = 333
          Top = 8
          Properties.ReadOnly = False
          Properties.OnChange = ClassNameComboBoxPropertiesChange
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 3
          Width = 145
        end
        object cxLabel5: TcxLabel
          Left = 489
          Top = 9
          Caption = #32452#21035#21517#31216#65306
        end
        object GroupNameDBTextEdit: TcxDBTextEdit
          Left = 564
          Top = 8
          DataBinding.DataSource = GroupInfoDS
          Properties.ReadOnly = True
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 5
          Width = 145
        end
      end
      object GroupInfoGrid: TcxGrid
        AlignWithMargins = True
        Left = 8
        Top = 64
        Width = 728
        Height = 390
        Margins.Left = 8
        Margins.Top = 8
        Margins.Right = 8
        Margins.Bottom = 8
        Align = alClient
        TabOrder = 2
        object GroupInfoGridTV: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.DataSource = GroupInfoDS
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsSelection.CellSelect = False
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          Styles.StyleSheet = GridTableViewStyleSheetDevExpress
          object GroupInfoGridTVNumCol: TcxGridDBColumn
            Caption = #24207#21495
            HeaderAlignmentHorz = taRightJustify
            Options.Editing = False
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
          end
          object GroupInfoGridTVSNameCol: TcxGridDBColumn
            Caption = #37096#38376#21517#31216
            Options.Editing = False
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
          end
          object GroupInfoGridTVCNameCol: TcxGridDBColumn
            Caption = #20998#37096#38376#21517#31216
            Options.Editing = False
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
          end
          object GroupInfoGridTVGNameCol: TcxGridDBColumn
            Caption = #32452#21035#21517#31216
            Options.Editing = False
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
          end
        end
        object GroupInfoGridLL: TcxGridLevel
          GridView = GroupInfoGridTV
        end
      end
    end
    object cxTabSheet4: TcxTabSheet
      Caption = #36523#20221#36164#26009
      ImageIndex = 3
      OnShow = cxTabSheet4Show
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Panel4: TPanel
        Left = 0
        Top = 462
        Width = 744
        Height = 65
        Align = alBottom
        BevelOuter = bvNone
        Color = clWhite
        ParentBackground = False
        TabOrder = 0
        object Label7: TLabel
          Left = 15
          Top = 5
          Width = 105
          Height = 16
          Caption = #22686#21152#36523#20221#21517#31216#65306
        end
        object Label8: TLabel
          Left = 15
          Top = 35
          Width = 105
          Height = 16
          Caption = #20462#25913#36523#20221#21517#31216#65306
        end
        object cxButton19: TcxButton
          Left = 274
          Top = 31
          Width = 75
          Height = 25
          Caption = #20462'   '#25913
          LookAndFeel.NativeStyle = True
          TabOrder = 0
          OnClick = cxButton19Click
        end
        object cxButton22: TcxButton
          Left = 274
          Top = 0
          Width = 75
          Height = 25
          Caption = #22686'   '#21152
          LookAndFeel.NativeStyle = True
          TabOrder = 1
          OnClick = cxButton22Click
        end
        object cxButton23: TcxButton
          Left = 437
          Top = 0
          Width = 75
          Height = 25
          Caption = #21024'   '#38500
          LookAndFeel.NativeStyle = True
          TabOrder = 2
          OnClick = cxButton23Click
        end
        object cxButton24: TcxButton
          Left = 437
          Top = 31
          Width = 75
          Height = 25
          Caption = #36864'   '#20986
          LookAndFeel.NativeStyle = True
          TabOrder = 3
          OnClick = cxButton24Click
        end
        object cxTextEdit4: TcxTextEdit
          Left = 120
          Top = 1
          Properties.MaxLength = 32
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 4
          Width = 145
        end
        object cxDBTextEdit4: TcxDBTextEdit
          Left = 560
          Top = 31
          DataBinding.DataField = 'ZW'
          DataBinding.DataSource = SFDS
          Properties.OnChange = cxDBTextEdit4PropertiesChange
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 5
          Visible = False
          Width = 145
        end
        object cxTextEdit11: TcxTextEdit
          Left = 120
          Top = 31
          Properties.MaxLength = 32
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 6
          Width = 145
        end
      end
      object cxGrid1: TcxGrid
        AlignWithMargins = True
        Left = 8
        Top = 8
        Width = 728
        Height = 446
        Margins.Left = 8
        Margins.Top = 8
        Margins.Right = 8
        Margins.Bottom = 8
        Align = alClient
        TabOrder = 1
        object cxGridDBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.DataSource = SFDS
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsSelection.CellSelect = False
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          OptionsView.HeaderAutoHeight = True
          Styles.StyleSheet = GridTableViewStyleSheetDevExpress
          object cxGridDBColumn1: TcxGridDBColumn
            Caption = #24207#21495
            DataBinding.FieldName = 'DM'
            HeaderAlignmentHorz = taRightJustify
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
            Width = 259
          end
          object cxGridDBColumn2: TcxGridDBColumn
            Caption = #36523#20221#21517#31216
            DataBinding.FieldName = 'ZW'
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
            Width = 467
          end
        end
        object cxGridLevel1: TcxGridLevel
          GridView = cxGridDBTableView1
        end
      end
    end
    object cxTabSheet5: TcxTabSheet
      Caption = #28040#36153#22320#28857
      ImageIndex = 4
      OnShow = cxTabSheet5Show
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Panel5: TPanel
        Left = 0
        Top = 462
        Width = 744
        Height = 65
        Align = alBottom
        BevelOuter = bvNone
        Color = clWhite
        ParentBackground = False
        TabOrder = 0
        object Label9: TLabel
          Left = 15
          Top = 5
          Width = 105
          Height = 16
          Caption = #22686#21152#22320#28857#21517#31216#65306
        end
        object Label10: TLabel
          Left = 15
          Top = 35
          Width = 105
          Height = 16
          Caption = #20462#25913#22320#28857#21517#31216#65306
        end
        object cxButton25: TcxButton
          Left = 277
          Top = 31
          Width = 75
          Height = 25
          Caption = #20462'   '#25913
          LookAndFeel.NativeStyle = True
          TabOrder = 0
          OnClick = cxButton25Click
        end
        object cxButton28: TcxButton
          Left = 277
          Top = 0
          Width = 75
          Height = 25
          Caption = #22686'   '#21152
          LookAndFeel.NativeStyle = True
          TabOrder = 1
          OnClick = cxButton28Click
        end
        object cxButton29: TcxButton
          Left = 429
          Top = 0
          Width = 75
          Height = 25
          Caption = #21024'   '#38500
          LookAndFeel.NativeStyle = True
          TabOrder = 2
          OnClick = cxButton29Click
        end
        object cxButton30: TcxButton
          Left = 429
          Top = 31
          Width = 75
          Height = 25
          Caption = #36864'   '#20986
          LookAndFeel.NativeStyle = True
          TabOrder = 3
          OnClick = cxButton30Click
        end
        object cxTextEdit5: TcxTextEdit
          Left = 120
          Top = 1
          Properties.MaxLength = 32
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 4
          Width = 145
        end
        object cxDBTextEdit5: TcxDBTextEdit
          Left = 536
          Top = 31
          DataBinding.DataField = 'STNAME'
          DataBinding.DataSource = STDS
          Properties.OnChange = cxDBTextEdit5PropertiesChange
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 5
          Visible = False
          Width = 145
        end
        object cxTextEdit12: TcxTextEdit
          Left = 120
          Top = 31
          Properties.MaxLength = 32
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 6
          Width = 145
        end
      end
      object cxGrid2: TcxGrid
        AlignWithMargins = True
        Left = 8
        Top = 8
        Width = 728
        Height = 446
        Margins.Left = 8
        Margins.Top = 8
        Margins.Right = 8
        Margins.Bottom = 8
        Align = alClient
        TabOrder = 1
        object cxGridDBTableView2: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.DataSource = STDS
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsSelection.CellSelect = False
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          OptionsView.HeaderAutoHeight = True
          Styles.StyleSheet = GridTableViewStyleSheetDevExpress
          object cxGridDBColumn3: TcxGridDBColumn
            Caption = #24207#21495
            DataBinding.FieldName = 'STID'
            HeaderAlignmentHorz = taRightJustify
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
            Width = 259
          end
          object cxGridDBColumn4: TcxGridDBColumn
            Caption = #28040#36153#22320#28857
            DataBinding.FieldName = 'STNAME'
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
            Width = 467
          end
        end
        object cxGridLevel2: TcxGridLevel
          GridView = cxGridDBTableView2
        end
      end
    end
    object cxTabSheet6: TcxTabSheet
      Caption = #31995#32479#29992#25143#31649#29702
      ImageIndex = 5
      OnShow = cxTabSheet6Show
      object cxGrid3: TcxGrid
        AlignWithMargins = True
        Left = 8
        Top = 8
        Width = 728
        Height = 408
        Margins.Left = 8
        Margins.Top = 8
        Margins.Right = 8
        Margins.Bottom = 8
        Align = alClient
        TabOrder = 0
        object cxGridDBTableView3: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.DataSource = USERDS
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsSelection.CellSelect = False
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          OptionsView.HeaderAutoHeight = True
          Styles.StyleSheet = GridTableViewStyleSheetDevExpress
          object cxGridDBTableView3Column1: TcxGridDBColumn
            Caption = #29992#25143#24207#21495
            DataBinding.FieldName = 'USERID'
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
            Width = 100
          end
          object cxGridDBTableView3Column2: TcxGridDBColumn
            Caption = #29992#25143#21517
            DataBinding.FieldName = 'USERNAME'
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
            Width = 150
          end
          object cxGridDBTableView3Column3: TcxGridDBColumn
            Caption = #23494#30721
            DataBinding.FieldName = 'PASSWORD'
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
            Width = 150
          end
          object cxGridDBColumn6: TcxGridDBColumn
            Caption = #29992#25143#32452#21517
            DataBinding.FieldName = 'GROUPNAME'
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
            Width = 467
          end
          object cxGridDBColumn5: TcxGridDBColumn
            Caption = #29992#25143#32452#24207#21495
            DataBinding.FieldName = 'GROUPID'
            HeaderAlignmentHorz = taCenter
            Options.Filtering = False
            Options.FilteringFilteredItemsList = False
            Options.FilteringMRUItemsList = False
            Options.FilteringPopup = False
            Options.FilteringPopupMultiSelect = False
            Width = 259
          end
        end
        object cxGridLevel3: TcxGridLevel
          GridView = cxGridDBTableView3
        end
      end
      object Panel2: TPanel
        Left = 0
        Top = 424
        Width = 744
        Height = 103
        Align = alBottom
        BevelOuter = bvNone
        Color = clWhite
        ParentBackground = False
        TabOrder = 1
        object Label11: TLabel
          Left = 15
          Top = 5
          Width = 90
          Height = 16
          Caption = #22686#21152#29992#25143#21517#65306
        end
        object Label12: TLabel
          Left = 292
          Top = 35
          Width = 90
          Height = 16
          Caption = #20462#25913#29992#25143#21517#65306
        end
        object Label13: TLabel
          Left = 277
          Top = 5
          Width = 105
          Height = 16
          Caption = #22686#21152#29992#25143#32452#21517#65306
        end
        object Label14: TLabel
          Left = 30
          Top = 34
          Width = 75
          Height = 16
          Caption = #21407#22987#23494#30721#65306
        end
        object Label15: TLabel
          Left = 15
          Top = 65
          Width = 90
          Height = 16
          Caption = #20462#25913#21518#23494#30721#65306
        end
        object cxButton1: TcxButton
          Left = 539
          Top = 31
          Width = 75
          Height = 25
          Caption = #20462'   '#25913
          LookAndFeel.NativeStyle = True
          TabOrder = 0
          OnClick = cxButton1Click
        end
        object cxButton2: TcxButton
          Left = 539
          Top = 1
          Width = 75
          Height = 25
          Caption = #22686'   '#21152
          LookAndFeel.NativeStyle = True
          TabOrder = 1
          OnClick = cxButton2Click
        end
        object cxButton5: TcxButton
          Left = 661
          Top = 0
          Width = 75
          Height = 25
          Caption = #21024'   '#38500
          LookAndFeel.NativeStyle = True
          TabOrder = 2
          OnClick = cxButton5Click
        end
        object cxButton8: TcxButton
          Left = 661
          Top = 31
          Width = 75
          Height = 25
          Caption = #36864'   '#20986
          LookAndFeel.NativeStyle = True
          TabOrder = 3
          OnClick = cxButton30Click
        end
        object cxTextEdit6: TcxTextEdit
          Left = 106
          Top = 1
          Properties.MaxLength = 32
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 4
          Width = 145
        end
        object cxDBTextEdit6: TcxDBTextEdit
          Left = 382
          Top = 71
          DataBinding.DataField = 'USERNAME'
          DataBinding.DataSource = USERDS
          Properties.OnChange = cxDBTextEdit6PropertiesChange
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 5
          Visible = False
          Width = 145
        end
        object cxComboBox1: TcxComboBox
          Left = 382
          Top = 1
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 6
          OnEnter = cxComboBox1Enter
          OnKeyPress = cxComboBox1KeyPress
          Width = 145
        end
        object cxTextEdit7: TcxTextEdit
          Left = 106
          Top = 62
          Properties.MaxLength = 8
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 7
          OnKeyPress = cxTextEdit7KeyPress
          Width = 145
        end
        object cxTextEdit13: TcxTextEdit
          Left = 382
          Top = 31
          Properties.MaxLength = 32
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 8
          Width = 145
        end
        object cxTextEdit14: TcxTextEdit
          Left = 106
          Top = 31
          Properties.MaxLength = 8
          Style.LookAndFeel.NativeStyle = True
          StyleDisabled.LookAndFeel.NativeStyle = True
          StyleFocused.LookAndFeel.NativeStyle = True
          StyleHot.LookAndFeel.NativeStyle = True
          TabOrder = 9
          OnKeyPress = cxTextEdit7KeyPress
          Width = 145
        end
        object cxButton9: TcxButton
          Left = 539
          Top = 61
          Width = 75
          Height = 25
          Caption = #35774#32622#26435#38480
          LookAndFeel.NativeStyle = True
          TabOrder = 10
          OnClick = cxButton9Click
        end
      end
    end
  end
  object SectionInfoDS: TDataSource
    DataSet = SectionInfoADOT
    Left = 32
    Top = 261
  end
  object SectionInfoADOT: TADOTable
    Connection = SDIAppForm.ADOConnection1
    CursorType = ctStatic
    TableName = 'BUMEN'
    Left = 32
    Top = 317
  end
  object SectionInfoSR: TcxStyleRepository
    Left = 36
    Top = 373
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
  object SubSectionInfoDS: TDataSource
    DataSet = SubSectionInfoADOQ
    Left = 128
    Top = 261
  end
  object SubSectionInfoADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 129
    Top = 208
  end
  object GroupInfoDS: TDataSource
    DataSet = GroupInfoADOQ
    Left = 224
    Top = 262
  end
  object GroupInfoADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 224
    Top = 208
  end
  object SFDS: TDataSource
    DataSet = SFADOT
    Left = 336
    Top = 270
  end
  object STDS: TDataSource
    DataSet = STADOT
    Left = 424
    Top = 270
  end
  object SFADOT: TADOTable
    Connection = SDIAppForm.ADOConnection1
    CursorType = ctStatic
    TableName = 'SFZW'
    Left = 336
    Top = 205
  end
  object STADOT: TADOTable
    Connection = SDIAppForm.ADOConnection1
    CursorType = ctStatic
    TableName = 'STNAME'
    Left = 424
    Top = 205
  end
  object USERADOT: TADOTable
    Connection = SDIAppForm.ADOConnection1
    CursorType = ctStatic
    TableName = 'SYSUSER'
    Left = 536
    Top = 205
  end
  object USERDS: TDataSource
    DataSet = USERADOT
    Left = 536
    Top = 270
  end
  object USERADOQ: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 536
    Top = 328
  end
end
