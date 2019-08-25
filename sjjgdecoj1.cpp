#include <cstdio>
#include <iostream>
using namespace std; 
int main()
{
  int m,n,a,i,q,j,k,t;
  while (cin>>n>>m)
  {
    int a[n+1];
    if(n==0 && m==0)
    break;
    else
    for(i=1;i<=n;i++)
    {
      cin>>a[i];
    }
    a[i+1]=m;
    for(j=1;j<n+1;j++)
    {
       q=0;
       for(k=0;k<n+1-j;k++)
       {
          if(a[k]>a[k+1])
          {
             t=a[k];
             a[k]=a[k+1];
             a[k+1]=t;
             q=1;
          }
       } 
       if (q==0)  break;
    }
     for(j=0;j<n+1;j++)
      {
         cout<<a[j];
      }
      cout<<"\n";
  }
         return 0;
 }
