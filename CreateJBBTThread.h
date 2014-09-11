//---------------------------------------------------------------------------

#ifndef CreateJBBTThreadH
#define CreateJBBTThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxDropDownEdit.hpp"
#include "cxCheckGroup.hpp"
#include "cxButtons.hpp"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>
#include "GlobalParameter.h"
//---------------------------------------------------------------------------
class TCreateJBBTThread : public TThread
{
private:
	TcxButton* ValidCSBTN;
    TcxButton* ValidJEBTN;
    TcxButton* ValidJBBTN;
    TcxButton* ValidEBTN;
    TcxComboBox* ValidJBComboBox;
    TcxCheckGroup* ValidJBCheckGroup;
    TcxProgressBar* ValidJBProBar;
    TADOQuery* ValidJBADOQ;
    TADOQuery* ValidJBInADOQ;
    String BTCreatetimestr;
    String insertsqlstr;
protected:
	void __fastcall Execute();
    void __fastcall CreateOneBonusFunc();
public:
	__fastcall TCreateJBBTThread(bool CreateSuspended,
    							TcxButton* CSBTN,
                                TcxButton* JEBTN,
                                TcxButton* JBBTN,
                                TcxButton* EBTN,
                                TcxComboBox *JBComboBox,
                                TcxCheckGroup *JBCheckGroup,
                                TcxProgressBar* JBProBar,
                                TADOQuery* JBADOQ,
                                TADOQuery* JBInADOQ);
};
//---------------------------------------------------------------------------
#endif
