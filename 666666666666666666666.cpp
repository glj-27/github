#include<iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main()
{
	int m,n,l;
	cout<<"请输入1 2 3:"; 
	while(cin>>n)
	{
	  switch(n)
	  {
		case 1:
			{
				cout<<"123456789";
			}
		break;
		case 2:
			{
				system("cls");
				cout<<"一二三四五六七八九"; 
			}
		break;
		case 3:
		    {
		    	system("cls");
		    	cout<<"输入任意键";
				getch();
				return(0); 
		    }	
	  }
    }
}
