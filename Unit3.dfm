object Form3: TForm3
  Left = 571
  Top = 172
  Width = 206
  Height = 136
  Caption = 'Form3'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object StaticText1: TStaticText
    Left = 0
    Top = 0
    Width = 155
    Height = 17
    Caption = 'Mouse Scroll Down:   Zoom Out'
    TabOrder = 0
  end
  object StaticText2: TStaticText
    Left = 0
    Top = 24
    Width = 148
    Height = 17
    Caption = 'Mouse Scroll Up:        Zoom In'
    TabOrder = 1
  end
  object StaticText3: TStaticText
    Left = 0
    Top = 48
    Width = 124
    Height = 17
    Caption = 'Mouse Drag:         Rotate'
    TabOrder = 2
  end
  object StaticText4: TStaticText
    Left = 0
    Top = 72
    Width = 149
    Height = 17
    Caption = 'Ctrl + Mouse Drag: AutoRotate'
    TabOrder = 3
  end
end
