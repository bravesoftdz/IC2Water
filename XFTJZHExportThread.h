//---------------------------------------------------------------------------

#ifndef XFTJZHExportThreadH
#define XFTJZHExportThreadH
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
class TXFTJZHExportThread : public TThread
{
private:
    TcxProgressBar* Validprogress;
    TADOQuery* ValidQuery;
    TcxButton* ValidEXBTN;
    TcxButton* ValidPreBTN;
    TcxButton* ValidEBTN;
    TcxButton* ValidQBTN;
    String ValidZZE;
    String ValidZZCS;
    String Validsavepath;
    String ValidBeginDatestr;
    String ValidEndDatestr;
    String ValidBMStr;
    String ValidBHStr;
    String ValidCZYStr;
protected:
	void __fastcall Execute();
public:
	__fastcall TXFTJZHExportThread(bool CreateSuspended,
									TcxProgressBar* progress,
                                    TADOQuery* Query,
                                    TcxButton* EXBTN,
                                    TcxButton* PreBTN,
                                    TcxButton* EBTN,
                                    TcxButton* QBTN,
                                    String ZZE,
                                    String ZZCS,
                                    String savepath,
                                    String BeginDatestr,
                                    String EndDatestr,
                                    String BMStr,
                                    String BHStr,
                                    String CZYStr);
};
//---------------------------------------------------------------------------
#endif
