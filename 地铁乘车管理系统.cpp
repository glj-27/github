#include<iostream>
#include<cstdio>
using namespace std;
class  fares//票价 
{
	public:
		double balance;//余额 
};
class older : public fares
{
	public:
		
		older(double a)
		{
			discount1=a; //折扣 
			balance=100;
		}
		double discount1;		
}; 
class student : public fares
{
	public:
		
		student(double a)
		{
			discount2=a;
			balance=100;
		}
		double discount2;		
};
class common : public fares
{
	public:
		
		common(double a)
		{
			discount3=a;
			balance=100;
		}
		double discount3;		
};
int main()
{
	cout<<"所有卡余额为100"<<endl<<"请输入老年人，学生，普通人的折扣，票价，购买张数：" ; 
	double a,b,c,d,n;
	cin>>a>>b>>c>>d>>n;
	older A(a); student B(b); common C(c);
	while(n--)
	{   
		cout<<"OLDER  ";
		if(A.balance-d*A.discount1>0) {cout<<d*A.discount1<<endl;A.balance-=d*A.discount1;} 
		else cout<<"Please recharge!"<<endl;
		cout<<"STUDENT  ";
		if(B.balance-d*B.discount2>0) {cout<<d*B.discount2<<endl;B.balance-=d*B.discount2;} 
		else cout<<"Please recharge!"<<endl;
		cout<<"COMMON  ";
		if(C.balance-d*C.discount3>0) {cout<<d*C.discount3<<endl;C.balance-=d*C.discount3;} 
		else cout<<"Please recharge!"<<endl;
	}
} 
