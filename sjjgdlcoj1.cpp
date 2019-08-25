#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int n,p,i,j,m,k;
	char s;
	cin>>n;
	int *array=new int[n];
	memset(array,0,n*sizeof(int));
	for( i=0;i<n;i++)
	{
		scanf("%d%c",&m,&s);		
		p=k=m%n;
		for(j=1;array[p];j++)
		{
			p=(k+j)%n;
		}
		array[p]=m;
		
		if(s=='\n')
		break; 
	}
	for (i=0;i<n-1;i++)
	{
		if(array[i]==0)
		continue;
		cout<<i<<' '<<array[i]<<endl;
	}
	cout<<(n-1)<<' '<<array[n-1];
}


