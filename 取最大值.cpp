#include<iostream>
using namespace std;
int max(int a,int b)
{
	if (a>b)return a;
	else return b;
} 
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<max(c,max(a,b));
}
