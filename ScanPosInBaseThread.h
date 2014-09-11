//---------------------------------------------------------------------------

#ifndef ScanPosInBaseThreadH
#define ScanPosInBaseThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxButtons.hpp"
#include "cxListView.hpp"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>
#include "Globalparameter.h"

//---------------------------------------------------------------------------
class TSCanPosInBaseThread : public TThread
{
private:
	TADOQuery* ValidADOQ;
	TcxListView* ValidLV;
	TcxButton* ValidSSBTN;
	TcxButton* ValidSABTN;
	TcxButton* ValidAddBTN;
    TcxButton* ValidAddmBTN;
	TcxButton* ValidDelBTN;
	TcxButton* ValidExitBTN;
	TcxButton* ValidScanBTN;
    TcxButton* ValidSelABTN;
	TcxButton* ValidCalSABTN;
	TcxButton* ValidSABPBTN;
	bool* Validtag;
	TcxProgressBar* ValidProBar;

    String nodenamestr;
    POSPARA* nodepospara;
    WORD checkstatus;

    String displaynodenamestr;

protected:
	void __fastcall Execute();
    void __fastcall additemfun();
    void __fastcall adddisplayitemfun();
public:
	__fastcall TSCanPosInBaseThread(bool CreateSuspended,
									TADOQuery* ADOQ,
									TcxListView* LV,
									TcxButton* SSBTN,
							  		TcxButton* SABTN,
									TcxButton* AddBTN,
                                    TcxButton* AddmBTN,
									TcxButton* DelBTN,
									TcxButton* ExitBTN,
									TcxButton* ScanBTN,
                                    TcxButton* SelABTN,
									TcxButton* CalSABTN,
									TcxButton* SABPBTN,
									bool* tag,
									TcxProgressBar* ProBar);
};
//---------------------------------------------------------------------------
#endif
