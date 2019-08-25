#include<iostream>
using namespace std;
const double PI=3.14;
class Shape
{	public:
		Shape(int i=0,int j=0){x=i,y=i;}
	private:
		int x,y;
};
class circle:public Shape
{
	public:
		circle(double radious=0){r=radious;}
		double area(){cout<<"mianji:"<<PI*r*r<<endl;}
		void show(){cout<<r<<endl;} 
		double getr(){return r;}
	private:
		double r;
};
class ball:public circle
{
	public:
		ball(double radius):circle(radius){}
		void area(){cout<<"biaomianji:"<<4*PI*getr()*getr()<<endl;}
		void volume(){cout<<"tiji:"<<4*PI*getr()*getr()*getr()/3<<endl;}
};
class jux:public Shape
{
	public:
	jux(double i,double j){x=i,y=j;}
	void area(){cout<<"mianji:"<<x*y<<endl;}
	double getx(){return x;}
	double gety(){return y;}
	private:
		double x,y;
};
class cft:public jux
{
	public:
		cft(double i,double j,double k):jux(i,j){z=k;}
		void area(){cout<<"biaomianj:"<<2*(getx()*gety()+getx()*z+gety()*z)<<endl;}
		void volume(){cout<<"tiji:"<<getx()*gety()*z<<endl;}
	private:
		double z;
	};
		
int main()
{	circle a(3);
	ball b(3);
	jux c(2,2);
	cft d(2,2,2);
	a.area();
	b.area();
	b.volume();
	c.area();
	d.area();
	d.volume();
}
