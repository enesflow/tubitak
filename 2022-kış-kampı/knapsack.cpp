// knapsack problem
#include <iostream>
#include <math.h>

#define int long long

using namespace std;

int32_t main()
{
    int n, w;
    cin >> n >> w;
    int v[n], c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i] >> v[i];
    }

    int dp[n + 1][w + 1];
    // init dp
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (j >= c[i - 1])
            {
                dp[i][j] = max(
                    // take item
                    v[i - 1] + dp[i - 1][j - c[i - 1]],
                    // don't take item
                    dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][w] << endl;

    return 0;
}