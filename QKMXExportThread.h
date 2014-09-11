//---------------------------------------------------------------------------

#ifndef QKMXExportThreadH
#define QKMXExportThreadH
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
class TQKMXExportThread : public TThread
{
private:
    TcxProgressBar* Validprogress;
    TADOQuery* ValidQuery;
    TcxButton* ValidEXBTN;
    TcxButton* ValidPreBTN;
    TcxButton* ValidEBTN;
    String Validsavepath;

    String ValidBeginDatestr;
    String ValidEndDatestr;
    String ValidKHstr;
    String ValidBHstr;
	String ValidAllQKstr;
	String ValidAllQCSstr;
    String ValidBMstr;
    String ValidBBstr;
    String ValidZBstr;
    String ValidQKCZYstr;
    bool ValidDKQQKtag;
    bool ValidTKQKtag;
    String ValidCZYstr;
protected:
	void __fastcall Execute();
public:
	__fastcall TQKMXExportThread(bool CreateSuspended,
								 TcxProgressBar* progress,
                                 TADOQuery* Query,
                                 TcxButton* EXBTN,
                                 TcxButton* PreBTN,
                                 TcxButton* EBTN,
                                 String savepath,
                                 String BeginDatestr,
                                 String EndDatestr,
                                 String KHstr,
                                 String BHstr,
								 String AllQKstr,
								 String AllQCSstr,
                                 String BMstr,
                                 String BBstr,
                                 String ZBstr,
                                 String QKCZYstr,
                                 bool DKQQKtag,
                                 bool TKQKtag,
                                 String CZYstr);
};
//---------------------------------------------------------------------------
#endif
