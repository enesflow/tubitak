#include <bits/stdc++.h>
using namespace std;
// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("tune=native,avx2")

int main()
{

    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int cnt = 0;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            cnt++;
        }
    }
    if (s[s.size() - 1] == '1')
    {
        if ((cnt - 1) % 2 == 0)
            cnt--;
    }
    cout << cnt << endl;

    return 0;
}