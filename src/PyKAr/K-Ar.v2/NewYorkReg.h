//---------------------------------------------------------------------------
#ifndef NewYorkRegH
#define NewYorkRegH
typedef float * PTREAL;

class TIsochron
{
	public:
	PTREAL x, y, sx, sy, wx, wy, alfa, r;
	PTREAL u37, u39k, u38;
	unsigned *IsochExcl;
	float j,sigj;
	float xint,slope,yint,sigxint,sigslope,sigyint;
	float ar40_36,ar40_39,sig40_36,sig40_39;
	float age,sigage;
	float fitxint,fityint,fitslope,fit40_36,fit40_39,fitage,sums;
	PTAGE list;
	int n;
};//---------------------------------------------------------------------------
#endif
