{$DEFINE DEBUG}
{*******************************************************}
{                                                       }
{       追逃系统                                        }
{                                                       }
{       版权所有 (C) 2010 贵阳公安处                    }
{                                                       }
{*******************************************************}
unit ReadThread;

interface

uses
  Classes, SysUtils, Windows, Main, mmsystem, IniOptionsUnit, IDCardClass;

type

  TReadThread = class(TThread)
  private
    { Private declarations }
    IDCard : TIDCardClass;
    FRecno : Integer;
  private
    function GetCardmsg(const cardmsg : TIDCardData;const filename:string): TIDCardClass;
    procedure PlayHintSound(const Recno :Integer);
    //function Search(const idcardno : string): Integer; //返回-1：没有查到结果，否则有结果返回，结果存储在Recno中
    procedure Search;   //返回-1：没有查到结果，否则有结果返回，结果存储在FRecno中
    procedure ShowMsg;
  protected
    procedure Execute; override;
  end;

implementation
uses
  LogHelperUnit;
{ Important: Methods and properties of objects in visual components can only be
used in a method called using Synchronize, for example,

    Synchronize(UpdateCaption);

and UpdateCaption could look like,

  procedure TReadThread.UpdateCaption;
  begin
    Form1.Caption := 'Updated in a thread';
  end; }

{ TReadThread }

procedure TReadThread.Execute;
var

  pucIIN: array[0..3] of Byte;
  pucSN: array[0..7] of Byte;
{$IFDEF DEBUG}  
  pucPHMsg : array[0..1023] of Byte;
  fsPhoto : TFileStream;
{$ELSE}
  UnTypedFile: file of TIDCardData;
{$ENDIF}
  uiCHMsgLen, uiPHMsgLen: Cardinal;
  cardmsg: TIDCardData;
  strFilename: string;

begin

  strFilename := ExtractFilePath(ParamStr(0)) + cstInfoFileName;
  while (not Terminated) do
  begin

        if SDT_StartFindIDCard(Port, @pucIIN, cstIfOpen) = SDT_FINDCARD_OK then

        begin
          if SDT_SelectIDCard(Port, @pucSN, cstIfOpen) = SDT_SUCCESS then
          begin   
              if SDT_ReadBaseMsg(Port, @cardmsg, @uiCHMsgLen, @pucPHMsg, @uiPHMsgLen, cstIfOpen) = SDT_SUCCESS then
              begin
{$IFDEF DEBUG}
                strFilename := ExtractFilePath(ParamStr(0)) + cstPhotoFileName;
                fsPhoto := TFileStream.Create(strFilename,fmCreate);
                try
                  fsPhoto.Position:=0;
                  fsPhoto.Write(pucPHMsg,uiPHMsgLen);
                finally
                  FreeAndNil(fsPhoto);
                end;
{$ELSE}
                if fileExists(strFilename) then
                begin
                  assignfile(UnTypedFile, strFilename);
                  reset(UnTypedFile);
                  try
                    if not Eof(UnTypedFile) then
                      read(UnTypedFile, cardmsg);
                  finally
                    CloseFile(UnTypedFile);
                  end;
                end;
{$ENDIF}
                IDCard := GetCardmsg(cardmsg,cstPhotoFileName);
                try
                  Synchronize(ShowMsg);
                  //Recno := Search(IDCard.Idcardno);
                  Synchronize(Search);
                  if IniOptions.PlaySound then PlayHintSound(FRecno);
                  LogHelper.Write(IDCard.Idcardno);
                finally
                  FreeAndNil(IDCard);
                end;

              end;
            end;
          end;
    Sleep(IniOptions.SpanInSecs);
  end;
end;

procedure TReadThread.ShowMsg;
begin
  if IDCard <> nil then
  begin
    with frmMain do
    begin
      edtName.Text := IDCard.Name;
      edtSex.Text := IDCard.sex;
      edtNation.Text := IDCard.Nation;
      edtBorn.Text := IDCard.Born;
      edtAddress.Text := IDCard.Address;
      edtIDCardNO.Text := IDCard.Idcardno;
      edtUserLifeEnd.Text := IDCard.UserLifeEnd;
      edtGrantdept.Text := IDCard.Grantdept;
      if fileExists(cstBmpFileName) then
      begin
        with img1 do
        begin
          picture.bitmap.loadfromfile(cstBmpFileName);
          picture.bitmap.transparent := true;
          picture.bitmap.transparentcolor := picture.bitmap.canvas.pixels[5, 3];
        end;
      end;
    end;
  end;
end;



procedure TReadThread.Search;
begin
  FRecno := -1;
//  with frmMain.qryADO do
//  begin
//    if Active = True then Active := False;
//    SQL.Text := Format(IniOptions.SQL, [IDCard.Idcardno]);
//    Active := True;
//    if Recno > 0 then FRecno := Recno;
//  end;
end;

{-------------------------------------------------------------------------------
  过程名:    TReadThread.GetCardmsg
  作者:      Administrator
  日期:      2010.06.12
  参数:      cardmsg : TIDCardData
  返回值:    无
-------------------------------------------------------------------------------}
function TReadThread.GetCardmsg(const cardmsg : TIDCardData; const filename:string) : TIDCardClass; 
begin
  GetBmp(PChar(filename), 2);
  Result := TIDCardClass.Create(cardmsg);
end;

{-------------------------------------------------------------------------------
  过程名:    TReadThread.PlaySound
  作者:      Administrator
  日期:      2010.06.12
  参数:      Recno :Integer 查询返回结果数，>0表示有结果
  返回值:    无
-------------------------------------------------------------------------------}
procedure TReadThread.PlayHintSound(const Recno :Integer);
begin
  if Recno>0 then
    PlaySound(PChar(IniOptions.AlarmFileA), 0, 0)
  else
    if IniOptions.PlayPassedSound then
        PlaySound(PChar(IniOptions.PassedSoundFile), 0, 0);   
end;
end.

