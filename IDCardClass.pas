unit IDCardClass;
{
  身份证类
  作者：莫光健 gztf@21cn.com
  注意: NOT COMPLETE for version 3, just minimal functionality
  Adapted from file created by Pablo Pissanetzky (pablo@myhtpc.net)
  which was based on SQLite.pas by Ben Hochstrasser (bhoc@surfeu.ch)
}
interface

const

    FEnable: Boolean = true;
    FDisEnable: boolean = false;
    FNull = '';
    FZero = '0';
    IFOpen = 1;


    //端口号
    USBPort1 = 1001;
    USBPort2 = 1002;
    USBPort3 = 1003;
    Com1Port = 1;
    Com2Port = 2;
    Com3Port = 3;
    Com4Port = 4;
    Com5Port = 5;
    Com6Port = 6;

    //串口速率
    Rate9600 = 9600;


    //错误码
    res_Suc_Operate = $90;//操作成功
    res_Err_CardNoContent = $91;//证卡中此项无内容
    res_Suc_FindCard = $9F;//寻找证/卡成功
    res_Err_PortNo = $1;//端口号不合法
    res_Err_PCRecOverTime = $02;//PC接收超时
    res_Err_DataTrans = $03;// 数据传输错误
    res_Err_SAMVNotUse = $05;//该SAM_V串口不可用，只在SDT_GetComBaud时才有可能返回
    res_Err_RecTerminalDataCheckSum = $10;//接收业务终端数据的校验和错
    res_Err_RecTerminalDataLength = $11;//接收业务终端数据的长度错
    res_Err_RecTerminalDataCommand = $21;//接收业务终端的命令错误，包括命令中的各种数值或逻辑搭配错误
    res_Err_ExceedAuthorityOperate = $23;//越权操作
    res_Err_Unknown = $24;//无法识别的错误
    res_Err_FindCard = $80;//寻找证/卡失败
    res_Err_SelectCard = $81;//选取证/卡失败
    res_Err_CardAuthSAMV = $31;//证/卡认证SAM_V失败
    res_Err_SAMVAuthCard = $32;//SAM_V认证证/卡失败
    res_Err_InfoVaildate = $33;//信息验证错误
    res_Err_UnknownCardType = $40;//无法识别的卡类型
    res_Err_ReadCardOperate = $41;//读证/卡操作失败
    res_Err_GetRandom = $47;//取随机数失败
    res_Err_SAMVCheck = $60;//SAM_V自检失败，不能接收命令
    res_Err_SAMVNOtAuth = $66;//SAM_V没经过授权，无法使用 

    //解析照片错误码
    res_pic_UseSTDAPIDLL =0;	    //调用sdtapi.dll错误
    res_pic_PhotoDecodeErr = -1;	//相片解码错误
    res_pic_WLTSuffixErr = -2;	  //wlt文件后缀错误
    res_pic_WLTOpenErr = -3;      //wlt文件打开错误
    res_pic_WLTFormat = -4;       //wlt文件格式错误
    res_pic_SoftNotAuth = -5;	    //软件未授权
    res_pic_DeviceConErr = -6;    //设备连接错误

  cstVnation: array[0..57] of string = ('未定义', '汉', '蒙古', '回', '藏',
    '维吾尔', '苗', '彝', '壮', '布依', '朝鲜',
    '满', '侗', '瑶', '白', '土家', '哈尼', '哈萨克', '傣', '黎', '傈僳',
    '佤', '畲', '高山', '拉祜', '水', '东乡', '纳西', '景颇', '柯尔克孜', '土',
    '达斡尔', '仫佬', '羌', '布朗', '撒拉', '毛南', '仡佬', '锡伯', '阿昌',
    '普米',
    '塔吉克', '怒', '乌孜别克', '俄罗斯', '鄂温克', '德昂', '保安', '裕固',
    '京',
    '塔塔尔',
    '独龙', '鄂伦春', '赫哲', '门巴', '珞巴', '基诺', '其它');

  cstSex: array[0..2] of string = ('未知', '男', '女');

  cstInfoFileName = 'wz.txt';
  cstPhotoFileName = 'zp.wlt';
  cstBmpFileName = 'zp.bmp';
  cstIfOpen = 0;    // 是否需要打开串口
  cstUSBPort = 0;

  SDT_SUCCESS = $90;
  SDT_FINDCARD_OK = $9F;

function ErrorType(ErrorValue: integer): String;

function PicErrorType(ErrorValue: integer): string;

function SDT_OpenPort(iPort: integer): integer; stdcall; external 'SDTAPI.DLL';
{ iPort[in]表示端口号，1-16(十进制)为串口，1001-1016(十进制)为USB口，缺省的一个USB设备端口是1001。
  函数返回0x90-打开端口成功,1-打开端口失败/端口号不合法
}

function SDT_ClosePort(iPort: integer): integer; stdcall; external 'SDTAPI.DLL';
{iPort[in]表示端口号，返回值0x90-关闭串口成功，0x01-端口号不合法}

//开始找卡

function SDT_StartFindIDCard(iPort: integer; pucManaInfo: Pbyte; ilfOpen:
  integer): integer; stdcall; external 'SDTAPI.DLL';
{iport[in]表示端口号，pucManaInfo[out]无符号指针，证/卡芯片管理号，4个字节，ilfOpen[in]参见SDT_ResetSAM
返回值0x9f-找卡成功，0x80-找卡失败}

//选卡

function SDT_SelectIDCard(iPort: integer; pucManaMsg: Pbyte; ilfOpen: integer):
  integer; stdcall; external 'SDTAPI.DLL';
{iPort[in]表示端口号，pucManaMsg[out]无符号指针，证/卡芯片序列号，8个字节，ilfOpen[in]参见SDT_ResetSAM
返回值0x90-选卡成功，0x81-选卡失败}

//读取证/卡固定信息

function SDT_ReadBaseMsg(iPort: integer; pucCHMsg: Pbyte; puiCHMsgLen: Pinteger;
  pucPHMsg: Pbyte; puiPHMsgLen: Pinteger; ilfOpen: integer): integer; stdcall;
  external 'SDTAPI.DLL';
{iPort[in]表示端口号，pucCHMsg[out]指向读到的文字信息，puiCHMsgLen[out]指向读到的文字信息长度
pucPHMsg[out]指向读到的照片信息，puiPHMsgLen[out]指向读到的照片信息长度，ilfOpen[in]参见SDT_ResetSAM
返回值0x90-读固定信息成功，其他读固定信息失败}

//function SDT_ReadBaseMsgToFile(iPort: Integer; fileName1: string; puiCHMsgLen:
//  Pinteger;
//  fileName2: string; puiPHMsgLen: Pinteger; iIfOpen: Integer): integer; stdcall;
//  external 'SDTAPI.DLL';

function SDT_ReadBaseMsgToFile(iPortID:integer;pcCHMsgFileName:PChar;puiCHMsgFileLen:pinteger;pcPHMsgFileName:PChar;puiPHMsgFileLen:pinteger;iIfOpen:integer):integer;stdcall;external 'SDTAPI.DLL' name 'SDT_ReadBaseMsgToFile';

function GetBmp(Wlt_File: PChar; intf: integer): integer; stdcall; external
  'WltRS.dll';
{Wlt_File-wlt文件名，intf阅读设备通讯接口类型(1-RS-232C,2-USB)
返回值：生成*.bmp和以下返回信息:1-相片解码正确，0-调用sdtapi.dll错误,-1-相片解码错误，-2-wlt文件后缀错误，
-3-wlt文件打开错误，-4-wlt文件格式错误，-5-软件未授权，-6-设备连接错误}


type
  TIDCardData = record
    name: array[0..29] of Byte;
    sex: array[0..1] of Byte;
    nation: array[0..3] of Byte;
    born: array[0..15] of Byte;
    address: array[0..69] of Byte;
    IDcardno: array[0..35] of Byte;
    grantdept: array[0..29] of Byte;
    UserLifeBegin: array[0..15] of Byte;
    UserLifeEnd: array[0..15] of Byte;
    reserved: array[0..35] of Byte;
//    unused : array[0..127] of Byte;
  end;

type
  TIDCardClass = class
  private
    FName: string;
    FSex: string;
    FNation: string;
    FBorn: string;
    FAddress: string;
    FIdcardno: string;
    FUserLifeEnd: string;
    FGrantdept: string;

  private
    function GetSex : string;
    function GetNation : string;
  public
    property Name: string read FName write FName;
    property Sex: string read GetSex write FSex;
    property Nation: string read GetNation write FNation;
    property Born: string read FBorn write FBorn;
    property Address: string read FAddress write FAddress;
    property Idcardno: string read FIdcardno write FIdcardno;
    property UserLifeEnd: string read FUserLifeEnd write FUserLifeEnd;
    property Grantdept: string read FGrantdept write FGrantdept;
  public
    constructor Create(cardmsg : TIDCardData);
  end;

implementation

uses SysUtils;

function TIDCardClass.GetSex : string;
var
  intSex : Integer;
begin
  try
    intSex := StrToInt(FSex);
  except
     on EConvertError do intSex := 0;
  end;
  if intSex < 3 then
    Result := cstsex[intSex]
  else
    Result := '未知' ;
end;

function TIDCardClass.GetNation : string;
var
  intNation : Integer;
begin
  try
    intNation := StrToInt(FNation);
  except
    on EConvertError do intNation := 0;
  end;

  case intNation of
    0..57: Result := cstVnation[intNation] ;
       97: Result := '外国人入籍';
  else
      Result := '其它';
  end;
end;

constructor TIDCardClass.Create(cardmsg : TIDCardData);
begin 
  inherited Create; // 调用父类的构造函数
  FName := trim(WideCharLenToString(PWideChar(@cardmsg.name), 15));
  FSex := Trim(WideCharLenToString(PWideChar(@CardMsg.sex),1));
  FNation := Trim(WideCharLenToString(PWideChar(@CardMsg.Nation), 2));
  Born := Trim(WideCharLenToString(PWideChar(@CardMsg.Born), 8));
  Address := Trim(WideCharLenToString(PWideChar(@CardMsg.address), 35));
  Idcardno := Trim(WideCharLenToString(PWideChar(@CardMsg.Idcardno), 18));
  UserLifeEnd := Trim(WideCharLenToString(PWideChar(@CardMsg.UserLifeEnd), 15));
end;


function ErrorType(ErrorValue: integer): String;
begin
  Result := '';

  Case ErrorValue of
    res_Suc_Operate: Result := ' 操作成功!';
    res_Err_CardNoContent: Result := ' 证卡中此项无内容!';
    res_Suc_FindCard: Result := ' 寻找证/卡成功!';
    res_Err_PortNo: Result := ' 端口号不合法!';
    res_Err_PCRecOverTime: Result := ' PC接收超时!';
    res_Err_DataTrans: Result := ' 数据传输错误!';
    res_Err_SAMVNotUse: Result := ' 该SAM_V串口不可用，只在SDT_GetComBaud时才有可能返回!';
    res_Err_RecTerminalDataCheckSum: Result := ' 接收业务终端数据的校验和错!';
    res_Err_RecTerminalDataLength: Result := ' 接收业务终端数据的长度错!';
    res_Err_RecTerminalDataCommand: Result := ' 接收业务终端的命令错误，包括命令中的各种数值或逻辑搭配错误!';
    res_Err_ExceedAuthorityOperate: Result := ' 越权操作!';
    res_Err_Unknown: Result := ' 无法识别的错误!';
    res_Err_FindCard: Result := ' 寻找证/卡失败!';
    res_Err_SelectCard: Result := ' 选取证/卡失败!';
    res_Err_CardAuthSAMV: Result := ' 证/卡认证SAM_V失败!';
    res_Err_SAMVAuthCard: Result := ' SAM_V认证证/卡失败!';
    res_Err_InfoVaildate: Result := ' 信息验证错误!';
    res_Err_UnknownCardType: Result := ' 无法识别的卡类型!';
    res_Err_ReadCardOperate: Result := ' 读证/卡操作失败!';
    res_Err_GetRandom: Result := ' 取随机数失败!';
    res_Err_SAMVCheck: Result := ' SAM_V自检失败，不能接收命令!';
    res_Err_SAMVNOtAuth: Result := ' AM_V没经过授权，无法使用!';
  else
    Result := ' 未知错误，错误返回值'+ inttostr(ErrorValue);
  end;

end;

function PicErrorType(ErrorValue: integer): String;
begin
  Result := '';
  Case ErrorValue of
    res_pic_UseSTDAPIDLL: Result := ' 调用sdtapi.dll错误!';
    res_pic_PhotoDecodeErr: Result := ' 相片解码错误!';
    res_pic_WLTSuffixErr: Result := ' wlt文件后缀错误!';
    res_pic_WLTOpenErr: Result := ' wlt文件打开错误!';
    res_pic_WLTFormat: Result := ' wlt文件格式错误!';
    res_pic_SoftNotAuth: Result := ' 软件未授权!';
    res_pic_DeviceConErr: Result := ' 设备连接错误!';
  else
    Result := ' 错误类型：未知错误!返回值'+ inttostr(ErrorValue);
  end;  
end;
end.
 