object CheckWriteReadMachineFRM: TCheckWriteReadMachineFRM
  Left = 0
  Top = 0
  Caption = 'CheckWriteReadMachineFRM'
  ClientHeight = 456
  ClientWidth = 572
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clMenuHighlight
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object cxRadioGroup1: TcxRadioGroup
    Left = 0
    Top = 0
    Align = alTop
    Caption = #36890#35759#31471#21475#36873#25321
    Properties.Columns = 9
    Properties.Items = <
      item
        Caption = 'COM1'
      end
      item
        Caption = 'COM2'
      end
      item
        Caption = 'COM3'
      end
      item
        Caption = 'COM4'
      end
      item
        Caption = 'COM5'
      end
      item
        Caption = 'COM6'
      end
      item
        Caption = 'COM7'
      end
      item
        Caption = 'COM8'
      end>
    TabOrder = 0
    Height = 65
    Width = 572
  end
  object cxButton1: TcxButton
    Left = 1
    Top = 71
    Width = 75
    Height = 25
    Caption = #27979'   '#35797
    LookAndFeel.NativeStyle = True
    TabOrder = 1
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 82
    Top = 71
    Width = 75
    Height = 25
    Caption = #36864'   '#20986
    LookAndFeel.NativeStyle = True
    TabOrder = 2
    OnClick = cxButton2Click
  end
  object ADOQuery1: TADOQuery
    Connection = SDIAppForm.ADOConnection1
    Parameters = <>
    Left = 312
    Top = 224
  end
end
