//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "SpikeDlg.h"
#include "../SPK.c"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TSpikeForm *SpikeForm;
//---------------------------------------------------------------------------
__fastcall TSpikeForm::TSpikeForm(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TSpikeForm::SpeedButton1Click(TObject *Sender)
{
	if (OpenDATDialog->Execute())
	{
		NameDATFile->Text= OpenDATDialog->FileName;
	}
}
//---------------------------------------------------------------------------
void __fastcall TSpikeForm::SpeedButton2Click(TObject *Sender)
{
	if (SaveRESDialog->Execute())
	{
		NameRESFile->Text= SaveRESDialog->FileName;
	}
}

void __fastcall TSpikeForm::Spike(void)
{
	CalcSpike(NameDATFile->Text.c_str(),NameRESFile->Text.c_str());
}

/*{
	if( NameDATFile->Text.Length()==0 )
    {
    	MessageBox(0,"Error opening DAT File","Error: DAT File Error",MB_OK);
        ModalResult= 0;
    }
    else if( NameRESFile->Text.Length()==0 )
	{
    	MessageBox(0,"Error opening RES File","Error: RES File Error",MB_OK);
        ModalResult= 0;
    }
    else
		ModalResult= mrOk;
} */

//Boton OK de la ventana de K-Ar Age
void __fastcall TSpikeForm::BitBtnOKClick(TObject *Sender)
{
	if( access(NameDATFile->Text.c_str(),0) )
    {//el archivo DAT no existe
    	MessageBox(0,"Error opening DAT File","Error: DAT File Error",
        	MB_OK|MB_ICONSTOP);
 		NameDATFile->SetFocus();
        ModalResult= 0;
        return;
    }
	if( NameRESFile->Text.Length()==0 )
    {//Error en el archivo RES
    	MessageBox(0,"Error Creating RES File","Error: RES File Error",
        	MB_OK|MB_ICONSTOP);
 		NameRESFile->SetFocus();
        ModalResult= 0;
        return;
    }
    if( !access(NameRESFile->Text.c_str(),0) )
	{//revisar si el archiv existe y preguntar para sobreescribir
    	char buff[100];
    	sprintf(buff,"File %s Exist, Overwrite?",NameRESFile->Text.c_str());
		if( MessageBox(0,buff,"Overwrite Warning",
         	MB_YESNO|MB_ICONSTOP|MB_DEFBUTTON2)==IDNO )
        {//no sobreescribir el archivo
	 		NameRESFile->SetFocus();
			ModalResult= 0;
            return;
        }
    }
    Spike();
	ModalResult= mrOk;
}
//---------------------------------------------------------------------------

