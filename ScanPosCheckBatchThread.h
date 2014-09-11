//---------------------------------------------------------------------------

#ifndef ScanPosCheckBatchThreadH
#define ScanPosCheckBatchThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include "cxCheckGroup.hpp"
#include "cxCheckListBox.hpp"
#include "cxButtons.hpp"
#include "GlobalParameter.h"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>

//---------------------------------------------------------------------------
class TScanPosCheckBatchThread : public TThread
{
private:
	bool* ValidScantag;
	TcxProgressBar* progressbar;
	TcxCheckListBox* ValidCKB;
	TcxButton* ValidCollectBTN;
	TcxButton* ValidScallBTN;
	TcxButton* ValidExitBTN;
	TcxButton* ValidSBTN;
	TPanel* ValidPanel;
	int* validposnum;
	TADOQuery* ValidCDQuery;

    WORD checkstatus;
    String nodenamestr;

protected:
	void __fastcall Execute();
    void __fastcall addlistitem();
public:
	__fastcall TScanPosCheckBatchThread(bool CreateSuspended,
										bool* Scantag,
										TcxProgressBar* progress,
										TcxCheckListBox* OnLinePosCKB,
										TcxButton* CollectBTN,
										TcxButton* EBTN,
										TcxButton* SBTN,
										TPanel* Panel,
										int* PosNum,
										TADOQuery* CDQuery);
};
//---------------------------------------------------------------------------
#endif
