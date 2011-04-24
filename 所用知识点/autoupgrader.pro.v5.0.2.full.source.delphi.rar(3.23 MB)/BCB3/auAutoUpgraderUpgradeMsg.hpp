// Borland C++ Builder
// Copyright (c) 1995, 1998 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'auAutoUpgraderUpgradeMsg.pas' rev: 3.00

#ifndef auAutoUpgraderUpgradeMsgHPP
#define auAutoUpgraderUpgradeMsgHPP
#include <auAutoUpgrader.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Windows.hpp>
#include <SysInit.hpp>
#include <System.hpp>

//-- user supplied -----------------------------------------------------------

namespace Auautoupgraderupgrademsg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TauAutoUpgraderUpgradeMessageForm;
class PASCALIMPLEMENTATION TauAutoUpgraderUpgradeMessageForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* BottomPanel;
	Stdctrls::TButton* YesBtn;
	Stdctrls::TButton* LaterBtn;
	Stdctrls::TLabel* Label1;
	Extctrls::TImage* Icon;
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	void __fastcall FormShow(System::TObject* Sender);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
public:
	/* TCustomForm.Create */ __fastcall virtual TauAutoUpgraderUpgradeMessageForm(Classes::TComponent* 
		AOwner) : Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ __fastcall TauAutoUpgraderUpgradeMessageForm(Classes::TComponent* AOwner
		, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ __fastcall virtual ~TauAutoUpgraderUpgradeMessageForm(void) { }
	
public:
	/* TWinControl.CreateParented */ __fastcall TauAutoUpgraderUpgradeMessageForm(HWND ParentWindow) : 
		Forms::TForm(ParentWindow) { }
	
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TauAutoUpgraderUpgradeMessageForm* UpgradeMessageForm;
extern PACKAGE bool __fastcall ShowUpgradeBox(System::AnsiString Msg);

}	/* namespace Auautoupgraderupgrademsg */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Auautoupgraderupgrademsg;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// auAutoUpgraderUpgradeMsg
