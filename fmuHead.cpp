//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmuHead.h"
#include "UTables.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfmHead *fmHead;
//---------------------------------------------------------------------------
__fastcall TfmHead::TfmHead(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmHead::tcInitialDataClick(TObject *Sender)
{
   fmSourceData->Show();
}
//---------------------------------------------------------------------------
void __fastcall TfmHead::tcCalcClick(TObject *Sender)
{
	COUNT(Delta, COUNT_Complete, Condition);
//	if (Sr[0]<0 && Condition){
//
//	  MassDisk(A,B, MassD0);
//
//	  //Çàïèñûâàåì ðåçóëüòàòû ðàñ÷åòà áàçîâîãî äèñêà â áàçó äèñêîâ
//	  NumberDisk:=0;   ColDisks:=1;
//	  Disk[0].Number:=0;                              //Íîìåð áàçîâîãî äèñêà
//	  Disk[0].Profile:=1;                             //Ïðîôèëü áàçîâîãî äèñêà
//	  Disk[0].Delta :=Delta;                          //Âåëè÷èíà íàòÿãà, ìì
//	  Disk[0].C1    :=C1;                             //Ðàäèóñ C1, ìì
//	  Disk[0].H1    :=H1;                             //Ðàäèóñ H1, ìì
//	  Disk[0].MassD :=MassD0;                         //Ìàññà äèñêà, êã
//	  Disk[0].MassD_MassD0:=1;                        //Îòíîøåíèå ìàññû òåêóùåãî äèñêà ê ìàññå èñõîäíîãî äèñêà
//	}

}
//---------------------------------------------------------------------------
//void drawDisk(){
//	int X0,Y0,Xk,Yk,FieldX,FieldY,Lx,Ly,Lp,Ld,i,dy;
//	int Xa1,Xa2,Xc1,Xc2,Xb1,Xb2,Ya1,Ya2,Yc1,Yc2,Yb1,Yb2,x,y,x1,y1;
//	double Mas,MasX,MasY,R,H,DR;
//	String S;
//
//  C1=B;
//  FieldX=20;      FieldY=20;     Lp=20;     Ld=40;
//  Lx=fmHead->layout->Width -2*FieldX -100;
//  Ly=fmHead->layout->Height -2*FieldY;
//  MasX:=Lx/(A+B+Lp);
//  MasY:=Ly/(2*H0+Ld);
//  Mas:=MasX;                     if MasY<Mas then Mas:=MasY;         //pixel/ìì
//  X0:=FieldX +round(Mas*A) +30;
//  Y0:=(FHead.Image1.Height-Ld) div 2;
//  Xk:=FHead.Image1.Width;  Yk:=FHead.Image1.Height;
//
//  Xa1:=X0+round(Mas*A);  Ya1:=Y0-round(Mas*H0/2);
//  Xa2:=Xa1;              Ya2:=Y0+round(Mas*H0/2);
//  Xc1:=X0+round(Mas*C);  Yc1:=Y0-round(Mas*H0/2);
//  Xc2:=Xc1;              Yc2:=Y0+round(Mas*H0/2);
//  Xb1:=X0+round(Mas*B);  Yb1:=Y0-round(Mas*Hk/2);
//  Xb2:=Xb1;              Yb2:=Y0+round(Mas*Hk/2);

//};

void __fastcall TfmHead::tcResultClick(TObject *Sender)
{

	fmt->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfmHead::FormCreate(TObject *Sender)
{
		tc->ActiveTab = tcMain;
		tc->TabPosition = TTabPosition::None;
}

//---------------------------------------------------------------------------

void __fastcall TfmHead::Button4Click(TObject *Sender)
{
         Form1->Show();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


