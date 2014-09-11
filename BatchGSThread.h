//---------------------------------------------------------------------------

#ifndef BatchGSThreadH
#define BatchGSThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "GlobalParameter.h"
#include "cxProgressBar.hpp"
#include "cxTL.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TBatchGSThread : public TThread
{
private:
	TADOQuery* ValidGSQuery;
	TADOQuery* ValidOPQuery;
	TcxProgressBar* ValidCProgressBar;
	TcxButton* ValidQBTN;
	TcxButton* ValidGBTN;
	TcxButton* ValidEBTN;
	String Validsqlinthread;
protected:
	void __fastcall Execute();
public:
	__fastcall TBatchGSThread(bool CreateSuspended,
							  TADOQuery* GSQuery,
							  TADOQuery* OPQuery,
							  TcxProgressBar* CProgressBar,
							  TcxButton* QBTN,
							  TcxButton* GBTN,
							  TcxButton* EBTN,
							  String sqlinthread);
};
//---------------------------------------------------------------------------
#endif
