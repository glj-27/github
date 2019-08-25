#include<iostream>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	for (i=1;i<n;i++)
    cout<<"* ";cout<<"*";
	cout<<endl;
	for (i=1;i<n-1;i++)
	{
		cout<<"*"; 
		for (j=1;j<=(n-2)*2+1;j++) cout<<" ";
		cout<<"*";
		cout<<endl;
	}
    for (i=1;i<n;i++)
    cout<<"* ";cout<<"*";
    return 0;
}
