object Form17: TForm17
  Left = 0
  Top = 0
  Caption = 'Web Demo'
  ClientHeight = 759
  ClientWidth = 1289
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object MemoDebug: TMemo
    Left = 24
    Top = 56
    Width = 553
    Height = 425
    Lines.Strings = (
      'MemoDebug')
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object WebBrowser1: TWebBrowser
    Left = 592
    Top = 56
    Width = 633
    Height = 625
    TabOrder = 1
    ControlData = {
      4C00000062250000E92400000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object Button1: TButton
    Left = 456
    Top = 592
    Width = 75
    Height = 25
    Caption = 'Navigate'
    TabOrder = 2
    OnClick = Button1Click
  end
  object BN_Quit: TButton
    Left = 456
    Top = 632
    Width = 75
    Height = 25
    Caption = 'QUIT'
    TabOrder = 3
    OnClick = BN_QuitClick
  end
  object IdHTTPServer1: TIdHTTPServer
    Bindings = <>
    OnCommandGet = IdHTTPServer1CommandGet
    Left = 88
    Top = 576
  end
end
