#include<iostream>
using namespace std;
int main()
{
	int n,i=0,j=0,k;
	cin>>k;
	
	for (int ii=1;ii<=k;ii++)
	{
		cin>>n;
		if(n>0){i++;}
		else if(n<0){j++;}
    }
    cout<<"������"<<i<<endl<<"������"<<j<<endl; 
    return 0;
}

