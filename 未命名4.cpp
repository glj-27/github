#include<iostream>
using namespace std;
int main()
{
	long int a=10,b=20,t;         //定义三个整型变量 
	long int *p1=&a,*p2=&b,*pt;   //定义三个指针变量 
	cout<<p1<<'\t'<<p2<<endl;     //输出a，b的地值 
	cout<<*p1<<'\t'<<*p2<<endl;   //输出a，b的值 
	t=*p1;*p1=*p2;*p2=t;          //交换a，b的值 
	cout<<*p1<<'\t'<<*p2<<endl;   //输出交换的值 
	pt=p1;p1=p2;p2=pt;            //交换地址 
	cout<<p1<<'\t'<<p2<<endl;     //输出交换后的地址 
	cout<<*p1<<'\t'<<*p2<<endl;   //输出现在所代表的值 
	cout<<a<<'\t'<<b<<endl;       //输出原来a，b所代表的值 
}
