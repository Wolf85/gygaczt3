// CodeGear C++ Builder
// Copyright (c) 1995, 2007 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Auutils.pas' rev: 11.00

#ifndef AuutilsHPP
#define AuutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Auutils
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TauSystemDirectory { sdCurrentDir, sdDesktop, sdMyDocuments, sdMyPictures, sdAppData, sdProgramFiles, sdWindowsDir, sdSystemDir, sdTempDir, sdHelpDir, sdMediaDir, sdCursorsDir, sdNone };
#pragma option pop

typedef Set<char, 0, 255>  SetOfChar;

#pragma option push -b-
enum TauSplitStrSide { LEFT, RIGHT };
#pragma option pop

typedef Set<TauSplitStrSide, LEFT, RIGHT>  TauSplitStrSides;

#pragma option push -b-
enum TauFileAttribute { atrArchive, atrHidden, atrReadOnly, atrSystem, atrTemporary, atrOffline };
#pragma option pop

typedef Set<TauFileAttribute, atrArchive, atrOffline>  TauFileAttributes;

#pragma pack(push,1)
struct TDoubleWord
{
	
	union
	{
		struct 
		{
			unsigned DWord;
			
		};
		struct 
		{
			Word LoWord;
			Word HiWord;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma option push -b-
enum TauStringListNVSeparatorSide { nvsLeft, nvsRight };
#pragma option pop

class DELPHICLASS TauStringList;
class PASCALIMPLEMENTATION TauStringList : public Classes::TStringList 
{
	typedef Classes::TStringList inherited;
	
private:
	AnsiString FNVSeparator;
	TauStringListNVSeparatorSide FNVSeparatorMainSide;
	int FMaxSize;
	HIDESBASE AnsiString __fastcall GetName(int Index);
	void __fastcall SetName(int Index, const AnsiString Value);
	HIDESBASE AnsiString __fastcall GetValue(int Index);
	HIDESBASE void __fastcall SetValue(int Index, const AnsiString Value);
	int __fastcall GetNVSeparatorPos(int Index);
	
protected:
	void __fastcall SetMaxSize(int Value);
	
public:
	__fastcall TauStringList(void);
	void __fastcall FreeAndFreeObjects(void);
	virtual int __fastcall Add(const AnsiString S);
	void __fastcall DeleteFirstItem(void);
	void __fastcall DeleteAndFreeObject(int Index);
	void __fastcall ClearAndFreeObjects(void);
	HIDESBASE int __fastcall IndexOfName(const AnsiString Name, bool IgnoreCase = true);
	int __fastcall IndexOfValue(const AnsiString Value, bool IgnoreCase = true);
	int __fastcall IndexOfNamePart(const AnsiString NamePart, bool IgnoreCase = true);
	int __fastcall IndexOfValuePart(const AnsiString ValuePart, bool IgnoreCase = true);
	void __fastcall WriteNamesToFile(const AnsiString FileName);
	void __fastcall WriteValuesToFile(const AnsiString FileName);
	AnsiString __fastcall GetFIFO();
	AnsiString __fastcall GetAndDeleteItem(int Index);
	__property int NVSeparatorPos[int Index] = {read=GetNVSeparatorPos};
	__property AnsiString NVSeparator = {read=FNVSeparator, write=FNVSeparator};
	__property TauStringListNVSeparatorSide NVSeparatorMainSide = {read=FNVSeparatorMainSide, write=FNVSeparatorMainSide, default=1};
	__property AnsiString Names[int Index] = {read=GetName, write=SetName};
	__property AnsiString Values[int Index] = {read=GetValue, write=SetValue};
	__property int MaxSize = {read=FMaxSize, write=SetMaxSize, default=2147483647};
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TauStringList(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString EXEDir;
extern PACKAGE AnsiString EXEName;
#define CRLF "\r\n"
#define D_CRLF "\r\n\r\n"
#define HTTPPrefix "http://"
extern PACKAGE bool __fastcall IsOnline(void);
extern PACKAGE Byte __fastcall PercentsOf(Extended Entire, Extended Part);
extern PACKAGE AnsiString __fastcall GetExecutableByExtension(const AnsiString Extension);
extern PACKAGE void __fastcall OpenURL(AnsiString URL, bool InNewWindow);
extern PACKAGE AnsiString __fastcall GetTempDir();
extern PACKAGE AnsiString __fastcall GetSystemDir();
extern PACKAGE AnsiString __fastcall GetWindowsDir();
extern PACKAGE AnsiString __fastcall GetSysDir(TauSystemDirectory Dir);
extern PACKAGE void __fastcall CreateDirectory(const AnsiString DirName);
extern PACKAGE bool __fastcall IsDirectoryExists(const AnsiString DirName);
extern PACKAGE AnsiString __fastcall ExpandToRealPath(const AnsiString Path, bool AddCurrentPathAsRoot = true);
extern PACKAGE bool __fastcall IsVista(void);
extern PACKAGE AnsiString __fastcall Base64Encode(const AnsiString Value);
extern PACKAGE AnsiString __fastcall GenerateAttachBoundary(char Salt);
extern PACKAGE AnsiString __fastcall GetMIMEType(AnsiString EXT);
extern PACKAGE bool __fastcall IsRegKeyExists(const AnsiString KeyName, HKEY RootKey = (HKEY)(0x80000001));
extern PACKAGE bool __fastcall IsRegValueExists(const AnsiString KeyName, const AnsiString ValueName, HKEY RootKey = (HKEY)(0x80000001));
extern PACKAGE bool __fastcall RegGetStr(const AnsiString KeyName, const AnsiString ValueName, AnsiString &Str, HKEY RootKey = (HKEY)(0x80000001));
extern PACKAGE AnsiString __fastcall RegReadStr(const AnsiString KeyName, const AnsiString ValueName, HKEY RootKey = (HKEY)(0x80000001));
extern PACKAGE void __fastcall RegWriteStr(const AnsiString KeyName, const AnsiString ValueName, const AnsiString Value, HKEY RootKey = (HKEY)(0x80000001));
extern PACKAGE void __fastcall RegWriteStrCULM(const AnsiString KeyName, const AnsiString ValueName, const AnsiString Value);
extern PACKAGE int __fastcall RegReadInt(const AnsiString KeyName, const AnsiString ValueName, int DefaultValue = 0x0, HKEY RootKey = (HKEY)(0x80000001));
extern PACKAGE void __fastcall RegWriteInt(const AnsiString KeyName, const AnsiString ValueName, int Value, HKEY RootKey = (HKEY)(0x80000001));
extern PACKAGE void __fastcall RegWriteIntCULM(const AnsiString KeyName, const AnsiString ValueName, int Value);
extern PACKAGE bool __fastcall RegReadBool(const AnsiString KeyName, const AnsiString ValueName, bool DefaultValue = false, HKEY RootKey = (HKEY)(0x80000001));
extern PACKAGE void __fastcall RegWriteBool(const AnsiString KeyName, const AnsiString ValueName, bool Value, HKEY RootKey = (HKEY)(0x80000001));
extern PACKAGE System::TDateTime __fastcall RegReadDateTime(const AnsiString KeyName, const AnsiString ValueName, const System::TDateTime DefaultValue = 0.000000E+00, HKEY RootKey = (HKEY)(0x80000001));
extern PACKAGE void __fastcall RegWriteDateTime(const AnsiString KeyName, const AnsiString ValueName, const System::TDateTime Value, HKEY RootKey = (HKEY)(0x80000001));
extern PACKAGE void __fastcall RegEraseValue(const AnsiString KeyName, const AnsiString ValueName, HKEY RootKey = (HKEY)(0x80000001));
extern PACKAGE void __fastcall RegEraseValueCULM(const AnsiString KeyName, const AnsiString ValueName);
extern PACKAGE void __fastcall RegEraseKey(const AnsiString KeyName, const HKEY RootKey = (HKEY)(0x80000001), bool DeleteAllSubkeys = true);
extern PACKAGE void __fastcall RegEraseKeyCULM(const AnsiString KeyName, bool DeleteAllSubkeys = true);
extern PACKAGE unsigned __fastcall RegGetValuesCount(const AnsiString KeyName, HKEY RootKey = (HKEY)(0x80000001));
extern PACKAGE bool __fastcall RegGetValueNames(const AnsiString KeyName, Classes::TStrings* Strings, HKEY RootKey = (HKEY)(0x80000001));
extern PACKAGE void __fastcall SplitStr(AnsiString SubStr, AnsiString Str, AnsiString &FirstPart, AnsiString &SecondPart, TauSplitStrSide MainSide, TauSplitStrSides LeaveSeparatorOn);
extern PACKAGE AnsiString __fastcall LeftPart(const AnsiString SubStr, const AnsiString Str);
extern PACKAGE AnsiString __fastcall RightPart(const AnsiString SubStr, const AnsiString Str);
extern PACKAGE AnsiString __fastcall LeftPartR(const AnsiString SubStr, const AnsiString Str);
extern PACKAGE AnsiString __fastcall RightPartR(const AnsiString SubStr, const AnsiString Str);
extern PACKAGE AnsiString __fastcall MiddlePart(const AnsiString SubStr1, const AnsiString SubStr2, const AnsiString Str);
extern PACKAGE int __fastcall PosR(const AnsiString SubStr, const AnsiString Str);
extern PACKAGE int __fastcall PosRM(const SetOfChar &Chars, const AnsiString Str);
extern PACKAGE int __fastcall PosCase(const AnsiString SubStr, const AnsiString Str, bool IgnoreCase = true);
extern PACKAGE AnsiString __fastcall IncludeLeadingBackslash(const AnsiString St);
extern PACKAGE AnsiString __fastcall ExcludeLeadingBackslash(const AnsiString St);
extern PACKAGE AnsiString __fastcall IncludeLeadingChar(const AnsiString St, char Ch = '\x5c');
extern PACKAGE AnsiString __fastcall ExcludeLeadingChar(const AnsiString St, char Ch = '\x5c');
extern PACKAGE void __fastcall SplitFilenameAndParams(AnsiString &FileName, AnsiString &Params);
extern PACKAGE bool __fastcall ParseURL(AnsiString URL, AnsiString &Protocol, AnsiString &HostName, AnsiString &URLPath, AnsiString &Username, AnsiString &Password, AnsiString &ExtraInfo, Word &Port);
extern PACKAGE AnsiString __fastcall URLToHostName(const AnsiString URL);
extern PACKAGE AnsiString __fastcall URLToFileName(const AnsiString URL);
extern PACKAGE int __fastcall CaseAnsiCompareText(const AnsiString S1, const AnsiString S2, bool CaseSensitive = true);
extern PACKAGE Shortint __fastcall VersionCheck(const AnsiString NewVersion, const AnsiString OldVersion);
extern PACKAGE System::TDateTime __fastcall GMTToLocalTime(System::TDateTime GMTTime);
extern PACKAGE System::TDateTime __fastcall InternetTimeToDateTime(AnsiString InternetTime);
extern PACKAGE _FILETIME __fastcall DateTimeToFileTime(System::TDateTime Time);
extern PACKAGE System::TDateTime __fastcall FileTimeToDateTime(const _FILETIME &Time);
extern PACKAGE bool __fastcall SetFileTimes(const AnsiString FileName, const System::TDateTime Created = -1.000000E+00, System::TDateTime Modified = -1.000000E+00, System::TDateTime Accessed = -1.000000E+00);
extern PACKAGE __int64 __fastcall Int2x32ToInt64(const unsigned IntHi, const unsigned IntLo);
extern PACKAGE __int64 __fastcall ExtractFileSize(const AnsiString FileName);
extern PACKAGE bool __fastcall LoadResourceToStream(unsigned Instance, char * ResName, char * ResType, Classes::TStream* Stream);
extern PACKAGE void __fastcall ShutdownApplication(void);
extern PACKAGE void __fastcall InitMSRecord(void *Rec, int Size);
extern PACKAGE void __fastcall Wait(unsigned &WaitHandle, unsigned Timeout = (unsigned)(0x0), bool CheckApplicationTermination = true);
extern PACKAGE void __fastcall StopWait(unsigned &WaitHandle);
extern PACKAGE AnsiString __fastcall StreamToString(Classes::TStream* Stream);
extern PACKAGE bool __fastcall SetFileAttr(const AnsiString FileName, const TauFileAttributes FileAttr);
extern PACKAGE bool __fastcall GetFileAttr(const AnsiString FileName, TauFileAttributes &FileAttr);

}	/* namespace Auutils */
using namespace Auutils;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Auutils
