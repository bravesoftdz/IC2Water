//---------------------------------------------------------------------------

#ifndef CreateCSBTThreadH
#define CreateCSBTThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxButtons.hpp"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>
#include "GlobalParameter.h"

//---------------------------------------------------------------------------
class TCreateCSBTThread : public TThread
{
private:
	TcxButton* ValidCSBTN;
    TcxButton* ValidJEBTN;
    TcxButton* ValidJBBTN;
    TcxButton* ValidEBTN;
    TcxProgressBar* ValidCSProBar;
    TADOQuery* ValidCSADOQ;
    TADOQuery* ValidCSInADOQ;
    String ValidBeginstr;
    String ValidEndstr;
    int Valideverytimeje;
    int Validmaxtime;
    String BTCreatetimestr;
    String insertsqlstr;
protected:
	void __fastcall Execute();
	void __fastcall CreateOneBonusFunc();
public:
	__fastcall TCreateCSBTThread(bool CreateSuspended,
    							TcxButton* CSBTN,
                                TcxButton* JEBTN,
                                TcxButton* JBBTN,
                                TcxButton* EBTN,
                                TcxProgressBar* CSProBar,
                                TADOQuery* CSADOQ,
                                TADOQuery* CSInADOQ,
                                String Beginstr,
                                String Endstr,
                                int everytimeje,
                                int maxtime);
};
//---------------------------------------------------------------------------
#endif
