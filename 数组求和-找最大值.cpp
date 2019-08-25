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
	cout << "请输入数字个数和每一个数字：";
	int n;
	cin >> n;
	int *arr = new int[n];
	int i;
	for (i=0; i<n; i++) {
		cin >> arr[i];
	}
	int sum = arr_sum(arr, 0, n-1);
	cout << "总和为：" << sum << endl;
	int max = find_max_norec(arr, n);
	cout << "最大值为(非递归)：" << max << endl; 
	int max2 = find_max_rec(arr, 0, n-1);
	cout << "最大值为(递归)：" << max2 << endl; 
}
