#include<iostream>
using namespace std;
void create( int *&app, int n );
void del( int *&app, int *&bpp, int n );
int maindiagonal( int *&app, int n );
void output( int *&app, int );
int main()
{ 
  int *ap = NULL, *bp = NULL, n; 
  cout << "�������Ľף�";
  cin >> n;
  create( ap,n );
  cout << "\n�γɾ���\n";
  output( ap, n );
  cout << "ȥ������Ԫ�����ɵľ���\n";
  del( ap,bp,n );
  output( bp,n-2 );
  cout << "���Խ���Ԫ��֮�ͣ�" << maindiagonal( ap, n ) <<endl;
}                                                                                 //�γ�n�׾�����
void create( int * &app, int n )
{ 
  app = new int[ n*n ];
  int i,j,k = 0; 
  for( i=0; i<n; i++ )
  for( j=0; j<n; j++ )
  {
    if( i<=j ) 
    app[k] = 1;
    else
    app[k] = i-j+1;
    k++; 
  }
}                                                                                  //ȥ������Ԫ������n-2�׾�����
void del( int *&app, int *&bpp, int n )
{
  int i,j,k = 0;
  bpp = new int[ ( n-2 )*( n-2 ) ];
  for ( i=0; i<n; i++ )
  { 
   for( j=0; j<n; j++ )
   if ( i && j && i<n-1 && j <n-1 )
   {
      bpp[k]= *( app + i*n + j );    
	  k++;
   }
  }
}
                                                                                  //�����Խ���Ԫ��֮�ͺ���
int maindiagonal( int *&app, int n )
{ 
  int i,j,k = 0,sum = 0;
  for ( i=0; i<n; i++ )
  {
    for( j=0; j<n; j++ )
	if( i==j )
    sum += *( app + i*n + j);
  }
  return sum;
}                                                                                 //�Է������ʽ������麯��
void output( int *&app, int n )
{
  int i,j;
  for ( i=0; i<n ; i++ )
  { 
    for( j=0; j<n; j++ )
	cout << *( app + i*n + j) <<  '\t';
    cout<<endl;
  }	
  cout<<endl;
}

