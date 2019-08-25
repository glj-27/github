#include <iostream>
using namespace std;

int bubble(int arr[], int L, int R) {
	if(L < R) {
		int i;
		for(i=0; i<R; i++) {
			if(arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
		bubble(arr, L, R-1);
	}
}

int main() {
	
	int n, i;
	cout << "请输入数字个数及每一个数：";
	cin >> n;
	int *arr = new int[n];
	for(i=0; i<n; i++) {
		cin >> arr[i];
	}
	bubble(arr, 0,n-1); 
	for(i=0; i<n; i++) {
		cout << arr[i] <<endl;
	}
} 
