#include <iostream>
using namespace std;

long gcd(long a, long b)
{
    long temp = a;
    while(a%b != 0)
	{
        a = b;
        b = temp%b;
        temp = a;
    }
    return b;
}

int main() 
{
    long a , b ;
    cin>>a>>b;
	cout<<gcd(a,b);
    return 0;
}
