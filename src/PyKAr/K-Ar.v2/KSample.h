//---------------------------------------------------------------------------
#ifndef KSampleH
#define KSampleH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Buttons.hpp>
//---------------------------------------------------------------------------
class TSampleDlg : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TButton *AntBttn;
	TButton *SigBttn;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *EditNoLab;
	TEdit *EditSample;
	TEdit *EditMineral;
	TEdit *EditDate;
	TEdit *EditLecture;
	TEdit *EditDil;
	TEdit *EditWeight;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TCheckBox *Exclude;
private:	// User declarations
public:		// User declarations
	__fastcall TSampleDlg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TSampleDlg *SampleDlg;
//---------------------------------------------------------------------------
#endif
