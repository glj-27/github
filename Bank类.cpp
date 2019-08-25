#include<iostream>
using namespace std;
class CBank
{
	private:
		int balance;
	public:
		void Bank1(int b)
		{
			balance=b;
		}
};
class JBank
{
	private:
		int balance;
	public:
		void Bank2(int b)
		{
			balance=b;
		}
};
class GBank
{
	private:
		int balance;
	public:
		void Bank3(int b)
		{
			balance=b;
		}
	friend int sum(int x,int y,int z);
};
int sum(int x,int y,int z)
{
	return x+y+z;
};
int main()
{   
    CBank C;
    JBank J;
    GBank G;
	int a,b,c;
	while(cin>>a>>b>>c)
	{
	 C.Bank1(a);
	 J.Bank2(b);
	 G.Bank3(c);
	 cout<<sum(a,b,c)<<endl;
    }
}












