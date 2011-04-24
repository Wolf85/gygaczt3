// Borland C++ Builder
// Copyright (c) 1995, 1998 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'auAutoUpgraderAddURL.pas' rev: 3.00

#ifndef auAutoUpgraderAddURLHPP
#define auAutoUpgraderAddURLHPP
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
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

namespace Auautoupgraderaddurl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TauAddURLForm;
class PASCALIMPLEMENTATION TauAddURLForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TButton* OKBtn;
	Stdctrls::TButton* CancelBtn;
	Stdctrls::TEdit* URLEdit;
public:
	/* TCustomForm.Create */ __fastcall virtual TauAddURLForm(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	/* TCustomForm.CreateNew */ __fastcall TauAddURLForm(Classes::TComponent* AOwner, int Dummy) : Forms::
		TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ __fastcall virtual ~TauAddURLForm(void) { }
	
public:
	/* TWinControl.CreateParented */ __fastcall TauAddURLForm(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	
};

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Auautoupgraderaddurl */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Auautoupgraderaddurl;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// auAutoUpgraderAddURL
