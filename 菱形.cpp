#include<iostream>
using namespace std;
int main()
{
	int n,i,j;
	while(cin>>n)
	{
	 for(i=1;i<=n;i++)
	 {
		for(j=1;j<=n-i;j++)
		{cout<<" ";}
		cout<<"*";	
		if(i==1)
		{cout<<endl;continue;}
		for(j=1;j<=i-2;j++)
		{cout<<" ";}
		cout<<"*";
		for(j=1;j<=i-2;j++)
		{cout<<" ";}
		cout<<"*"<<endl;
	 }
	  for(i=n-1;i>=1;i--)
	 {
		for(j=1;j<=n-i;j++)
		{cout<<" ";}
		cout<<"*";	
		if(i==1)
		{cout<<endl;continue;}
		for(j=1;j<=i-2;j++)
		{cout<<" ";}
		cout<<"*";
		for(j=1;j<=i-2;j++)
		{cout<<" ";}
		cout<<"*"<<endl;
	 }
	} 
} 
