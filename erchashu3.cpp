#include<iostream>
using namespace std;
template <class Elem>
void level(BinNode<Elem>* subroot) 
{
   AQueue<BinNode<Elem>*> Q;
   Q.enqueue(subroot);
   while(!Q.isEmpty()) 
   {
      BinNode<Elem>* temp;
      Q.dequeue(temp);
      if(temp != NULL) 
	  {
         Print(temp);
         Q.enqueue(temp->left());
         Q.enqueue(temp->right());
      }
   }
}

int height(BinNode<Elem>* subroot) 
{
   if (subroot == NULL) return 0; // Empty subtree
   return 1 + max(height(subroot->left()),
   height(subroot->right()));
}

int count(BinNode<Elem>* subroot) 
{
   if (subroot == NULL) return 0; // Empty subtree
   if (subroot->isLeaf()) return 1; // A leaf
   return 1 + count(subroot->left()) + count(subroot->right());
}
int main()
{
}
