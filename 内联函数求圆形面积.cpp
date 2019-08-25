#include<iostream>
using namespace std;
const double PI=3.1415;
inline double calarea(double radius) {return PI*radius*radius;}
int main()
{
	double r;
	cout<<"radius=";
	cin>>r;
	double area=calarea(r); 
	cout<<"area="<<area<<endl;
	return 0;
} 
