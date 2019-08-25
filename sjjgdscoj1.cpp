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
        //TODO: 3?¨º??¡¥?a??¨º¡Â
        root = NULL;
    }
    void insert(int elem) {
        //TODO: ¡ã?¨°???¨ºyelem2?¨¨?¦Ì?BST?D
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
        //TODO: ¡À¨¦¨¤¨²BST2¡é¡ã?¡À¨¦¨¤¨²?¨¢1?¡ã¡ä?3D¨°¡ä?¡¤??¨²result¨ºy¡Á¨¦?D
        //¨ºy¡Á¨¦??¡À¨º¡ä¨®0?a¨º?
        index=0;
        find(root,result);
    }
    //TODO: ?¨¦¨¬¨ª?¨®????3¨¦?¡À¡À?¨¢??¨°3¨¦?¡Ào¡¥¨ºy
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
        //?¨¢¨¨?¨º?¨¨?
        Tree tree;
        for(int i=0;i<N;i++) {
            int temp;
            cin>>temp;
            tree.insert(temp);
        }
        //¡À¨¦¨¤¨²?a??¨º¡Â
        int *result = new int[N];
        tree.traverse(result);
        //¨º?3??¨¢1?
        for(int i=0; i<N; i++)
            cout << result[i] << (i==N-1?'\n':' ');
        delete [] result;
    }
    return 0;
}
