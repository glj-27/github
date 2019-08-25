#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,x,y,d;
    cin>>n;
    int *m=new int[n];
    if(n>=1&&n<=10000)
    {
        for(int j=0;j<n;j++)
        {
            cin>>x>>y;
            m[j]=y;
        }
        sort(m,m+n);
        d=m[n/2];
        int total=0;
        for(int j=0;j<n;j++)
        {
            int l=d-m[j];
            if(l>0)
            {total=total+l;}
            if(l<0)
            {total=total-l;}
        }
        cout<<total;
    }
    else return false;
}
