#include <iostream>

using namespace std;

long long int MOD = 1000000000 + 7;

long long int fast_pow(long long int a, long long int b) {
		if (b == 0) 
			return 1;
		
		long long int c = fast_pow(a,b/2);
		
		c = (c * c) % MOD;
		
		if (b % 2 == 1)
			c = (c * a) % MOD;
		return c;
}

int main() {
	long long int a = 0;
	long long int b = 0;
	cin >> a;
	cin >> b;
	long long int x = b*b; // fast_pow(b,2);
	cout << fast_pow(a, x);
	
	return 0;
}

