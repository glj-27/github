#include<iostream>
using namespace std;
int add(int x=2,int y=7)   //带默认值的参数只能放在最右边（int x，int y=10） 
{
	return x+y;
}
int main()
{
	cout<<add(27,72)<<endl;
	cout<<add(27)<<endl;   //赋值从左到右 
	cout<<add()<<endl;
}
