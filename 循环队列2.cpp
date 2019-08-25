#ifndef LinkQueue_H
#define LinkQueue_H
template<class DataType>
struct Node
{
   DataTypedata;
   Node<DataType>*next;
};
template<class DataType>
class LinkQueue
{
   public:
     LinkQueue(); 
     ~LinkQueue(); 
     voidEnQueue(DataType x); 
     DataTypeDeQueue();
     DataTypeGetQueue();
     intEmpty();
   private:
     Node<DataType>*front,*rear;
};
#endif;
#include"LinkQueue.h"
template<class DataType>
LinkQueue<DataType>::LinkQueue()
{
   Node<DataType>*s=NULL;
   s=newNode<DataType>;
   s->next=NULL;
   front=rear=s;
}
template<class DataType>
LinkQueue<DataType>::~LinkQueue()
{
   Node<DataType>*p=NULL;
   while(front!=NULL)
   {
     p=front->next;
	 deletefront;
	 front=p;
   }
}
template<class DataType>
void LinkQueue<DataType>::EnQueue(DataTypex)
{
   Node<DataType>*s=NULL;
   s=newNode<DataType>;
   s->data=x;
   s->next=NULL;
   rear->next=s;rear=s;
}
template<class DataType>
DataTypeLinkQueue<DataType>::DeQueue()
{
   Node<DataType>*p=NULL;
   intx;
   if(rear==front)throw"下溢";
   p=front->next;
   x=p->data;
   front->next=p->next;
   if(p->next==NULL)rear=front;
   deletep;
   returnx;
}
template<class DataType>
DataTypeLinkQueue<DataType>::GetQueue()
{
   if(front!=rear)
   returnfront->next->data;
}
template<class DataType>
int LinkQueue<DataType>::Empty()
{
   if(front==rear)
   return1;
   else
   return0;
}
#include<iostream>
using namespace std;
#include"LinkQueue.cpp"?
void main()
{
  LinkQueue<int>.Q;
  if(Q.Empty())
  cout<<"队列已空"<<endl;
  else
  cout<<"队列非空"<<endl;
  cout<<"元素100，32，69执行入队操作"<<endl;
  try
  {
    Q.EnQueue(100);
	Q.EnQueue(32);
	Q.EnQueue(69);
  }
  catch(char*wrong)
  {
    cout<<wrong<<endl;
  }
  cout<<"查看队头元素"<<endl;
  cout<<Q.GetQueue()<<endl;
  cout<<"执行出队操作,并将23入队"<<endl;
  try
  {
    Q.DeQueue();
	Q.EnQueue(23);
  }
  catch(char*wrong)
  {
    cout<<wrong<<endl;
  }
  cout<<"查看队头元素"<<endl;
  cout<<Q.GetQueue()<<endl;
}

