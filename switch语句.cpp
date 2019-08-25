#include<iostream>
using namespace std;
int main()
{
	int n,r,a,b,s;
	const double p=3.1415; 
	cout<<"1 圆形；2 长方形；3 正方形 :";
	cin>>n;
	switch(n)
	{
		case 1: 
		cout<<"圆形的半径：";
		cin>>r;s=p*r*r;
		cout<<"圆形的面积："<<s;
		break;
		case 2:
		cout<<"长方形的边长：";
		cin>>a>>b;s=a*b;
		cout<<"长方形的面积："<<s;
		break;
		case 3:
		cout<<"正方形的边长：";
		cin>>a;s=a*a;
		cout<<"正方形的面积："<<s;
		break;
	} 
	cout<<endl;
} 
