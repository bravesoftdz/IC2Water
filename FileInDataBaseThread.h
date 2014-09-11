//---------------------------------------------------------------------------

#ifndef FileInDataBaseThreadH
#define FileInDataBaseThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxTL.hpp"
#include "cxProgressBar.hpp"
#include "GlobalParameter.h"
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TFileInDataBaseThread : public TThread
{
private:
	TcxButton* validBTN1;
    TcxButton* validBTN2;
    TcxButton* validBTN3;
    TcxButton* validBTN4;
    TcxButton* validBTN5;
    String validfilepathname;
    TcxProgressBar* validInDataBasePBar;
    TADOQuery* validupdateADOQuery;
    String OrignalDataStr;
    String SerialNum;
	String Place;
	int PosNumber;

    unsigned char BufferFromFile[2048];
    ofstream TmpSaveInsertRecordFile;
	ofstream TmpSaveInsertErrRecFile;

    unsigned char* tmpdata;
	int tmpdatalen;
	unsigned char* purifieddata;
	int purifieddatalen;

protected:
	void __fastcall Execute();
	void __fastcall PurifyFileFunc();
    void __fastcall AnalyzeDataFunc();
    void __fastcall UpdateDataBaseFunc();
public:
	__fastcall TFileInDataBaseThread(bool CreateSuspended,
    								TcxButton* BTN1,
                                    TcxButton* BTN2,
                                    TcxButton* BTN3,
                                    TcxButton* BTN4,
                                    TcxButton* BTN5,
                                    String filepathname,
                                    TcxProgressBar* InDataBasePBar,
                                    TADOQuery* updateADOQuery);
};
//---------------------------------------------------------------------------
#endif
