#include<iostream>
#include<iomanip> 
using namespace std;
int main()
{
	int i,j,m,n;
	cout<<"�˽��� "<<'\t'<<"ʮ����"<<'\t'<<"ʮ������"<<endl;
	for(i=1;i<=100;i++)
	{
		cout<<binary<<i<<'\t';  
		cout<<oct<<i<<'\t';    
		cout<<dec<<i<<'\t';  
		cout<<hex<<i<<endl; 
	}
	
}
