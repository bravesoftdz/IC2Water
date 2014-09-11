//---------------------------------------------------------------------------

#ifndef GlobalParameterH
#define GlobalParameterH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "iostream.h"
#include "fstream.h"
#include "RY3_API.h"
#pragma link "RY3_BCB.lib"
#include <time.h>
#include <ADODB.hpp>

extern RY_HANDLE doghandle;
extern HINSTANCE LoadHModule;

typedef int __stdcall (*beepofread)(unsigned char*, unsigned char);

typedef int __stdcall (*readinfo)(unsigned char*,
								  unsigned char,
								  unsigned char,
								  unsigned char*,
								  unsigned char*,
								  unsigned char*,
								  unsigned char*,
								  unsigned char*,
								  unsigned char*,
								  unsigned char*,
								  unsigned char*,
								  unsigned char);

typedef int __stdcall (*readwaterinfo)(unsigned char*,
									  unsigned char,
									  unsigned char,
									  unsigned char*,
									  unsigned char*,
									  unsigned char*,
									  unsigned char*,
									  unsigned char*,
									  unsigned char*,
									  unsigned char);

typedef int __stdcall (*readserial)(unsigned char*,
									unsigned char*);

typedef int __stdcall (*LaunchCard)(unsigned char*,
									unsigned char,
									unsigned char,
									unsigned char*,
									unsigned char*,
									unsigned char*,
									unsigned char*,
									unsigned char*,
									unsigned char*,
									unsigned char*,
									unsigned char*,
									unsigned char,
									unsigned char);

typedef int __stdcall (*LaunchWaterCard)(unsigned char*,
										unsigned char,
										unsigned char,
										unsigned char*,
										unsigned char*,
										unsigned char*,
										unsigned char*,
										unsigned char*,
										unsigned char*,
										unsigned char,
										unsigned char);

typedef int __stdcall(*ClearCardInfo)(unsigned char*,
									  unsigned char,
									  unsigned char,
									  unsigned char*,
									  unsigned char);

typedef int __stdcall(*EncrptyCardMM)(char,
									  char*,
									  char*);

extern beepofread beepofreaddll;
extern readinfo readcardinfo;
extern readwaterinfo readwatercardinfo;
extern readserial readserialfun;
extern LaunchCard LaunchNewCard;
extern LaunchWaterCard LaunchWaterNewCard;
extern ClearCardInfo ClearCardInfoProc;
extern EncrptyCardMM EncrptyCardMMProc;

extern unsigned char readcomno[5];

extern TADOTable *UpZETable;

//extern unsigned char VaildPosTag[300];

extern bool timetag;
extern int times;
extern bool checktime;
extern bool goontag;
extern bool usetag;
extern double SFK_ZE;
extern double SK_ZE;
extern char timebuf[17];
extern char randbuf[32];
extern char goonpw[12];
extern char relvpw[12];
extern char CCH[62];
extern char globalqx[50];

extern unsigned char PosInUseTag[300];
extern int ModeOFCollect;   //0:不采集-1:实时-2:批量
extern int ReportClick;
extern bool PosContag;
extern bool PostLostInfotag;
extern bool enableGS;
extern bool fixrecordtag;
extern bool DOGChk;
extern bool ReaderChk;
extern bool WriteNameChk;

extern HINSTANCE LoadCOMHModule;
typedef int __stdcall (*SerReceiveOFdll)(unsigned char,
										 WORD,
										 unsigned char,
										 unsigned char*,
										 int,
										 int,
										 unsigned char*,
										 int);

typedef int __stdcall (*SerSendOFdll)(unsigned char,
									  WORD,
									  unsigned char,
									  unsigned char*,
									  int,
									  int);

typedef int __stdcall (*SendAckOFdll)(unsigned char, unsigned char);

typedef int __stdcall (*GetnormaldateOFdll)(unsigned char*, unsigned char*);

typedef int __stdcall(*Ppacarddll)(unsigned char*,
								   unsigned char,
								   unsigned char*,
								   unsigned char*,
								   unsigned char*,
								   unsigned char);


extern SerReceiveOFdll SerReceiveFunc;
extern SerSendOFdll SerSendFunc;
extern SendAckOFdll SendAckFunc;
extern GetnormaldateOFdll GetnormaldateFunc;
extern Ppacarddll pacarddllproc;
extern Ppacarddll pacarddllprocreader;


extern HINSTANCE LoadUSBHModule;
typedef char* __stdcall (*GETUSBCOMPORT)();
extern GETUSBCOMPORT getusbcomportdll;

extern ofstream DataSaveToFileStream;
extern ofstream DataWOSaveToFileStream;
extern ofstream BatchDataSaveToFileStream;
extern ofstream CDBatchDataSaveToFileStream;

extern ofstream CQKLogStream;
//extern ofstream CollectDataLogStream;

extern String ActiveTableName;
extern String DataBaseNameStr;

struct PosPara{
	int posnum;
	int comnum;
	int tag; //1:在线在库-2:不在线在库-3:在线不在库-4:在线-5:不在线
};
typedef PosPara POSPARA;

extern String OperatorName;
extern String OperatorGroupName;
extern String GlobalPath;
extern String SYSTEMDISPLAYNAME;
extern String VersionStr;

//extern String DWPassword;
//extern String CARDPassword;
extern unsigned char DWPassword[2];
extern unsigned char CARDPassword[6];
extern char DECCARDPassword[12];
extern unsigned char SuperPasword[6];
extern char DECSuperPassword[12];
extern unsigned char CARDPasswordEdition;
extern unsigned char UsingSecNUM;
extern unsigned char DelaySecond;

extern int maxconsumption;
extern int maxconsumption1;
extern int maxconsumption2;
extern int maxconsumption3;
extern int maxconsumption4;

extern int GlobalFKYJ;
extern int GlobalTKYJ;

extern int* BTGArray;
extern int BTGArraylen;

extern char** BTGmonthArray;
extern int BTGmonthArraylen;

extern char** JBNameArray;
extern int JBNameArraylen;

//extern int CardNoPtr[5040];
//extern int BonusPtr[5040];
//extern int AllCardNum;

extern unsigned char BTSendStr1[8192];
extern unsigned char BTSendStr2[8192];
extern unsigned char BTSendStr3[8192];
extern unsigned char BTSendStr4[8192];
extern unsigned char BTSendStr5[8192];

extern bool CreateBTtag;
extern bool DownloadBTtag;

extern bool BatchLaunchCardtag;
extern bool BatchGStag;

extern SHELLEXECUTEINFO e1;
extern String DataBaseServerName;
extern String DataBaseName;
#endif


