#include<iostream>
using namespace std;
int main()
{
	int a,b,c,t;
	cout<<"��������������";
	cin>>a>>b>>c;
	if(a>b);
	{t=a;
	 a=b;
	 b=t;
	}
	if(c<a) cout<<c<<"<"<<a<<"<"<<b;
	else if(c<b) cout<<a<<"<"<<c<<"<"<<b;
	else cout<<a<<"<"<<b<<"<"<<c;
} 
