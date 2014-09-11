//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RealDataInBaseThread.h"
#include "SDIMAIN.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TRealDataInBaseThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TRealDataInBaseThread::TRealDataInBaseThread(bool CreateSuspended,
                                                          TcxButton* InBTN,
                                                          TcxButton* BCBTN,
                                                          TcxButton* EBTN,
                                                          TcxProgressBar* ProgressBar,
                                                          TADOQuery* updateQuery,
                                                          TPanel *DPanel) : TThread(CreateSuspended)
{
	ValidInBTN = InBTN;
	ValidBCBTN = BCBTN;
	ValidEBTN = EBTN;
	ValidProgressBar = ProgressBar;
	UpdateDataBaseQuery = updateQuery;
	ValidPanel = DPanel;
}
//---------------------------------------------------------------------------
void __fastcall TRealDataInBaseThread::Execute()
{
	//---- Place thread code here ----
    ValidInBTN->Enabled = false;
	ValidBCBTN->Enabled = false;
	ValidProgressBar->Properties->Marquee = false;
	ValidProgressBar->Position = 0;

    if(true == FileExists(GlobalPath+"\\StoreRealCWOIBData.dat"))
	{
		String filepathstr = GlobalPath+"\\StoreRealCWOIBData.dat";
    	HANDLE HFILE = CreateFile(filepathstr.t_str(),
								  GENERIC_READ,
								  0,
								  NULL,
								  OPEN_EXISTING,
								  FILE_ATTRIBUTE_NORMAL,
								  NULL);
		ValidEBTN->Enabled = false;
		int filesize = GetFileSize(HFILE, NULL);
		if(0 == filesize)
		{
			CloseHandle(HFILE);
			DeleteFileA(filepathstr.t_str());
			ValidProgressBar->Position = 100;
			MessageBox(SDIAppForm->Handle, "批量数据入库完毕!", "OK", MB_OK|MB_ICONEXCLAMATION);
			ValidBCBTN->Enabled = true;
			ValidInBTN->Enabled = false;
			ValidEBTN->Enabled = true;
			ValidPanel->Caption = "批量数据入库完毕!";
			return;
		}
		else
		{
			String tmpfilepath = GlobalPath+"\\RealWaitForInsertToMX.dat";
			TmpSaveInsertRecordFile.open(tmpfilepath.t_str(), ios::app);

            String tmpAIPfilepath = GlobalPath+"\\WaitForInsertAIPMX.dat";
            TmpAddInPosInsertRecordFile.open(tmpAIPfilepath.t_str(), ios::app);

			String tmperrfilepath = GlobalPath+"\\RealWaitForInsertToErrMX.dat";
			TmpSaveInsertErrRecFile.open(tmperrfilepath.t_str(), ios::app);

			int LineInFile = filesize/18;
            if(LineInFile == 0)
            	LineInFile = 1;

			bool Readresult;
			DWORD nBytesRead;
			ZeroMemory(BufferFromFile, 18);
			Readresult = ReadFile(HFILE, BufferFromFile, 18, &nBytesRead, NULL);
			int i = 1;
			while(Readresult&&nBytesRead)
			{
				if(Readresult&&nBytesRead)
				{
					Synchronize(AnalyzeDataFunc);
					Synchronize(DisplayDataFunc);
				}
				ValidProgressBar->Position = i*100/LineInFile;
				ZeroMemory(BufferFromFile, 18);
				Readresult = ReadFile(HFILE, BufferFromFile, 18, &nBytesRead, NULL);
				i++;
			}
			TmpSaveInsertRecordFile.close();
            TmpAddInPosInsertRecordFile.close();
			TmpSaveInsertErrRecFile.close();
			CloseHandle(HFILE);
		//	MessageBox(SDIAppForm->Handle, "Before InBase", "Notice!", MB_OK);
			UpdateDataBaseFunc();
			DeleteFileA(filepathstr.t_str());
		}
		ValidEBTN->Enabled = true;
	}
	else
	{
		MessageBox(SDIAppForm->Handle, "没有批量数据存储文件!", "Notice", MB_OK|MB_ICONERROR);
		ValidBCBTN->Enabled = true;
		ValidEBTN->Enabled = true;
		return;
	}
	MessageBox(SDIAppForm->Handle, "批量数据入库完毕!", "OK", MB_OK|MB_ICONEXCLAMATION);
    ValidPanel->Caption = "批量数据入库完毕!";
	ValidBCBTN->Enabled = true;
	ValidInBTN->Enabled = false;
	ValidEBTN->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TRealDataInBaseThread::AnalyzeDataFunc()
{
	int tmpKH;
	int tmpXFCS;
	double tmpYE;
	double tmpXFJE;
	String tmpDATESTR;
	String tmpXFLX;
	String tmpSQLSTR;
	String username;

	bool errortag = false;

	unsigned char instr[4];
	unsigned char outstr[6];
	ZeroMemory(instr, 4);
	ZeroMemory(outstr, 6);

//begin提取卡信息----------------------------------------
	instr[0] = BufferFromFile[11];
	instr[1] = BufferFromFile[12];
	instr[2] = BufferFromFile[13];
	instr[3] = BufferFromFile[14];

	tmpKH = (int)BufferFromFile[0]*256*256+(int)BufferFromFile[1]*256+(int)BufferFromFile[2];
	tmpXFCS = (int)BufferFromFile[3]*256+(int)BufferFromFile[4];
	tmpYE = ((double)BufferFromFile[5]*256*256+(double)BufferFromFile[6]*256+(double)BufferFromFile[7])/100;
	tmpXFJE = ((double)BufferFromFile[8]*256*256+(double)BufferFromFile[9]*256+(double)BufferFromFile[10])/100;
    PosNumber = (int)BufferFromFile[16]*256+(int)BufferFromFile[17];

	if(GetnormaldateFunc)
	{
		if(0 != GetnormaldateFunc(instr, outstr))
		{
			outstr[0] = '0';
			outstr[1] = '1';
			outstr[2] = '1';
			outstr[3] = '0';
			outstr[4] = '0';
			outstr[5] = '0';
		}
		tmpDATESTR = "20"+IntToHex((int)outstr[0], 2)+"-"+
						  IntToHex((int)outstr[1], 2)+"-"+
						  IntToHex((int)outstr[2], 2)+" "+
						  IntToHex((int)outstr[3], 2)+":"+
						  IntToHex((int)outstr[4], 2)+":"+
						  IntToHex((int)outstr[5], 2);
	}
	else
	{
		outstr[0] = '0';
		outstr[1] = '1';
		outstr[2] = '1';
		outstr[3] = '0';
		outstr[4] = '0';
		outstr[5] = '0';
		tmpDATESTR = "20"+IntToHex((int)outstr[0], 2)+"-"+
				 IntToHex((int)outstr[1], 2)+"-"+
				 IntToHex((int)outstr[2], 2)+" "+
				 IntToHex((int)outstr[3], 2)+":"+
				 IntToHex((int)outstr[4], 2)+":"+
				 IntToHex((int)outstr[5], 2);
	}

	if(0 == BufferFromFile[15])
		tmpXFLX = "X";
	else if(1 == BufferFromFile[15])
		tmpXFLX = "Y";
	else if(2 == BufferFromFile[15])
		tmpXFLX = "B";
	else if(3 == BufferFromFile[15])
		tmpXFLX = "I";
	else if(4 == BufferFromFile[15])
		tmpXFLX = "L";
	else if(5 == BufferFromFile[15])
		tmpXFLX = "M";
	else if(6 == BufferFromFile[15])
		tmpXFLX = "O";
	else if(7 == BufferFromFile[15])
		tmpXFLX = "P";
	else if(250 == BufferFromFile[15])
		tmpXFLX = "Z";
    else if(65 == BufferFromFile[15]) //breakfast
    	tmpXFLX = "S";
    else if(66 == BufferFromFile[15]) //lunch
    	tmpXFLX = "D";
    else if(67 == BufferFromFile[15]) //supper
    	tmpXFLX = "F";
    else if(68 == BufferFromFile[15]) //night
    	tmpXFLX = "G";
	else tmpXFLX = "E";
//end提取卡信息-----------------------------------------

//Begin-UpdateDatabase----------------------------------
	UpdateDataBaseQuery->Close();
	tmpSQLSTR = "select * from CARD where KH='";
	tmpSQLSTR += tmpKH;
	tmpSQLSTR += "'";
	UpdateDataBaseQuery->SQL->Clear();
	UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
	UpdateDataBaseQuery->Open();
	if(!UpdateDataBaseQuery->IsEmpty())
	{
		SerialNum = UpdateDataBaseQuery->FieldByName("BH")->AsAnsiString.Trim();
		username = UpdateDataBaseQuery->FieldByName("XM")->AsAnsiString.Trim();
		if(UpdateDataBaseQuery->FieldByName("SYCS")->AsInteger < tmpXFCS)
		{
			UpdateDataBaseQuery->Edit();
			UpdateDataBaseQuery->FieldByName("SYCS")->AsInteger = tmpXFCS;
			UpdateDataBaseQuery->FieldByName("SF_YE")->AsFloat = tmpYE;
            UpdateDataBaseQuery->FieldByName("SFYEDT")->AsString = tmpDATESTR;
			UpdateDataBaseQuery->Post();
		}
	}
	else
		errortag = true;
	UpdateDataBaseQuery->Close();

	tmpSQLSTR = "select * from CARD_F where KH = '";
	tmpSQLSTR += tmpKH;
	tmpSQLSTR += "'";
	UpdateDataBaseQuery->SQL->Clear();
	UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
	UpdateDataBaseQuery->Open();
	if(!UpdateDataBaseQuery->IsEmpty())
	{
		if(UpdateDataBaseQuery->FieldByName("SYCS")->AsInteger < tmpXFCS)
		{
			UpdateDataBaseQuery->Edit();
			UpdateDataBaseQuery->FieldByName("SYCS")->AsInteger = tmpXFCS;
			UpdateDataBaseQuery->FieldByName("SF_YE")->AsFloat = tmpYE;
            UpdateDataBaseQuery->FieldByName("SFYEDT")->AsString = tmpDATESTR;
			UpdateDataBaseQuery->Post();
		}
	}
	else
		errortag = true;
	UpdateDataBaseQuery->Close();

	String UpdateTime;
	SYSTEMTIME tmpsystime;
	GetLocalTime(&tmpsystime);
	UpdateTime = DateTimeToStr(SystemTimeToDateTime(tmpsystime));

	if(!errortag)
	{
        TmpSaveInsertRecordFile<<SerialNum.t_str()<<","<<tmpKH<<","<<tmpYE<<","<<tmpXFJE<<",";
        TmpSaveInsertRecordFile<<tmpXFCS<<","<<tmpDATESTR.t_str()<<","<<PosNumber<<",0,";
        TmpSaveInsertRecordFile<<tmpXFLX.t_str()<<","<<OperatorName.t_str()<<","<<UpdateTime.t_str()<<endl;

    	if("I" == tmpXFLX)
        {
            TmpAddInPosInsertRecordFile<<tmpKH<<","<<SerialNum.t_str()<<","<<tmpYE<<",1,"<<tmpXFJE<<",0,";
            TmpAddInPosInsertRecordFile<<tmpXFJE<<",0,"<<tmpXFJE<<","<<tmpXFCS<<","<<tmpDATESTR.t_str()<<",1000,1,I,";
            TmpAddInPosInsertRecordFile<<OperatorName.t_str()<<endl;
        }
	}
	else
	{
        TmpSaveInsertErrRecFile<<SerialNum.t_str()<<","<<tmpKH<<","<<tmpYE<<","<<tmpXFJE<<",";
        TmpSaveInsertErrRecFile<<tmpXFCS<<","<<tmpDATESTR.t_str()<<","<<PosNumber<<",0,";
        TmpSaveInsertErrRecFile<<tmpXFLX.t_str()<<","<<OperatorName.t_str()<<","<<UpdateTime.t_str()<<endl;
    }
    return;
}
//---------------------------------------------------------------------------

void __fastcall TRealDataInBaseThread::DisplayDataFunc()
{
//
}
//---------------------------------------------------------------------------

void __fastcall TRealDataInBaseThread::UpdateDataBaseFunc()
{
	String tmppath = GlobalPath + "\\WaitForInsertToMX.dat";
	String tmpSQLSTR = "bulk insert MX from '";
	tmpSQLSTR += tmppath;
	tmpSQLSTR += "' with (fieldterminator=',',rowterminator='\n')";
	UpdateDataBaseQuery->SQL->Clear();
	UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
	UpdateDataBaseQuery->ExecSQL();
	UpdateDataBaseQuery->Close();

/*	tmpSQLSTR = "bulk insert MXBAK from '";
	tmpSQLSTR += tmppath;
	tmpSQLSTR += "' with (fieldterminator=',',rowterminator='\n')";
//	tmpSQLSTR = "bulk insert MXBAK from 'WaitForInsertToMX.dat' with (fieldterminator=',',rowterminator='\n')";
	UpdateDataBaseQuery->SQL->Clear();
	UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
	UpdateDataBaseQuery->ExecSQL();
	UpdateDataBaseQuery->Close();   */

	DeleteFileA(tmppath.t_str());

	tmppath = GlobalPath + "\\WaitForInsertAIPMX.dat";
	tmpSQLSTR = "bulk insert CK from '";
	tmpSQLSTR += tmppath;
	tmpSQLSTR += "' with (fieldterminator=',',rowterminator='\n')";
	UpdateDataBaseQuery->SQL->Clear();
	UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
	UpdateDataBaseQuery->ExecSQL();
	UpdateDataBaseQuery->Close();

	DeleteFileA(tmppath.t_str());

	tmppath = GlobalPath + "\\WaitForInsertToErrMX.dat";
	tmpSQLSTR = "bulk insert MX_ERROR from '";
	tmpSQLSTR += tmppath;
	tmpSQLSTR += "' with (fieldterminator=',',rowterminator='\n')";
	UpdateDataBaseQuery->SQL->Clear();
	UpdateDataBaseQuery->SQL->Add(tmpSQLSTR);
	UpdateDataBaseQuery->ExecSQL();
	UpdateDataBaseQuery->Close();

	DeleteFileA(tmppath.t_str());
	return;
}
//---------------------------------------------------------------------------

void __fastcall TRealDataInBaseThread::SaveDataToFileFunc()
{
//
}
//---------------------------------------------------------------------------
