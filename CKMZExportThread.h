//---------------------------------------------------------------------------

#ifndef CKMZExportThreadH
#define CKMZExportThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxButtons.hpp"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>
#include "Comobj.hpp"
#include "clipbrd.hpp"
#include "cxCheckBox.hpp"
//---------------------------------------------------------------------------
class TCKMXExportThread : public TThread
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
    String ValidJYLXStr;
    String ValidCZYStr;
    String Validsqlstr;
    TcxCheckBox* cxCheckBox1;
    TcxCheckBox* cxCheckBox2;
protected:
	void __fastcall Execute();
public:
	__fastcall TCKMXExportThread(bool CreateSuspended,
    							TADOQuery* Query,
                                TcxProgressBar* progress,
                                TcxButton* ExportBTN,
                                TcxButton* PreviewBTN,
                                String filename,
                                String BeginTimeStr,
                                String EndTimeStr,
                                String KHStr,
                                String BHStr,
                                String JYLXStr,
                                String CZYStr,
                                String sqlstr,
                                TcxCheckBox *cxCheckB1,
                                TcxCheckBox *cxCheckB2);
};
//---------------------------------------------------------------------------
#endif
