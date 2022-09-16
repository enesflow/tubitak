// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int q = 0;
    cin >> q;
    int arr[n];
    int x;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> x;
        
        int m = 0;
        int left = 0;
        int right = n -1;
        
        while (left <= right) {
            m = (left+right) / 2;
            
            if (arr[m] == x) {
                cout << m + 1 << endl;
                break;
            }
            if (x > arr[m]) {
                left = m+1;
            }
            if (x < arr[m]) {
                right = m-1;
            }
            
        }
        if (arr[m] != x) {
            cout << 0 << endl;
        }
        
    }

    return 0;
}
