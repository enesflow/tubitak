#include <iostream>

using namespace std;

int main() {
        
    string word;
    cin >> word;
    if (word[0] >= 'a' && word [0] <= 'z')
    word[0] += ('A' - 'a');
    cout << word;
    return 0;
}
