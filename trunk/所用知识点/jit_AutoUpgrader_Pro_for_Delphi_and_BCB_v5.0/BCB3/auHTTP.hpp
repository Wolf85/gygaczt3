// Borland C++ Builder
// Copyright (c) 1995, 1998 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'auHTTP.pas' rev: 3.00

#ifndef auHTTPHPP
#define auHTTPHPP
#include <auUtils.hpp>
#include <auThread.hpp>
#include <WinInet.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <Windows.hpp>
#include <SysInit.hpp>
#include <System.hpp>

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
	System::AnsiString FLoginUsername;
	System::AnsiString FLoginPassword;
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
public:
	/* TComponent.Create */ __fastcall virtual TauLoginComponent(Classes::TComponent* AOwner) : Classes::
		TComponent(AOwner) { }
	/* TComponent.Destroy */ __fastcall virtual ~TauLoginComponent(void) { }
	
};

typedef void __fastcall (__closure *TauHTTPProgressEvent)(System::TObject* Sender, const System::AnsiString 
	ContentType, int DataSize, int BytesRead, int ElapsedTime, int EstimatedTimeLeft, Byte PercentsDone
	, float TransferRate, Classes::TStream* Stream);

typedef void __fastcall (__closure *TauHTTPHeaderInfoEvent)(System::TObject* Sender, int ErrorCode, 
	const System::AnsiString RawHeadersCRLF, const System::AnsiString ContentType, const System::AnsiString 
	ContentLanguage, const System::AnsiString ContentEncoding, int ContentLength, const System::AnsiString 
	Location, const System::TDateTime Date, const System::TDateTime LastModified, const System::TDateTime 
	Expires, const System::AnsiString ETag, bool &ContinueDownload);

typedef void __fastcall (__closure *TauHTTPStatusChanged)(System::TObject* Sender, Cardinal StatusID
	, const System::AnsiString StatusStr);

typedef void __fastcall (__closure *TauHTTPRedirected)(System::TObject* Sender, const System::AnsiString 
	NewURL);

typedef void __fastcall (__closure *TauHTTPDoneEvent)(System::TObject* Sender, const System::AnsiString 
	ContentType, int FileSize, Classes::TStream* Stream);

typedef void __fastcall (__closure *TauHTTPConnLostEvent)(System::TObject* Sender, const System::AnsiString 
	ContentType, int FileSize, int BytesRead, Classes::TStream* Stream);

typedef void __fastcall (__closure *TauHTTPErrorEvent)(System::TObject* Sender, int ErrorCode, Classes::TStream* 
	Stream);

typedef void __fastcall (__closure *TauHTTPPasswordRequestEvent)(System::TObject* Sender, const System::AnsiString 
	Realm, bool &TryAgain);

typedef void __fastcall (__closure *TauHTTPProxyAuthenticationEvent)(System::TObject* Sender, System::AnsiString 
	&ProxyUsername, System::AnsiString &ProxyPassword, bool &TryAgain);

typedef void __fastcall (__closure *TauHTTPBeforeSendRequest)(System::TObject* Sender, void * hRequest
	);

enum TauHTTPRequestMethod { rmAutoDetect, rmGET, rmPOST };

enum TauHTTPAccessType { atPreconfig, atDirect, atUseProxy };

class DELPHICLASS TauHTTPProxy;
class PASCALIMPLEMENTATION TauHTTPProxy : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TauHTTPAccessType FAccessType;
	int FProxyPort;
	System::AnsiString FProxyServer;
	System::AnsiString FProxyBypass;
	System::AnsiString FProxyUsername;
	System::AnsiString FProxyPassword;
	bool __fastcall IsUseProxy(void);
	
public:
	__fastcall TauHTTPProxy(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property TauHTTPAccessType AccessType = {read=FAccessType, write=FAccessType, default=0};
	__property int ProxyPort = {read=FProxyPort, write=FProxyPort, default=8080};
	__property System::AnsiString ProxyServer = {read=FProxyServer, write=FProxyServer, stored=IsUseProxy
		};
	__property System::AnsiString ProxyBypass = {read=FProxyBypass, write=FProxyBypass, stored=IsUseProxy
		};
	__property System::AnsiString ProxyUsername = {read=FProxyUsername, write=FProxyUsername};
	__property System::AnsiString ProxyPassword = {read=FProxyPassword, write=FProxyPassword};
public:
	/* TPersistent.Destroy */ __fastcall virtual ~TauHTTPProxy(void) { }
	
};

class DELPHICLASS TauHTTPRange;
class PASCALIMPLEMENTATION TauHTTPRange : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Cardinal FStartRange;
	Cardinal FEndRange;
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Cardinal StartRange = {read=FStartRange, write=FStartRange, default=0};
	__property Cardinal EndRange = {read=FEndRange, write=FEndRange, default=0};
public:
	/* TPersistent.Destroy */ __fastcall virtual ~TauHTTPRange(void) { }
	
public:
	/* TObject.Create */ __fastcall TauHTTPRange(void) : Classes::TPersistent() { }
	
};

class DELPHICLASS TauHTTPTimeouts;
class PASCALIMPLEMENTATION TauHTTPTimeouts : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	int FConnectTimeout;
	int FReceiveTimeout;
	int FSendTimeout;
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property int ConnectTimeout = {read=FConnectTimeout, write=FConnectTimeout, default=0};
	__property int ReceiveTimeout = {read=FReceiveTimeout, write=FReceiveTimeout, default=0};
	__property int SendTimeout = {read=FSendTimeout, write=FSendTimeout, default=0};
public:
	/* TPersistent.Destroy */ __fastcall virtual ~TauHTTPTimeouts(void) { }
	
public:
	/* TObject.Create */ __fastcall TauHTTPTimeouts(void) : Classes::TPersistent() { }
	
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
	__property Auutils::TauFileAttributes Incomplete = {read=FIncomplete, write=SetIncomplete, default=17
		};
public:
	/* TPersistent.Destroy */ __fastcall virtual ~TauOutputFileAttributes(void) { }
	
};

class DELPHICLASS TauFileStream;
class PASCALIMPLEMENTATION TauFileStream : public Classes::THandleStream 
{
	typedef Classes::THandleStream inherited;
	
public:
	__fastcall TauFileStream(const System::AnsiString FileName, bool CreateNew, bool TestFileAttributes
		);
	__fastcall virtual ~TauFileStream(void);
};

typedef int TauBufferSize;

enum TauInternetOption { ioIgnoreCertificateInvalid, ioIgnoreCertificateDateInvalid, ioIgnoreUnknownCertificateAuthority, 
	ioIgnoreRedirectToHTTP, ioIgnoreRedirectToHTTPS, ioKeepConnection, ioNoAuthentication, ioNoAutoRedirect, 
	ioNoCookies };

typedef Set<TauInternetOption, ioIgnoreCertificateInvalid, ioNoCookies>  TauInternetOptions;

enum TauCacheOption { coAlwaysReload, coReloadIfNoExpireInformation, coReloadUpdatedObjects, coPragmaNoCache, 
	coNoCacheWrite, coCreateTempFilesIfCantCache, coUseCacheIfNetFail };

typedef Set<TauCacheOption, coAlwaysReload, coUseCacheIfNetFail>  TauCacheOptions;

class DELPHICLASS TauCustomHTTP;
class PASCALIMPLEMENTATION TauCustomHTTP : public Auhttp::TauLoginComponent 
{
	typedef Auhttp::TauLoginComponent inherited;
	
private:
	Classes::TStrings* FAddHeaders;
	System::AnsiString FAcceptTypes;
	System::AnsiString FAgent;
	System::AnsiString FOutputFileName;
	TauOutputFileAttributes* FOutputFileAttributes;
	System::AnsiString FURL;
	System::AnsiString FPostData;
	System::AnsiString FReferer;
	TauCacheOptions FCacheOptions;
	TauInternetOptions FInternetOptions;
	TauHTTPRange* FRange;
	TauHTTPTimeouts* FTimeouts;
	TauBufferSize FTransferBufferSize;
	TauHTTPRequestMethod FRequestMethod;
	TauHTTPProxy* FProxy;
	bool FWorkOffline;
	void *FData;
	TauHTTPBeforeSendRequest FOnBeforeSendRequest;
	TauHTTPHeaderInfoEvent FOnHeaderInfo;
	TauHTTPDoneEvent FOnDone;
	Classes::TNotifyEvent FOnDoneInterrupted;
	TauHTTPProgressEvent FOnProgress;
	TauHTTPStatusChanged FOnStatusChanged;
	TauHTTPRedirected FOnRedirected;
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
	Cardinal HTTPFileSize;
	Cardinal HTTPBytesTransferred;
	Cardinal HTTPStartTime;
	Cardinal HTTPInitStartRange;
	Cardinal HTTPInitEndRange;
	void *hSession;
	void *hConnect;
	void *hRequest;
	int hFile;
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
	System::AnsiString __fastcall GetFileName();
	System::AnsiString __fastcall GetHostName();
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
	void __fastcall CallPasswordRequest(void);
	void __fastcall CallProxyAuthenticationRequest(void);
	
protected:
	System::AnsiString HTTPRawHeadersCRLF;
	System::AnsiString HTTPContentType;
	System::AnsiString HTTPContentLanguage;
	System::AnsiString HTTPContentEncoding;
	System::AnsiString HTTPLocation;
	System::AnsiString HTTPETag;
	System::TDateTime HTTPDate;
	System::TDateTime HTTPLastModified;
	System::TDateTime HTTPExpires;
	Byte ProgressPercentsDone;
	Cardinal ProgressElapsedTime;
	Cardinal ProgressEstimatedTime;
	float ProgressTransferRate;
	void __fastcall DoAnyError(void);
	void __fastcall ReleaseHTTPStream(void);
	
public:
	int HTTPErrorCode;
	__fastcall virtual TauCustomHTTP(Classes::TComponent* aOwner);
	__fastcall virtual ~TauCustomHTTP(void);
	bool __fastcall Read(void);
	bool __fastcall ReadRange(Cardinal StartRange, Cardinal EndRange);
	void __fastcall Abort(bool DeleteOutputFile, bool HardTerminate);
	void __fastcall Pause(void);
	bool __fastcall Resume(void);
	bool __fastcall IsGlobalOffline(void);
	__property System::AnsiString Username = {read=FLoginUsername, write=FLoginUsername, stored=false};
		
	__property System::AnsiString Password = {read=FLoginPassword, write=FLoginPassword, stored=false};
		
	__property bool Busy = {read=FBusy, nodefault};
	__property bool ThreadBusy = {read=GetThreadBusy, nodefault};
	__property bool FreeOnTerminate = {read=GetFreeOnTerminate, write=SetFreeOnTerminate, nodefault};
	__property System::AnsiString FileName = {read=GetFileName};
	__property System::AnsiString HostName = {read=GetHostName};
	__property Authread::TauCustomThread* Thread = {read=FThread};
	__property System::AnsiString AcceptTypes = {read=FAcceptTypes, write=FAcceptTypes, stored=IsNotDefaultAcceptTypes
		};
	__property Classes::TStrings* AddHeaders = {read=FAddHeaders, write=SetAddHeaders};
	__property System::AnsiString Agent = {read=FAgent, write=FAgent};
	__property TauHTTPProxy* Proxy = {read=FProxy, write=FProxy};
	__property TauCacheOptions CacheOptions = {read=FCacheOptions, write=FCacheOptions, default=38};
	__property TauInternetOptions InternetOptions = {read=FInternetOptions, write=FInternetOptions, default=32
		};
	__property System::AnsiString OutputFileName = {read=FOutputFileName, write=FOutputFileName};
	__property TauOutputFileAttributes* OutputFileAttributes = {read=FOutputFileAttributes, write=FOutputFileAttributes
		};
	__property System::AnsiString URL = {read=FURL, write=FURL};
	__property System::AnsiString POSTData = {read=FPostData, write=FPostData};
	__property TauHTTPRange* Range = {read=FRange, write=FRange};
	__property System::AnsiString Referer = {read=FReferer, write=FReferer};
	__property TauHTTPRequestMethod RequestMethod = {read=FRequestMethod, write=FRequestMethod, default=0
		};
	__property TauHTTPTimeouts* Timeouts = {read=FTimeouts, write=FTimeouts};
	__property TauBufferSize TransferBufferSize = {read=FTransferBufferSize, write=FTransferBufferSize, 
		default=4096};
	__property bool WorkOffline = {read=FWorkOffline, write=FWorkOffline, default=0};
	__property void * Data = {read=FData, write=FData, stored=false};
	__property bool Suspended = {read=GetSuspended, write=SetSuspended, nodefault};
	__property Classes::TThreadPriority ThreadPriority = {read=GetThreadPriority, write=SetThreadPriority
		, default=3};
	__property bool WaitThread = {read=GetWaitThread, write=SetWaitThread, default=0};
	__property int WaitTimeout = {read=GetWaitTimeout, write=SetWaitTimeout, default=0};
	__property TauHTTPBeforeSendRequest OnBeforeSendRequest = {read=FOnBeforeSendRequest, write=FOnBeforeSendRequest
		};
	__property TauHTTPHeaderInfoEvent OnHeaderInfo = {read=FOnHeaderInfo, write=FOnHeaderInfo};
	__property TauHTTPDoneEvent OnDone = {read=FOnDone, write=FOnDone};
	__property TauHTTPProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	__property TauHTTPStatusChanged OnStatusChanged = {read=FOnStatusChanged, write=FOnStatusChanged};
	__property TauHTTPRedirected OnRedirected = {read=FOnRedirected, write=FOnRedirected};
	__property Classes::TNotifyEvent OnAnyError = {read=FOnAnyError, write=FOnAnyError};
	__property Classes::TNotifyEvent OnAborted = {read=FOnAborted, write=FOnAborted};
	__property TauHTTPConnLostEvent OnConnLost = {read=FOnConnLost, write=FOnConnLost};
	__property Classes::TNotifyEvent OnDoneInterrupted = {read=FOnDoneInterrupted, write=FOnDoneInterrupted
		};
	__property Classes::TNotifyEvent OnOutputFileError = {read=FOnOutputFileError, write=FOnOutputFileError
		};
	__property TauHTTPPasswordRequestEvent OnPasswordRequest = {read=FOnPasswordRequest, write=FOnPasswordRequest
		};
	__property TauHTTPProxyAuthenticationEvent OnProxyAuthenticationRequest = {read=FOnProxyAuthenticationRequest
		, write=FOnProxyAuthenticationRequest};
	__property Classes::TNotifyEvent OnHostUnreachable = {read=FOnHostUnreachable, write=FOnHostUnreachable
		};
	__property TauHTTPErrorEvent OnHTTPError = {read=FOnHTTPError, write=FOnHTTPError};
	__property Authread::TauThreadWaitTimeoutExpired OnWaitTimeoutExpired = {read=FOnWaitTimeoutExpired
		, write=FOnWaitTimeoutExpired};
};

class DELPHICLASS TauHTTPPragmaNoCache;
class PASCALIMPLEMENTATION TauHTTPPragmaNoCache : public Auhttp::TauCustomHTTP 
{
	typedef Auhttp::TauCustomHTTP inherited;
	
public:
	__fastcall virtual TauHTTPPragmaNoCache(Classes::TComponent* aOwner);
	__property CacheOptions ;
public:
	/* TauCustomHTTP.Destroy */ __fastcall virtual ~TauHTTPPragmaNoCache(void) { }
	
};

class DELPHICLASS TauHTTP;
class PASCALIMPLEMENTATION TauHTTP : public Auhttp::TauCustomHTTP 
{
	typedef Auhttp::TauCustomHTTP inherited;
	
__published:
	__property AcceptTypes ;
	__property AddHeaders ;
	__property Agent ;
	__property Proxy ;
	__property URL ;
	__property Username ;
	__property CacheOptions ;
	__property InternetOptions ;
	__property OutputFileName ;
	__property OutputFileAttributes ;
	__property Password ;
	__property POSTData ;
	__property Range ;
	__property Referer ;
	__property RequestMethod ;
	__property Timeouts ;
	__property ThreadPriority ;
	__property TransferBufferSize ;
	__property WaitThread ;
	__property WaitTimeout ;
	__property WorkOffline ;
	__property OnBeforeSendRequest ;
	__property OnHeaderInfo ;
	__property OnDone ;
	__property OnDoneInterrupted ;
	__property OnOutputFileError ;
	__property OnProgress ;
	__property OnRedirected ;
	__property OnAnyError ;
	__property OnAborted ;
	__property OnConnLost ;
	__property OnHTTPError ;
	__property OnHostUnreachable ;
	__property OnPasswordRequest ;
	__property OnProxyAuthenticationRequest ;
	__property OnWaitTimeoutExpired ;
public:
	/* TauCustomHTTP.Create */ __fastcall virtual TauHTTP(Classes::TComponent* aOwner) : Auhttp::TauCustomHTTP(
		aOwner) { }
	/* TauCustomHTTP.Destroy */ __fastcall virtual ~TauHTTP(void) { }
	
};

//-- var, const, procedure ---------------------------------------------------
#define auDefaultProxyPort (Word)(8080)
#define auDefaultProxyBypass "127.0.0.1;"
#define DEF_TRANSFERBUFFERSIZE (Word)(4096)
#define TEXTHTML "text/html"
#define DEF_ACCEPT_TYPES "text/html, */*"
#define HTTP_STATUS_CONTINUE (Byte)(100)
#define HTTP_STATUS_SWITCH_PROTOCOLS (Byte)(101)
#define HTTP_STATUS_OK (Byte)(200)
#define HTTP_STATUS_CREATED (Byte)(201)
#define HTTP_STATUS_ACCEPTED (Byte)(202)
#define HTTP_STATUS_PARTIAL (Byte)(203)
#define HTTP_STATUS_NO_CONTENT (Byte)(204)
#define HTTP_STATUS_RESET_CONTENT (Byte)(205)
#define HTTP_STATUS_PARTIAL_CONTENT (Byte)(206)
#define HTTP_STATUS_AMBIGUOUS (Word)(300)
#define HTTP_STATUS_MOVED (Word)(301)
#define HTTP_STATUS_REDIRECT (Word)(302)
#define HTTP_STATUS_REDIRECT_METHOD (Word)(303)
#define HTTP_STATUS_NOT_MODIFIED (Word)(304)
#define HTTP_STATUS_USE_PROXY (Word)(305)
#define HTTP_STATUS_REDIRECT_KEEP_VERB (Word)(307)
#define HTTP_STATUS_BAD_REQUEST (Word)(400)
#define HTTP_STATUS_DENIED (Word)(401)
#define HTTP_STATUS_PAYMENT_REQ (Word)(402)
#define HTTP_STATUS_FORBIDDEN (Word)(403)
#define HTTP_STATUS_NOT_FOUND (Word)(404)
#define HTTP_STATUS_BAD_METHOD (Word)(405)
#define HTTP_STATUS_NONE_ACCEPTABLE (Word)(406)
#define HTTP_STATUS_PROXY_AUTH_REQ (Word)(407)
#define HTTP_STATUS_REQUEST_TIMEOUT (Word)(408)
#define HTTP_STATUS_CONFLICT (Word)(409)
#define HTTP_STATUS_GONE (Word)(410)
#define HTTP_STATUS_AUTH_REFUSED (Word)(411)
#define HTTP_STATUS_PRECOND_FAILED (Word)(412)
#define HTTP_STATUS_REQUEST_TOO_LARGE (Word)(413)
#define HTTP_STATUS_URI_TOO_LONG (Word)(414)
#define HTTP_STATUS_UNSUPPORTED_MEDIA (Word)(415)
#define HTTP_STATUS_SERVER_ERROR (Word)(500)
#define HTTP_STATUS_NOT_SUPPORTED (Word)(501)
#define HTTP_STATUS_BAD_GATEWAY (Word)(502)
#define HTTP_STATUS_SERVICE_UNAVAIL (Word)(503)
#define HTTP_STATUS_GATEWAY_TIMEOUT (Word)(504)
#define HTTP_STATUS_VERSION_NOT_SUP (Word)(505)
#define HTTP_STATUS_FIRST (Byte)(100)
#define HTTP_STATUS_LAST (Word)(505)
#define HTTP_STATUS_RANGE_NOT_SATISFIABLE (Word)(416)
#define STR_DownloadError "Download Error"
#define STR_HostUnreachable "Host Unreachable"
#define STR_ConnectionLost "Connection Lost"
extern PACKAGE bool __fastcall ParseURL(System::AnsiString URL, System::AnsiString &Protocol, System::AnsiString 
	&HostName, System::AnsiString &URLPath, System::AnsiString &Username, System::AnsiString &Password, 
	System::AnsiString &ExtraInfo, Word &Port);
extern PACKAGE System::AnsiString __fastcall URLEncode(const System::AnsiString Str);
extern PACKAGE System::AnsiString __fastcall URLDecode(System::AnsiString Str);
extern PACKAGE System::AnsiString __fastcall HTTPReadString(const System::AnsiString URL, int Timeout
	);

}	/* namespace Auhttp */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Auhttp;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// auHTTP
