#include<iostream>
#include<cstring> 
using namespace std;
class animal
{
	public:
		string voice;
}; 
class Cat:public animal
{
	public:
		void sound()
		{
			voice="miao";
			cout<<voice<<endl;
		}
};
class Dog:public animal
{
	public:
		void sound()
		{
			voice="wang";
			cout<<voice<<endl;
		}
};
class Frog:public animal
{
	public:
		void sound()
		{
			voice="gua";
			cout<<voice<<endl;
		}
};
int main()
{
	string a;
	while(cin>>a)
	{
		if(a=="cat")
		{
			Cat cat;
			cat.sound();
		}
		if(a=="dog")
		{
			Dog dog;
			dog.sound();
		}if(a=="frog")
		{
			Frog frog;
			frog.sound();
		}
	}
}


