//---------------------------------------------------------------------------

#pragma hdrstop

#include "uMaterial.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

double E(double T, double E0){
	double E = E0 - 140*T;
	return E;
};

double Alfa(double T, double Alfa0){
	double Alfa = Alfa0 + 5E-9*T;
	return Alfa;
};

double SigmaT(double T, double SigmaT0){
	double SigmaT = SigmaT0 - 0.1143*T;
	return SigmaT;
}
