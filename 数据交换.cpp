#include<iostream>
using namespace std;
void swap(int& a,int& b)         //ÒıÓÃ´«µİ 
{
	int t;
	t=a;a=b;b=t;
}
int main()
{   
    int x=2,y=4;
	cout<<"x="<<x<<'\t'<<"y="<<y<<endl;
	swap(x,y);
	cout<<"x="<<x<<'\t'<<"y="<<y<<endl;
}
