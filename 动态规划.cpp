#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
using namespace std;

#include<malloc.h>
#include<string.h>
#include<stdlib.h>

int ** Get2Array(int n, int m)
{
    int **s = (int**)malloc(sizeof(int*)*n);
    for (int i = 0; i<n; ++i)
    {
        s[i] = (int*)malloc(sizeof(int)*m);
        memset(s[i], 0, sizeof(int)*m);
    }
    return s;
}

void Free2Array(int **p, int n)
{
    for (int i = 0; i<n; ++i)
    {
        free(p[i]);
    }
    free(p);
}

void Print_2Array(int **p, int n, int m)
{
    for (int i = 0; i<n; ++i)
    {
        for (int j = 0; j<m; ++j)
        {
            cout << setw(7) << p[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

//////////////////////////////////////
void MatrixMul(int **a, int **b, int **c,//a*b=c
    int ra, int ca, int rb, int cb)
{
    if (ca != rb) return;
    for (int i = 0; i<ra; ++i)
    {
        for (int j = 0; j<cb; ++j)
        {
            int tmp = 0;
            for (int k = 0; k<ca; ++k)
            {
                tmp += a[i][k] * b[k][j];
            }
            c[i][j] = tmp;
        }
    }
}//矩阵相乘


void Backtrack(int **s, int i, int j)//s 1 6
{//关于1 到6 的最优解
    if (i < j)
    {
        Backtrack(s, i, s[i][j]);//递归1到s[1][6]//这里存储的是最后一个段点，先递归前面的
        Backtrack(s, s[i][j] + 1, j);
        cout << "Matrix A " << i << " , " << s[i][j] << " and A ";
        cout << s[i][j] + 1 << " , " << j << endl;
    }
}


int MatrixChain2(int *p, int n, int **m, int **s)//6个矩阵
{//                  p    6          m      s
    int i, j;
    for (i = 1; i <= n; ++i) m[i][i] = 0;//对角线上的元素都设置成0，1~6
    for (int len = 2; len <= n; ++len)//2~6 3
    {//从二开始断12 23 34 45 56                                                                                                                                     
        for (i = 1; i <= n - len + 1; ++i)//1~5
        {//1 2
            j = i + len - 1;//1+2-1 = 2 3  2
            //1 2            2/3     2/3        0/1        1/2      2/3
            //1 3            2 3             0     1        3   
            m[i][j] = 0 + m[i + 1][j] + p[i - 1] * p[i] * p[j];//计算出m[1][2]就是1~2的值
            s[i][j] = i;//s[1][2] = 1
            for (int k = i + 1; k < j; ++k)//遍历i,j之间j-1个位置,然后进行比较
            {//2                     3
                //        1 2         3    3        0         2    3   
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (m[i][j] > t)
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
        Print_2Array(m, n + 1, n + 1);
    }
    return m[1][n];
}


int main()
{
    const int n = 6;
    int p[n + 1] = { 20,10,35,15,40,25,30 };//30*35 35*15 15*5 5*10 10*20 20*25
    int **m = Get2Array(n + 1, n + 1);//7*7 0~6
    int **s = Get2Array(n + 1, n + 1);
    int min = MatrixChain2(p, n, m, s);
    cout << "Min: " << min << endl;
    Print_2Array(m, n + 1, n + 1);
    Print_2Array(s, n + 1, n + 1);

    Backtrack(s, 1, n);
    return 0;
}
