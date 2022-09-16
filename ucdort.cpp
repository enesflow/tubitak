
#include <iostream>
using namespace std;
int main() {
    
    int arr[] = {4,0,0,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int fs[n];
    for (int i = 0; i < n; i++) {
        fs[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 4) {
            fs[i] = 4;
        }
        
    }
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == 3) {
            for (int j = 0; j < n; j++) {
                if (fs[j] == 4) {
                    fs[j] = 0;
                    if (j-1 >= 0) {
                        if (arr[j-1] != 4) {
                            int tmp = arr[j-1];
                            arr[j-1] = 3;
                            arr[i] = tmp;
                            break;
                        }
                    } else if (i + 1 < n) {
                        fs[j] = 0;
                        int tmp = arr[i+1];
                        arr[i+1] =4;
                        arr[j] = tmp;
                        break;
                    } else {
                        fs[j] = 0;
                        for (int k = n-1; k > 0; k--) {
                            arr[k] = arr[k-1];
                        }
                        arr[0] = 3;
                    }
                }
            }
        }  
    }
    
    
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
