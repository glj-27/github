#include<iostream>
using namespace std;
void create( int *&app, int n );
void del( int *&app, int *&bpp, int n );
int maindiagonal( int *&app, int n );
void output( int *&app, int );
int main()
{ 
  int *ap = NULL, *bp = NULL, n; 
  cout << "输入矩阵的阶：";
  cin >> n;
  create( ap,n );
  cout << "\n形成矩阵：\n";
  output( ap, n );
  cout << "去掉靠边元素生成的矩阵：\n";
  del( ap,bp,n );
  output( bp,n-2 );
  cout << "主对角线元素之和：" << maindiagonal( ap, n ) <<endl;
}                                                                                 //形成n阶矩阵函数
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
}                                                                                  //去掉靠边元素生成n-2阶矩阵函数
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
                                                                                  //求主对角线元素之和函数
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
}                                                                                 //以方阵的形式输出数组函数
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

