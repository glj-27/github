#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits.h>
using namespace std;
int main()
{
   int stone[200];
   int score[200][200];
   int smax[200][200];
   int smin[200][200];
   int maxn,minn;
   int n;
   while(cin>>n)
   {
       memset(score,0,sizeof(score));//��ʼ��score�����ֵΪ0 
       for(int i=1;i<=n;i++)
       {
           cin>>stone[i];//stone[i]Ϊÿһ��ʯ�ӵ�ֵ 
           stone[n+i]=stone[i];//��Բ�����⿼��Ϊ���������ӵ����� 
       }
       
       for(int i=1;i<=2*n;i++)
        {
            score[i][i]=stone[i];
            for(int j=i+1;j<=2*n;j++)
                score[i][j]=score[i][j-1]+stone[j];//��б����������ӵ��ұ� 
        }
        
       memset(smax,0,sizeof(smax));//��ʼ��smax 
       for(int d=1;d<n;d++)     //d ��ʾ���ϲ�������ʯ�Ӹ���
       {
           for(int i=1;i<=2*n-d;i++) //i��ʾ�ϲ�ʯ�ӣ���ʼλ��
           {
               int j=d+i;      //j��ʾҪ�ϲ�d��ʯ�ӣ��ϲ����н�����λ��
               smin[i][j]=INT_MAX;  //��ʼ��
               for(int k=i;k<j;k++)
               {
                   smax[i][j]=max(smax[i][j],smax[i][k]+smax[k+1][j]+score[i][j]);
                   smin[i][j]=min(smin[i][j],smin[i][k]+smin[k+1][j]+score[i][j]);
               }
 
           }
       }
       
       maxn=0;
       minn=INT_MAX;
       for(int i=1;i<=n;i++) //2N���У�������г���ΪN���������кϲ������Сֵ
       {
          maxn=max(maxn,smax[i][n+i-1]);
          minn=min(minn,smin[i][n+i-1]);
       }
       cout<<minn<<" "<<maxn;
   }
}
