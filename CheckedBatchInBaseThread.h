//---------------------------------------------------------------------------

#ifndef CheckedBatchInBaseThreadH
#define CheckedBatchInBaseThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxProgressBar.hpp"
#include "GlobalParameter.h"
#include <ADODB.hpp>
#include <DB.hpp>
#include <cxButtons.hpp>
//---------------------------------------------------------------------------
class TCheckBatchInBaseThread : public TThread
{
private:
	TcxButton* ValidInBTN;
	TcxButton* ValidBCBTN;
	TcxButton* ValidEBTN;
	TcxProgressBar* ValidProgressBar;
	TADOQuery* UpdateDataBaseQuery;
	TPanel *ValidPanel;
	unsigned char BufferFromFile[2048];
	String OrignalDataStr;
	String SerialNum;
	String Place;
	int PosNumber;
	ofstream TmpSaveInsertRecordFile;
	ofstream TmpSaveInsertErrRecFile;
protected:
	void __fastcall Execute();
	void __fastcall AnalyzeDataFunc();
	void __fastcall DisplayDataFunc();
	void __fastcall UpdateDataBaseFunc();
	void __fastcall SaveDataToFileFunc();
public:
	__fastcall TCheckBatchInBaseThread(bool CreateSuspended,
									  TcxButton* InBTN,
									  TcxButton* BCBTN,
									  TcxButton* EBTN,
									  TcxProgressBar* ProgressBar,
									  TADOQuery* updateQuery,
									  TPanel *DPanel);
};
//---------------------------------------------------------------------------
#endif
