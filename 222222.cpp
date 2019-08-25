#include<iostream>
using namespace std;
int main()
{
	int n,i,j;
	cout<<"请输入正方形边长：";
	cin>>n;
	for(j=1;j<=n-1;j++)
		{cout<<"*"<<" ";}cout<<"*"<<endl;
	for(i=1;i<=n-2;i++)
	{
		cout<<"*";
		for(j=1;j<=n-2;j++)
		{cout<<"  ";}
		cout<<" "<<"*"<<endl;
	}
	for(j=1;j<=n-1;j++)
		{cout<<"*"<<" ";}cout<<"*"<<endl;
}
