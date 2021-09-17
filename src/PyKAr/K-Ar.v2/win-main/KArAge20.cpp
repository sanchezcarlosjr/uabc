//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Main.cpp", MainForm);
USERES("KArAge20.res");
USEFORM("KArAgeDlg.cpp", AgeForm);
USEFORM("SpikeDlg.cpp", SpikeForm);
USEFORM("mdiChild.cpp", RichTextForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TMainForm), &MainForm);
    Application->CreateForm(__classid(TAgeForm), &AgeForm);
    Application->CreateForm(__classid(TSpikeForm), &SpikeForm);
    Application->CreateForm(__classid(TRichTextForm), &RichTextForm);
    Application->Run();

	return 0;
}
//---------------------------------------------------------------------------
