#include<iostream>
#include<cmath>	
using namespace std;
void aveMsd( double [], int, double &, double & );
int main()
{ 
double s[] = { 76, 85, 54, 77, 93, 83, 90, 67, 81, 65 };
double ave, msd;
int i,n;
n = sizeof( s )/sizeof( double );
cout<<"ѧ���ɼ���";
for( i=0; i<n; i++ )
  cout<<s[i]<<"  ";
cout<<endl;
aveMsd( s, n, ave, msd );
cout << "ƽ��ֵ��" << ave << endl << "������ֵ��" << msd << endl;
}
void aveMsd( double s[], int n, double &ave, double &msd )
{ 
int i;
double sum1=0, sum2=0;
for( i=0; i<n; i++ )	
   sum1 += s[i];
ave = sum1/n;
for( i=0; i<n; i++ )	
   sum2 += pow( s[i]-ave, 2 );
msd = sqrt( sum2/n );
}

