#include<iostream>
#include<cstring>
using namespace std;
int main()
{
  char string[10];
  char str[][10]={ "while", "break", "if", "extern", "void", "auto", "long", "static", "do", "const" };
  int i;
  strcpy_s(string,str[0]);
  for( i=0; i<10; i++ )
  if( strcmp(str[i],string)<0 ) strcpy_s( string, str[i] );
  cout << "The minimum string is:" << string << endl;
}

