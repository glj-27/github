#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	int i=0;
	char ch;
	char a[999999];	
	while ( ( ch=getchar() )!=EOF )
	{
		a[ ++ i ] = ch;
	}
	for (int j=1;j<=i;j++)
	{
		cout<<a[i];;
		
	}
	
}
