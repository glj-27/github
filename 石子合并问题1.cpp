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
       memset(score,0,sizeof(score));//初始化score数组的值为0 
       for(int i=1;i<=n;i++)
       {
           cin>>stone[i];//stone[i]为每一堆石子的值 
           stone[n+i]=stone[i];//将圆形问题考虑为两条线连接的问题 
       }
       
       for(int i=1;i<=2*n;i++)
        {
            score[i][i]=stone[i];
            for(int j=i+1;j<=2*n;j++)
                score[i][j]=score[i][j-1]+stone[j];//从斜轴线两两相加到右边 
        }
        
       memset(smax,0,sizeof(smax));//初始化smax 
       for(int d=1;d<n;d++)     //d 表示待合并进来的石子个数
       {
           for(int i=1;i<=2*n-d;i++) //i表示合并石子，起始位置
           {
               int j=d+i;      //j表示要合并d个石子，合并序列结束的位置
               smin[i][j]=INT_MAX;  //初始化
               for(int k=i;k<j;k++)
               {
                   smax[i][j]=max(smax[i][j],smax[i][k]+smax[k+1][j]+score[i][j]);
                   smin[i][j]=min(smin[i][j],smin[i][k]+smin[k+1][j]+score[i][j]);
               }
 
           }
       }
       
       maxn=0;
       minn=INT_MAX;
       for(int i=1;i<=n;i++) //2N堆中，求解所有长度为N的连续序列合并最大，最小值
       {
          maxn=max(maxn,smax[i][n+i-1]);
          minn=min(minn,smin[i][n+i-1]);
       }
       cout<<minn<<" "<<maxn;
   }
}
