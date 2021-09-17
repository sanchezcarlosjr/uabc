//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "MDIFrame.h"
#include "KArAgeDlg.h"
#include "karage.c"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TAgeForm *AgeForm;
//---------------------------------------------------------------------------
__fastcall TAgeForm::TAgeForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAgeForm::SpeedButton1Click(TObject *Sender)
{
	if (OpenDATDialog->Execute())
		NameDATFile->Text= OpenDATDialog->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TAgeForm::SpeedButton2Click(TObject *Sender)
{
	if (SaveRESDialog->Execute())
	{
		NameRESFile->Text= SaveRESDialog->FileName;
	}

}

void __fastcall TAgeForm::Age(void)
{
	nedad(NameDATFile->Text.c_str(),NameRESFile->Text.c_str());
}

//Boton OK de la ventana de K-Ar Age
void __fastcall TAgeForm::BitBtnOKClick(TObject *Sender)
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
    Age();
	ModalResult= mrOk;
}
//---------------------------------------------------------------------------

