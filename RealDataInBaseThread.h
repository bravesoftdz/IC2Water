//---------------------------------------------------------------------------

#ifndef RealDataInBaseThreadH
#define RealDataInBaseThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxTL.hpp"
#include "cxProgressBar.hpp"
#include "GlobalParameter.h"
#include "cxRichEdit.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TRealDataInBaseThread : public TThread
{
private:
	TcxButton* ValidInBTN;
	TcxButton* ValidBCBTN;
	TcxButton* ValidEBTN;
	TcxProgressBar* ValidProgressBar;
	TADOQuery* UpdateDataBaseQuery;
	TPanel *ValidPanel;
	unsigned char BufferFromFile[18];
	String OrignalDataStr;
	String SerialNum;
	String Place;
	int PosNumber;
	ofstream TmpSaveInsertRecordFile;
    ofstream TmpAddInPosInsertRecordFile;
	ofstream TmpSaveInsertErrRecFile;
protected:
	void __fastcall Execute();
	void __fastcall AnalyzeDataFunc();
	void __fastcall DisplayDataFunc();
	void __fastcall UpdateDataBaseFunc();
	void __fastcall SaveDataToFileFunc();
public:
	__fastcall TRealDataInBaseThread(bool CreateSuspended,
									  TcxButton* InBTN,
									  TcxButton* BCBTN,
									  TcxButton* EBTN,
									  TcxProgressBar* ProgressBar,
									  TADOQuery* updateQuery,
									  TPanel *DPanel);
};
//---------------------------------------------------------------------------
#endif
