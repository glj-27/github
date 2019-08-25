#include<iostream>
using namespace std;
int main()
{
	//终于等到你还好我没放弃！5555
    //数组的动态联编：
    int size;int m;
    cout<<"请输入数组成员个数："; 
	cin>>size;
	int *shuzu=new int [size];
	cout<<"请输入数组成员："; 
    for(int n=0;n<size;n++)
	{
		cin>>m;shuzu[n]=m;
	} 
	
	for(int n=0;n<size;n++)
	{
		cout<<shuzu[n]<<'\t';
	}
}
