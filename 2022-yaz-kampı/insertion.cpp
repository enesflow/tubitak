
#include <iostream>
using namespace std;
int main() {
    
    int arr[] = {6,5,4,7,3,8,2,1,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    for (int i = 1; i < n; i++) {
        int j = i-1;
        int key = arr[i];
        while (j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
