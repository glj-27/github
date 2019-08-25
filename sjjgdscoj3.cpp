#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
char value[20000];
char a[40000];
int main()
{
	int t ;
	cin>>t;
	int b[10000];
	while (t--){

		int i=0;
		int j=0;
		scanf("%s",a);
		int k =0;
		while (i<strlen(a)){
			while (j!=strlen(a)&&a[j]!=',') j++;
			strncpy(value,a+i,j-i);
			value[j-i]='\0';
		    i=j+1;
		    j=j+1;
		    b[++k] = atoi(value);
		}
		int sum=0;
		for (i=1;i<=k;i++)
			for (j=1;j<k;j++)
				if (b[j]>b[j+1]) {
					sum++;
					swap(b[j],b[j+1]);
				}
		cout<<sum<<endl;
	}
}
