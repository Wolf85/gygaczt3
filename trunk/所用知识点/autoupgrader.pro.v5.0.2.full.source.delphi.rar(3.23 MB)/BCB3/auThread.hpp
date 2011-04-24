// Borland C++ Builder
// Copyright (c) 1995, 1998 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'auThread.pas' rev: 3.00

#ifndef auThreadHPP
#define auThreadHPP
#include <Classes.hpp>
#include <Windows.hpp>
#include <SysInit.hpp>
#include <System.hpp>

//-- user supplied -----------------------------------------------------------

namespace Authread
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TauEventThread;
class DELPHICLASS TauCustomThread;
typedef void __fastcall (__closure *TauThreadWaitTimeoutExpired)(System::TObject* Sender, bool &TerminateThread
	);

class PASCALIMPLEMENTATION TauCustomThread : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TauEventThread* FThread;
	bool FDesignSuspended;
	bool FHandleExceptions;
	bool FFreeOwnerOnTerminate;
	bool FWaitThread;
	Cardinal FWaitTimeout;
	TauThreadWaitTimeoutExpired FOnWaitTimeoutExpired;
	Classes::TNotifyEvent FSyncMethod;
	void *FSyncParams;
	void __fastcall InternalSynchronization(void);
	Classes::TThreadPriority __fastcall GetPriority(void);
	void __fastcall SetPriority(Classes::TThreadPriority Value);
	bool __fastcall GetSuspended(void);
	void __fastcall SetSuspended(bool Value);
	bool __fastcall GetTerminated(void);
	int __fastcall GetThreadID(void);
	Classes::TNotifyEvent __fastcall GetOnException();
	void __fastcall SetOnException(Classes::TNotifyEvent Value);
	Classes::TNotifyEvent __fastcall GetOnExecute();
	void __fastcall SetOnExecute(Classes::TNotifyEvent Value);
	Classes::TNotifyEvent __fastcall GetOnTerminate();
	void __fastcall SetOnTerminate(Classes::TNotifyEvent Value);
	int __fastcall GetReturnValue(void);
	void __fastcall SetReturnValue(int Value);
	
protected:
	virtual void __fastcall Loaded(void);
	void __fastcall DoWaitTimeoutExpired(bool &TerminateThread);
	
public:
	__fastcall virtual TauCustomThread(Classes::TComponent* aOwner);
	__fastcall virtual ~TauCustomThread(void);
	bool __fastcall Execute(void);
	bool __fastcall ExecuteAndWaitForEvent(int &WaitHandle, int Timeout);
	void __fastcall Synchronize(Classes::TThreadMethod Method);
	void __fastcall SynchronizeEx(Classes::TNotifyEvent Method, void * Params);
	void __fastcall Suspend(void);
	void __fastcall Resume(void);
	void __fastcall Terminate(bool Imediately);
	int __fastcall WaitFor(void);
	bool __fastcall WaitForEvent(int &WaitHandle, int Timeout);
	int __fastcall Handle(void);
	bool __fastcall Running(void);
	bool __fastcall RunningAndNotSuspended(void);
	__property bool Terminated = {read=GetTerminated, nodefault};
	__property int ThreadID = {read=GetThreadID, nodefault};
	__property int ReturnValue = {read=GetReturnValue, write=SetReturnValue, nodefault};
	__property bool FreeOwnerOnTerminate = {read=FFreeOwnerOnTerminate, write=FFreeOwnerOnTerminate, default=0
		};
	__property bool HandleExceptions = {read=FHandleExceptions, write=FHandleExceptions, default=1};
	__property Classes::TThreadPriority Priority = {read=GetPriority, write=SetPriority, default=3};
	__property bool Suspended = {read=GetSuspended, write=SetSuspended, default=1};
	__property bool WaitThread = {read=FWaitThread, write=FWaitThread, default=0};
	__property Cardinal WaitTimeout = {read=FWaitTimeout, write=FWaitTimeout, default=0};
	__property Classes::TNotifyEvent OnException = {read=GetOnException, write=SetOnException};
	__property Classes::TNotifyEvent OnExecute = {read=GetOnExecute, write=SetOnExecute};
	__property Classes::TNotifyEvent OnTerminate = {read=GetOnTerminate, write=SetOnTerminate};
	__property TauThreadWaitTimeoutExpired OnWaitTimeoutExpired = {read=FOnWaitTimeoutExpired, write=FOnWaitTimeoutExpired
		};
};

class PASCALIMPLEMENTATION TauEventThread : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FHandle;
	int FThreadID;
	bool FTerminated;
	bool FSuspended;
	bool FFreeOnTerminate;
	int FReturnValue;
	bool FRunning;
	Classes::TThreadMethod FMethod;
	System::TObject* FSynchronizeException;
	Classes::TNotifyEvent FOnExecute;
	Classes::TNotifyEvent FOnException;
	Classes::TNotifyEvent FOnTerminate;
	TauCustomThread* Owner;
	Classes::TThreadPriority __fastcall GetPriority(void);
	void __fastcall SetPriority(Classes::TThreadPriority Value);
	void __fastcall SetSuspended(bool Value);
	void __fastcall CallTerminate(void);
	void __fastcall CallException(void);
	
protected:
	void __fastcall DoTerminate(void);
	void __fastcall Execute(void);
	void __fastcall Synchronize(Classes::TThreadMethod Method);
	__property int ReturnValue = {read=FReturnValue, write=FReturnValue, nodefault};
	__property bool Terminated = {read=FTerminated, nodefault};
	TauEventThread* __fastcall CreateThread(void);
	TauEventThread* __fastcall RecreateThread(void);
	
public:
	__fastcall TauEventThread(TauCustomThread* aOwner);
	__fastcall virtual ~TauEventThread(void);
	void __fastcall Resume(void);
	void __fastcall Suspend(void);
	void __fastcall Terminate(void);
	int __fastcall WaitFor(void);
	__property bool FreeOnTerminate = {read=FFreeOnTerminate, write=FFreeOnTerminate, nodefault};
	__property int Handle = {read=FHandle, nodefault};
	__property Classes::TThreadPriority Priority = {read=GetPriority, write=SetPriority, nodefault};
	__property bool Suspended = {read=FSuspended, write=SetSuspended, nodefault};
	__property int ThreadID = {read=FThreadID, nodefault};
	__property Classes::TNotifyEvent OnExecute = {read=FOnExecute, write=FOnExecute};
	__property Classes::TNotifyEvent OnException = {read=FOnException, write=FOnException};
	__property Classes::TNotifyEvent OnTerminate = {read=FOnTerminate, write=FOnTerminate};
};

class DELPHICLASS TauThread;
class PASCALIMPLEMENTATION TauThread : public Authread::TauCustomThread 
{
	typedef Authread::TauCustomThread inherited;
	
__published:
	__property HandleExceptions ;
	__property Priority ;
	__property Suspended ;
	__property WaitThread ;
	__property WaitTimeout ;
	__property OnException ;
	__property OnExecute ;
	__property OnTerminate ;
	__property OnWaitTimeoutExpired ;
public:
	/* TauCustomThread.Create */ __fastcall virtual TauThread(Classes::TComponent* aOwner) : Authread::
		TauCustomThread(aOwner) { }
	/* TauCustomThread.Destroy */ __fastcall virtual ~TauThread(void) { }
	
};

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Authread */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Authread;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// auThread
