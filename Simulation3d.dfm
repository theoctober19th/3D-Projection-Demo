object Form1: TForm1
  Left = 323
  Top = 290
  Width = 1048
  Height = 684
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnActivate = FormActivate
  OnCreate = FormCreate
  OnDblClick = FormDblClick
  OnKeyDown = FormKeyDown
  OnKeyUp = FormKeyUp
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseUp = FormMouseUp
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  PixelsPerInch = 96
  TextHeight = 13
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 8
    Top = 64
  end
  object MainMenu1: TMainMenu
    Left = 248
    Top = 16
    object Go1: TMenuItem
      Caption = 'Shapes'
      object Fo1: TMenuItem
        Caption = 'Pyramid'
        OnClick = Fo1Click
      end
      object No1: TMenuItem
        Caption = 'Cube'
        OnClick = No1Click
      end
    end
    object Color1: TMenuItem
      Caption = 'Color'
      object Red1: TMenuItem
        Caption = 'Red'
        OnClick = Red1Click
      end
      object Green1: TMenuItem
        Caption = 'Green'
        OnClick = Green1Click
      end
      object Blue1: TMenuItem
        Caption = 'Blue'
        OnClick = Blue1Click
      end
      object Custom1: TMenuItem
        Caption = 'Custom'
        OnClick = Custom1Click
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      object Controls1: TMenuItem
        Caption = 'Controls'
        OnClick = Controls1Click
      end
      object AboutApplication1: TMenuItem
        Caption = 'About Application'
      end
    end
  end
end
