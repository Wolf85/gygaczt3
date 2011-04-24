// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'auAutoUpgraderEditor.pas' rev: 5.00

#ifndef auAutoUpgraderEditorHPP
#define auAutoUpgraderEditorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <auExtAssociation.hpp>	// Pascal unit
#include <auAutoUpgrader.hpp>	// Pascal unit
#include <DsgnWnds.hpp>	// Pascal unit
#include <DsgnIntf.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <Registry.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Auautoupgradereditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TauAutoUpgraderEditor;
class PASCALIMPLEMENTATION TauAutoUpgraderEditor : public Dsgnwnds::TDesignWindow 
{
	typedef Dsgnwnds::TDesignWindow inherited;
	
__published:
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* DateEdit;
	Stdctrls::TEdit* NumberEdit;
	Stdctrls::TLabel* Label3;
	Stdctrls::TRadioButton* ByDateRadio;
	Stdctrls::TRadioButton* ByNumberRadio;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TGroupBox* GroupBox3;
	Stdctrls::TButton* OKBtn;
	Stdctrls::TButton* CancelBtn;
	Stdctrls::TButton* ExportBtn;
	Dialogs::TSaveDialog* SaveDialog;
	Stdctrls::TButton* AddBtn;
	Stdctrls::TButton* DeleteBtn;
	Stdctrls::TButton* CheckURLBtn;
	Extctrls::TPanel* Panel1;
	Controls::TImageList* ImageList;
	Menus::TPopupMenu* PopupMenu;
	Comctrls::TListView* ListView;
	Menus::TMenuItem* AddItem;
	Menus::TMenuItem* DeleteItem;
	Menus::TMenuItem* RenameItem;
	Menus::TMenuItem* CheckURLItem;
	Menus::TMenuItem* N2;
	Stdctrls::TMemo* Memo1;
	Stdctrls::TButton* TestBtn;
	Stdctrls::TLabel* Label6;
	Stdctrls::TRadioButton* ReplaceRadio;
	Stdctrls::TRadioButton* SetupRadio;
	Stdctrls::TRadioButton* RedirectRadio;
	void __fastcall ExportBtnClick(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	void __fastcall OKBtnClick(System::TObject* Sender);
	void __fastcall CancelBtnClick(System::TObject* Sender);
	void __fastcall TestBtnClick(System::TObject* Sender);
	void __fastcall ByDateRadioClick(System::TObject* Sender);
	void __fastcall DateEditExit(System::TObject* Sender);
	void __fastcall AddBtnClick(System::TObject* Sender);
	void __fastcall ListViewChange(System::TObject* Sender, Comctrls::TListItem* Item, Comctrls::TItemChange 
		Change);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall DeleteBtnClick(System::TObject* Sender);
	void __fastcall CheckURLBtnClick(System::TObject* Sender);
	void __fastcall RenameItemClick(System::TObject* Sender);
	void __fastcall ListViewDblClick(System::TObject* Sender);
	
private:
	void __fastcall AddURLToList(AnsiString URL);
	
public:
	Auautoupgrader::TauAutoUpgrader* AutoUpgrader;
public:
	#pragma option push -w-inl
	/* TDesignWindow.Create */ inline __fastcall virtual TauAutoUpgraderEditor(Classes::TComponent* AOwner
		) : Dsgnwnds::TDesignWindow(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TauAutoUpgraderEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TauAutoUpgraderEditor(Classes::TComponent* AOwner
		, int Dummy) : Dsgnwnds::TDesignWindow(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TauAutoUpgraderEditor(HWND ParentWindow) : Dsgnwnds::TDesignWindow(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowAutoUpgraderDesigner(Forms::_di_IDesigner Designer, Auautoupgrader::TauAutoUpgrader* 
	AutoUpgrader);

}	/* namespace Auautoupgradereditor */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Auautoupgradereditor;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// auAutoUpgraderEditor
