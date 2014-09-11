//---------------------------------------------------------------------------

#ifndef PostLostInfoThreadH
#define PostLostInfoThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxButtons.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
#include "cxProgressBar.hpp"
#include "GlobalParameter.h"

//---------------------------------------------------------------------------
class TPostLostInfoThread : public TThread
{
private:
protected:
	TADOTable* ValidLostInfoT;
	TcxButton* ValidGSBTN;
	TcxButton* ValidExitBTN;
	TcxProgressBar* ValidProBar;
	void __fastcall Execute();
public:
	__fastcall TPostLostInfoThread(bool CreateSuspended,
								   TcxButton* GSBTN,
								   TcxButton* EBTN,
								   TADOTable* LostInfoT,
								   TcxProgressBar* ProBar);
};
//---------------------------------------------------------------------------
#endif
