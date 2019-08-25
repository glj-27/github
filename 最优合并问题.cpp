#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int k;
	int minsum=0;
	int maxsum=0;
	
	cin>>k;
	int* m=new int[k];
	int* n=new int[k];
	
	for(int i=0;i<k;i++)
	{
		cin>>m[i];  
		n[i]=m[i];
	}
	
	sort(m,m+k);
	for(int i=0;i<k-1;i++) 
	{
		minsum=minsum+m[i]+m[i+1]-1;//贪心策略：每次选最小的序列合并得到最少比较次数；每次选最大的序列合并得到最多比较次数。 
		m[i+1]=m[i]+m[i+1];
		m[i]=0;
		sort(m,m+k);//两个最小的相加不一定是最小的，需要再次排序 
	}
	
	sort(n,n+k);
	for(int j=k;j>1;j--)
	{
		maxsum=maxsum+n[j-1]+n[j-2]-1;
		n[j-2]=n[j-1]+n[j-2];//连个最大的相加一定是最大的，不需要再排序 
	}
	cout<<maxsum<<" "<<minsum;
} 
