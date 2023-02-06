#include <bits/stdc++.h>
// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("tune=native,avx2")
////////////
using namespace std;
int32_t main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a[n][m];
    int x;
    char c;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            a[i][j] = c - '0';
        }
    }

    int r[m][n];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            if (a[i][j] == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            r[j][i] = count;
        }
    }
    int answer = 0;
    // print r
    // print r
    for (int i = 0; i < m; i++)
    {
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            v[j] = r[i][j];
        }
        sort(v.begin(), v.end());
        for (int j = 0; j < n; j++)
        {
            answer = max(answer, v[j] * (n - j));
        }
    }
    cout << answer << endl;

    return 0;
}