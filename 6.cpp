#include<iostream>
using namespace std;
void sort( double x,double y );
void sort( double x,double y,double z );
int main()
{ 
	sort( 5.6, 79 );
	sort( 0.5, 30.8, 5.9 );
}
void sort(double x,double y)
{ 
	if ( x>y ) 
		cout << x << '\t' << y << endl;
	else 
		cout << y << '\t' << x << endl;
}
void sort( double x,double y,double z )
{ 
	double t;
	if( y<z ) { t = y; y = z; z = t; }
	if( x<z ) { t = x; x = z; z = t; }
	if( x<y ) { t = x; x = y ;y = t; }
	cout << x << '\t' << y << '\t' << z << '\t' << endl;
}

