#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define int long long
#define endl '\n'

using namespace std;

// initialize array of vectors whose are empty
vector<int> children[50005] = {};
int dp[50005][505];
int ans = 0;
int k;

void dfs(int node, int parent)
{
    dp[node][0] = 1;
    int c;

    for (int child = 0; child < children[node].size(); child++)
    {
        c = children[node][child];
        if (c == parent)
            continue;
        dfs(c, node);

        for (int i = 0; i < k; i++)
        {

            ans += dp[node][i] * dp[c][k - i - 1];
        }

        for (int i = 1; i <= k; i++)
        {
            dp[node][i] += dp[c][i - 1];
        }
    }
}

int32_t main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin >> k;

    int u, v;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        children[u].push_back(v);
        children[v].push_back(u); // <-- Forgot to add this line
    }

    if (k == 1)
        cout << n - 1;
    else
    {
        dfs(1, -1);

        cout << ans << endl;
    }

    return 0;
}