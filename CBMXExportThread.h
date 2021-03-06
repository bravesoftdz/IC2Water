//---------------------------------------------------------------------------

#ifndef CBMXExportThreadH
#define CBMXExportThreadH
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
class TCBMXExportThread : public TThread
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
    String ValidCTNamestr;
    bool Validbftag;
    bool Validlhtag;
    bool Validsrtag;
    bool Validnttag;
    double Validbfze;
    int Validbfcs;
    double Validlhze;
    int Validlhcs;
    double Validsrze;
    int Validsrcs;
    double Validntze;
    int Validntcs;
    String ValidCZYstr;
protected:
	void __fastcall Execute();
public:
	__fastcall TCBMXExportThread(bool CreateSuspended,
								 TcxProgressBar* progress,
                                 TADOQuery* Query,
                                 TcxButton* EXBTN,
                                 TcxButton* PreBTN,
                                 TcxButton* EBTN,
                                 String savepath,
                                 String BeginDatestr,
                                 String EndDatestr,
                                 String CTNamestr,
                                 bool bftag,
                                 bool lhtag,
                                 bool srtag,
                                 bool nttag,
                                 double bfze,
                                 int bfcs,
                                 double lhze,
                                 int lhcs,
                                 double srze,
                                 int srcs,
                                 double ntze,
                                 int ntcs,
                                 String CZYstr);
};
//---------------------------------------------------------------------------
#endif
