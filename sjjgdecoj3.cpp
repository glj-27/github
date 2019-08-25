#include<iostream>
#include<string>
using namespace std;
struct Node 
{
    char content;
    Node * left;
    Node * right;
};
class BinNode 
{
  private:
    Node * root;
    Node * current;
    Node * point;
    int i;
    char c[80];//�����ַ���
    bool flag;//���
 
    //���ɽڵ�
    void createNode(char c) 
	{
        point = new Node();
        point->content = c;
        point->left = NULL;
        point->right = NULL;
    }
 
    Node * subInsert(Node * subRoot)
	{
        if(c[i] != '\0')
		{
            createNode(c[i]);
            subRoot = point;
 
            if(c[i] >= 'A' && c[i] <= 'Z')
                return subRoot;
 
            i++;
            subRoot->left = subInsert(subRoot->left);
            i++;
            subRoot->right = subInsert(subRoot->right);
 
        }
        return subRoot;
    }
 
    //�ж��Ƿ�ƽ��ĺ�������Ļ��޸ı��
    void isBalance(int a, int b) 
	{
        if((a < (b-1))||(a > (b+1))) 
		{
            flag = false;
        }
    }
    //��ȡ���ĸ߶ȣ����ڼ仹���˺ܶ���Ƿ�ƽ����ж�
    int getHeight(Node * subRoot)
	{
        int a,b;
        if(subRoot == NULL) return 0;
        else 
		{
            a = getHeight(subRoot->left);
            b = getHeight(subRoot->right);
            //�ж�
            isBalance(a,b);
            return 1 + (a>b? a:b);
        }       
    }
 
  public:
    BinNode() 
	{
        root = NULL;
        current = NULL;
        point = NULL;
        flag = true;
        i = 0;
    }
 
    //����ӿڣ�������subInsertʵ�ֲ���
    void insert() 
	{
        cin.getline(c, 80);
        root = subInsert(root);
    }
 
    bool getFlag()
	{
        getHeight(root);
        return flag;
    }
    
};
 
int main() 
{
    int T, i;
    BinNode * BinNodeArray;
    cin>>T;//��T���������
    cin.get();
    BinNodeArray = new BinNode[T];
    for(i=0; i<T; i++) 
	{
        
        if(BinNodeArray[i].getFlag())
          cout<<'B'<<endl;
        else cout<<'N'<<endl;
        
        
    }
    return 0;
}
