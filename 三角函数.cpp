#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	const double pi=3.1415926;
	int i;
	double x,x1,a,b,c; 
	for(i=1;i<=18;i++)
	{
		x=(i*10*pi)/180;
		x1=i*10;
		a=sin(x);
		b=cos(x);
		c=tan(x);
		cout<<"x1="<<x1<<'\t'<<"sinx="<<a<<'\t'<<"cosx="<<b<<'\t'<<"tanx="<<c<<endl;
	}
}
