#include<iostream>
#include<iomanip>
using namespace std;
int main() 
{
	double n;
	while(cin>>n)
	cout<<setprecision(2)<<std::fixed<<n<<endl;
	cout<<fixed<<setprecision(2)<<n<<endl;
}
