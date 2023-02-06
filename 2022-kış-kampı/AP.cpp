#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;

int m[1005][1005];
int dp[1005][1005];

int main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    char c;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            if (c == '.')
                m[i][j] = 0;
            else
                m[i][j] = 1;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (m[i][j])
                continue;

            if (i == n - 1 && j == n - 1)
            {
                dp[i][j] = 1;
                continue;
            }

            if (i == n - 1)
            {
                dp[i][j] = dp[i][j + 1];
                continue;
            }

            if (j == n - 1)
            {
                dp[i][j] = dp[i + 1][j];
                continue;
            }

            dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % 1000000007;
        }
    }

    cout << dp[0][0];
    return 0;
}