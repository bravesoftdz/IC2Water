//---------------------------------------------------------------------------

#ifndef FixRecordThreadH
#define FixRecordThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <ComCtrls.hpp>

//---------------------------------------------------------------------------
class TFixRecordThread : public TThread
{
private:
	TADOQuery* ValidAllCardADOQ;
	TADOQuery* ValidAllRecordADOQ;
	TADOQuery* ValidAddRecordADOQ;
	TProgressBar* ValidProBar;
	TButton* ValidBTN;
protected:
	void __fastcall Execute();
public:
	__fastcall TFixRecordThread(bool CreateSuspended,
								TADOQuery* AllCardADOQ,
								TADOQuery* AllRecordADOQ,
								TADOQuery* AddRecordADOQ,
								TProgressBar* ProBar,
								TButton* BTN);
};
//---------------------------------------------------------------------------
#endif
