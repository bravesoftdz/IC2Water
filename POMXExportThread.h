//---------------------------------------------------------------------------

#ifndef POMXExportThreadH
#define POMXExportThreadH
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
class TPOMXExportThread : public TThread
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

    double Validbfdcje;
    double Validbfxfje;
    double Validbfze;
    int Validbfdccs;
    int Validbfxfcs;


    double Validlhdcje;
    double Validlhxfje;
    double Validlhze;
    int Validlhdccs;
    int Validlhxfcs;

    double Validsrdcje;
    double Validsrxfje;
    double Validsrze;
    int Validsrdccs;
    int Validsrxfcs;

    double Validntdcje;
    double Validntxfje;
    double Validntze;
    int Validntdccs;
    int Validntxfcs;

    String ValidCZYstr;
protected:
	void __fastcall Execute();
public:
	__fastcall TPOMXExportThread(bool CreateSuspended,
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
                                 double bfdcje,
                                 double bfxfje,
                                 double bfze,
                                 int bfdccs,
                                 int bfxfcs,
                                 double lhdcje,
                                 double lhxfje,
                                 double lhze,
                                 int lhdccs,
                                 int lhxfcs,
                                 double srdcje,
                                 double srxfje,
                                 double srze,
                                 int srdccs,
                                 int srxfcs,
                                 double ntdcje,
                                 double ntxfje,
                                 double ntze,
                                 int ntdccs,
                                 int ntxfcs,
                                 String CZYstr);
};
//---------------------------------------------------------------------------
#endif
