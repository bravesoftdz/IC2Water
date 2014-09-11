//---------------------------------------------------------------------------

#ifndef CSBTDownThreadH
#define CSBTDownThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxButtons.hpp"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>
#include "GlobalParameter.h"
//---------------------------------------------------------------------------
class TCSBTDownThread : public TThread
{
private:
	TcxButton* ValidCSDownBTN;
    TcxButton* ValidJBDownBTN;
    TcxButton* ValidEBTN;
    TcxProgressBar* ValidCSProBar;
    TPanel* ValidCSBTPanel;
    TADOQuery* ValidCSADOQ;
protected:
	void __fastcall Execute();
public:
	__fastcall TCSBTDownThread(bool CreateSuspended,
    							TcxButton* CSDownBTN,
                                TcxButton* JBDownBTN,
                                TcxButton* EBTN,
                                TcxProgressBar* CSProBar,
                                TPanel* CSBTPanel,
                                TADOQuery* CSADOQ);
};
//---------------------------------------------------------------------------
#endif
