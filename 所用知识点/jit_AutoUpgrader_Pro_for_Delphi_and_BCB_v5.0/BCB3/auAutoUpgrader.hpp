// Borland C++ Builder
// Copyright (c) 1995, 1998 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'auAutoUpgrader.pas' rev: 3.00

#ifndef auAutoUpgraderHPP
#define auAutoUpgraderHPP
#include <auUtils.hpp>
#include <auHTTP.hpp>
#include <Graphics.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Messages.hpp>
#include <Windows.hpp>
#include <SysInit.hpp>
#include <System.hpp>

//-- user supplied -----------------------------------------------------------

namespace Auautoupgrader
{
//-- type declarations -------------------------------------------------------
enum TauAutoUpgraderLanguage { wlAuto, wlEnglish, wlRussian, wlGerman, wlFrench, wlSpanish, wlPortuguese, 
	wlPortugueseBrazilian, wlItalian, wlDutch, wlDanish, wlSwedish, wlFinnish, wlEstonian, wlUkrainian, 
	wlPolish, wlCzech, wlHungarian, wlRomanian, wlCatalan, wlBasque, wlAfrikaans, wlChineseTraditional, 
	wlChineseSimplified, wlIndonesian, wlMalay, wlIcelandic, wlTurkish, wlNorwegian, wlSlovak };

enum TacMiscFilesUpgradeBehavior { mfuAlwaysDownload, mfuOnlyIfSizeDifferent };

enum TauAutoUpgraderVersionControl { byDate, byNumber };

enum TacUpgradeMethod { umSelfUpgrade, umUseExternalSetup, umRedirectToURL };

class DELPHICLASS TauAutoUpgraderInfo;
class PASCALIMPLEMENTATION TauAutoUpgraderInfo : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Classes::TStrings* FFiles;
	TacUpgradeMethod FUpgradeMethod;
	System::AnsiString FUpgradeMsg;
	void __fastcall SetFiles(const Classes::TStrings* Value);
	
public:
	__fastcall TauAutoUpgraderInfo(void);
	__fastcall virtual ~TauAutoUpgraderInfo(void);
	
__published:
	__property Classes::TStrings* Files = {read=FFiles, write=SetFiles};
	__property TacUpgradeMethod UpgradeMethod = {read=FUpgradeMethod, write=FUpgradeMethod, default=0};
		
	__property System::AnsiString UpgradeMsg = {read=FUpgradeMsg, write=FUpgradeMsg};
};

enum auAutoUpgrader__2 { mAskUpgrade, mConnLost, mHostUnreachable, mLostFile, mNoInfoFile, mNoUpdateAvailable, 
	mPasswordRequest };

typedef Set<auAutoUpgrader__2, mAskUpgrade, mPasswordRequest>  TauAutoUpgraderShowMessages;

class DELPHICLASS TauAutoUpgraderWizard;
class PASCALIMPLEMENTATION TauAutoUpgraderWizard : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FEnabled;
	bool FHideFileLocation;
	Graphics::TPicture* FPicture;
	TauAutoUpgraderLanguage FLanguage;
	bool FStayOnTop;
	void __fastcall SetPicture(const Graphics::TPicture* Value);
	void __fastcall SetLanguage(TauAutoUpgraderLanguage Value);
	
public:
	__fastcall TauAutoUpgraderWizard(Classes::TComponent* aOwner);
	__fastcall virtual ~TauAutoUpgraderWizard(void);
	
__published:
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
	__property bool HideFileLocation = {read=FHideFileLocation, write=FHideFileLocation, default=0};
	__property Graphics::TPicture* Pic118x218 = {read=FPicture, write=SetPicture};
	__property TauAutoUpgraderLanguage Language = {read=FLanguage, write=SetLanguage, default=0};
	__property bool StayOnTop = {read=FStayOnTop, write=FStayOnTop, default=1};
};

typedef void __fastcall (__closure *TAUBeginUpgradeEvent)(System::TObject* Sender, const System::AnsiString 
	UpgradeMsg, TacUpgradeMethod UpgradeMethod, Auutils::TauStringList* Files, bool &CanUpgrade);

typedef void __fastcall (__closure *TAUEndUpgradeEvent)(System::TObject* Sender, bool &RestartImediately
	);

typedef void __fastcall (__closure *TAUFileStartEvent)(System::TObject* Sender, const System::AnsiString 
	FileURL, int FileSize, const System::TDateTime FileTime, bool &CanUpgrade);

typedef void __fastcall (__closure *TAUFileDoneEvent)(System::TObject* Sender, const System::AnsiString 
	FileName);

typedef void __fastcall (__closure *TAUHostUnreachableEvent)(System::TObject* Sender, const System::AnsiString 
	URL, const System::AnsiString Hostname);

typedef void __fastcall (__closure *TAULostFileEvent)(System::TObject* Sender, const System::AnsiString 
	FileURL, int ErrorCode, bool &ContinueUpgrade);

typedef void __fastcall (__closure *TAUProgressEvent)(System::TObject* Sender, const System::AnsiString 
	FileURL, int FileSize, int BytesRead, int ElapsedTime, int EstimatedTimeLeft, Byte PercentsDone, Byte 
	TotalPercentsDone, float TransferRate);

class DELPHICLASS TauAutoUpgrader;
class PASCALIMPLEMENTATION TauAutoUpgrader : public Auhttp::TauCustomHTTP 
{
	typedef Auhttp::TauCustomHTTP inherited;
	
private:
	bool FAutoCheck;
	int FAutoCheckDelay;
	Auhttp::TauCacheOptions FCacheOptions;
	TauAutoUpgraderInfo* FInfoFile;
	System::AnsiString FInfoFileURL;
	TauAutoUpgraderVersionControl FVersionControl;
	System::AnsiString FVersionDate;
	bool FVersionDateAutoSet;
	System::AnsiString FVersionNumber;
	TacMiscFilesUpgradeBehavior FMiscFilesUpgrade;
	System::AnsiString FRestartParams;
	TauAutoUpgraderShowMessages FShowMessages;
	TauAutoUpgraderWizard* FWizard;
	TAUBeginUpgradeEvent FOnBeginUpgrade;
	TAUEndUpgradeEvent FOnEndUpgrade;
	Classes::TNotifyEvent FOnLaterUpgrade;
	TAUProgressEvent FOnProgress;
	TAUFileStartEvent FOnFileStart;
	TAUFileDoneEvent FOnFileDone;
	Classes::TNotifyEvent FOnDoOwnCloseAppMethod;
	Classes::TNotifyEvent FOnAfterRestart;
	Classes::TNotifyEvent FOnAborted;
	Classes::TNotifyEvent FOnConnLost;
	TAUHostUnreachableEvent FOnHostUnreachable;
	Classes::TNotifyEvent FOnNoUpdateAvailable;
	Classes::TNotifyEvent FOnNoInfoFile;
	TAULostFileEvent FOnLostFile;
	Auhttp::TauHTTPPasswordRequestEvent FOnPasswordRequest;
	int FHandle;
	bool FAborted;
	bool FCanUpgrade;
	bool FJustCheckButDontUpgrade;
	bool FAutoCheckDone;
	bool FIsAutoCheck;
	bool FQueryInfoStage;
	bool FUpdatesReady;
	TacUpgradeMethod FUpdateMethod;
	Auutils::TauStringList* FDownloadQueue;
	System::AnsiString FCurrentFileName;
	System::TDateTime FCurrentFileTime;
	int FCurrentFileIndex;
	bool FRestarting;
	void __fastcall SetAutoCheck(bool Value);
	void __fastcall SetQueryInfoStage(bool Value);
	void __fastcall SetRestartParams(const System::AnsiString Value);
	void __fastcall SetVersionDateAutoSet(bool Value);
	bool __fastcall IsDefaultParams(void);
	System::AnsiString __fastcall GetLoginUsername();
	void __fastcall SetLoginUsername(const System::AnsiString Value);
	System::AnsiString __fastcall GetLoginPassword();
	void __fastcall SetLoginPassword(const System::AnsiString Value);
	void __fastcall HTTPHeaderInfo(System::TObject* Sender, int ErrorCode, const System::AnsiString RawHeadersCRLF
		, const System::AnsiString ContentType, const System::AnsiString ContentLanguage, const System::AnsiString 
		ContentEncoding, int ContentLength, const System::AnsiString Location, const System::TDateTime Date
		, const System::TDateTime LastModified, const System::TDateTime Expires, const System::AnsiString 
		ETag, bool &ContinueDownload);
	void __fastcall HTTPDone(System::TObject* Sender, const System::AnsiString ContentType, int FileSize
		, Classes::TStream* Stream);
	void __fastcall HTTPDoneInterrupted(System::TObject* Sender);
	void __fastcall HTTPProgress(System::TObject* Sender, const System::AnsiString ContentType, int FileSize
		, int BytesRead, int ElapsedTime, int EstimatedTimeLeft, Byte PercentsDone, float TransferRate, Classes::TStream* 
		Stream);
	void __fastcall HTTPConnLost(System::TObject* Sender, const System::AnsiString ContentType, int FileSize
		, int BytesRead, Classes::TStream* Stream);
	void __fastcall HTTPError(System::TObject* Sender, int ErrorCode, Classes::TStream* Stream);
	void __fastcall HTTPHostUnreachable(System::TObject* Sender);
	void __fastcall HTTPPasswordRequest(System::TObject* Sender, const System::AnsiString Realm, bool &
		TryAgain);
	void __fastcall ParseInfoFile(Classes::TStream* Stream);
	void __fastcall DoUpgrade(bool FirstFile);
	void __fastcall SafeTerminate(bool Imediately);
	void __fastcall Relaunch(const System::AnsiString ParamStr);
	void __fastcall UpdateTimer(void);
	
protected:
	int FWaitHandle;
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	
public:
	__fastcall virtual TauAutoUpgrader(Classes::TComponent* aOwner);
	__fastcall virtual ~TauAutoUpgrader(void);
	virtual void __fastcall Loaded(void);
	bool __fastcall CheckUpdate(bool JustCheckIsUpdateAvailable);
	HIDESBASE void __fastcall Abort(bool Imediately);
	void __fastcall RestartApplication(const System::AnsiString Params);
	void __fastcall DeleteTemporaryFiles(void);
	__property bool Aborted = {read=FAborted, nodefault};
	__property Auutils::TauStringList* DownloadQueue = {read=FDownloadQueue};
	__property bool QInfoStage = {read=FQueryInfoStage, write=SetQueryInfoStage, stored=false, nodefault
		};
	__property bool Restarting = {read=FRestarting, nodefault};
	
__published:
	__property Proxy ;
	__property InternetOptions ;
	__property ThreadPriority ;
	__property TransferBufferSize ;
	__property System::AnsiString HTTPUsername = {read=GetLoginUsername, write=SetLoginUsername, stored=false
		};
	__property System::AnsiString HTTPPassword = {read=GetLoginPassword, write=SetLoginPassword, stored=false
		};
	__property OnProxyAuthenticationRequest ;
	__property bool AutoCheck = {read=FAutoCheck, write=SetAutoCheck, default=0};
	__property int AutoCheckDelay = {read=FAutoCheckDelay, write=FAutoCheckDelay, default=10000};
	__property CacheOptions  = {read=FCacheOptions, write=FCacheOptions, default=38};
	__property TauAutoUpgraderInfo* InfoFile = {read=FInfoFile, write=FInfoFile};
	__property System::AnsiString InfoFileURL = {read=FInfoFileURL, write=FInfoFileURL};
	__property System::AnsiString RestartParams = {read=FRestartParams, write=SetRestartParams, stored=
		IsDefaultParams};
	__property TacMiscFilesUpgradeBehavior MiscFilesUpgrade = {read=FMiscFilesUpgrade, write=FMiscFilesUpgrade
		, default=0};
	__property TauAutoUpgraderVersionControl VersionControl = {read=FVersionControl, write=FVersionControl
		, default=0};
	__property System::AnsiString VersionDate = {read=FVersionDate, write=FVersionDate};
	__property bool VersionDateAutoSet = {read=FVersionDateAutoSet, write=SetVersionDateAutoSet, nodefault
		};
	__property System::AnsiString VersionNumber = {read=FVersionNumber, write=FVersionNumber};
	__property TauAutoUpgraderShowMessages ShowMessages = {read=FShowMessages, write=FShowMessages, default=75
		};
	__property TauAutoUpgraderWizard* Wizard = {read=FWizard, write=FWizard};
	__property TAUBeginUpgradeEvent OnBeginUpgrade = {read=FOnBeginUpgrade, write=FOnBeginUpgrade};
	__property TAUEndUpgradeEvent OnEndUpgrade = {read=FOnEndUpgrade, write=FOnEndUpgrade};
	__property Classes::TNotifyEvent OnLaterUpgrade = {read=FOnLaterUpgrade, write=FOnLaterUpgrade};
	__property TAUProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	__property TAUFileStartEvent OnFileStart = {read=FOnFileStart, write=FOnFileStart};
	__property TAUFileDoneEvent OnFileDone = {read=FOnFileDone, write=FOnFileDone};
	__property Classes::TNotifyEvent OnDoOwnCloseAppMethod = {read=FOnDoOwnCloseAppMethod, write=FOnDoOwnCloseAppMethod
		};
	__property Classes::TNotifyEvent OnAfterRestart = {read=FOnAfterRestart, write=FOnAfterRestart};
	__property Classes::TNotifyEvent OnAborted = {read=FOnAborted, write=FOnAborted};
	__property Classes::TNotifyEvent OnConnLost = {read=FOnConnLost, write=FOnConnLost};
	__property TAUHostUnreachableEvent OnHostUnreachable = {read=FOnHostUnreachable, write=FOnHostUnreachable
		};
	__property Classes::TNotifyEvent OnNoUpdateAvailable = {read=FOnNoUpdateAvailable, write=FOnNoUpdateAvailable
		};
	__property Classes::TNotifyEvent OnNoInfoFile = {read=FOnNoInfoFile, write=FOnNoInfoFile};
	__property TAULostFileEvent OnLostFile = {read=FOnLostFile, write=FOnLostFile};
	__property Auhttp::TauHTTPPasswordRequestEvent OnPasswordRequest = {read=FOnPasswordRequest, write=
		FOnPasswordRequest};
};

//-- var, const, procedure ---------------------------------------------------
#define LanguageResEntryPoint (int)(41000)
#define auWizardTitle (Byte)(0)
#define auDownloadingFiles (Byte)(1)
#define auUpdateCompleted (Byte)(2)
#define auCurrentFile (Byte)(3)
#define auAllFiles (Byte)(4)
#define auDownloadingFrom (Byte)(5)
#define auFileSize (Byte)(6)
#define auTransferRate (Byte)(7)
#define auEstimatedTime (Byte)(8)
#define auDownloadingOf (Byte)(9)
#define auSuccessUpdate (Byte)(10)
#define auEnterPassword (Byte)(11)
#define auUsername (Byte)(12)
#define auPassword (Byte)(13)
#define auYes (Byte)(14)
#define auNo (Byte)(15)
#define auOK (Byte)(16)
#define auCancel (Byte)(17)
#define auNext (Byte)(18)
#define auLater (Byte)(19)
#define auWarning (Byte)(20)
#define auError (Byte)(21)
#define auPreparing (Byte)(22)
#define auWelcome (Byte)(23)
#define auNoUpdate (Byte)(24)
#define auNoInfoFile (Byte)(25)
#define auHostUnreachable (Byte)(26)
#define auInterrupt (Byte)(27)
#define auLostFile (Byte)(28)
#define auPasswordRequired (Byte)(29)
#define auConnectionLost (Byte)(30)
#define auAutoUpgraderStr (int)(40999)
#define auDelphiStr (int)(40998)
#define auAppTitle (int)(40997)
extern PACKAGE System::TDateTime __fastcall AUDateToDate(const System::AnsiString AUDate);
extern PACKAGE System::AnsiString __fastcall DateToAUDate(const System::TDateTime Date);
extern PACKAGE System::AnsiString __fastcall AULangStr(int Ident);
extern PACKAGE System::AnsiString __fastcall AUFmtLangStr(int Ident, const System::TVarRec * Args, const 
	int Args_Size);

}	/* namespace Auautoupgrader */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Auautoupgrader;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// auAutoUpgrader
