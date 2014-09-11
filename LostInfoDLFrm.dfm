object LostInfoFRM: TLostInfoFRM
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = #25346#22833#35299#25346#20449#24687#19979#20256#31383#21475
  ClientHeight = 500
  ClientWidth = 688
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
    Width = 688
    Height = 57
    Align = alTop
    Caption = #25346#22833#35299#25346#20449#24687#19979#20256
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -27
    Font.Name = #40657#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 57
    Width = 688
    Height = 344
    Align = alTop
    DataSource = DataSource1
    Options = [dgTitles, dgIndicator]
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -13
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'SFJID'
        Title.Caption = #28040#36153#26426#21495
        Width = 150
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'SFJPORT'
        Title.Caption = #36890#35759#31471#21475
        Width = 150
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'CMD'
        Title.Caption = #25346#22833'/'#35299#25346
        Width = 150
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'PARA'
        Title.Caption = #21345#21495
        Width = 200
        Visible = True
      end>
  end
  object SCanProBar: TcxProgressBar
    Left = 0
    Top = 401
    Align = alTop
    AutoSize = False
    Properties.BarStyle = cxbsAnimationLEDs
    Properties.BeginColor = 54056
    Properties.Max = 100.000000000000000000
    Style.LookAndFeel.Kind = lfStandard
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.Kind = lfStandard
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.Kind = lfStandard
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.Kind = lfStandard
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 2
    Height = 32
    Width = 688
  end
  object cxButton1: TcxButton
    Left = 216
    Top = 446
    Width = 97
    Height = 34
    Caption = #19979#20256#20449#24687
    LookAndFeel.NativeStyle = True
    TabOrder = 3
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 353
    Top = 446
    Width = 97
    Height = 34
    Caption = #36864#20986
    LookAndFeel.NativeStyle = True
    TabOrder = 4
    OnClick = cxButton2Click
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 592
    Top = 168
  end
  object ADOTable1: TADOTable
    Connection = SDIAppForm.ADOConnection1
    TableName = 'CMDLIST'
    Left = 592
    Top = 112
  end
end
