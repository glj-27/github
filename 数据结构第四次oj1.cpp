#include <cstdlib>
#include <iostream>
using namespace std;
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node 
{
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(int n);
void Print( List L );

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    int a;int b;
    while(cin>>a>>b)
    {
      L1 = Read(a);
      L2 = Read(b);
      L = Merge(L1, L2);
      Print(L);
	}
	return 0;
}
List Read(int n)
{

    List L=(List)malloc(sizeof(PtrToNode));   
    L->Next = NULL;        
    if(n)    
    {
        List r=L;    
        for(int i=0;i<n;i++) 
        {
            List p=(List)malloc(sizeof(struct Node));
            cin>>p->Data;    
            r->Next = p;
            r = p;
        }
        r->Next = NULL;         
    }
    return L;
}
void Print( List L )
{
   List p=L->Next;
   if(p)
   {
       List r;
       r = L;
       r = r->Next;
       cout<<r->Data;
       while(r->Next)
       {
           r = r->Next;
           cout<<" "<<r->Data;
       }
   }
   else
   {
       cout<<"NULL";
   }
   cout<<endl;
}
List Merge( List L1, List L2 ) 
{
    List pa,pb,pc,L;
    L = (List)malloc(sizeof(struct Node));
    pa=L1->Next;
    pb=L2->Next;
    pc = L;
    while(pa && pb)
    {
        if(pa->Data <= pb->Data)
        {
            pc->Next = pa;
            pc = pa;
            pa = pa->Next;
        }
        else
        {
            pc->Next = pb;
            pc = pb;
            pb = pb->Next;
        }
    }
    pc->Next = pa ? pa : pb;
    return L;
}
