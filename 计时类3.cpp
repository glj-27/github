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
class DateTime:public Time,public Date
{
	public:
		DateTime (int n,int d,int h,int m,ints)
		{
			second=second+n;
			for(second;second>=60;second=second-60)
			{minute++;}
			for(minute;minute>=60;minute=minute-60)
			{hour++;}
			for(hour;hour>=24;hour=hour-24)
			{day++;}
		}
		
};
int main()
{
	int a,b,c,d,e,f,n;
	while(cin>>a>>b>>c>>d>>e>>f>>n)
	{
	  Time(d,e,f);Date(a,b,c);
	  DateTime (n);
	  cout<<Date.year<<" "<<Date.month<<" "<<DateTime.day<<" "<<DateTime.hour<<" "<<DateTime.minute<<" "<<DateTime.second;
	}
}

