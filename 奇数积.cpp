#include<iostream>
using namespace std;
int main()
{
	int n,m,i;
	while(cin>>n)
	{
	 int j=1,w=0;
	 for(i=1;i<=n;i++)
	 {
		cin>>m;
		if(m%2==1)
		{
		 w=1;
	 	 j=j*m;
	    }
	 }
	 if(w==0) cout<<0<<endl;
	 else cout<<j<<endl;
    }
}
