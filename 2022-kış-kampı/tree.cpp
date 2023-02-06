#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define int long long
#define endl '\n'

using namespace std;

vector<int> tree[50005];
int parent[50005];
int poss[50005];
list<int> leavesList;

int32_t main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    // tree
    int u, v;
    for (int i = 0; i < n - 1; i++)
    {

        cin >> u >> v;

        tree[u].push_back(v);
        leavesList.push_back(v);
        // remove u from leavesList
        leavesList.remove(u);
        parent[v] = u;
    }

    parent[1] = 0;

    int node;
    int prev = 0;
    for (auto i : leavesList)
    {
        node = i;
        for (int i = 0; i < k; i++)
        {
            node = parent[node];
            if (node == 0)
                break;
        }
        if (!node)
            continue;
        poss[node]++;
        cout << "first: " << node << endl;
        while (node != 0)
        {
            prev = poss[node];
            node = parent[node];
            if (node == 0)
                break;
            poss[node] += prev + 1;
            cout << "node: " << node << " poss: " << poss[node] << endl;
        }
    }

    cout << poss[1];
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << poss[i];
        cout << endl;
    }
    cout << endl;
    return 0;
}