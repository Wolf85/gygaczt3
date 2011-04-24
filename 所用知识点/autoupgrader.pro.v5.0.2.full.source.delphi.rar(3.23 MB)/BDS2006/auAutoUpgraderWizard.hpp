// Borland C++ Builder
// Copyright (c) 1995, 2005 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Auautoupgraderwizard.pas' rev: 10.00

#ifndef AuautoupgraderwizardHPP
#define AuautoupgraderwizardHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Comctrls.hpp>	// Pascal unit
#include <Auautoupgrader.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit

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
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TauAutoUpgraderWizardForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TauAutoUpgraderWizardForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TauAutoUpgraderWizardForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TauAutoUpgraderWizardForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TauAutoUpgraderWizardForm* WizardForm;
extern PACKAGE void __fastcall ShowAutoUpgraderWizard(Auautoupgrader::TauAutoUpgrader* aAutoUpgrader);

}	/* namespace Auautoupgraderwizard */
using namespace Auautoupgraderwizard;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Auautoupgraderwizard
