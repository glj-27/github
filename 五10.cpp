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
  while( (c = getchar()) != '\n' )		                                                                                 //����һ���ַ�
   {
 p = new node;			                                                                                                 //�����½��
	    p->ch = c;
	    p->next = head;		                                                                                               //�����ͷ
	    head=p;  
}
   show(head);
}
void show( node *head )		                                                                                                 //�������
{
 node *p = head;
  cout << "�����е��ַ���: \n";
  while( p )
   { cout << p->ch;
      p = p->next;  
}
  cout << endl; 
}

