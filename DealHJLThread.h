//---------------------------------------------------------------------------

#ifndef DealHJLThreadH
#define DealHJLThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxTL.hpp"
#include "cxProgressBar.hpp"
#include "GlobalParameter.h"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDealHJLThread : public TThread
{
private:
	TcxButton* ValidEBTN;
	TcxProgressBar* ValidPBar;
	TADOQuery* ValidADOQ;
	TADOQuery* ValidDADOQ;
protected:
	void __fastcall Execute();
public:
	__fastcall TDealHJLThread(bool CreateSuspended,
							  TcxButton* EBTN,
							  TcxProgressBar* PBar,
							  TADOQuery* ADOQ,
							  TADOQuery* DADOQ);
};
//---------------------------------------------------------------------------
#endif
