#include<iostream>
#include<cmath>	
#include <cstdlib>
#include<ctime>
using namespace std;
int main()
{ 
  int a[10],i,j;
  srand( int( time(0)) );      	//Ϊ�������������������ֵ
  for( i=0; i<10; i++ )
  {
       l: a[i] = rand();    		//�����������ŵ�������
       if ( a[i]<10 || a[i]>=100 ) 		//��ȡָ����Χ����
       goto l; 
	   for( j=0; j<i; j++ )				//�ų���ͬ����
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
  cout << "��������" << endl;
}

