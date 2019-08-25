#include<iostream>
using namespace std;
int main()
{
	char a[12][12];
	for(int i=0;i<=11;i++)
	for(int j=0;j<=11;j++)
	cin>>a[i][j];cout<<endl;
	for(int i=0;i<=11;i++)
	for(int j=0;j<=11;j++)
	{
	    cout<<a[i][j]<<" ";
	   	if(j==11) cout<<endl;
	}
}
