#include<iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main()
{
	int m,n,l;
	cout<<"������1 2 3:"; 
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
				cout<<"һ�����������߰˾�"; 
			}
		break;
		case 3:
		    {
		    	system("cls");
		    	cout<<"���������";
				getch();
				return(0); 
		    }	
	  }
    }
}
