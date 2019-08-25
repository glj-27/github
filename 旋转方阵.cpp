#include<iostream>
using namespace std;
int main()
{
    int M,N,flag=0,num1=0,num2=1,i=0,j=0;
    int str=1;
    int Array[31][31];
    cin>>M>>N;
    Array[0][0]=str;
    while(flag < M*N-1)
    {
      switch(num2%4)
      {
       case 1:
       ++j;
       if(j == N-num1-1){num2++;}break;
       case 2:
       ++i;
       if(i == M-num1-1){num2++;}break;
       case 3:
       --j;
       if(j == num1){num2++;}break;
       case 0:
       --i;
       if(i == num1+1){num2++;num1++;}break;
      }
      if(++str == 1)
      str=1;
      Array[i][j]=str;
      flag++;
    }
    for(i=0;i<M;i++)
    {
       for(j=0;j<N;j++){cout<<Array[i][j]<<'\t';}
       cout<<endl; 
    }
}
