#include<iostream>
using namespace std;
class Time
{
	private:
		int hour;
		int minute;
		int second;
};
class Date
{
	private:
		int year, month,day;
};
class DateTime:public Time,public Date
{
	void time()
	{
		for(;second>=60;second=second-60)
		{
	       minute++;
	       if(minute>=60)
	       {
		       hour++;minute=minute-60;
	       }
	       if(hour>23)
	       {
		       day++;hour=hour-24;
	       }
	    }
	}
};
int main()
{
	DateTime t;
	cin>>t.year>>t.month>>t.day>>t.hour>>t.minute>>t.second;
    t.time();
}
