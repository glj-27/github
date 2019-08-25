#include<iostream>
using namespace std;
int main()
{   
    int a,n,i;
    cin>>a;
	for(n=0;a>=1;a/10)
		{
		 i=n%10;n=n*10+i;
		}return n;
	cout<<n;
}

