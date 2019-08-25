#include<iostream>
#inlcude<cmath>
using namespace std;
void sushu(int a)
{
    int* list=new int [a];
    int x=0;
    for(int i=3;i<=a;i++)
    {
    	for(int j=3;j<i;i++)
    	{
    		if(i%j!=0)list[x++]=i;
    		else break;
    	}
    }
    return list[x];
}
int main()
{
	int n,m;
	cin>>n;
	m=sqrt(n);
	sushu(m);
	for(int i=0;i<=m;i++)
	{
		if
	}
	cout<<n;
} 
