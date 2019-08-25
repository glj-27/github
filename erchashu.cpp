#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<stack>
#include <tchar.h>
using namespace std; 

//二叉链表方式存储的二叉树结构
typedef struct _tagBinaryTreeNode
{
    unsigned char  value;
    struct  _tagBinaryTreeNode* lchind; 
    struct  _tagBinaryTreeNode* rchild;
}BinaryTreeNode, *PBinaryTreeNode;
//先序  递归方式初始化二叉树 
void InitBinaryTree(PBinaryTreeNode& pRoot)
{
    cout << "请输入节点的值，#表示空:";
    unsigned char temp;
    cin >> temp;
    if (temp == '#')
    {
        pRoot = NULL;
    }
    else
    {
        if (NULL != (pRoot = new BinaryTreeNode()))
        {
            pRoot->value = temp;
            InitBinaryTree(pRoot->lchind);
            InitBinaryTree(pRoot->rchild);
        }
        else
        {
            exit(-1);
        }
    }
}
//访问二叉树节点
void Visit(PBinaryTreeNode pNode)
{
    cout<<"节点值为:"<<pNode->value<<endl;
}
//递归方式先序遍历二叉树
void PreTraverse(PBinaryTreeNode pNode)
{
    if (NULL == pNode)
    {
        return;
    }
    else
    {
        Visit(pNode);
    }
    PreTraverse(pNode->lchind);
    PreTraverse(pNode->rchild);
}
/*****************************************************************
//非递归方式先序遍历二叉树，第二个参数无意义，重载只表示非递归

//非递归方式先序遍历的思想：
首先将根节点入栈，如果栈为空退出
取栈顶元素，如果栈顶元素a为NULL，则栈顶元素a == NULL出栈，
再将此时的栈顶元素b出栈，然后将元素b的右子树入栈，再次循环此过程; 

******************************************************************/
void PreTraverse(PBinaryTreeNode pNode, int nonRecurrence)
{
    //存放元素的栈
    stack<PBinaryTreeNode> stBT;

    //将栈顶元素入栈
    stBT.push(pNode);

    while(! stBT.empty())
    {
        PBinaryTreeNode topPNode = stBT.top();
        //栈顶元素不为NULL，访问此元素，并将其左子树入栈
        if (NULL != topPNode)
        {
            Visit(topPNode);
            stBT.push(topPNode->lchind);
        }

        //栈顶元素a为NULL，此元素a出栈，然后再将栈顶元素b出栈
        //将元素b右子树入栈
        else
        {
            //将栈顶的为NULL的元素出栈
            stBT.pop();
            if (! stBT.empty())
            {
                //取此时的栈顶元素，将其出栈并将其右子树入栈
                topPNode = stBT.top();
                stBT.pop();
                stBT.push(topPNode->rchild);
            }
        }
    }
}
int _tmain(int argc, _TCHAR* argv[])
{
    cout << "\r\n ------先序构造二叉树，注意叶子节点的左右子树为空，输入#表示NULL--------\r\n";
    PBinaryTreeNode pRoot = NULL;
    InitBinaryTree(pRoot);
    cout << "\r\n ----------先序构造二叉树完毕 --------------\r\n\r\n";

    cout << "\r\n -----------开始递归先序遍历二叉树 ------------\r\n";
    PreTraverse(pRoot);
    cout << " --------------结束 递归先序遍历二叉树 ------------\r\n";

    cout << "\r\n ----------开始 非递归 遍历二叉树--------------\r\n";
    PreTraverse(pRoot, 0);  
    cout << " --------------结束 非递归 遍历二叉树--------------\r\n";

    return 0;
}
