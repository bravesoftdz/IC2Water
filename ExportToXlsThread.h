//---------------------------------------------------------------------------

#ifndef ExportToXlsThreadH
#define ExportToXlsThreadH
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
class TExportToXlsThread : public TThread
{
private:
	TcxProgressBar* ExportProgress;
	TADOQuery* ExportQuery;
	TcxButton* ExportBTN;
	TcxButton* ExitBTN;
	String ExportFileName;
	String TableName;
protected:
	void __fastcall Execute();
public:
	__fastcall TExportToXlsThread(bool CreateSuspended,
								  TcxProgressBar* progress,
								  TADOQuery* Query,
								  TcxButton* BTN,
								  TcxButton* EBTN,
								  String filename,
								  String Tagname);
};
//---------------------------------------------------------------------------
#endif
