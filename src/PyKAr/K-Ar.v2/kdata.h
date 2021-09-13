//----------------------------------------------------------------------------
#ifndef kdataH
#define kdataH
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
class TPagesDlg : public TForm
{
__published:
	TPanel *Panel1;
	TPanel *Panel2;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TEdit *EditBlanck;
	TLabel *Label1;
	TLabel *Label3;
	TEdit *EditName;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	TButton *StdGraph;
	TEdit *EditStd00;
	TEdit *EditStd01;
	TEdit *EditStd02;
	TEdit *EditStd03;
	TEdit *EditStd04;
	TEdit *EditStd05;
	TEdit *EditStd06;
	TEdit *EditStd07;
	TEdit *EditStd08;
	TEdit *EditStd09;
	TEdit *EditStd10;
	TEdit *EditStd11;
	TEdit *EditStd12;
	TEdit *EditStd13;
	TEdit *EditStd14;
	TEdit *EditStd15;
	TEdit *EditStd16;
	TEdit *EditStd17;
	TEdit *EditStd18;
	TEdit *EditStd19;
	TListView *SamplesList;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	TBitBtn *BitBtn4;
	TBitBtn *BitBtn5;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall SamplesListDblClick(TObject *Sender);
private:
public:
	virtual __fastcall TPagesDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern TPagesDlg *PagesDlg;
//----------------------------------------------------------------------------
#endif    
