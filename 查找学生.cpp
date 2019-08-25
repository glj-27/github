#include<iostream>
using namespace std;
int main()
{ 
  char name[5][20] = { "li ming", "彭少辰", "liu xiao ping", "wang ying", "lu pei" };
  long num[5] = { 20170001, 20170002, 20170005, 20170007, 20170010 };
  int i;
  long snumber;
  cout << "请输入学号:";
  cin >> snumber;
  for( i=0; i<5; i++ )
  {
     if( num[i] == snumber )
     {
      cout << "他的名字是:" << name[i] << endl;
	  break; 
     }
  }
  if( i==5 )  cout << "找不到！" << endl;
}

