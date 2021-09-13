/*
Definicion de la clase TKArData para calcular la edad por el metodo de K-Ar.
Ing. Jonas de Dios De Basabe Delgado (debasabe@cicese.mx)
6-Dic-1999. Laboratorio de Geocronologia, CICESE.
*/
#ifndef Edad-K-ArH
#define Edad-K-ArH

#include <stdio.h>
#include <math.h>

#define nier 295.5
#define atm3638 5.349
#define at4038 1580.6906
#define n36 0.0003
#define n38 0.0024
#define n40 0.0021

#define NUMMAX 16 //maximo numero de barridos
class TKArData
{
	public:
    char InFile[256], OutFile[256];//archivos de entrada y salida
    char BcoNm[256], ExpNm[256];//nombre del bco y del experimento
    int nb,n;//numero de barridos del bco y exp
    float tb36[NUMMAX],tx36[NUMMAX];//t0 de cada barrido
    float b[12][NUMMAX];//barridos del blanco
    float x[12][NUMMAX];//barridos del experimento
	//datos del spike
    char SpkName[16];
    float sp4038, sgsp4038, sp3638, sgsp3638;
    float az36, az38, az40;
    float tcero, sgtcero, delta, sgdelta;
    float spikeno, peso, pot, sgpot;
    //datos del atmos
    char AtmName[16], AtmDate[24];
    float atm4036, sgatm4036;

    __fastcall TKArData(void);
    __fastcall TKArData(char *, char *);
	__fastcall ReadFile(char *);
    __fastcall Age(void);

    private:
    bool DataOk;
    __fastcall ReadFile(void);
};

extern TKArData *KArData;
#endif
