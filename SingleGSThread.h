//---------------------------------------------------------------------------

#ifndef SingleGSThreadH
#define SingleGSThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "GlobalParameter.h"
#include "cxListView.hpp"
#include "cxTL.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TSingleGSThread : public TThread
{
private:
	String Validkhstr;
	TcxListView* ValidGSListView;
	TADOQuery* ValidGSADOQuery;
	TcxButton* ValidGSB;
	TcxButton* ValidEB;
	int Validgstag;
protected:
	void __fastcall Execute();
public:
	__fastcall TSingleGSThread(bool CreateSuspended,
							   String khstr,
							   TcxListView* GSListView,
							   TADOQuery* GSADOQuery,
							   TcxButton* GSB,
							   TcxButton* EB,
							   int gstag);
};
//---------------------------------------------------------------------------
#endif
