#include <cstdio>
#include <iostream>
using namespace std;
 
void ojld(int a,int b,int &s,int &t)
{
    if (b) ojld(b,a%b,s,t);
    else 
	{
        s=1; t=0; return;
    }
    int S=t,T=s-a/b*t;
    s=S; t=T;
}
 
int main()
{
    int s,t,a,b;
    cout<<"a=";
    cin>>a;
	cout<<"b=";
	cin>>b;
    ojld(a,b,s,t);
    cout<<"s="<<s<<" t="<<t<<" (a,b)="<<a*s+b*t;
}
