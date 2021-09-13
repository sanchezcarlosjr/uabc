//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "Main.h"
#include "KArAgeDlg.h"
#include "SpikeDlg.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	Application->OnHint = ShowHint;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::ShowHint(TObject *Sender)
{
	StatusLine->SimpleText = Application->Hint;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::OpenAgeDlg(TObject *Sender)
{
	AgeForm->ShowModal();
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FileSave(TObject *Sender)
{
	//---- Add code to save current file under current name ----
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FileSaveAs(TObject *Sender)
{
	if (SaveDialog->Execute())
	{
		//--- Add code to save current file under SaveDialog->FileName ---
	}
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FilePrint(TObject *Sender)
{
	if (PrintDialog->Execute())
	{
		//---- Add code to print current file ----
	}
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FilePrintSetup(TObject *Sender)
{
	PrintSetupDialog->Execute();
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FileExit(TObject *Sender)
{
	Close();
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::WindowTile(TObject *Sender)
{
	Tile();
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::WindowCascade(TObject *Sender)
{
	Cascade();
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::WindowArrange(TObject *Sender)
{
	ArrangeIcons();
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::HelpContents(TObject *Sender)
{
	Application->HelpCommand(HELP_CONTENTS, 0);
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::HelpSearch(TObject *Sender)
{
	Application->HelpCommand(HELP_PARTIALKEY, Longint(""));
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::HelpHowToUse(TObject *Sender)
{
	Application->HelpCommand(HELP_HELPONHELP, 0);
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::HelpAbout(TObject *Sender)
{
	//---- Add code to show program's About Box ----
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::SpeedButton3Click(TObject *Sender)
{
	SpikeForm->ShowModal();
}
//---------------------------------------------------------------------------
