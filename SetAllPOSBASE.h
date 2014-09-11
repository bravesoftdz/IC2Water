//---------------------------------------------------------------------------

#ifndef SetAllPOSBASEH
#define SetAllPOSBASEH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxButtons.hpp"
#include "cxProgressBar.hpp"
#include "cxListView.hpp"
#include <ADODB.hpp>
#include "Globalparameter.h"
//---------------------------------------------------------------------------
class TSetAllPOSBaseThread : public TThread
{
private:
	int Validcomn;
	int Validmax;
	int Validdmax;
	String Validpw;
	bool Validdinc;
	bool Validqkbt;
	bool Validmmax;
	int Validmmaxcs;
	TADOQuery* ValidADOQ;
	TcxButton* ValidSABTN;
	TcxButton* ValidSSBTN;
	TcxButton* ValidDelBTN;
	TcxButton* ValidAddBTN;
	TcxButton* ValidAddMBTN;
	TcxButton* ValidScanBTN;
	TcxButton* ValidEndBTN;
	TcxButton* ValidExitBTN;
	TcxButton* ValidSelABTN;
	TcxButton* ValidCalSABTN;
	TcxButton* ValidSABPBTN;
	TcxProgressBar* ValidProBar;
	TcxListView* ValidLV;
protected:
	void __fastcall Execute();
public:
	__fastcall TSetAllPOSBaseThread(bool CreateSuspended,
									int comn,
									int max,
									int dmax,
									String pw,
									bool dinc,
									bool qkbt,
									bool mmax,
									int mmaxcs,
									TADOQuery* ADOQ,
									TcxButton* SABTN,
									TcxButton* SSBTN,
									TcxButton* DelBTN,
									TcxButton* AddBTN,
									TcxButton* AddMBTN,
									TcxButton* ScanBTN,
									TcxButton* EndBTN,
									TcxButton* ExitBTN,
									TcxButton* SelABTN,
									TcxButton* CalSABTN,
									TcxButton* SABPBTN,
									TcxProgressBar* ProBar,
									TcxListView* LV);
};
//---------------------------------------------------------------------------
#endif
