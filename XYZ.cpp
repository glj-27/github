#include<iostream>
using namespace std;
int main()
{
	int X,Y,Z;
	for(X=0;X<=9;X++)
	for(Y=0;Y<=9;Y++)
	for(Z=0;Z<=9;Z++)
	{
		if(X*100+Y*10+Z+Y*100+Z*10+Z==532)
		cout<<"X="<<X<<endl<<"Y="<<Y<<endl<<"Z="<<Z;
	}
}
