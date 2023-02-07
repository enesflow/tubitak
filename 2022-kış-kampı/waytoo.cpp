#include <bits/stdc++.h>
using namespace std;

int main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // way too long words
    int n;
    cin >> n;
    string s;
    while (n--)
    {
        cin >> s;
        if (s.length() > 10)
        {
            cout << s[0] << s.length() - 2 << s[s.length() - 1];
        }
        else
        {
            cout << s;
        }
        cout << "\n";
    }
    return 0;
}