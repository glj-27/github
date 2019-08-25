#include<stdio.h>
#include<string.h>
#include<iostream>
char stack[135];
using namespace std;
int main()
{
int n;
cin>>n;
getchar();
while(n-->0)
 {
  memset(stack,0,sizeof(stack));
  char c;
  int top=0;
  int flag=1;
  while((c=getchar())!=EOF)
  {
  	if (c=='\n') break;
   if(c=='(') stack[top++]=c;
   else if(c==')')
   {
    if(top<=0||stack[--top]!='(') flag=0;    
   }                       
  } 
  if(flag==0||top!=0) cout<<"FLASE"<<endl;
  else cout<<"TRUE"<<endl;        
 }
 return 0;   
}
