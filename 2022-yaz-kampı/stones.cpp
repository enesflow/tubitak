#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    string word;
    cin >> word;
    int count = 0;
    
    for (int i = 0; i < n-1; i++) {
        if (word[i] == word[i+1]) {
            count++;
        }
    }
    cout << count << endl;
}
