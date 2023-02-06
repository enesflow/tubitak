#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> children[100005];
int group[100005]; // 0: not visited, 1: red, 2: blue

void bicolor(int node, int color)
{
    group[node] = color;
    for (int i = 0; i < children[node].size(); i++)
    {
        int child = children[node][i];
        if (group[child] == 0)
        {
            bicolor(child, 3 - color);
        }
    }
}

int32_t main()
{

    int n;
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        // cout<< "at: " << u << " " << v << endl;
        children[u].push_back(v);
        children[v].push_back(u);
    }

    bicolor(1, 2);

    int red = 0, blue = 0;
    for (int i = 1; i <= n; i++)
    {
        if (group[i] == 1)
            red++;
        else
            blue++;
    }

    cout << red * blue - (n - 1) << endl;

    return 0;
}