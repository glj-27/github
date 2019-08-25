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
		int len=s.length()-1;
		int m=0;
		for(int i=0;i<=len;i++)
	    {
		  if(s[i]=='(') m++;
		  else if(s[i]==')')
		  {
		  	if(m==0)
		  	{
		  	   cout<<"FLASE"<<endl;
			   goto A;	
		  	}
		  	else m--;
		  }
		  if (m==0)cout<<"TRUE"<<endl;
	    }
	    A: ;
	}
	return 0;
} 
