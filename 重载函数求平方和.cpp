#include<iostream>
using namespace std;
int sumofsquare (int a,int b)
{return a*a+b*b;}

int sumofsquare (int a,int b,int c)            //���غ���������βΣ����������벻ͬ 
{return a*a+b*b+c*c;}

double sumofsquare (double a,double b)         //��������ͬ �βΣ����ͣ���ͬ 
{return a*a+b*b;}
 int main()
 {
 	int x,y,z; 
 	cout<<"����x y z=";
 	cin>>x>>y>>z; 
 	cout<<"����x y��ƽ����="<<sumofsquare(x,y)<<endl;
 	cout<<"����x y z��ƽ����="<<sumofsquare(x,y,z)<<endl;
 	cout<<"������m n="; 
 	double m,n;
	 cin>>m>>n;
 	cout<<"������m n��ƽ����="<<sumofsquare(m,n)<<endl;
 }
