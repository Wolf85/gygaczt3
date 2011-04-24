// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Auhttp.pas' rev: 11.00

#ifndef AuhttpHPP
#define AuhttpHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Wininet.hpp>	// Pascal unit
#include <Authread.hpp>	// Pascal unit
#include <Auutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Auhttp
{
//-- type declarations -------------------------------------------------------
typedef Set<char, 0, 255>  SetOfChar;

class DELPHICLASS TauLoginComponent;
class PASCALIMPLEMENTATION TauLoginComponent : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	void __fastcall ReadData(Classes::TStream* Stream);
	void __fastcall WriteData(Classes::TStream* Stream);
	
protected:
	AnsiString FLoginUsername;
	AnsiString FLoginPassword;
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TauLoginComponent(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TauLoginComponent(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TauHTTPProgressEvent)(System::TObject* Sender, const AnsiString ContentType, int DataSize, int BytesRead, int ElapsedTime, int EstimatedTimeLeft, Byte PercentsDone, float TransferRate, Classes::TStream* Stream);

typedef void __fastcall (__closure *TauHTTPUploadProgressEvent)(System::TObject* Sender, int DataSize, int BytesTransferred, int ElapsedTime, int EstimatedTimeLeft, Byte PercentsDone, float TransferRate);

typedef void __fastcall (__closure *TauHTTPUploadFieldRequest)(System::TObject* Sender, Word FileIndex, Classes::TMemoryStream* UploadStream, AnsiString &FieldName, AnsiString &FileName);

typedef void __fastcall (__closure *TauHTTPHeaderInfoEvent)(System::TObject* Sender, int ErrorCode, const AnsiString RawHeadersCRLF, const AnsiString ContentType, const AnsiString ContentLanguage, const AnsiString ContentEncoding, int ContentLength, const AnsiString Location, const System::TDateTime Date, const System::TDateTime LastModified, const System::TDateTime Expires, const AnsiString ETag, bool &ContinueDownload);

typedef void __fastcall (__closure *TauHTTPStatusChanged)(System::TObject* Sender, unsigned StatusID, const AnsiString StatusStr);

typedef void __fastcall (__closure *TauHTTPRedirected)(System::TObject* Sender, const AnsiString NewURL);

typedef void __fastcall (__closure *TauHTTPDoneEvent)(System::TObject* Sender, const AnsiString ContentType, int FileSize, Classes::TStream* Stream);

typedef void __fastcall (__closure *TauHTTPConnLostEvent)(System::TObject* Sender, const AnsiString ContentType, int FileSize, int BytesRead, Classes::TStream* Stream);

typedef void __fastcall (__closure *TauHTTPErrorEvent)(System::TObject* Sender, int ErrorCode, Classes::TStream* Stream);

typedef void __fastcall (__closure *TauHTTPPasswordRequestEvent)(System::TObject* Sender, const AnsiString Realm, bool &TryAgain);

typedef void __fastcall (__closure *TauHTTPProxyAuthenticationEvent)(System::TObject* Sender, AnsiString &ProxyUsername, AnsiString &ProxyPassword, bool &TryAgain);

typedef void __fastcall (__closure *TauHTTPBeforeSendRequest)(System::TObject* Sender, void * hRequest);

#pragma option push -b-
enum TauHTTPPOSTMethod { pmFormURLEncoded, pmMultipartFormData };
#pragma option pop

#pragma option push -b-
enum TauHTTPRequestMethod { rmAutoDetect, rmGET, rmPOST };
#pragma option pop

#pragma option push -b-
enum TauHTTPAccessType { atPreconfig, atDirect, atUseProxy };
#pragma option pop

class DELPHICLASS TauHTTPProxy;
class PASCALIMPLEMENTATION TauHTTPProxy : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TauHTTPAccessType FAccessType;
	int FProxyPort;
	AnsiString FProxyServer;
	AnsiString FProxyBypass;
	AnsiString FProxyUsername;
	AnsiString FProxyPassword;
	bool __fastcall IsUseProxy(void);
	
public:
	__fastcall TauHTTPProxy(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property TauHTTPAccessType AccessType = {read=FAccessType, write=FAccessType, default=0};
	__property int ProxyPort = {read=FProxyPort, write=FProxyPort, default=8080};
	__property AnsiString ProxyServer = {read=FProxyServer, write=FProxyServer, stored=IsUseProxy};
	__property AnsiString ProxyBypass = {read=FProxyBypass, write=FProxyBypass, stored=IsUseProxy};
	__property AnsiString ProxyUsername = {read=FProxyUsername, write=FProxyUsername};
	__property AnsiString ProxyPassword = {read=FProxyPassword, write=FProxyPassword};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TauHTTPProxy(void) { }
	#pragma option pop
	
};


class DELPHICLASS TauHTTPRange;
class PASCALIMPLEMENTATION TauHTTPRange : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	unsigned FStartRange;
	unsigned FEndRange;
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property unsigned StartRange = {read=FStartRange, write=FStartRange, default=0};
	__property unsigned EndRange = {read=FEndRange, write=FEndRange, default=0};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TauHTTPRange(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TauHTTPRange(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


class DELPHICLASS TauHTTPTimeouts;
class PASCALIMPLEMENTATION TauHTTPTimeouts : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	unsigned FConnectTimeout;
	unsigned FReceiveTimeout;
	unsigned FSendTimeout;
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property unsigned ConnectTimeout = {read=FConnectTimeout, write=FConnectTimeout, default=0};
	__property unsigned ReceiveTimeout = {read=FReceiveTimeout, write=FReceiveTimeout, default=0};
	__property unsigned SendTimeout = {read=FSendTimeout, write=FSendTimeout, default=0};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TauHTTPTimeouts(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TauHTTPTimeouts(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


class DELPHICLASS TauOutputFileAttributes;
class PASCALIMPLEMENTATION TauOutputFileAttributes : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Auutils::TauFileAttributes FComplete;
	Auutils::TauFileAttributes FIncomplete;
	void __fastcall SetComplete(const Auutils::TauFileAttributes Value);
	void __fastcall SetIncomplete(const Auutils::TauFileAttributes Value);
	
protected:
	DYNAMIC void __fastcall AttributesChanged(void);
	
public:
	__fastcall TauOutputFileAttributes(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Auutils::TauFileAttributes Complete = {read=FComplete, write=SetComplete, default=1};
	__property Auutils::TauFileAttributes Incomplete = {read=FIncomplete, write=SetIncomplete, default=17};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TauOutputFileAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS TauFileStream;
class PASCALIMPLEMENTATION TauFileStream : public Classes::THandleStream 
{
	typedef Classes::THandleStream inherited;
	
public:
	__fastcall TauFileStream(const AnsiString FileName, bool CreateNew, bool TestFileAttributes);
	__fastcall virtual ~TauFileStream(void);
};


typedef int TauBufferSize;

#pragma option push -b-
enum TauInternetOption { ioIgnoreCertificateInvalid, ioIgnoreCertificateDateInvalid, ioIgnoreUnknownCertificateAuthority, ioIgnoreRedirectToHTTP, ioIgnoreRedirectToHTTPS, ioKeepConnection, ioNoAuthentication, ioNoAutoRedirect, ioNoCookies };
#pragma option pop

typedef Set<TauInternetOption, ioIgnoreCertificateInvalid, ioNoCookies>  TauInternetOptions;

#pragma option push -b-
enum TauCacheOption { coAlwaysReload, coReloadIfNoExpireInformation, coReloadUpdatedObjects, coPragmaNoCache, coNoCacheWrite, coCreateTempFilesIfCantCache, coUseCacheIfNetFail };
#pragma option pop

typedef Set<TauCacheOption, coAlwaysReload, coUseCacheIfNetFail>  TauCacheOptions;

class DELPHICLASS TauCustomHTTP;
class PASCALIMPLEMENTATION TauCustomHTTP : public TauLoginComponent 
{
	typedef TauLoginComponent inherited;
	
private:
	Classes::TStrings* FAddHeaders;
	AnsiString FAcceptTypes;
	AnsiString FAgent;
	AnsiString FOutputFileName;
	TauOutputFileAttributes* FOutputFileAttributes;
	AnsiString FURL;
	AnsiString FPostData;
	AnsiString FReferer;
	TauCacheOptions FCacheOptions;
	TauInternetOptions FInternetOptions;
	TauHTTPRange* FRange;
	TauHTTPTimeouts* FTimeouts;
	TauBufferSize FTransferBufferSize;
	TauHTTPPOSTMethod FPOSTMethod;
	TauHTTPRequestMethod FRequestMethod;
	TauHTTPProxy* FProxy;
	bool FShowGoOnlineMessage;
	bool FWorkOffline;
	void *FData;
	TauHTTPBeforeSendRequest FOnBeforeSendRequest;
	TauHTTPHeaderInfoEvent FOnHeaderInfo;
	TauHTTPDoneEvent FOnDone;
	Classes::TNotifyEvent FOnDoneInterrupted;
	TauHTTPProgressEvent FOnProgress;
	TauHTTPStatusChanged FOnStatusChanged;
	TauHTTPRedirected FOnRedirected;
	TauHTTPUploadProgressEvent FOnUploadProgress;
	TauHTTPUploadFieldRequest FOnUploadFieldRequest;
	Classes::TNotifyEvent FOnAnyError;
	Classes::TNotifyEvent FOnAborted;
	TauHTTPConnLostEvent FOnConnLost;
	Classes::TNotifyEvent FOnHostUnreachable;
	TauHTTPErrorEvent FOnHTTPError;
	Classes::TNotifyEvent FOnOutputFileError;
	TauHTTPPasswordRequestEvent FOnPasswordRequest;
	TauHTTPProxyAuthenticationEvent FOnProxyAuthenticationRequest;
	Authread::TauThreadWaitTimeoutExpired FOnWaitTimeoutExpired;
	bool FBusy;
	bool FRealBusy;
	Authread::TauCustomThread* FThread;
	Classes::TStream* HTTPStream;
	bool HTTPSuccess;
	bool HTTPTryAgain;
	bool HTTPOutputToFile;
	bool HTTPContinueDownload;
	bool HTTPDeleteOutputFileOnAbort;
	void *HTTPData;
	unsigned HTTPFileSize;
	unsigned HTTPBytesTransferred;
	unsigned HTTPStartTime;
	unsigned HTTPInitStartRange;
	unsigned HTTPInitEndRange;
	AnsiString HTTPUploadRequestHeader;
	void *hSession;
	void *hConnect;
	void *hRequest;
	unsigned hFile;
	void __fastcall SetAddHeaders(Classes::TStrings* Value);
	bool __fastcall GetSuspended(void);
	void __fastcall SetSuspended(bool Value);
	Classes::TThreadPriority __fastcall GetThreadPriority(void);
	void __fastcall SetThreadPriority(Classes::TThreadPriority Value);
	bool __fastcall GetWaitThread(void);
	void __fastcall SetWaitThread(bool Value);
	int __fastcall GetWaitTimeout(void);
	void __fastcall SetWaitTimeout(int Value);
	bool __fastcall GetThreadBusy(void);
	bool __fastcall GetFreeOnTerminate(void);
	void __fastcall SetFreeOnTerminate(bool Value);
	AnsiString __fastcall GetFileName();
	AnsiString __fastcall GetHostName();
	bool __fastcall IsNotDefaultAcceptTypes(void);
	void __fastcall PrepareProgressParams(void);
	void __fastcall CloseHTTPHandles(void);
	void __fastcall AbortAndReleaseStreams(void);
	void __fastcall ThreadExecute(System::TObject* Sender);
	void __fastcall ThreadException(System::TObject* Sender);
	void __fastcall ThreadDone(System::TObject* Sender);
	void __fastcall ThreadWaitTimeoutExpired(System::TObject* Sender, bool &TerminateThread);
	void __fastcall CallAborted(void);
	void __fastcall CallHeaderInfo(void);
	void __fastcall CallProgress(void);
	void __fastcall CallUploadProgress(void);
	void __fastcall CallPasswordRequest(void);
	void __fastcall CallProxyAuthenticationRequest(void);
	
protected:
	AnsiString HTTPRawHeadersCRLF;
	AnsiString HTTPContentType;
	AnsiString HTTPContentLanguage;
	AnsiString HTTPContentEncoding;
	AnsiString HTTPLocation;
	AnsiString HTTPETag;
	System::TDateTime HTTPDate;
	System::TDateTime HTTPLastModified;
	System::TDateTime HTTPExpires;
	Byte ProgressPercentsDone;
	unsigned ProgressElapsedTime;
	unsigned ProgressEstimatedTime;
	float ProgressTransferRate;
	void __fastcall DoAnyError(void);
	void __fastcall ReleaseHTTPStream(void);
	
public:
	int HTTPErrorCode;
	__fastcall virtual TauCustomHTTP(Classes::TComponent* aOwner);
	__fastcall virtual ~TauCustomHTTP(void);
	bool __fastcall Read(bool ForceWaitThread = false);
	bool __fastcall ReadRange(unsigned StartRange, unsigned EndRange = (unsigned)(0x0), bool ForceWaitThread = false);
	bool __fastcall Upload(Word NumberOfFields);
	bool __fastcall BeginPrepareUpload(void);
	void __fastcall UploadStream(const AnsiString FieldName, Classes::TStream* UploadStream, const AnsiString FileName = "");
	void __fastcall UploadString(const AnsiString FieldName, const AnsiString StrValue);
	void __fastcall UploadInteger(const AnsiString FieldName, int IntValue);
	void __fastcall UploadBoolean(const AnsiString FieldName, bool BoolValue);
	void __fastcall UploadPicture(const AnsiString FieldName, Graphics::TPicture* Picture, const AnsiString FileName = "pic");
	void __fastcall EndPrepareUpload(void);
	void __fastcall Abort(bool DeleteOutputFile = false, bool HardTerminate = false);
	void __fastcall Pause(void);
	bool __fastcall Resume(void);
	bool __fastcall IsGlobalOffline(void);
	__property AnsiString Username = {read=FLoginUsername, write=FLoginUsername, stored=false};
	__property AnsiString Password = {read=FLoginPassword, write=FLoginPassword, stored=false};
	__property bool Busy = {read=FBusy, nodefault};
	__property bool ThreadBusy = {read=GetThreadBusy, nodefault};
	__property bool FreeOnTerminate = {read=GetFreeOnTerminate, write=SetFreeOnTerminate, nodefault};
	__property AnsiString FileName = {read=GetFileName};
	__property AnsiString HostName = {read=GetHostName};
	__property Authread::TauCustomThread* Thread = {read=FThread};
	__property AnsiString AcceptTypes = {read=FAcceptTypes, write=FAcceptTypes, stored=IsNotDefaultAcceptTypes};
	__property Classes::TStrings* AddHeaders = {read=FAddHeaders, write=SetAddHeaders};
	__property AnsiString Agent = {read=FAgent, write=FAgent};
	__property TauHTTPProxy* Proxy = {read=FProxy, write=FProxy};
	__property bool ShowGoOnlineMessage = {read=FShowGoOnlineMessage, write=FShowGoOnlineMessage, default=0};
	__property TauCacheOptions CacheOptions = {read=FCacheOptions, write=FCacheOptions, default=38};
	__property TauInternetOptions InternetOptions = {read=FInternetOptions, write=FInternetOptions, default=32};
	__property AnsiString OutputFileName = {read=FOutputFileName, write=FOutputFileName};
	__property TauOutputFileAttributes* OutputFileAttributes = {read=FOutputFileAttributes, write=FOutputFileAttributes};
	__property AnsiString URL = {read=FURL, write=FURL};
	__property AnsiString POSTData = {read=FPostData, write=FPostData};
	__property TauHTTPRange* Range = {read=FRange, write=FRange};
	__property AnsiString Referer = {read=FReferer, write=FReferer};
	__property TauHTTPRequestMethod RequestMethod = {read=FRequestMethod, write=FRequestMethod, default=0};
	__property TauHTTPTimeouts* Timeouts = {read=FTimeouts, write=FTimeouts};
	__property TauBufferSize TransferBufferSize = {read=FTransferBufferSize, write=FTransferBufferSize, default=4096};
	__property bool WorkOffline = {read=FWorkOffline, write=FWorkOffline, default=0};
	__property void * Data = {read=FData, write=FData, stored=false};
	__property bool Suspended = {read=GetSuspended, write=SetSuspended, nodefault};
	__property Classes::TThreadPriority ThreadPriority = {read=GetThreadPriority, write=SetThreadPriority, default=3};
	__property bool WaitThread = {read=GetWaitThread, write=SetWaitThread, default=0};
	__property int WaitTimeout = {read=GetWaitTimeout, write=SetWaitTimeout, default=0};
	__property TauHTTPBeforeSendRequest OnBeforeSendRequest = {read=FOnBeforeSendRequest, write=FOnBeforeSendRequest};
	__property TauHTTPHeaderInfoEvent OnHeaderInfo = {read=FOnHeaderInfo, write=FOnHeaderInfo};
	__property TauHTTPDoneEvent OnDone = {read=FOnDone, write=FOnDone};
	__property TauHTTPProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	__property TauHTTPStatusChanged OnStatusChanged = {read=FOnStatusChanged, write=FOnStatusChanged};
	__property TauHTTPRedirected OnRedirected = {read=FOnRedirected, write=FOnRedirected};
	__property TauHTTPUploadProgressEvent OnUploadProgress = {read=FOnUploadProgress, write=FOnUploadProgress};
	__property TauHTTPUploadFieldRequest OnUploadFieldRequest = {read=FOnUploadFieldRequest, write=FOnUploadFieldRequest};
	__property Classes::TNotifyEvent OnAnyError = {read=FOnAnyError, write=FOnAnyError};
	__property Classes::TNotifyEvent OnAborted = {read=FOnAborted, write=FOnAborted};
	__property TauHTTPConnLostEvent OnConnLost = {read=FOnConnLost, write=FOnConnLost};
	__property Classes::TNotifyEvent OnDoneInterrupted = {read=FOnDoneInterrupted, write=FOnDoneInterrupted};
	__property Classes::TNotifyEvent OnOutputFileError = {read=FOnOutputFileError, write=FOnOutputFileError};
	__property TauHTTPPasswordRequestEvent OnPasswordRequest = {read=FOnPasswordRequest, write=FOnPasswordRequest};
	__property TauHTTPProxyAuthenticationEvent OnProxyAuthenticationRequest = {read=FOnProxyAuthenticationRequest, write=FOnProxyAuthenticationRequest};
	__property Classes::TNotifyEvent OnHostUnreachable = {read=FOnHostUnreachable, write=FOnHostUnreachable};
	__property TauHTTPErrorEvent OnHTTPError = {read=FOnHTTPError, write=FOnHTTPError};
	__property Authread::TauThreadWaitTimeoutExpired OnWaitTimeoutExpired = {read=FOnWaitTimeoutExpired, write=FOnWaitTimeoutExpired};
};


class DELPHICLASS TauHTTPPragmaNoCache;
class PASCALIMPLEMENTATION TauHTTPPragmaNoCache : public TauCustomHTTP 
{
	typedef TauCustomHTTP inherited;
	
public:
	__fastcall virtual TauHTTPPragmaNoCache(Classes::TComponent* aOwner);
	__property CacheOptions  = {default=14};
public:
	#pragma option push -w-inl
	/* TauCustomHTTP.Destroy */ inline __fastcall virtual ~TauHTTPPragmaNoCache(void) { }
	#pragma option pop
	
};


class DELPHICLASS TauHTTP;
class PASCALIMPLEMENTATION TauHTTP : public TauCustomHTTP 
{
	typedef TauCustomHTTP inherited;
	
__published:
	__property AcceptTypes ;
	__property AddHeaders ;
	__property Agent ;
	__property Proxy ;
	__property URL ;
	__property Username ;
	__property CacheOptions  = {default=38};
	__property InternetOptions  = {default=32};
	__property OutputFileName ;
	__property OutputFileAttributes ;
	__property Password ;
	__property POSTData ;
	__property Range ;
	__property Referer ;
	__property RequestMethod  = {default=0};
	__property ShowGoOnlineMessage  = {default=0};
	__property Timeouts ;
	__property ThreadPriority  = {default=3};
	__property TransferBufferSize  = {default=4096};
	__property WaitThread  = {default=0};
	__property WaitTimeout  = {default=0};
	__property WorkOffline  = {default=0};
	__property OnBeforeSendRequest ;
	__property OnHeaderInfo ;
	__property OnDone ;
	__property OnDoneInterrupted ;
	__property OnOutputFileError ;
	__property OnProgress ;
	__property OnRedirected ;
	__property OnUploadProgress ;
	__property OnUploadFieldRequest ;
	__property OnAnyError ;
	__property OnAborted ;
	__property OnConnLost ;
	__property OnHTTPError ;
	__property OnHostUnreachable ;
	__property OnPasswordRequest ;
	__property OnProxyAuthenticationRequest ;
	__property OnWaitTimeoutExpired ;
public:
	#pragma option push -w-inl
	/* TauCustomHTTP.Create */ inline __fastcall virtual TauHTTP(Classes::TComponent* aOwner) : TauCustomHTTP(aOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TauCustomHTTP.Destroy */ inline __fastcall virtual ~TauHTTP(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word auDefaultProxyPort = 0x1f90;
#define auDefaultProxyBypass "127.0.0.1;"
static const Word DEF_TRANSFERBUFFERSIZE = 0x1000;
#define TEXTHTML "text/html"
#define DEF_ACCEPT_TYPES "text/html, */*"
#define S_PIC "pic"
static const Word HTTP_STATUS_RANGE_NOT_SATISFIABLE = 0x1a0;
#define STR_DownloadError "Download Error"
#define STR_HostUnreachable "Host Unreachable"
#define STR_ConnectionLost "Connection Lost"
extern PACKAGE bool __fastcall ParseURL(AnsiString URL, AnsiString &Protocol, AnsiString &HostName, AnsiString &URLPath, AnsiString &Username, AnsiString &Password, AnsiString &ExtraInfo, Word &Port);
extern PACKAGE AnsiString __fastcall URLEncode(const AnsiString Str);
extern PACKAGE AnsiString __fastcall URLDecode(AnsiString Str);
extern PACKAGE AnsiString __fastcall HTTPReadString(const AnsiString URL, int Timeout = 0x0);

}	/* namespace Auhttp */
using namespace Auhttp;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Auhttp
