#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double r,girth,area;
	const double PI=3.1415;
	cout<<"请输入半径："<<endl;
	cin>>r;
	girth=2*PI*r;
	area=PI*r*r;
	cout<<"半径="<<r<<endl;
	cout<<"周长="<<girth<<endl;
	cout<<"面积="<<area<<endl;
	
} 
