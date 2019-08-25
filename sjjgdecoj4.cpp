#include<iostream>
#include<string>
#include<queue>
using namespace std;
string st;
int i;
struct node
{
	char ch;
	node* lc;
	node* rc;
};
node* setTree(node *nd)
{
	nd = new node;
	nd->ch=st[i];
	if(st[i]<'a')
	{
		nd->lc=NULL;
		nd->rc=NULL;
		return nd;
	}
	i++;
	nd->lc=setTree(nd->lc);
	i++;
	nd->rc=setTree(nd->rc);
	return nd;
}
void show(node *bt)   
{	
	queue<node *>q;
	if(bt==NULL)return;
	q.push(bt);
	while(!q.empty())
	{
		cout<<q.front()->ch;
		if(q.front()->lc!=NULL)q.push(q.front()->lc);
		if(q.front()->rc!=NULL)q.push(q.front()->rc);
		q.pop();
	}
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	for(;n>0;n--)
	{
	cin>>st;
	i=0;
	node *head;
	head=setTree(head);
	show(head);
    }
}
	
		
