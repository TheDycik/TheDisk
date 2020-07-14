//---------------------------------------------------------------------------

#ifndef uGeneralH
#define uGeneralH
#include "uLib.h"
#include <Math.hpp>
#include "uMaterial.h"
#include "fmuSourceData.h"
//---------------------------------------------------------------------------
		extern int HW0, WW0, NumberDisk, ColDisks;
		extern bool COUNT_Complete;
		extern double U[NP],Nr[NP],Nt[NP],Sr[NP],St[NP],Si[NP],SIGMAdop[NP],EpsR[NP],EpsT[NP];
		extern double Delta, Nr0,U0, A,B,C,H0,Hk,DensM,Ta,Tb,Pb,K1,K2,E0,Mu,Alfa0,Omega,SImax,MassD,MassD0,SigmaT0,NNT, C1,H1;
		extern int Profile;
		extern  MMMZ Z;

		double WorkingStress;  //Допускаемое напряжение
		extern bool Condition;        //Маркер успешного завершения расчета
	   //	void RightHandMember(double R, MMY Y, MMY V);
//		MMMZ Z;
		void COUNT(double Delta, bool &COUNT_complete, bool Condition);
		void Form_Y00();
		void TruncCalcResult();
		void Found_SImax(double &SImax);
		void ControlStrengthDisk(bool &Condition);
		double HDisk(double R, double C, double C1, int Profile);
        void CALC_NDS();
		MMY V;
		void RightHandMember(double R, MMY Y, MMY (&V));
		//

		extern double Kdinam, CC1;
#endif

