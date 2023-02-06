#include <bits/stdc++.h>
// codeforces problem 1098A
using namespace std;
#define int long long
int n;
vector<int> parent(100005);
vector<int> children[100005];
vector<int> s(100005);
int ans = 0;

void oops()
{
    cout << -1 << endl;
    exit(0);
}

void dfs(int node)
{
    if (s[node] == -1)
    {
        int n = s[parent[node]];
        if (children[node].size() != 0)
        {
            int m = 1000000000;
            for (int c : children[node])
            {
                m = min(m, s[c]);
            }
            if (m < n)
                oops();
            s[node] = s[parent[node]] + m - n;
            ans += m - n;
        }
    }
    else
    {
        if (!node)
        {
            ans += s[node];
        }
        else
        {
            ans += s[node] - s[parent[node]];
        }
    }

    for (int c : children[node])
    {
        dfs(c);
    }
}

int32_t main()
{
    cin >> n;
    int p;
    for (int i = 1; i < n; i++)
    {
        cin >> p;
        parent[i] = p - 1;
        children[p - 1].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    dfs(0);
    cout << ans << endl;

    return 0;
}