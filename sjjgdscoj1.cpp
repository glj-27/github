#include <iostream>
using namespace std;
class Node {
public:
    Node(int elem, Node *left=NULL, Node *right=NULL) {
        this->elem = elem;
        this->left = left;
        this->right = right;
    }
    int elem;
    Node *left, *right;
};
class Tree {
public:
    Tree() {
        //TODO: 3?��??��?a??����
        root = NULL;
    }
    void insert(int elem) {
        //TODO: ��?��???��yelem2?��?��?BST?D
        if (root==NULL){
            root = new Node(elem);
            return;
        } 
        Node* q = new Node(elem);
        Node *p=root;
        while(true){
            
            if ( elem<p->elem ){
                if (p->left==NULL) {p->left=q;return;}
                else p=p->left; 
            }
            else {
                if (p->right==NULL) {p->right=q;return;}
                else p=p->right;
            }
        }
    }
    void traverse(int *result) {
        //TODO: ��������BST2���?��������?��1?���?3D����?��??��result��y����?D
        //��y����??�����䨮0?a��?
        index=0;
        find(root,result);
    }
    //TODO: ?������?��????3��?����?��??��3��?��o����y
    void find(Node* p , int* result){
        if (p==NULL) return ;
        result[index++]=p->elem;
        find(p->left,result);
        find(p->right,result);
    }
    int index;
    Node *root;
};
int main() {
    int M;
    cin>>M;
    while(M--) {
        int N;
        cin>>N;
        //?����?��?��?
        Tree tree;
        for(int i=0;i<N;i++) {
            int temp;
            cin>>temp;
            tree.insert(temp);
        }
        //��������?a??����
        int *result = new int[N];
        tree.traverse(result);
        //��?3??��1?
        for(int i=0; i<N; i++)
            cout << result[i] << (i==N-1?'\n':' ');
        delete [] result;
    }
    return 0;
}
