#include<iostream>
using namespace std;
int main()
{
	int n,r,a,b,s;
	const double p=3.1415; 
	cout<<"1 Բ�Σ�2 �����Σ�3 ������ :";
	cin>>n;
	switch(n)
	{
		case 1: 
		cout<<"Բ�εİ뾶��";
		cin>>r;s=p*r*r;
		cout<<"Բ�ε������"<<s;
		break;
		case 2:
		cout<<"�����εı߳���";
		cin>>a>>b;s=a*b;
		cout<<"�����ε������"<<s;
		break;
		case 3:
		cout<<"�����εı߳���";
		cin>>a;s=a*a;
		cout<<"�����ε������"<<s;
		break;
	} 
	cout<<endl;
} 
