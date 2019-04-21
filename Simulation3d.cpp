//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Simulation3d.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int numberOfPoints = 0;
int a = 50;
float** object;

static float zvp = 4.2, zprp = 250;

static int startX, startY;
static bool clicked = false, keyDown = false;
static int autoRotateDirection;

TForm2* colorSelector;

//extern int colorModel = clRed;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        colorSelector = new TForm2(this);
}

void drawProjection(){
    Form1->Refresh();
    Form1->Canvas->Pen->Color = colorSelector->colorSelected;
    TPoint* points = new TPoint[numberOfPoints];

    for(int i=0; i<numberOfPoints; i++){
    	points[i].x = Form1->Width/2 + object[i][0]*(zprp - zvp)/((float)(zprp - object[i][2]));
        points[i].y = Form1->Height/2 + object[i][1]*(zprp - zvp)/((float)(zprp - object[i][2]));
    }

    Form1->Canvas->Polygon(points, numberOfPoints - 1);
}

void rotateProjection(int about, float A=0.1){
        if(about == 0){
 	        for(int i=0; i<numberOfPoints; i++){
    	                float tempX = object[i][2]*cos(A) - object[i][0]*sin(A);
                        float tempY = object[i][2]*sin(A) + object[i][0]*cos(A);
    	                object[i][2] = tempX;
                        object[i][0] = tempY;
                }
        }
        if (about == 1){
                for(int i=0; i<numberOfPoints; i++){
    	                float tempX = object[i][0]*cos(A) - object[i][1]*sin(A);
                        float tempY = object[i][0]*sin(A) + object[i][1]*cos(A);
    	                object[i][0] = tempX;
                        object[i][1] = tempY;
                }
        }
        if(about == 2){
                for(int i=0; i<numberOfPoints; i++){
    	                float tempX = object[i][1]*cos(A) - object[i][2]*sin(A);
                        float tempY = object[i][1]*sin(A) + object[i][2]*cos(A);
    	                object[i][1] = tempX;
                        object[i][2] = tempY;
                }
        }
}

void scaleProjection(float scaleX, float scaleY, float scaleZ){
        for(int i=0; i<numberOfPoints; i++){
    	        object[i][0] *= scaleX;
                object[i][1] *= scaleY;
                object[i][2] *= scaleZ;
        }
}

void translateProjection(float X, float Y, float Z){
       for(int i=0; i<numberOfPoints; i++){
    	        object[i][0] += X;
                object[i][1] += Y;
                object[i][2] += Z;
        }
}

void initializeCube(){
        if(object != NULL){
        for(int i = 0; i < numberOfPoints; ++i) {
                delete [] object[i];
        }
        delete [] object;
        }

        numberOfPoints = 20;
        //const int tempn = 20;
        object = new float*[numberOfPoints];
        for(int i = 0; i < numberOfPoints; ++i)
                object[i] = new float[3];

        object[0][0] = -a;      object[0][1]  = a;      object[0][2]  = a;
        object[1][0] = a;       object[1][1]  = a;      object[1][2]  = a;
        object[2][0] = a;       object[2][1]  = -a;     object[2][2]  = a;
        object[3][0] = -a;      object[3][1]  = -a;     object[3][2]  = a;
        object[4][0] = -a;      object[4][1]  = a;      object[4][2]  = a;
        object[5][0] = -a;      object[5][1]  = a;      object[5][2]  = -a;
        object[6][0] = a;       object[6][1]  = a;      object[6][2]  = -a;
        object[7][0] = a;       object[7][1]  = -a;     object[7][2]  = -a;
        object[8][0] = -a;      object[8][1]  = -a;     object[8][2]  = -a;
        object[9][0] = -a;      object[9][1]  = a;      object[9][2]  = -a;
        object[10][0] = a;      object[10][1] = a;      object[10][2] = -a;
        object[11][0] = a;      object[11][1] = -a;     object[11][2] = -a;
        object[12][0] = a;      object[12][1] = -a;     object[12][2] = a;
        object[13][0] = a;      object[13][1] = a;      object[13][2] = a;
        object[14][0] = a;      object[14][1] = a;      object[14][2] = -a;
        object[15][0] = -a;     object[15][1] = a;      object[15][2] = -a;
        object[16][0] = -a;     object[16][1] = a;      object[16][2] = a;
        object[17][0] = -a;     object[17][1] = -a;     object[17][2] = a;
        object[18][0] = -a;     object[18][1] = -a;     object[18][2] = -a;
        object[19][0] = -a;     object[19][1] = a;      object[19][2] = -a;

        drawProjection();
}

void initializePyramid(){
        if(object != NULL){
        for(int i = 0; i < numberOfPoints; ++i) {
                delete [] object[i];
        }
        delete [] object;
        }

        numberOfPoints = 11;
        //const int tempn = 20;
        object = new float*[numberOfPoints];
        for(int i = 0; i < numberOfPoints; ++i)
                object[i] = new float[3];

        object[0][0] = a;       object[0][1]  = a;      object[0][2]  = 0;
        object[1][0] = -a;      object[1][1]  = a;      object[1][2]  = 0;
        object[2][0] = -a;      object[2][1]  = -a;     object[2][2]  = 0;
        object[3][0] = a;       object[3][1]  = -a;     object[3][2]  = 0;
        object[4][0] = a;       object[4][1]  = a;      object[4][2]  = 0;
        object[5][0] = 0;       object[5][1]  = 0;      object[5][2]  = 2*a;
        object[6][0] = a;       object[6][1]  = -a;     object[6][2]  = 0;
        object[7][0] = 0;       object[7][1]  = 0;      object[7][2]  = 2*a;
        object[8][0] = -a;      object[8][1]  = -a;     object[8][2]  = 0;
        object[9][0] = 0;       object[9][1]  = 0;      object[9][2]  = 2*a;
        object[10][0] = -a;     object[10][1] = a;      object[10][2] = 0;

        drawProjection();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        initializeCube();
        autoRotateDirection = 2;
        Form1->Timer1->Enabled = true;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
        scaleProjection(1.1, 1.1, 1.1);
        drawProjection();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
        scaleProjection(0.9, 0.9, 0.9);
        drawProjection();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        startX = X;
        startY = Y;
        clicked = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        int dx = abs(X - startX);
        int dy = abs(Y - startY);
        if(clicked){

                if(keyDown){
                        if(dx > dy && X > startX){
                                autoRotateDirection = 3;
                                Form1->Timer1->Enabled = true;
                        }
                        if(dx > dy && X < startX){
                                 autoRotateDirection = 0;
                                 Form1->Timer1->Enabled = true;
                                 }
                        if(dx <= dy && Y>startY){
                                 autoRotateDirection = 2;
                                Form1->Timer1->Enabled = true;
                                }
                        if(dx <= dy && Y<startY){
                                 autoRotateDirection = 1;
                                Form1->Timer1->Enabled = true;
                                }
                }else{
                        if(X>startX)
                                rotateProjection(0, 0.02);
                        if(X < startX)
                                rotateProjection(0, -0.02);
                        if(Y>startY)
                                rotateProjection(2,-0.02);
                        if(Y<startY)
                                rotateProjection(2,0.02);
                }

                drawProjection();
                startX = X;
                startY = Y;
        }



}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        autoRotateDirection = 0;
        Form1->Timer1->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        clicked = false;

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image2Click(TObject *Sender)
{
        initializePyramid();
        rotateProjection(2,0.8);
        drawProjection();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1Click(TObject *Sender)
{
        initializeCube();
        rotateProjection(0,0.5);
        drawProjection();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        if(!clicked){
                if(autoRotateDirection == 0){
                        rotateProjection(0,-0.1);
                        drawProjection();
                }
                if(autoRotateDirection == 1){
                        rotateProjection(2,+0.1);
                        drawProjection();
                }
                if(autoRotateDirection == 2){
                        rotateProjection(2,-0.1);
                        drawProjection();
                }
                if(autoRotateDirection == 3){
                        rotateProjection(0,0.1);
                        drawProjection();
                }
        }

        else
               Form1->Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
         autoRotateDirection = 1;
        Form1->Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
         autoRotateDirection = 2;
        Form1->Timer1->Enabled = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
         autoRotateDirection = 3;
        Form1->Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        keyDown = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key = VK_SHIFT );
                        keyDown = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyPress(TObject *Sender, char &Key)
{
        //keyDown = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDblClick(TObject *Sender)
{
        //keyDown = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Custom1Click(TObject *Sender)
{
        colorSelector->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormActivate(TObject *Sender)
{
        drawProjection();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Red1Click(TObject *Sender)
{
        colorSelector->colorSelected = clRed;
        drawProjection();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Green1Click(TObject *Sender)
{
        colorSelector->colorSelected = clGreen;
        drawProjection();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Blue1Click(TObject *Sender)
{
        colorSelector->colorSelected = clBlue;
        drawProjection();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Fo1Click(TObject *Sender)
{
        initializePyramid();
        rotateProjection(2,0.8);
        drawProjection();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::No1Click(TObject *Sender)
{
        initializeCube();
        rotateProjection(0,0.5);
        drawProjection();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Controls1Click(TObject *Sender)
{
        Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BounceSimulation1Click(TObject *Sender)
{
        Form4->Show();
}
//---------------------------------------------------------------------------

