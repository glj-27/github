#include<iostream>
using namespace std;
int main()
{
	int big=5;
	double small=1.5;
	cout<<"big value="<<big<<endl;
	cout<<"big address="<<&big<<endl;
	cout<<"small value="<<small<<endl;
	cout<<"small address="<<&small<<endl<<endl;
	
	int* bigbig;
	bigbig=&big;
	cout<<"big value="<<big<<endl;
	cout<<"*bigbig value="<<* bigbig<<endl;
	cout<<"big address="<<&big<<endl;
	cout<<"*bigbig address="<<bigbig<<endl;
	* bigbig=* bigbig+1;
	cout<<"Now *bigbig value="<<* bigbig<<endl;
	cout<<"Now big value="<<big<<endl<<endl;
	
	int* normal;
	* normal=5;
	cout<<"* normal value="<<* normal<<endl;
	cout<<"* normal address="<<normal<<endl<<endl; 
	//�ȶ���ָ�룬ϵͳֻ������ָ���ַ�������ָ����ָ���ֵ�����ַ�����׳����޷����ҵ�bug.
	
	int a=100;double b=50;
	b=(double)a;
	cout<<"b value="<<b<<endl;
	int* c;
	c=&a;
	cout<<"c value="<<* c<<endl; 
	c=(int*)0xb8000000;
	cout<<"*c address="<<c<<endl;
	//cout<<"NOW c value="<<* c<<endl<<endl; 
	//ǿ��ת���������͡�
	//��ȻcΪ����ָ����������ֱ�Ӱ�������ֵ��c����Ȼ������������ȴ������ͬ�ĸ��������ͨ��ǿ��ת�������������ָ�븳ֵ�� 
	
	 
}
