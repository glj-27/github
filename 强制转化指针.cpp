#include<iostream>
 using namespace std;
 int main()
 {
 	int a=65;
 	int *ip;
 	void *vp=&a;
 	cout<<*(int*)vp<<endl;
 	cout<<*(char*)vp<<endl;
 	ip=(int*)vp;
 	cout<<*ip<<endl;
 }
