//---------------------------------------------------------------------------

#pragma hdrstop

#include "uLib.h"
#include "UDiagrams.h"
#include <Math.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
 void RUNGE(double X0, double Xn, int NP, MMY Y0, void F(double, MMY, MMY&), MMMZ (&Z))
 {
   MMY Y = {0};
   MMY Y1 = {0};

	MMY K1 = {0};
	MMY K2={0};
	MMY K3={0};
	MMY K4={0};
	double x,dx;
	dx=(Xn-X0)/(NP-1);
	x=X0;   Y=Y0;
  for (int i=1; i < NV; i++){
	 for (int j = 1; j < PD; j++) {
		 Z.arr[0][i][j]=Y0.arr[i][j];
	 }
  }
  for (int k = 1; k < NP; k++) {
	 F(x,Y,K1);
	 x=x+dx/2;
	 for (int i = 1; i < NV; i++) {
		for (int j = 1; j < PD; j++) {
		   Y1.arr[i][j]=Y.arr[i][j]+K1.arr[i][j]*dx/2;
		}
	 }
	  F(x,Y1,K2);
	  for (int i = 1; i <NV; i++) {
		for (int j = 1; j < PD; j++) {
		   Y1.arr[i][j]=Y.arr[i][j]+K2.arr[i][j]*dx/2;
		}
	 }
	  F(x,Y1,K3);
	  x=x+dx/2;
	 for (int i = 1; i <NV; i++) {
		for (int j = 1; j < PD; j++) {
		   Y1.arr[i][j]=Y.arr[i][j]+K3.arr[i][j]*dx;
		}
	 }
	  F(x,Y1,K4);
	  for (int i = 1; i < NV; i++) {
		for (int j = 1; j < PD; j++) {
			Y.arr[i][j]=Y.arr[i][j]+(K1.arr[i][j]+2*K2.arr[i][j]+2*K3.arr[i][j]
			+K4.arr[i][j])*dx/6;
			Z.arr[k][i][j]=Y.arr[i][j];
		}
	 }
  }
    int q = x*2;
 }
double T(double A, double B, double Ta, double Tb, double R){
   //—тационарное температурное поле в стенке толстостенного цилиндра
   double T;
   if (A == 0) {
	   T = Tb;
   } else {
	   T = Ta + (Tb - Ta)*log(R/A)/log(B/A);
   }
   return T;
}

double IncremXG,IncremYG,YGmax,YGmin, DX, Ymax, Ymin;

void DiagramParamemers2(double Ymin, double Ymax){
	double Y1min,Y1max,DY,Mas,C;
	int K;

	 YGmin = Ymin;
	 YGmax = Ymax;

	 if (YGmin == YGmax) {
		YGmin = YGmin - 5;
		YGmax = YGmax + 5;
		IncremYG = 1;
	 }

	 if (YGmin > 0) {
		 Y1min = YGmin * 0.99;
	 }
	 else{
		 Y1min = YGmin * 1.01;
	 }

	 if (YGmax > 0) {
		 Y1max = YGmax * 1.01;
	 }
	 else{
		 Y1max = YGmax * 0.99;
	 }

	 DY = Y1max - Y1min;
	 C = log10(DY);
	 if (C > 0) {
		 K = (int)C -1;
	 }
	 else{
		 K = (int)C - 2;
	 }

	 Mas = (10.0, K);
	 Y1min = Y1min/Mas;
	 Y1max = Ymax/Mas;
	 Y1min = (int)Y1min-1;
	 Y1max = (int)Y1max+1;

	 DY = Y1max-Y1min;

	 if (10 <= DY && DY < 20) {
		 IncremYG = 1;
	 }
	 if (20 <= DY && DY < 50) {
		 IncremYG = 2;
	 }
	 if (50 <= DY) {
		 IncremYG = 5;
	 }

	 YGmin = Y1min*Mas;     
	 YGmax = Y1max*Mas;
	 IncremYG = IncremYG*Mas;
	 
}

 void GRAPHIC_1(double X[], double Y[]){


	Ymin = 1E16;   
	Ymax = -1E16;

	for (int i = 0; i < NP; i++) {
		if (Y[i] < Ymin) { Ymin = Y[i]; }
		if (Y[i] > Ymax) { Ymax = Y[i]; }
	}

	 DiagramParamemers2(Ymin,Ymax);      
	 Form1->Series1->Clear();
	 Form1->Series2->Clear();
	 Form1->Series3->Clear();
	 Form1->Series4->Clear();
	 Form1->Chart1->LeftAxis->Maximum = 1E16;
	 Form1->Chart1->LeftAxis->Minimum = 1E-16;
	 Form1->Chart1->LeftAxis->Minimum = Ymin;
	 Form1->Chart1->LeftAxis->Maximum = Ymax;

	 for (int i = 0; i < 101; i++) {
		 Form1->Series1->AddXY(X[i],Y[i]);
	 }

	
}

void GRAPHIC_2(double X[], double Y1[], double Y2[]){

	Ymin = 1E16;   
	Ymax = -1E16;

	for (int i = 0; i < NP; i++) {
		if (Y1[i] < Ymin) { Ymin = Y1[i]; }
		if (Y1[i] > Ymax) { Ymax = Y1[i]; }
		if (Y2[i] < Ymin) { Ymin = Y2[i]; }
		if (Y2[i] > Ymax) { Ymax = Y2[i]; }
	}

	 DiagramParamemers2(Ymin,Ymax);      
	 Form1->Series1->Clear();
	 Form1->Series2->Clear();
	 Form1->Series3->Clear();
	 Form1->Series4->Clear();
	 Form1->Chart1->LeftAxis->Maximum = 1E16;
	 Form1->Chart1->LeftAxis->Minimum = 1E-16;
	 Form1->Chart1->LeftAxis->Minimum = Ymin;
	 Form1->Chart1->LeftAxis->Maximum = Ymax;

	 for (int i = 0; i < 100; i++) {
		 Form1->Series1->AddXY(X[i],Y1[i]);
		 Form1->Series2->AddXY(X[i],Y2[i]);
	 }

	
}


void GRAPHIC_4(double* X, double Y1[], double Y2[], double Y3[], double Y4[]){

	Ymin = 1E16;   
	Ymax = -1E16;

	
	
	for (int i = 0; i < NP; i++) {
		if (Y1[i] < Ymin) { Ymin = Y1[i]; }
		if (Y1[i] > Ymax) { Ymax = Y1[i]; }
		if (Y2[i] < Ymin) { Ymin = Y2[i]; }
		if (Y2[i] > Ymax) { Ymax = Y2[i]; }
		if (Y3[i] < Ymin) { Ymin = Y3[i]; }
		if (Y3[i] > Ymax) { Ymax = Y3[i]; }
		if (Y4[i] < Ymin) { Ymin = Y4[i]; }
		if (Y4[i] > Ymax) { Ymax = Y4[i]; }
	}

	int sr = Ymax - Ymin;
	
	 DiagramParamemers2(Ymin,Ymax);      
	 Form1->Series1->Clear();
	 Form1->Series2->Clear();
	 Form1->Series3->Clear();
	 Form1->Series4->Clear();
	 Form1->Chart1->LeftAxis->Maximum = 1E16;
	 Form1->Chart1->LeftAxis->Minimum = 1E-16;
	 Form1->Chart1->LeftAxis->Minimum = Ymin;
	 Form1->Chart1->LeftAxis->Maximum = Ymax;
//	 Form1->Chart1->BottomAxis->Maximum = X[NP];
//	 Form1->Chart1->BottomAxis->Minimum = X[0];



	 DX = X[NP]-X[0];


//	 if (DX < 4) { IncremXG = 0.1; }
//	 else if (DX < 10) { IncremXG = 0.5; }
//	 else if (DX < 25) { IncremXG = 1; }
//	 else if (DX < 50) { IncremXG = 2; }
//	 else if (DX < 100) { IncremXG = 5; }
//	 else if (DX < 250) { IncremXG = 10; }
//	 else if (DX < 500) { IncremXG = 20; }
//	 else if (DX < 1000) { IncremXG = 50; }
//	 else if (DX < 2500) { IncremXG = 100; }
//	 else if (DX < 5000) { IncremXG = 200; }
//	 else if (DX < 10000) { IncremXG = 500; }
//	 else { IncremXG = 1000; }


	 for (int i = 0; i < NP; i++) {
		 Form1->Series1->AddXY(X[i],Y1[i]);
		 Form1->Series2->AddXY(X[i],Y2[i]);
		 Form1->Series3->AddXY(X[i],Y3[i]);
		 Form1->Series4->AddXY(X[i],Y4[i]);
	 }

	
}

