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
		minsum=minsum+m[i]+m[i+1]-1;//̰�Ĳ��ԣ�ÿ��ѡ��С�����кϲ��õ����ٱȽϴ�����ÿ��ѡ�������кϲ��õ����Ƚϴ����� 
		m[i+1]=m[i]+m[i+1];
		m[i]=0;
		sort(m,m+k);//������С����Ӳ�һ������С�ģ���Ҫ�ٴ����� 
	}
	
	sort(n,n+k);
	for(int j=k;j>1;j--)
	{
		maxsum=maxsum+n[j-1]+n[j-2]-1;
		n[j-2]=n[j-1]+n[j-2];//�����������һ�������ģ�����Ҫ������ 
	}
	cout<<maxsum<<" "<<minsum;
} 
