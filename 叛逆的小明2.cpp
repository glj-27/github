#include<cstdio>
#include<iostream>
using namespace std; 
int dao(int a) 
{ 
  int b=0,c; 
  if(a<0) {c=a;a=-a;}  
  while(a) 
  { b=b*10+a%10; a=a/10; } 
  if(c<0) b=-b; return b; 
}
int main()
{ 
   int a,b,m,n,x,y,t; 
   cin>>t; 
   while(t--) 
   { 
     cin>>x>>y;
     m=(x+y)/2; n=(x-y)/2; a=dao(m); b=dao(n);
     cout<<a+b<<" "<<a-b<<endl;
   }
}
