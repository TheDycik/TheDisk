//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UDiagrams.h"
#include "uLib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Charge(TObject *Sender)
{
	double X[NP];

	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Напряжения в диске");
	Chart1->Repaint();
	Chart1->LeftAxis->Title->Caption = "Sigma, МПа";

	for (int i = 0; i < NP; i++) {
		X[i] = A + i * (B-A)/NP;
	}

	Series2->LinePen->Visible = true;
	Series3->LinePen->Visible = true;
	Series4->LinePen->Visible = true;


	Series1->Title = "Радиальные напряжения";
	Series2->Title = "Кольцевые напряжения";
	Series3->Title = "Интенсивность напряжений";
	Series4->Title = "Допускаемые напряжения";

	Series1->Legend->Text =  "Радиальные напряжения";

	Series1->Legend->Visible = true;
	Series2->Legend->Visible = true;
	Series3->Legend->Visible = true;
	Series4->Legend->Visible = true;

	GRAPHIC_4(X,Sr,St,Si,SIGMAdop);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Strength(TObject *Sender)
{
	double X[NP];

	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Внутренние усилия в диске");
	Chart1->Repaint();
	Chart1->LeftAxis->Title->Caption = "Ns, Nt, Н/мм";

	for (int i = 0; i < NP; i++) {
		X[i] = A + i * (B-A)/NP;
	}

	Series2->LinePen->Visible = true;
	Series2->LinePen->Visible = true;
	Series3->LinePen->Visible = false;
	Series4->LinePen->Visible = false;

	Series1->Title = "Радиальные усилия";
	Series2->Title = "Кольцевые усилия";

	Series1->Legend->Text =  "Радиальные усилия";

	Series1->Legend->Visible = true;
	Series2->Legend->Visible = true;
	Series3->Legend->Visible = false;
	Series4->Legend->Visible = false;

	GRAPHIC_2(X,Nr,Nt);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Moving(TObject *Sender)
{
	double X[NP];

	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Радиальные перемещения");
	Chart1->Repaint();
	Chart1->LeftAxis->Title->Caption = "U, мм";

	for (int i = 0; i < NP; i++) {
		X[i] = A + i * (B-A)/NP;
	}
	Series1->LinePen->Visible = true;
	Series2->LinePen->Visible = false;
	Series3->LinePen->Visible = false;
	Series4->LinePen->Visible = false;



	Series1->Legend->Visible = true;
	Series2->Legend->Visible = false;
	Series3->Legend->Visible = false;
	Series4->Legend->Visible = false;

    Series1->Title = "Радиальные перемещения";
//	Series1->Legend->Text =  "Радиальные перемещения";

	GRAPHIC_1(X,U);
}
//---------------------------------------------------------------------------


