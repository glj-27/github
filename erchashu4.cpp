#include <iostream>
#define MAXSIZE 100
using namespace std;
typedef char TElemType;
typedef struct BiTNode 
{
	TElemType data;
	struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;
void InOrderTraverse1(BiTree T) 
{
	if(T) {
		cout<<T->data;
		InOrderTraverse1(T->lchild);
		InOrderTraverse1(T->rchild);
	}
}
void CreateBiTree(BiTree &T) 
{
	char ch;
	cin>>ch;
	if(ch=='#')
		T=NULL;
	else {
		T=new BiTNode;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
int Depth(BiTree T) 
{
	int n,m;
	if(T==NULL)
		return 0;
	else {
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n)
			return(m+1);
		else
			return(n+1);
	}
}
int LeafNum(BiTree T)
{
	if(!T)
	return 0;
	else if(!(T->lchild)&&!(T->rchild))
	{
        return 1;
    }
    else
	{
        return (LeafNum(T->lchild)+LeafNum(T->rchild));
    }
}
int main() 
{
	BiTree a;
	int height,leafnum;
	CreateBiTree(a);
	InOrderTraverse1(a);
	height=Depth(a);
	leafnum=LeafNum(a);
	cout<<"\n高度为："; 
	cout<<height<<endl;
	cout<<"叶子数为："; 
	cout<<leafnum;
	return 0;
}

