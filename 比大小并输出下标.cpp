#include<iostream>
using namespace std;
int main()
{ 
  int a[] = { 38, 6, 29, 1, 0, 25, 26, 32, 78, 10 };
  int index[10];		                                                //记录下标的数组
  int i,j,temp;
  for( i=0; i<10; i++ )
  index[i] = i;
  for( i=0; i<=8; i++ )
  for( j=i+1; j<=9; j++ )
  if( a[i] < a[j] )
  { 
     temp = a[i]; a[i] = a[j]; a[j] = temp;
     temp = index[i]; index[i] = index[j]; index[j] = temp;
  }
  for( i=0; i<10; i++ ) 
  cout << a[i] << '\t' << index[i] << endl;
}

