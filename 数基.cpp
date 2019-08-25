#include<iostream>
using namespace std;
int main()
{
	int N,i;int a=1;
	cin>>N;
	int n[N];
	for(i=0;i<N;i++)
	{
		n[i]=a;
		a++;
	}
	cout<<n[4]<<n[5]<<n[6];
} 
