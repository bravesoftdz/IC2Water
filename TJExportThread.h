//---------------------------------------------------------------------------

#ifndef TJExportThreadH
#define TJExportThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include "GlobalParameter.h"
#include "cxTL.hpp"
#include "Comobj.hpp"
#include "clipbrd.hpp"
//---------------------------------------------------------------------------
class TTJExportThread : public TThread
{
private:
	TListView* ValidLV;
	TButton* ValidEBTN;
    TcxButton *ValidQBTN;
    TcxButton *ValidExitBTN;
	TProgressBar* Validprobar;
	String Validyfstr;
	double Validzxf;
	String Validsavepath;
protected:
	void __fastcall Execute();
public:
	__fastcall TTJExportThread(bool CreateSuspended,
								TListView *LV,
								TButton *EBTN,
                                TcxButton *QBTN,
                                TcxButton *ExitBTN,
								TProgressBar* probar,
								String yfstr,
								double zxf,
								String savepath);
};
//---------------------------------------------------------------------------
#endif
