#include<cstdio>
#include<iostream> 
#define max 1000
using namespace std;
int main()
{
	int i,k,n,m,num[max],*p,x;
	cin>>n;
	cin>>x;
	p=num;
	for(i=0;i<n;i++)
		*(p+i)=i+1;
	i=0;k=0;m=0;
	while(m<n-1)
	{
		if(*(p+i)!=0)
			k++;
		if(k==x)
		{
			*(p+i)=0;
			m++;
			k=0;
		}
		i++;
		if(i==n)
			i=0;
	}
	for(i=0;i<n;i++)
		if(*(p+i)!=0)
		 cout<<*(p+i)<<endl;
	return 0;
}

