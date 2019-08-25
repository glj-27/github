#include<iostream>
#define maxnum 40
using namespace std;

int n,m,t;//最大载客量，站点数，订票总数 
int now[maxnum];//车上人数 
 
int maxvalue;//最大利润 
struct piao//定义票的结构 
{
	int start;
	int end;
	int num;//起点，终点，人数
};
piao ticket[maxnum];
void caculate(int u,int sum)//（订票信息数，利润） 
{
	if(sum>maxvalue)
	maxvalue=sum;
	if(u>=t)return;//当前订票信息数多余>订票总数 
	int j;
	for(j=ticket[u].start;j<ticket[u].end;j++)//先判断每张车票，七点到终点过程中，会不会超载
	{if(now[j]+ticket[u].num>n)break;//若超载，则退出 	
	}
	if(j>=ticket[u].end)//车所在站号>订票终点号 
	{for(j=ticket[u].start;j<ticket[u].end;j++)
		{now[j]+=ticket[u].num;//车上人数+=上车人数 
		}
		caculate(u+1,sum+(ticket[u].end-ticket[u].start)*ticket[u].num);//利润+=（终点-起点）*人数 
		for(j=ticket[u].start;j<ticket[u].end;j++)
		{now[j]-=ticket[u].num;//车上人数-=下车人数 
		}}
	caculate(u+1,sum);//到达下一个车站 
}
int main()
{
	while(cin>>n>>m>>t)//输入>>最大载客量，站点数，订票总数
	{
		for(int j=0;j<t;j++)
		{cin>>ticket[j].start>>ticket[j].end>>ticket[j].num;}
		caculate(0,0);//从起点开始 
		cout<<maxvalue<<endl;//输出最大利润 
		maxvalue=0;
	}
	
}
