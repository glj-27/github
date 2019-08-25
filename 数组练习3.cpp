#include<iostream>
using namespace std;
void rowsum(int a[][4],int nrow)                         //求数组每一行的和 
{
	for(int i=0;i<nrow;i++)
	{
		for(int j=1;j<4;j++)
	    a[i][0]+=a[i][j];
	}
}
int main()
{
	int table[4][4]={{2,8,6,4},{6,8,2,4},{5,6,7,9},{2,5,9,4}}; 
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		cout<<table[i][j]<<'\t';
		cout<<endl;	
    }
    rowsum(table,4);
    for(int i=0;i<4;i++)
    cout<<"第"<<i+1<<"行的和为"<<table[i][0]<<endl;
}
