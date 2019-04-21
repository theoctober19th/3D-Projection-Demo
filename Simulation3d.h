//---------------------------------------------------------------------------

#ifndef Simulation3dH
#define Simulation3dH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTimer *Timer1;
        TMainMenu *MainMenu1;
        TMenuItem *Go1;
        TMenuItem *Fo1;
        TMenuItem *No1;
        TMenuItem *Color1;
        TMenuItem *Red1;
        TMenuItem *Green1;
        TMenuItem *Blue1;
        TMenuItem *Custom1;
        TMenuItem *Help1;
        TMenuItem *Controls1;
        TMenuItem *AboutApplication1;
        void __fastcall FormCreate(TObject *Sender);
       // void __fastcall FormClick(TObject *Sender);
        void __fastcall FormMouseWheelUp(TObject *Sender,
          TShiftState Shift, TPoint &MousePos, bool &Handled);
        void __fastcall FormMouseWheelDown(TObject *Sender,
          TShiftState Shift, TPoint &MousePos, bool &Handled);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall FormDblClick(TObject *Sender);
        void __fastcall Custom1Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Red1Click(TObject *Sender);
        void __fastcall Green1Click(TObject *Sender);
        void __fastcall Blue1Click(TObject *Sender);
        void __fastcall Fo1Click(TObject *Sender);
        void __fastcall No1Click(TObject *Sender);
        void __fastcall Controls1Click(TObject *Sender);
        void __fastcall BounceSimulation1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
