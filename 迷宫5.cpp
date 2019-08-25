#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
using namespace std;
struct step
{
 int i;//每一步的
 int j;//位置
 step*next;//用于建立链表
};
 step*head;//表头指针
 int m,n;
 void way(int i,int j)//记录所走轨迹
 {
  step*s;
  s=new step; s->i=i; s->j=j;
  s->next=head; head=s;}
void back(int&i,int&j)//若遇到死路,则退一步
 {
 step*s; s=head;
 head=head->next; delete s; i=head->i; j=head->j; 
 }
void mazePrint(char maze[][100],int m,int n)//输出此时迷宫状况
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
void mazeGenerator(char maze[][100],int m,int n)//迷宫生成函数
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
 if(i==m-2){cout<<"成功走出迷宫!!"<<endl;return;}if(maze[i][j-1]=='.')
 {j--;maze[i][j]='X';way(i,j);} 
 else if(maze[i+1][j]=='.')
 {i++;maze[i][j]='X';way(i,j);} 
 else if(maze[i][j+1]=='.')
 {j++;maze[i][j]='X';way(i,j);} 
 else if(maze[i-1][j]=='.')
 {i--;maze[i][j]='X';way(i,j);} 
 else if(head->next==NULL)
 {cout<<"回退到入口."<<endl;return;}
 else
 {maze[i][j]='@';back(i,j);}mazeTraverse(i,j,maze,m,n);
}
void mazego(char&a,char maze[][100],int&i,int&j,int m,int n) 
{
 system("cls");
 mazePrint(maze,m,n);char b;
 b=_getch();
 if(i==(m-2)){cout<<"成功走出迷宫!!"<<endl;return;}
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
 cout<<"请输入迷宫大小.m n "<<endl;
 cin>>m>>n;
 char maze[50][100];
 mazeGenerator(maze,m,n); 
 cout<<"请输入迷宫入口点的坐标:(1,?).(入口为第二行,出口为倒数第二行)."<<endl;
 cin>>i>>j;
 maze[i][j]='X'; head->i=i; head->j=j;
 head->next=NULL; 
 cout<<"自己走(t);答案(b)"<<endl;
 cin>>a;
 if(a=='t')
 {  cout<<"方向键(a,s,d,w),答案(b)."<<endl;
    mazego(a,maze,i,j,m,n);
 }
 if(a=='b')
 {  cout<<"Enter为行走键"<<endl;
    mazeTraverse(i,j,maze,m,n);
 }
}
