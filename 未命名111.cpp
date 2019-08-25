#include<iostream>
using namespace std;
int main()
{
	double u;
	double k = 8.913, r0 = 56.1, u0 = 1300.0;
	while (cin >> u) {
		double m;
		m = ((1 + k) / ((k / (1 + k)*(u0 / u) - 1)))*r0;
		cout << m << endl;
		cout << (m + r0) << endl;
	}


    return 0;
}
