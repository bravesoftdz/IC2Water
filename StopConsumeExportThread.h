//---------------------------------------------------------------------------

#ifndef StopConsumeExportThreadH
#define StopConsumeExportThreadH
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
class TStopConsumeExportThread : public TThread
{
private:
	TcxProgressBar* Validprogress;
    TADOQuery* ValidQuery;
    TcxButton* ValidEXBTN;
    TcxButton* ValidPreBTN;
    TcxButton* ValidEBTN;

    String Validsavepath;
    String Validcheckstr;
    String ValidCZYstr;
protected:
	void __fastcall Execute();
public:
	__fastcall TStopConsumeExportThread(bool CreateSuspended,
										TcxProgressBar* progress,
                                      	TADOQuery* Query,
                                      	TcxButton* EXBTN,
                                      	TcxButton* PreBTN,
                                      	TcxButton* EBTN,
                                      	String savepath,
                                      	String checkstr,
                                      	String CZYstr);
};
//---------------------------------------------------------------------------
#endif
