#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;

map<int, int> m;
int main()
{

    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int x;
    int l = INT_MAX;
    int r = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        m[x]++;
        l = min(l, x);
        r = max(r, x);
    }

    if (l == r)
        cout << "NO";
    else if (r - l + 1 != m.size())
        cout << "NO";

    else
    {
        for (int i = 1 + l; i <= r; i++)
        {
            m[i] -= m[i - 1];

            if (i != r && m[i] <= 0)
            {
                cout << "NO";
                return 0;
            }
        }

        if (m[r] == 0)
            cout << "YES";
        else
            cout << "NO";
    }

    return 0;
}