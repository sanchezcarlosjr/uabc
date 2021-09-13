//----------------------------------------------------------------------------
#ifndef FileOpenDataDlgH
#define FileOpenDataDlgH
//----------------------------------------------------------------------------
#include <vcl\ExtCtrls.hpp>
#include <vcl\ComCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
//----------------------------------------------------------------------------
class TKArDataPages : public TForm
{
__published:
	TPanel *Panel1;
	TPanel *Panel2;
	TPageControl *PageControl1;
	TTabSheet *General;
	TTabSheet *BCO;
	TTabSheet *EXP;
	TButton *OKBtn;
	TButton *CancelBtn;
	TButton *HelpBtn;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *EditInputFile;
	TEdit *EditOutputFile;
	TEdit *EditSpikeName;
	TGroupBox *GroupBox1;
	TLabel *Label5;
	TLabel *Label7;
	TLabel *Label6;
	TLabel *Label3;
	TGroupBox *GroupBox2;
	TLabel *Label4;
	TEdit *EditAtmosName;
	TEdit *Edit40_36;
	TEdit *EditAtmosDate;
	TEdit *Edit40_36Sig;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TEdit *EditSpikeNo;
	TEdit *EditWeight;
	TEdit *Edit36Ar;
	TEdit *Edit38Ar;
	TEdit *Edit40Ar;
	TLabel *Label18;
	TLabel *Label20;
	TEdit *EditBcoName;
	TLabel *Label19;
	TEdit *EditExpName;
	TEdit *EditKAvg;
	TEdit *EditKSig;
	TLabel *Label17;
	TEdit *EditTo;
	TLabel *Label21;
	TEdit *EditToSig;
	TEdit *EditDelta;
	TLabel *Label22;
	TEdit *EditDeltaSig;
	TEdit *Edit40_38;
	TLabel *Label23;
	TEdit *Edit40_38Sig;
	TEdit *Edit36_38;
	TLabel *Label24;
	TEdit *Edit36_38Sig;
	void __fastcall FormShow(TObject *Sender);
private:
public:
	virtual __fastcall TKArDataPages(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern TKArDataPages *KArDataPages;
//----------------------------------------------------------------------------
#endif    
