#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;cin>>n;
	while (n--)
	{
	  double a[10],b,c=0;
	  int k=0;
      for(int i=0;i<10;i++)
      {
    	cin>>b;a[i]=b;
      }
	   for(int i=0;i<10;i++)
      {
    	  if(a[i]>0)
    	  {
    		c=c+a[i];k++;
    	  }
      }
	  if(c>0) {cout<<fixed<<setprecision(2)<<c/k<<endl;}
	  else cout<<"None";
	}
}
