{*******************************************************}
{                                                       }
{       ��Ա��ѯϵͳ                                    }
{                                                       }
{       ��Ȩ���� (C) 2012 ������·������                }
{                                                       }
{*******************************************************}

{
modify:
  2012-10-25���޸����Ա�ֵ��������
}
unit RyxxClass;

interface

type
  TRyxx = class
  private
    FId : string;
    FName : string;
    FIdCardNo : string;
    FSex : string;
    FHeight : string;
    FSponsor : string;
    FContact : string;
    FPhone : string;
    FNumber : string;
    FLevel : string;
    FCategory : string;
  private
      
    procedure SetSex(value: string);
  public
    property 	Id	: string read	FId	write	FId	;
    property 	Name	: string read	FName	write	FName	;
    property 	IdCardNo	: string read	FIdCardNo	write	FIdCardNo	;
    property 	Sex	: string read	FSex	write	SetSex	;
    property 	Height	: string read	FHeight	write	FHeight	;
    property 	Sponsor	: string read	FSponsor	write	FSponsor	;
    property 	Contact	: string read	FContact	write	FContact	;
    property 	Phone	: string read	FPhone	write	FPhone	;
    property 	Number	: string read	FNumber	write	FNumber	;
    property 	Level	: string read	FLevel	write	FLevel	;
    property 	Category	: string read	FCategory	write	FCategory	;
  public
    constructor Create;overload;
    constructor Create(const Id :string; const Name :string; const IdCardNo :string; const Sex :string; const Height :string; const Sponsor :string; const Contact :string; const Phone :string; const Number :string; const Level :string; const Category  :string);overload;
  end;
implementation

constructor TRyxx.Create;
begin
  inherited Create;
end;

constructor TRyxx.Create(const Id :string; const Name :string; const IdCardNo :string; const Sex :string; const Height :string; const Sponsor :string; const Contact :string; const Phone :string; const Number :string; const Level :string; const Category  :string);
begin 
  inherited Create; // ���ø���Ĺ��캯��
  FId :=	Id	;
  FName	:=	Name	;
  FIdCardNo	:=	IdCardNo	;
  FSex	:=	Sex	;
  FHeight	:=	Height	;
  FSponsor	:=	Sponsor	;
  FContact	:=	Contact	;
  FPhone	:=	Phone	;
  FNumber	:=	Number	;
  FLevel	:=	Level	;
  FCategory	:=	Category	;

end;

procedure TRyxx.SetSex(value: string);
begin

  if value = '1' then
    FSex := '��'
  else if value = '2' then
      FSex := 'Ů'
  else
    FSex := value;
  
end;

end.
