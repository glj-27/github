#include<iostream>
using namespace std;
int main()
{ 
  char *weekday[7] = { "monday", "tuesday","wednesday", "thursday", "friday", "saturday","sunday" };
  int d;
  cout << "���������ڼ�: ";
  cin >> d;
  if( d>=0 && d<=7 )
  cout << d << "  " << *( weekday + d -1 ) <<endl;
  else
  cout << "�����" << endl;
}

