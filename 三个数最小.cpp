#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c; 
    if(a>b) cout<<min(b,c);
	else cout<<min(a,c);

} 
