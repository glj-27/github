#include<iostream>
using namespace std;
int main()
{
	char a,b;
	cout<<"请出拳："; 
	cin>>a>>b;
	if(a=='s')
	{
	 if(b=='s') cout<<"平局";
	 if(b=='r') cout<<"b赢";
	 if(b=='p') cout<<"a赢";
	}
	if(a=='r')
	{
	 if(b=='s') cout<<"a赢";
	 if(b=='r') cout<<"平局";
	 if(b=='p') cout<<"b赢";	
	}
	if(a=='p')
	{
	 if(b=='s') cout<<"b赢";
	 if(b=='r') cout<<"a赢";
	 if(b=='p') cout<<"平局";
    }
} 
