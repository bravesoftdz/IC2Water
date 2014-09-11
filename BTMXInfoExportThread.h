//---------------------------------------------------------------------------

#ifndef BTMXInfoExportThreadH
#define BTMXInfoExportThreadH
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
class TBTMXInfoExportThread : public TThread
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
	int Validqtag;
	String ValidCZYstr;
	String ValidAllXFstr;
	String ValidAllCSstr;
protected:
	void __fastcall Execute();
public:
	__fastcall TBTMXInfoExportThread(bool CreateSuspended,
    								 TcxProgressBar* progress,
                                     TADOQuery* Query,
                                     TcxButton* EXBTN,
                                     TcxButton* PreBTN,
                                     TcxButton* EBTN,
                                     String savepath,
                                     String BeginDatestr,
									 String EndDatestr,
									 String AllXFstr,
									 String AllCSstr,
									 int qtag,
									 String CZYstr);
};
//---------------------------------------------------------------------------
#endif
