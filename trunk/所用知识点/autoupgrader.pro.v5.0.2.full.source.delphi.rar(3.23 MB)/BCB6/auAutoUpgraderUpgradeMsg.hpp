// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'auAutoUpgraderUpgradeMsg.pas' rev: 6.00

#ifndef auAutoUpgraderUpgradeMsgHPP
#define auAutoUpgraderUpgradeMsgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <auAutoUpgrader.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

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
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TauAutoUpgraderUpgradeMessageForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TauAutoUpgraderUpgradeMessageForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TauAutoUpgraderUpgradeMessageForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TauAutoUpgraderUpgradeMessageForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TauAutoUpgraderUpgradeMessageForm* UpgradeMessageForm;
extern PACKAGE bool __fastcall ShowUpgradeBox(AnsiString Msg);

}	/* namespace Auautoupgraderupgrademsg */
using namespace Auautoupgraderupgrademsg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// auAutoUpgraderUpgradeMsg
