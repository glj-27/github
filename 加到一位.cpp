#include<iostream>
using namespace std;
int jixu(int a)
{
	int b=0;
	while(a!=0)
	{b=b+a%10;a=a/10;}
	if(b>10){return jixu(b);}
	return b;
} 
int main()
{
	int n;
	while(cin>>n)
	cout<<jixu(n)<<endl;
}
