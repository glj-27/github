#include<iostream>
using namespace std;
int fib(int n); 
int main()
{
	int n,answer;
	cout<<"�ڼ�������";
	cin>>n; 
	answer=fib(n);
	cout<<"�����Ϊ��"<<answer;
}
int fib(int n)
{
	if(n<3)
	{return (1);} 
	else 
	{return(fib(n-1)+fib(n-2));} 
}
 
