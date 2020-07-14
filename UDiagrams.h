//---------------------------------------------------------------------------

#ifndef UDiagramsH
#define UDiagramsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Types.hpp>
#include <FMXTee.Chart.hpp>
#include <FMXTee.Engine.hpp>
#include <FMXTee.Procs.hpp>
#include <FMXTee.Series.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include "uLib.h"
#include "uGeneral.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TRadioButton *Напряжения;
	TRadioButton *Усилия;
	TRadioButton *Перемещения;
	TStyleBook *StyleBook1;
	TChart *Chart1;
	TLineSeries *Series1;
	TLineSeries *Series2;
	TLineSeries *Series3;
	TLineSeries *Series4;
	void __fastcall Charge(TObject *Sender);
	void __fastcall Strength(TObject *Sender);
	void __fastcall Moving(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
