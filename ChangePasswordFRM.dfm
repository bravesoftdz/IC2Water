object ChangePasswordFrom: TChangePasswordFrom
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #20462#25913#23494#30721#31383#21475
  ClientHeight = 142
  ClientWidth = 280
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clMenuHighlight
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object cxLabel1: TcxLabel
    Left = 8
    Top = 12
    Caption = #26087#23494#30721#65306
    ParentColor = False
    ParentFont = False
    Style.Color = clSkyBlue
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clMaroon
    Style.Font.Height = -13
    Style.Font.Name = 'Tahoma'
    Style.Font.Style = []
    Style.IsFontAssigned = True
  end
  object cxLabel2: TcxLabel
    Left = 8
    Top = 42
    Caption = #26032#23494#30721#65306
    ParentColor = False
    ParentFont = False
    Style.Color = clSkyBlue
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clMaroon
    Style.Font.Height = -13
    Style.Font.Name = 'Tahoma'
    Style.Font.Style = []
    Style.IsFontAssigned = True
  end
  object cxLabel3: TcxLabel
    Left = 8
    Top = 72
    Caption = #26032#23494#30721#65306
    ParentColor = False
    ParentFont = False
    Style.Color = clSkyBlue
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clMaroon
    Style.Font.Height = -13
    Style.Font.Name = 'Tahoma'
    Style.Font.Style = []
    Style.IsFontAssigned = True
  end
  object TEOldPassword: TcxTextEdit
    Left = 67
    Top = 8
    Properties.MaxLength = 4
    Properties.ReadOnly = False
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 3
    OnKeyPress = TEOldPasswordKeyPress
    Width = 201
  end
  object TENewPassword1: TcxTextEdit
    Left = 67
    Top = 38
    Properties.MaxLength = 4
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 4
    OnKeyPress = TENewPassword1KeyPress
    Width = 201
  end
  object TENewPassword2: TcxTextEdit
    Left = 67
    Top = 68
    Properties.MaxLength = 4
    Properties.PasswordChar = #9679
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 5
    OnKeyPress = TENewPassword2KeyPress
    Width = 201
  end
  object cxButton1: TcxButton
    Left = 52
    Top = 103
    Width = 75
    Height = 25
    Caption = #20462'   '#25913
    LookAndFeel.NativeStyle = True
    TabOrder = 6
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 145
    Top = 103
    Width = 75
    Height = 25
    Caption = #21462'   '#28040
    LookAndFeel.NativeStyle = True
    TabOrder = 7
    OnClick = cxButton2Click
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 232
    Top = 96
  end
end
