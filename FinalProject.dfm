object Form1: TForm1
  Left = 245
  Top = 147
  Width = 1044
  Height = 540
  Caption = 'Form1'
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseUp = FormMouseUp
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  PixelsPerInch = 96
  TextHeight = 13
  object CColorGrid1: TCColorGrid
    Left = 664
    Top = 0
    Width = 312
    Height = 120
    TabOrder = 0
    OnChange = CColorGrid1Change
  end
  object Button1: TButton
    Left = 24
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Pencil'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 120
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Rectangle'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 224
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Ellipse'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 328
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Fill Color'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 440
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Line'
    TabOrder = 5
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 544
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Eraser'
    TabOrder = 6
    OnClick = Button6Click
  end
end
