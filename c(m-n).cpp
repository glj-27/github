#include<iostream>
using namespace std;
int main()
{
	double n,m,i,j,x=1,y=1;
	cout<<"�������ѡ������(c m-n)"<<endl<<"������="; 
	cin>>m;
	cout<<"ѡ������=";
	cin>>n; 
	for(i=m;i>m-n;i--)
	{
	  x=x*i;
    }
	for(j=n;j>=1;j--)
	{
      y=y*j;
	}
	cout<<"�������"<<x/y<<"��"<<endl;
} 
