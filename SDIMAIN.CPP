//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "SDIMain.h"
#include "About.h"
//---------------------------------------------------------------------
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxNavBar"
#pragma link "dxNavBarBase"
#pragma link "dxNavBarCollns"


#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinsdxNavBar2Painter"
#pragma link "dxSkinsdxStatusBarPainter"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinValentine"
#pragma link "dxSkinXmas2008Blue"

#pragma link "dxStatusBar"
#pragma link "cxContainer"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "cxTimeEdit"
#pragma link "cxImage"
#pragma link "dxGDIPlusClasses"

#pragma link "cxContainer"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma resource "*.dfm"
TSDIAppForm *SDIAppForm;
//---------------------------------------------------------------------
__fastcall TSDIAppForm::TSDIAppForm(TComponent *AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------

int CreateSendingWNDList(const TCHAR *pstrKSCoreAppName)
{
	//-------防止多次起动----------
	HANDLE hMutex = ::CreateMutex(0, true, pstrKSCoreAppName);
	int nRet = 0;
	if (hMutex)
	{
		if(GetLastError() == ERROR_ALREADY_EXISTS)
		{
			nRet = 1;
		}
		else
		{
			nRet = 0;
		}
	}
	else
	{
	nRet = -1;
	}
	return nRet;
}
//---------------------------------------------------------------------

void __fastcall TSDIAppForm::FormCreate(TObject *Sender)
{
	switch(CreateSendingWNDList("onlyXYInfoManageone"))
	{
		case 1:
		{	// 已存在进程，退出
			::MessageBox(this->Handle, "已经有一个实例在运行了。", "注意", MB_OK|MB_ICONERROR);
			TerminateProcess(e1.hProcess,ExitCode);
			exit(1);
		}
		case -1:
		{
			TerminateProcess(e1.hProcess,ExitCode);
			exit(1);// 无法创建，退出
		}
	}

	String path = GetCurrentDir();
	String dllpath;
	GlobalPath = path;

	String checkfirstrunstr = GlobalPath + "\\IsFirstRun.tag";

	if(FileExists(checkfirstrunstr))
	{
		ifstream getin(checkfirstrunstr.t_str());
		int IsFirstRunTag;
		getin>>IsFirstRunTag;
		if(IsFirstRunTag)
		{
			if(!SetLocaleInfoA(LOCALE_SYSTEM_DEFAULT,LOCALE_SSHORTDATE,"yyyy-MM-dd"))
			{
				UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
				ShowMessage("无法将系统日期格式设置成长日期格式，程序无法正常运行!");
				this->Free();
				exit(1);
			}

			if(!SetLocaleInfoA(LOCALE_SYSTEM_DEFAULT,LOCALE_SLONGDATE,"yyyy-MM-dd"))
			{
				UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
				ShowMessage("无法将系统日期格式设置成长日期格式，程序无法正常运行!");
				this->Free();
				exit(1);
			}

	  //    String TimeFormatStr = "HH:mm:ss";
			if(!SetLocaleInfoA(LOCALE_SYSTEM_DEFAULT,LOCALE_STIMEFORMAT,"HH:mm:ss"))
			{
				UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
				ShowMessage("无法将系统时间格式设置成长时间格式，程序无法正常运行!");
				this->Free();
				exit(1);
			}


			UINT ExitCode;
			TerminateProcess(e1.hProcess,ExitCode);

	  //	SetBaseInfoFrm->ShowModal();

			SHELLEXECUTEINFO ex;
			memset(&ex,0,sizeof(ex));
			ex.cbSize=sizeof(ex);
			ex.hwnd=NULL;
			ex.lpFile= "InitDataBaseConFig.exe";
			ex.nShow=1;
			ex.fMask=SEE_MASK_NOCLOSEPROCESS;
			ShellExecuteEx(&ex);

			this->Free();
			exit(1);
		}
		else
		{
        	String versionstrpath = GlobalPath + "\\version.xml";
            ifstream versionIN(versionstrpath.t_str());

            char versionchar[20];
            ZeroMemory(versionchar, 20);
            if(versionIN)
            {
                versionIN.getline(versionchar, 20);
                VersionStr=versionchar;
                versionIN.close();
            }

			String databseinfostr = GlobalPath + "\\DataBaseParameter.ini";
			ifstream DataBaseInfoIN(databseinfostr.t_str());

			char dataservername[50];
			char databasename[20];
            ZeroMemory(dataservername, 50);
            ZeroMemory(databasename, 20);

			if(DataBaseInfoIN)
			{
				for(int tt = 0; tt < 2; tt++)
				{
					if(DataBaseInfoIN)
					{
						if(0 == tt)
						{
							DataBaseInfoIN.getline(dataservername, 50);
                            DataBaseServerName = dataservername;
						}
						if(1 == tt)
						{
							DataBaseInfoIN.getline(databasename, 20);
							DataBaseNameStr = databasename;
                        }
                    }
                }
            }

			String ValidConnectstr = "Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=";
			ValidConnectstr += databasename;
			ValidConnectstr += ";Data Source=";
			ValidConnectstr += dataservername;
			ADOConnection1->ConnectionString = ValidConnectstr;
			try
			{
				ADOConnection1->Open();
			}
			catch(...)
			{
				ShowMessage("数据库连接错误,请重新运行并设置数据库!");
				String tmpfilepathstr = GlobalPath + "\\IsFirstRun.tag";
				ofstream ResetfirstrunOut(tmpfilepathstr.t_str());
				ResetfirstrunOut<<1<<endl;
				UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
				this->Free();
				exit(1);
			}


			if(!SetLocaleInfoA(LOCALE_SYSTEM_DEFAULT,LOCALE_SSHORTDATE,"yyyy-MM-dd"))
			{
				UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
				ShowMessage("无法将系统日期格式设置成长日期格式，程序无法正常运行!");
				this->Free();
				exit(1);
			}

	  //  	String DateFormatStr = "yyyy-MM-dd";
            if(!SetLocaleInfoA(LOCALE_SYSTEM_DEFAULT,LOCALE_SLONGDATE,"yyyy-MM-dd"))
            {
            	UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
                ShowMessage("无法将系统日期格式设置成长日期格式，程序无法正常运行!");
                this->Free();
                exit(1);
            }

      //    String TimeFormatStr = "HH:mm:ss";
            if(!SetLocaleInfoA(LOCALE_SYSTEM_DEFAULT,LOCALE_STIMEFORMAT,"HH:mm:ss"))
            {
            	UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
                ShowMessage("无法将系统时间格式设置成长时间格式，程序无法正常运行!");
                this->Free();
                exit(1);
			}

			String datestr = DateToStr(Now());
			if(10 != datestr.Length())
			{
				UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
				ShowMessage("您的系统日期格式已经成功设置为长日期格式，请重启程序!");
				this->Free();
				exit(1);
			}

			String timestr = TimeToStr(Now());
			if(8 != timestr.Length())
			{
				UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
				ShowMessage("您的系统日期格式已经成功设置为长日期格式，请重启程序!");
				this->Free();
				exit(1);
			}

			UpdateZETable->Active = true;
			UpZETable = UpdateZETable;

            //判断是否有加密狗，卡参数在读卡器，姓名等参数入卡策略表
            InitADOQ->Close();
            InitADOQ->SQL->Clear();
            InitADOQ->SQL->Add("SELECT name FROM sysobjects where name='ModeSet'");
            InitADOQ->Open();
            if(InitADOQ->IsEmpty())//如果无则新建，默认不使用加密，卡参数在读卡器，姓名等参数不入卡
            {
                //创建ModeSet表，并根据参数设置ModeSet表
                InitADOQ->Close();
                InitADOQ->SQL->Clear();
                InitADOQ->SQL->Add("CREATE TABLE ModeSet (DOG int default 0, INREADER int default 1,INCARD int default 0)");
                InitADOQ->ExecSQL();
                InitADOQ->Close();
                InitADOQ->SQL->Clear();
                InitADOQ->SQL->Add("insert into ModeSet values(0,1,0)");
                InitADOQ->ExecSQL();
                InitADOQ->Close();
                DOGChk = false;
                ReaderChk = true;
                WriteNameChk = false;
            }
            else //表存在，则初始化三个变量
            {
            	InitADOQ->Close();
                InitADOQ->SQL->Clear();
                InitADOQ->SQL->Add("select * from ModeSet");
                InitADOQ->Open();
                DOGChk = InitADOQ->FieldByName("DOG")->AsInteger;
                ReaderChk = InitADOQ->FieldByName("INREADER")->AsInteger;
                WriteNameChk = InitADOQ->FieldByName("INCARD")->AsInteger;
                InitADOQ->Close();
            }
            //结束

            //检查加密狗
            DWORD retcode;
            int count;
            unsigned char  buf[16];
            int checkserial;
            unsigned char readbuf[113];
        	if(DOGChk)
            {
                memset(buf,0,sizeof(buf));
                memset(readbuf,0,sizeof(readbuf));
                count = 0;
                retcode = RY3_Find(buf, &count);
                if(!retcode)
                {
                    retcode = RY3_Open(&doghandle, 1);
                    if(!retcode)
                    {
                        int offset = 0x0001;
                        int len = 113;
                        retcode = RY3_Read(doghandle,offset,readbuf,len);
                        if(retcode)
                        {
                            UINT ExitCode;
                            TerminateProcess(e1.hProcess,ExitCode);
                            ShowMessage("无法找到读加密狗!");
                            this->Free();
                            exit(1);
                        }
                    }
                    else
                    {
                        UINT ExitCode;
                        TerminateProcess(e1.hProcess,ExitCode);
                        ShowMessage("无法找到读加密狗!");
                        this->Free();
                        exit(1);
                    }
                }
                else
                {
                    UINT ExitCode;
                    TerminateProcess(e1.hProcess,ExitCode);
                    ShowMessage("无法找到读加密狗!");
                    this->Free();
                    exit(1);
                }
                //检查完毕
            }

            if(DOGChk)
            {
    			//读加密狗内的信息，时间，随机数，充值总额--如为第一运行则初始化加密狗
                char randindog[32];
                ZeroMemory(randindog, 32);
                memcpy(randindog, &readbuf[19], 32);

                unsigned char hightempchar;
                unsigned char lowtempchar;
                for(int i = 0; i < 113; i++)
                {
                    hightempchar = readbuf[i]&0xf0;
                    lowtempchar = readbuf[i]&0x0f;

                    hightempchar = hightempchar>>4;
                    hightempchar = hightempchar&0x0f;

                    lowtempchar = lowtempchar<<4;
                    lowtempchar = lowtempchar&0xf0;

                    readbuf[i] = hightempchar|lowtempchar;
                }

                memcpy(goonpw, &readbuf[70], 12);
                memcpy(relvpw, &readbuf[82], 12);

                unsigned char hightempchar2;
                unsigned char lowtempchar2;
                for(int t = 0; t < 32; t++)
                {
                    hightempchar2 = randindog[t]&0xf0;
                    lowtempchar2 = randindog[t]&0x0f;

                    hightempchar2 = hightempchar2>>4;
                    hightempchar2 = hightempchar2&0x0f;

                    lowtempchar2 = lowtempchar2<<4;
                    lowtempchar2 = lowtempchar2&0xf0;

                    randindog[t] = hightempchar2|lowtempchar2;
                }

                memset(timebuf,0,17);
                memset(randbuf,0,32);
                memcpy(timebuf,readbuf,17);
                memcpy(randbuf,&readbuf[19],32);
                timetag = readbuf[17];
                times = readbuf[18];
                usetag = readbuf[51];
                checktime = readbuf[68];
                goontag = readbuf[69];
                unsigned char sfkzebuf[8];
                unsigned char skzebuf[8];
                memset(sfkzebuf,0,8);
                memset(skzebuf,0,8);
                memcpy(&SFK_ZE,&readbuf[52],8);
                memcpy(&SK_ZE,&readbuf[60],8);
                if(!timetag && !usetag)
                {
                    //检查数据库是否有已运行标识
                    String checkstr;
                    InitADOQ->Close();
                    InitADOQ->SQL->Clear();
                    InitADOQ->SQL->Add("select * from XTSET");
                    InitADOQ->Open();
                    if(!InitADOQ->IsEmpty())
                    {
                        checkstr = InitADOQ->FieldByName("SYSTag")->AsString;
                    }
                    InitADOQ->Close();
                    if(checkstr != "00000000000000000000000000000000")
                    {
                        if(checkstr != randindog)
                        {
                            UINT ExitCode;
                            TerminateProcess(e1.hProcess,ExitCode);
                            ShowMessage("程序、数据库与加密狗不匹配，无法运行!");
                            RY3_Close(doghandle,TRUE);
                            this->Free();
                            exit(1);
                        }
                    }

                    //检查完毕
                    unsigned char writebuf[68];
                    ZeroMemory(writebuf, 68);
                    char writerandbuf[32];
                    ZeroMemory(writerandbuf, 32);

                    String timestr = DateTimeToStr(Now());
                    memcpy(writebuf, timestr.t_str(),16);
                    writebuf[17] = 0x01;
                    writebuf[18] = times;
                    timetag = true;

                    srand((unsigned)time(NULL));
                    int tempposint = 0;
                    for(int i = 0; i < 32; i++)
                    {
                        tempposint = rand()%61;
                        writebuf[19+i] = CCH[tempposint];
                        writerandbuf[i] = CCH[tempposint];
                    }

                    writebuf[51] = 0x01;
                    usetag = true;


                    unsigned char hightempchar1;
                    unsigned char lowtempchar1;
                    for(int t = 0; t < 68; t++)
                    {
                        hightempchar1 = writebuf[t]&0xf0;
                        lowtempchar1 = writebuf[t]&0x0f;

                        hightempchar1 = hightempchar1>>4;
                        hightempchar1 = hightempchar1&0x0f;

                        lowtempchar1 = lowtempchar1<<4;
                        lowtempchar1 = lowtempchar1&0xf0;

                        writebuf[t] = hightempchar1|lowtempchar1;
                    }
                    //memcpy(writerandbuf, &writebuf[19], 32);

                    int writeoffset = 0x0001;
                    int writelen = 68;
                    DWORD writeretcode = RY3_Write(doghandle,writeoffset,writebuf,writelen);
                    if(writeretcode)
                    {
                        UINT ExitCode;
                        TerminateProcess(e1.hProcess,ExitCode);
                        ShowMessage("写加密狗错误，程序无法运行!");
                        RY3_Close(doghandle,TRUE);
                        this->Free();
                        exit(1);
                    }
    //				RY3_Close(doghandle,TRUE);
                    //32位随机数入库
                    InitADOQ->Close();
                    InitADOQ->SQL->Clear();
                    InitADOQ->SQL->Add("select * from XTSET");
                    InitADOQ->Open();
                    if(!InitADOQ->IsEmpty())
                    {
                        InitADOQ->Edit();
                        InitADOQ->FieldByName("SYSTag")->AsString = writerandbuf;
                        InitADOQ->Post();
                    }
                    InitADOQ->Close();
                }
                else
                {
                    //加密狗已启用，则判断是否与数据库匹配，并检查时间是否过期
                    String randinDBStr;
                    InitADOQ->Close();
                    InitADOQ->SQL->Clear();
                    InitADOQ->SQL->Add("select * from XTSET");
                    InitADOQ->Open();
                    if(!InitADOQ->IsEmpty())
                    {
                        randinDBStr = InitADOQ->FieldByName("SYSTag")->AsString;
                    }
                    InitADOQ->Close();

                    char dbstr[32];
                    memcpy(dbstr, randinDBStr.t_str(), 32);


                    for (int i = 0; i < 32; i++)
                    {
                        if(randindog[i] != dbstr[i])
                        {
                            UINT ExitCode;
                            TerminateProcess(e1.hProcess,ExitCode);
                            ShowMessage("程序、数据库与加密狗不匹配，无法运行!");
                            this->Free();
                            exit(1);
                        }
                    }

                    char timeindog[17];
                    ZeroMemory(timeindog, 17);
                    memcpy(timeindog, readbuf, 16);
                    TDateTime dogtime = StrToDateTime(timeindog);
                    TDateTime systime = Now();
                    if(checktime)
                    {
                        if(systime < dogtime)
                        {
                            UINT ExitCode;
                            TerminateProcess(e1.hProcess,ExitCode);
                            ShowMessage("系统时间与加密狗时间异常，无法运行!");
                            this->Free();
                            exit(1);
                        }
                        if(goontag)
                            times++;
                        dogtime = IncMonth(dogtime,times);
                        if(systime > dogtime)
                        {
                            UINT ExitCode;
                            TerminateProcess(e1.hProcess,ExitCode);
                            //继续使用密码输入，正确则延期使用一个月
                            GoonPWForm->ShowModal();
                        //	ShowMessage("软件已过试用期，无法运行!");
                        //	this->Free();
                        //	exit(1);
                        }
                    }

                    char lastruntime[20];
                    ZeroMemory(lastruntime, 20);
                    memcpy(lastruntime, &readbuf[94], 19);
                    TDateTime lasttimeindog = StrToDateTime(lastruntime);
                    TDateTime nowtime = Now();
                    if(checktime)
                    {
                        if(nowtime <= lasttimeindog)
                        {
                            UINT ExitCode;
                            TerminateProcess(e1.hProcess,ExitCode);
                            ShowMessage("系统时间更改，导致时间异常，无法运行!");
                            this->Free();
                            exit(1);
                        }
                        else if(nowtime > lasttimeindog)
                        {
                            //写dog本次运行时间
                            char runtime[20];
                            ZeroMemory(runtime, 20);
                            memcpy(runtime, DateTimeToStr(Now()).t_str(),19);
                            unsigned char timehightempchar;
                            unsigned char timelowtempchar;
                            for(int t = 0; t < 20; t++)
                            {
                                timehightempchar = runtime[t]&0xf0;
                                timelowtempchar = runtime[t]&0x0f;

                                timehightempchar = timehightempchar>>4;
                                timehightempchar = timehightempchar&0x0f;

                                timelowtempchar = timelowtempchar<<4;
                                timelowtempchar = timelowtempchar&0xf0;

                                runtime[t] = timehightempchar|timelowtempchar;
                            }
                            int timewriteoffset = 0x005E;
                            int timewritelen = 19;
                            DWORD timewriteretcode = RY3_Write(doghandle,
                                                            timewriteoffset,runtime,timewritelen);
                            if(timewriteretcode)
                            {
                                UINT ExitCode;
                                TerminateProcess(e1.hProcess,ExitCode);
                                ShowMessage("写加密狗错误，程序无法运行!");
                                RY3_Close(doghandle,TRUE);
                                this->Free();
                                exit(1);
                            }
                        }
                    }
                }

                //检查总消费额度
                double AllMoneyInDB = UpdateZETable->FieldByName("SFKZE")->AsFloat;
                if(AllMoneyInDB > SFK_ZE)
                {
                    unsigned char Moneyhightempchar;
                    unsigned char Moneylowtempchar;
                    unsigned char AllMoney[8];
                    memcpy(AllMoney, &AllMoneyInDB, 8);
                    for(int t = 0; t < 8; t++)
                    {
                        Moneyhightempchar = AllMoney[t]&0xf0;
                        Moneylowtempchar = AllMoney[t]&0x0f;

                        Moneyhightempchar = Moneyhightempchar>>4;
                        Moneyhightempchar = Moneyhightempchar&0x0f;

                        Moneylowtempchar = Moneylowtempchar<<4;
                        Moneylowtempchar = Moneylowtempchar&0xf0;

                        AllMoney[t] = Moneyhightempchar|Moneylowtempchar;
                    }
                    int Moneywriteoffset = 0x0034;
                    int Moneywritelen = 8;
                    DWORD timewriteretcode = RY3_Write(doghandle,
                                                    Moneywriteoffset,AllMoney,Moneywritelen);
                    if(timewriteretcode)
                    {
                        UINT ExitCode;
                        TerminateProcess(e1.hProcess,ExitCode);
                        ShowMessage("写加密狗错误，程序无法运行!");
                        RY3_Close(doghandle,TRUE);
                        this->Free();
                        exit(1);
                    }
                }

                //加密狗处理完毕
            }

			dllpath = GlobalPath + "\\reader.dll";
			LoadHModule = LoadLibraryA(dllpath.t_str());
			if(NULL == LoadHModule)
			{
				UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
				ShowMessage("加载读写卡动态链接库失败！");
				this->Free();
				exit(1);
			}
			else
			{
				beepofreaddll = (beepofread)GetProcAddress(LoadHModule, "beep");

			//	readcardinfo = (readinfo)GetProcAddress(LoadHModule,"readhb90card");
            	readwatercardinfo = (readwaterinfo)GetProcAddress(LoadHModule,"readwatercard");

				readserialfun = (readserial)GetProcAddress(LoadHModule, "testcard");

			//	LaunchNewCard = (LaunchCard)GetProcAddress(LoadHModule,"writehb90card");
            	LaunchWaterNewCard = (LaunchWaterCard)GetProcAddress(LoadHModule,"writewatercard");

				ClearCardInfoProc = (ClearCardInfo)GetProcAddress(LoadHModule, "clearwatercard");
				EncrptyCardMMProc = (EncrptyCardMM)GetProcAddress(LoadHModule, "get_card_mm");
				pacarddllprocreader = (Ppacarddll)GetProcAddress(LoadHModule, "pacarddll");

				if(beepofreaddll)
				{
					for(int i = 0; i <= 16; i++)
					{
						unsigned char tmpcomstr[5] = "COM0";
						unsigned char tmptime = '1';
						unsigned char tmpi[2] = "";
						itoa(i, tmpi, 10);
						tmpcomstr[3] = tmpi[0];
						if(0 == beepofreaddll(tmpcomstr, tmptime))
						{
							strcpy(readcomno, tmpcomstr);
							break;
						}
					}
				}

				if(!EncrptyCardMMProc)
				{
                    MessageBox(this->Handle, "加载加解密函数失败!", "Error", MB_OK|MB_ICONERROR);
                    this->Free();
                    exit(1);
                }
			}

			dllpath = path + "\\com485.dll";
			LoadCOMHModule = LoadLibraryA(dllpath.t_str());
			if(NULL == LoadCOMHModule)
			{
				UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
				ShowMessage("加载POS机动态链接库失败！");
				this->Free();
				exit(1);
			}
			else
			{
				SerReceiveFunc = (SerReceiveOFdll)GetProcAddress(LoadCOMHModule, "SerReceive");
				SerSendFunc = (SerSendOFdll)GetProcAddress(LoadCOMHModule, "SerSend");
				SendAckFunc = (SendAckOFdll)GetProcAddress(LoadCOMHModule, "SendAck");
				GetnormaldateFunc = (GetnormaldateOFdll)GetProcAddress(LoadCOMHModule, "getnormaldate");
				pacarddllproc = (Ppacarddll)GetProcAddress(LoadHModule, "pacarddll");
			}

			dllpath = path + "\\returnusbcom.dll";
			LoadUSBHModule = LoadLibraryA(dllpath.t_str());
			if(NULL == LoadUSBHModule)
			{
				UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
				ShowMessage("加载USB测试动态链接库失败！");
				this->Free();
				exit(1);
			}
			else
			{
				getusbcomportdll = (GETUSBCOMPORT)GetProcAddress(LoadUSBHModule, "returnusbcom");
			}

			String CQKlogfilepath = path + "\\LOG\\CQKLog.dat";
//			String Collectlogfilepath = path + "\\LOG\\CollectLog.dat";

			CQKLogStream.open(CQKlogfilepath.t_str(), ios::app);
			if(!CQKLogStream)
			{
				UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
				ShowMessage("打开存取款日志文档失败！");
				this->Free();
				exit(1);
			}


			InitADOQ->Close();
			InitADOQ->SQL->Clear();
			InitADOQ->SQL->Add("alter table OperationList alter column Operator char(30)");
			InitADOQ->ExecSQL();

			//判断SYSUSER表中是否有priority字段
			InitADOQ->Close();
			InitADOQ->SQL->Clear();
			InitADOQ->SQL->Add("select * from syscolumns where id=object_id('SYSUSER') and name='priority'");
			InitADOQ->Open();
			if(InitADOQ->IsEmpty())
			{
				InitADOQ->Close();
				InitADOQ->SQL->Clear();
				InitADOQ->SQL->Add("alter table SYSUSER add priority char(50) null");
				InitADOQ->ExecSQL();
			}
			else
			{
            	InitADOQ->Close();
				InitADOQ->SQL->Clear();
				InitADOQ->SQL->Add("alter table SYSUSER alter column priority char(50)");
				InitADOQ->ExecSQL();
            }
			//end判断priority
/*
            if(ReaderChk)
            {
                //读取读卡器中的卡密码，密码版本及使用扇区
                String tmpReadercode;
                char ReadercodeStr[16];
                unsigned char tmpsendlen = 0x03;
                unsigned char tmpdelay = 0x00;
                unsigned char tmpsendbuf[140];
                ZeroMemory(tmpsendbuf, 140);
                unsigned char tmprecbuf[140];
                ZeroMemory(tmprecbuf, 140);
                unsigned char tmpreclen;
                tmpsendbuf[0] = 0xC0;
                tmpsendbuf[1] = 0x08;
                tmpsendbuf[2] = 0x22;
                WORD tmpstatus = pacarddllprocreader(readcomno, tmpsendlen, tmpsendbuf, &tmpreclen, tmprecbuf,tmpdelay);
                if(!tmpstatus)
                {
                    for(int m = 3; m < (int)tmpreclen; m++)
                    {
                        tmpReadercode += IntToHex(Byte(tmprecbuf[m]),2);
                    }
                }

                InitADOQ->Close();
                InitADOQ->SQL->Clear();
                InitADOQ->SQL->Add("select * from XTSET");
                InitADOQ->Open();
                if(!InitADOQ->IsEmpty())
                {
                    if(tmpReadercode.Length() == 16)
                    {
              //  	 	InitADOQ->Edit();
              //        InitADOQ->FieldByName("CARDMM")->AsString = tmpReadercode;
              //        InitADOQ->Post();
        				//解密卡片密码
                        char tReadercodeStr[16];
              //          AnsiString tmpCARDPassword = InitADOQ->FieldByName("CARDMM")->AsAnsiString.Trim();
              //          memcpy(tReadercodeStr, tmpCARDPassword.c_str(), 16);
              			memcpy(tReadercodeStr, tmpReadercode.t_str(), 16);
                        unsigned char oldpassword[8];
                        unsigned char newpassword[8];
                        int hpassword,lpassword;
                        for(int i = 0; i < 8; i++)
                        {
                            if(tReadercodeStr[i*2]>0x2f&&tReadercodeStr[i*2]<0x3a)
                                hpassword = ((byte)tReadercodeStr[i*2]-0x30)*16;
                            else if(tReadercodeStr[i*2]>0x40&&tReadercodeStr[i*2]<0x47)
                                hpassword = ((byte)tReadercodeStr[i*2]-0x41+10)*16;
                            else if(tReadercodeStr[i*2]>0x60&&tReadercodeStr[i*2]<0x67)
                                hpassword = ((byte)tReadercodeStr[i*2]-0x61+10)*16;
                            else
                            {
                                //wrong code
                                memset(oldpassword, 0xff, 8);
                                break;
                            }

                            if(tReadercodeStr[i*2+1]>0x2f&&tReadercodeStr[i*2+1]<0x3a)
                                hpassword = hpassword+((byte)tReadercodeStr[i*2+1]-0x30);
                            else if(tReadercodeStr[i*2+1]>0x40&&tReadercodeStr[i*2+1]<0x47)
                                hpassword = hpassword+((byte)tReadercodeStr[i*2+1]-0x41+10);
                            else if(tReadercodeStr[i*2+1]>0x60&&tReadercodeStr[i*2+1]<0x67)
                                hpassword = hpassword+((byte)tReadercodeStr[i*2+1]-0x61+10);
                            else
                            {
                                //wrong code
                                memset(oldpassword, 0xff, 8);
                                break;
                            }

                            oldpassword[i] = (unsigned char)hpassword;
                        }

                        EncrptyCardMMProc(0x01, oldpassword, newpassword);
                        for(int i = 0; i < 6; i++)
                        {
                            CARDPassword[i] = newpassword[i];
                        }
                        CARDPasswordEdition = newpassword[6];
                        UsingSecNUM = newpassword[7];
                //        //show card mm
                //        String chkmmstr = "";
                //        for(int i = 0; i < 6; i++)
                //        {
                //        	chkmmstr += IntToHex(Byte(CARDPassword[i]),2);
                //        }
                //        ShowMessage(chkmmstr);
                        //end show
              			//show pwedition
               //         chkmmstr = "pwedition:";
               //         chkmmstr += IntToHex(Byte(CARDPasswordEdition),2);
               //         chkmmstr += "  secnum:";
               //         chkmmstr += IntToHex(Byte(UsingSecNUM),2);
               //         ShowMessage(chkmmstr);

                        //end show
                        //end
                    }
                }
                memcpy(ReadercodeStr, tmpReadercode.t_str(), 16);

                //end
            }

			ZeroMemory(PosInUseTag, 300);

			InitADOQ->Close();
			InitADOQ->SQL->Clear();
			InitADOQ->SQL->Add("select * from XTSET");
			InitADOQ->Open();
			if(!InitADOQ->IsEmpty())
			{
            	Panel3->Caption = InitADOQ->FieldByName("Caption")->AsAnsiString.Trim();
				this->Caption = "IC卡收费管理系统";//InitADOQ->FieldByName("SYSTEMNAME")->AsAnsiString.Trim();
				SYSTEMDISPLAYNAME = InitADOQ->FieldByName("SYSTEMNAME")->AsAnsiString.Trim();

				String tmpDWPassword = InitADOQ->FieldByName("DWMM")->AsAnsiString.Trim();
				for(int t=0; t < 2; t++)
				{
					int tmpint = StrToInt("0x"+tmpDWPassword.SubString(t*2+1, 2));
					IntToUChar(tmpint, &DWPassword[t]);
				}


				unsigned char TCARDPassword[16];
				char Enchar[9];
				char Dechar[8];
				ZeroMemory(TCARDPassword, 16);
				ZeroMemory(Enchar, 9);
				ZeroMemory(Dechar, 8);

                if(!ReaderChk)
                {
                //原始版本：密码不写入读卡器
       		   		AnsiString tmpCARDPassword = InitADOQ->FieldByName("CARDMM")->AsAnsiString.Trim();
                    memcpy(TCARDPassword, tmpCARDPassword.c_str(), 16);

                    for(int i = 0; i < 8; i++)
                    {
                        int tmpint = StrToInt("0x"+tmpCARDPassword.SubString(i*2+1, 2));
                        IntToUChar(tmpint, &Enchar[i]);
                    }
                    EncrptyCardMMProc(1, Enchar, Dechar);

                    for(int i = 0; i<6; i++)
                    {
                        CARDPassword[i] = Dechar[i];
                    }

                    for(int i = 0; i<6; i++)
                    {
                        unsigned char tmpchar = CARDPassword[i];

                        itoa((tmpchar>>4)&0x0f, &DECCARDPassword[i*2], 16);
                        itoa(tmpchar&0x0f, &DECCARDPassword[i*2+1], 16);
                    }
                    IntToUChar(InitADOQ->FieldByName("USINGSEC")->AsInteger, &UsingSecNUM);
                    IntToUChar(InitADOQ->FieldByName("MMEDITION")->AsInteger, &CARDPasswordEdition);
                }

                unsigned char TSuperPassword[16];
                char SEnchar[9];
                char SDechar[8];
				ZeroMemory(TSuperPassword, 16);
                ZeroMemory(SEnchar, 9);
                ZeroMemory(SDechar, 8);
                AnsiString tmpSuperPassword = InitADOQ->FieldByName("SuperPW")->AsAnsiString.Trim();

				for(int i = 0; i < 8; i++)
				{
					int tmpint = StrToInt("0x"+tmpSuperPassword.SubString(i*2+1, 2));
					IntToUChar(tmpint, &SEnchar[i]);
				}
				EncrptyCardMMProc(1, SEnchar, SDechar);

				for(int i = 0; i<6; i++)
				{
					SuperPasword[i] = SDechar[i];
				}

                char tmpsuperpwchar;
				for(int i = 0; i<6; i++)
				{
					unsigned char tmpchar = SuperPasword[i];

					itoa((tmpchar>>4)&0x0f, &tmpsuperpwchar, 16);
                    DECSuperPassword[i*2] = tmpsuperpwchar;
					itoa(tmpchar&0x0f, &tmpsuperpwchar, 16);
                    DECSuperPassword[i*2+1] = tmpsuperpwchar;
				}

				GlobalFKYJ = InitADOQ->FieldByName("FKYJ")->AsInteger;
				GlobalTKYJ = InitADOQ->FieldByName("TKYJ")->AsInteger;

				DelaySecond = 0x00;
		   //		CARDPasswordEdition = newpassword[6];
		   //		UsingSecNUM = newpassword[7];
			}
			else
			{
				UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
				ShowMessage("系统设置表为空，不能运行该程序!请联系技术人员!");
				InitADOQ->Close();
				this->Free();
				exit(1);
			}
			InitADOQ->Close();     */

            //water paramete
            InitADOQ->Close();
			InitADOQ->SQL->Clear();
			InitADOQ->SQL->Add("select * from XTSET");
			InitADOQ->Open();
			if(!InitADOQ->IsEmpty())
			{
            	Panel3->Caption = InitADOQ->FieldByName("Caption")->AsAnsiString.Trim();
				this->Caption = "IC卡水控管理系统";//InitADOQ->FieldByName("SYSTEMNAME")->AsAnsiString.Trim();
				SYSTEMDISPLAYNAME = InitADOQ->FieldByName("SYSTEMNAME")->AsAnsiString.Trim();

				String tmpDWPassword = InitADOQ->FieldByName("DWMM")->AsAnsiString.Trim();
				for(int t=0; t < 2; t++)
				{
					int tmpint = StrToInt("0x"+tmpDWPassword.SubString(t*2+1, 2));
					IntToUChar(tmpint, &DWPassword[t]);
				}


	   /*			unsigned char TCARDPassword[16];
				char Enchar[9];
				char Dechar[8];
				ZeroMemory(TCARDPassword, 16);
				ZeroMemory(Enchar, 9);
				ZeroMemory(Dechar, 8);

                if(!ReaderChk)
                {
                //原始版本：密码不写入读卡器
       		   		AnsiString tmpCARDPassword = InitADOQ->FieldByName("CARDMM")->AsAnsiString.Trim();
                    memcpy(TCARDPassword, tmpCARDPassword.c_str(), 16);

                    for(int i = 0; i < 8; i++)
                    {
                        int tmpint = StrToInt("0x"+tmpCARDPassword.SubString(i*2+1, 2));
                        IntToUChar(tmpint, &Enchar[i]);
                    }
                    EncrptyCardMMProc(1, Enchar, Dechar);

                    for(int i = 0; i<6; i++)
                    {
                        CARDPassword[i] = Dechar[i];
                    }

                    for(int i = 0; i<6; i++)
                    {
                        unsigned char tmpchar = CARDPassword[i];

                        itoa((tmpchar>>4)&0x0f, &DECCARDPassword[i*2], 16);
                        itoa(tmpchar&0x0f, &DECCARDPassword[i*2+1], 16);
                    }
                    IntToUChar(InitADOQ->FieldByName("USINGSEC")->AsInteger, &UsingSecNUM);
                    IntToUChar(InitADOQ->FieldByName("MMEDITION")->AsInteger, &CARDPasswordEdition);
                }       */

                unsigned char TSuperPassword[16];
                char SEnchar[9];
                char SDechar[8];
				ZeroMemory(TSuperPassword, 16);
                ZeroMemory(SEnchar, 9);
                ZeroMemory(SDechar, 8);
                AnsiString tmpSuperPassword = InitADOQ->FieldByName("SuperPW")->AsAnsiString.Trim();

				for(int i = 0; i < 8; i++)
				{
					int tmpint = StrToInt("0x"+tmpSuperPassword.SubString(i*2+1, 2));
					IntToUChar(tmpint, &SEnchar[i]);
				}
				EncrptyCardMMProc(1, SEnchar, SDechar);

				for(int i = 0; i<6; i++)
				{
					SuperPasword[i] = SDechar[i];
				}

                char tmpsuperpwchar;
				for(int i = 0; i<6; i++)
				{
					unsigned char tmpchar = SuperPasword[i];

					itoa((tmpchar>>4)&0x0f, &tmpsuperpwchar, 16);
                    DECSuperPassword[i*2] = tmpsuperpwchar;
					itoa(tmpchar&0x0f, &tmpsuperpwchar, 16);
                    DECSuperPassword[i*2+1] = tmpsuperpwchar;
				}

				GlobalFKYJ = InitADOQ->FieldByName("FKYJ")->AsInteger;
				GlobalTKYJ = InitADOQ->FieldByName("TKYJ")->AsInteger;

				DelaySecond = 0x00;
		   //		CARDPasswordEdition = newpassword[6];
		   //		UsingSecNUM = newpassword[7];
			}
			else
			{
				UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
				ShowMessage("系统设置表为空，不能运行该程序!请联系技术人员!");
				InitADOQ->Close();
				this->Free();
				exit(1);
			}
			InitADOQ->Close();


            InitADOQ->Close();
            InitADOQ->SQL->Clear();
            InitADOQ->SQL->Add("select * from WXTSET");
            InitADOQ->Open();
            if(!InitADOQ->IsEmpty())
            {
            //    ComNumcombox->ItemIndex = InitADOQ->FieldByName("COMPORT")->AsInteger-1;
            //    SecNumcomboBox->ItemIndex = InitADOQ->FieldByName("SECNUM")->AsInteger;
            //    MMeditionEdit->Text = InitADOQ->FieldByName("MMEdition")->AsInteger;
            //    MMEdit->Text = InitADOQ->FieldByName("CARDMM")->AsString.Trim();

                unsigned char tmpcomstr[5] = "COM0";
                unsigned char tmptime = '1';
                unsigned char tmpi[2] = "";
                itoa(StrToInt(InitADOQ->FieldByName("COMPORT")->AsInteger), tmpi, 10);
                tmpcomstr[3] = tmpi[0];
                strcpy(readcomno, tmpcomstr);


                unsigned char TCARDPassword[16];
                AnsiString tmpCARDPassword = InitADOQ->FieldByName("CARDMM")->AsAnsiString.Trim();
                memcpy(TCARDPassword, tmpCARDPassword.c_str(), 16);

                for(int i = 0; i < 6; i++)
                {
                    int tmpint = StrToInt("0x"+tmpCARDPassword.SubString(i*2+1, 2));
                    IntToUChar(tmpint, &CARDPassword[i]);
                }

                IntToUChar(InitADOQ->FieldByName("SECNUM")->AsInteger, &UsingSecNUM);
                IntToUChar(InitADOQ->FieldByName("MMEDITION")->AsInteger, &CARDPasswordEdition);
            }
            else
			{
				UINT ExitCode;
				TerminateProcess(e1.hProcess,ExitCode);
				ShowMessage("系统设置表为空，不能运行该程序!请联系技术人员!");
				InitADOQ->Close();
				this->Free();
				exit(1);
			}

            InitADOQ->Close();
            //end water parameter

			InitADOQ->SQL->Clear();
			InitADOQ->SQL->Add("select * from secnum");
			InitADOQ->Open();
			if(!InitADOQ->IsEmpty())
			{
				maxconsumption = InitADOQ->FieldByName("daymaxxf")->AsInteger;
				maxconsumption1 = InitADOQ->FieldByName("daymaxxf1")->AsInteger;
				maxconsumption2 = InitADOQ->FieldByName("daymaxxf2")->AsInteger;
				maxconsumption3 = InitADOQ->FieldByName("daymaxxf3")->AsInteger;
				maxconsumption4 = InitADOQ->FieldByName("daymaxxf4")->AsInteger;
			}
			InitADOQ->Close();

            InitADOQ->Close();
            InitADOQ->SQL->Clear();
            InitADOQ->SQL->Add("select count(*) as recnum from MX");
            InitADOQ->Open();
            if(InitADOQ->FieldByName("recnum")->AsInteger >= 500000)
            {
            	InitADOQ->Close();
                InitADOQ->SQL->Clear();
                InitADOQ->SQL->Add("insert into MXBAK(BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ) select BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ from MX");
                InitADOQ->ExecSQL();
                InitADOQ->Close();
                InitADOQ->SQL->Clear();
                InitADOQ->SQL->Add("truncate table MX");
                InitADOQ->ExecSQL();
            }
			InitADOQ->Close();

			UpdateZETable->Active = true;

			//启动挂失线程
/*			if(!PostLostInfoThead)
			{
				GSADOT->Active = true;
				if(GSADOT->Active)
				{
					PostLostInfoThead = new TPostLostInfoThread(true, GSADOT);
					if(PostLostInfoThead)
						PostLostInfoThead->Resume();
					else
					{
						UINT ExitCode;
						TerminateProcess(e1.hProcess,ExitCode);
						ShowMessage("挂失模块启动异常，挂失操作无法进行，请联系技术人员!");
						this->Free();
						exit(1);
					}
				}
				else
				{
					ShowMessage("无法连接到挂失数据库(CMDLIST)!");
				}
			}  */
		}
	}
	else
	{
		UINT ExitCode;
		TerminateProcess(e1.hProcess,ExitCode);
		ShowMessage("缺少系统必须的“IsFirstRun.tag”文件，请联系技术人员!");
		this->Free();
		exit(1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item1Click(TObject *Sender)
{
	TRect rect = Panel11->ClientRect;
	SystemConfigFRM->Dock(Panel11, rect);
	SystemConfigFRM->Show();
	SystemConfigFRM->ADOTable1->Active = true;

	if("系统管理员" == OperatorGroupName)
	{
		SystemConfigFRM->BTUnitName->Enabled = true;
		SystemConfigFRM->TBUnitPassword->Enabled = true;
		SystemConfigFRM->TBDeliverCardDeposit->Enabled = true;
		SystemConfigFRM->TBCancelCardDeposit->Enabled = true;
		SystemConfigFRM->TBCardPassWord->Enabled = true;
		SystemConfigFRM->TBPasswordEdtion->Enabled = true;
		SystemConfigFRM->TBUsingSector->Enabled = true;
		SystemConfigFRM->TBDailyMaxConsumption->Enabled = true;
		SystemConfigFRM->TBDailyMaxConsumption1->Enabled = true;
		SystemConfigFRM->TBDailyMaxConsumption2->Enabled = true;
		SystemConfigFRM->TBDailyMaxConsumption3->Enabled = true;
		SystemConfigFRM->TBDailyMaxConsumption4->Enabled = true;
		SystemConfigFRM->TBMaxPosNUM->Enabled = true;
	}
	else
	{
		SystemConfigFRM->BTUnitName->Enabled = false;
		SystemConfigFRM->TBUnitPassword->Enabled = false;
		SystemConfigFRM->TBDeliverCardDeposit->Enabled = false;
		SystemConfigFRM->TBCancelCardDeposit->Enabled = false;
		SystemConfigFRM->TBCardPassWord->Enabled = false;
		SystemConfigFRM->TBPasswordEdtion->Enabled = false;
		SystemConfigFRM->TBUsingSector->Enabled = false;
		SystemConfigFRM->TBDailyMaxConsumption->Enabled = false;
		SystemConfigFRM->TBDailyMaxConsumption1->Enabled = false;
		SystemConfigFRM->TBDailyMaxConsumption2->Enabled = false;
		SystemConfigFRM->TBDailyMaxConsumption3->Enabled = false;
		SystemConfigFRM->TBDailyMaxConsumption4->Enabled = false;
		SystemConfigFRM->TBMaxPosNUM->Enabled = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item2Click(TObject *Sender)
{
	if(!ModeOFCollect)
	{
		TRect rect = Panel11->ClientRect;
		PosConfigFRM->Dock(Panel11, rect);
		PosConfigFRM->Show();
		if("系统管理员" == OperatorGroupName)
		{
		//	PosConfigFRM->ScanPosBTN->Enabled = false;
			PosConfigFRM->AddOneBTN->Enabled = false;
			PosConfigFRM->DelOneBTN->Enabled = false;
		}
		else
		{
			PosConfigFRM->ScanPosBTN->Enabled = false;
			PosConfigFRM->AddOneBTN->Enabled = false;
			PosConfigFRM->DelOneBTN->Enabled = false;
		}
	}
	else
	{
		ShowMessage("您正在进行数据采集，请先退出数据采集再进行该操作!");
	}
//	dxNavBar1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item5Click(TObject *Sender)
{
	TRect rect = Panel11->ClientRect;
	CheckWriteReadMachineFRM->Dock(Panel11, rect);
	CheckWriteReadMachineFRM->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item6Click(TObject *Sender)
{
	TRect rect = Panel11->ClientRect;
	SectionInfoManageFRM->Dock(Panel11, rect);
	SectionInfoManageFRM->Show();
}
//---------------------------------------------------------------------------


void __fastcall TSDIAppForm::dxNavBar1Item8Click(TObject *Sender)
{
/*	LaunchNewUserCardFRM->NumberOFCardTextEdit->Text = "";
	LaunchNewUserCardFRM->SerialOFCardTextEdit->Text = "";
	LaunchNewUserCardFRM->UserNameTextEdit->Text = "";
	LaunchNewUserCardFRM->UserSexComboBox->ItemIndex = -1;
	LaunchNewUserCardFRM->SectionNameComboBox->ItemIndex = -1;
	LaunchNewUserCardFRM->ClassNameComboBox->ItemIndex = -1;
	LaunchNewUserCardFRM->DegreeComboBox->ItemIndex = -1;
	LaunchNewUserCardFRM->GroupNameComboBox->ItemIndex = -1;
	LaunchNewUserCardFRM->cxTextEdit4->Text = "1";
	LaunchNewUserCardFRM->IdentityIDTextEdit->Text = "";
	LaunchNewUserCardFRM->DegreeTextEdit->Text = "1";
	LaunchNewUserCardFRM->PerPassWordTextEdit->Text = "";
	LaunchNewUserCardFRM->DepositTextEdit->Text = GlobalFKYJ;
	LaunchNewUserCardFRM->PrepayTextEdit->Text = "";
	LaunchNewUserCardFRM->ConsumeRateComboBox->ItemIndex = 0;
	LaunchNewUserCardFRM->cxLabel20->Caption = "0.00"; */
	TRect rect = Panel11->ClientRect;
	LaunchNewUserCardFRM->Dock(Panel11, rect);
	LaunchNewUserCardFRM->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item9Click(TObject *Sender)
{
	TRect rect = Panel11->ClientRect;
	ReadCardInfoFRM->Dock(Panel11, rect);
	ReadCardInfoFRM->Show();
	ReadCardInfoFRM->cxTextEdit1->Text = "";
	ReadCardInfoFRM->cxTextEdit2->Text = "";
	ReadCardInfoFRM->cxTextEdit3->Text = "";
	ReadCardInfoFRM->cxTextEdit4->Text = "";
	ReadCardInfoFRM->cxTextEdit5->Text = "";
	ReadCardInfoFRM->cxTextEdit6->Text = "";
	ReadCardInfoFRM->cxTextEdit7->Text = "";
	ReadCardInfoFRM->cxTextEdit9->Text = "";
    ReadCardInfoFRM->SectionNameComboBox->Text = "";
    ReadCardInfoFRM->ClassNameComboBox->Text = "";
    ReadCardInfoFRM->DegreeComboBox->Text = "";
    ReadCardInfoFRM->GroupNameComboBox->Text = "";
	ReadCardInfoFRM->cxTextEdit10->Text = "";
	ReadCardInfoFRM->cxTextEdit11->Text = "";
	ReadCardInfoFRM->cxTextEdit12->Text = "";
	ReadCardInfoFRM->cxTextEdit15->Text = "";
	ReadCardInfoFRM->cxTextEdit16->Text = "";
	ReadCardInfoFRM->cxTextEdit17->Text = "";
	ReadCardInfoFRM->cxTextEdit18->Text = "";
	ReadCardInfoFRM->cxTextEdit8->Text = "";
//    ReadCardInfoFRM->MXBTN->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item10Click(TObject *Sender)
{
	TRect rect = Panel11->ClientRect;
	CardRechargeMoneyFRM->Dock(Panel11, rect);
	CardRechargeMoneyFRM->Show();
	CardRechargeMoneyFRM->cxTextEdit1->Text = "";
	CardRechargeMoneyFRM->cxTextEdit2->Text = "";
	CardRechargeMoneyFRM->cxTextEdit3->Text = "";
	CardRechargeMoneyFRM->cxTextEdit4->Text = "";
	CardRechargeMoneyFRM->cxTextEdit5->Text = "";
	CardRechargeMoneyFRM->cxTextEdit6->Text = "";
	CardRechargeMoneyFRM->cxTextEdit7->Text = "";
	CardRechargeMoneyFRM->cxTextEdit8->Text = "";
	CardRechargeMoneyFRM->cxTextEdit9->Text = "";
	CardRechargeMoneyFRM->cxTextEdit10->Text = "";
	CardRechargeMoneyFRM->cxTextEdit11->Text = "";
	CardRechargeMoneyFRM->cxTextEdit12->Text = "";
	CardRechargeMoneyFRM->cxTextEdit15->Text = "";
	CardRechargeMoneyFRM->cxTextEdit16->Text = "";
	CardRechargeMoneyFRM->cxTextEdit17->Text = "";
	CardRechargeMoneyFRM->cxTextEdit18->Text = "";
    CardRechargeMoneyFRM->ReCharge5BTN->Enabled = false;
    CardRechargeMoneyFRM->ReCharge10BTN->Enabled = false;
    CardRechargeMoneyFRM->ReCharge20BTN->Enabled = false;
    CardRechargeMoneyFRM->ReCharge30BTN->Enabled = false;
    CardRechargeMoneyFRM->ReCharge40BTN->Enabled = false;
    CardRechargeMoneyFRM->ReCharge50BTN->Enabled = false;
    CardRechargeMoneyFRM->ReCharge60BTN->Enabled = false;
    CardRechargeMoneyFRM->ReCharge70BTN->Enabled = false;
    CardRechargeMoneyFRM->ReCharge80BTN->Enabled = false;
    CardRechargeMoneyFRM->ReCharge90BTN->Enabled = false;
    CardRechargeMoneyFRM->ReCharge100BTN->Enabled = false;
	CardRechargeMoneyFRM->ReCharge150BTN->Enabled = false;
	CardRechargeMoneyFRM->ReCharge200BTN->Enabled = false;
	CardRechargeMoneyFRM->ReCharge500BTN->Enabled = false;
	CardRechargeMoneyFRM->ReCharge1000BTN->Enabled = false;
	CardRechargeMoneyFRM->cxButton1->Enabled = false;
	CardRechargeMoneyFRM->cxButton2->Enabled = false;
	CardRechargeMoneyFRM->cxButton3->Enabled = false;
	CardRechargeMoneyFRM->cxButton4->Enabled = false;
	CardRechargeMoneyFRM->cxButton5->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item11Click(TObject *Sender)
{
	TRect rect = Panel11->ClientRect;
	CardWithDrawMoneyFRM->Dock(Panel11, rect);
	CardWithDrawMoneyFRM->Show();
	CardWithDrawMoneyFRM->cxTextEdit1->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit2->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit3->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit4->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit5->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit6->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit7->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit8->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit9->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit10->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit11->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit12->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit15->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit16->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit17->Text = "";
	CardWithDrawMoneyFRM->cxTextEdit18->Text = "";

    CardWithDrawMoneyFRM->WithDraw5BTN->Enabled = false;
    CardWithDrawMoneyFRM->WithDraw10BTN->Enabled = false;
    CardWithDrawMoneyFRM->WithDraw20BTN->Enabled = false;
    CardWithDrawMoneyFRM->WithDraw30BTN->Enabled = false;
    CardWithDrawMoneyFRM->WithDraw40BTN->Enabled = false;
    CardWithDrawMoneyFRM->WithDraw50BTN->Enabled = false;
    CardWithDrawMoneyFRM->WithDraw60BTN->Enabled = false;
    CardWithDrawMoneyFRM->WithDraw70BTN->Enabled = false;
    CardWithDrawMoneyFRM->WithDraw80BTN->Enabled = false;
    CardWithDrawMoneyFRM->WithDraw90BTN->Enabled = false;
    CardWithDrawMoneyFRM->WithDraw100BTN->Enabled = false;
    CardWithDrawMoneyFRM->WithDraw150BTN->Enabled = false;
    CardWithDrawMoneyFRM->WithDraw200BTN->Enabled = false;
    CardWithDrawMoneyFRM->WithDraw500BTN->Enabled = false;
    CardWithDrawMoneyFRM->WithDraw1000BTN->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item12Click(TObject *Sender)
{
//	ShowMessage("注意，要确保收费机得数据全部已成功采集，否则报表会出现帐不平！");
	TRect rect = Panel11->ClientRect;
	CardCanceledFRM->Dock(Panel11, rect);
	CardCanceledFRM->Show();
	CardCanceledFRM->cxTextEdit1->Text = "";
	CardCanceledFRM->cxTextEdit2->Text = "";
	CardCanceledFRM->cxTextEdit3->Text = "";
	CardCanceledFRM->cxTextEdit4->Text = "";
	CardCanceledFRM->cxTextEdit5->Text = "";
	CardCanceledFRM->cxTextEdit6->Text = "";
	CardCanceledFRM->cxTextEdit7->Text = "";
	CardCanceledFRM->cxTextEdit8->Text = "";
	CardCanceledFRM->cxTextEdit9->Text = "";
	CardCanceledFRM->cxTextEdit10->Text = "";
	CardCanceledFRM->cxTextEdit11->Text = "";
	CardCanceledFRM->cxTextEdit12->Text = "";
	CardCanceledFRM->cxTextEdit15->Text = "";
	CardCanceledFRM->cxTextEdit17->Text = "";
	CardCanceledFRM->cxTextEdit18->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item17Click(TObject *Sender)
{
	TRect rect = Panel11->ClientRect;
	DeleteCardInfoFrom->Dock(Panel11, rect);
	DeleteCardInfoFrom->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item18Click(TObject *Sender)
{
/*	if("系统管理员" == OperatorGroupName)
	{
        TRect rect = Panel11->ClientRect;
        MakeAssistancedFRM->Dock(Panel11, rect);
        MakeAssistancedFRM->Show();
    }
    else
    {
		ShowMessage("您不是系统管理员，不能使用“生成补贴”功能!");
	}  */
	TRect rect = Panel11->ClientRect;
	MakeAssistancedFRM->Dock(Panel11, rect);
	MakeAssistancedFRM->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item19Click(TObject *Sender)
{
	if(!ModeOFCollect)
	{
/*        if("系统管理员" == OperatorGroupName)
        {
            TRect rect = Panel11->ClientRect;
            BTDownloadFrm->Dock(Panel11, rect);
            BTDownloadFrm->Show();
        }
        else
        {
            ShowMessage("您不是系统管理员，不能使用“下传补贴”功能!");
		}   */
		TRect rect = Panel11->ClientRect;
		BTDownloadFrm->Dock(Panel11, rect);
		BTDownloadFrm->Show();
    }
    else
    {
        ShowMessage("您正在进行数据采集，所以不能下载补贴，请先退出数据采集!");
    }
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::FormShow(TObject *Sender)
{
	LoginFrom->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item22Click(TObject *Sender)
{
	ShowMessage("注意，要确保收费机的数据全部已成功采集，否则报表会出现帐不平！");
	TRect rect = Panel11->ClientRect;
	RecordLostCardFRM->Dock(Panel11, rect);
	RecordLostCardFRM->Show();

	RecordLostCardFRM->cxTextEdit1->Text = "";
	RecordLostCardFRM->cxTextEdit2->Text = "";
	RecordLostCardFRM->cxTextEdit3->Text = "";
	RecordLostCardFRM->cxTextEdit4->Text = "";
	RecordLostCardFRM->cxTextEdit5->Text = "";
	RecordLostCardFRM->cxTextEdit6->Text = "";
	RecordLostCardFRM->cxTextEdit7->Text = "";
	RecordLostCardFRM->cxTextEdit8->Text = "";
	RecordLostCardFRM->cxTextEdit9->Text = "";
	RecordLostCardFRM->cxTextEdit10->Text = "";
	RecordLostCardFRM->cxTextEdit11->Text = "";
	RecordLostCardFRM->cxTextEdit12->Text = "";
	RecordLostCardFRM->cxTextEdit13->Text = "";
	RecordLostCardFRM->cxTextEdit14->Text = "";
	RecordLostCardFRM->cxTextEdit15->Text = "";
	RecordLostCardFRM->cxTextEdit16->Text = "";
	RecordLostCardFRM->cxTextEdit17->Text = "";
	RecordLostCardFRM->cxTextEdit19->Text = "";

	RecordLostCardFRM->NextBTN->Enabled = false;
	RecordLostCardFRM->NextBTN->Visible = false;
	RecordLostCardFRM->PutLostInfoBTN->Enabled = false;
	RecordLostCardFRM->DelLostInfoBTN->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item23Click(TObject *Sender)
{
	if(!ModeOFCollect)
	{
//		if("系统管理员" == OperatorGroupName)
//		{
        	ShowMessage("注意，要确保收费机的数据全部已成功采集，否则报表会出现帐不平！");
			TRect rect = Panel11->ClientRect;
			LostCardInfoDownloadFRM->Dock(Panel11, rect);
			LostCardInfoDownloadFRM->Show();

		//	LostCardInfoDownloadFRM->POSListView->Clear();
		//	LostCardInfoDownloadFRM->SCanProBar->Position = 0;
		//	LostCardInfoDownloadFRM->GJBTN->Enabled = false;

			LostCardInfoDownloadFRM->DGSBTN->Enabled = false;
			LostCardInfoDownloadFRM->GABTN->Enabled = false;
//		}
//		else
//		{
//			ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
//		}
	}
	else
	{
    	ShowMessage("您正在进行数据采集，请先退出数据采集再进行该操作!");
    }
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item24Click(TObject *Sender)
{
//	if(mrOk == MessageBox(this->Handle, "该功能必须在采集完数据后进行，请确保采集完数据", "请确认", MB_OKCANCEL|MB_ICONWARNING))
//	{
		TRect rect = Panel11->ClientRect;
		ResendLostCardnewFRM->Dock(Panel11, rect);
		ResendLostCardnewFRM->Show();

		ResendLostCardnewFRM->cxRadioButton1->Checked = false;
		ResendLostCardnewFRM->cxRadioButton2->Checked = false;
		ResendLostCardnewFRM->cxRadioButton3->Checked = false;
		ResendLostCardnewFRM->cxRadioButton4->Checked = false;

		ResendLostCardnewFRM->NextBTN->Enabled = false;
		ResendLostCardnewFRM->NextBTN->Visible = false;
		ResendLostCardnewFRM->cxButton2->Enabled = false;
		ResendLostCardnewFRM->cxButton3->Enabled = false;

		ResendLostCardnewFRM->cxTextEdit1->Enabled = false;
		ResendLostCardnewFRM->cxTextEdit1->Text = "";
		ResendLostCardnewFRM->cxTextEdit2->Enabled = false;
		ResendLostCardnewFRM->cxTextEdit2->Text = "";
		ResendLostCardnewFRM->cxTextEdit3->Enabled = false;
		ResendLostCardnewFRM->cxTextEdit3->Text = "";
		ResendLostCardnewFRM->cxTextEdit4->Enabled = false;
		ResendLostCardnewFRM->cxTextEdit4->Text = "";

		ResendLostCardnewFRM->cxTextEdit14->Text = "";
	//	ResendLostCardnewFRM->cxTextEdit18->Text = "";
	//	ResendLostCardnewFRM->cxTextEdit20->Text = "";

		ResendLostCardnewFRM->cxTextEdit5->Text = "";
		ResendLostCardnewFRM->cxTextEdit6->Text = "";
		ResendLostCardnewFRM->cxTextEdit7->Text = "";
		ResendLostCardnewFRM->cxTextEdit8->Text = "";
		ResendLostCardnewFRM->cxTextEdit9->Text = "";
		ResendLostCardnewFRM->cxTextEdit10->Text = "";
		ResendLostCardnewFRM->cxTextEdit11->Text = "";
		ResendLostCardnewFRM->cxTextEdit12->Text = "";
		ResendLostCardnewFRM->cxTextEdit13->Text = "";
		ResendLostCardnewFRM->cxTextEdit15->Text = "";
		ResendLostCardnewFRM->cxTextEdit16->Text = "";
		ResendLostCardnewFRM->cxTextEdit17->Text = "";
		ResendLostCardnewFRM->cxTextEdit19->Text = "";
//	}
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item25Click(TObject *Sender)
{
	if(mrOk == MessageBox(this->Handle, "该功能必须在采集完数据后进行，请确保采集完数据", "请确认", MB_OKCANCEL|MB_ICONWARNING))
	{
		TRect rect = Panel11->ClientRect;
		FireLostCardInfoFRM->Dock(Panel11, rect);
		FireLostCardInfoFRM->Show();

		FireLostCardInfoFRM->cxRadioButton1->Checked = false;
		FireLostCardInfoFRM->cxRadioButton2->Checked = false;
		FireLostCardInfoFRM->cxRadioButton3->Checked = false;
		FireLostCardInfoFRM->cxRadioButton4->Checked = false;

		FireLostCardInfoFRM->NextBTN->Enabled = false;
		FireLostCardInfoFRM->NextBTN->Visible = false;

		FireLostCardInfoFRM->cxButton2->Enabled = false;

		FireLostCardInfoFRM->cxTextEdit1->Enabled = false;
		FireLostCardInfoFRM->cxTextEdit1->Text = "";
		FireLostCardInfoFRM->cxTextEdit2->Enabled = false;
		FireLostCardInfoFRM->cxTextEdit2->Text = "";
		FireLostCardInfoFRM->cxTextEdit3->Enabled = false;
		FireLostCardInfoFRM->cxTextEdit3->Text = "";
		FireLostCardInfoFRM->cxTextEdit4->Enabled = false;
		FireLostCardInfoFRM->cxTextEdit4->Text = "";

		FireLostCardInfoFRM->cxTextEdit5->Text = "";
		FireLostCardInfoFRM->cxTextEdit6->Text = "";
		FireLostCardInfoFRM->cxTextEdit7->Text = "";
		FireLostCardInfoFRM->cxTextEdit8->Text = "";
		FireLostCardInfoFRM->cxTextEdit9->Text = "";
		FireLostCardInfoFRM->cxTextEdit10->Text = "";
		FireLostCardInfoFRM->cxTextEdit11->Text = "";
		FireLostCardInfoFRM->cxTextEdit12->Text = "";
		FireLostCardInfoFRM->cxTextEdit13->Text = "";
        FireLostCardInfoFRM->cxTextEdit14->Text = "";
		FireLostCardInfoFRM->cxTextEdit15->Text = "";
		FireLostCardInfoFRM->cxTextEdit16->Text = "";
		FireLostCardInfoFRM->cxTextEdit17->Text = "";
		FireLostCardInfoFRM->cxTextEdit18->Text = IntToStr(GlobalTKYJ);
		FireLostCardInfoFRM->cxTextEdit19->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item26Click(TObject *Sender)
{
	if((2 != ModeOFCollect)&&(3 != ModeOFCollect)&&(4 != ModeOFCollect)&&(5 != ModeOFCollect))
	{
		if(!ModeOFCollect)
		{
			TRect rect = Panel11->ClientRect;
			RealTimeCollectFRM->Dock(Panel11, rect);
			RealTimeCollectFRM->ScallProgressBar->Visible = true;
			RealTimeCollectFRM->ScallProgressBar->Position = 0;
			RealTimeCollectFRM->CollectProgressBar->Visible = false;
			RealTimeCollectFRM->DataDisplayView->Items->Clear();
			RealTimeCollectFRM->Show();
		}

		if(1 == ModeOFCollect)
		{
			TRect rect = Panel11->ClientRect;
			RealTimeCollectFRM->Dock(Panel11, rect);
			RealTimeCollectFRM->Show();
        }
	}
	else
	{
		if(2 == ModeOFCollect)
			ShowMessage("您正在进行“批量数据采集入库”，请先退出“批量数据采集入库”再进行“实时数据采集入库”！");
		if(3 == ModeOFCollect)
			ShowMessage("您正在进行“选定批量数据采集”，请先退出“选定批量数据采集”再进行“实时数据采集入库”！");
        if(4 == ModeOFCollect)
            ShowMessage("您正在进行“采集到文件&&从文件入库”，请先退出“选定批量数据采集”再进行“实时数据采集入库”！");
    	if(5 == ModeOFCollect)
        	ShowMessage("您正在进行“实时数据采集”，请先退出“实时数据采集”再进行“实时数据采集入库”！");
	}
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item27Click(TObject *Sender)
{
	if((1 != ModeOFCollect)&&(3 != ModeOFCollect)&&(4 != ModeOFCollect)&&(5 != ModeOFCollect))
	{
		if(!ModeOFCollect)
		{
			TRect rect = Panel11->ClientRect;
			BatchCollectFRM->Dock(Panel11, rect);
			BatchCollectFRM->ScallProgressBar->Visible = true;
			BatchCollectFRM->ScallProgressBar->Position = 0;
			BatchCollectFRM->CollectProgressBar->Visible = false;
			BatchCollectFRM->DisPlayListView->Items->Clear();
			BatchCollectFRM->Show();
		}

		if(2 == ModeOFCollect)
		{
			TRect rect = Panel11->ClientRect;
			BatchCollectFRM->Dock(Panel11, rect);
			BatchCollectFRM->Show();
        }
	}
	else
	{
		if(1 == ModeOFCollect)
			ShowMessage("您正在进行“实时数据采集入库”，请先退出“实时数据采集入库”再进行“批量数据采集”！");
		if(3 == ModeOFCollect)
			ShowMessage("您正在进行“选定批量数据采集”，请先退出“选定批量数据采集”再进行“批量数据采集”！");
        if(4 == ModeOFCollect)
        	ShowMessage("您正在进行“采集到文件&&从文件入库”，请先退出“选定批量数据采集”再进行“批量数据采集”！");
    	if(5 == ModeOFCollect)
        	ShowMessage("您正在进行“实时数据采集”，请先退出“实时数据采集”再进行“批量数据采集”！");
	}

}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item37Click(TObject *Sender)
{
	if((1 != ModeOFCollect)&&(2 != ModeOFCollect)&&(4 != ModeOFCollect)&&(5 != ModeOFCollect))
	{
		if(!ModeOFCollect)
		{
			TRect rect = Panel11->ClientRect;
			CheckBatchCollectFRM->Dock(Panel11, rect);
			CheckBatchCollectFRM->ScallProgressBar->Visible = true;
			CheckBatchCollectFRM->ScallProgressBar->Position = 0;
			CheckBatchCollectFRM->CollectProgressBar->Visible = false;
			CheckBatchCollectFRM->DisPlayListView->Items->Clear();
			CheckBatchCollectFRM->Show();
		}

		if(3 == ModeOFCollect)
		{
			TRect rect = Panel11->ClientRect;
			CheckBatchCollectFRM->Dock(Panel11, rect);
			CheckBatchCollectFRM->Show();
		}
	}
	else
	{
		if(1 == ModeOFCollect)
			ShowMessage("您正在进行“实时数据采集入库”，请先退出“实时数据采集入库”再进行“选定批量数据采集”！");
		if(2 == ModeOFCollect)
			ShowMessage("您正在进行“批量数据采集”，请先退出“批量数据采集”再进行“选定批量数据采集”！");
        if(4 == ModeOFCollect)
        	ShowMessage("您正在进行“采集到文件&&从文件入库”，请先退出“批量数据采集”再进行“选定批量数据采集”！");
    	if(5 == ModeOFCollect)
        	ShowMessage("您正在进行“实时数据采集”，请先退出“实时数据采集”再进行“选定批量数据采集”！");
    }
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item4Click(TObject *Sender)
{
	if((1 != ModeOFCollect)&&(2 != ModeOFCollect)&&(4 != ModeOFCollect)&&(3 != ModeOFCollect))
	{
		if(!ModeOFCollect)
		{
			TRect rect = Panel11->ClientRect;
			RealCollectWOIBFrm->Dock(Panel11, rect);
			RealCollectWOIBFrm->ScallProgressBar->Visible = true;
			RealCollectWOIBFrm->ScallProgressBar->Position = 0;
			RealCollectWOIBFrm->CollectProgressBar->Visible = false;
			RealCollectWOIBFrm->DataDisplayView->Items->Clear();
			RealCollectWOIBFrm->Show();
		}

		if(5 == ModeOFCollect)
		{
			TRect rect = Panel11->ClientRect;
			RealCollectWOIBFrm->Dock(Panel11, rect);
			RealCollectWOIBFrm->Show();
		}
	}
	else
	{
		if(1 == ModeOFCollect)
			ShowMessage("您正在进行“实时数据采集入库”，请先退出“实时数据采集入库”再进行“实时数据采集”！");
		if(2 == ModeOFCollect)
			ShowMessage("您正在进行“批量数据采集”，请先退出“批量数据采集”再进行“实时数据采集”！");
        if(4 == ModeOFCollect)
        	ShowMessage("您正在进行“采集到文件&&从文件入库”，请先退出“批量数据采集”再进行“实时数据采集”！");
    	if(3 == ModeOFCollect)
        	ShowMessage("您正在进行“选定批量数据采集”，请先退出“选定批量数据采集”再进行“实时数据采集”！");
    }
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if(PosContag)
		ShowMessage("正在进行POS机参数设置，必须退出“POS机参数设置”才能进行其他操作!");
	if(PostLostInfotag)
		ShowMessage("正在进行POS机信息补齐，必须退出“POS机信息补齐”才能进行其他操作!");
    if(CreateBTtag)
        ShowMessage("正在进行补贴生成，必须退出“补贴生成”才能进行其他操作!");
    if(DownloadBTtag)
    	ShowMessage("正在进行补贴下传，必须退出“下传补贴”才能进行其他操作!");
	if(BatchLaunchCardtag)
		ShowMessage("正在进行批量发卡，必须退出“批量发卡”才能进行其他操作!");
	if(BatchGStag)
		ShowMessage("正在进行批量挂失登记，必须退出“批量挂失登记”才能进行其他操作!");
	if(fixrecordtag)
		ShowMessage("正在进行数据记录修复，必须退出“批量挂失登记”才能进行其他操作!");
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::Timer1Timer(TObject *Sender)
{
	cxMaskEdit1->Text = DateToStr(Date())+ "  " + TimeToStr(Now());
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item35Click(TObject *Sender)
{
//	if("系统管理员" == OperatorGroupName)
//	{
        TRect rect = Panel11->ClientRect;
        BatchLaunchCardForm->Dock(Panel11, rect);
        BatchLaunchCardForm->Show();
/*    }
    else
	{
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	} */
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	int showtag = BackUpDatafrm->ShowModal();

	if(mrOk == showtag)//MessageBox(this->Handle, "是否在退出程序前进行数据库备份", "请确认", MB_OKCANCEL|MB_ICONQUESTION))
	{
		String backuppath = GlobalPath;
		backuppath += "\\DataBackUp\\";
		String sqlstr = "exec p_backupdb @bkpath='";
		sqlstr += backuppath;
		sqlstr += "',@bkfname='db_\\DATE\\_\\TIME\\_db.bak',@dbname='";
		sqlstr += DataBaseNameStr;
		sqlstr += "'";
		BackUpADOQ->Close();
		BackUpADOQ->SQL->Clear();
		BackUpADOQ->SQL->Add(sqlstr);
		BackUpADOQ->ExecSQL();
		BackUpADOQ->Close();
		ShowMessage("数据库备份完毕!");
		if(CQKLogStream)
			CQKLogStream.close();
    }

    if(mrCancel == showtag)
    {
        CanClose=false;
	}

	if(mrNo == showtag)
	{
		BackUpADOQ->Close();
        BackUpADOQ->SQL->Clear();
        String sqlStr = "insert into OperationList values(:BH,:KH,:JE,:YE,:LX,:Operator,:DateTime)";
        BackUpADOQ->SQL->Add(sqlStr);
        BackUpADOQ->Parameters->ParamByName("BH")->Value = -1;//LaunchNewCardADOQ->FieldByName("BH")->AsString;
        BackUpADOQ->Parameters->ParamByName("KH")->Value = -1;
        BackUpADOQ->Parameters->ParamByName("JE")->Value = 0;
        BackUpADOQ->Parameters->ParamByName("YE")->Value = 0;
        BackUpADOQ->Parameters->ParamByName("LX")->Value = "退出";
        BackUpADOQ->Parameters->ParamByName("Operator")->Value = OperatorName;
        BackUpADOQ->Parameters->ParamByName("DateTime")->Value = DateTimeToStr(Now());
        BackUpADOQ->ExecSQL();
		if(CQKLogStream)
			CQKLogStream.close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item39Click(TObject *Sender)
{
/*	if("系统管理员" == OperatorGroupName)
    {
    	TRect rect = Panel11->ClientRect;
        BonusInfoExportForm->Dock(Panel11, rect);
        BonusInfoExportForm->Show();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}   */
	TRect rect = Panel11->ClientRect;
	BonusInfoExportForm->Dock(Panel11, rect);
	BonusInfoExportForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item40Click(TObject *Sender)
{
/*	if(IDOK == MessageBox(this->Handle, "该操作将把数据还原为初始状态，您确认要还原数据库吗?", "Notice",MB_OKCANCEL|MB_ICONQUESTION))
    {
    	String curdir = GlobalPath;
        curdir += "\\InitDataBase";
        String timestr = DateToStr(Now());
        SYSTEMTIME st;
		GetSystemTime(&st);
        timestr += "_";
        timestr += (st.wHour+8)%24;
        timestr += "#";
        timestr += st.wMinute;
        timestr += "#";
        timestr += st.wSecond;

        ReStoreADOQ->Close();
        String sqlstr = "RESTORE DATABASE ";
        sqlstr += DataBaseNameStr;
        sqlstr += " FROM DISK='";
        sqlstr += curdir;
        sqlstr += "\\InitData' WITH REPLACE,move 'sf_Data' to '";
        sqlstr += curdir;
        sqlstr += "\\";
        sqlstr += timestr;
        sqlstr += ".mdf',move 'sf_Log' to '";
        sqlstr += curdir;
        sqlstr += "\\";
        sqlstr += timestr;
        sqlstr += ".ldf',recovery";

        ADOConnection1->Connected = false;
        ADOConnection1->ConnectionString = "";

        String connstr = "Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Data Source=";
        connstr += DataBaseServerName;
        ReStoreADOQ->ConnectionString = connstr;
        ReStoreADOQ->SQL->Clear();
        ReStoreADOQ->SQL->Add(sqlstr);
        try
        {
            ReStoreADOQ->ExecSQL();
        }
        catch(EOleException& e)
        {
            ShowMessage(e.Message);
            ReStoreADOQ->Close();
            return;
        }
        ShowMessage("新建数据库成功!");
    }                                */

	if((1 != ModeOFCollect)&&(2 != ModeOFCollect)&&(3 != ModeOFCollect)&&(5 != ModeOFCollect))
	{
		if(!ModeOFCollect)
		{
            if("系统管理员" == OperatorGroupName)
            {
                TRect rect = Panel11->ClientRect;
                DataToFileFrm->Dock(Panel11, rect);
                DataToFileFrm->Show();
            }
            else
            {
                ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
            }
        }
        if(4 == ModeOFCollect)
		{
            if("系统管理员" == OperatorGroupName)
            {
                TRect rect = Panel11->ClientRect;
                DataToFileFrm->Dock(Panel11, rect);
                DataToFileFrm->Show();
            }
            else
            {
                ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
            }
    	}
    }
    else
    {
		if(1 == ModeOFCollect)
			ShowMessage("您正在进行“实时数据采集入库”，请先退出“实时数据采集入库”再进行“采集到文件&&从文件入库”！");
		if(2 == ModeOFCollect)
			ShowMessage("您正在进行“批量数据采集”，请先退出“批量数据采集”再进行“采集到文件&&从文件入库”！");
        if(3 == ModeOFCollect)
        	ShowMessage("您正在进行“选定批量数据采集”，请先退出“批量数据采集”再进行“采集到文件&&从文件入库”！");
        if(5 == ModeOFCollect)
        	ShowMessage("您正在进行“实时数据采集”，请先退出“实时数据采集”再进行“采集到文件&&从文件入库”！");
    }
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item41Click(TObject *Sender)
{
/*
	if("系统管理员" == OperatorGroupName)
	{
		CZMXQFrm->ShowModal();
	}
	else
	{
		ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}*/
	CZMXQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item42Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
		QKMXQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}*/
	QKMXQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item7Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
		PreOrderQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}  */
	PreOrderQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item43Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
		XFMXQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	} */
	XFMXQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item44Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
		CARDQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}    */
	CARDQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item45Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
		CBQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}    */
	CBQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item46Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
		CTQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}     */
	CTQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item47Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
		JHQFrm->ShowModal();
	}
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}          */
	JHQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item48Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
	{
		BMQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}    */
	BMQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item49Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
		KYQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}           */
	KYQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item50Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
		TKQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}      */
	TKQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item51Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
		GSQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}  */
	GSQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item52Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
		EMXQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}      */
	EMXQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item54Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
		CZLQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}          */
	CZLQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item55Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
	{
		CZYJSQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}     */
	CZYJSQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item53Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
		SZHZQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}      */
	SZHZQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item57Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
		XFTJQFrm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}         */
	XFTJQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item15Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
    {
    	BKMXQForm->ShowModal();
    }
    else
    {
    	ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}              */
	BKMXQForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Group8Click(TObject *Sender)
{
	ReportClick = 1;
	if(ModeOFCollect)
	{
        ShowMessage("您正在进行数据采集，为保证数据的完整性，必须退出数据采集才能进行报表操作!");
        dxNavBar1Item41->Enabled = false;
		dxNavBar1Item42->Enabled = false;
        dxNavBar1Item43->Enabled = false;
        dxNavBar1Item44->Enabled = false;
        dxNavBar1Item45->Enabled = false;
        dxNavBar1Item46->Enabled = false;
        dxNavBar1Item47->Enabled = false;
        dxNavBar1Item48->Enabled = false;
        dxNavBar1Item49->Enabled = false;
        dxNavBar1Item50->Enabled = false;
        dxNavBar1Item51->Enabled = false;
        dxNavBar1Item52->Enabled = false;
        dxNavBar1Item53->Enabled = false;
        dxNavBar1Item54->Enabled = false;
        dxNavBar1Item55->Enabled = false;
        dxNavBar1Item56->Enabled = false;
        dxNavBar1Item57->Enabled = false;
        dxNavBar1Item39->Enabled = false;
        dxNavBar1Item15->Enabled = false;
        dxNavBar1Item16->Enabled = false;
        dxNavBar1Item30->Enabled = false;
        return;
    }

    //建立puremx表做mx备份
    MXTOBAKADOQ->Close();
	MXTOBAKADOQ->SQL->Clear();
	MXTOBAKADOQ->SQL->Add("SELECT name FROM sysobjects where name='PureMX'");
	MXTOBAKADOQ->Open();
    if(MXTOBAKADOQ->IsEmpty())
    {
        //SELECT * into puremx from mxbak where 0=1
        MXTOBAKADOQ->Close();
        MXTOBAKADOQ->SQL->Clear();
        MXTOBAKADOQ->SQL->Add("SELECT * into PureMX from MXBAK where 0=1");
        MXTOBAKADOQ->ExecSQL();
        MXTOBAKADOQ->Close();
        MXTOBAKADOQ->SQL->Clear();
		MXTOBAKADOQ->SQL->Add("insert into PureMX(BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ) select BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ from MXBAK");
		MXTOBAKADOQ->ExecSQL();
		MXTOBAKADOQ->Close();
    }

    MXTOBAKADOQ->Close();
	MXTOBAKADOQ->SQL->Clear();
	MXTOBAKADOQ->SQL->Add("SELECT * FROM MXBAK");
	MXTOBAKADOQ->Open();
    if(MXTOBAKADOQ->IsEmpty())
    {
    	MXTOBAKADOQ->Close();
        MXTOBAKADOQ->SQL->Clear();
        MXTOBAKADOQ->SQL->Add("SELECT * FROM PureMX");
        MXTOBAKADOQ->Open();
        if(!MXTOBAKADOQ->IsEmpty())
        {
        	MXTOBAKADOQ->Close();
            MXTOBAKADOQ->SQL->Clear();
            MXTOBAKADOQ->SQL->Add("insert into MXBAK(BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ) select BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ from PureMX");
            MXTOBAKADOQ->ExecSQL();
        }
    }

    //建立pureCK表做ck备份
    MXTOBAKADOQ->Close();
	MXTOBAKADOQ->SQL->Clear();
	MXTOBAKADOQ->SQL->Add("SELECT name FROM sysobjects where name='PureCK'");
	MXTOBAKADOQ->Open();
    if(MXTOBAKADOQ->IsEmpty())
    {
        //SELECT * into puremx from mxbak where 0=1
        MXTOBAKADOQ->Close();
        MXTOBAKADOQ->SQL->Clear();
        MXTOBAKADOQ->SQL->Add("SELECT * into PureCK from CK where 0=1");
        MXTOBAKADOQ->ExecSQL();
        MXTOBAKADOQ->Close();
 		MXTOBAKADOQ->SQL->Clear();
		MXTOBAKADOQ->SQL->Add("insert into PureCK(kh,bh,sf_ye,sf_fl,ckxj,glf,ckje,lqbt,xkje,sycs,sfrq,jyno,gzzid,sflx,CZY) select kh,bh,sf_ye,sf_fl,ckxj,glf,ckje,lqbt,xkje,sycs,sfrq,jyno,gzzid,sflx,CZY from CK");
		MXTOBAKADOQ->ExecSQL();
		MXTOBAKADOQ->Close();
    }

    MXTOBAKADOQ->Close();
	MXTOBAKADOQ->SQL->Clear();
	MXTOBAKADOQ->SQL->Add("SELECT * FROM CK");
	MXTOBAKADOQ->Open();
    if(MXTOBAKADOQ->IsEmpty())
    {
    	MXTOBAKADOQ->Close();
        MXTOBAKADOQ->SQL->Clear();
        MXTOBAKADOQ->SQL->Add("SELECT * FROM PureCK");
        MXTOBAKADOQ->Open();
        if(!MXTOBAKADOQ->IsEmpty())
        {
        	MXTOBAKADOQ->Close();
            MXTOBAKADOQ->SQL->Clear();
            MXTOBAKADOQ->SQL->Add("insert into CK(kh,bh,sf_ye,sf_fl,ckxj,glf,ckje,lqbt,xkje,sycs,sfrq,jyno,gzzid,sflx,CZY) select kh,bh,sf_ye,sf_fl,ckxj,glf,ckje,lqbt,xkje,sycs,sfrq,jyno,gzzid,sflx,CZY from PureCK");
            MXTOBAKADOQ->ExecSQL();
        }
    }

	MXTOBAKADOQ->Close();
	MXTOBAKADOQ->SQL->Clear();
	MXTOBAKADOQ->SQL->Add("select count(*) as allrec from MX");
	MXTOBAKADOQ->Open();
	if(MXTOBAKADOQ->FieldByName("allrec")->AsInteger>0)
	{
    	MXTOBAKADOQ->Close();
		MXTOBAKADOQ->SQL->Clear();
		MXTOBAKADOQ->SQL->Add("insert into PureMX(BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ) select BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ from MX");
		MXTOBAKADOQ->ExecSQL();
		MXTOBAKADOQ->Close();
		MXTOBAKADOQ->SQL->Clear();
		MXTOBAKADOQ->SQL->Add("insert into MXBAK(BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ) select BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ from MX");
		MXTOBAKADOQ->ExecSQL();
		MXTOBAKADOQ->Close();
		MXTOBAKADOQ->SQL->Clear();
		MXTOBAKADOQ->SQL->Add("truncate table MX");
		MXTOBAKADOQ->ExecSQL();
		MXTOBAKADOQ->Close();
		MXTOBAKADOQ->SQL->Clear();
		MXTOBAKADOQ->SQL->Add("select BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,min(SCRQ) as SCRQ into #Tmp from MXBAK group by BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY drop table MXBAK select * into MXBAK from #Tmp drop table #Tmp");
//		MXTOBAKADOQ->SQL->Add("select distinct BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ into #Tmp from MXBAK drop table MXBAK select * into MXBAK from #Tmp drop table #Tmp");
		MXTOBAKADOQ->ExecSQL();
		MXTOBAKADOQ->Close();

		MXTOBAKADOQ->SQL->Clear();
		MXTOBAKADOQ->SQL->Add("select kh,bh,sf_ye,sf_fl,ckxj,glf,ckje,lqbt,xkje,sycs,sfrq,jyno,gzzid,sflx,CZY into #ttmp from CK group by kh,bh,sf_ye,sf_fl,ckxj,glf,ckje,lqbt,xkje,sycs,sfrq,jyno,gzzid,sflx,CZY drop table CK select * into CK from #ttmp drop table #ttmp alter table CK add pkey int identity(1,1)");
//		MXTOBAKADOQ->SQL->Add("select distinct BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ into #Tmp from MXBAK drop table MXBAK select * into MXBAK from #Tmp drop table #Tmp");
		MXTOBAKADOQ->ExecSQL();
		MXTOBAKADOQ->Close();

		//CREATE INDEX SF_YE ON MXBAK (BH,KH,SYCS,SFRQ);
/*		MXTOBAKADOQ->SQL->Clear();
		MXTOBAKADOQ->SQL->Add("CREATE INDEX SF_YE ON MXBAK (BH,KH,SYCS,SFRQ");
//		MXTOBAKADOQ->SQL->Add("select distinct BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ into #Tmp from MXBAK drop table MXBAK select * into MXBAK from #Tmp drop table #Tmp");
		MXTOBAKADOQ->ExecSQL();
		MXTOBAKADOQ->Close();  */
	}
	MXTOBAKADOQ->Close();

	if('1' == globalqx[23])
		dxNavBar1Item41->Enabled = true;
	else
		dxNavBar1Item41->Enabled = false;

	if('1' == globalqx[24])
		dxNavBar1Item42->Enabled = true;
	else
		dxNavBar1Item42->Enabled = false;

	if('1' == globalqx[25])
		dxNavBar1Item43->Enabled = true;
	else
		dxNavBar1Item43->Enabled = false;

	if('1' == globalqx[26])
		dxNavBar1Item16->Enabled = true;
	else
		dxNavBar1Item16->Enabled = false;

	if('1' == globalqx[27])
		dxNavBar1Item44->Enabled = true;
	else
		dxNavBar1Item44->Enabled = false;

	if('1' == globalqx[28])
		dxNavBar1Item45->Enabled = true;
	else
		dxNavBar1Item45->Enabled = false;

	if('1' == globalqx[29])
		dxNavBar1Item46->Enabled = true;
	else
		dxNavBar1Item46->Enabled = false;

	if('1' == globalqx[30])
		dxNavBar1Item47->Enabled = true;
	else
		dxNavBar1Item47->Enabled = false;

	if('1' == globalqx[31])
		dxNavBar1Item48->Enabled = true;
	else
		dxNavBar1Item48->Enabled = false;

	if('1' == globalqx[32])
		dxNavBar1Item49->Enabled = true;
	else
		dxNavBar1Item49->Enabled = false;

	if('1' == globalqx[33])
		dxNavBar1Item50->Enabled = true;
	else
		dxNavBar1Item50->Enabled = false;

	if('1' == globalqx[34])
		dxNavBar1Item15->Enabled = true;
	else
		dxNavBar1Item15->Enabled = false;

	if('1' == globalqx[35])
		dxNavBar1Item51->Enabled = true;
	else
		dxNavBar1Item51->Enabled = false;

	if('1' == globalqx[36])
		dxNavBar1Item52->Enabled = true;
	else
		dxNavBar1Item52->Enabled = false;

	if('1' == globalqx[37])
		dxNavBar1Item53->Enabled = true;
	else
		dxNavBar1Item53->Enabled = false;

	if('1' == globalqx[38])
		dxNavBar1Item57->Enabled = true;
	else
		dxNavBar1Item57->Enabled = false;

	if('1' == globalqx[39])
		dxNavBar1Item54->Enabled = true;
	else
		dxNavBar1Item54->Enabled = false;

	if('1' == globalqx[40])
		dxNavBar1Item56->Enabled = true;
	else
		dxNavBar1Item56->Enabled = false;

	if('1' == globalqx[41])
		dxNavBar1Item39->Enabled = true;
	else
		dxNavBar1Item39->Enabled = false;

	if('1' == globalqx[42])
		dxNavBar1Item30->Enabled = true;
	else
		dxNavBar1Item30->Enabled = false;

	if('1' == globalqx[43])
		dxNavBar1Item55->Enabled = true;
	else
		dxNavBar1Item55->Enabled = false;

/*    dxNavBar1Item41->Enabled = true;
    dxNavBar1Item42->Enabled = true;
    dxNavBar1Item43->Enabled = true;
    dxNavBar1Item44->Enabled = true;
    dxNavBar1Item45->Enabled = true;
    dxNavBar1Item46->Enabled = true;
    dxNavBar1Item47->Enabled = true;
    dxNavBar1Item48->Enabled = true;
    dxNavBar1Item49->Enabled = true;
    dxNavBar1Item50->Enabled = true;
    dxNavBar1Item51->Enabled = true;
    dxNavBar1Item52->Enabled = true;
    dxNavBar1Item53->Enabled = true;
    dxNavBar1Item54->Enabled = true;
    dxNavBar1Item55->Enabled = true;
    dxNavBar1Item56->Enabled = true;
    dxNavBar1Item57->Enabled = true;
    dxNavBar1Item39->Enabled = true;
    dxNavBar1Item15->Enabled = true;
    dxNavBar1Item16->Enabled = true;
	dxNavBar1Item30->Enabled = true;  */
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Group1Click(TObject *Sender)
{
	ReportClick = 0;
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Group2Click(TObject *Sender)
{
	ReportClick = 0;
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Group6Click(TObject *Sender)
{
	ReportClick = 0;
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Group5Click(TObject *Sender)
{
	ReportClick = 0;
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Group3Click(TObject *Sender)
{
	ReportClick = 0;
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Group4Click(TObject *Sender)
{
	ReportClick = 0;
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::Panel3DblClick(TObject *Sender)
{
//	FixTitleForm->cxTextEdit1->Text = Panel3->Caption;
//	FixTitleForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item3Click(TObject *Sender)
{
	ConfirmDataFrm->ShowModal();
/*	if(IDOK == MessageBox(this->Handle, "您确认进行“旧数据备份”吗?", "提示", MB_OKCANCEL|MB_ICONQUESTION))
	{
		StoreMXADOQ->Close();
        StoreMXADOQ->SQL->Clear();
        StoreMXADOQ->SQL->Add("insert into OLDMX(BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ) select BH,KH,SF_YE,SFJE,SYCS,SFRQ,JYNO,GZZID,SFLX,CZY,SCRQ from MXBAK");
        StoreMXADOQ->ExecSQL();
        StoreMXADOQ->Close();
        StoreMXADOQ->SQL->Clear();
        StoreMXADOQ->SQL->Add("truncate table MXBAK");
        StoreMXADOQ->ExecSQL();
        StoreMXADOQ->Close();
		MessageBox(this->Handle, "旧数据备份成功,备份数据保存在数据库OLDMX表中,无特殊情况请不要对OLDMX表进行操作!", "提示", MB_OK);
	}*/
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item13Click(TObject *Sender)
{
	TRect rect = Panel11->ClientRect;
	DealHJLFRM->Dock(Panel11, rect);
	DealHJLFRM->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item14Click(TObject *Sender)
{
	TRect rect = Panel11->ClientRect;
	BigWalletFrm->Dock(Panel11, rect);
	BigWalletFrm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::ShowStatus()
{
	PosStatusForm->ShowModal();
}

//---------------------------------------------------------------------------
void __fastcall TSDIAppForm::dxNavBar1Item36Click(TObject *Sender)
{
//批量挂失
	TRect rect = Panel11->ClientRect;
	BatchGSForm->Dock(Panel11, rect);
	BatchGSForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item28Click(TObject *Sender)
{
//误收处理
	TRect rect = Panel11->ClientRect;
	DealMistakeForm->Dock(Panel11, rect);
	DealMistakeForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item16Click(TObject *Sender)
{
/*	if("系统管理员" == OperatorGroupName)
	{
		SKMXQFrm->ShowModal();
	}
	else
	{
		ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}      */
	SKMXQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item30Click(TObject *Sender)
{
/*    if("系统管理员" == OperatorGroupName)
	{
		BTFXMXQFrm->ShowModal();
	}
	else
	{
		ShowMessage("您不属于系统管理员，该功能必须由系统管理员执行!");
	}            */
	BTFXMXQFrm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item31Click(TObject *Sender)
{
	TRect rect = Panel11->ClientRect;
	FixLimitTimeForm->Dock(Panel11, rect);
	FixLimitTimeForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item32Click(TObject *Sender)
{
	TRect rect = Panel11->ClientRect;
	FixRecordFRM->Dock(Panel11, rect);
	FixRecordFRM->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item33Click(TObject *Sender)
{
	PXFXMForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TSDIAppForm::dxNavBar1Item34Click(TObject *Sender)
{
	StopConsumeQFrm->ShowModal();
}
//---------------------------------------------------------------------------

