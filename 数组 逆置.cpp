#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
void printarray(int *p,int n);
void adverse(int *p,int n);
int main()
{ 
  int *p,n,i;
  cout<<"���������鳤��:";
  cin>>n;
  p=new int [n];                                                          //������̬����
  srand(int(time(0)));
  for(i=0;i<n;i++)                                                        //�������������ŵ���̬������
    *(p+i)=rand()%1000; 
  cout<<"��̬���飺"; 
  printarray(p,n);                                                        // �����̬����
  adverse(p,n);                                                           // ����������
  cout<<"�������飺";  
  printarray(p,n);                                                        // �����������
}                                                                         // ������麯��
void printarray(int *p,int n)
{
  int i;
  for( i=0; i<n; i++ )
  {
    if (i % 5==0) cout<<endl;                                             // ����һ�����5������
    cout<<"ary["<<i<<"]="<<*(p+i)<<"\t";
  }
  cout<<endl;    
}                                                                         // ���������ú���
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

