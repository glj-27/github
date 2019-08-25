#include<iostream>
using namespace std;//声明命名空间
void counta(int);
int main()
{
    int a;
    cin>>a;
    counta(a);
}
void counta(int k)
{
    int count[10]={0};
    int i=0,j;
    for(;k!=0;)//循环条件是k!=0
    {
        i=k%10;
       count[i]++;
        k/=10;
    }
    for(j=0;j<10;j++)
        cout<<count[j]<<" "<<endl;
}
