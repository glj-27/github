#include <tchar.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
 
using namespace std;
 
void calculatePrime(int n,int* prime_num)
{
	if(n>3)
	{
		calculatePrime(sqrt((float)n),prime_num);
	}
	for(int i=2; i<=sqrt((float)n); i++)
	{
		if(prime_num[i]!=0)
		{
			for(int j=2; j<=n/prime_num[i]; j++)
			{
				prime_num[j*prime_num[i]]=0;
			}
		}
	}
}
 
int _tmain(int argc, _TCHAR* argv[])
{
	int n, sqrt_n;
 
	cin >> n;
	sqrt_n = sqrt((float)n);
	int* prime_num = new int[n+1];
 
	for(int i=0; i<n+1; i++)
		prime_num[i] = i;
	calculatePrime(n,prime_num);
 
	for(int i=2; i<n+1; i++)
	{
		if(prime_num[i]!=0)
		cout << prime_num[i] << " ";
	}
	cout << endl;
	return 0;
}
