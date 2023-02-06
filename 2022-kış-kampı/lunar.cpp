// painting

#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;

#define int long long

int32_t main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int x;
    vector<set<int>> v = vector<set<int>>(n);
    int d[1005] = {0};
    int maxd = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[d[x]].insert(x);
        d[x]++;
        maxd = max(d[x], maxd);
    }

    int t = 0;
    for (int i = 0; i < maxd; i++)
    {
        t += v[i].size() - 1;
    }
    cout << t;
    return 0;
}