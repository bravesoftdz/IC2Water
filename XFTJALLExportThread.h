//---------------------------------------------------------------------------

#ifndef XFTJALLExportThreadH
#define XFTJALLExportThreadH
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
class TXFTJALLExportThread : public TThread
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
    String ValidBZE;
    String ValidBZCS;
    String ValidLZE;
    String ValidLZCS;
    String ValidSZE;
    String ValidSZCS;
    String ValidNZE;
    String ValidNZCS;
    String Validsavepath;
    String ValidBeginDatestr;
    String ValidEndDatestr;
    String ValidBMStr;
    String ValidBHStr;
    String ValidCZYStr;
protected:
	void __fastcall Execute();
public:
	__fastcall TXFTJALLExportThread(bool CreateSuspended,
									TcxProgressBar* progress,
                                    TADOQuery* Query,
                                    TcxButton* EXBTN,
                                    TcxButton* PreBTN,
                                    TcxButton* EBTN,
                                    TcxButton* QBTN,
                                    String ZZE,
                                    String ZZCS,
                                    String BZE,
                                    String BZCS,
                                    String LZE,
                                    String LZCS,
                                    String SZE,
                                    String SZCS,
                                    String NZE,
                                    String NZCS,
                                    String savepath,
                                    String BeginDatestr,
                                    String EndDatestr,
                                    String BMStr,
                                    String BHStr,
                                    String CZYStr);
};
//---------------------------------------------------------------------------
#endif
