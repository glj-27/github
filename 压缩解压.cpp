#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
void pack( int *a, unsigned char *p, int n );
void unpack( unsigned char *p, int *a, int n );
int main()
{ 
	int *ary, n, i;
	unsigned char *packary;
	cout<<"���������鳤�ȣ�";
	cin>>n;
	ary = new int [n];				                                             //������̬����
	packary = new unsigned char[n];		                                         //ѹ������
    srand(int(time(0)));
	for(i=0;i<n;i++)					                                         //�������������ŵ���̬������
	ary[i]=rand()/255; 
	pack( ary, packary, n );
	cout<<"\n���ѹ�����飺"; 
	for( i=0; i<n; i++ )
	{
	   if (i %10 == 0)  cout<<endl;		                                         //����һ�����10������
	   cout << int( packary[i] ) <<"  ";
	}
	unpack( packary, ary, n);
	cout<<"\n�����ѹ���飺"; 
	for( i=0; i<n; i++ )
	{
	   if (i %10 == 0)  cout<<endl;  
	   cout<<ary[i]<<"  ";
	} 
}
void pack( int *a, unsigned char *p, int n )
{
	for(int i=0; i<n; i++)
	{
	   p[i] = (unsigned) char(a[i]) ;
	}
}
void unpack( unsigned char *p, int *a, int n )
{
	for(int i=0; i<n; i++)
	{
	   a[i] = int(p[i]);
	}
}

