//---------------------------------------------------------------------------

#ifndef CZLExportThreadH
#define CZLExportThreadH
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
class TCZLExportThread : public TThread
{
private:
    TcxProgressBar* Validprogress;
    TADOQuery* ValidQuery;
    TcxButton* ValidEXBTN;
    TcxButton* ValidPreBTN;
    TcxButton* ValidEBTN;
    TcxButton* ValidQBTN;
    String Validsavepath;
    String ValidBeginDatestr;
    String ValidEndDatestr;
    String ValidCZYstr;
protected:
	void __fastcall Execute();
public:
	__fastcall TCZLExportThread(bool CreateSuspended,
								TcxProgressBar* progress,
                               	TADOQuery* Query,
                               	TcxButton* EXBTN,
                               	TcxButton* PreBTN,
                               	TcxButton* EBTN,
                               	TcxButton* QBTN,
                               	String savepath,
                               	String BeginDatestr,
                               	String EndDatestr,
                               	String CZYstr);
};
//---------------------------------------------------------------------------
#endif
