#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define int long long
#define endl '\n'

using namespace std;

int32_t main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    list<int> l;
    int f = n % 4;

    vector<int> x = {};

    if (f == 0 || f == 2)
    {
        if (f == 0)
            cout << "0\n";
        else
            cout << "1\n";
        for (int i = 1; i <= n; i++)
        {
            if (i % 4 == 0 || i % 4 == 1)
            {
                x.push_back(i);
            }
        }
    }
    else if (f == 1 || f == 3)
    {
        if (f == 1)
        {
            cout << "1\n";
            for (int i = 1; i <= n / 4 + 1; i++)
                x.push_back(i);
            for (int i = n - (n / 4) + 1; i <= n; i++)
                x.push_back(i);
        }
        else
        {
            cout << "0\n";
            for (int i = 1; i < n / 4 + 1; i++)
                x.push_back(i);
            for (int i = n - (n / 4); i <= n; i++)
                x.push_back(i);
        }
    }

    cout << x.size() << " ";
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }

    return 0;
}