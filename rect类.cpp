#include<iostream>
using namespace std;
class rect
{
	public:
		rect(int l,int w,int h)
		{length=l;width=w;height=h;}
		int area()
        {return length*width*2+length*height*2+width*height*2;}
	private:
		int length,width,height;
};

int main()
{
	int l,w,h;
	while(cin>>l>>w>>h)
	{
		rect rect1(l,w,h);
		cout<<rect1.area()<<endl;
	}
}
