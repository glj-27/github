#include<iostream>
#include<cmath>	
#include <cstdlib>
#include<ctime>
using namespace std;
int main()
{ 
  int a[10],i,j;
  srand( int( time(0)) );      	//为随机数生成器设置种子值
  for( i=0; i<10; i++ )
  {
       l: a[i] = rand();    		//产生随机数存放到数组中
       if ( a[i]<10 || a[i]>=100 ) 		//获取指定范围数据
       goto l; 
	   for( j=0; j<i; j++ )				//排除相同数据
       if( a[i]==a[j] ) 
       goto l;
  }
  for( i=0; i<10; i++ )
  cout << a[i] << "   ";
  cout << endl;
  for( i=0; i<10; i++ )
  { 
     double m=sqrt( double (a[i]) );
     for( j=2; j<=m; j++)
     if( a[i] % j == 0 )break;
     if( j>m )
     cout << a[i] << "   ";
  }
  cout << "是素数！" << endl;
}

