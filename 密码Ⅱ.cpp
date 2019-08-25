#include<iostream>
using namespace std;
int main()
{
	char c;
	{
	 if(c>=97&&c<=122)
	 {
	  if((c-'a'+1+4)%26==0) c=char(26+96)£» 
	  else c=(char)((c-'a'+1+4)%26+96)£» 
     }
     if(c>=65&&c<=90)
     {
	  if((c-'A'+1+4)%26==0) c=char(26+64)£» 
	  else c=(char)((c-'A'+1+4)%26+64)£» 
     }
	 cout<<c;
    }
}
