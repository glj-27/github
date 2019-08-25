#include<iostream>
using namespace std;
class Box 
{
	private:
		double length,width,height;
	public:
		Box(double l,double w,double h)
		{
	    	length=l;width=w;height=h;
	    }
		void setBox(double l,double w,double h)
	    {
	    	length=l;width=w;height=h;
	    }
		void volume()
		{
			cout<<"volume="<<length*width*height<<endl;
		}
}; 
int main()
{
	Box Box1(3,4,5);
	Box1.volume();
	Box Box2(3,4,5);
	Box2.setBox(5,6,7);
	Box2.volume();
}
