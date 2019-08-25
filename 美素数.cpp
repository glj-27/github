#include<iostream>
#include<cmath> 
using namespace std;
int sushu(int a)
{ int i=2;
 if(a==1)return 0;
 while(i<=sqrt(a))
 {
  if(a%i==0)return 0;
  i++;
 }
	 return 1;
}
int qiuhe(int a)
{
 int b;
 for(b=0;a>=1;a=a/10)
 {
  b=b+a%10;
 }
 return b;
}
int main()
{ 
 int a,b,c,sum,n,i;
 cin>>n;
 for(i=1;i<=n;i++)
 {
  cin>>a>>b;
  for(c=a,sum=0;c<=b;c++)
  if(sushu(c)&&sushu(qiuhe(c)))sum++;
  cout<<"Case #"<<i<<": "<<sum<<endl;
 }

}

