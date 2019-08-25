#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string s;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>s;
		int len=s.size();
		int m=0,i=0;
		for(i;i<=len;i++)
		{
			if(s[i]=='(')
			m++;
			else if(s[i]==')')
			{
				if(m==0)
				{
				  cout<<"FALSE"<<endl;goto A;
				}
				else m--;
			}
		}
		if(m==0)
		cout<<"TRUE"<<endl;
		else cout<<"FALSE"<<endl; 
		A:;
	} 
} 
