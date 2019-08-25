#include <iostream>
using namespace std;
int arr_sum(int arr[], int L, int R) {
	int sum = 0;
	if (L==R) {
		return arr[L];
	}
	else {
		sum = arr[L] + arr_sum(arr, L+1, R);
	}
}

int find_max_norec(int arr[],int n) {
	int max = arr[0];
	int i;
	for(i=0; i<n; i++) {
		if(max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

int find_max_rec(int arr[], int L, int R) {
	int max = 0;
	if(L == R) {
		return arr[L];
	}
	else {
		int a = arr[L];
		int b = find_max_rec(arr, L+1, R);
		if(a > b) {
			return a;
		}
		else {
			return b;
		}
 	}
}

int main() {
	cout << "���������ָ�����ÿһ�����֣�";
	int n;
	cin >> n;
	int *arr = new int[n];
	int i;
	for (i=0; i<n; i++) {
		cin >> arr[i];
	}
	int sum = arr_sum(arr, 0, n-1);
	cout << "�ܺ�Ϊ��" << sum << endl;
	int max = find_max_norec(arr, n);
	cout << "���ֵΪ(�ǵݹ�)��" << max << endl; 
	int max2 = find_max_rec(arr, 0, n-1);
	cout << "���ֵΪ(�ݹ�)��" << max2 << endl; 
}
