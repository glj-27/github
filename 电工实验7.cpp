#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	while(1)
	{
	
	double P=3.14;
	double u1,u2,u3,z,q,r,l,c,i,co;
	cin>>u1>>u2>>u3;
	i=u2/1000;
	z=u3/i;
	q=acos((u1*u1-u2*u2-u3*u3)/(2*u2*u3));
	co=cos(q);
	r=z*co;
	l=z*sin(q)/(2*P*50);
	c=1/(2*P*50*z*sin(q));
	cout<<z<<"  "<<co<<"  "<<r<<"  "<<l<<"  "<<c;
	}
}
