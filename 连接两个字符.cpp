#include<iostream>
using namespace std;
char *strcat( char *str1,char *str2 )
{
  char *p = str1;
  while( *p != '\0' ) p++;
  *p = *str2;
  do 
{  
    p++; 
    str2++;
    *p = *str2; 
} while( *str2 != '\0' );
  return( str1 );
}
int main()
{
  char str1[80], str2[80];
  cout << "input str1:"; 
  cin >> str1;
  cout << "input str2:";  
  cin >> str2;
  cout << "str1+str2=" << strcat( str1, str2 ) << endl;
}

