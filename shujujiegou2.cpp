#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack <char>stk;
	string s;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>s;
		int m=s.length();
		for(int i=0;i<=m;i++)
		{
			if(s[i]=='(')
			{
				stk.push(s[i]);
				
			}
			else if(s[i]==')')
			{
				if(stk.top()=='(')
				{
					stk.pop();
				}
				else 
				{
					cout<<"FLASE"<<endl;
					goto A;
				}
			}
		}
		cout<<"TRUE"<<endl;	
	A: ; 
	}
}

