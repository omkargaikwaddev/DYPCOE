#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;
class kochcurve
{
	public:
	void koch(int it,int x1,int y1,int x5,int y5)
	{
		int x2,y2,x3,y3,x4,y4;
		int dx,dy;
		if(it==0)
		{
			line(x1,y1,x5,y5);
		}
		else
		{
			delay(50);a
			dx=(x5-x1)/3;
			dy=(y5-y1)/3;
			x2=x1+dx;
			y2=y1+dy;
			x3=(int)(0.5*(x1+x5)+sqrt(3)*(y1-y5)/6);
			y3=(int)(0.5*(y1+y5)+sqrt(3)*(x5-x1)/6);
			x4=2*dx+x1;
			y4=2*dy+y1;
			koch(it-1,x1,y1,x2,y2);
			koch(it-1,x2,y2,x3,y3);
			koch(it-1,x3,y3,x4,y4);
			koch(it-1,x4,y4,x5,y5);
		}
	}
};
int main()
{
	kochcurve k;
	int it;
	cout<<"Number of iterations"<<endl;
	cin>>it;
	int gd=DETECT;
	int gm;
	initgraph(&gd,&gm,NULL);
	k.koch(it,150,20,20,280);
	k.koch(it,280,280,150,20);
	k.koch(it,20,280,280,280);
	getch();
	closegraph();
	return 0;
}

