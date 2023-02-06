#include <iostream>

using namespace std;

int main() {
	
	int q = 0;
	int n = 0;
	cin >> n;
	cin >> q;
	
	int l = 0, r = 0;
	
	int one = 0, two = 0, three = 0;
	
	int food[n];
	int asd[n][3];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			asd[i][j] = 0;
		}
	}
	one = 0; two = 0; three = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> food[i];
		if (food[i] == 1) 
		{
			one ++;
		}
		else if (food[i] == 2)
		{
			two ++;
		}
		else if (food[i] == 3) 
		{
			three ++;
		}
		
		asd[i][0] = one;
		asd[i][1] = two;
		asd[i][2] = three;
	}
	
	
	////////
	
	for (int i = 0; i < q; i++) {
		l = 0, r = 0;
		cin >> l;
		cin >> r;
		
		if (l <= 1) {
			cout << asd[r-1][0] << " " << asd[r-1][1] << " " <<  asd[r-1][2];
		}
		else {
			cout << (asd[r-1][0] - asd[l-2][0]) << " " << (asd[r-1][1] - asd[l-2][1]) << " " <<  (asd[r-1][2] - asd[l-2][2]);
		}
		cout << endl;
	}
	
	
	
	
	return 0;
}
