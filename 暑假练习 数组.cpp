#include<iostream>
using namespace std;
int main()
{
	//���ڵȵ��㻹����û������5555
    //����Ķ�̬���ࣺ
    int size;int m;
    cout<<"�����������Ա������"; 
	cin>>size;
	int *shuzu=new int [size];
	cout<<"�����������Ա��"; 
    for(int n=0;n<size;n++)
	{
		cin>>m;shuzu[n]=m;
	} 
	
	for(int n=0;n<size;n++)
	{
		cout<<shuzu[n]<<'\t';
	}
}
