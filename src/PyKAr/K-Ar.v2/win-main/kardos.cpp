//---------------------------------------------------------------------------
#include <vcl\condefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma hdrstop
//---------------------------------------------------------------------------
USERES("kardos.res");
USEUNIT("nwSpike.cpp");
USEUNIT("Edad-K-Ar.cpp");
#include "Edad-K-Ar.h"
#define INFILE  "c:\\ms10\\tst.dat"
#define OUTFILE "c:\\ms10\\nwtst.res"
extern void nedad(char *InFile,char *OutFile);
//---------------------------------------------------------------------------
int main(int argc, char **argv)
{
	TKArData *KArData= new TKArData(INFILE, OUTFILE);
	KArData->Age();
	return 0;
}
//---------------------------------------------------------------------------
