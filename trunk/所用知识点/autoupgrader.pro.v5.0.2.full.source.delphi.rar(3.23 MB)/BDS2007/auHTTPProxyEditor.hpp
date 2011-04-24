// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Auhttpproxyeditor.pas' rev: 11.00

#ifndef AuhttpproxyeditorHPP
#define AuhttpproxyeditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Designintf.hpp>	// Pascal unit
#include <Designwindows.hpp>	// Pascal unit
#include <Auhttp.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Auhttpproxyeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TauHTTPProxyEditor;
class PASCALIMPLEMENTATION TauHTTPProxyEditor : public Designwindows::TDesignWindow 
{
	typedef Designwindows::TDesignWindow inherited;
	
__published:
	Stdctrls::TRadioButton* PreconfigBtn;
	Stdctrls::TRadioButton* DirectBtn;
	Extctrls::TBevel* Bevel1;
	Stdctrls::TRadioButton* ProxyBtn;
	Stdctrls::TLabel* ProxyServerLab;
	Stdctrls::TLabel* BypassLab;
	Stdctrls::TMemo* BypassMemo;
	Stdctrls::TLabel* TipLab;
	Stdctrls::TButton* OKBtn;
	Stdctrls::TButton* CancelBtn;
	Stdctrls::TLabel* ProxyAddressLab;
	Stdctrls::TLabel* SeparatorLab;
	Stdctrls::TLabel* PortLab;
	Stdctrls::TEdit* ServerEdit;
	Stdctrls::TEdit* PortEdit;
	void __fastcall CancelBtnClick(System::TObject* Sender);
	void __fastcall PreconfigBtnClick(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall OKBtnClick(System::TObject* Sender);
	
private:
	Auhttp::TauHTTPProxy* Proxy;
public:
	#pragma option push -w-inl
	/* TDesignWindow.Create */ inline __fastcall virtual TauHTTPProxyEditor(Classes::TComponent* AOwner) : Designwindows::TDesignWindow(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TauHTTPProxyEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TauHTTPProxyEditor(Classes::TComponent* AOwner, int Dummy) : Designwindows::TDesignWindow(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TauHTTPProxyEditor(HWND ParentWindow) : Designwindows::TDesignWindow(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowHTTPProxyDesigner(Designintf::_di_IDesigner Designer, Auhttp::TauHTTPProxy* Proxy);

}	/* namespace Auhttpproxyeditor */
using namespace Auhttpproxyeditor;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Auhttpproxyeditor
