// Borland C++ Builder
// Copyright (c) 1995, 1998 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'auExtAssociation.pas' rev: 3.00

#ifndef auExtAssociationHPP
#define auExtAssociationHPP
#include <Graphics.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Windows.hpp>
#include <SysInit.hpp>
#include <System.hpp>

//-- user supplied -----------------------------------------------------------

namespace Auextassociation
{
//-- type declarations -------------------------------------------------------
enum TauShellExtAccessMode { amReadOnly, amReadWrite };

class DELPHICLASS TauExtAssociation;
class PASCALIMPLEMENTATION TauExtAssociation : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TauShellExtAccessMode FAccessMode;
	System::AnsiString FExtension;
	System::AnsiString FExecutableFile;
	System::AnsiString FExtDescription;
	System::AnsiString FFileDescription;
	System::AnsiString FParamString;
	System::AnsiString FIconFile;
	int FIconIndex;
	Graphics::TIcon* FLargeIcon;
	Graphics::TIcon* FSmallIcon;
	void __fastcall SetExtension(System::AnsiString Value);
	void __fastcall SetExecutableFile(System::AnsiString Value);
	void __fastcall SetExtDescription(System::AnsiString Value);
	void __fastcall SetFileDescription(System::AnsiString Value);
	void __fastcall SetParamString(System::AnsiString Value);
	void __fastcall SetIconFile(System::AnsiString Value);
	void __fastcall SetIconIndex(int Value);
	void __fastcall SetIcon(Graphics::TIcon* Value);
	bool __fastcall CheckAccessMode(void);
	void __fastcall GetExtensionInfo(void);
	void __fastcall DoInstallExtension(void);
	
public:
	__fastcall virtual TauExtAssociation(Classes::TComponent* aOwner);
	__fastcall virtual ~TauExtAssociation(void);
	bool __fastcall InstallExtension(System::AnsiString Extension, System::AnsiString ExecutableFile, System::AnsiString 
		ParamString, System::AnsiString ExtDescription, System::AnsiString FileDescription, System::AnsiString 
		IconFile, int IconIndex);
	bool __fastcall UninstallExtension(System::AnsiString Ext);
	
__published:
	__property TauShellExtAccessMode AccessMode = {read=FAccessMode, write=FAccessMode, nodefault};
	__property System::AnsiString EXTENSION = {read=FExtension, write=SetExtension};
	__property System::AnsiString ExecutableFile = {read=FExecutableFile, write=SetExecutableFile};
	__property System::AnsiString ExtDescription = {read=FExtDescription, write=SetExtDescription};
	__property System::AnsiString FileDescription = {read=FFileDescription, write=SetFileDescription};
	__property System::AnsiString ParamString = {read=FParamString, write=SetParamString};
	__property System::AnsiString IconFile = {read=FIconFile, write=SetIconFile};
	__property int IconIndex = {read=FIconIndex, write=SetIconIndex, nodefault};
	__property Graphics::TIcon* LargeIcon = {read=FLargeIcon, write=SetIcon};
	__property Graphics::TIcon* SmallIcon = {read=FSmallIcon, write=SetIcon};
};

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Auextassociation */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Auextassociation;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// auExtAssociation
