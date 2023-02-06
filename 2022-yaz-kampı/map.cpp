#include <bits/stdc++.h>

using namespace std;

int main() {

	int n = 0;
	cin >> n;
	string s;
	
	map<string, int> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (m.count(s) == 0)
			m[s] = 1;
		else 
			m[s]++;
			
	}
	
	int q = 0;
	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> s;
		cout << m[s] << "\n";
	}
	return 0;
}
