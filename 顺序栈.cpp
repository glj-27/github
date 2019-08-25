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
	if(top==StackSize-1)throw"����";
	top++;
	data[top]=x;
}
 
template<class DataType>
DataType SeqStack<DataType>::Pop()
{
	DataType x;
	if(top==-1)throw"����";
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
		cout<<"ջΪ��"<<endl;
	else
		cout<<"ջΪ��"<<endl;
	cout<<"��30��27��36,13����ջ��"<<endl;
	S.Push(30);
	S.Push(27);
	S.Push(36);
	S.Push(13);
	cout<<"ջ��Ԫ��Ϊ"<<endl;
	cout<<S.GetTop()<<endl;
	cout<<"ִ��һ�γ�ջ"<<endl;
	S.Pop();
	cout<<"ջ��Ԫ��Ϊ��"<<endl;
	cout<<S.GetTop()<<endl;
}

