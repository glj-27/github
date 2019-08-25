#include<iostream>
using namespace std;
int sumofsquare (int a,int b)
{return a*a+b*b;}

int sumofsquare (int a,int b,int c)            //重载函数定义的形参（个数）必须不同 
{return a*a+b*b+c*c;}

double sumofsquare (double a,double b)         //函数名相同 形参（类型）不同 
{return a*a+b*b;}
 int main()
 {
 	int x,y,z; 
 	cout<<"整数x y z=";
 	cin>>x>>y>>z; 
 	cout<<"整数x y的平方和="<<sumofsquare(x,y)<<endl;
 	cout<<"整数x y z的平方和="<<sumofsquare(x,y,z)<<endl;
 	cout<<"浮点数m n="; 
 	double m,n;
	 cin>>m>>n;
 	cout<<"浮点数m n的平方和="<<sumofsquare(m,n)<<endl;
 }
