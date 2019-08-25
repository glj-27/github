#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
 
#define  MAXN 100
int sum[MAXN];
int mins[MAXN][MAXN], maxs[MAXN][MAXN];
int INTMAX=9999999;
int n, stone[MAXN];
 
int sums(int i, int j) 
{
	if(i + j >= n) {
		return sums(i, n - i - 1) + sums(0, (i + j) % n);
	} else {
		return sum[i + j] - (i > 0 ? sum[i - 1] : 0);
	}
}
 
void getBest(int& minnum, int& maxnum) {
	//��ʼ����û�кϲ�������Ϊ0
	for(int i = 0; i < n; ++i) {
		mins[i][0] = maxs[i][0] = 0;
	}
	//������кϲ�����
	for(int j = 1; j < n; ++j) {
		for(int i = 0; i < n; ++i) {
			mins[i][j] = INTMAX;
			maxs[i][j] = 0;
			for(int k = 0; k < j; ++k) {
	mins[i][j] = min(mins[i][k] + mins[(i + k + 1)%n][j - k - 1] + sums(i, j), mins[i][j]);
	maxs[i][j] = max(maxs[i][k] + maxs[(i + k + 1)%n][j - k - 1] + sums(i, j), maxs[i][j]);
				
			}
		}
	}
	minnum = mins[0][n - 1];
	maxnum = maxs[0][n - 1];
	for(int i = 0; i < n; ++i) {
		minnum = min(minnum, mins[i][n - 1]);
		maxnum = max(maxnum, maxs[i][n - 1]);
	}
	
}
 
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &stone[i]);
 
	sum[0] = stone[0];
	for(int i = 1; i < n; ++i) {
		sum[i] = sum[i - 1] + stone[i];
	}
	int minnum, maxnum;
	getBest(minnum, maxnum);
	cout<<minnum<<"  "<<maxnum;
	return 0;
}
