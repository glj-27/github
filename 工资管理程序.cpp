#include<iostream>
#include<iomanip>
using namespace std;
class Employee
{
    public:
     	virtual void pay()=0; //一定要定义这个函数的值为零，为啥？？？？ 
     	double profit;        //虚构函数：在一个基类中定义一个虚构函数，在其他类引用是也需要加上virtual 
};
class Manager:virtual public Employee
{
	public:
		Manager(double a){profit=a;}
		void pay()
		{
			double salary=8000;
			cout<<1001<<setw(20)<<"manager_zhang"<<setw(16)<<salary<<endl;
		}
		
};
class Saleman:virtual public Employee
{
	public:
		Saleman(double a){profit=a;}
		void pay()
		{
			double salary=profit*0.1;
			cout<<2001<<setw(20)<<"saleman_li"<<setw(16)<<(int)salary<<endl;
		}
};
class ManagerSaleman:virtual public Manager,virtual public Saleman
{
	public:
		ManagerSaleman(double a,double b,double c):Manager(b),Saleman(c)// 
		{profit=a;}
		void pay()
		{
			double salary=5000+profit*0.02;
			cout<<3001<<setw(20)<<"managerSaleman_wang"<<setw(16)<<(int)salary<<endl;
		}	
};
int main()
{
	double s;
	while(cin>>s)
	{
		Manager A(s);
		Saleman B(s);
		ManagerSaleman C(s,s,s);
		A.pay();
		B.pay();
		C.pay();
	}
}
