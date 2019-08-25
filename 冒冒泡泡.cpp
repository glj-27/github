#include<iostream>
using namespace std;
int main()
{
	int n;int m;
	cin>>n;
	int*p=new int[n];
	for(int i=0;i<n;i++)
	cin>>p[i];
	for(int i=0;i<n;i++)
	{
	   for(int j=0;j<n;j++)
	   {
		   int t;
		   if(p[j]<p[j+1])
		   {
		   	   t=p[j];p[j]=p[j+1];p[j+1]=t;
		   }
	   }
    }
    for(int i=0;i<n;i++)
    cout<<p[i]<<" ";
} 
