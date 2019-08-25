#include <iostream>
#include <string.h>
using namespace std;
class Node
{
public:
	int m_data;
	Node *m_next;
	Node(int data):m_data(data),m_next(NULL){}
}; 
class List
{
public:
	List():m_head(NULL){}
	~List();
	bool isEmpty(){return m_head;}
	int Length();
	void Print();
	bool Insert(int data,int pos);
	Node* FindByPos(int pos);
	void Delete(int pos);
	void Reverse();
	void InsertSort(int data);
	bool IsLoop();
	Node* Combine(Node *first);
public:
	Node *m_head;
};
 
Node* List::Combine(Node *first)
{
	Node *head = NULL;
	if(this->m_head == NULL)
		return first;
	if(first == NULL)
		return this->m_head;
	if(m_head->m_data < first->m_data)
	{
		head = m_head;
		m_head = m_head->m_next;
		head->m_next = Combine(first);
	}
	else
	{
		head = first;
		head->m_next = Combine(first->m_next);
	}
	return head;
}
bool List::IsLoop()
{
	Node *first = m_head,*second = m_head;
	do
	{
		first = first->m_next;
		second = second->m_next->m_next;
	}while(second != NULL && second->m_next != NULL && first != second);
	if(first == second)
	{
		return true;
	}
	else
		return false;
}
void List::InsertSort(int data)
{
	Node *tmp = m_head;
	Node *pre;
	Node *node = new Node(data);
	if(m_head == NULL)
	{
		m_head = node;
		return;
	}
	if(data < m_head->m_data)
	{
		node->m_next = m_head;
		m_head = node;
		return;
	}
	while(tmp != NULL && tmp->m_data < data)
	{
		pre = tmp;
		tmp = tmp->m_next;
	}
	if(NULL == tmp)
	{
		pre->m_next = node;
		return;
	}
	else
	{
		node->m_next = pre->m_next;
		pre->m_next = node;
	}
}
 
void List::Reverse()
{
	if(Length() < 2)
		return;
	Node *cur = m_head,*next = m_head->m_next,*tmp;
	while(next != NULL)
	{
		tmp = next->m_next;
		next->m_next = cur;
		cur = next;
		next = tmp;
	}
	m_head->m_next = NULL;
	m_head = cur;
}
void List::Delete(int pos)
{
	if(Length() <= pos)
	{
		cout << "给定删除位置超出数组大小，删除失败！" << endl;
		return;
	}
	Node *tmp = m_head;
	int index = 1;
	if(0 == pos)
	{
		m_head = tmp->m_next;
		delete tmp;
		return;
	}
	while(tmp != NULL && index < pos)
	{
		tmp = tmp->m_next;
		index++;
	}
	if(NULL == tmp)
	{
		cout << "给定删除位置超出数组范围，删除失败！" << endl;
		return;
	}
	Node *de = tmp->m_next;
	tmp->m_next = tmp->m_next->m_next;
	delete de;
}
Node* List::FindByPos(int pos)
{
	Node *tmp = m_head;
	if(tmp == NULL)
	{
		return NULL;
	}
	int index = 1;
	while(tmp != NULL && index < pos)
	{
		tmp = tmp->m_next;
		index++;
	}
	if(tmp == NULL)
	{
		return NULL;
	}
	return tmp;
}
bool List::Insert(int data,int pos)
{
	Node *tmp = m_head;
	Node *node = new Node(data);
	if(m_head == NULL)
	{
		m_head = node;
		return 1;
	}
	if(0 == pos)
	{
		node->m_next = m_head;
		m_head = node;
		return 1;
	}
	else
	{
		int index = 1;
		while(tmp != NULL && index < pos)
		{
			tmp = tmp->m_next;
			index++;
		}
		if(NULL == tmp)
			return 0;
		node->m_next = tmp->m_next;
		tmp->m_next = node;
		return 1;
	}
}
void List::Print()
{
	if(m_head == NULL)
		cout << "空链表" << endl;
	Node *tmp = m_head;
	while(tmp != NULL)
	{
		cout << tmp->m_data << " ";
		tmp = tmp->m_next;
	}
	cout << endl;
}
 
List::~List()
{
	Node *tmp = NULL;
	while(m_head != NULL)
	{
		tmp = m_head->m_next;
		delete m_head;
		m_head = tmp;
	}
	cout << "已删除" << endl;
}
 
int List::Length()
{
	int len = 0;
	Node *tmp = m_head;
	if(tmp == NULL)
		return len;
	else
	{
		while(tmp != NULL)
		{
			tmp = tmp->m_next;
			len++;
		}
	}
	return len;
}
 
void print(Node *p)
{
	if(NULL == p)
	{
		cout << "节点为空" << endl;
		return;
	}
	while(p!=NULL)
	{
		cout << p->m_data << " ";
		p = p->m_next;
	}
	cout << endl;
}
 
int main()
{
	List list;
	list.InsertSort(10);
	list.InsertSort(50);
	list.InsertSort(80);
	list.InsertSort(30);
	list.InsertSort(20);
	cout << "list:";
	list.Print();
	List list2;
	list2.InsertSort(11);
	list2.InsertSort(44);
	list2.InsertSort(33);
	list2.InsertSort(22);
	cout << "list2:" ;
	list2.Print();
 
	cout << "合并list1 list2：" << endl;
	Node *head = list.Combine(list2.m_head);
	print(head);
	return 0;
}

