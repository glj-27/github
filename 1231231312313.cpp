#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char a[20]="1234650";
	char b[20];
	char c[20]=".txt";
	strcpy(b,a);
	strcat(b,c);
	cout<<b;
} 
