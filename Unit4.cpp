//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define down 0
#define up 1
TForm4 *Form4;

float X, Y;
static float maxHeight;
float xMove=1, yMove=2;
int state;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
        X = Shape1->Left;
        Y = Shape1->Top;
        maxHeight = Form4->Height;
        state = down;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormCreate(TObject *Sender)
{
        Form4->Timer1->Enabled = True;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Timer1Timer(TObject *Sender)
{


        //Form4->Refresh();
        Shape1->Left = X;
        Shape1->Top = Y;

        if(state == down){
                X  = X + 0.5;
                Y  = Y + 2;
                if( Y >= 300 ){
                        //maxHeight = maxHeight / 2;
                        state = up;
                }
        }

        if(state == up){
                X  = X + 0.5;
                Y  = Y - 2;
                if( Y < maxHeight/2 ){
                        state = down;
                        maxHeight = maxHeight / 2;
                }
        }
}
//---------------------------------------------------------------------------

