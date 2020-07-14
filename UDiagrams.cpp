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
	Chart1->Title->Text->Add("���������� � �����");
	Chart1->Repaint();
	Chart1->LeftAxis->Title->Caption = "Sigma, ���";

	for (int i = 0; i < NP; i++) {
		X[i] = A + i * (B-A)/NP;
	}

	Series2->LinePen->Visible = true;
	Series3->LinePen->Visible = true;
	Series4->LinePen->Visible = true;


	Series1->Title = "���������� ����������";
	Series2->Title = "��������� ����������";
	Series3->Title = "������������� ����������";
	Series4->Title = "����������� ����������";

	Series1->Legend->Text =  "���������� ����������";

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
	Chart1->Title->Text->Add("���������� ������ � �����");
	Chart1->Repaint();
	Chart1->LeftAxis->Title->Caption = "Ns, Nt, �/��";

	for (int i = 0; i < NP; i++) {
		X[i] = A + i * (B-A)/NP;
	}

	Series2->LinePen->Visible = true;
	Series2->LinePen->Visible = true;
	Series3->LinePen->Visible = false;
	Series4->LinePen->Visible = false;

	Series1->Title = "���������� ������";
	Series2->Title = "��������� ������";

	Series1->Legend->Text =  "���������� ������";

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
	Chart1->Title->Text->Add("���������� �����������");
	Chart1->Repaint();
	Chart1->LeftAxis->Title->Caption = "U, ��";

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

    Series1->Title = "���������� �����������";
//	Series1->Legend->Text =  "���������� �����������";

	GRAPHIC_1(X,U);
}
//---------------------------------------------------------------------------


