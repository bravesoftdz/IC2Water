//---------------------------------------------------------------------------

#ifndef GSExportThreadH
#define GSExportThreadH
//---------------------------------------------------------------------------
#include <Windows.hpp>
#include <System.hpp>
#include <Classes.hpp>
#include "cxProgressBar.hpp"
#include "cxButtons.hpp"
#include <ADODB.hpp>
#include "Comobj.hpp"
#include "clipbrd.hpp"
#include "cxGridDBTableView.hpp"
//---------------------------------------------------------------------------
class TGSExportThread : public TThread
{
private:
    TcxProgressBar* Validprogress;
    TADOQuery* ValidQuery;
    TcxButton* ValidEXBTN;
    TcxButton* ValidPreBTN;
    TcxButton* ValidEBTN;
    TcxButton* ValidQBTN;
    String Validsavepath;
    String ValidKHstr;
    String ValidBHstr;
    String ValidXMstr;
	String ValidCZYstr;
protected:
	void __fastcall Execute();
public:
	__fastcall TGSExportThread(bool CreateSuspended,
							   TcxProgressBar* progress,
                               TADOQuery* Query,
                               TcxButton* EXBTN,
                               TcxButton* PreBTN,
                               TcxButton* EBTN,
                               TcxButton* QBTN,
                               String savepath,
                               String KHstr,
                               String BHstr,
                               String XMstr,
                               String CZYstr);
};
//---------------------------------------------------------------------------
#endif
