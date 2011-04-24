// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Auautoupgraderpassword.pas' rev: 11.00

#ifndef AuautoupgraderpasswordHPP
#define AuautoupgraderpasswordHPP

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
#include <Stdctrls.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Auautoupgrader.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Auautoupgraderpassword
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TauAutoUpgraderPasswordForm;
class PASCALIMPLEMENTATION TauAutoUpgraderPasswordForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TLabel* Label1;
	Extctrls::TImage* Image1;
	Extctrls::TPanel* BottomPanel;
	Stdctrls::TLabel* UsernameLab;
	Stdctrls::TLabel* PasswordLab;
	Stdctrls::TEdit* UsernameEdit;
	Stdctrls::TEdit* PasswordEdit;
	Stdctrls::TButton* OKBtn;
	Stdctrls::TButton* CancelBtn;
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	void __fastcall OKBtnClick(System::TObject* Sender);
	
private:
	Auautoupgrader::TauAutoUpgrader* AutoUpgrader;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TauAutoUpgraderPasswordForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TauAutoUpgraderPasswordForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TauAutoUpgraderPasswordForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TauAutoUpgraderPasswordForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TauAutoUpgraderPasswordForm* PasswordForm;
extern PACKAGE bool __fastcall ShowPasswordBox(Auautoupgrader::TauAutoUpgrader* aAutoUpgrader, AnsiString FileName);

}	/* namespace Auautoupgraderpassword */
using namespace Auautoupgraderpassword;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Auautoupgraderpassword
