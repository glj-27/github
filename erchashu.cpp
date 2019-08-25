#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<stack>
#include <tchar.h>
using namespace std; 

//��������ʽ�洢�Ķ������ṹ
typedef struct _tagBinaryTreeNode
{
    unsigned char  value;
    struct  _tagBinaryTreeNode* lchind; 
    struct  _tagBinaryTreeNode* rchild;
}BinaryTreeNode, *PBinaryTreeNode;
//����  �ݹ鷽ʽ��ʼ�������� 
void InitBinaryTree(PBinaryTreeNode& pRoot)
{
    cout << "������ڵ��ֵ��#��ʾ��:";
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
//���ʶ������ڵ�
void Visit(PBinaryTreeNode pNode)
{
    cout<<"�ڵ�ֵΪ:"<<pNode->value<<endl;
}
//�ݹ鷽ʽ�������������
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
//�ǵݹ鷽ʽ����������������ڶ������������壬����ֻ��ʾ�ǵݹ�

//�ǵݹ鷽ʽ���������˼�룺
���Ƚ����ڵ���ջ�����ջΪ���˳�
ȡջ��Ԫ�أ����ջ��Ԫ��aΪNULL����ջ��Ԫ��a == NULL��ջ��
�ٽ���ʱ��ջ��Ԫ��b��ջ��Ȼ��Ԫ��b����������ջ���ٴ�ѭ���˹���; 

******************************************************************/
void PreTraverse(PBinaryTreeNode pNode, int nonRecurrence)
{
    //���Ԫ�ص�ջ
    stack<PBinaryTreeNode> stBT;

    //��ջ��Ԫ����ջ
    stBT.push(pNode);

    while(! stBT.empty())
    {
        PBinaryTreeNode topPNode = stBT.top();
        //ջ��Ԫ�ز�ΪNULL�����ʴ�Ԫ�أ���������������ջ
        if (NULL != topPNode)
        {
            Visit(topPNode);
            stBT.push(topPNode->lchind);
        }

        //ջ��Ԫ��aΪNULL����Ԫ��a��ջ��Ȼ���ٽ�ջ��Ԫ��b��ջ
        //��Ԫ��b��������ջ
        else
        {
            //��ջ����ΪNULL��Ԫ�س�ջ
            stBT.pop();
            if (! stBT.empty())
            {
                //ȡ��ʱ��ջ��Ԫ�أ������ջ��������������ջ
                topPNode = stBT.top();
                stBT.pop();
                stBT.push(topPNode->rchild);
            }
        }
    }
}
int _tmain(int argc, _TCHAR* argv[])
{
    cout << "\r\n ------�������������ע��Ҷ�ӽڵ����������Ϊ�գ�����#��ʾNULL--------\r\n";
    PBinaryTreeNode pRoot = NULL;
    InitBinaryTree(pRoot);
    cout << "\r\n ----------�������������� --------------\r\n\r\n";

    cout << "\r\n -----------��ʼ�ݹ�������������� ------------\r\n";
    PreTraverse(pRoot);
    cout << " --------------���� �ݹ�������������� ------------\r\n";

    cout << "\r\n ----------��ʼ �ǵݹ� ����������--------------\r\n";
    PreTraverse(pRoot, 0);  
    cout << " --------------���� �ǵݹ� ����������--------------\r\n";

    return 0;
}
