//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "nwSpike.h"
//---------------------------------------------------------------------------

float w36, w37, w38, w39, w40, v36, v37, v38, v39, v40;
float y036, y037, y038, y039, y040, a036, a037, a038, a039, a040;
float m36, m37, m38, m39, m40, l36, l37, l38, l39, l40;
float y36, y37, y38, y39, y40, a36, a37, a38, a39, a40;
float x36, x37, x38, x39, x40, b36, b37, b38, b39, b40;
float d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13;
float f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13;
float p36[50], p37[50], p38[50], p39[50], p40[50];
float q36[50], q37[50], q38[50], q39[50], q40[50];
float sig36[50], sig37[50], sig38[50], sig39[50], sig40[50];
float sib36[50], sib37[50], sib38[50], sib39[50], sib40[50];
float t36[50], t37[50], t38[50], t39[50], t40[50];
float z36[50], z37[50], z38[50], z39[50], z40[50];
float blk36, blk37, blk38, blk39, blk40, bco36, bco37, bco38, bco39;
float sgbl36, sgbl37, sgbl38, sgbl39, sgbl40;
float s36 = 0.0, s36c = 0.0, sx36 = 0.0, s37 = 0.0, s37c = 0.0, sx37 = 0.0;
float s38 = 0.0, s38c = 0.0, sx38 = 0.0, s39 = 0.0, s39c = 0.0, sx39 = 0.0;
float s40 = 0.0, s40c = 0.0, sx40 = 0.0, sb36 = 0.0, z36c = 0.0, sz36 = 0.0;
float sb37 = 0.0, z37c = 0.0, sz37 = 0.0, sb38 = 0.0, z38c = 0.0, sz38 = 0.0;
float sb39 = 0.0, z39c = 0.0, sz39 = 0.0, sb40 = 0.0, z40c = 0.0, sz40 = 0.0;
float st36 = 0.0, st36c = 0.0, st37 = 0.0, st37c = 0.0;
float st38 = 0.0, st38c = 0.0, st39 = 0.0, st39c = 0.0;
float st40 = 0.0, st40c = 0.0, ss36 = 0.0, ss36c = 0.0;
float ss37 = 0.0, ss37c = 0.0, ss38 = 0.0, ss38c = 0.0;
float ss39 = 0.0, ss39c = 0.0, ss40 = 0.0, ss40c = 0.0;
float sw36 = 0.0, sw37 = 0.0, sw38 = 0.0, sw39 = 0.0, sw40 = 0.0;
float sv36 = 0.0, sv37 = 0.0, sv38 = 0.0, sv39 = 0.0, sv40 = 0.0;
float sum36 = 0.0, sum37 = 0.0, sum38 = 0.0, sum39 = 0.0, sum40 = 0.0;
float sub36 = 0.0, sub37 = 0.0, sub38 = 0.0, sub39 = 0.0, sub40 = 0.0;
float sgm36 = 0.0, sgm37 = 0.0, sgm38 = 0.0, sgm39 = 0.0, sgm40 = 0.0;
float sbm36 = 0.0, sbm37 = 0.0, sbm38 = 0.0, sbm39 = 0.0, sbm40 = 0.0;
float sgmm36 = 0.0, sgmm37 = 0.0, sgmm38 = 0.0, sgmm39 = 0.0, sgmm40 = 0.0;
float sgl36 = 0.0, sgl37 = 0.0, sgl38 = 0.0, sgl39 = 0.0, sgl40 = 0.0;
float eq6 = 0.0, eq7 = 0.0, eq8 = 0.0, eq9 = 0.0, eq0 = 0.0;
float seq6 = 0.0, seq7 = 0.0, seq8 = 0.0, seq9 = 0.0, seq0 = 0.0;
float eq06 = 0.0, eq08 = 0.0, eq68 = 0.0;
float seq06 = 0.0, seq08 = 0.0, seq68 = 0.0;
float at36 = 0.0, at38 = 0.0, at40 = 0.0;
float sgat36 = 0.0, sgat38 = 0.0, sgat40 = 0.0;
float matm4036 = 0.0, sgmatm = 0.0, sqat40 = 0.0, sqat36 = 0.0;
float matm3638 = 0.0, sgatm = 0.0, sqat38 = 0.0;
float num36 = 0.0, num37 = 0.0, num38 = 0.0, num39 = 0.0, num40 = 0.0, num;
float nub36 = 0.0, nub37 = 0.0, nub38 = 0.0, nub39 = 0.0, nub40 = 0.0;
float denom36, denom37, denom38, denom39, denom40, den36, den37, den38, den39, den40;
float dias;// w36, v36, w37, v37, w38, v38, w39, v39, w40, v40,
float d1;//, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13;
float g1, g2, g3, g4, g5, g6, g7, g8, g9, g10, g11, g12, g13;
float tail1, tail2, K = 0.0;
float peso, m4036, sg4036, jfac, sdjfac, s09, err09, age, di = 0.0, sddi = 0.0, PKFAC = 0.0;
float KFA = 0.0, KFACC = 0.0;
float az36 = 0.0, azz36 = 0.0, ax36 = 0.0;// s36 = 0.0, sx36 = 0.0,
float az38 = 0.0, ax38 = 0.0;// s38 = 0.0, sx38 = 0.0,
float ax39 = 0.0, axx39 = 0.0, ar39k = 0.0;// s39 = 0.0, sx39 = 0.0,
float eqxx6 = 0.0, eqx6 = 0.0;//, eq6 = 0.0, eq7 = 0.0, eq8 = 0.0, eq9 = 0.0, eq0 = 0.0;
float b036, b037, b038, b039;
float ab36 = 0.0, ab37 = 0.0, ab38 = 0.0, ab39 = 0.0, ab40 = 0.0;
float sgab37 = 0.0, sgab38 = 0.0, sgab39 = 0.0, sgab40 = 0.0;//sgab36 = 0.0,
float ar36 = 0.0, ar37 = 0.0, ar38 = 0.0, ar39 = 0.0, ar40 = 0.0;
float sd36 = 0.0, sd37 = 0.0, sd38 = 0.0, sd39 = 0.0, sd40 = 0.0;
float  r09 = 0.0, r69 = 0.0, r97 = 0.0, r96 = 0.0, r06 = 0.0;
float c39 = 0.0, r09k = 0.0, e09k = 0.0, atm40 = 0.0, rad40 = 0.0;
float ca37k39 = 0.0;//r79 = 0.0,,c37 = 0.0,  cak = 0.0;
float f1 = 0.0;//, f2 = 0.0, f3 = 0.0, f4 = 0.0, f5 = 0.0;
float f14 = 0.0, f15 = 0.0;// f11 = 0.0, f12 = 0.0, f13 = 0.0,
float f16 = 0.0, f17 = 0.0, f18 = 0.0, f19 = 0.0, f20 = 0.0, KFAC[10], CaFAC[10];
float jota[10], sdjota[10], wjo = 0.0, sdwjo= 0.0, wjota = 0.0, sdwjota = 0.0;
float inl36 = 0.0, inl37 = 0.0, inl38 = 0.0, inl39 = 0.0, inl40 = 0.0;
char name [100], *c1, namer[100], *c2, nomb1[100], nomb2[100], nomb3[100];
char atlab[16], date[30];

void InitStdAtm(void);
void CalcSpike(char *InFile,char *OutFile);
float sqr ( float a);

/*
#define INFILE  "c:\\ms10\\tst.dat"
#define OUTFILE "c:\\ms10\\tst.res"
int main(void)
{
	CalcSpike(INFILE,OUTFILE);
	return 0;
}
/**/

void InitStdAtm(void)
{
	s36 = 0.0;
	s36c = 0.0;
	sx36 = 0.0;
	s37 = 0.0;
	s37c = 0.0;
	sx37 = 0.0;
	s38 = 0.0;
	s38c = 0.0;
	sx38 = 0.0;
	s39 = 0.0;
	s39c = 0.0;
	sx39 = 0.0;
	s40 = 0.0;
	s40c = 0.0;
	sx40 = 0.0;
	sb36 = 0.0;
	z36c = 0.0;
	sz36 = 0.0;
	sb37 = 0.0;
	z37c = 0.0;
	sz37 = 0.0;
	sb38 = 0.0;
	z38c = 0.0;
	sz38 = 0.0;
	sb39 = 0.0;
	z39c = 0.0;
	sz39 = 0.0;
	sb40 = 0.0;
	z40c = 0.0;
	sz40 = 0.0;
	st36 = 0.0;
	st36c = 0.0;
	st37 = 0.0;
	st37c = 0.0;
	st38 = 0.0;
	st38c = 0.0;
	st39 = 0.0;
	st39c = 0.0;
	st40 = 0.0;
	st40c = 0.0;
	ss36 = 0.0;
	ss36c = 0.0;
	ss37 = 0.0;
	ss37c = 0.0;
	ss38 = 0.0;
	ss38c = 0.0;
	ss39 = 0.0;
	ss39c = 0.0;
	ss40 = 0.0;
	ss40c = 0.0;
	sw36 = 0.0;
	sw37 = 0.0;
	sw38 = 0.0;
	sw39 = 0.0;
	sw40 = 0.0;
	sv36 = 0.0;
	sv37 = 0.0;
	sv38 = 0.0;
	sv39 = 0.0;
	sv40 = 0.0;
	sum36 = 0.0;
	sum37 = 0.0;
	sum38 = 0.0;
	sum39 = 0.0;
	sum40 = 0.0;
	sub36 = 0.0;
	sub37 = 0.0;
	sub38 = 0.0;
	sub39 = 0.0;
	sub40 = 0.0;
	sgm36 = 0.0;
	sgm37 = 0.0;
	sgm38 = 0.0;
	sgm39 = 0.0;
	sgm40 = 0.0;
	sbm36 = 0.0;
	sbm37 = 0.0;
	sbm38 = 0.0;
	sbm39 = 0.0;
	sbm40 = 0.0;
	sgmm36 = 0.0;
	sgmm37 = 0.0;
	sgmm38 = 0.0;
	sgmm39 = 0.0;
	sgmm40 = 0.0;
	sgl36 = 0.0;
	sgl37 = 0.0;
	sgl38 = 0.0;
	sgl39 = 0.0;
	sgl40 = 0.0;
	eq6 = 0.0;
	eq7 = 0.0;
	eq8 = 0.0;
	eq9 = 0.0;
	eq0 = 0.0;
	seq6 = 0.0;
	seq7 = 0.0;
	seq8 = 0.0;
	seq9 = 0.0;
	seq0 = 0.0;
	eq06 = 0.0;
	eq08 = 0.0;
	eq68 = 0.0;
	seq06 = 0.0;
	seq08 = 0.0;
	seq68 = 0.0;
	at36 = 0.0;
	at38 = 0.0;
	at40 = 0.0;
	sgat36 = 0.0;
	sgat38 = 0.0;
	sgat40 = 0.0;
	matm4036 = 0.0;
	sgmatm = 0.0;
	sqat40 = 0.0;
	sqat36 = 0.0;
	matm3638 = 0.0;
	sgatm = 0.0;
	sqat38 = 0.0;
	num36 = 0.0;
	num37 = 0.0;
	num38 = 0.0;
	num39 = 0.0;
	num40 = 0.0;
	nub36 = 0.0;
	nub37 = 0.0;
	nub38 = 0.0;
	nub39 = 0.0;
	nub40 = 0.0;
}

//-----------------------------------------------------------------------------------
void CalcSpike(char *InFile,char *OutFile)
{
	float sqar38 = 0.0, sqar40 = 0.0, sqar36 = 0.0;
	float sp4038 = 0.0, sgsp4038 = 0.0, sp3638 = 0.0, sgsp3638 = 0.0;
	float sgar36 = 0.0, sgar38 = 0.0, sgar40 = 0.0;
	float dem36 = 0.0, dem37 = 0.0,dem38 = 0.0, dem39 = 0.0, dem40 = 0.0;
	float den36 = 0.0, den37 = 0.0, den38 = 0.0, den39 = 0.0, den40 = 0.0;
	float dis36 = 0.0, discr36 = 0.0, dis38 = 0.0, discr38 = 0.0;
	float sgab36 = 0.0, sgab37 = 0.0, sgab38 = 0.0, sgab39 = 0.0, sgab40 = 0.0;
	char nomb1 [100], nomb2 [100];
//    char buff[256];
	int i, numero, inl;
	FILE *in, *out;

	in = fopen(InFile, "r");
	out = fopen (OutFile, "w");
	InitStdAtm();

	fscanf (in, "%[^\n]", nomb1);
	fprintf(out,"%s\n", nomb1);
	fprintf(out,"\n");
	fscanf (in, "%d", &inl);
/* lee el numero de barridos en el inlet */
		sv36 = 0.0;
		sv37 = 0.0;
		sv38 = 0.0;
		sv39 = 0.0;
		sv40 = 0.0;
		ss36 = 0.0;
		ss37 = 0.0;
		ss38 = 0.0;
		ss39 = 0.0;
		ss40 = 0.0;
		ss36c = 0.0;
		ss37c = 0.0;
		ss38c = 0.0;
		ss39c = 0.0;
		ss40c = 0.0;
		sb36 = 0.0;
		sb37 = 0.0;
		sb38 = 0.0;
		sb39 = 0.0;
		sb40 = 0.0;
		sz36 = 0.0;
		sz37 = 0.0;
		sz38 = 0.0;
		sz39 = 0.0;
		sz40 = 0.0;
fprintf(out, " 36\t 37\t 38\t 39\t 40\n");
	for (i = 0; i<inl; i++){
/* empieza el lazo del inlet */
		fscanf(in, "%f%f%f%f%f%f%f%f%f%f%f%f\n",
        	&b36, &g2, &g3, &g4, &g5, &g6, &g7, &g8, &g9, &g10, &g11, &g12);
//        fgets(buff,sizeof buff,in);
//		sscanf(buff, "%f%f%f%f%f%f%f%f%f%f%f%f",
//        	&b36, &g2, &g3, &g4, &g5, &g6, &g7, &g8, &g9, &g10, &g11, &g12);		a36 = g3 - (g2 + g4) / 2.0;
		a37 = g5 - (g4 + g6) / 2.0;
		a38 = g7 - (g6 + g8) / 2.0;
		a39 = g9 - g8;
		a40 = g11 - (g10 + g12) / 2.0;
fprintf(out, "%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n", a36, a37, a38, a39, a40);
		q36[i] = a36;
		q37[i] = a37;
		q38[i] = a38;
		q39[i] = a39;
		q40[i] = a40;
		sib36[i] = ((0.0012 * a36)*(0.0012 * a36) + (n36 * n36));
		sib37[i] = ((0.0012 * a37)*(0.0012 * a37) + (n37 * n37));
		sib38[i] = ((0.0012 * a38)*(0.0012 * a38) + (n38 * n38));
		sib39[i] = ((0.0012 * a39)*(0.0012 * a39) + (n39 * n39));
		sib40[i] = ((0.0012 * a40)*(0.0012 * a40) + (n40 * n40));
		v36 = 1.0 / sib36[i];
		v37 = 1.0 / sib37[i];
		v38 = 1.0 / sib38[i];
		v39 = 1.0 / sib39[i];
		v40 = 1.0 / sib40[i];
		b36 = b36 + 20;
		b37 = b36 + 60;
		b38 = b36 + 100;
		b39 = b36 + 140;
		b40 = b36 + 180;
		z36[i] = b36;
		z37[i] = b37;
		z38[i] = b38;
		z39[i] = b39;
		z40[i] = b40;
		sv36 += v36;
		sv37 += v37;
		sv38 += v38;
		sv39 += v39;
		sv40 += v40;
		ss36 += (v36 * b36);
		ss37 += (v37 * b37);
		ss38 += (v38 * b38);
		ss39 += (v39 * b39);
		ss40 += (v40 * b40);
		ss36c += (v36 * b36 * b36);
		ss37c += (v37 * b37 * b37);
		ss38c += (v38 * b38 * b38);
		ss39c += (v39 * b39 * b39);
		ss40c += (v40 * b40 * b40);
		sb36 += (v36 * a36);
		sb37 += (v37 * a37);
		sb38 += (v38 * a38);
		sb39 += (v39 * a39);
		sb40 += (v40 * a40);
		sz36 += (v36 * b36 * a36);
		sz37 += (v37 * b37 * a37);
		sz38 += (v38 * b38 * a38);
		sz39 += (v39 * b39 * a39);
		sz40 += (v40 * b40 * a40);
	}
	den36 = sv36 * ss36c - ss36 * ss36;
	den37 = sv37 * ss37c - ss37 * ss37;
	den38 = sv38 * ss38c - ss38 * ss38;
	den39 = sv39 * ss39c - ss39 * ss39;
	den40 = sv40 * ss40c - ss40 * ss40;
	a036 = (sb36 * ss36c - ss36 * sz36) / den36;
	a037 = (sb37 * ss37c - ss37 * sz37) / den37;
	a038 = (sb38 * ss38c - ss38 * sz38) / den38;
	a039 = (sb39 * ss39c - ss39 * sz39) / den39;
	a040 = (sb40 * ss40c - ss40 * sz40) / den40;
	l36 = (sv36 * sz36 - sb36 * ss36) / den36;
	l37 = (sv37 * sz37 - sb37 * ss37) / den37;
	l38 = (sv38 * sz38 - sb38 * ss38) / den38;
	l39 = (sv39 * sz39 - sb39 * ss39) / den39;
	l40 = (sv40 * sz40 - sb40 * ss40) / den40;
		sub36 = 0.0;
		sub37 = 0.0;
		sub38 = 0.0;
		sub39 = 0.0;
		sub40 = 0.0;

	for(i=0; i<inl; i++)
    {// termina de calcular el ajuste de la recta de inlet
		inl36 = q36[i] - a036 - l36 * z36[i];
		inl37 = q37[i] - a037 - l37 * z37[i];
		inl38 = q38[i] - a038 - l38 * z38[i];
		inl39 = q39[i] - a039 - l39 * z39[i];
		inl40 = q40[i] - a040 - l40 * z40[i];
		sub36 += (inl36 * inl36 / sib36[i]);
		sub37 += (inl37 * inl37 / sib37[i]);
		sub38 += (inl38 * inl38 / sib38[i]);
		sub39 += (inl39 * inl39 / sib39[i]);
		sub40 += (inl40 * inl40 / sib40[i]);
	// termina el lazo del inlet 
	}
		sbm36 = sqrt (( ss36c / den36 ) * ( sub36 / (inl - 2 )));
		sbm37 = sqrt (( ss37c / den37 ) * ( sub37 / (inl - 2 )));
		sbm38 = sqrt (( ss38c / den38 ) * ( sub38 / (inl - 2 )));
		sbm39 = sqrt (( ss39c / den39 ) * ( sub39 / (inl - 2 )));
		sbm40 = sqrt (( ss40c / den40 ) * ( sub40 / (inl - 2)));
		sgl36 = sqrt (( sv36 / den36 ) * ( sub36 / (inl - 2)));
		sgl37 = sqrt (( sv37 / den37 ) * ( sub37 / (inl - 2)));
		sgl38 = sqrt (( sv38 / den38 ) * ( sub38 / (inl - 2)));
		sgl39 = sqrt (( sv39 / den39 ) * ( sub39 / (inl - 2)));
		sgl40 = sqrt (( sv40 / den40 ) * ( sub40 / (inl - 2)));
fprintf(out,"\n");
fprintf(out,"S36 %.2f S37 %.2f S38 %.2f S39 %.2f S40 %.2f\n", sub36, sub37, sub38, sub39, sub40);
fprintf(out,"m36 %f m37 %f m38 %f m39 %f m40 %f\n", l36, l37, l38, l39, l40);
fprintf(out,"err %f err %f err %f err %f err %f\n", sgl36, sgl37, sgl38, sgl39, sgl40);

/* calculo de picos al tiempo de equilibrio */
	blk40 = l40 * 600.0 + a040;
	sgbl40 = sqrt( 360000.0 * sgl40 * sgl40 + sbm40 * sbm40);
	b036 = l36 * 600.0 + a036 ;
	b037 = l37 * 600.0 + a037 ;
	b038 = l38 * 600.0 + a038 ;
	b039 = l39 * 600.0 + a039 ;
fprintf(out,"\n");
fprintf(out,"eq36 %f eq37 %f eq38 %f eq39 %f eq40 %f\n", b036, b037, b038, b039, blk40);
	sgbl36 = sqrt( 360000.0 * sgl36 * sgl36 + sbm36 * sbm36);
	sgbl37 = sqrt( 360000.0 * sgl37 * sgl37 + sbm37 * sbm37);
	sgbl38 = sqrt( 360000.0 * sgl38 * sgl38 + sbm38 * sbm38);
	sgbl39 = sqrt( 360000.0 * sgl39 * sgl39 + sbm39 * sbm39);
	blk36 = (b036 < 0.0) ? 0.00001 : b036;
	blk37 = (b037 < 0.0) ? 0.00001 : b037;
	blk38 = (b038 < 0.0) ? 0.00001 : b038;
	blk39 = (b039 < 0.0) ? 0.00001 : b039;
fprintf(out,"\n");
fprintf(out,"blk36 %f blk37 %f blk38 %f blk39 %f blk40 %f ----40/36 = %.1f\n",
	blk36, blk37, blk38, blk39, blk40, blk40/blk36);
fprintf(out,"err36 %f err37 %f err38 %f err39 %f err40 %f\n", sgbl36, sgbl37, sgbl38, sgbl39, sgbl40);
fprintf(out,"\n");
	fprintf(out,"\n");
	fscanf (in, "%[^\n]", nomb2);
	fscanf (in, "%d", &numero);
	fprintf(out,"%s\n", nomb2);
/* numero es el numero de barridos en cada fraccion */
		sw36 = 0.0;
		sw37 = 0.0;
		sw38 = 0.0;
		sw39 = 0.0;
		sw40 = 0.0;
		st36 = 0.0;
		st37 = 0.0;
		st38 = 0.0;
		st39 = 0.0;
		st40 = 0.0;
		st36c = 0.0;
		st37c = 0.0;
		st38c = 0.0;
		st39c = 0.0;
		st40c = 0.0;
		s36 = 0.0;
		s37 = 0.0;
		s38 = 0.0;
		s39 = 0.0;
		s40 = 0.0;
		sx36 = 0.0;
		sx37 = 0.0;
		sx38 = 0.0;
		sx39 = 0.0;
		sx40 = 0.0;
fprintf(out, " 36\t 37\t 38\t 39\t 40\n");
	  for (i = 0; i<numero; i++){
/* aqui empieza a calcular los picos de cada fraccion */
		fscanf(in, "%f%f%f%f%f%f%f%f%f%f%f%f",
        &x36, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11, &d12);
//        fgets(buff,sizeof buff,in);
//		sscanf(buff, "%f%f%f%f%f%f%f%f%f%f%f%f",
//        	&x36, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11, &d12);
		y36 = d3 -d2;
		y37 = d5 - (d4 + d6) / 2.0;
		y38 = d7 - (d6 + d8) / 2.0;
		y39 = d9 -d8;
		y40 = d11 - d2;
		p36[i] = y36;
		p37[i] = y37;
		p38[i] = y38;
		p39[i] = y39;
		p40[i] = y40;
fprintf(out, "%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n", y36, y37, y38, y39, y40);
		sig36[i] = ((0.0012 * y36)*(0.0012 * y36) + (n36 * n36));
		sig37[i] = ((0.0012 * y37)*(0.0012 * y37) + (n37 * n37));
		sig38[i] = ((0.0012 * y38)*(0.0012 * y38) + (n38 * n38));
		sig39[i] = ((0.0012 * y39)*(0.0012 * y39) + (n39 * n39));
		sig40[i] = ((0.0012 * y40)*(0.0012 * y40) + (n40 * n40));
		w36 = 1.0 / sig36[i];
		w37 = 1.0 / sig37[i];
		w38 = 1.0 / sig38[i];
		w39 = 1.0 / sig39[i];
		w40 = 1.0 / sig40[i];
		x36 = x36 + 20;
		x37 = x36 + 60;
		x38 = x36 + 100;
		x39 = x36 + 140;
		x40 = x36 + 180;
		t36[i] = x36;
		t37[i] = x37;
		t38[i] = x38;
		t39[i] = x39;
		t40[i] = x40;
		sw36 += w36;
		sw37 += w37;
		sw38 += w38;
		sw39 += w39;
		sw40 += w40;
		st36 += (w36 * x36);
		st37 += (w37 * x37);
		st38 += (w38 * x38);
		st39 += (w39 * x39);
		st40 += (w40 * x40);
		st36c += (w36 * x36 * x36);
		st37c += (w37 * x37 * x37);
		st38c += (w38 * x38 * x38);
		st39c += (w39 * x39 * x39);
		st40c += (w40 * x40 * x40);
		s36 += (w36 * y36);
		s37 += (w37 * y37);
		s38 += (w38 * y38);
		s39 += (w39 * y39);
		s40 += (w40 * y40);
		sx36 += (w36 * x36 * y36);
		sx37 += (w37 * x37 * y37);
		sx38 += (w38 * x38 * y38);
		sx39 += (w39 * x39 * y39);
		sx40 += (w40 * x40 * y40);
/* aqui termina el primer grupo de calculos con los datos de la fraccion */

	}
	dem36 = sw36 * st36c - st36 * st36;
	dem37 = sw37 * st37c - st37 * st37;
	dem38 = sw38 * st38c - st38 * st38;
	dem39 = sw39 * st39c - st39 * st39;
	dem40 = sw40 * st40c - st40 * st40;
	y036 = (s36 * st36c - st36 * sx36) / dem36;
	y037 = (s37 * st37c - st37 * sx37) / dem37;
	y038 = (s38 * st38c - st38 * sx38) / dem38;
	y039 = (s39 * st39c - st39 * sx39) / dem39;
	y040 = (s40 * st40c - st40 * sx40) / dem40;
	m36 = (sw36 * sx36 - s36 * st36) / dem36;
	m37 = (sw37 * sx37 - s37 * st37) / dem37;
	m38 = (sw38 * sx38 - s38 * st38) / dem38;
	m39 = (sw39 * sx39 - s39 * st39) / dem39;
	m40 = (sw40 * sx40 - s40 * st40) / dem40;
	sum36 = 0.0;
	sum37 = 0.0;
	sum38 = 0.0;
	sum39 = 0.0;
	sum40 = 0.0;
	for(i=0; i<numero; i++){
/* necesita terminar el calculo del ajuste por minimos cuadrados */
		num36 = p36[i] - y036 - m36 * t36[i];
		num37 = p37[i] - y037 - m37 * t37[i];
		num38 = p38[i] - y038 - m38 * t38[i];
		num39 = p39[i] - y039 - m39 * t39[i];
		num40 = p40[i] - y040 - m40 * t40[i];
		sum36 += (num36 * num36 / sig36[i]);
		sum37 += (num37 * num37 / sig37[i]);
		sum38 += (num38 * num38 / sig38[i]);
		sum39 += (num39 * num39 / sig39[i]);
		sum40 += (num40 * num40 / sig40[i]);
/* termina el lazo de los barridos de la fraccion */
}
		sgm36 = sqrt (( st36c / dem36 ) * ( sum36 / (numero - 2 )));
		sgm37 = sqrt (( st37c / dem37 ) * ( sum37 / (numero - 2 )));
		sgm38 = sqrt (( st38c / dem38 ) * ( sum38 / (numero - 2 )));
		sgm39 = sqrt (( st39c / dem39 ) * ( sum39 / (numero - 2 )));
		sgm40 = sqrt (( st40c / dem40 ) * ( sum40 / (numero - 2 )));
		sgmm36 = sqrt (( sw36 / dem36 ) * ( sum36 / (numero - 2 )));
		sgmm37 = sqrt (( sw37 / dem37 ) * ( sum37 / (numero - 2 )));
		sgmm38 = sqrt (( sw38 / dem38 ) * ( sum38 / (numero - 2 )));
		sgmm39 = sqrt (( sw39 / dem39 ) * ( sum39 / (numero - 2 )));
		sgmm40 = sqrt (( sw40 / dem40 ) * ( sum40 / (numero - 2 )));
/* imprime los datos de la recta para cada fraccion */
fprintf(out,"\n");
fprintf(out,"S36 %.2f S37 %.2f S38 %.2f S39 %.2f S40 %.2f\n", sum36, sum37, sum38, sum39, sum40);
fprintf(out,"m36 %f m37 %f m38 %f m39 %f m40 %f\n", m36, m37, m38, m39, m40);
fprintf(out,"err %f err %f err %f err %f err %f\n", sgmm36, sgmm37, sgmm38, sgmm39, sgmm40);
fprintf(out,"\n");
fprintf(out,"y036 %f y037 %f y038 %f y039 %f y040 %f\n", y036, y037, y038, y039, y040);

	eq7 = m37 * 600.0 + y037;
	eq6 = m36 * 600.0 + y036;
	eq8 = m38 * 600.0 + y038;
	eq0 = m40 * 600.0 + y040;
	eq9 = m39 * 600.0 + y039;

	seq7 = sqrt( 360000.0 * sgmm37 * sgmm37 + sgm37 * sgm37);
	seq6 = sqrt( 360000.0 * sgmm36 * sgmm36 + sgm36 * sgm36);
	seq8 = sqrt( 360000.0 * sgmm38 * sgmm38 + sgm38 * sgm38);
	seq0 = sqrt( 360000.0 * sgmm40 * sgmm40 + sgm40 * sgm40);
	seq9 = sqrt( 360000.0 * sgmm39 * sgmm39 + sgm39 * sgm39);

fprintf(out,"\n");
  fprintf(out,"Datos calculados al tiempo de equilibrio y su error\n");
  fprintf(out,"36  %f 37  %f 38  %f 39  %f 40  %f\n", eq6, eq7, eq8, eq9, eq0);
  fprintf(out,"err %f err %f err %f err %f err %f\n", seq6, seq7, seq8, seq9, seq0);
/* correccion por blanco linea */
	  ab36 = ((eq6 - blk36) < 0.0) ? 0.00001 : (eq6 -blk36);
	  ab37 = ((eq7 - blk37) < 0.0) ? 0.00001 : (eq7 -blk37);
	  ab38 = ((eq8 - blk38) < 0.0) ? 0.00001 : (eq8 -blk38);
	  ab39 = ((eq9 - blk39) < 0.0) ? 0.00001 : (eq9 -blk39);
	  ab40 = ((eq0 - blk40) < 0.0) ? 0.00001 : (eq0 -blk40);
	  sgab36 = sqrt (sqr( sgbl36 ) + sqr( seq6 ));
	  sgab37 = sqrt (sqr( sgbl37 ) + sqr( seq7 ));
	  sgab38 = sqrt (sqr( sgbl38 ) + sqr( seq8 ));
	  sgab39 = sqrt (sqr( sgbl39 ) + sqr( seq9 ));
	  sgab40 = sqrt (sqr( sgbl40 ) + sqr( seq0 ));

fprintf(out,"\n");
  fprintf(out,"Picos corregidos por blanco\n");
  fprintf(out,"36Ar %f 37Ar %f 38Ar %f 39Ar %f 40Ar %f\n", ab36, ab37, ab38, ab39, ab40);
  fprintf(out,"er36 %f er37 %f er38 %f er39 %f er40 %f\n", sgab36, sgab37, sgab38, sgab39, sgab40);

fscanf(in, "%s%s", &atlab, &date);
fscanf(in, "%f%f", &m4036, &sg4036);
	di = ( 0.250 ) * ( nier / m4036 - 1.0 );
	sddi = ( nier * sg4036 ) / (4.0 * m4036 * m4036 );

	  dis36 = 1.000 + (4.000 * di);
	  dis38 = 1.000 + (2.000 * di);
	  ar36 = ab36 / ( dis36 );
	  discr36 = (4 * ab36 * sddi) / (dis36 * dis36);
	  sgar36 = sqrt ((sgab36 / dis36) * (sgab36 / dis36) + (discr36 * discr36));
	  ar38 = ab38 / (dis38);
	  discr38 = (2 * ab38 * sddi) / (dis38 * dis38);
	  sgar38 = sqrt ((sgab38 / dis38) * (sgab38 / dis38) + (discr38 * discr38));
	  ar40 = ab40;
	  sgar40 = sgab40;
fprintf(out,"\n");
fprintf(out,"Masa 36 %f Masa 38 %f Masa 40 %f\n", ar36, ar38, ar40);
fprintf(out,"error36 %f error38 %f error40 %f\n", sgar36, sgar38, sgar40);
	  sqar36 = (sgar36 / ar36) * (sgar36 / ar36);
	  sqar38 = (sgar38 / ar38) * (sgar38 / ar38);
	  sqar40 = (sgar40 / ar40) * (sqar40 / ar40);
	  sp4038 = (ar40 / ar38);
	  sgsp4038 = sp4038 * ( sqrt (sqar40 + sqar38));
	  sp3638 = (ar36 / ar38);
	  sgsp3638 = sp3638 * ( sqrt (sqar36 + sqar38));
fprintf(out,"\n");
fprintf(out, "40/38sp  %f    1 sigma  %f\n", sp4038, sgsp4038);
fprintf(out, "36/38sp  %f    1 sigma  %f\n", sp3638, sgsp3638);
fprintf(out,"\n");
fprintf(out,"Atmos\t fecha\t\t 40/36atm\t +/-\n");
fprintf(out,"%s\t %s\t %.1f\t\t %.1f\n", atlab, date, m4036, sg4036);
	fclose(in);
	fclose(out);
}

float sqr( float a )
{
	return (a*a);
}
