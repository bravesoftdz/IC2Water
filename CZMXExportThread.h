//---------------------------------------------------------------------------

#ifndef CZMXExportThreadH
#define CZMXExportThreadH
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
class TCZMXExportThread : public TThread
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
    String ValidAllCKstr;
    String ValidBMstr;
    String ValidBBstr;
    String ValidZBstr;
    String ValidCZCZYstr;
    bool ValidDKQCZtag;
    bool ValidPOSCZtag;
    bool ValidFKCZtag;
    String ValidCZYstr;
protected:
	void __fastcall Execute();
public:
	__fastcall TCZMXExportThread(bool CreateSuspended,
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
                                 String AllCKstr,
                                 String BMstr,
                                 String BBstr,
                                 String ZBstr,
                                 String CZCZYstr,
                                 bool DKQCZtag,
                                 bool POSCZtag,
                                 bool FKCZtag,
                                 String CZYstr);
};
//---------------------------------------------------------------------------
#endif
