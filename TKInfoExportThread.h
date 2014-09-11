//---------------------------------------------------------------------------

#ifndef TKInfoExportThreadH
#define TKInfoExportThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "cxButtons.hpp"
#include <ADODB.hpp>
#include "Comobj.hpp"
#include "clipbrd.hpp"
//---------------------------------------------------------------------------
class TTkInfoExportThread : public TThread
{
private:
	TADOQuery* ValidADOQuery;
    TcxButton* ValidExportBTN;
    TcxButton* ValidPreviewBTN;
    String Validfilename;
    String ValidBeginTimeStr;
    String ValidEndTimeStr;
protected:
	void __fastcall Execute();
public:
	__fastcall TTkInfoExportThread(bool CreateSuspended,
    								TADOQuery* Query,
                                    TcxButton* ExportBTN,
                                    TcxButton* PreviewBTN,
                                    String filename,
                                    String BeginTimeStr,
                                    String EndTimestr);
};
//---------------------------------------------------------------------------
#endif
