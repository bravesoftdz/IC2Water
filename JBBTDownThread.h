//---------------------------------------------------------------------------

#ifndef JBBTDownThreadH
#define JBBTDownThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxButtons.hpp"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>
#include "GlobalParameter.h"
//---------------------------------------------------------------------------
class TJBBTDownThread : public TThread
{
private:
	TcxButton* ValidCSDownBTN;
    TcxButton* ValidJBDownBTN;
    TcxButton* ValidEBTN;
    TcxProgressBar* ValidJBProBar;
    TPanel* ValidJBBTPanel;
    TADOQuery* ValidJBADOQ;
protected:
	void __fastcall Execute();
public:
	__fastcall TJBBTDownThread(bool CreateSuspended,
    							TcxButton* CSDownBTN,
                                TcxButton* JBDownBTN,
                                TcxButton* EBTN,
                                TcxProgressBar* JBProBar,
                                TPanel* JBBTPanel,
                                TADOQuery* JBADOQ);
};
//---------------------------------------------------------------------------
#endif
