//---------------------------------------------------------------------------

#ifndef CARDExportThreadH
#define CARDExportThreadH
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
class TCARDExportThread : public TThread
{
private:
	TcxProgressBar* Validprogress;
    TADOQuery* ValidQuery;
    TcxButton* ValidEXBTN;
    TcxButton* ValidPreBTN;
    TcxButton* ValidEBTN;

    String Validsavepath;
	String ValidKHstr;
    String ValidBHstr;
    String ValidXMstr;
    String ValidBMstr;
    String ValidBBstr;
    String ValidZBstr;
    String ValidCZYstr;
protected:
	void __fastcall Execute();
public:
	__fastcall TCARDExportThread(bool CreateSuspended,
    							 TcxProgressBar* progress,
                                 TADOQuery* Query,
                                 TcxButton* EXBTN,
                                 TcxButton* PreBTN,
                                 TcxButton* EBTN,
                                 String savepath,
    							 String KHstr,
                                 String BHstr,
                                 String XMstr,
                                 String BMstr,
                                 String BBstr,
                                 String ZBstr,
                                 String CZYstr);
};
//---------------------------------------------------------------------------
#endif
