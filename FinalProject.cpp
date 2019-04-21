#include <vcl.h>
#pragma hdrstop
#include "FinalProject.h"
#pragma package(smart_init)
#pragma link "CGRID"
#pragma link "cdiroutl"
#pragma resource "*.dfm"
#define pencil 0
#define rectangle 1
#define ellipse 2
#define eraser 3
#define bucket 4
#define line 5
TForm1 *Form1;

//---------------------------------------------------------------------------

bool clicked = false;
int mode = pencil;
int foregroundColor = clBlack;
int backgroundColor;
bool drawing = false; int oldX; int oldY;



//*******************************
//float[][] multiplyMatrix(float A[][], float B[][], int m, int n, int p, int q)
int startX, startY;

void fill(int x, int y, int fillColor, int regionColor){
        int color = Form1->Canvas->Pixels[x][y];
        if(color != fillColor && color == regionColor){
        Form1->Canvas->Pixels[x][y] = fillColor;
        fill(x+1,y, fillColor, regionColor);
        fill(x,y+1,  fillColor, regionColor);
        fill(x-1,y,  fillColor, regionColor);
        fill(x,y-1,  fillColor, regionColor);}
}

void eraseCanvas(int X, int Y){
        Form1->Canvas->Pen->Color = clWhite;
                //Form1->Canvas->Rectangle(X-5, Y-5, X+5, Y+5);
                for(int i=X-5; i <X+5; i++){
                        for(int j=Y-5; j<Y+5; j++){
                                Form1->Canvas->Pixels[i][j] = clWhite;
                        }
                }
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        clicked = true;
        //Form1->Canvas->MoveTo(X, Y);

        startX = X;
        startY = Y;
      //Form1->Canvas->Rectangle(startX,startY,oldX,oldY);
      //drawing = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        clicked = false;
        if(mode == bucket){
                int colortemp = Form1->Canvas->Pixels[X][Y];
                if(startX == X && startY == Y)
                        fill(X, Y, foregroundColor, colortemp);
        }

        if(mode == eraser){
                eraseCanvas(X,Y);
        }

        if(mode == rectangle){
                Canvas->Pen->Color = foregroundColor;
                Form1->Canvas->MoveTo(startX, startY);
                Form1->Canvas->LineTo(X,startY);
                Form1->Canvas->LineTo(X, Y);
                Form1->Canvas->LineTo(startX, Y);
                Form1->Canvas->LineTo(startX, startY);
        }

        if(mode == ellipse){
                Canvas->Pen->Color = foregroundColor;
                Form1->Canvas->Ellipse(startX,startY,X,Y);
        }

        if(mode == line){
                Canvas->Pen->Color = foregroundColor;
                Canvas->MoveTo(startX, startY);
                Canvas->LineTo(X,Y);
        }

        //Canvas->Pen->Color = clRed;
        //Form1->Canvas->Rectangle(startX, startY, X, Y);
        //Form1->Canvas->Ellipse(X,Y,X+60,Y+60);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        mode = pencil;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
       if(clicked){
                if(mode == pencil){
                        Form1->Canvas->Pen->Color  = foregroundColor;
                        Form1->Canvas->MoveTo(startX,startY);
                        Form1->Canvas->LineTo(X,Y);
                        startX = X; startY = Y;
                        //Screen->Cursor = 4;
                }

                if(mode == eraser){
                        eraseCanvas(X,Y);
                }
        }


}
//---------------------------------------------------------------------------


void __fastcall TForm1::CColorGrid1Change(TObject *Sender)
{
        foregroundColor = CColorGrid1->ForegroundColor;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
        Form1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
        //Form1->Canvas->TextOutA(5,5, Shift);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        mode = rectangle;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        mode = ellipse;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        mode = bucket;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        mode = line;
}
//---------------------------------------------------------------------------


/*void __fastcall TForm1::Image2Click(TObject *Sender)
{
        mode = ellipse;        
} */
//---------------------------------------------------------------------------

/*void __fastcall TForm1::Image3Click(TObject *Sender)
{
        mode = line;
}*/
//---------------------------------------------------------------------------

/*void __fastcall TForm1::Image1Click(TObject *Sender)
{
        mode = rectangle;
} */
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
        mode = eraser;
}
//---------------------------------------------------------------------------

