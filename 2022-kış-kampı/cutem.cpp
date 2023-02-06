#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define int long long

using namespace std;

vector<int> children[100007] = {vector<int>()};
int ans = 0;

int dfs(int node, int parent)
{
    int st = 1; // subtree

    for (int child : children[node])
    {
        if (child != parent)
        {
            st += dfs(child, node);
        }
    }

    if (st % 2 == 0)
    {
        ans++;
        return 0;
    }
    return st;
}

int32_t main()
{

    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int u, v;

    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        children[u].push_back(v);
        children[v].push_back(u);
    }

    if (n % 2)
    {
        cout << -1;
        return 0;
    }

    dfs(1, -1);

    cout << ans - 1; // dunno why -1 but it works

    return 0;
}