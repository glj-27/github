#include<iostream>
using namespace std;
int main()
{
	int i,a[10],b[10];
	for(i=0;i<=10;i++)
	{
		a[i]=i*2+1;
		b[10-i]=a[i];
	}
	for(i=0;i<=10;i++)
	{
		cout<<"a["<<i<<"]="<<a[i]<<'\t'<<'\t';
		cout<<"b["<<i<<"]="<<b[i]<<endl;
	}
} 
