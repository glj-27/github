#include <iostream>
using namespace std;
int gcd(int a, int b) {
	int r = 0;
	r = a % b;
	if(r == 0) {
		return b;
	}
	else {
		return gcd(b, r);
	}
} 

int main() {
	int a, b;
	cout << "����������������"; 
	cin >> a >> b;
	int g = gcd(a, b);
	cout << "�������Ϊ��" << g;
}
