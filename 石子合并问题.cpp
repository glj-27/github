#include<iostream>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int> q1;//�󶥶� 
	priority_queue<int,vector<int>,greater<int> >q2;//С����
	
	int k;
	cin>>k;
	int x;
	for(int i=0;i<k;i++)
	{
		cin>>x;
		q1.push(x);//��ջ 
		q2.push(x);//��ջ 
	}

	int sum=0;
	int max=0,min=0;
	int a=0,b=0;
	k=k-1;
	while(k--)
	{
		a=q1.top();//a=��һ�� 
		q1.pop();//��һ���ջ 
		b=q1.top();//b=�ڶ��� 
		q1.pop();
		sum=a+b;
		max+=(sum-1);
		q1.push(sum);//֮����ջ 
		
		a=q2.top();//a=��һС 
		q2.pop();//��һС��ջ 
		b=q2.top();//b=�ڶ�С 
		q2.pop();//�ڶ�С��ջ
		sum=a+b;
		min+=(sum-1);
		q2.push(sum);//֮����ջ
	}
	cout<<max<<" "<<min;
} 
