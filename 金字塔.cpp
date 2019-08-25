#include<iostream>
using namespace std;
int main()
{
	int n,i,j;
	char m;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		cout<<" ";
		for(j=1;j<=2*i-1;j++)
		cout<<m;
		cout<<endl;
	}
} 
