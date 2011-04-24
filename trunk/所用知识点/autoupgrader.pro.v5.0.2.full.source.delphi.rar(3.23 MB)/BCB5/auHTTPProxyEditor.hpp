// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'auHTTPProxyEditor.pas' rev: 5.00

#ifndef auHTTPProxyEditorHPP
#define auHTTPProxyEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <auHTTP.hpp>	// Pascal unit
#include <DsgnWnds.hpp>	// Pascal unit
#include <DsgnIntf.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Auhttpproxyeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TauHTTPProxyEditor;
class PASCALIMPLEMENTATION TauHTTPProxyEditor : public Dsgnwnds::TDesignWindow 
{
	typedef Dsgnwnds::TDesignWindow inherited;
	
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
	/* TDesignWindow.Create */ inline __fastcall virtual TauHTTPProxyEditor(Classes::TComponent* AOwner
		) : Dsgnwnds::TDesignWindow(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TauHTTPProxyEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TauHTTPProxyEditor(Classes::TComponent* AOwner
		, int Dummy) : Dsgnwnds::TDesignWindow(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TauHTTPProxyEditor(HWND ParentWindow) : Dsgnwnds::TDesignWindow(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowHTTPProxyDesigner(Forms::_di_IDesigner Designer, Auhttp::TauHTTPProxy* 
	Proxy);

}	/* namespace Auhttpproxyeditor */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Auhttpproxyeditor;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// auHTTPProxyEditor
