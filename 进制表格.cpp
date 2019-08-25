#include<iostream>
#include<iomanip>
using namespace std;
int main()
{ 
	int i,k,t,m;
    cout<<"decimal\t  binary\toctal\thexadecimal\n";
	for(i=1; i<=256; i++)
	{ 
	   cout<<dec<<i<<"\t";
	   t=i;
	   m=0;
	   for(k=256; k>=1; k/=2)
	   { 
		if(t>=k) 
		{
		   cout<<1;
		   t=t-k;
		   m=1;
		} 
		else 
		   if(m) cout<<0;
      }
	if(i<128)	cout<<'\t';
	cout<<"\t"<<oct<<i<<"\t"<<hex<<i<<endl;
  }
}

