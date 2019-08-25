#include<iostream>
#include<cmath>	
using namespace std;
int main()
{ 
 const double b= 1e-8;
 double a,x0,x;
 cout<<"ÇëÊäÈëa:";
 cin>>a;
 x0=a/2;
 x=(x0+a/x0)/2; 
 while(fabs(x-x0)>b*a)
 {
  x0=x;x=(x0+a/x0)/2; 
 }
 cout<<x<<endl;
}

