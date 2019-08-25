#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class customer
{
	public :
		double money;
};
class Student : public customer
{
	public :
		Student(double a)
		{
			discount1=a;
			money=100;
		}
		double discount1;
};
class Older : public customer
{
	public :
		Older(double a)
		{
			discount2=a;
			money=100;
		}
		double discount2;
};
class Common : public customer
{
	public :
		Common(double a){
			discount3=a;
			money=100;
		}
		double discount3;
};
int main()
{
	double a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e;
	Older A(a); Student B (b); Common C(c);
	for (int i=1;i<=e;i++)
	{
		printf("OLDER  ");
		if ( A.money - d*A.discount2>0 ) {cout<<d*A.discount2<<endl;A.money -= d*A.discount2;} else printf("Please recharge!\n");
		printf("STUDENT ");
		if ( B.money - d*B.discount1>0 ) {cout<<d*B.discount1<<endl;B.money -= d*B.discount1;} else printf("Please recharge!\n");
		printf("COMMON ");
		if ( C.money - d*C.discount3>0 ) {cout<<d*C.discount3<<endl;C.money -= d*C.discount3;} else printf("Please recharge!\n");
	}


}
