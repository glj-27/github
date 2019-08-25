#include<iostream>
using namespace std;
const double PI=3.14159;
class Circle
{
	public:
		Circle(double radius=0){r=radius;}
		virtual double area(){};
		virtual double volume(){};
	protected:
		double r;
};
class Sphere:public Circle
{
	public:
		Sphere(double radius):Circle(radius){};
		double area(){	cout<<"��ı����"<<4*PI*r*r<<endl;}
		double volume(){	cout<<"������"<<4*PI*r*r*r/3<<endl; }
};
class Column:public Circle
{
	public:
		Column(double radius,double height){r=radius;h=height;}
		double area(){	cout<<"Բ���ı����"<<2*PI*r*r+2*PI*r*h<<endl;}
		double volume(){	cout<<"Բ�������"<<PI*r*r*h<<endl;}
	protected:
		double h;
};
int main()
{
	Sphere sp(2.7);
	Column co(2.7,2.7);
	Circle *pi;
	pi=&sp;
	pi->area();
	pi->volume();
	pi=&co;
	pi->area();
	pi->volume();
	
}
