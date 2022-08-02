object Form9: TForm9
  Left = 0
  Top = 0
  Caption = 'Form9'
  ClientHeight = 333
  ClientWidth = 609
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 280
    Top = 256
    Width = 54
    Height = 13
    Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
  end
  object Memo1: TMemo
    Left = 376
    Top = 28
    Width = 185
    Height = 89
    Lines.Strings = (
      'abab'
      'dfa fgh')
    ScrollBars = ssVertical
    TabOrder = 0
    Visible = False
  end
  object Button1: TButton
    Left = 188
    Top = 152
    Width = 229
    Height = 25
    Caption = #1057#1078#1072#1090#1100' '#1092#1072#1081#1083
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 188
    Top = 200
    Width = 229
    Height = 25
    Caption = #1056#1072#1079#1072#1088#1093#1080#1074#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 2
    OnClick = Button2Click
  end
  object ProgressBar1: TProgressBar
    Left = 224
    Top = 288
    Width = 150
    Height = 17
    TabOrder = 3
  end
  object OpenDialog1: TOpenDialog
    Left = 88
    Top = 32
  end
  object SaveDialog1: TSaveDialog
    Left = 224
    Top = 40
  end
end
