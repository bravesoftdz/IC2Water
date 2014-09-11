//---------------------------------------------------------------------------

#ifndef SetAllPosParamThreadH
#define SetAllPosParamThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxButtons.hpp"
#include "cxListView.hpp"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>
#include "Globalparameter.h"
//---------------------------------------------------------------------------
class TSetAllPosParamThread : public TThread
{
private:
	TADOQuery* ValidADOQ;
	TcxListView* ValidLV;
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
    TCheckBox* ValidCheckBox;

protected:
	void __fastcall Execute();
public:
	__fastcall TSetAllPosParamThread(bool CreateSuspended,
									 TADOQuery* ADOQ,
									 TcxListView* LV,
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
                                     TCheckBox* CheckBox);
};
//---------------------------------------------------------------------------
#endif
