#include<iostream>
using namespace std;
struct Point
{
	double x,y;
}; 
class Line
{
	public:
		Line(double i,double j)
		{
			a=i;b=j;
		}
		void print()
		{
			cout<<"y="<<a<<"x+"<<b;
		}
		friend Point setPoint(Line &l1,Line &l2)
		{
			Point p;
            p.x=( l2.b-l1.b )/( l1.a-l2.a );
            p.y=( l1.a*l2.b-l2.a*l1.b)/(l1.a-l2.a );
            return p;
		}
	private:
		double a,b;
}; 
int main()
{
	Point setp;
	Line l1(3,6);Line l2(4,8);
	cout<<"ֱ��l1��";l1.print();cout<<endl;
	cout<<"ֱ��l2��";l2.print();cout<<endl;
	setp=setPoint(l1,l2);
	cout<<"��ֱ�߽���Ϊ����"<<setp.x<<","<<setp.y<<")"<<endl; 
	
}
