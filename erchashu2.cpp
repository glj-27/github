#include<stdio.h>

#include<stdlib.h>

#define N 20

#define SIZE 100

#define MORE 10

typedef struct BiTNode{

char data; //数据域

struct BiTNode *lchild, *rchild; //左、右孩子指针

}BiTNode, *BiTree;



//栈 

typedef struct{

BiTree *base;

int top;

int stacksize;

}SqStack;



//队列 

typedef struct {

BiTree *base; //初始化动态分配空间

int front;

int rear;

} SqQueue;

//栈 

void InitStack(SqStack &S){

//构造一个空栈 

S.base=(BiTree*)malloc(SIZE*sizeof(BiTree));

if(!S.base) return ;

S.top=0;

S.stacksize=SIZE;

}

int StackEmpty(SqStack &S){

//判空 是返回1 否返回0

if(S.top==0) return 1;

else return 0;

}

void Push(SqStack &S,BiTree e){

//入栈 

if(S.top>=S.stacksize){

S.base=(BiTree *)realloc(S.base,(S.stacksize+MORE)*sizeof(BiTree));

if(!S.base) exit(0);

S.stacksize+=MORE;

}

S.base[S.top++]=e;

}

void Pop(SqStack &S,BiTree &e){

//出栈

if(S.top==0) exit(0);

else

e=S.base[--S.top];

}

int GetTop(SqStack &S,BiTree &e){

//取栈顶元素 

if(S.top==0) 

return 0;

else

e=S.base[S.top-1];

return 1;

}//栈 



//队列 

void InitQueue(SqQueue &Q){

//构造一个空队列

Q.base=(BiTree *)malloc(SIZE*sizeof(BiTree));

if (!Q.base) exit(0);

else

Q.front=Q.rear=0;

}

int QueueEmpty(SqQueue Q){

//判空

if (Q.rear==Q.front) return 1;

else

return 0;

}

void EnQueue(SqQueue &Q,BiTree e){

//插入元素e为Q的新的队尾元素

if ((Q.rear+1)%SIZE==Q.front)

exit(0);

else

Q.base[Q.rear]=e;

Q.rear=(Q.rear+1)%SIZE;

}

void DeQueue(SqQueue &Q,BiTree &e){

// 删除Q的队头元素, 并用e返回其值

if ((Q.rear+1)%SIZE==Q.front)

exit(0);

else

e=Q.base[Q.front];

Q.front=(Q.front+1)%SIZE;

} //队列
void visit(char data){

printf("%3c",data);

}

void CreatBiTree(BiTree &bt){

//构造二叉树

char ch;

ch=getchar();

if(ch=='#')

bt=NULL;

else{

bt=(BiTree)malloc(sizeof(BiTNode));

bt->data=ch;

CreatBiTree(bt->lchild);

CreatBiTree(bt->rchild);

}

}

//二叉树三种遍历的递归算法 

void PreOrderTraverse(BiTree bt){

//先序遍历

if(bt){

visit(bt->data);

PreOrderTraverse(bt->lchild);

PreOrderTraverse(bt->rchild);

}

}

void InOrderTraverse(BiTree bt){

//中序遍历

if(bt){

InOrderTraverse(bt->lchild);

visit(bt->data);

InOrderTraverse(bt->rchild);

}

}

void PostOrderTraverse(BiTree bt){

//后序遍历

if(bt){

PostOrderTraverse(bt->lchild);

PostOrderTraverse(bt->rchild);

visit(bt->data);

}

}

//二叉树三种遍历的非递归算法，栈 

void PreOrderTraverse2(BiTree bt){

 //先序遍历

BiTree p;

 SqStack S;

if(bt){

InitStack(S); 

Push(S,bt); 

while(!StackEmpty(S)){ 

while(GetTop(S,p)&&p){ 

visit(p->data); 

Push(S,p->lchild); 

} 

Pop(S,p); 

if(!StackEmpty(S)){ 

Pop(S,p); 

Push(S,p->rchild); 

}

}

}

}

void InOrderTraverse2(BiTree bt){

//中序遍历

BiTree p;

SqStack S;

if(bt){ 

InitStack(S); 

Push(S, bt); 

while(!StackEmpty(S)){ 

while(GetTop(S,p)&&p){

Push(S, p->lchild); 

Pop(S, p); 

} 

if(!StackEmpty(S)){ 

Pop(S,p); 

visit(p->data); 

Push(S, p->rchild); 

}

}

}

}

void PostOrderTraverse2(BiTree bt){

//后序遍历

BiTree p,q;

SqStack S;

InitStack(S); 

Push(S,bt); 

while(!StackEmpty(S)){ 

while(GetTop(S,p)&&p){

Push(S,p->lchild); 

Pop(S,p); 

} 

if(!StackEmpty(S)){ 

GetTop(S,p); 

if(p->rchild)

Push(S,p->rchild);

else{ 

Pop(S,p); 

visit(p->data);

while(!StackEmpty(S)&&GetTop(S,q)&&q->rchild==p){ 

Pop(S,p); 

visit(p->data);

}

if(!StackEmpty(S)){ 

GetTop(S,p); Push(S,p->rchild); 

}

            }

}

}

}



void LevelOrderTraverse(BiTree bt)
{

//层次遍历，队列 

BiTree p;

SqQueue Q;

if(bt){

InitQueue(Q); 

EnQueue(Q,bt);

while(!QueueEmpty(Q)){

DeQueue(Q,p);

visit(bt->data);

if(p->lchild){

EnQueue(Q,p->lchild);

}

if(p->rchild){

EnQueue(Q,p->rchild);

}

} 

}

}

int NodeNum(BiTree bt){

//求结点个数 

int count=0;

BiTree p;

SqQueue Q;

if(bt){

InitQueue(Q); 

EnQueue(Q,bt);

while(!QueueEmpty(Q)){

DeQueue(Q,p);

count++;

if(p->lchild){

EnQueue(Q,p->lchild);

}

if(p->rchild){

EnQueue(Q,p->rchild);

}

} 

}

return count;

}

int LeaNum(BiTree bt){

//求叶子总数

if(!bt){

return 0;

} 

else if(!(bt->lchild)&&!(bt->rchild)){

return 1;

}

else{

return (LeaNum(bt->lchild)+LeaNum(bt->rchild));

}

} 

int main(){

int a,b;

BiTree bt;

printf("请输入二叉树的元素：\n");

CreatBiTree(bt);

a=NodeNum(bt);

printf("结点个数为：%d\n",a);

b=LeaNum(bt);

printf("叶子个数为：%d\n",b);


return 0;



}
