//---------------------------------------------------------------------------

#ifndef CollectDataWOThreadH
#define CollectDataWOThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxProgressBar.hpp"
#include "cxListView.hpp"
#include "cxTL.hpp"
#include "cxEdit.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TCollectDataWOThread : public TThread
{
private:
	bool* validcollecttag;
	bool ValidGSTag;
	TcxListView* DisplayListView;
	TTreeView* ValidPosTreeList;
    TcxProgressBar* ValidCProgressBar;
	int* ONLinePosNum;
	int PosNumber;
	String OrignalDataStr;
	String DataStatusStr;
//	TcxButton* ValidPauseBTN;
	TADOQuery* UpdateDataBaseQuery;
	TADOTable* ValidLostInfoT;
	unsigned char receivebuf[16];
	String SerialNum;
	String Place;
	String USERNAME;
	String CARDNO;
	String MONEY;
	String ConSumeTime;
	String YUE;
	String DSYCS;
    HANDLE hStoreToFile;
protected:
	void __fastcall Execute();
	void __fastcall DisplayDataFunc();
	void __fastcall SaveDataToFileFunc();
public:
	__fastcall TCollectDataWOThread(bool CreateSuspended,
								  bool* collecttag,
								  bool GSTag,
								  TcxListView* DataListView,
								  TTreeView* OnLinePosTreeList,
                                  int* PosNum,
                                  TcxProgressBar* CProgressBar,
								  TADOQuery* updateQuery,
								  TADOTable* LostInfoT);
};
//---------------------------------------------------------------------------
#endif
