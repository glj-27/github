#include<iostream>
using namespace std;
int fib(int n); 
int main()
{
	int n,answer;
	cout<<"第几个数：";
	cin>>n; 
	answer=fib(n);
	cout<<"这个数为："<<answer;
}
int fib(int n)
{
	if(n<3)
	{return (1);} 
	else 
	{return(fib(n-1)+fib(n-2));} 
}
 
