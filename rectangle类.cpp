#include<iostream>
#include<cmath>
using namespace std;
class point
{
	public:
	    int x,y;
};
class rectangle
{
    public:
		point P1,P2;
		void print(point &P1,point &P2); 
        int area(point &P1,point &P2);
		
};
void rectangle::print(point &P1,point &P2)
{
	cout<<"1:("<<P1.x<<","<<P1.y<<")"<<endl;
	cout<<"2:("<<P2.x<<","<<P1.y<<")"<<endl;
	cout<<"3:("<<P1.x<<","<<P2.y<<")"<<endl;
	cout<<"4:("<<P2.x<<","<<P2.y<<")"<<endl;
}
int rectangle::area(point &P1,point &P2)
{
	cout<<abs((P2.x-P1.x)*(P1.y-P2.y))<<endl;
}
int main()
{
	int n;
	cin>>n;
	point P1,P2;
	rectangle r1;
	while(n--)
	{
		cin>>P1.x>>P1.y>>P2.x>>P2.y;
		r1.print(P1,P2);
		r1.area(P1,P2);
	}
}

