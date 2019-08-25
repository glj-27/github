#include<iostream>
using namespace std;
int main()
{ 
  long s[][3] = { { 300, 250, 150 }, { 200, 240, 200},{ 280, 210, 180 } };
  long p[] = { 3500, 3300, 3800 };
  int i,j;
  double sum;
  for( i=0; i<3; i++ )
  { 
    sum=0;
    for( j=0; j<3; j++)
    sum += s[i][j] * p[j];
    cout << "第" << i+1 << "百货公司的电视机营业额:  " << sum << endl;
  }
}

