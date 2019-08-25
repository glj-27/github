#include<iostream>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int> q1;//大顶堆 
	priority_queue<int,vector<int>,greater<int> >q2;//小顶堆
	
	int k;
	cin>>k;
	int x;
	for(int i=0;i<k;i++)
	{
		cin>>x;
		q1.push(x);//入栈 
		q2.push(x);//入栈 
	}

	int sum=0;
	int max=0,min=0;
	int a=0,b=0;
	k=k-1;
	while(k--)
	{
		a=q1.top();//a=第一大 
		q1.pop();//第一大出栈 
		b=q1.top();//b=第二大 
		q1.pop();
		sum=a+b;
		max+=(sum-1);
		q1.push(sum);//之和入栈 
		
		a=q2.top();//a=第一小 
		q2.pop();//第一小出栈 
		b=q2.top();//b=第二小 
		q2.pop();//第二小出栈
		sum=a+b;
		min+=(sum-1);
		q2.push(sum);//之和入栈
	}
	cout<<max<<" "<<min;
} 
