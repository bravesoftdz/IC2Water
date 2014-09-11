//---------------------------------------------------------------------------

#ifndef TKExportThreadH
#define TKExportThreadH
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
class TTKExportThread : public TThread
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
    String ValidKHstr;
    String ValidBHstr;
    String ValidXMstr;
    String ValidBMstr;
    String ValidCZYstr;
    String ValidCSstr;
    String ValidJEstr;
    String ValidCBstr;
protected:
	void __fastcall Execute();
public:
	__fastcall TTKExportThread(bool CreateSuspended,
    						   TcxProgressBar* progress,
                               TADOQuery* Query,
                               TcxButton* EXBTN,
                               TcxButton* PreBTN,
                               TcxButton* EBTN,
                               TcxButton* QBTN,
                               String savepath,
                               String BeginDatestr,
                               String EndDatestr,
                               String KHstr,
                               String BHstr,
                               String XMstr,
                               String BMstr,
                               String CZYstr,
                               String CSstr,
                               String JEstr,
                               String CBstr);
};
//---------------------------------------------------------------------------
#endif
