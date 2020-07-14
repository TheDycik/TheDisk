//---------------------------------------------------------------------------

#ifndef fmuSourceDataH
#define fmuSourceDataH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include "uGeneral.h"
//---------------------------------------------------------------------------
class TfmSourceData : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TEdit *edE;
	TEdit *edMu;
	TEdit *edSigmaT0;
	TEdit *edAlfa0;
	TEdit *edDensM;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *laE;
	TGroupBox *GroupBox2;
	TEdit *edOmega;
	TEdit *edPb;
	TEdit *edTa;
	TEdit *edTb;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TGroupBox *GroupBox3;
	TEdit *edA;
	TEdit *edB;
	TEdit *edC;
	TEdit *edH0;
	TEdit *edHk;
	TEdit *edDelta;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TLabel *Label32;
	TLabel *Label33;
	TGroupBox *GroupBox5;
	TLabel *Label34;
	TLabel *Label36;
	TEdit *edNT;
	TButton *buCancel;
	TButton *buNext;
	TStyleBook *StyleBook1;
	TToolBar *ToolBar1;
	TImage *Image1;
	void __fastcall buNextClick(TObject *Sender);
private:	// User declarations
public:
		// User declarations
	__fastcall TfmSourceData(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmSourceData *fmSourceData;
extern double DR, R;
//---------------------------------------------------------------------------
#endif
