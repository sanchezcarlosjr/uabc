//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1997 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MDIFrame.cpp", FrameForm);
USERES("TextEdit.res");
USEFORM("MDIEdit.cpp", EditForm);
USEFORM("KArAgeDlg.cpp", AgeForm);
USEFORM("SpikeDlg.cpp", SpikeForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    Application->Initialize();
    Application->Title = "K-Ar";
		Application->CreateForm(__classid(TFrameForm), &FrameForm);
		Application->CreateForm(__classid(TAgeForm), &AgeForm);
		Application->CreateForm(__classid(TSpikeForm), &SpikeForm);
		Application->Run();

    return 0;
}
//---------------------------------------------------------------------------
