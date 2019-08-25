#include<iostream>
using namespace std;  
int main() 
{
    int n,i,j;char m;
    cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i-1;j++)
		{cout<<"  ";}
		for(j=1;j<=2*n-2*i;j++)
		{cout<<m<<" ";}
		cout<<m<<endl;
	}
} 
