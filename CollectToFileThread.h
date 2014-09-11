//---------------------------------------------------------------------------

#ifndef CollectToFileThreadH
#define CollectToFileThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "GlobalParameter.h"
#include "cxTL.hpp"
#include "cxProgressBar.hpp"
#include "fstream.h"
//---------------------------------------------------------------------------
class TCollectToFileThread : public TThread
{
private:
	int validposnum;
    int validcomnum;
    TcxButton* validBTN1;
    TcxButton* validBTN2;
    TcxButton* validBTN3;
    TcxButton* validBTN4;
    TcxButton* validBTN5;
    String validfilepathname;
    TcxProgressBar* validCollectPBar;
    ofstream SingleCollectSaveStream;
    unsigned char receivebuf[2048];
    int PosNumber;
protected:
	void __fastcall Execute();
    void __fastcall AnalyzeDataFunc();
public:
	__fastcall TCollectToFileThread(bool CreateSuspended,
    								int posnum,
                                    int comnum,
                                    TcxButton* BTN1,
                                    TcxButton* BTN2,
                                    TcxButton* BTN3,
                                    TcxButton* BTN4,
                                    TcxButton* BTN5,
                                    String filepathname,
                                    TcxProgressBar* CollectPBar);
};
//---------------------------------------------------------------------------
#endif
