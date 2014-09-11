//---------------------------------------------------------------------------

#ifndef PostAllCardLostInfoThreadH
#define PostAllCardLostInfoThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxButtons.hpp"
#include "cxListView.hpp"
#include "cxProgressBar.hpp"
#include "GlobalParameter.h"
#include <ADODB.hpp>

//---------------------------------------------------------------------------
class TPostAllCardLostInfoThread : public TThread
{
private:
	TcxButton* ValidAllBTN;
	TcxButton* ValidGSBTN;
	TcxButton* ValidExitBTN;
	TcxProgressBar* ValidPorBar;
	TcxListView* ValidListV;
	TADOQuery* ValidADOQ;
protected:
	void __fastcall Execute();
public:
	__fastcall TPostAllCardLostInfoThread(bool CreateSuspended,
										  TcxButton* AllBTN,
										  TcxButton* GSBTN,
										  TcxButton* EBTN,
										  TcxProgressBar* ProBar,
										  TcxListView* ListV,
										  TADOQuery* ADOQ);
};
//---------------------------------------------------------------------------
#endif
