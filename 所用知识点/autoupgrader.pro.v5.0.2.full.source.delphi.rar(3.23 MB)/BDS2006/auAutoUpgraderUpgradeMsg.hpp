// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Auautoupgraderupgrademsg.pas' rev: 10.00

#ifndef AuautoupgraderupgrademsgHPP
#define AuautoupgraderupgrademsgHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Auautoupgrader.hpp>	// Pascal unit

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
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Auautoupgraderupgrademsg
