//rutina nedad() para calcular la edad por el metodo de K-Ar
//adaptada del programa nedad.c, realizado por la Dra. M. Lopez
//Jonas De Basabe. Laboratorio de Geocronologia, CICESE.

#include <stdio.h>
#include <math.h>

/*
#define INFILE  "c:\\ms10\\af-51-1.dat"
#define OUTFILE "c:\\ms10\\af-51-1.res"
void nedad(char *InFile,char *OutFile);

int main(void)
{
	nedad(INFILE,OUTFILE);
	return 0;
}
/**/

void nedad(char *InFile,char *OutFile)
{
float nier = 295.5, atm3638 = 5.349, at4038 = 1580.6906;
/* Rutina de ajuste por minimos cuadrados de los picos usando York fit */
float denom36, denom38, denom40, den36, den38, den40;
float w36, v36, w38, v38, w40, v40, lamb = 0.0;
/* peso de cada pico inverso de sigma del pico al cuadrado */
float n36 = 0.0003, n38 = 0.0024, n40 = 0.0021;
/*   error asignado por pico */
float s36 = 0.0, sx36 = 0.0;// s36c = 0.0,
float s38 = 0.0, sx38 = 0.0;// s38c = 0.0,
float s40 = 0.0, sx40 = 0.0;// s40c = 0.0,
float sb36 = 0.0, sz36 = 0.0;// z36c = 0.0,
float sb38 = 0.0, sz38 = 0.0;// z38c = 0.0,
float sb40 = 0.0, sz40 = 0.0;//, z40c = 0.0
/* s es la suma de wy para cada pico */
float st36 = 0.0, st36c = 0.0;
float st38 = 0.0, st38c = 0.0;
float st40 = 0.0, st40c = 0.0;
float ss36 = 0.0, ss36c = 0.0;
float ss38 = 0.0, ss38c = 0.0;
float ss40 = 0.0, ss40c = 0.0;
/* st es la suma de wx para cada pico */
float y036, y038, y040, a036, a038, a040;
/* y0 intercepcion al origen de los picos */
float m36, m38, m40, l36, l38,l40;
/* pendiente de la recta */
float y36, y38, y40, a36, a38, a40;
/* intensidades individuales de los picos */
float x36, x38, x40, b36, b38, b40;
/* las abcisas representan el tiempo para cada pico */
float d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13;
float f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13;
/* datos originales del barrido */
float p36[50], p38[50], p40[50];
float q36[50], q38[50], q40[50];
/* picos calculados */
float sig36[50], sig38[50], sig40[50];
float sib36[50], sib38[50], sib40[50];
/* error asignado a cada pico */
float sw36 = 0.0, sw38 = 0.0, sw40 = 0.0;
float sv36 = 0.0, sv38 = 0.0, sv40 = 0.0;
/* sw, sv es la suma de w y de v */
float t36[50], t38[50], t40[50];
float z36[50], z38[50], z40[50];
/* tiempos para cada pico */
float sum36 = 0.0, sum38 = 0.0, sum40 = 0.0;
float sub36 = 0.0, sub38 = 0.0, sub40 = 0.0;
/* sum es el factor SumS de York */
float sgm36 = 0.0, sgm38 = 0.0, sgm40 = 0.0;
float sbm36 = 0.0, sbm38 = 0.0, sbm40 = 0.0;
/* sgm error calculado para y0 */
float sgmm36 = 0.0, sgmm38 = 0.0, sgmm40 = 0.0;
float sgl36 = 0.0, sgl38 = 0.0, sgl40 = 0.0;
/* sgmm error calculado para la pendiente */
//float sqr36 = 0.0, sqr40 = 0.0, sqr38 = 0.0;
//float spr36 = 0.0, spr40 = 0.0, spr38 = 0.0;
/* sqr suma del error entre pico al cuadrado */
float eq6 = 0.0, eq8 = 0.0, eq0 = 0.0, seq6 = 0.0, seq8 = 0.0, seq0 = 0.0;
float eq06 = 0.0, eq08 = 0.0, eq68 = 0.0;
float seq06 = 0.0, seq08 = 0.0, seq68 = 0.0;
/* datos para calcular los picos al tiempo de equilibrio */
float matm4036 = 0.0, sgmatm = 0.0;
/* matm4036 es atmos 40/36 medido sgmatm es error en 4036 */
float blk36, bco36, blk38, bco38, blk40, sgbl36, sgbl38, sgbl40;
/* datos blanco y error en blanco */
float ab36 = 0.0, ab38 = 0.0, ab40 = 0.0;
float sgab36 = 0.0, sgab38 = 0.0, sgab40 = 0.0;
/* picos corregidos por blanco */
float ar36 = 0.0, ar38 = 0.0, ar40 = 0.0, ax36 = 0.0, ax40 = 0.0;
float sgar36 = 0.0, sgar38 = 0.0, sgar40 = 0.0, az36 = 0.0, az38 = 0.0, az40 = 0.0;
/* picos corregidos por discriminacion y su error */
float sqar36 = 0.0, sqar38 = 0.0, sqar40 = 0.0;
/* cuadrado del cociente error entre pico */
float discr = 0.0, sgdiscr = 0.0;
/* discr es el factor de discriminacion y sgdiscr su error */
float dis36 = 0.0, discr36 = 0.0, dis38 = 0.0, discr38 = 0.0;
/* valores intermedios para el calculo de discrim y su error */
float m4038 = 0.0, sgm4038 = 0.0, m3836 = 0.0, sgm3836 = 0.0;// sgm3638 = 0.0;
/* cocientes medidos en la muestra y su error */
float sp4038, sgsp4038, sp3638, sgsp3638;
float tcero, sgtcero, delta, sgdelta, esp = 0.0;
float sp38 = 0.0, sgsp38 = 0.0, sqs38 = 0.0, sqsp38 = 0.0, spikeno = 0.0;
float fa1 = 0.0, sgfa1 = 0.0, fa1a = 0.0, fa1b = 0.0, sqfa1 = 0.0;
float fa2 = 0.0, sgfa2 = 0.0, sqfa2 = 0.0, fa3 = 0.0, sgfa3 = 0.0, sqfa3 = 0.0;
float fa4 = 0.0, sgfa4 = 0.0, fa5 = 0.0, sgfa5 = 0.0, sqfa5 = 0.0;
float star40 = 0.0, sgstar = 0.0, atm40 = 0.0, atomar = 0.0, sgatomar = 0.0;
float tot40 = 0.0, vol40 = 0.0, peso = 0.0, rad40 = 0.0;// sgtot40 = 0.0,
/* vol40 es ccSTP por gramo, atomar es atomos de 40Ar por gramo */
float pot = 0.0, sgpot = 0.0, pot40 = 0.0 , sgpot40 = 0.0;
/* pot es %K y sgpot es su error pot40 es gr de potasio por gr de muestra */
float atompot = 0.0, sgatompot = 0.0, zeta1 = 0.0, zeta2 = 0.0;
/*atompot es atomos de 40K por gramo */
float edad = 0.0, sgedad = 0.0, zeta3 = 0.0, zeta4 = 0.0, zeta5 = 0.0;
/* edad y zetas sirven para calcular la edad y su error */
float te = 0.0, te1 = 0.0, te2 = 0.0, te3 = 0.0, tet = 0.0, tet2 = 0.0, tet3 = 0.0;
/* tetas y sgteta sirven para calcular el error segun Dalrymple, 1969 */
float num, nub36, nub38 , nub40 ;
char nomb1 [100], nomb2 [100];// name [24], namer[24],
char atlab[24], date[24], spname[24];
int i, numero, nub;
FILE *in, *out;

	in = fopen(InFile, "r");
	out = fopen (OutFile, "w");
	fscanf (in, "%[^\n]", nomb1);
	fscanf (in, "%d", &nub);
	fprintf(out,"%s\n", nomb1);
	fprintf(out, "36        38      40     voltaje\n");
	for (i = 0; i<nub; i++){
		fscanf(in, "%f%f%f%f%f%f%f%f%f%f%f%f%f\n", &b36, &f2, &f3, &f4, &f5, &f6, &f7, &f8, &f9, &f10, &f11, &f12, &f13);
		a36 = f3 - (f2 + f4) / 2.0;
		a38 = f7 - (f6 + f8) / 2.0;
		a40 = f11 - (f10 + f12) / 2.0;
	fprintf(out, "%.4f  %.4f  %.4f   %.3f\n", a36, a38, a40, f13);
		q36[i] = a36;
		q38[i] = a38;
		q40[i] = a40;
		sib36[i] = ((0.0012 * a36)*(0.0012 * a36) + (n36 * n36));
		sib38[i] = ((0.0012 * a38)*(0.0012 * a38) + (n38 * n38));
		sib40[i] = ((0.0012 * a40)*(0.0012 * a40) + (n40 * n40));
		v36 = 1.0 / sib36[i];
		v38 = 1.0 / sib38[i];
		v40 = 1.0 / sib40[i];
		b36 = b36 + 20;
		b38 = b36 + 100.0;
		b40 = b36 + 180.0;
		z36[i] = b36;
		z38[i] = b38;
		z40[i] = b40;
		sv36 += v36;
		ss36 += (v36 * b36);
		ss36c += (v36 * b36 * b36);
		sb36 += (v36 * a36);
		sz36 += (v36 * b36 * a36);
		sv38 += v38;
		ss38 += (v38 * b38);
		ss38c += (v38 * b38 * b38);
		sb38 += (v38 * a38);
		sz38 += (v38 * b38 * a38);
		sv40 += v40;
		ss40 += (v40 * b40);
		ss40c += (v40 * b40 * b40);
		sb40 += (v40 * a40);
		sz40 += (v40 * b40 * a40);
	}
	den36 = sv36 * ss36c - ss36 * ss36;
	a036 = (sb36 * ss36c - ss36 * sz36) / den36;
	l36 = (sv36 * sz36 - sb36 * ss36) / den36;
	den38 = sv38 * ss38c - ss38 * ss38;
	a038 = (sb38 * ss38c - ss38 * sz38) / den38;
	l38 = (sv38 * sz38 - sb38 * ss38) / den38;
	den40 = sv40 * ss40c - ss40 * ss40;
	a040 = (sb40 * ss40c - ss40 * sz40) / den40;
	l40 = (sv40 * sz40 - sb40 * ss40) / den40;
	for(i=0; i<nub; i++){
		nub36 = q36[i] - a036 - l36 * z36[i];
		sub36 += (nub36 * nub36 / sib36[i]);
		nub38 = q38[i] - a038 - l38 * z38[i];
		sub38 += (nub38 * nub38 / sib38[i]);
		nub40 = q40[i] - a040 - l40 * z40[i];
		sub40 += (nub40 * nub40 / sib40[i]);
}
		sbm36 = sqrt (( ss36c / den36 ) * ( sub36 / (nub - 2 )));
		sgl36 = sqrt (( sv36 / den36 ) * ( sub36 / (nub - 2)));
		sbm38 = sqrt (( ss38c / den38 ) * ( sub38 / (nub -2 )));
		sgl38 = sqrt (( sv38 / den38 ) * ( sub38 / (nub - 2)));
		sbm40 = sqrt (( ss40c / den40 ) * ( sub40 / (nub - 2)));
		sgl40 = sqrt (( sv40 / den40 ) * ( sub40 / (nub - 2)));
//		spr36 = ( sbm36 / a036 ) *  ( sbm36 / a036 );
//		spr38 = ( sbm38 / a038 ) *  ( sbm38 / a038 );
//		spr40 = ( sbm40 / a040 ) *  ( sbm40 / a040 );
/* calculo de picos al tiempo de equilibrio */
	bco36 = l36 * 600.0 + a036;
	bco38 = l38 * 600.0 + a038;
	blk40 = l40 * 600.0 + a040;
	sgbl36 = sqrt( 360000.0 * sgl36 * sgl36 + sbm36 * sbm36);
	sgbl38 = sqrt( 360000.0 * sgl38 * sgl38 + sbm38 * sbm38);
	sgbl40 = sqrt( 360000.0 * sgl40 * sgl40 + sbm40 * sbm40);
	blk36 = (bco36 < 0.0) ? 0.00001 : bco36;
	blk38 = (bco38 < 0.0) ? 0.00001 : bco38;
fprintf(out,"\n");
fprintf(out,"y036 %.4f y038 %.4f y040 %.4f\n", a036, a038, a040);
	fprintf(out,"SumS36  %f   SumS38  %f   SumS40  %f\n", sub36, sub38, sub40);
	fprintf(out,"Pend36 %f Pend38 %f Pend40 %f\n", l36, l38, l40);
	fprintf(out,"err 36 %f err 38 %f err 40 %f\n", sgl36, sgl38, sgl40);
fprintf(out,"\n");
fprintf(out,"Blanco calculado al tiempo de equilibrio --------  40/36 =  %.1f\n", blk40/blk36);
fprintf(out,"36Ar  %f  38Ar  %f 40Ar  %f\n", blk36, blk38, blk40);
fprintf(out,"err36 %f  err38 %f err40 %f\n", sgbl36, sgbl38, sgbl40);
	fprintf(out,"\n");
	fscanf (in, "%[^\n]", nomb2);
	fscanf (in, "%d", &numero);
	fprintf(out,"%s\n", nomb2);
	fprintf(out, "36        38      40    voltaje\n");
	for (i = 0; i<numero; i++){
		fscanf(in, "%f%f%f%f%f%f%f%f%f%f%f%f%f", &x36, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11, &d12, &d13);
		y36 = d3 - (d2 + d4) / 2.0;
		y38 = d7 - (d6 + d8) / 2.0;
		y40 = d11 - (d10 + d12) / 2.0;
		p36[i] = y36;
		p38[i] = y38;
		p40[i] = y40;
fprintf(out, "%.4f  %.4f  %.4f   %.3f\n", y36, y38, y40, d13);
		sig36[i] = ((0.0012 * y36)*(0.0012 * y36) + (n36 * n36));
		sig38[i] = ((0.0012 * y38)*(0.0012 * y38) + (n38 * n38));
		sig40[i] = ((0.0012 * y40)*(0.0012 * y40) + (n40 * n40));
		w36 = 1.0 / sig36[i];
		w38 = 1.0 / sig38[i];
		w40 = 1.0 / sig40[i];
		x36 = x36 + 20;
		x38 = x36 + 100.0;
		x40 = x36 + 180.0;
		t36[i] = x36;
		t38[i] = x38;
		t40[i] = x40;
		sw36 += w36;
		st36 += (w36 * x36);
		st36c += (w36 * x36 * x36);
		s36 += (w36 * y36);
		sx36 += (w36 * x36 * y36);
		sw38 += w38;
		st38 += (w38 * x38);
		st38c += (w38 * x38 * x38);
		s38 += (w38 * y38);
		sx38 += (w38 * x38 * y38);
		sw40 += w40;
		st40 += (w40 * x40);
		st40c += (w40 * x40 * x40);
		s40 += (w40 * y40);
		sx40 += (w40 * x40 * y40);
	}
	fscanf(in, "%f%f%f%f", &sp4038, &sgsp4038, &sp3638, &sgsp3638);
	fscanf(in, "%f%f%f", &az36, &az38, &az40);
	fscanf(in, "%f%f%f%f", &tcero, &sgtcero, &delta, &sgdelta);
	fscanf(in, "%s%s", &atlab, &date);
	fscanf(in, "%f%f", &matm4036, &sgmatm);
	fscanf(in, "%s", &spname);
	fscanf(in, "%f%f%f%f", &spikeno, &peso, &pot, &sgpot);

	denom36 = sw36 * st36c - st36 * st36;
	y036 = (s36 * st36c - st36 * sx36) / denom36;
	m36 = (sw36 * sx36 - s36 * st36) / denom36;
	denom38 = sw38 * st38c - st38 * st38;
	y038 = (s38 * st38c - st38 * sx38) / denom38;
	m38 = (sw38 * sx38 - s38 * st38) / denom38;
	denom40 = sw40 * st40c - st40 * st40;
	y040 = (s40 * st40c - st40 * sx40) / denom40;
	m40 = (sw40 * sx40 - s40 * st40) / denom40;
	for(i=0; i<numero; i++){
		num = p36[i] - y036 - m36 * t36[i];
		sum36 += (num * num / sig36[i]);
		num = p38[i] - y038 - m38 * t38[i];
		sum38 += (num * num / sig38[i]);
		num = p40[i] - y040 - m40 * t40[i];
		sum40 += (num * num / sig40[i]);
}
		sgm36 = sqrt (( st36c / denom36 ) * ( sum36 / (numero - 2 )));
		sgmm36 = sqrt (( sw36 / denom36 ) * ( sum36 / (numero - 2)));
		sgm38 = sqrt (( st38c / denom38 ) * ( sum38 / (numero -2 )));
		sgmm38 = sqrt (( sw38 / denom38 ) * ( sum38 / (numero - 2)));
		sgm40 = sqrt (( st40c / denom40 ) * ( sum40 / (numero - 2)));
		sgmm40 = sqrt (( sw40 / denom40 ) * ( sum40 / (numero - 2)));
//		sqr36 = ( sgm36 / y036 ) *  ( sgm36 / y036 );
//		sqr38 = ( sgm38 / y038 ) *  ( sgm38 / y038 );
//		sqr40 = ( sgm40 / y040 ) *  ( sgm40 / y040 );
	fprintf(out,"\n");
	fprintf(out,"y036  %f y038 %f y040 %f\n", y036, y038, y040);
	fprintf(out,"err36 %f err38 %f err40 %f\n", sgm36, sgm38, sgm40);
	fprintf(out,"SumS36 %f   SumS38  %f   SumS40  %f\n", sum36, sum38, sum40);
	fprintf(out,"Pend 36 %f  Pend 38 %f Pend 40 %f\n", m36, m38, m40);
	fprintf(out,"err Pend %f  err Pend %f err Pend %f\n", sgmm36, sgmm38, sgmm40);
	eq6 = m36 * 600.0 + y036;
	eq8 = m38 * 600.0 + y038;
	eq0 = m40 * 600.0 + y040;
	seq6 = sqrt( 360000.0 * sgmm36 * sgmm36 + sgm36 * sgm36);
	seq8 = sqrt( 360000.0 * sgmm38 * sgmm38 + sgm38 * sgm38);
	seq0 = sqrt( 360000.0 * sgmm40 * sgmm40 + sgm40 * sgm40);
	eq06 = eq0 / eq6;
	eq08 = eq0 / eq8;
	eq68 = eq6 / eq8;
	seq06 = eq06 * sqrt ((seq6*seq6)/(eq6*eq6) + (seq0*seq0)/(eq0*eq0));
	seq08 = eq08 * sqrt ((seq8*seq8)/(eq8*eq8) + (seq0*seq0)/(eq0*eq0));
	seq68 = eq68 * sqrt ((seq6*seq6)/(eq6*eq6) + (seq8*seq8)/(eq8*eq8));
	fprintf(out,"\n");
fprintf(out,"Datos calculados al tiempo de equilibrio\n");
	fprintf(out,"36Ar %f 38Ar %f 40Ar %f\n", eq6, eq8, eq0);
	fprintf(out,"err36 %f err38 %f err40 %f\n", seq6, seq8, seq0);
	fprintf(out,"\n");
	fprintf(out,"40/36 %f  40/38 %f 36/38 %f\n", eq06, eq08, eq68);
	fprintf(out,"error  %f  error  %f error  %f\n", seq06, seq08, seq68);
/* correccion por blanco linea */
	  ab36 = ((eq6 - blk36) < 0.0) ? 0.00001 : (eq6 - blk36);
	  ab38 = ((eq8 - blk38) < 0.0) ? 0.00001 : (eq8 - blk38);
	  ab40 = ((eq0 - blk40) < 0.0) ? 0.00001 : (eq0 - blk40);
	  sgab36 = sqrt ((sgbl36 * sgbl36) + (seq6 * seq6));
	  sgab38 = sqrt ((sgbl38 * sgbl38) + (seq8 * seq8));
	  sgab40 = sqrt ((sgbl40 * sgbl40) + (seq0 * seq0));
/* correccion por discriminacion */
	  discr = (0.250) * (( nier / matm4036 ) - 1 );
	  sgdiscr = ( nier * sgmatm ) / (4.0 * matm4036 * matm4036 );
	  dis36 = 1.0000 + (4.0 * discr);
	  dis38 = 1.0000 + (2.0 * discr);
	  ar36 = ab36 / ( dis36 );
	  discr36 = (4 * ab36 * sgdiscr) / (dis36 * dis36);
	  sgar36 = sqrt ((sgab36 / dis36) * (sgab36 / dis36) + (discr36 * discr36));
	  sqar36 = (sgar36 / ar36) * (sgar36 / ar36);
	  ar38 = ab38 / ( dis38 );
	  discr38 = (2 * ab38 * sgdiscr) / (dis38 * dis38);
	  sgar38 = sqrt ((sgab38 / dis38) * (sgab38 / dis38) + (discr38 * discr38));
	  sqar38 = (sgar38 / ar38) * (sgar38 / ar38);
	  ar40 = ab40;
	  ax40 = ar40 - ((ar38 * az40)/ az38 );
	  ax36 = ar36 - ((ar38 * az36) / az38);
	  sgar40 = sgab40;
	  sqar40 = (sgar40 / ar40) * (sgar40 / ar40);
	fprintf(out,"\n");
  fprintf(out,"Masa36 %f Masa38 %f Masa40 %f\n", ar36, ar38, ar40);
  fprintf(out,"err 36 %f err 38 %f err 40 %f\n", sgar36, sgar38, sgar40);
  fprintf(out,"40/36 muestra %.1f\n", ax40/ax36);
/* calculo del volumen de Ar38 */
	  esp = exp ((-1) * delta * spikeno);
	  sp38 = tcero * esp;
	  sqs38 = delta * tcero * esp * sgdelta;
	  sgsp38 = sqrt ((esp * sgtcero) * (esp * sgtcero) + (sqs38 * sqs38));
	  sqsp38 = (sgsp38 / sp38) * (sgsp38 / sp38);
/* calculo de los cocientes de la muestra */
	  m3836 = (ar38 / ar36);
	  sgm3836 = (m3836 * (sqrt (sqar38 + sqar36)));
//	  sgm3638 = (ar36/ar38) * (sqrt (sqar38 + sqar36));
	  m4038 = (ar40 / ar38);
	  sgm4038 = m4038 * (sqrt (sqar40 + sqar38));
/* calculo de 40Ar star */
	  fa1 = (1 - (m3836 * sp3638));
	  fa1a = (sp3638 * sp3638 * sgm3836 * sgm3836);
	  fa1b = (m3836 * m3836 * sgsp3638 * sgsp3638);
	  sgfa1 = sqrt ( fa1a + fa1b);
	  sqfa1 = (sgfa1 / fa1) * (sgfa1 / fa1);
	  fa2 = ((m3836 * atm3638) - 1);
	  sgfa2 = (atm3638 * sgm3836);
	  sqfa2 = (sgfa2 / fa2) * (sgfa2 / fa2);
	  fa3 = (at4038 - m4038);
	  sgfa3 = (sgm4038);
	  sqfa3 = (sgfa3 / fa3 ) * (sgfa3 / fa3);
	  fa4 = (fa1 / fa2) * fa3;
	  sgfa4 = (fa4 * (sqrt (sqfa1 + sqfa2 + sqfa3)));
	  fa5 = (m4038 - sp4038 - fa4);
	  sgfa5 = (sqrt ((sgm4038 * sgm4038) + (sgsp4038 * sgsp4038) + (sgfa4 * sgfa4)));
	  sqfa5 = (sgfa5 / fa5) * (sgfa5 / fa5);
	  star40 = (sp38 * fa5);
	  tot40 = (m4038 * sp38);
//	  sgtot40 = (tot40 * (sqrt ((sgm4038 / m4038) * (sgm4038/m4038) + sqsp38)));
	  rad40 = star40 / tot40;
	  atm40 = (1.0 - rad40);
	  sgstar = (star40 * (sqrt (sqsp38 + sqfa5)));
	  vol40 = (star40 / peso);
	  atomar = (vol40 * 6.023E23) / (2.24E4);
	  sgatomar = ((sgstar / peso) * (6.023E23)) / (2.24E4);
	  pot40 = (pot / 100);
	  sgpot40 = (sgpot / 100);
	  atompot = ((pot40 * 6.023E23 * 1.167E-4) / (39.0983));
	  sgatompot = ((sgpot40 * 6.023E23 * 1.167E-4) / (39.0983));
	  edad = (1 / 5.543E-10) * (log ((5.543 / 0.581) * (atomar / atompot) + 1));
	  zeta1 = (1 / 5.543E-10) * (1 / ((5.543 / 0.581) * (atomar / atompot) + 1));
	  zeta2 = (5.543 / 0.581 ) * ( 1 / atompot);
	  zeta3 = (5.543 / 0.582) * ( atomar / (atompot * atompot));
	  zeta4 = (zeta1 * zeta2 * sgatomar);
	  zeta5 = (zeta1 * zeta3 * sgatompot);
	  sgedad = sqrt ((zeta4 * zeta4 ) + (zeta5 * zeta5));
	  lamb = ( 1 - (exp ((-1) * 5.543E-10 * edad))) / (5.543E-10 * edad);
	  te1 = ((sgpot40 * sgpot40) / (pot * pot)) + sqsp38;
	  te2 = (1 + atm40/rad40) * (1 + atm40/rad40) * sqar40 + sqar38;
	  te3 = ((atm40 * atm40)/(rad40 * rad40)) * sqar36;
	  te = edad * lamb * sqrt( te1 + te2 + te3 );
	  tet2 = (sqar40 + sqar38) * (1 / (rad40 * rad40));
	  tet3 = (sqar36 + sqar38) * ((atm40*atm40) / (rad40 * rad40));
	  tet = edad * sqrt (te1 + tet2 + tet3);
	fprintf(out,"\n");
fprintf(out,"Spike No %s  No spk %.1f 38Ar spk %12.5E err %12.5E\n", spname, spikeno, sp38, sgsp38);
fprintf(out, "40/38sp %.6f err %.6f 36/38sp %.6f err %.6f\n", sp4038, sgsp4038, sp3638, sgsp3638);
fprintf(out, "Delta %12.5E  err %12.5E Tcero %12.5E err %12.5E\n", delta, sgdelta, tcero, sgtcero);
fprintf(out,"\n");
fprintf(out, "40/38m %.6f err %.6f 38/36m %.6f err %.6f\n", m4038, sgm4038, m3836, sgm3836);
	fprintf(out,"\n");
	fprintf(out,"Vol 40Ar total en cc STP/gr = %12.5E\n", vol40);
	fprintf(out,"\n");
fprintf(out,"EDAD %12.5E error %12.5E\n", edad, sgedad);
fprintf(out,"Error segun York  %12.5E Error segun Dalrymple %12.5E\n", te, tet);
	fprintf(out,"\n");
fprintf(out,"40Ar rad %.2f 40Ar atm %.2f Peso muestra %.4f Potasio %.2f err %.2f\n", rad40*100, atm40*100, peso, pot, sgpot);
fprintf(out,"Atmos No %s  fecha atmos %s 40/36 atm %.1f err %.1f\n", atlab, date, matm4036, sgmatm);
	fclose(in);
	fclose(out);
}
