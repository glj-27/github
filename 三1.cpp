#include<iostream>
#include<cmath>	
using namespace std;
double sh( double t );
int main()
{ 
	double x,y;
	cout << "x=";
	cin >> x;
	y = sh( 1+sh(x) )/( sh( 2*x )+sh( 3*x ) );
	cout << "y=" << y << endl;
}
double sh( double t )
{  
	return ( exp( t )-exp( -t ) )/2; 
}

