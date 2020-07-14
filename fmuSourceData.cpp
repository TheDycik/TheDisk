//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmuSourceData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfmSourceData *fmSourceData;
double DR, R;
//---------------------------------------------------------------------------
__fastcall TfmSourceData::TfmSourceData(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmSourceData::buNextClick(TObject *Sender)
{
    //исходная конструкция
		Nr0 = 0;
		U0 = 0;
		Delta = 0;
		//Profile = 0;

		//параметры диска при Т=0
		E0 = StrToFloat(edE->Text);
		Mu = StrToFloat(edMu->Text);
		SigmaT0 = StrToFloat(edSigmaT0->Text);
		Alfa0 = StrToFloat(edAlfa0->Text);
		DensM = StrToFloat(edDensM->Text);

		//параметры нагрузки и температуры
		Omega = StrToFloat(edOmega->Text);
		Pb = StrToFloat(edPb->Text);
		Ta = StrToFloat(edTa->Text); //Температура нагрева
		Tb = StrToFloat(edTb->Text); //Температура нагрева

		//конструктивные параметры
		A = StrToFloat(edA->Text);
		B = StrToFloat(edB->Text);
		C = StrToFloat(edC->Text);
		H0 = StrToFloat(edH0->Text);
		Hk = StrToFloat(edHk->Text);

		//величина натяга
		Delta = StrToFloat(edDelta->Text);

		//коэффициент запаса прочности
		NNT = StrToFloat(edNT->Text);

		//Определяем параметры начального (базового) профиля диска  Для базового профиля: profile=1,  c1=B, h1=hk
		 C = 60;
		 C1 = B;
		 H1 = Hk;
		 Profile = 1;
		 K1 = (H0-H1)/(C-C1);
		 K2 = H0-K1*C;

		 //Вычисляем допускаемые напряжения в узловых точках диска
		DR = (B - A)/NP;

		for (int i = 0; i <= NP; i++) {
			R = A + i*DR;
			SIGMAdop[i] = SigmaT(T(A,B,Ta,Tb,R), SigmaT0)/NNT;
		};

		//Параметры для начальной матрицы

		fmSourceData->Visible=false;
}
//---------------------------------------------------------------------------
