#include<iostream>
using namespace std;
class student 
{
	public:
	char name;
	void people()
	{
		cout<<"nixiangshuhosah!";
	
	} 
	void man()
		{
			people();
			char m;
			cin>>m;
			name=m;
			cout<<name;
		}
};
int main()
{
	student eee;
	eee.man();
}
