//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.IOUtils.hpp>


#pragma hdrstop

#include "Unit17.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm17 *Form17;
//---------------------------------------------------------------------------
__fastcall TForm17::TForm17(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm17::FormCreate(TObject *Sender)
{
    IdHTTPServer1->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm17::IdHTTPServer1CommandGet(TIdContext *AContext, TIdHTTPRequestInfo *ARequestInfo,
          TIdHTTPResponseInfo *AResponseInfo)
{
	pmef("command get");

    //from http://www.e-iter.net/knowledge/indy9/007389.html
	pme(ARequestInfo->Command);
	pme(ARequestInfo->Document);
	pme(ARequestInfo->RawHTTPCommand);
	pme(ARequestInfo->RemoteIP);
	pme(ARequestInfo->Version);
	for (auto a:ARequestInfo->Params) {
		pme(a);
	}
	for (auto a:ARequestInfo->QueryParams) {
		pme(a);
	}

    try
	{
		String f = TFile::ReadAllText("brad.html");
		pme("Loaded file");
		AResponseInfo->ContentText = f;

	}
	catch(...)
	{
		/* Catch the possible exceptions */
		MessageDlg("Incorrect path", mtError, TMsgDlgButtons() << mbOK, 0);
		return;
	}


	/*
	String resp =  "<html><head><title>My First Response</title></head>";
	resp += "<body>Command: ";
	resp += ARequestInfo->Command +  "<br />Host: ";
	resp += ARequestInfo->Host +  "<br />URI: ";
	resp += ARequestInfo->URI +   "<br />UserAgent: ";
	resp += ARequestInfo->UserAgent +  "</body></html>";

	pme(resp);



	AResponseInfo->ContentText = resp;
    */

}
//---------------------------------------------------------------------------


void  TForm17::pmef(const char* fmt, ...)
{
	//Check length and clear after 1000 lines

	if (MemoDebug->Lines->Count > 1000)		MemoDebug->Lines->Clear();
	va_list args;
	va_start(args, fmt);
	char buf[2000];
	vsprintf(buf,fmt,args);

	MemoDebug->Lines->Add(buf);

	va_end(args);

	//scroll to bottom of text
	MemoDebug->SelStart = MemoDebug->Lines->Text.Length();
	MemoDebug->SelLength = 1;
	MemoDebug->ClearSelection();
}

void  TForm17::pme(String s)
{
	//Check length and clear after 1000 lines
	if (MemoDebug->Lines->Count > 1000)		MemoDebug->Lines->Clear();
	MemoDebug->Lines->Add(s);
	//scroll to bottom of text
	MemoDebug->SelStart = MemoDebug->Lines->Text.Length();
	MemoDebug->SelLength = 1;
	MemoDebug->ClearSelection();
}
//---------------------------------------------------------------------------


void __fastcall TForm17::Button1Click(TObject *Sender)
{
    WebBrowser1->Navigate("localhost");
}
//---------------------------------------------------------------------------
void __fastcall TForm17::BN_QuitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
