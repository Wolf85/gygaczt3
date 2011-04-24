// Borland C++ Builder
// Copyright (c) 1995, 1998 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'auUtils.pas' rev: 3.00

#ifndef auUtilsHPP
#define auUtilsHPP
#include <Classes.hpp>
#include <Windows.hpp>
#include <SysInit.hpp>
#include <System.hpp>

//-- user supplied -----------------------------------------------------------

namespace Auutils
{
//-- type declarations -------------------------------------------------------
enum TauSystemDirectory { sdCurrentDir, sdDesktop, sdMyDocuments, sdMyPictures, sdAppData, sdProgramFiles, 
	sdWindowsDir, sdSystemDir, sdTempDir, sdHelpDir, sdMediaDir, sdCursorsDir, sdNone };

typedef Set<char, 0, 255>  SetOfChar;

enum TauSplitStrSide { LEFT, RIGHT };

typedef Set<TauSplitStrSide, LEFT, RIGHT>  TauSplitStrSides;

enum auUtils__1 { rfReplaceAll, rfIgnoreCase };

typedef Set<auUtils__1, rfReplaceAll, rfIgnoreCase>  TReplaceFlags;

enum TauFileAttribute { atrArchive, atrHidden, atrReadOnly, atrSystem, atrTemporary, atrOffline };

typedef Set<TauFileAttribute, atrArchive, atrOffline>  TauFileAttributes;

#pragma pack(push, 1)
struct TDoubleWord
{
	
	union
	{
		int DWord;
		struct 
		{
			Word LoWord;
			Word HiWord;
			
		};
		
	};
} ;
#pragma pack(pop)

enum TauStringListNVSeparatorSide { nvsLeft, nvsRight };

class DELPHICLASS TauStringList;
class PASCALIMPLEMENTATION TauStringList : public Classes::TStringList 
{
	typedef Classes::TStringList inherited;
	
private:
	System::AnsiString FNVSeparator;
	TauStringListNVSeparatorSide FNVSeparatorMainSide;
	int FMaxSize;
	HIDESBASE System::AnsiString __fastcall GetName(int Index);
	void __fastcall SetName(int Index, const System::AnsiString Value);
	HIDESBASE System::AnsiString __fastcall GetValue(int Index);
	HIDESBASE void __fastcall SetValue(int Index, const System::AnsiString Value);
	int __fastcall GetNVSeparatorPos(int Index);
	
protected:
	void __fastcall SetMaxSize(int Value);
	
public:
	__fastcall TauStringList(void);
	void __fastcall FreeAndFreeObjects(void);
	virtual int __fastcall Add(const System::AnsiString S);
	void __fastcall DeleteFirstItem(void);
	void __fastcall DeleteAndFreeObject(int Index);
	void __fastcall ClearAndFreeObjects(void);
	HIDESBASE int __fastcall IndexOfName(const System::AnsiString Name, bool IgnoreCase);
	int __fastcall IndexOfValue(const System::AnsiString Value, bool IgnoreCase);
	int __fastcall IndexOfNamePart(const System::AnsiString NamePart, bool IgnoreCase);
	int __fastcall IndexOfValuePart(const System::AnsiString ValuePart, bool IgnoreCase);
	void __fastcall WriteNamesToFile(const System::AnsiString FileName);
	void __fastcall WriteValuesToFile(const System::AnsiString FileName);
	System::AnsiString __fastcall GetFIFO();
	System::AnsiString __fastcall GetAndDeleteItem(int Index);
	__property int NVSeparatorPos[int Index] = {read=GetNVSeparatorPos};
	__property System::AnsiString NVSeparator = {read=FNVSeparator, write=FNVSeparator};
	__property TauStringListNVSeparatorSide NVSeparatorMainSide = {read=FNVSeparatorMainSide, write=FNVSeparatorMainSide
		, default=1};
	__property System::AnsiString Names[int Index] = {read=GetName, write=SetName};
	__property System::AnsiString Values[int Index] = {read=GetValue, write=SetValue};
	__property int MaxSize = {read=FMaxSize, write=SetMaxSize, default=2147483647};
public:
	/* TStringList.Destroy */ __fastcall virtual ~TauStringList(void) { }
	
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::AnsiString EXEDir;
extern PACKAGE System::AnsiString EXEName;
#define CRLF "\r\n"
#define D_CRLF "\r\n\r\n"
#define HTTPPrefix "http://"
#define TIME_ZONE_ID_INVALID (int)(-1)
#define TIME_ZONE_ID_UNKNOWN (Byte)(0)
#define TIME_ZONE_ID_STANDARD (Byte)(1)
#define TIME_ZONE_ID_DAYLIGHT (Byte)(2)
extern PACKAGE bool __fastcall IsOnline(void);
extern PACKAGE Byte __fastcall PercentsOf(Extended Entire, Extended Part);
extern PACKAGE System::AnsiString __fastcall GetExecutableByExtension(const System::AnsiString Extension
	);
extern PACKAGE void __fastcall OpenURL(System::AnsiString URL, bool InNewWindow);
extern PACKAGE System::AnsiString __fastcall GetTempDir();
extern PACKAGE System::AnsiString __fastcall GetSystemDir();
extern PACKAGE System::AnsiString __fastcall GetWindowsDir();
extern PACKAGE System::AnsiString __fastcall GetSysDir(TauSystemDirectory Dir);
extern PACKAGE void __fastcall CreateDirectory(const System::AnsiString DirName);
extern PACKAGE bool __fastcall IsDirectoryExists(const System::AnsiString DirName);
extern PACKAGE System::AnsiString __fastcall ExpandToRealPath(const System::AnsiString Path, bool AddCurrentPathAsRoot
	);
extern PACKAGE bool __fastcall IsVista(void);
extern PACKAGE System::AnsiString __fastcall Base64Encode(const System::AnsiString Value);
extern PACKAGE System::AnsiString __fastcall GenerateAttachBoundary(char Salt);
extern PACKAGE System::AnsiString __fastcall GetMIMEType(System::AnsiString EXT);
extern PACKAGE bool __fastcall IsRegKeyExists(const System::AnsiString KeyName, HKEY RootKey);
extern PACKAGE bool __fastcall IsRegValueExists(const System::AnsiString KeyName, const System::AnsiString 
	ValueName, HKEY RootKey);
extern PACKAGE bool __fastcall RegGetStr(const System::AnsiString KeyName, const System::AnsiString 
	ValueName, System::AnsiString &Str, HKEY RootKey);
extern PACKAGE System::AnsiString __fastcall RegReadStr(const System::AnsiString KeyName, const System::AnsiString 
	ValueName, HKEY RootKey);
extern PACKAGE void __fastcall RegWriteStr(const System::AnsiString KeyName, const System::AnsiString 
	ValueName, const System::AnsiString Value, HKEY RootKey);
extern PACKAGE void __fastcall RegWriteStrCULM(const System::AnsiString KeyName, const System::AnsiString 
	ValueName, const System::AnsiString Value);
extern PACKAGE int __fastcall RegReadInt(const System::AnsiString KeyName, const System::AnsiString 
	ValueName, int DefaultValue, HKEY RootKey);
extern PACKAGE void __fastcall RegWriteInt(const System::AnsiString KeyName, const System::AnsiString 
	ValueName, int Value, HKEY RootKey);
extern PACKAGE void __fastcall RegWriteIntCULM(const System::AnsiString KeyName, const System::AnsiString 
	ValueName, int Value);
extern PACKAGE bool __fastcall RegReadBool(const System::AnsiString KeyName, const System::AnsiString 
	ValueName, bool DefaultValue, HKEY RootKey);
extern PACKAGE void __fastcall RegWriteBool(const System::AnsiString KeyName, const System::AnsiString 
	ValueName, bool Value, HKEY RootKey);
extern PACKAGE System::TDateTime __fastcall RegReadDateTime(const System::AnsiString KeyName, const 
	System::AnsiString ValueName, const System::TDateTime DefaultValue, HKEY RootKey);
extern PACKAGE void __fastcall RegWriteDateTime(const System::AnsiString KeyName, const System::AnsiString 
	ValueName, const System::TDateTime Value, HKEY RootKey);
extern PACKAGE void __fastcall RegEraseValue(const System::AnsiString KeyName, const System::AnsiString 
	ValueName, HKEY RootKey);
extern PACKAGE void __fastcall RegEraseValueCULM(const System::AnsiString KeyName, const System::AnsiString 
	ValueName);
extern PACKAGE void __fastcall RegEraseKey(const System::AnsiString KeyName, const HKEY RootKey, bool 
	DeleteAllSubkeys);
extern PACKAGE void __fastcall RegEraseKeyCULM(const System::AnsiString KeyName, bool DeleteAllSubkeys
	);
extern PACKAGE int __fastcall RegGetValuesCount(const System::AnsiString KeyName, HKEY RootKey);
extern PACKAGE bool __fastcall RegGetValueNames(const System::AnsiString KeyName, Classes::TStrings* 
	Strings, HKEY RootKey);
extern PACKAGE System::AnsiString __fastcall StringReplace(const System::AnsiString S, const System::AnsiString 
	OldPattern, const System::AnsiString NewPattern, TReplaceFlags Flags);
extern PACKAGE void __fastcall SplitStr(System::AnsiString SubStr, System::AnsiString Str, System::AnsiString 
	&FirstPart, System::AnsiString &SecondPart, TauSplitStrSide MainSide, TauSplitStrSides LeaveSeparatorOn
	);
extern PACKAGE System::AnsiString __fastcall LeftPart(const System::AnsiString SubStr, const System::AnsiString 
	Str);
extern PACKAGE System::AnsiString __fastcall RightPart(const System::AnsiString SubStr, const System::AnsiString 
	Str);
extern PACKAGE System::AnsiString __fastcall LeftPartR(const System::AnsiString SubStr, const System::AnsiString 
	Str);
extern PACKAGE System::AnsiString __fastcall RightPartR(const System::AnsiString SubStr, const System::AnsiString 
	Str);
extern PACKAGE System::AnsiString __fastcall MiddlePart(const System::AnsiString SubStr1, const System::AnsiString 
	SubStr2, const System::AnsiString Str);
extern PACKAGE int __fastcall PosR(const System::AnsiString SubStr, const System::AnsiString Str);
extern PACKAGE int __fastcall PosRM(const SetOfChar &Chars, const System::AnsiString Str);
extern PACKAGE int __fastcall PosCase(const System::AnsiString SubStr, const System::AnsiString Str, 
	bool IgnoreCase);
extern PACKAGE System::AnsiString __fastcall IncludeTrailingBackslash(const System::AnsiString St);
extern PACKAGE System::AnsiString __fastcall ExcludeTrailingBackslash(const System::AnsiString St);
extern PACKAGE System::AnsiString __fastcall IncludeLeadingBackslash(const System::AnsiString St);
extern PACKAGE System::AnsiString __fastcall ExcludeLeadingBackslash(const System::AnsiString St);
extern PACKAGE System::AnsiString __fastcall IncludeLeadingChar(const System::AnsiString St, char Ch
	);
extern PACKAGE System::AnsiString __fastcall ExcludeLeadingChar(const System::AnsiString St, char Ch
	);
extern PACKAGE void __fastcall SplitFilenameAndParams(System::AnsiString &FileName, System::AnsiString 
	&Params);
extern PACKAGE bool __fastcall ParseURL(System::AnsiString URL, System::AnsiString &Protocol, System::AnsiString 
	&HostName, System::AnsiString &URLPath, System::AnsiString &Username, System::AnsiString &Password, 
	System::AnsiString &ExtraInfo, Word &Port);
extern PACKAGE System::AnsiString __fastcall URLToHostName(const System::AnsiString URL);
extern PACKAGE System::AnsiString __fastcall URLToFileName(const System::AnsiString URL);
extern PACKAGE int __fastcall CaseAnsiCompareText(const System::AnsiString S1, const System::AnsiString 
	S2, bool CaseSensitive);
extern PACKAGE Shortint __fastcall VersionCheck(const System::AnsiString NewVersion, const System::AnsiString 
	OldVersion);
extern PACKAGE System::TDateTime __fastcall GMTToLocalTime(System::TDateTime GMTTime);
extern PACKAGE System::TDateTime __fastcall InternetTimeToDateTime(System::AnsiString InternetTime);
	
extern PACKAGE _FILETIME __fastcall DateTimeToFileTime(System::TDateTime Time);
extern PACKAGE System::TDateTime __fastcall FileTimeToDateTime(const _FILETIME &Time);
extern PACKAGE bool __fastcall SetFileTimes(const System::AnsiString FileName, const System::TDateTime 
	Created, System::TDateTime Modified, System::TDateTime Accessed);
extern PACKAGE System::Comp __fastcall Int2x32ToInt64(const int IntHi, const int IntLo);
extern PACKAGE System::Comp __fastcall ExtractFileSize(const System::AnsiString FileName);
extern PACKAGE bool __fastcall LoadResourceToStream(Windows::HINST Instance, char * ResName, char * 
	ResType, Classes::TStream* Stream);
extern PACKAGE void __fastcall ShutdownApplication(void);
extern PACKAGE void __fastcall InitMSRecord(void *Rec, int Size);
extern PACKAGE void __fastcall Wait(int &WaitHandle, int Timeout, bool CheckApplicationTermination);
	
extern PACKAGE void __fastcall StopWait(int &WaitHandle);
extern PACKAGE System::AnsiString __fastcall StreamToString(Classes::TStream* Stream);
extern PACKAGE bool __fastcall SetFileAttr(const System::AnsiString FileName, const TauFileAttributes 
	FileAttr);
extern PACKAGE bool __fastcall GetFileAttr(const System::AnsiString FileName, TauFileAttributes &FileAttr
	);

}	/* namespace Auutils */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Auutils;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// auUtils
