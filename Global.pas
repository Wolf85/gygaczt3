unit Global;

interface

{
  编码转换
}
function UnicodeEncode(Str:string;CodePage:integer):WideString;
function UnicodeDecode(Str:WideString;CodePage:integer):string;
function Gb2Big5(Str:string):string; 
function Big52Gb(Str:string):string; 
function Utf8Encode(const WS: WideString): UTF8String;
function UnicodeToAnsi(SubUnicode: string):string;
function HexToInt(hex:string):cardinal; 

implementation
uses
  SysUtils, Windows;


function UnicodeEncode(Str:string;CodePage:integer):WideString; 
var 
  Len:integer; 
begin 
  Len:=Length(Str)+1;  
  SetLength(Result,Len); 
  Len:=MultiByteToWideChar(CodePage,0,PChar(Str),-1,PWideChar(Result),Len);
  SetLength(Result,Len-1); //end is #0 
end; 

function UnicodeDecode(Str:WideString;CodePage:integer):string; 
var 
  Len:integer; 
begin 
  Len:=Length(Str)*2+1;  //one for #0 
  SetLength(Result,Len); 
  Len:=WideCharToMultiByte(CodePage,0,PWideChar(Str),-1,PChar(Result),Len,nil,nil); 
  SetLength(Result,Len-1); 
end; 

function Gb2Big5(Str:string):string; 
begin 
  SetLength(Result,Length(Str)); 
  LCMapString(GetUserDefaultLCID,LCMAP_TRADITIONAL_CHINESE, 
  PChar(Str),Length(Str), 
  PChar(Result),Length(Result)); 
  Result:=UnicodeDecode(UnicodeEncode(Result,936),950); 
end; 

function Big52Gb(Str:string):string; 
begin 
  Str:=UnicodeDecode(UnicodeEncode(Str,950),936); 
  SetLength(Result,Length(Str)); 
  LCMapString(GetUserDefaultLCID,LCMAP_SIMPLIFIED_CHINESE,
    PChar(Str),Length(Str), 
   PChar(Result),Length(Result)); 
end;


function Utf8Encode(const WS: WideString): UTF8String; 
var 
  L: Integer; 
  Temp: UTF8String; 
begin 
  Result := ''; 
  if WS = '' then Exit; 
  SetLength(Temp, Length(WS) * 3); // SetLength includes space for null terminator 
  L := UnicodeToUtf8(PChar(Temp), Length(Temp)+1, PWideChar(WS), Length(WS)); 
  if L > 0 then 
    SetLength(Temp, L-1) 
  else 
    Temp := ''; 
  Result := Temp; 
end; 


{-------------------------------------------------------------------------------
  过程名:    UnicodeToAnsi, Unicode 解码 Delphi: 将Unicode码转换为汉字
  作者:      Administrator
  日期:      2011.04.25
  参数:      SubUnicode: string
  返回值:    string
-------------------------------------------------------------------------------}
function UnicodeToAnsi(SubUnicode: string):string;  //将unicode码转换为汉字
var 
   a:array[0..500] of char;  
   s1,s2:char;  
   substr1,substr2,s:string;  
   str:string;  
   i:integer;  
begin 
    if length(SubUnicode) mod 4 = 0 then  
    Begin  
       str:='';  
       for i:=1 to length(SubUnicode) div 4 do  
       Begin  
        s:='';  
        substr1:=copy(SubUnicode,i*4-3,2);  
        substr2:=copy(SubUnicode,i*4-1,2);  
        s1:=chr(HexToInt(substr1));
        s2:=chr(HexToInt(substr2));
        s:=s+s2+s1;  
        strpcopy(a,s);  
         str:=str+copy(widechartostring(@(a[0])),1,2);  
       end;  
      result:=str; 
     end;  
  end;  

function HexToInt(hex:string):cardinal;  
const 
  cHex='0123456789ABCDEF';
var 
  mult,i,loop:integer;
begin  
     result:=0; 
     mult:=1;  
     for loop:=length(hex)downto 1 do  
     begin 
      i:=pos(hex[loop],cHex)-1;  
     if (i<0) then i:=0;  
       inc(result,(i*mult));  
      mult:=mult*16;  
     end;  
end;   

end.
