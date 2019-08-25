#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef struct
{
    int data[MAXSIZE];
    int front,rear;
}CriQuence;
void init(CriQuence **q)
{
    *q = (CriQuence *)malloc(sizeof(CriQuence));
    (*q)->front = 0;
    (*q)->rear  = 0;
}
void insertQ(CriQuence *p,int value)
{
   if((p->rear + 1)%MAXSIZE == p->front)
   {
       printf("Quence is full\n");
   }else{
       p->rear=(p->rear+1)%MAXSIZE;
       p->data[p->rear] = value;
       printf("%d\n",p->data[p->rear]);
   }
}
void popQ(CriQuence *p,int *x)
{
   if(p->rear == p->front)
   {
       printf("Quence is empty\n");
   }else{
       p->front = (p->front+1)%MAXSIZE;
       *x = p->data[p->front];
       printf("%d\n",*x);
   }
}
void emptyQ(CriQuence *q)
{
   if(q->rear == q->front)
   {
       printf("empty Quence!\n");
   }
}
int main(int argc,char **argv)
{
    int x = 0;
    int value = 5;
    CriQuence *q = NULL;
    init(&q);
    insertQ(q,value);
    popQ(q,&x);
    emptyQ(q);
    return 0;
}
