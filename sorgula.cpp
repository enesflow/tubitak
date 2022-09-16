// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
    int s = 0, a = 0, b = 0;
    cin >>s;
    cin >>a;
    cin >>b;
    
    switch (s) {
        case 1:
        if (a != b) cout << 1;
        else cout << 0;
        break;
        case 2:
        if (a%2 == 0 && b%2 == 0) cout << 1;
        else cout << 0;
        break;
        case 3:
        if (a%2== 0 || b%2 == 0) cout << 1;
        else cout << 0;
        break;
        case 4:
        cout << a%b;
        break;
    }
        
        cout << endl;
    }
    return 0;
}
