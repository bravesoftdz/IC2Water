//---------------------------------------------------------------------------

#ifndef KYExportThreadH
#define KYExportThreadH
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
class TKYExportThread : public TThread
{
private:
    TcxProgressBar* Validprogress;
    TADOQuery* ValidQuery;
    TcxButton* ValidEXBTN;
    TcxButton* ValidPreBTN;
    TcxButton* ValidEBTN;
    TcxButton* ValidRCBTN;
    TcxButton* ValidQBTN;
    String Validsavepath;
    String ValidKHstr;
    String ValidBHstr;
    String ValidXMstr;
    String ValidBMstr;
	String ValidCZYstr;
	String ValidKZSstr;
	String ValidKZZstr;
protected:
	void __fastcall Execute();
public:
	__fastcall TKYExportThread(bool CreateSuspended,
								TcxProgressBar* progress,
                                TADOQuery* Query,
                                TcxButton* EXBTN,
                                TcxButton* PreBTN,
                                TcxButton* EBTN,
                                TcxButton* RCBTN,
                                TcxButton* QBTN,
                                String savepath,
                                String KHstr,
                                String BHstr,
                                String XMstr,
                                String BMstr,
								String CZYstr,
								String KZSstr,
								String KZZstr);
};
//---------------------------------------------------------------------------
#endif
