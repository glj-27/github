#include<iostream>
using namespace std;
int dao(int a)
{
	int b=0,c;
	if(a<0){c=a;a=-a;}
	while(a)
	{
		b=b*10+a%10;a=a/10;
	}
	if(c<0) b=-b; return b;
}
int main()
{
	int T,x,y,a,b;
	cin>>T;
	while(T--)
	{
	 cin>>x>>y;
	 a=(x+y)/2;b=(x-y)/2;
	 a=dao(a);b=dao(b);
	 cout<<a+b<<" "<<a-b<<endl;
    }
}
