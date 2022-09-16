#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int x = 0;
    if (n == 0) {cout << 0; return 0;}
    if (n % 5 == 0) {cout << n / 5; return 0;}
    cout << n/5+1;
    return 0;
}
