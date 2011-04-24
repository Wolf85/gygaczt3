// Borland C++ Builder
// Copyright (c) 1995, 1998 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'auAutoUpgraderPassword.pas' rev: 3.00

#ifndef auAutoUpgraderPasswordHPP
#define auAutoUpgraderPasswordHPP
#include <Graphics.hpp>
#include <auAutoUpgrader.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Windows.hpp>
#include <SysInit.hpp>
#include <System.hpp>

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
	/* TCustomForm.Create */ __fastcall virtual TauAutoUpgraderPasswordForm(Classes::TComponent* AOwner
		) : Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ __fastcall TauAutoUpgraderPasswordForm(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ __fastcall virtual ~TauAutoUpgraderPasswordForm(void) { }
	
public:
	/* TWinControl.CreateParented */ __fastcall TauAutoUpgraderPasswordForm(HWND ParentWindow) : Forms::
		TForm(ParentWindow) { }
	
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TauAutoUpgraderPasswordForm* PasswordForm;
extern PACKAGE bool __fastcall ShowPasswordBox(Auautoupgrader::TauAutoUpgrader* aAutoUpgrader, System::AnsiString 
	FileName);

}	/* namespace Auautoupgraderpassword */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Auautoupgraderpassword;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// auAutoUpgraderPassword
