#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
using namespace std;
struct step
 {
 int i;
 int j;
 step*next;
 };
 step*head;
 int m,n;
 void way(int i,int j)
 {
  step*s;
  s=new step; s->i=i; s->j=j;
  s->next=head; head=s;
  }
void back(int&i,int&j)
 {
   step*s; s=head;
   head=head->next; delete s; i=head->i; j=head->j; 
 }
void mazePrint(char maze[][100],int m,int n)
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
void mazeGenerator(char maze[][100],int m,int n)
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
 if(i==m-2)
 {cout<<"成功走出迷宫!!"<<endl;return;}
 if(maze[i][j-1]=='.')
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
 {maze[i][j]='@';back(i,j);}
 mazeTraverse(i,j,maze,m,n);
}
void mazego(char&a,char maze[][100],int&i,int&j,int m,int n) 
{
 system("cls");
 mazePrint(maze,m,n);
 char b;
 b=_getch();
 if(i==(m-2))
 {cout<<"成功走出迷宫!!"<<endl;return;}
 if(b=='b')
 {a='b';return;}
 else if(b=='a'&&maze[i][j-1]!='#')
 {j--;maze[i][j]='X';way(i,j);}
 else if(b=='s'&&maze[i+1][j]!='#')
 {i++;maze[i][j]='X';way(i,j);}
 else if(b=='d'&&maze[i][j+1]!='#')
 {j++;maze[i][j]='X';way(i,j);}
 else if(b=='w'&&maze[i-1][j]!='#')
 {i--;maze[i][j]='X';way(i,j);}
 mazego(a,maze,i,j,m,n);
}
int main()
{
  int i,j;
  char a;
  head=new step;
  cout<<"请输入迷宫大小:m,n"<<endl;
  cin>>m>>n;
  char maze[50][100];
  mazeGenerator(maze,m,n);
  cout<<"请输入迷宫的入口坐标："<<endl;
  cin>>i>>j;
  maze[i][j]='X';head->j=j;
  head->next=NULL;
  mazeTraverse(i,j,maze,m,n);
  mazego(a,maze,i,j,m,n);
}
 
