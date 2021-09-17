//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FileOpenDataDlg.h"
#include "Edad-K-Ar.h"
#include "MDIFrame.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TKArDataPages *KArDataPages;
//--------------------------------------------------------------------- 
__fastcall TKArDataPages::TKArDataPages(TComponent* AOwner)
	: TForm(AOwner)
{
}
//Poner la informacion del archivo en la ventana de dialogo 
void __fastcall TKArDataPages::FormShow(TObject *Sender)
{
   	TKArData *KArData= new TKArData();

    KArData->ReadFile(FrameForm->OpenDATDialog->FileName.c_str());
	KArDataPages->EditInputFile->Text= KArData->InFile;
	KArDataPages->EditOutputFile->Text= KArData->OutFile;
    //informacion del Atmos
	KArDataPages->EditAtmosName->Text= KArData->AtmName;
	KArDataPages->EditAtmosDate->Text= KArData->AtmDate;
	KArDataPages->Edit40_36->Text= KArData->atm4036;
	KArDataPages->Edit40_36Sig->Text= KArData->sgatm4036;
    //inf. del Spike
	KArDataPages->EditSpikeName->Text= KArData->SpkName;
	KArDataPages->EditSpikeNo->Text= KArData->spikeno;
	KArDataPages->EditWeight->Text= KArData->peso;
	KArDataPages->Edit36Ar->Text= KArData->az36;
	KArDataPages->Edit38Ar->Text= KArData->az38;
	KArDataPages->Edit40Ar->Text= KArData->az40;
	KArDataPages->EditKAvg->Text= KArData->pot;
	KArDataPages->EditKSig->Text= KArData->sgpot;
	KArDataPages->EditTo->Text= KArData->tcero;
	KArDataPages->EditToSig->Text= KArData->sgtcero;
	KArDataPages->EditDelta->Text= KArData->delta;
	KArDataPages->EditDeltaSig->Text= KArData->sgdelta;
	KArDataPages->Edit40_38->Text= KArData->sp4038;
	KArDataPages->Edit40_38Sig->Text= KArData->sgsp4038;
	KArDataPages->Edit36_38->Text= KArData->sp3638;
	KArDataPages->Edit36_38Sig->Text= KArData->sgsp3638;
    //experiemntos
	KArDataPages->EditBcoName->Text= KArData->BcoNm;
	KArDataPages->EditExpName->Text= KArData->ExpNm;
}
//---------------------------------------------------------------------------
