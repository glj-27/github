#include<iostream>
#include<cstdio>
using namespace std;
class  fares//Ʊ�� 
{
	public:
		double balance;//��� 
};
class older : public fares
{
	public:
		
		older(double a)
		{
			discount1=a; //�ۿ� 
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
	cout<<"���п����Ϊ100"<<endl<<"�����������ˣ�ѧ������ͨ�˵��ۿۣ�Ʊ�ۣ�����������" ; 
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
