//---------------------------------------------------------------------------

#ifndef ScallPosThreadH
#define ScallPosThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>

#include "cxButtons.hpp"
#include "cxListView.hpp"
#include "cxTL.hpp"
#include "GlobalParameter.h"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>

//---------------------------------------------------------------------------
 class TScallPosThread : public TThread
{
private:
	bool* ValidScantag;
	TcxProgressBar* progressbar;
	TTreeView* ValidPosTreeList;
	TcxButton* ValidCollectBTN;
	TcxButton* ValidScallBTN;
	TcxButton* ValidExitBTN;
	TcxButton* ValidSBTN;
	TPanel* ValidPanel;
	int* validposnum;
	TADOQuery* ValidCDQuery;

    WORD checkstatus;
    POSPARA* addtmppospara;
    String nodenamestr;
protected:
	void __fastcall Execute();
    void __fastcall addlistitem();
public:
	__fastcall TScallPosThread(bool CreateSuspended,
							   bool* Scantag,
							   TcxProgressBar* progress,
							   TTreeView* OnLinePosTreeList,
							   TcxButton* RealCollectBTN,
							   TcxButton* EBTN,
							   TcxButton* SBTN,
							   TPanel* Panel,
							   int* PosNum,
							   TADOQuery* CDQuery);
};
//---------------------------------------------------------------------------
#endif
