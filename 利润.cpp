#include<iostream>
using namespace std;
int main()
{
	double i,a;
	cin>>i;
	if(i<=100000) a=i*.1 ,cout<<"奖金总数="<<a<<endl;
	else if(i>100000&&i<200000) a=100000*.1+(i-100000)*.07 ,cout<<"奖金总数="<<a<<endl;
	else if(i>200000&&i<400000) a=100000*.1+100000*.07+(i-200000)*.04 ,cout<<"奖金总数="<<a<<endl;
    else if(i>400000) a=100000*.1+100000*.07+200000*.04+(i-400000)*.01 ,cout<<"奖金总数="<<a<<endl;
	
} 
