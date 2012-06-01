unit RyxxClass;

interface

type
  TRyxx = class
  private
    FXm: string;
    FNumber: string;
    FJb: string;
    FLb: string;
    FZtbh: string;
  private

  public
    property Xm: string read FXm write FXm;
    property Number: string read FNumber write FNumber;
    property Jb: string read FJb write FJb;
    property Lb: string read FLb write FLb;
    property Ztbh: string read FZtbh write FZtbh;
  public
    constructor Create;overload;
    constructor Create(const xm:string; const number:string; const jb:string; const lb:string; const ztbh:string);overload;
  end;
implementation

constructor TRyxx.Create;
begin
  inherited Create;
end;

constructor TRyxx.Create(const xm:string; const number:string; const jb:string; const lb:string; const ztbh:string);
begin 
  inherited Create; // 调用父类的构造函数
  FXm :=  xm;
  FNumber := number;
  FJb := jb;
  FLb := lb;
  FZtbh := ztbh;
end;

end.
