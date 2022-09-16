#include <iostream>

using namespace std;

int findmin(int arr[], int l, int r) {
		if (l == r) return arr[l];
		
		int m = (l+r)/2;
		
		int leftmin = findmin(arr, l, m);
		int rightmin = findmin(arr, m+1, r);
		
		if (leftmin < rightmin) return leftmin;
		return rightmin;
}

int findmax(int arr[], int l, int r) {
		if (l == r) return arr[l];
		
		int m = (l+r)/2;
		
		int leftmax = findmax(arr, l, m);
		int rightmax = findmax(arr, m+1, r);
		
		if (leftmax > rightmax) return leftmax;
		return rightmax;
}

int main() {
		int n = 0;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		cout << findmax(arr, 0, n-1) - findmin(arr, 0, n-1);
	
		return 0;
}
