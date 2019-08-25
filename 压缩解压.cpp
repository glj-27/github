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
	cout<<"请输入数组长度：";
	cin>>n;
	ary = new int [n];				                                             //建立动态数组
	packary = new unsigned char[n];		                                         //压缩数组
    srand(int(time(0)));
	for(i=0;i<n;i++)					                                         //产生随机数并存放到动态数组中
	ary[i]=rand()/255; 
	pack( ary, packary, n );
	cout<<"\n输出压缩数组："; 
	for( i=0; i<n; i++ )
	{
	   if (i %10 == 0)  cout<<endl;		                                         //控制一行输出10个数据
	   cout << int( packary[i] ) <<"  ";
	}
	unpack( packary, ary, n);
	cout<<"\n输出解压数组："; 
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

