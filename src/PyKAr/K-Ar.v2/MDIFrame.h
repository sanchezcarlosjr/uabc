//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1997 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef MDIFrameH
#define MDIFrameH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Menus.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\ComCtrls.hpp>
#include <vcl\Buttons.hpp>
//---------------------------------------------------------------------------
class TFrameForm : public TForm
{
__published:	// IDE-managed Components 
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *New1;
    TMenuItem *Open1;
    TMenuItem *N1;
    TMenuItem *Exit1;
    TMenuItem *Window1;
    TMenuItem *Tile1;
    TMenuItem *Cascade1;
    TMenuItem *Arrangeicons1;
    TOpenDialog *OpenFileDialog;
	TStatusBar *StatusBar1;
	TMenuItem *Age1;
	TMenuItem *Spike1;
	THeaderControl *HeaderControl1;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TMenuItem *KData1;
	TMenuItem *N2;
	TMenuItem *KAvg1;
	TBitBtn *BitBtn3;
	TMenuItem *OpenDAT1;
	TOpenDialog *OpenDATDialog;
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall Tile1Click(TObject *Sender);
    void __fastcall Cascade1Click(TObject *Sender);
    void __fastcall Arrangeicons1Click(TObject *Sender);
    
    
    void __fastcall New1Click(TObject *Sender);
    void __fastcall Open1Click(TObject *Sender);
	void __fastcall Age1Click(TObject *Sender);
	void __fastcall Spike1Click(TObject *Sender);
	
	
	
	void __fastcall KData1Click(TObject *Sender);
	
	void __fastcall OpenDAT1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    virtual __fastcall TFrameForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFrameForm *FrameForm;
//---------------------------------------------------------------------------
#endif
