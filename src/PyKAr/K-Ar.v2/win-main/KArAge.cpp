//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1997 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MDIFrame.cpp", FrameForm);
USERES("KArAge.res");
USEFORM("MDIEdit.cpp", EditForm);
USEFORM("KArAgeDlg.cpp", AgeForm);
USEFORM("SpikeDlg.cpp", SpikeForm);
USEFORM("kdata.cpp", PagesDlg);
USEFORM("KSample.cpp", SampleDlg);
USEUNIT("Edad-K-Ar.cpp");
USEFORM("FileOpenDataDlg.cpp", KArDataPages);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application->Initialize();
    Application->Title = "K-Ar";
		Application->CreateForm(__classid(TFrameForm), &FrameForm);
		Application->CreateForm(__classid(TAgeForm), &AgeForm);
		Application->CreateForm(__classid(TSpikeForm), &SpikeForm);
		Application->CreateForm(__classid(TPagesDlg), &PagesDlg);
		Application->CreateForm(__classid(TSampleDlg), &SampleDlg);
		Application->CreateForm(__classid(TKArDataPages), &KArDataPages);
		Application->Run();

    return 0;
}
//---------------------------------------------------------------------------
