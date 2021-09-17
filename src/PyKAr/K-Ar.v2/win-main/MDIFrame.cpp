//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1997 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "MDIFrame.h"
#include "MDIEdit.h"
#include "KArAgeDlg.h"
#include "SpikeDlg.h"
#include "kdata.h"
#include "FileOpenDataDlg.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFrameForm *FrameForm;
//---------------------------------------------------------------------------
__fastcall TFrameForm::TFrameForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrameForm::Exit1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::Tile1Click(TObject *Sender)
{
  Tile();
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::Cascade1Click(TObject *Sender)
{
  Cascade();
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::Arrangeicons1Click(TObject *Sender)
{
  ArrangeIcons();
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::New1Click(TObject *Sender)
{
  EditForm = new TEditForm(this);
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::Open1Click(TObject *Sender)
{
  if(OpenFileDialog->Execute()){
    EditForm=new TEditForm(this);
    EditForm->Open(OpenFileDialog->FileName);
  }
}
//---------------------------------------------------------------------
void __fastcall TFrameForm::Age1Click(TObject *Sender)
{
	if( AgeForm->ShowModal()==mrOk )
    {
	    EditForm=new TEditForm(this);
    	EditForm->Open(AgeForm->NameRESFile->Text);
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrameForm::Spike1Click(TObject *Sender)
{
	if( SpikeForm->ShowModal()==mrOk )
    {
	    EditForm=new TEditForm(this);
    	EditForm->Open(SpikeForm->NameRESFile->Text);
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrameForm::KData1Click(TObject *Sender)
{
	PagesDlg->ShowModal();	
}
//---------------------------------------------------------------------------
void __fastcall TFrameForm::OpenDAT1Click(TObject *Sender)
{
	if( OpenDATDialog->Execute() )
    	KArDataPages->ShowModal();
}
//---------------------------------------------------------------------------
