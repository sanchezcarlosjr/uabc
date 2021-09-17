//---------------------------------------------------------------------------
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <vcl\sysutils.hpp>
#include <vcl\windows.hpp>
#include <vcl\messages.hpp>
#include <vcl\sysutils.hpp>
#include <vcl\classes.hpp>
#include <vcl\graphics.hpp>
#include <vcl\controls.hpp>
#include <vcl\forms.hpp>
#include <vcl\dialogs.hpp>
#include <vcl\stdctrls.hpp>
#include <vcl\buttons.hpp>
#include <vcl\extctrls.hpp>
#include <vcl\menus.hpp>
#include <vcl\ComCtrls.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:   
	TMainMenu *MainMenu;
	TMenuItem *FileNewItem;
	TMenuItem *FileOpenItem;
	TMenuItem *FileSaveItem;
	TMenuItem *FileSaveAsItem;
	TMenuItem *FilePrintItem;
	TMenuItem *FilePrintSetupItem;
	TMenuItem *FileExitItem;
	TMenuItem *WindowTileItem;
	TMenuItem *WindowCascadeItem;
	TMenuItem *WindowArrangeItem;
	TMenuItem *HelpContentsItem;
	TMenuItem *HelpSearchItem;
	TMenuItem *HelpHowToUseItem;
	TMenuItem *HelpAboutItem;
	TStatusBar *StatusLine;
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	TPrintDialog *PrintDialog;
	TPrinterSetupDialog *PrintSetupDialog;
	TPanel *SpeedBar;
	TSpeedButton *SpeedButton1;  // &Open...
	TSpeedButton *SpeedButton2;  // E&xit
	TSpeedButton *SpeedButton3;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ShowHint(TObject *Sender);
	void __fastcall OpenAgeDlg(TObject *Sender);
	
	void __fastcall FileSave(TObject *Sender);
	void __fastcall FileSaveAs(TObject *Sender);
	void __fastcall FilePrint(TObject *Sender);
	void __fastcall FilePrintSetup(TObject *Sender);
	void __fastcall FileExit(TObject *Sender);
	void __fastcall WindowTile(TObject *Sender);
	void __fastcall WindowCascade(TObject *Sender);
	void __fastcall WindowArrange(TObject *Sender);
	void __fastcall HelpContents(TObject *Sender);
	void __fastcall HelpSearch(TObject *Sender);
	void __fastcall HelpHowToUse(TObject *Sender);
	void __fastcall HelpAbout(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
private:        // private user declarations
public:         // public user declarations
	virtual __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
