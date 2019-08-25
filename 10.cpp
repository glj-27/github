#ifndef FABRIC
#define FABRICATE_H
int Fabricate( int m,int n );
int Multi( int m, int n );
#endif
#include<iostream>
using namespace std;
#include "Fabricate.h"
int main()
{ 
	int m ,n;
	cout << "input m and n:";
	cin >> m >> n;
	cout << "Fabricate(" << m << "," << n << ")=" << Fabricate( m, n ) << endl;
}
#include "Fabricate.h"
int Fabricate( int m, int n )
{ 
	return Multi( m, m-n + 1 ) / Multi( n, 1 );
}
int Multi( int m, int n )
{ 
	int i, t = 1;
	for( i=n; i<=m; i++ )
	t = t * i;
	return t;
}

