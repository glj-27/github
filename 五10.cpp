#include <iostream>
using namespace std;
struct node
{
 char ch;
  node *next;  
};
void show( node *head );
int main()
{
 node *head, *p;
  char c;
  head = NULL;
  while( (c = getchar()) != '\n' )		                                                                                 //输入一行字符
   {
 p = new node;			                                                                                                 //建立新结点
	    p->ch = c;
	    p->next = head;		                                                                                               //插入表头
	    head=p;  
}
   show(head);
}
void show( node *head )		                                                                                                 //输出链表
{
 node *p = head;
  cout << "链表中的字符是: \n";
  while( p )
   { cout << p->ch;
      p = p->next;  
}
  cout << endl; 
}

