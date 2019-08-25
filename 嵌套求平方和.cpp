#include<iostream>
using namespace std;
int fun1(int m)
{
	return m*m; 
}
int fun2(int x,int y)
{
	return fun1(x)+fun1(y);
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<fun2(a,b)<<endl;
}
