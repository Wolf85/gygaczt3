unit IDCardClass;
{
  ���֤��
  ���ߣ�Ī�⽡ gztf@21cn.com
  ע��: NOT COMPLETE for version 3, just minimal functionality
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


    //�˿ں�
    USBPort1 = 1001;
    USBPort2 = 1002;
    USBPort3 = 1003;
    Com1Port = 1;
    Com2Port = 2;
    Com3Port = 3;
    Com4Port = 4;
    Com5Port = 5;
    Com6Port = 6;

    //��������
    Rate9600 = 9600;


    //������
    res_Suc_Operate = $90;//�����ɹ�
    res_Err_CardNoContent = $91;//֤���д���������
    res_Suc_FindCard = $9F;//Ѱ��֤/���ɹ�
    res_Err_PortNo = $1;//�˿ںŲ��Ϸ�
    res_Err_PCRecOverTime = $02;//PC���ճ�ʱ
    res_Err_DataTrans = $03;// ���ݴ������
    res_Err_SAMVNotUse = $05;//��SAM_V���ڲ����ã�ֻ��SDT_GetComBaudʱ���п��ܷ���
    res_Err_RecTerminalDataCheckSum = $10;//����ҵ���ն����ݵ�У��ʹ�
    res_Err_RecTerminalDataLength = $11;//����ҵ���ն����ݵĳ��ȴ�
    res_Err_RecTerminalDataCommand = $21;//����ҵ���ն˵�������󣬰��������еĸ�����ֵ���߼��������
    res_Err_ExceedAuthorityOperate = $23;//ԽȨ����
    res_Err_Unknown = $24;//�޷�ʶ��Ĵ���
    res_Err_FindCard = $80;//Ѱ��֤/��ʧ��
    res_Err_SelectCard = $81;//ѡȡ֤/��ʧ��
    res_Err_CardAuthSAMV = $31;//֤/����֤SAM_Vʧ��
    res_Err_SAMVAuthCard = $32;//SAM_V��֤֤/��ʧ��
    res_Err_InfoVaildate = $33;//��Ϣ��֤����
    res_Err_UnknownCardType = $40;//�޷�ʶ��Ŀ�����
    res_Err_ReadCardOperate = $41;//��֤/������ʧ��
    res_Err_GetRandom = $47;//ȡ�����ʧ��
    res_Err_SAMVCheck = $60;//SAM_V�Լ�ʧ�ܣ����ܽ�������
    res_Err_SAMVNOtAuth = $66;//SAM_Vû������Ȩ���޷�ʹ�� 

    //������Ƭ������
    res_pic_UseSTDAPIDLL =0;	    //����sdtapi.dll����
    res_pic_PhotoDecodeErr = -1;	//��Ƭ�������
    res_pic_WLTSuffixErr = -2;	  //wlt�ļ���׺����
    res_pic_WLTOpenErr = -3;      //wlt�ļ��򿪴���
    res_pic_WLTFormat = -4;       //wlt�ļ���ʽ����
    res_pic_SoftNotAuth = -5;	    //���δ��Ȩ
    res_pic_DeviceConErr = -6;    //�豸���Ӵ���

  cstVnation: array[0..57] of string = ('δ����', '��', '�ɹ�', '��', '��',
    'ά���', '��', '��', '׳', '����', '����',
    '��', '��', '��', '��', '����', '����', '������', '��', '��', '����',
    '��', '�', '��ɽ', '����', 'ˮ', '����', '����', '����', '�¶�����', '��',
    '���Ӷ�', '����', 'Ǽ', '����', '����', 'ë��', '����', '����', '����',
    '����',
    '������', 'ŭ', '���α��', '����˹', '���¿�', '�°�', '����', 'ԣ��',
    '��',
    '������',
    '����', '���״�', '����', '�Ű�', '���', '��ŵ', '����');

  cstSex: array[0..2] of string = ('δ֪', '��', 'Ů');

  cstInfoFileName = 'wz.txt';
  cstPhotoFileName = 'zp.wlt';
  cstBmpFileName = 'zp.bmp';
  cstIfOpen = 0;    // �Ƿ���Ҫ�򿪴���
  cstUSBPort = 0;

  SDT_SUCCESS = $90;
  SDT_FINDCARD_OK = $9F;

function ErrorType(ErrorValue: integer): String;

function PicErrorType(ErrorValue: integer): string;

function SDT_OpenPort(iPort: integer): integer; stdcall; external 'SDTAPI.DLL';
{ iPort[in]��ʾ�˿ںţ�1-16(ʮ����)Ϊ���ڣ�1001-1016(ʮ����)ΪUSB�ڣ�ȱʡ��һ��USB�豸�˿���1001��
  ��������0x90-�򿪶˿ڳɹ�,1-�򿪶˿�ʧ��/�˿ںŲ��Ϸ�
}

function SDT_ClosePort(iPort: integer): integer; stdcall; external 'SDTAPI.DLL';
{iPort[in]��ʾ�˿ںţ�����ֵ0x90-�رմ��ڳɹ���0x01-�˿ںŲ��Ϸ�}

//��ʼ�ҿ�

function SDT_StartFindIDCard(iPort: integer; pucManaInfo: Pbyte; ilfOpen:
  integer): integer; stdcall; external 'SDTAPI.DLL';
{iport[in]��ʾ�˿ںţ�pucManaInfo[out]�޷���ָ�룬֤/��оƬ����ţ�4���ֽڣ�ilfOpen[in]�μ�SDT_ResetSAM
����ֵ0x9f-�ҿ��ɹ���0x80-�ҿ�ʧ��}

//ѡ��

function SDT_SelectIDCard(iPort: integer; pucManaMsg: Pbyte; ilfOpen: integer):
  integer; stdcall; external 'SDTAPI.DLL';
{iPort[in]��ʾ�˿ںţ�pucManaMsg[out]�޷���ָ�룬֤/��оƬ���кţ�8���ֽڣ�ilfOpen[in]�μ�SDT_ResetSAM
����ֵ0x90-ѡ���ɹ���0x81-ѡ��ʧ��}

//��ȡ֤/���̶���Ϣ

function SDT_ReadBaseMsg(iPort: integer; pucCHMsg: Pbyte; puiCHMsgLen: Pinteger;
  pucPHMsg: Pbyte; puiPHMsgLen: Pinteger; ilfOpen: integer): integer; stdcall;
  external 'SDTAPI.DLL';
{iPort[in]��ʾ�˿ںţ�pucCHMsg[out]ָ�������������Ϣ��puiCHMsgLen[out]ָ�������������Ϣ����
pucPHMsg[out]ָ���������Ƭ��Ϣ��puiPHMsgLen[out]ָ���������Ƭ��Ϣ���ȣ�ilfOpen[in]�μ�SDT_ResetSAM
����ֵ0x90-���̶���Ϣ�ɹ����������̶���Ϣʧ��}

//function SDT_ReadBaseMsgToFile(iPort: Integer; fileName1: string; puiCHMsgLen:
//  Pinteger;
//  fileName2: string; puiPHMsgLen: Pinteger; iIfOpen: Integer): integer; stdcall;
//  external 'SDTAPI.DLL';

function SDT_ReadBaseMsgToFile(iPortID:integer;pcCHMsgFileName:PChar;puiCHMsgFileLen:pinteger;pcPHMsgFileName:PChar;puiPHMsgFileLen:pinteger;iIfOpen:integer):integer;stdcall;external 'SDTAPI.DLL' name 'SDT_ReadBaseMsgToFile';

function GetBmp(Wlt_File: PChar; intf: integer): integer; stdcall; external
  'WltRS.dll';
{Wlt_File-wlt�ļ�����intf�Ķ��豸ͨѶ�ӿ�����(1-RS-232C,2-USB)
����ֵ������*.bmp�����·�����Ϣ:1-��Ƭ������ȷ��0-����sdtapi.dll����,-1-��Ƭ�������-2-wlt�ļ���׺����
-3-wlt�ļ��򿪴���-4-wlt�ļ���ʽ����-5-���δ��Ȩ��-6-�豸���Ӵ���}


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
    Result := 'δ֪' ;
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
       97: Result := '������뼮';
  else
      Result := '����';
  end;
end;

constructor TIDCardClass.Create(cardmsg : TIDCardData);
begin 
  inherited Create; // ���ø���Ĺ��캯��
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
    res_Suc_Operate: Result := ' �����ɹ�!';
    res_Err_CardNoContent: Result := ' ֤���д���������!';
    res_Suc_FindCard: Result := ' Ѱ��֤/���ɹ�!';
    res_Err_PortNo: Result := ' �˿ںŲ��Ϸ�!';
    res_Err_PCRecOverTime: Result := ' PC���ճ�ʱ!';
    res_Err_DataTrans: Result := ' ���ݴ������!';
    res_Err_SAMVNotUse: Result := ' ��SAM_V���ڲ����ã�ֻ��SDT_GetComBaudʱ���п��ܷ���!';
    res_Err_RecTerminalDataCheckSum: Result := ' ����ҵ���ն����ݵ�У��ʹ�!';
    res_Err_RecTerminalDataLength: Result := ' ����ҵ���ն����ݵĳ��ȴ�!';
    res_Err_RecTerminalDataCommand: Result := ' ����ҵ���ն˵�������󣬰��������еĸ�����ֵ���߼��������!';
    res_Err_ExceedAuthorityOperate: Result := ' ԽȨ����!';
    res_Err_Unknown: Result := ' �޷�ʶ��Ĵ���!';
    res_Err_FindCard: Result := ' Ѱ��֤/��ʧ��!';
    res_Err_SelectCard: Result := ' ѡȡ֤/��ʧ��!';
    res_Err_CardAuthSAMV: Result := ' ֤/����֤SAM_Vʧ��!';
    res_Err_SAMVAuthCard: Result := ' SAM_V��֤֤/��ʧ��!';
    res_Err_InfoVaildate: Result := ' ��Ϣ��֤����!';
    res_Err_UnknownCardType: Result := ' �޷�ʶ��Ŀ�����!';
    res_Err_ReadCardOperate: Result := ' ��֤/������ʧ��!';
    res_Err_GetRandom: Result := ' ȡ�����ʧ��!';
    res_Err_SAMVCheck: Result := ' SAM_V�Լ�ʧ�ܣ����ܽ�������!';
    res_Err_SAMVNOtAuth: Result := ' AM_Vû������Ȩ���޷�ʹ��!';
  else
    Result := ' δ֪���󣬴��󷵻�ֵ'+ inttostr(ErrorValue);
  end;

end;

function PicErrorType(ErrorValue: integer): String;
begin
  Result := '';
  Case ErrorValue of
    res_pic_UseSTDAPIDLL: Result := ' ����sdtapi.dll����!';
    res_pic_PhotoDecodeErr: Result := ' ��Ƭ�������!';
    res_pic_WLTSuffixErr: Result := ' wlt�ļ���׺����!';
    res_pic_WLTOpenErr: Result := ' wlt�ļ��򿪴���!';
    res_pic_WLTFormat: Result := ' wlt�ļ���ʽ����!';
    res_pic_SoftNotAuth: Result := ' ���δ��Ȩ!';
    res_pic_DeviceConErr: Result := ' �豸���Ӵ���!';
  else
    Result := ' �������ͣ�δ֪����!����ֵ'+ inttostr(ErrorValue);
  end;  
end;
end.
 