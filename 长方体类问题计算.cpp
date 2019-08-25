#include<iostream>
using namespace std;
class rect
{
	private:
		int length,width,height;
	public:
		void rect(length,width,height);
	    void area();
} ;
void rect::rect(int l,int w,int h){l=length;w=width;h=height;}
void rect::area()
int main()
{
	rect rect1;
	int l,w,h;
	while(cin>>l>>w>>h)
	{
		rect1.rect();
		cout<<rect1.area<<endl;
	}
}

