//---------------------------------------------------------------------------
#ifndef SpikeDlgH
#define SpikeDlgH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\Dialogs.hpp>
#include <io.h>
//---------------------------------------------------------------------------
class TSpikeForm : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *BitBtnOK;
	TSpeedButton *SpeedButton1;
	TEdit *NameDATFile;
	TGroupBox *GroupBox1;
	TSpeedButton *SpeedButton2;
	TEdit *NameRESFile;
	TGroupBox *GroupBox2;
	TBitBtn *BitBtnCancel;
	TOpenDialog *OpenDATDialog;
	TSaveDialog *SaveRESDialog;
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall Spike(void);
	void __fastcall BitBtnOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSpikeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TSpikeForm *SpikeForm;
//extern void CalcSpike(char *InFile,char *OutFile);
//---------------------------------------------------------------------------
#endif
