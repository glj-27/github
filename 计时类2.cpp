#include<iostream>
using namespace std;
class Time
{
	public:
		Time(int d,int e,int f)
		{
			hour=d;minute=e;second=f;
		}
	private:
		int hour,minute,second;
};
class Date
{	
    public:
	    Date(int a,int b,int c)
		{
			year=a;month=b;day=c;
	    }
	private:
		int  year,month,day;
};
class DateTime
{
	public:
		int o,p,q,r;
		void jishi(int c,int d,int e,int f,int n)
		{
			
			f=f+n;
			for(f;f>=60;f=f-60)
			{e++;r=f;}
			for(e;e>=60;e=e-60)
			{d++;q=e;}
			for(d;d>=24;d=d-24)
			{c++;p=d;o=c;}
		}
		
};
int main()
{
	int a,b,c,d,e,f,n;
	while(cin>>a>>b>>c>>d>>e>>f>>n)
	{
	  Time(d,e,f);Date(a,b,c);
	  DateTime A;
	  A.jishi(c,d,e,f,n);
	  cout<<a<<" "<<b<<" "<<A.o<<" "<<A.p<<" "<<A.q<<" "<<A.r;
	}
}

