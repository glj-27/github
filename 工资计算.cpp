#include<iostream>
using namespace std;
int main()
{
	int S;
	double x;
	while(cin>>S)
	if ( S <= 2000)
	x = S, cout << x << endl;
	else if (S > 2000 && S <= 5000)
	x = 2000 + S*0.08, cout << x << endl;
	else if (S > 5000 && S <= 10000)
	x = 2000 + S*0.1, cout << x << endl;
	else if (S > 10000 )
	x = 2000 + S*0.12, cout << x << endl;
}
