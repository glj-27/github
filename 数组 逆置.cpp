#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
void printarray(int *p,int n);
void adverse(int *p,int n);
int main()
{ 
  int *p,n,i;
  cout<<"请输入数组长度:";
  cin>>n;
  p=new int [n];                                                          //建立动态数组
  srand(int(time(0)));
  for(i=0;i<n;i++)                                                        //产生随机数并存放到动态数组中
    *(p+i)=rand()%1000; 
  cout<<"动态数组："; 
  printarray(p,n);                                                        // 输出动态数组
  adverse(p,n);                                                           // 对数组逆置
  cout<<"逆置数组：";  
  printarray(p,n);                                                        // 输出逆置数组
}                                                                         // 输出数组函数
void printarray(int *p,int n)
{
  int i;
  for( i=0; i<n; i++ )
  {
    if (i % 5==0) cout<<endl;                                             // 控制一行输出5个数据
    cout<<"ary["<<i<<"]="<<*(p+i)<<"\t";
  }
  cout<<endl;    
}                                                                         // 对数组逆置函数
void adverse(int *p,int n)
{
  int i,t;
  for (i=0;i<n/2;i++)
  {
    t=*(p+i);
    *(p+i)=*(p+n-i-1);
    *(p+n-i-1)=t; 
  }
}

