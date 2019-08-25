#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int len;
class transfer
{ 
public:
    char *p;
friend void trans(transfer &tr,char*pn);
void print()
{
cout<<p<<endl;
}
};
void trans(transfer &tr,char*pn)
{
tr.p=new char[len+1];
for(int i=0;i<len;i++)
{
if(pn[i]>=97&&pn[i]<=122)
{
tr.p[i]=pn[i]-32;
}
else tr.p[i]=pn[i];
}
}
int main()
{
char *s;
s=new char[1111];
len=0;char ch;
while ( (ch=getchar())!=EOF )
{
if (ch=='\n') break;
s[len]=ch;
len++;
}
s[len+1]='\0';
transfer t;
trans(t,s);
t.print();
}
