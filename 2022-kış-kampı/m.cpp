#include <bits/stdc++.h>
using namespace std;
vector<int> c[1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, x;
    int u, v;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        for (int i = 1; i < n; i++)
        {
            // cout << "entering " << i << endl;
            cin >> u >> v;
            /* cout << u << " " << v << endl; */
            c[u].push_back(v);
            c[v].push_back(u);
        }

        /* for (int i = 1; i <= n; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < c[i].size(); j++)
            {
                cout << c[i][j] << " ";
            }
            cout << endl;
        } */

        if (c[x].size() == 1 || n == 1)
        {
            cout << "Ayush" << endl;
        }

        else if (n % 2 == 0)
        {
            cout << "Ayush" << endl;
        }
        else
        {
            cout << "Ashish" << endl;
        }

        // clear the graph
        for (int i = 1; i <= n; i++)
        {
            c[i].clear();
        }
    }
}