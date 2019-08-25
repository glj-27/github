#include<iostream>
using namespace std;
int fmin(int [], int);
int main()
{ 
  int a[ ] = { 73, 85, 62, 95, 77, 56, 81, 66, 90, 80 };
  int index;
  index = fmin( a, sizeof(a)/sizeof(int) );
  cout << "The minnum number is : " << a[index] << endl;
  cout << "The index is : " << index << endl;
}
int fmin( int a[], int size )
{ 
  int i,min = a[0], index = 0;
  for( i=0; i<size; i++ )
  if( a[i]<min )
  {
    min = a[i]; 
    index = i;
  }
  return index;
}

