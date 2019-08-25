#include<iostream>
#include<cstdio>
using namespace std;
class Node{
    public:
        Node(int x){
            value = x;
            next = NULL;
        };
        ~Node(){};
        Node* insertNode(Node *p){
            p->next = this;
            p = this;
            return p;
        }
        void swapPairs(Node *node){
            swap(this->value,node->value);
        }
        int value;
        Node* next;
//      static Node *head;
//		static Node *tail;
};
//de* Node::head = NULL;
//de* Node::tail = NULL;
Node *tail;
Node *head;
int main()
{
	int n;
    cin>>n;
    int a;
    while (n--){
        int v = -1;
        head =NULL;
        tail = NULL;
        do{
            cin>>v;
            if (v==-1) break;
            if (head==NULL){
                head = new Node(v);
                tail = head;
                continue;
            }
            Node *p = new Node(v);
            tail = p->insertNode(tail);
        }while (v!=-1);
        int k =0;
        Node *p=head;
        while (p != NULL){
            ++k;
            if ( k%2==1&&p->next!=NULL){
                p->swapPairs(p->next);
            }
            p=p->next;
        }
            
		while (head != NULL){
            Node *p = head;
            printf("%d ",p->value);
            head = head->next;
            //if (p->next!=NULL) printf(" ");
            delete p;
        }
        printf("\n");
    }


}
