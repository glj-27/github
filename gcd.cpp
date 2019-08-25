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
	cout << "请输入两个整数："; 
	cin >> a >> b;
	int g = gcd(a, b);
	cout << "最大公因数为：" << g;
}
