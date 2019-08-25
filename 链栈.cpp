#include<iostream>
using namespace std;
template<class DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;
};
 
template<class DataType>
class LinkStack
{
public:
	LinkStack();
	~LinkStack(){}
	void Push(DataType x);
	DataType Pop();
	DataType GetTop();
	int Empty();
private:
	Node<DataType> *top;
};
 
template<class DataType>
LinkStack<DataType>::LinkStack()
{
	top=new Node<DataType>; 
	top=NULL;
}
 
template<class DataType>
void LinkStack<DataType>::Push(DataType x)
{
	Node<DataType>*s;
	s=new Node<DataType>
	;s->data=x;
	s->next=top;
	top=s;
}
 
template<class DataType>
DataType LinkStack<DataType>::Pop()
{
	if(top==NULL)throw"下溢";
	else{
	Node<DataType>*p;
	p=new Node<DataType>;
	p=top;
	DataType x=p->data;
	top=top->next;
	delete p;
	return x;}
}
 
template<class DataType>
DataType LinkStack<DataType>::GetTop()
{
	if(top!=NULL)
	return top->data;
}
 
template<class DataType>
int LinkStack<DataType>::Empty()
{
	if(top==NULL){
		return 1;
	}
	else 
	{
		return 0;
	}
}
 
int main()
{
	LinkStack<int>S;
	if(S.Empty())
		cout<<"栈为空"<<endl;
	else
		cout<<"栈为满"<<endl;
	cout<<"将30，27，36,13放入栈中"<<endl;
	S.Push(30);
	S.Push(27);
	S.Push(36);
	S.Push(13);
	cout<<"栈顶元素为"<<endl;
	cout<<S.GetTop()<<endl;
	cout<<"执行一次出栈"<<endl;
	S.Pop();
	cout<<"栈顶元素为："<<endl;
	cout<<S.GetTop()<<endl;
}

