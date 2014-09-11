//---------------------------------------------------------------------------

#ifndef DLSCanPosThreadH
#define DLSCanPosThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxButtons.hpp"
#include "cxListView.hpp"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>
//#include "GlobalParameter.h"
//---------------------------------------------------------------------------
class TDLSCanPosThread : public TThread
{
private:
	TADOQuery* ValidQuery;
	TcxButton* ValidAllBTN;
	TcxButton* ValidDGBTN;
	TcxButton* ValidEBTN;
	TcxButton* ValidSBTN;
	TcxProgressBar* ValidProBar;
	TcxListView* ValidListV;
	bool* Validtag;
	bool* Validstag;
	TcxButton* ValidSABTN;
	TcxButton* ValidCSABTN;
protected:
	void __fastcall Execute();
public:
	__fastcall TDLSCanPosThread(bool CreateSuspended,
								TADOQuery* Query,
								TcxButton* AllBTN,
								TcxButton* DGBTN,
								TcxButton* EBTN,
								TcxProgressBar* ProBar,
								TcxListView* ListV,
								bool* tag,
								bool* stag,
								TcxButton* SABTN,
								TcxButton* CSABTN,
								TcxButton* SBTN);
};
//---------------------------------------------------------------------------
#endif
