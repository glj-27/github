#include <iostream>
using namespace std;

int add1(int a) {
	return a++; 
}

int add2(int *a) {
	return (*a)++; 
}

int main() {
	int a = 1, b = 1;
	add1(a);
	cout << a << endl;
	add2(&b);
	cout << b << endl;
} 
