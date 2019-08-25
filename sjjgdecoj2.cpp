#include <stdio.h>
int main()
{
  int m,n,a,b,c,q,h,r,t;
  while (scanf("%d%d",&n,&m)!=EOF)
  {
    int a[n+1];
    if(n==0 && m==0)
    break;
    else
    for(c=0;c<n-1;c++)
    {
      scanf("%d",&a[c]);
    }
    a[c+1]=m;
    for(h=1;h<n+1;h++)
{
    q=0;
    for(r=0;r<n+1-h;r++)
    {
    if(a[r]>a[r+1])
{
    t=a[r];
    a[r]=a[r+1];
    a[r+1]=t;
    q=1;
}
    } 
    if (q==0)  break;
   }
     for(h=0;h<n+1;h++)
      {
         printf(" %d",a[h]);
      }
      printf("\n");
  }
         return 0;
 }
