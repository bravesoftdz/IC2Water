//---------------------------------------------------------------------------

#ifndef DisplayTJThreadH
#define DisplayTJThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include "cxTL.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDisplayTJThread : public TThread
{
private:
	TListView* ValidLV;
	TButton* ValidEBTN;
    TcxButton *ValidQBTN;
    TcxButton *ValidExitBTN;
	TEdit* ValidTJEdit;
	TADOQuery* ValidADOQL;
	TADOQuery* ValidADOQH;
	TADOQuery* ValidADOQJH;
protected:
	void __fastcall Execute();
public:
	__fastcall TDisplayTJThread(bool CreateSuspended,
								TListView *LV,
								TButton *EBTN,
                                TcxButton *QBTN,
                                TcxButton *ExitBTN,
								TEdit* TJEdit,
								TADOQuery* ADOQL,
								TADOQuery* ADOQH,
								TADOQuery* ADOQJH);
};
//---------------------------------------------------------------------------
#endif
