//---------------------------------------------------------------------------

#ifndef BKMXExportThreadH
#define BKMXExportThreadH
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
class TBKMXExportThread : public TThread
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

    String ValidCZCZYstr;
    String ValidCZYstr;
protected:
	void __fastcall Execute();
public:
	__fastcall TBKMXExportThread(bool CreateSuspended,
                                TcxProgressBar* progress,
                                TADOQuery* Query,
                                TcxButton* EXBTN,
                                TcxButton* PreBTN,
                                TcxButton* EBTN,
                                String savepath,
                                String BeginDatestr,
                                String EndDatestr,
                                String CZCZYstr,
                                String CZYstr);
};
//---------------------------------------------------------------------------
#endif
