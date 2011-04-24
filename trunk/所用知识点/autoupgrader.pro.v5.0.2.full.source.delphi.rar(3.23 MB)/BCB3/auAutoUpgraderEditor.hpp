// Borland C++ Builder
// Copyright (c) 1995, 1998 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'auAutoUpgraderEditor.pas' rev: 3.00

#ifndef auAutoUpgraderEditorHPP
#define auAutoUpgraderEditorHPP
#include <auExtAssociation.hpp>
#include <auAutoUpgrader.hpp>
#include <DsgnWnds.hpp>
#include <DsgnIntf.hpp>
#include <Registry.hpp>
#include <Dialogs.hpp>
#include <SysUtils.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Windows.hpp>
#include <SysInit.hpp>
#include <System.hpp>

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
	void __fastcall AddURLToList(System::AnsiString URL);
	
public:
	Auautoupgrader::TauAutoUpgrader* AutoUpgrader;
public:
	/* TDesignWindow.Create */ __fastcall virtual TauAutoUpgraderEditor(Classes::TComponent* AOwner) : 
		Dsgnwnds::TDesignWindow(AOwner) { }
	/* TDesignWindow.Destroy */ __fastcall virtual ~TauAutoUpgraderEditor(void) { }
	
public:
	/* TCustomForm.CreateNew */ __fastcall TauAutoUpgraderEditor(Classes::TComponent* AOwner, int Dummy
		) : Dsgnwnds::TDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ __fastcall TauAutoUpgraderEditor(HWND ParentWindow) : Dsgnwnds::TDesignWindow(
		ParentWindow) { }
	
};

typedef TDesigner IDesigner;
;

typedef TFormDesigner IFormDesigner;
;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowAutoUpgraderDesigner(Forms::TDesigner* Designer, Auautoupgrader::TauAutoUpgrader* 
	AutoUpgrader);

}	/* namespace Auautoupgradereditor */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Auautoupgradereditor;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// auAutoUpgraderEditor
