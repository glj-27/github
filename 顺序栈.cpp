#define SeqStack_H
const int StackSize=10;
template<class DataType>
	class SeqStack
	{
	public:
		SeqStack();
		~SeqStack(){}
		void Push(DataType x);
		DataType Pop();
		DataType GetTop();
		int Empty();
	private:
		DataType data[StackSize];
		int top;
	};
 
#include<iostream>
using namespace std;
template<class DataType>
SeqStack<DataType>::SeqStack()
{
	top=-1;
}
 
template<class DataType>
void SeqStack<DataType>::Push(DataType x)
{
	if(top==StackSize-1)throw"上溢";
	top++;
	data[top]=x;
}
 
template<class DataType>
DataType SeqStack<DataType>::Pop()
{
	DataType x;
	if(top==-1)throw"下溢";
	x=data[top--];
	return x;
}
 
template<class DataType>
DataType SeqStack<DataType>::GetTop()
{
	if(top!=-1)
	return data[top];
}
 
template<class DataType>
int SeqStack<DataType>::Empty()
{
	if(top==-1)return 1;
	else return 0;
}
 
int main()
{
	SeqStack<int>S;
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

