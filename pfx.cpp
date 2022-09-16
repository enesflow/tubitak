#include <iostream>

using namespace std;

int main() {
	
	int n = 0;
	int q = 0;
	cin >> n;
	int arr[n];
	int pfx[n];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) {
			pfx[i] = arr[i];
		} else {
			pfx[i] = pfx[i-1] + arr[i];
		}
	}
	
	
	cin >> q;
	int l = 0, r = 0;
	
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		if (l == 0) cout << pfx[r];
		else cout << pfx[r] - pfx[l-1];
		cout << "\n";
	}
	
	
	
	return 0;
}
