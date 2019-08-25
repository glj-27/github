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
		int i=s.length()-1;
		for(i;i>=0;i--)
	    {
		   cout<<s[i];
		   
	    }
	    cout<<endl;
	}
	return 0;
} 
