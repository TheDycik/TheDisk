//---------------------------------------------------------------------------

#ifndef uLibH
#define uLibH
//#include "uGeneral.h"
//#include "uGeneral.h"
//#include "uGeneral.h"
#include <FMXTee.Chart.hpp>

//---------------------------------------------------------------------------
	static const int NP = 101;  	//����� ����� �������������� �� ������� [A,B]
	static const int NV = 3;    	//����� �������� � ������� ������� ������� ���. ���������
	static const int PD = 3;    	//������� ������� ���������������� ���������

	struct Vector{
	 double arr[PD];
	};

	struct MMY{
	 double arr[NV][PD];  		//{������� Y}
	};

	struct MMMZ{
	 double arr[NP][NV][PD];    //{������ ������� ������� ���. ���������}
	};

   //	extern void (*procRUNGE)(double X, MMY Y, MMY KI);    //{������ ������� ������� ���. ���������}


	void RUNGE(double X0, double Xn, int NP, MMY Y0, void(double, MMY, MMY&), MMMZ (&Z));
   //	String CONVERT(float A, int LA, int Prec,int Digit);
	double MP[NP];
	double T(double a, double b, double ta, double tb, double r);
	void GRAPHIC_4(double X[], double Y1[], double Y2[], double Y3[], double Y4[]);
	void GRAPHIC_1(double X[], double Y[]);
	void GRAPHIC_2(double X[], double Y1[], double Y2[]);

#endif
