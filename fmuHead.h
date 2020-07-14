//---------------------------------------------------------------------------

#ifndef fmuHeadH
#define fmuHeadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include "fmuSourceData.h"
#include "uGeneral.h"
#include "UDiagrams.h"
#include <FMX.Layouts.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <System.Rtti.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TfmHead : public TForm
{
__published:	// IDE-managed Components
	TTabControl *tc;
	TTabItem *tcMain;
	TTabItem *tcInitialData;
	TTabItem *tcCalc;
	TTabItem *tcResult;
	TLabel *Label1;
	TGridPanelLayout *GridPanelLayout1;
	TStyleBook *StyleBook1;
	TLayout *Layout1;
	TGridPanelLayout *GridPanelLayout2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TTabItem *TabItem1;
	TButton *Button4;
	TGridPanelLayout *GridPanelLayout3;
	void __fastcall tcInitialDataClick(TObject *Sender);
	void __fastcall tcCalcClick(TObject *Sender);
	void __fastcall tcResultClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfmHead(TComponent* Owner);
//    void drawDisk();
};
//---------------------------------------------------------------------------
extern PACKAGE TfmHead *fmHead;
//---------------------------------------------------------------------------
#endif
