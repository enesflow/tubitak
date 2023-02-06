// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] = a[i] + (abs('a' - 'A'));
        }
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'u' || a[i] == 'o' || a[i] == 'y') {
            
            a[i] = '0';
        }
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '0') {
            continue;
        }
        cout << "." << a[i];
    }
    cout << endl;
    return 0;
}
