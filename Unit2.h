//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CGRID.h"
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TCColorGrid *CColorGrid1;
        void __fastcall CColorGrid1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
        int colorSelected;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
