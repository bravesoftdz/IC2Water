//---------------------------------------------------------------------------

#ifndef CheckedBatchCollectDataThreadH
#define CheckedBatchCollectDataThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "GlobalParameter.h"
#include "cxListView.hpp"
#include "cxCheckGroup.hpp"
#include "cxCheckListBox.hpp"
#include "cxButtons.hpp"
#include "GlobalParameter.h"
#include "cxProgressBar.hpp"
#include "cxRichEdit.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TCheckedBatchCollectDataThread : public TThread
{
private:
	bool* validcollecttag;
	TcxListView* ValidDisplayListView;
	TcxCheckListBox* ValidCKB;
	int* ONLinePosNum;
	int PosNumber;
	TADOQuery* UpdateDataBaseQuery;
	unsigned char receivebuf[2048];
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

protected:
	void __fastcall Execute();
	void __fastcall AnalyzeDataFunc();
	void __fastcall DisplayCollectingFunc();
	void __fastcall DisplayEndCollectFunc();
public:
	__fastcall TCheckedBatchCollectDataThread(bool CreateSuspended,
											bool* collecttag,
											TcxCheckListBox* OnLinePosCKB,
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
