#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n = 0;
	cin >> n;
	vector<int> arr;
	int x = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}
	
	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	
	
	return 0;
}
