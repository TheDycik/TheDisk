//---------------------------------------------------------------------------

#pragma hdrstop

#include "uGeneral.h"
#include "UTables.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
MMY Y00, Y;
void COUNT(double Delta, bool &COUNT_complete, bool Condition){
	COUNT_complete = false;
	Kdinam =  DensM*pow(Omega,2)*1e-12;
	Form_Y00();
	RUNGE(A,B, NP,Y00, RightHandMember, Z);
	CC1 = (Pb*Hk-Z.arr[NP-1][2][2])/Z.arr[NP-1][1][2];
	//{Вычисляем компоненты НДС}
	CALC_NDS();
	//{Выполняем округление параметров НДС}
	TruncCalcResult();
	//{Отыскиваем максимальную интенсивность напряжений в диске}
	Found_SImax(SImax);

	COUNT_Complete=True;
	ControlStrengthDisk(Condition);

	if (!COUNT_Complete){
	 ShowMessage("Численный расчет не завершен.");
	}
	if (Sr[0]>0) {
	  ShowMessage("Численный расчет завершен. Конструкция диска неработоспобна! Между валом и диском образуется зазор.");
	} else
			if (Condition) {
				ShowMessage("Численный расчет завершен. Условие прочности диска выполняется.");
			} else {
				ShowMessage("Численный расчет завершен. Условие прочности диска не выполняется.");
			}
};
void Form_Y00(){

	double Kappa, Beta;

		if (H0/A > 0.6) {
		Kappa=1-0.5*exp(-H0/A);
		} else {
		Kappa=0.94*sqrt(H0/A);
		}

	Beta=Kappa*(1-Mu)*A/(E(Ta, E0)*H0);
	Y00.arr[1][1]=Beta;
	Y00.arr[1][2]=1;
	Y00.arr[2][1]=Delta/2+A*Alfa(Ta, Alfa0)*Ta;
	Y00.arr[2][2]=0;
};
void RightHandMember(double R, MMY Y, MMY (&V)){

  double Tr,Er,Hr,Teta;
  Tr=T(A,B,Ta,Tb,R);
  Er=E(Tr, E0);    Teta=Alfa(Tr, Alfa0)*Tr;
  Hr=HDisk(R,C,C1,Profile);
  //{ Учет однородных слагаемых }
  for (int i = 1; i < NV; i++) {
	  if (R == 0) {
		  V.arr[i][1]=(1-Mu)*Y.arr[i][2]/(Er*Hr);
		  V.arr[i][2]=0;
	  } else {
		  V.arr[i][1]=-Mu*Y.arr[i][1]/R +(1-Mu*Mu)*Y.arr[i][2]/(Er*Hr);
		  V.arr[i][2]=Er*Hr*Y.arr[i][1]/(R*R) -(1-Mu)*Y.arr[i][2]/R;
      }
  }
  // {Учет неоднородных слагаемых}
  if (R==0) {
	  V.arr[NV-1][1]=V.arr[NV-1][1]+Teta;
	  V.arr[NV-1][2]=V.arr[NV-1][2];
  } else {
	  V.arr[NV-1][1]=V.arr[NV-1][1] +(1+Mu)*Teta;
	  V.arr[NV-1][2]=V.arr[NV-1][2] -Kdinam*R*Hr -Er*Hr*Teta/R;
  }
};

void CALC_NDS(){
	double R,Er,Tr,Hr;
	for (int k = 0; k < NP; k++) {
	  R=A+k*(B-A)/(NP-1);
	  Hr=HDisk(R,C,C1,Profile);
	  Tr=T(A,B,Ta,Tb,R);
	  Er=E(Tr, E0);

	  U[k]=CC1*Z.arr[k][1][1]+Z.arr[k][2][1];
	  Nr[k]=CC1*Z.arr[k][1][2]+Z.arr[k][2][2];
	  Nt[k]=Mu*Nr[k]+Er*Hr*(U[k]/R-Alfa(Tr, Alfa0)*Tr);

	  Sr[k]=Nr[k]/Hr;
	  St[k]=Nt[k]/Hr;
	  Si[k]=sqrt(Sr[k]*Sr[k]-Sr[k]*St[k]+St[k]*St[k]);
	  EpsR[k]=(Sr[k]-Mu*St[k])/Er+Alfa(Tr, Alfa0)*Tr;
	  EpsT[k]=U[k]/R;

	}
}

void TruncCalcResult(){
	double EPS_4,EPS_6;
	 EPS_4=1E-4;
	 EPS_6=1E-6;
	for (int k = 0; k<NP; k++){
	  if (abs(Nr[k])<EPS_4) Nr[k]=0;
	  if (abs(Nt[k])<EPS_4) Nt[k]=0;
	  if (abs(Sr[k])<EPS_4) Sr[k]=0;
	  if (abs(St[k])<EPS_4) St[k]=0;
	  if (abs(Si[k])<EPS_4) Si[k]=0;
	  if (abs(U[k])<EPS_6) U[k]=0;
	  if (abs(EpsR[k])<EPS_6) EpsR[k]=0;
	  if (abs(EpsT[k])<EPS_6) EpsT[k]=0;
	 };
}

void Found_SImax(double &SImax){
  SImax=0;
  for (int i = 0; i < NP; i++) {
		if (SImax <Si[i]) SImax=Si[i];
  }
}

void ControlStrengthDisk(bool &Condition){
  Condition=true;
  for (int i = 0; i < NP; i++) {
	 if (Si[i] >1.001*SIGMAdop[i]) {
		Condition = false;
	 }
  }
}

double HDisk(double R, double C, double C1, int Profile){
	//  {Вычисление толщины диска}
	double H;
	H=H0;
	if (R>C1) {
		H = Hk;
	}
	if (R>=C&&R<=C1) {
		switch (Profile) {
			case 1: {
			 H=K1*R+K2;
			 break;
			}
			case 2: {
			H=K1+K2/R;
			break;
			}
			case 3: {
			H=K1+K2/(R*R);
			break;
			}
			case 4: {
			H=K1+K2*(R-C1)*(R-C1);
			break;
			}
			case 5: {
			H=K1*exp(-K2*R);
            break;
			}
		}
	}
	return H;
} ;
double Delta, Nr0,U0, A,B,C,H0,Hk,DensM,Ta,Tb,Pb,K1,K2,E0,Mu,Alfa0,Omega,SImax,MassD,MassD0,SigmaT0,NNT, C1,H1;
int HW0, WW0, NumberDisk, ColDisks;
bool COUNT_Complete;
int Profile;
double U[NP],Nr[NP],Nt[NP],Sr[NP],St[NP],Si[NP],SIGMAdop[NP],EpsR[NP],EpsT[NP];
MMMZ Z;
bool Condition;
double Kdinam, CC1;

