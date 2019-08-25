#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i,a,b,c;
	for(i=100;i<=999;i++) 
	{
		a=i%10;
		b=((i-a)/10)%10;
		c=((i-a)/10-b)/10;
		if(i==a*a*a+b*b*b+c*c*c) cout<<i<<endl;
	}
} 
