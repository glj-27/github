#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <deque>
#include <set>
#define MAX 0x3f3f3f3f
#define fori(a,b) for(LL i=a;i<=b;i++)
#define forj(a,b) for(LL j=a;j<=b;j++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
const double PI = acos(-1);
const LL M=5e5+10;
deque <char> dq;
int t,len1=0,len2=0;
int judge(int st,int en,char s[]){//用来判断两个串中注意里面的情况
                                  //如果右边大一点，就返回0，否则返回1
    while(s[st]==s[en]&&st<en){
        st++,en--;
    }
    if(st<en){
        if(s[st]>s[en])
            return 1;
    }
    return 0;
}
int judge1(char a1[],char a2[],int st,int pos)//合成的时候
{
    while(st<len1&&pos<len2&&a1[st]==a2[pos]){
        st++,pos++;
    }
    if(st<len1&&pos<len2){
        if(a1[st]>a2[pos])
            return 1;
    }
    if(st>=len1&&pos<len1){
        if(a1[len1-1]>a2[pos])
            return 1;
 
    }
    if(st<len1&&pos>=len2){
        if(a1[st]>a2[len2-1])
            return 1;
    }
    return 0;
}
 
int main()
{
    char s1[144],s2[144];
    cin>>t;
    for(int cnt=1;cnt<=t;cnt++)
    {
        char a1[188],a2[188];
        mem(a1,0);
        mem(a2,0);
        mem(s1,0);
        mem(s2,0);
        int e=0;
        cin>>s1>>s2;
        len1=strlen(s1);
        len2=strlen(s2);
        int st=0,en=len1-1;
        while(st<=en){//先把第一个串按照规则拿出来
            if(st==en){
                a1[e++]=s1[st];
                st++;
                break;
            }
            if(s1[st]>s1[en]){
                a1[e++]=s1[st];
                st++;
            }
            else if(s1[st]<s1[en]){
                a1[e++]=s1[en];
                en--;
 
            }
            else {
                if(st+1==en){
                    a1[e++]=s1[st];
                    a1[e++]=s1[en];
                    st++,en--;
                    break;
                }
                if(s1[st+1]>s1[en-1]){
                    a1[e++]=s1[st];
                    st++;
                }
                else if(s1[st+1]<s1[en-1]){
                    a1[e++]=s1[en];
                    en--;
                }
                else {
                    int flag=judge(st,en,s1);
                    if(flag){
                        a1[e++]=s1[st];
                        st++;
                    }
                    else {
                        a1[e++]=s1[en];
                        en--;
                    }
                }
            }
        }
        a1[e]=0;
        e=0;
        st=0,en=len2-1;
        while(st<=en){//将第二个串按照规则拿出来
            if(st==en){
                a2[e++]=s2[st];
                st++;
                break;
            }
            if(s2[st]>s2[en]){
                a2[e++]=s2[st];
                st++;
            }
            else if(s2[st]<s2[en]){
                a2[e++]=s2[en];
                en--;
 
            }
            else {
                if(st+1==en){
                    a2[e++]=s2[st];
                    a2[e++]=s2[en];
                    st++,en--;
                    break;
                }
                if(s2[st+1]>s2[en-1]){
                    a2[e++]=s2[st];
                    st++;
                }
                else if(s2[st+1]<s2[en-1]){
                    a2[e++]=s2[en];
                    en--;
                }
                else {
                    int flag=judge(st,en,s2);
                    if(flag){
                        a2[e++]=s2[st];
                        st++;
                    }
                    else {
                        a2[e++]=s2[en];
                        en--;
                    }
                }
            }
        }
        a2[e]=0;
        //cout << a1 << " " << a2 << endl;
        char ans[188];
        mem(ans,0);
        int pos=0;
        e=0;
        st=0;
        while(st<=len1-1){//合成
            if(a1[st]>a2[pos]){
                ans[e++]=a1[st];
                st++;
            }
            else if(a1[st]<a2[pos]){
                ans[e++]=a2[pos];
                pos++;
            }
            else {
                if(st==len1-1){
                    for(int i=pos;i<=len2-1;i++){
                        if(a1[st]<=a2[i]){
                            ans[e++]=a2[i];
                            pos++;
                        }
                        else {
                            pos=i;
                            ans[e++]=a1[st];
                            st++;
                            for(int j=pos;j<len2;j++){
                                ans[e++]=a2[j];
                                pos++;
                            }
                            ans[e]=0;
                            break;
                        }
                    }
                    if(pos==len2){
                        for(int j=st;j<len1;j++){
                            ans[e++]=a1[j];
                            st++;
                        }
                        break;
                    }
 
                }
                if(pos==len2-1){
                    for(int i=st;i<=len1-1;i++){
                        if(a2[pos]<=a1[i]){
                            ans[e++]=a1[i];
                            st++;
                        }
                        else {
                            st=i;
                            ans[e++]=a2[pos];
                            pos++;
                            for(int j=st;j<len1;j++){
                                ans[e++]=a1[j];
                                st++;
                            }
                            ans[e]=0;
                            break;
                        }
                    }
                    if(st==len1){
                        for(int j=pos;j<len2;j++){
                            ans[e++]=a2[j];
                            pos++;
                        }
                        break;
                    }
 
                }
                int flag=judge1(a1,a2,st,pos);
                if(flag){
                    ans[e++]=a1[st];
                    st++;
                }
                else {
                    ans[e++]=a2[pos];
                    pos++;
                }
 
            }
        }
        //最后剩下的接到ans后面
        if(pos<len2){
            for(int j=pos;j<len2;j++){
                ans[e++]=a2[j];
            }
        }
        if(st<len1){
            for(int j=st;j<len1;j++){
                ans[e++]=a1[j];
            }
        }
        printf("Case #%d: ",cnt);
        cout << ans <<endl;
    }
    return 0;
}
