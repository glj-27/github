#include <iostream>
#include <cmath>
using namespace std;
struct point
{
 double x;
 double y; 
};
double d( point p1, point p2 )
{
  return sqrt( pow( p1.x-p2.x,2 )+pow( p1.y-p2.y,2 ) ); 
}
int main()
{
  int i;  point p[5];
   for( i=1; i<=4; i++ )
    { cout << "输入第" << i << "个顶点的横坐标和纵坐标: ";
      cin >> p[i].x >> p[i].y;  
}
   if( fabs( d( p[1],p[2] ) - d( p[3],p[4] ))<=1e-8
        && fabs( d( p[1],p[4] ) - d( p[2],p[3] ))<=1e-8
        && fabs( d( p[1],p[3] ) - d( p[2],p[4] ))<=1e-8)
     if( fabs( d( p[1],p[2] ) - d( p[2],p[3] ))<1e-8 )
         cout << "四个顶点构成的图形为正方形！" << endl;
     else cout << "四个顶点构成的图形为矩形！" << endl;
  else cout << "四个顶点构成的图形为其它四边形！" << endl;
}

