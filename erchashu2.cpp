#include<stdio.h>

#include<stdlib.h>

#define N 20

#define SIZE 100

#define MORE 10

typedef struct BiTNode{

char data; //������

struct BiTNode *lchild, *rchild; //���Һ���ָ��

}BiTNode, *BiTree;



//ջ 

typedef struct{

BiTree *base;

int top;

int stacksize;

}SqStack;



//���� 

typedef struct {

BiTree *base; //��ʼ����̬����ռ�

int front;

int rear;

} SqQueue;

//ջ 

void InitStack(SqStack &S){

//����һ����ջ 

S.base=(BiTree*)malloc(SIZE*sizeof(BiTree));

if(!S.base) return ;

S.top=0;

S.stacksize=SIZE;

}

int StackEmpty(SqStack &S){

//�п� �Ƿ���1 �񷵻�0

if(S.top==0) return 1;

else return 0;

}

void Push(SqStack &S,BiTree e){

//��ջ 

if(S.top>=S.stacksize){

S.base=(BiTree *)realloc(S.base,(S.stacksize+MORE)*sizeof(BiTree));

if(!S.base) exit(0);

S.stacksize+=MORE;

}

S.base[S.top++]=e;

}

void Pop(SqStack &S,BiTree &e){

//��ջ

if(S.top==0) exit(0);

else

e=S.base[--S.top];

}

int GetTop(SqStack &S,BiTree &e){

//ȡջ��Ԫ�� 

if(S.top==0) 

return 0;

else

e=S.base[S.top-1];

return 1;

}//ջ 



//���� 

void InitQueue(SqQueue &Q){

//����һ���ն���

Q.base=(BiTree *)malloc(SIZE*sizeof(BiTree));

if (!Q.base) exit(0);

else

Q.front=Q.rear=0;

}

int QueueEmpty(SqQueue Q){

//�п�

if (Q.rear==Q.front) return 1;

else

return 0;

}

void EnQueue(SqQueue &Q,BiTree e){

//����Ԫ��eΪQ���µĶ�βԪ��

if ((Q.rear+1)%SIZE==Q.front)

exit(0);

else

Q.base[Q.rear]=e;

Q.rear=(Q.rear+1)%SIZE;

}

void DeQueue(SqQueue &Q,BiTree &e){

// ɾ��Q�Ķ�ͷԪ��, ����e������ֵ

if ((Q.rear+1)%SIZE==Q.front)

exit(0);

else

e=Q.base[Q.front];

Q.front=(Q.front+1)%SIZE;

} //����
void visit(char data){

printf("%3c",data);

}

void CreatBiTree(BiTree &bt){

//���������

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

//���������ֱ����ĵݹ��㷨 

void PreOrderTraverse(BiTree bt){

//�������

if(bt){

visit(bt->data);

PreOrderTraverse(bt->lchild);

PreOrderTraverse(bt->rchild);

}

}

void InOrderTraverse(BiTree bt){

//�������

if(bt){

InOrderTraverse(bt->lchild);

visit(bt->data);

InOrderTraverse(bt->rchild);

}

}

void PostOrderTraverse(BiTree bt){

//�������

if(bt){

PostOrderTraverse(bt->lchild);

PostOrderTraverse(bt->rchild);

visit(bt->data);

}

}

//���������ֱ����ķǵݹ��㷨��ջ 

void PreOrderTraverse2(BiTree bt){

 //�������

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

//�������

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

//�������

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

//��α��������� 

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

//������� 

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

//��Ҷ������

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

printf("�������������Ԫ�أ�\n");

CreatBiTree(bt);

a=NodeNum(bt);

printf("������Ϊ��%d\n",a);

b=LeaNum(bt);

printf("Ҷ�Ӹ���Ϊ��%d\n",b);


return 0;



}
