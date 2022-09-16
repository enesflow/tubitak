// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    string word;
    for (int i = 0; i < n; i++) {
        cin >> word;
        if (word.size() > 10) {
            cout << word[0] << word.size() - 2 << word[word.size() - 1] << endl;
            continue;
        }
        cout << word << endl;
    }

    return 0;
}
