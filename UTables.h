//---------------------------------------------------------------------------

#ifndef UTablesH
#define UTablesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Types.hpp>
#include <System.Rtti.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Layouts.hpp>
//---------------------------------------------------------------------------
class Tfmt : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TFloatColumn *FloatColumn1;
	TFloatColumn *FloatColumn2;
	TFloatColumn *FloatColumn3;
	TFloatColumn *FloatColumn4;
	TFloatColumn *FloatColumn5;
	TFloatColumn *FloatColumn6;
	TFloatColumn *FloatColumn7;
	TRadioButton *rb1;
	TRadioButton *rb2;
	TRadioButton *rb3;
	TRadioButton *rb4;
	TToolBar *ToolBar1;
	TGridPanelLayout *GridPanelLayout1;
	void __fastcall rb1MouseMove(TObject *Sender, TShiftState Shift, float X, float Y);

private:	// User declarations
	int Ncol;

public:		// User declarations
	void FormTablDeformation();
	void FormTablStress();
	void FormTablDisplacement()  ;
	void FormTablForces();
	void ClearTab();
	__fastcall Tfmt(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfmt *fmt;
//---------------------------------------------------------------------------
#endif
