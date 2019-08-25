#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
int main()
{
	srand( (unsigned)time(NULL) );
	int st=1+( rand() )%99;
	int n=-1;
	//cout<<st;
	while (n!=st)
	{
		cout<<"请输入数字"<<endl;
		cin>>n;
		if (n>st) cout<<"少辰是猪"<<endl ;
		if (n<st) cout<<"少辰是GAY"<<endl ;
		if (n==st) cout<<"RIGHT"<<endl; 
	}
	
	
} 
