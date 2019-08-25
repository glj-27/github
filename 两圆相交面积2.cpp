#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
double q,w,m,n,a,b,c,x,y,z,PI;
int main()
{
	PI=2*asin(1.0);
    while(cin>>a>>b>>c>>x>>y>>z)
	{
      double l=sqrt((a-x)*(a-x)+(b-y)*(b-y));
      if(l>=c+z||!c||!z) x=0;        
      else if(l<=fabs(z-c)) 
      {
        if(z>c)z=c;
        x=z*z*PI;
      }
      else
      {
        b=acos((l*l+c*c-z*z)/(2*l*c));                                         
        y=acos((l*l+z*z-c*c)/(2*l*z));                                                
        m=b*c*c;                                                   
        n=y*z*z;                                                        
        q=c*c*sin(b)*cos(b);                                                       
        w=z*z*sin(y)*cos(y);
        x=m+n-(q+w);
      }
      cout.setf(ios::fixed);
	  cout<<fixed<<setprecision(2)<<x<<endl;
	}
    return 0;
}
