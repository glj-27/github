
#include<iostream>
#include<cstring>
using namespace std;
 
int map[50][50];
bool v[50],k;
int n,m,i,j;
 
void Init()
{
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		 	map[i][j] = 0;
} 
 
void ser(int i)
{
	if(k) return;
	for(j=0;j<n;j++)
	{
		if(!v[i] && map[i][j])
		{
			v[i] = true;
			ser(j);
			v[i] = false;
		}
		else if(map[i][j]) k = true;
	}
}
 
int main()
{
	int x;
	while(x--)
	{
	cin>>n>>m;
	char a[50];
	k = false;
	memset(v,false,sizeof(v));
	for(i=0;i<n;i++)
	cin>>a[i];
	Init();
	for(i=0;i<m;i++)
	{
		char ch1,ch2;
		cin>>ch1>>ch2;
		map[ch1-'A'][ch2-'A'] = 1;
	}
	ser(0);
	if(k) cout<<"YES";
	else cout<<"NO";
	}
	return 0;
		
}

