// Borland C++ Builder
// Copyright (c) 1995, 1998 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'auHTTPProxyEditor.pas' rev: 3.00

#ifndef auHTTPProxyEditorHPP
#define auHTTPProxyEditorHPP
#include <auHTTP.hpp>
#include <DsgnWnds.hpp>
#include <DsgnIntf.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Messages.hpp>
#include <Windows.hpp>
#include <SysInit.hpp>
#include <System.hpp>

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
	/* TDesignWindow.Create */ __fastcall virtual TauHTTPProxyEditor(Classes::TComponent* AOwner) : Dsgnwnds::
		TDesignWindow(AOwner) { }
	/* TDesignWindow.Destroy */ __fastcall virtual ~TauHTTPProxyEditor(void) { }
	
public:
	/* TCustomForm.CreateNew */ __fastcall TauHTTPProxyEditor(Classes::TComponent* AOwner, int Dummy) : 
		Dsgnwnds::TDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ __fastcall TauHTTPProxyEditor(HWND ParentWindow) : Dsgnwnds::TDesignWindow(
		ParentWindow) { }
	
};

typedef TDesigner IDesigner;
;

typedef TFormDesigner IFormDesigner;
;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowHTTPProxyDesigner(Forms::TDesigner* Designer, Auhttp::TauHTTPProxy* 
	Proxy);

}	/* namespace Auhttpproxyeditor */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Auhttpproxyeditor;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// auHTTPProxyEditor
