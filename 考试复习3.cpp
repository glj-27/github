#include<iostream>
using namespace std;//���������ռ�
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
    for(;k!=0;)//ѭ��������k!=0
    {
        i=k%10;
       count[i]++;
        k/=10;
    }
    for(j=0;j<10;j++)
        cout<<count[j]<<" "<<endl;
}
