#include<iostream>
using namespace std;
void insert( int a[],int,int );
int main()
{
  int a[] = { 10, 12, 23, 25, 48, 48, 53, 58, 60, 78 };
  int x,n,i;
  cout << "������һ��ֵ: ";
  cin >> x;
  n = sizeof(a)/sizeof(int);		                                //�����鳤��
  insert( a, n, x );			                                    //����Ԫ��
  for( i=0; i<n; i++ )
  cout << a[i] << "   ";
  cout << endl;
}
void insert( int a[],int n,int x )
{
  int i,p,j;
  if ( x<a[n-1] )
  {
    for( i=1; i<n; i++ )	                                        //���Ҳ���λ��
    if( x<a[i] )
    {
     p=i; break; 
    }
	for( j=n-1; j>=p; j-- )		                                    //����Ԫ�أ��������ֵ
	a[j] = a[j-1];
	a[p] = x;					                                    //����Ԫ��
  }
}

