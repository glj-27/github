#include<iostream>
#define maxnum 40
using namespace std;

int n,m,t;//����ؿ�����վ��������Ʊ���� 
int now[maxnum];//�������� 
 
int maxvalue;//������� 
struct piao//����Ʊ�Ľṹ 
{
	int start;
	int end;
	int num;//��㣬�յ㣬����
};
piao ticket[maxnum];
void caculate(int u,int sum)//����Ʊ��Ϣ�������� 
{
	if(sum>maxvalue)
	maxvalue=sum;
	if(u>=t)return;//��ǰ��Ʊ��Ϣ������>��Ʊ���� 
	int j;
	for(j=ticket[u].start;j<ticket[u].end;j++)//���ж�ÿ�ų�Ʊ���ߵ㵽�յ�����У��᲻�ᳬ��
	{if(now[j]+ticket[u].num>n)break;//�����أ����˳� 	
	}
	if(j>=ticket[u].end)//������վ��>��Ʊ�յ�� 
	{for(j=ticket[u].start;j<ticket[u].end;j++)
		{now[j]+=ticket[u].num;//��������+=�ϳ����� 
		}
		caculate(u+1,sum+(ticket[u].end-ticket[u].start)*ticket[u].num);//����+=���յ�-��㣩*���� 
		for(j=ticket[u].start;j<ticket[u].end;j++)
		{now[j]-=ticket[u].num;//��������-=�³����� 
		}}
	caculate(u+1,sum);//������һ����վ 
}
int main()
{
	while(cin>>n>>m>>t)//����>>����ؿ�����վ��������Ʊ����
	{
		for(int j=0;j<t;j++)
		{cin>>ticket[j].start>>ticket[j].end>>ticket[j].num;}
		caculate(0,0);//����㿪ʼ 
		cout<<maxvalue<<endl;//���������� 
		maxvalue=0;
	}
	
}
