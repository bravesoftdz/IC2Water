//---------------------------------------------------------------------------

#ifndef PXFMXExportThreadH
#define PXFMXExportThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxButtons.hpp"
#include "cxProgressBar.hpp"
#include <ADODB.hpp>
#include "Comobj.hpp"
#include "clipbrd.hpp"
//---------------------------------------------------------------------------
class PXFMXInfoExportThread : public TThread
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
	String ValidXMStr;
	String ValidXFZEStr;
	String ValidXFZCSStr;
	String ValidCZZEStr;
	String ValidCZZCSStr;
	String ValidQKZEStr;
	String ValidQKZCSStr;
	String Validczystr;
protected:
	void __fastcall Execute();
public:
	__fastcall PXFMXInfoExportThread(bool CreateSuspended,
									TADOQuery* Query,
									TcxProgressBar* progress,
									TcxButton* ExportBTN,
									TcxButton* PreviewBTN,
									String filename,
									String BeginTimeStr,
									String EndTimeStr,
									String KHStr,
									String XMStr,
									String XFZEStr,
									String XFZCSStr,
									String CZZEStr,
									String CZZCSStr,
									String QKZEStr,
									String QKZCSStr,
									String czystr);
};
//---------------------------------------------------------------------------
#endif
