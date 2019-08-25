#include<iostream>
using namespace std;
class Time
{
 public:
    Time(int h,int m,int s):hour(h),minute(m),sec(s){}
    void display(){cout<<hour<<":"<<minute<<":"<<sec<<endl;}
protected:
    int hour;
    int minute;
    int sec;  
};
class Date
{
 public:
    Date(int y,int mo,int d):year(y),month(mo),day(d){}
    void show(){cout<<year<<"Äê"<<month<<"ÔÂ"<<day<<"ÈÕ"<<endl;}
protected:
    int year;
    int month;
    int day;
};
class Timedate:public Date,public Time
{
 public:
    Timedate(int y,int mo,int d,int h,int m,int s):Date(y,mo,d),Time(h,m,s){}
    void displayall()
	{show();display();}
};
int main()
{
 int y,mo,d,h,m,s;
 while(cin>>y>>mo>>d>>h>>m>>s)
 {
    Date d(y,mo,d);
    d.show();
    Time t(h,m,s);
    t.display();
    Timedate T(y,mo,d,h,m,s);
    T.displayall();
    return 0;
 }
}
