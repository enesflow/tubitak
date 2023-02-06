// MY FAVOURITE PROBLEM
#include <bits/stdc++.h>

// optimize for maximum performance
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
const int LOG = 20;
vector<int> children[200005];

// memory efficient binary lifting
// int up[LOG][200005];
// make the code above memory efficient
vector<vector<int>> up(LOG, vector<int>(200005));

int ithParent(int node, int i) // get ith parent of node using binary lifting
{
    for (int j = 0; j < LOG; j++)
    {
        if (i & (1 << j))
        {
            node = up[j][node];
            // node = up[node][j]; // 2^j th parent
        }
    }
    return node;
}

void initialize(int node, int parent) // initialize up array using binary lifting
{
    up[0][node] = parent;
    // up[node][0] = parent;
    for (int i = 1; i < LOG; i++)
    {
        up[i][node] = up[i - 1][up[i - 1][node]];
        // up[node][i] = up[up[node][i - 1]][i - 1];
    }
}

int32_t main()
{

    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    int x;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        children[x].push_back(i + 2);
    }
    initialize(1, -1);
    queue<int> Q;
    Q.push(1);
    while (!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        for (int child : children[node])
        {
            initialize(child, node);
            Q.push(child);
        }
    }
    int y;
    for (int Q = 0; Q < q; Q++)
    {
        int node, k;
        cin >> node >> k;
        y = ithParent(node, k);
        if (y)
            cout << y << endl;
        else
            cout << -1 << endl;
    }
}