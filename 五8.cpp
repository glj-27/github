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
    { cout << "�����" << i << "������ĺ������������: ";
      cin >> p[i].x >> p[i].y;  
}
   if( fabs( d( p[1],p[2] ) - d( p[3],p[4] ))<=1e-8
        && fabs( d( p[1],p[4] ) - d( p[2],p[3] ))<=1e-8
        && fabs( d( p[1],p[3] ) - d( p[2],p[4] ))<=1e-8)
     if( fabs( d( p[1],p[2] ) - d( p[2],p[3] ))<1e-8 )
         cout << "�ĸ����㹹�ɵ�ͼ��Ϊ�����Σ�" << endl;
     else cout << "�ĸ����㹹�ɵ�ͼ��Ϊ���Σ�" << endl;
  else cout << "�ĸ����㹹�ɵ�ͼ��Ϊ�����ı��Σ�" << endl;
}

