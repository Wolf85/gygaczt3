// Borland C++ Builder
// Copyright (c) 1995, 1998 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'auAutoUpgraderWizard.pas' rev: 3.00

#ifndef auAutoUpgraderWizardHPP
#define auAutoUpgraderWizardHPP
#include <Graphics.hpp>
#include <auAutoUpgrader.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Messages.hpp>
#include <SysInit.hpp>
#include <System.hpp>

//-- user supplied -----------------------------------------------------------

namespace Auautoupgraderwizard
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TauAutoUpgraderWizardForm;
class PASCALIMPLEMENTATION TauAutoUpgraderWizardForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* Panel1;
	Extctrls::TImage* Image1;
	Extctrls::TBevel* Bevel1;
	Stdctrls::TLabel* WizardTitle;
	Stdctrls::TGroupBox* LCurrentFile;
	Stdctrls::TGroupBox* LAllFiles;
	Stdctrls::TLabel* LDownloadingFileFrom;
	Stdctrls::TLabel* LEstimatedTime;
	Stdctrls::TLabel* LTransferRate;
	Comctrls::TProgressBar* ProgressCurrentFile;
	Comctrls::TProgressBar* ProgressAllFiles;
	Stdctrls::TButton* FinishBtn;
	Stdctrls::TButton* CancelBtn;
	Stdctrls::TLabel* AllDownloading;
	Stdctrls::TLabel* AboutShadow;
	Stdctrls::TLabel* AboutLabel;
	Stdctrls::TEdit* FileURL;
	Stdctrls::TLabel* AfterNote;
	Stdctrls::TLabel* LFileSize;
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	void __fastcall FileURLKeyPress(System::TObject* Sender, char &Key);
	void __fastcall FinishBtnClick(System::TObject* Sender);
	void __fastcall CancelBtnClick(System::TObject* Sender);
	
private:
	Auautoupgrader::TauAutoUpgrader* AutoUpgrader;
	HIDESBASE MESSAGE void __fastcall WMSysCommand(Messages::TWMSysCommand &Message);
	
public:
	void __fastcall Finish(void);
public:
	/* TCustomForm.Create */ __fastcall virtual TauAutoUpgraderWizardForm(Classes::TComponent* AOwner) : 
		Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ __fastcall TauAutoUpgraderWizardForm(Classes::TComponent* AOwner, int Dummy
		) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ __fastcall virtual ~TauAutoUpgraderWizardForm(void) { }
	
public:
	/* TWinControl.CreateParented */ __fastcall TauAutoUpgraderWizardForm(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TauAutoUpgraderWizardForm* WizardForm;
extern PACKAGE void __fastcall ShowAutoUpgraderWizard(Auautoupgrader::TauAutoUpgrader* aAutoUpgrader
	);

}	/* namespace Auautoupgraderwizard */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Auautoupgraderwizard;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// auAutoUpgraderWizard
