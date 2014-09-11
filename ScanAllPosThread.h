//---------------------------------------------------------------------------

#ifndef ScanAllPosThreadH
#define ScanAllPosThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxButtons.hpp"
#include "cxListView.hpp"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>
#include <iostream.h>

//---------------------------------------------------------------------------
class TScanAllPosThread : public TThread
{
private:
	string COMSTR;
	TcxProgressBar* Validprogress;
	TcxListView* ValidListView;
	TcxButton* ValidSingleBTN;
	TcxButton* ValidAllBTN;
	TcxButton* ValidPBTN;
	TcxButton* ValidSBTN;
	TcxButton* ValidExitBTN;
	bool* Validtag;
	TADOQuery* ValidADOQ;
protected:
	void __fastcall Execute();
public:
	__fastcall TScanAllPosThread(bool CreateSuspended,
								 string comstr,
								 TcxProgressBar* progress,
								 TcxListView* ListView,
								 TcxButton* SingleBTN,
								 TcxButton* AllBTN,
								 TcxButton* PauseBTN,
								 TcxButton* ScanBTN,
								 TcxButton* ExitBTN,
								 bool* tag,
								 TADOQuery* ADOQ);
};
//---------------------------------------------------------------------------
#endif
