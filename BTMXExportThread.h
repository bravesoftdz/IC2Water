//---------------------------------------------------------------------------

#ifndef BTMXExportThreadH
#define BTMXExportThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxButtons.hpp"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>
#include "Comobj.hpp"
#include "clipbrd.hpp"
//---------------------------------------------------------------------------
class TBTMXExportThread : public TThread
{
private:
	TADOQuery* ValidADOQuery;
    TcxProgressBar* Validprogress;
    TcxButton* ValidExportBTN;
    TcxButton* ValidPreviewBTN;
    String Validfilename;
	String ValidBeginTimeStr;
    String ValidEndTimeStr;
    String ValidKHStr;
    String ValidBHStr;
    String ValidJHStr;
    String ValidDDStr;
protected:
	void __fastcall Execute();
public:
	__fastcall TBTMXExportThread(bool CreateSuspended,
								TADOQuery* Query,
                                TcxProgressBar* progress,
                                TcxButton* ExportBTN,
                                TcxButton* PreviewBTN,
                                String filename,
                                String BeginTimeStr,
                                String EndTimeStr,
                                String KHStr,
                                String BHStr,
                                String JHStr,
                                String DDStr);
};
//---------------------------------------------------------------------------
#endif
