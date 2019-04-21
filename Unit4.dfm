object Form4: TForm4
  Left = 355
  Top = 175
  Width = 1044
  Height = 500
  Caption = 'Form4'
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
  object Shape1: TShape
    Left = 48
    Top = 0
    Width = 65
    Height = 65
    Shape = stCircle
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 10
    OnTimer = Timer1Timer
    Left = 184
    Top = 8
  end
end
