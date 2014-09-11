//---------------------------------------------------------------------------

#ifndef BatchDataInBaseThreadH
#define BatchDataInBaseThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxTL.hpp"
#include "cxProgressBar.hpp"
#include "GlobalParameter.h"
#include "cxRichEdit.hpp"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TBatchDataInBaseThread : public TThread
{
private:
	TcxButton* ValidInBTN;
	TcxButton* ValidBCBTN;
	TcxButton* ValidEBTN;
	TcxProgressBar* ValidProgressBar;
	TADOQuery* UpdateDataBaseQuery;
	TcxRichEdit* DisplayRichEditView;
	TPanel *ValidPanel;
	unsigned char BufferFromFile[2048];
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
	__fastcall TBatchDataInBaseThread(bool CreateSuspended,
									  TcxButton* InBTN,
									  TcxButton* BCBTN,
									  TcxButton* EBTN,
									  TcxProgressBar* ProgressBar,
									  TADOQuery* updateQuery,
									  TcxRichEdit* RichEView,
									  TPanel *DPanel);
};
//---------------------------------------------------------------------------
#endif
