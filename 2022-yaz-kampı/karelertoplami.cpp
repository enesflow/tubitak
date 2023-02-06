// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int x = 0;
    int total = 0;
    cin >> x;
    
    for (int i = 1; i <= x; i++) {
        total += (i*i);
    }
    cout << total << endl;

    return 0;
}
