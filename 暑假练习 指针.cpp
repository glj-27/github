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
	*bigbig=* bigbig+1;
	cout<<"Now *bigbig value="<<* bigbig<<endl;
	cout<<"Now big value="<<big<<endl<<endl;
	
	int* normal;
	*normal=5;
	cout<<"* normal value="<<* normal<<endl;
	cout<<"* normal address="<<normal<<endl<<endl; 
	//�ȶ���ָ�룬ϵͳֻ������ָ���ַ�������ָ����ָ���ֵ�����ַ�����׳����޷����ҵ�bug.
	
	int a=100;double b=50;
	b=(double)a;
	cout<<"b value="<<b<<endl;
	//ǿ��ת���������͡�
	int* c;
	c=&a;
	cout<<"c value="<<* c<<endl;
	cout<<"*c address="<<c<<endl; 
	c=(int*)0xb5fd5c;
	//������big�ĵ�ַǿ�Ƹ�ֵ��c. 
	cout<<"NOW *c address="<<c<<endl;
	cout<<"NOW c value="<<* c<<endl<<endl;  
	/*��ȻcΪ����ָ����������ֱ�Ӱ�������ֵ��c����Ȼ������������ȴ������ͬ�ĸ��������ͨ��ǿ��ת
	�������������ָ�븳ֵ��*/ 
	
	int* pt=new int;
	//�ڳ�������ʱ�Ŷ����ݶ�������ڴ档 
	*pt=1001;
	double* pd=new double;
	*pd= 10001.1;
	cout<<"int value="<<*pt<<";location="<<pt<<endl;
	cout<<"double value="<<*pd<<";location="<<pd<<endl;
	cout<<"location of pointer pt="<<&pt<<endl;
	cout<<"location of pointer pd="<<&pd<<endl;
	cout<<"size of pt="<<sizeof(pt)<<";size of *pt="<<sizeof(*pt)<<endl;
	cout<<"size of pd="<<sizeof(pd)<<";size of *pt="<<sizeof(*pt)<<endl<<endl;
	
	int* ab=new int;
	*ab=100;
	cout<<"int value="<<*ab<<";location of int="<<ab<<";location of pointer ab="<<&ab<<endl;
	delete ab;
	//Ϊ�˷�ֹ�ڴ�й©����delete�ͷ�ָ����ָ����ڴ棬������ɾ��ָ�뱾�� 
	cout<<"int value="<<*ab<<";location of int="<<ab<<";location of pointer ab="<<&ab<<endl<<'\n';
	
	double* sz=new double [3];
	sz[0]=0.27;
	sz[1]=2.7;
	sz[2]=27;
	cout<<"sz[0]="<<sz[0]<<'\t'<<"sz[1]="<<sz[1]<<'\t'<<"sz[2]"<<sz[2]<<endl;
	sz=sz+1;
	cout<<"sz[0]="<<sz[0]<<'\t'<<"sz[1]="<<sz[1]<<'\t'<<"sz[2]"<<sz[2]<<'\t'<<"sz[-1]"<<sz[-1]<<endl;
	sz=sz-1;
	cout<<"pointer notation of array sz[]:"<<endl;
	//new�����ֱ�ӷ���δ�������ڴ��ַ�� 
	cout<<&sz[0]<<'\t'<<&sz[1]<<'\t'<<&sz[2]<<'\n'<<'\n';
	delete [] sz;
	
	/*ָ��С�᣺��ָ�븳ֵʱ��Ӧ�����ڴ��ַ����ָ�룬û��ʹ��newʱ��Ӧ��&����ڴ��ַ��ʹ��newʱ��
	  new�������ֱ�ӷ���δ�������ڴ��ַ��*/ 
	
	 
}
