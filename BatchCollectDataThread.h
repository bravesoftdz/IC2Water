//---------------------------------------------------------------------------

#ifndef BatchCollectDataThreadH
#define BatchCollectDataThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "GlobalParameter.h"
#include "cxListView.hpp"
#include "cxTL.hpp"
#include "cxProgressBar.hpp"
#include "cxRichEdit.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TBatchCollectDataThread : public TThread
{
private:
	bool* validcollecttag;

	TcxListView* ValidDisplayListView;
	TTreeView* ValidPosTreeList;
	int* ONLinePosNum;
	int PosNumber;
//	String OrignalDataStr;
	TADOQuery* UpdateDataBaseQuery;
	unsigned char receivebuf[2048];
//	String SerialNum;
	String Place;
	TPanel* ValidInfoPanel;
	HANDLE hStoreToFile;
	TcxButton* ValidStoreBtn;
	TcxButton* ValidEBTN;
	TcxButton* ValidSBTN;
	TcxProgressBar* ValidCProgressBar;
	String tmpcaptionstr;
	int nodecount;
	int currentcount;
	int poscollectedrecordcount;
	int posallrecordcount;

	String CollectOverStautsStr;
	bool errortag;

protected:
	void __fastcall Execute();
	void __fastcall AnalyzeDataFunc();
	void __fastcall DisplayCollectingFunc();
	void __fastcall DisplayEndCollectFunc();
public:
	__fastcall TBatchCollectDataThread(bool CreateSuspended,
									   bool* collecttag,
									   TTreeView* OnLinePosTreeList,
									   TcxListView* DataListView,
									   int* PosNum,
                                       TcxProgressBar* CProgressBar,
									   TADOQuery* updateQuery,
									   TPanel* InfoPanel,
									   TcxButton* StoreBtn,
									   TcxButton* EBTN,
									   TcxButton* SBTN);
};
//---------------------------------------------------------------------------
#endif
