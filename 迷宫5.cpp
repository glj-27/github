#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
using namespace std;
struct step
{
 int i;//ÿһ����
 int j;//λ��
 step*next;//���ڽ�������
};
 step*head;//��ͷָ��
 int m,n;
 void way(int i,int j)//��¼���߹켣
 {
  step*s;
  s=new step; s->i=i; s->j=j;
  s->next=head; head=s;}
void back(int&i,int&j)//��������·,����һ��
 {
 step*s; s=head;
 head=head->next; delete s; i=head->i; j=head->j; 
 }
void mazePrint(char maze[][100],int m,int n)//�����ʱ�Թ�״��
{
 int i,j;
 for(i=0;i<m;i++)
 {
   for(j=0;j<n;j++)
   {
    cout<<maze[i][j];
    if(j==n-1)cout<<endl;
   }
 }
}
void mazeGenerator(char maze[][100],int m,int n)//�Թ����ɺ���
{
 int i,j;
 srand(int(time(0)));
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   if(i==0||j==0||i==(m-1)||j==(n-1))maze[i][j]='#';
   else if(rand()%3==0)maze[i][j]='#';
   else maze[i][j]='.';
  }
 }
 mazePrint(maze,m,n);
}
void mazeTraverse(int i,int j,char maze[][100],int m,int n)
{
 cin.get();
 system("cls");
 mazePrint(maze,m,n);cout<<endl;
 if(i==m-2){cout<<"�ɹ��߳��Թ�!!"<<endl;return;}if(maze[i][j-1]=='.')
 {j--;maze[i][j]='X';way(i,j);} 
 else if(maze[i+1][j]=='.')
 {i++;maze[i][j]='X';way(i,j);} 
 else if(maze[i][j+1]=='.')
 {j++;maze[i][j]='X';way(i,j);} 
 else if(maze[i-1][j]=='.')
 {i--;maze[i][j]='X';way(i,j);} 
 else if(head->next==NULL)
 {cout<<"���˵����."<<endl;return;}
 else
 {maze[i][j]='@';back(i,j);}mazeTraverse(i,j,maze,m,n);
}
void mazego(char&a,char maze[][100],int&i,int&j,int m,int n) 
{
 system("cls");
 mazePrint(maze,m,n);char b;
 b=_getch();
 if(i==(m-2)){cout<<"�ɹ��߳��Թ�!!"<<endl;return;}
 if(b=='b'){a='b';return;}
 else if(b=='a'&&maze[i][j-1]!='#'){j--;maze[i][j]='X';way(i,j);}
 else if(b=='s'&&maze[i+1][j]!='#'){i++;maze[i][j]='X';way(i,j);}
 else if(b=='d'&&maze[i][j+1]!='#'){j++;maze[i][j]='X';way(i,j);}
 else if(b=='w'&&maze[i-1][j]!='#'){i--;maze[i][j]='X';way(i,j);}
 mazego(a,maze,i,j,m,n);
}
int main()
{
 int i,j;char a;
 head=new step; 
 cout<<"�������Թ���С.m n "<<endl;
 cin>>m>>n;
 char maze[50][100];
 mazeGenerator(maze,m,n); 
 cout<<"�������Թ���ڵ������:(1,?).(���Ϊ�ڶ���,����Ϊ�����ڶ���)."<<endl;
 cin>>i>>j;
 maze[i][j]='X'; head->i=i; head->j=j;
 head->next=NULL; 
 cout<<"�Լ���(t);��(b)"<<endl;
 cin>>a;
 if(a=='t')
 {  cout<<"�����(a,s,d,w),��(b)."<<endl;
    mazego(a,maze,i,j,m,n);
 }
 if(a=='b')
 {  cout<<"EnterΪ���߼�"<<endl;
    mazeTraverse(i,j,maze,m,n);
 }
}
