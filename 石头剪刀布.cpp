#include<iostream>
using namespace std;
int main()
{
	char a,b;
	cout<<"���ȭ��"; 
	cin>>a>>b;
	if(a=='s')
	{
	 if(b=='s') cout<<"ƽ��";
	 if(b=='r') cout<<"bӮ";
	 if(b=='p') cout<<"aӮ";
	}
	if(a=='r')
	{
	 if(b=='s') cout<<"aӮ";
	 if(b=='r') cout<<"ƽ��";
	 if(b=='p') cout<<"bӮ";	
	}
	if(a=='p')
	{
	 if(b=='s') cout<<"bӮ";
	 if(b=='r') cout<<"aӮ";
	 if(b=='p') cout<<"ƽ��";
    }
} 
