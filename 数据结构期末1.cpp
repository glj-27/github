#include<iostream>
using namespace std;
void me(int *n1,int N1,int *n2,int N2,int *ma)
{
	for(int i=0;i<N1;i++)
	{
		ma[i]=n1[i];
	}
	for(int i=N1-1;i<N1+N2;i++)
	{
		ma[i]=n2[i-(N1-1)];
	}
	for(int j=0;j<N1+N2-1;j++)
	{
		int e=0;
		if(ma[j]>ma[j+1])
		{
			e=ma[j];ma[j]=ma[j+1];ma[j+1]=e;
		}
	}
}
int main()
{
	int M;
	cin>>M;
	while(M--)
	{
		int N1,N2;
		cin>>N1>>N2;
		int *n1=new int[N1],*n2=new int[N2],*ma=new int[N1+N2];
		for(int i=0;i<N1;i++)
		{
			cin>>n1[i];         //0~N1-1
		}
		for(int i=0;i<N2;i++)
		{
			cin>>n2[i];         //0~N2-1
		}
		me(n1,N1,n2,N2,ma);
		cout<<ma[0];
		for(int i=1;i<N1+N2;i++)
		{
			cout<<" "<<ma[i];
		}
		cout<<endl;
	}
} 
