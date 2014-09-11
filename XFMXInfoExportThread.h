//---------------------------------------------------------------------------

#ifndef XFMXInfoExportThreadH
#define XFMXInfoExportThreadH
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
class TXFMXInfoExportThread : public TThread
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
    String ValidAllXFstr;
    String ValidBMstr;
    String ValidBBstr;
    String ValidZBstr;
    String ValidXMstr;
    String ValidJHstr;
    String ValidCTstr;
	String ValidCZYstr;
	String ValidAllCSstr;
protected:
	void __fastcall Execute();
public:
	__fastcall TXFMXInfoExportThread(bool CreateSuspended,
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
									 String AllXFstr,
									 String AllCSstr,
                                     String BMstr,
                                     String BBstr,
                                     String ZBstr,
                                     String XMstr,
                                     String JHstr,
                                     String CTstr,
									 String CZYstr);
};
//---------------------------------------------------------------------------
#endif
