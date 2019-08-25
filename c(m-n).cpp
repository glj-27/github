#include<iostream>
using namespace std;
int main()
{
	double n,m,i,j,x=1,y=1;
	cout<<"概率随机选择问题(c m-n)"<<endl<<"几个数="; 
	cin>>m;
	cout<<"选几个数=";
	cin>>n; 
	for(i=m;i>m-n;i--)
	{
	  x=x*i;
    }
	for(j=n;j>=1;j--)
	{
      y=y*j;
	}
	cout<<"情况共有"<<x/y<<"种"<<endl;
} 
