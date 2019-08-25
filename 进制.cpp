#include<iostream>
#include<iomanip> 
using namespace std;
int main()
{
	int i,j,m,n;
	cout<<"八进制 "<<'\t'<<"十进制"<<'\t'<<"十六进制"<<endl;
	for(i=1;i<=100;i++)
	{
		cout<<binary<<i<<'\t';  
		cout<<oct<<i<<'\t';    
		cout<<dec<<i<<'\t';  
		cout<<hex<<i<<endl; 
	}
	
}
