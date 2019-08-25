#include<iostream> 
#include<cstdio>
using namespace std;
int a[1000],n,i,j,ans;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)		cin>>a[i];
	
	for (i=1;i<=n;i++)
		for (j=i-1;j>=1;j--) 
			if (a[j] > a[i] ) ans++;			
	cout<<ans;
	
	
}
