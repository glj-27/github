#include<iostream>
using namespace std;
int add(int x=2,int y=7)   //��Ĭ��ֵ�Ĳ���ֻ�ܷ������ұߣ�int x��int y=10�� 
{
	return x+y;
}
int main()
{
	cout<<add(27,72)<<endl;
	cout<<add(27)<<endl;   //��ֵ������ 
	cout<<add()<<endl;
}
