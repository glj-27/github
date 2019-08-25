#include<iostream>
using namespace std;
int main()
{ 
int x,y,z,i;
	for( x=1; x<=9; x++ )
	  for( y=1; y<=9; y++ )
	    for( z=0; z<=9; z++ )
	     {
  i = 100*x + 10*y + z + 100*y + 10*z + z;
	        if ( i == 532 ) 
cout<<"x="<<x<<'\t'<<"y="<<y<<'\t'<<"z="<<z<<endl;
	      }
}

