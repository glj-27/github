#include <iostream>
#include <cstdio>
#include <algorithm> 
#define maxn 40 
using namespace std;
int n,m,t; 
int now[maxn];//现在的人数 
int maxx;//最大的人数 
struct ticket
{
	public:
	int start,end,num;
}tic[maxn];


void dfs(int u,int sum)
{
	if(sum>maxx)
	maxx=sum;
	if(u>=t)return;
	int i;
	for(i=tic[u].start;i<tic[u].end;i++)
	{
		if(now[i]+tic[u].num>n)
		break;
	}
	if(i>=tic[u].end)
	{
		for(i=tic[u].start;i<tic[u].end;i++)
	    {  
		    now[i]+=tic[u].num;
		}
		dfs(u+1,sum+(tic[u].end-tic[u].start)*tic[u].num);
		for(i=tic[u].start;i<tic[u].end;i++)
		{
			now[i]+=tic[u].num;
		}
	}
	dfs(u+1,sum);
}

int mian()
{
	while(cin>>n>>m>>t)
	{
		if(n==0)
		break;
		for(int i;i<t;i++)
		{
			cin>>tic[i].start>>tic[i].end>>tic[i].num;
		}
		dfs(0,0);
		cout<<maxx<<endl;
	}
	
}
