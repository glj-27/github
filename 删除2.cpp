#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;
class Employee
{
	public :
		virtual void pay()=0;
		double profit1;
};
class Manager : virtual public  Employee
{
	public :
	    Manager(double a){profit1=a;}
	    void pay()
		{
		    double t=8000;
		    cout<<1001<<setw(20)<<"manager_zhang"<<setw(16)<<t<<endl;
     	}
};
class Saleman : virtual public  Employee
{
	public :
	Saleman(double a){profit1=a;}
	void pay()
	{
		double t=profit1*0.1;
		cout<<2001<<setw(20)<<"saleman_li"<<setw(16)<<(int)t<<endl;
	}
};
class ManagerSaleman : virtual public Manager, virtual public Saleman
{
	public :
	ManagerSaleman(double a,double b,double c): Saleman(b),Manager(c)
	{profit1=a;}
	void pay()
	{
		double t=5000+profit1*0.02;
		cout<<3001<<setw(20)<<"managerSaleman_wang"<<setw(16)<<(int)t<<endl;
	}
};
int main()
{
	double s;
	while (cin>>s)
	{
		Manager A(s);
		Saleman B(s);
		ManagerSaleman C(s,s,s);
		A.pay();
		B.pay();
		C.pay();
	}


}
