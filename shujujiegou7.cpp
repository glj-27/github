#include<iostream>
#define M 10000
using namespace std;
int main()
{
	int n,t;
	while(cin>>n>>t)
	{
      int a[M];
      int m=0,i=1,k=0,j=0;
      for(j=1;j<=n;j++)
	  {
        a[j]=j;		
      }
      while(m < n-1)
	  {
        if(a[i]!=0)
		{				
            k++;		
        }
        if(k == t)
		{
            a[i]=0;
            k=0;
            m++;
        }
        i++;
        if(i == n+1)
		{
            i=1;
        } 
      } 
      for(j=1;j<=n;j++)
	  {
        if(a[j]!=0)
		{
            cout<<a[j]<<endl;
        }
      }
      }
      return 0;
}
