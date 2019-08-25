#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue> 
using namespace std;
struct node
{
	char c;
	int x,idx;
	int length;
	node *l,*r;

	node( node *l1=NULL,node*r1=NULL,int i=0)
	{
		idx=i;
		length=0;
		l=l1;r=r1;
		if(l&&r)
		{
			x=l->x+r->x;
		}
		else
		x=0;
		c='0';
	}
	void set(char a,int b,int i)
	{
		c=a;
		x=b;
		idx=i;
	}
	friend bool operator <(const struct node &a,const struct node &b)
	{
		return a.x>b.x;
	}
	bool child()
	{
		return (l==NULL&&r==NULL);
	}
	void out()
	{
		printf("the c is %c\t the weight is %d  the dep is %d\n",c,x,length);
	}
};
void dfs( node *root,int dp)
{
	if(root->child())
	{
		root->length=dp;
		return ;
	}
	
	dfs(root->l,dp+1);
	dfs(root->r,dp+1);
}
int main()
{
	int n,p,i,m,j,k,count,g;
	char c;
	priority_queue<node>pq;
	cin>>n;
	char *str=new char[100];
	node *array=new node[100],*tmp,*tmp1,*tmp2,*top;

	while(n--)
	{
		cin>>m;
		j=m;
		i=0;
		memset(array,0,100*sizeof(node));
		while(m--)
		{
			cin>>c>>p;
			array[i].set(c,p,i);
			pq.push(array[i]);
			i++;			
		}
		top=(node *)&pq.top();
		while(1)
		{
			tmp1=&array[top->idx];
			pq.pop();
			tmp2=&array[top->idx];
			tmp=new node(tmp1,tmp2,i);
			array[i++]=*tmp;
			pq.pop();
			if(pq.empty())
			{
				break;
			}
			pq.push(*tmp);
		}
		dfs(tmp,0);
		
		cin>>str;
		k=0;
		count=0;
		while(str[k])
		{
			for( g=0;g<j;g++)
			{
				if(str[k]==array[g].c)
				break;
			}
			count+=array[g].length;
			k++;
		}
		cout<<count<<endl;
	}
}


