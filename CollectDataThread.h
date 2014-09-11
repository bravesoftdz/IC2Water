//---------------------------------------------------------------------------

#ifndef CollectDataThreadH
#define CollectDataThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxListView.hpp"
#include "cxTL.hpp"
#include "cxEdit.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TCollectDataThread : public TThread
{
private:
	bool* validcollecttag;
	bool ValidGSTag;
	TcxListView* DisplayListView;
	TTreeView* ValidPosTreeList;
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
//	TcxTextEdit* Validusername;
//	TcxTextEdit* Validcardno;
//	TcxTextEdit* Validplace;
//	TcxTextEdit* Validmoney;

protected:
	void __fastcall Execute();
	void __fastcall DisplayDataFunc();
	void __fastcall SaveDataToFileFunc();
	void __fastcall UpdateDataBaseFunc();
public:
	__fastcall TCollectDataThread(bool CreateSuspended,
								  bool* collecttag,
								  bool GSTag,
								  TcxListView* DataListView,
								  TTreeView* OnLinePosTreeList,
								  int* PosNum,
								  TADOQuery* updateQuery,
								  TADOTable* LostInfoT
							//	  TcxTextEdit* username,
							//	  TcxTextEdit* cardno,
							//	  TcxTextEdit* place,
							//	  TcxTextEdit* money
									);
};
//---------------------------------------------------------------------------
#endif
