//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "kdata.h"
#include "KSample.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TPagesDlg *PagesDlg;
//--------------------------------------------------------------------- 
__fastcall TPagesDlg::TPagesDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TPagesDlg::Button1Click(TObject *Sender)
{
    TListItem * ListItems;

	if( SampleDlg->ShowModal()==mrOk )
    {
	    ListItems = SamplesList->Items->Add();
    	ListItems->Caption = SampleDlg->EditNoLab->Text;
    	ListItems->SubItems->Add(SampleDlg->EditSample->Text);
    	ListItems->SubItems->Add(SampleDlg->EditMineral->Text);
    	ListItems->SubItems->Add(SampleDlg->EditDate->Text);
    	ListItems->SubItems->Add(SampleDlg->EditLecture->Text);
    	ListItems->SubItems->Add(SampleDlg->EditDil->Text);
    	ListItems->SubItems->Add(SampleDlg->EditWeight->Text);
    }
}
//---------------------------------------------------------------------------
void __fastcall TPagesDlg::SamplesListDblClick(TObject *Sender)
{
	if( SamplesList->SelCount>0 )
    {
		SampleDlg->EditNoLab->Text= SamplesList->Selected->Caption;
        //investigar como se accesan y modofican los SubItems de cad elemento
		//SampleDlg->EditSample->Text= SamplesList->SubItems->Strings[0];

		if( SampleDlg->ShowModal()==mrOk )
    	{
    		SamplesList->Selected->Caption= SampleDlg->EditNoLab->Text;
	    }
    }
}
//---------------------------------------------------------------------------
