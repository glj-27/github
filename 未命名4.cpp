#include<iostream>
using namespace std;
int main()
{
	long int a=10,b=20,t;         //�����������ͱ��� 
	long int *p1=&a,*p2=&b,*pt;   //��������ָ����� 
	cout<<p1<<'\t'<<p2<<endl;     //���a��b�ĵ�ֵ 
	cout<<*p1<<'\t'<<*p2<<endl;   //���a��b��ֵ 
	t=*p1;*p1=*p2;*p2=t;          //����a��b��ֵ 
	cout<<*p1<<'\t'<<*p2<<endl;   //���������ֵ 
	pt=p1;p1=p2;p2=pt;            //������ַ 
	cout<<p1<<'\t'<<p2<<endl;     //���������ĵ�ַ 
	cout<<*p1<<'\t'<<*p2<<endl;   //��������������ֵ 
	cout<<a<<'\t'<<b<<endl;       //���ԭ��a��b�������ֵ 
}
