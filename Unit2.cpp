//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Simulation3d.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGRID"
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
        colorSelected = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::CColorGrid1Change(TObject *Sender)
{
       colorSelected = CColorGrid1->ForegroundColor;
       
       this->Close();
}
//---------------------------------------------------------------------------

