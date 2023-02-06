#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define int long long
#define endl '\n'

using namespace std;

bool played[1005][1005] = {false};

int32_t main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    double N = n;
    double K = k;

    if (N / K <= 2)
    {
        cout << -1 << endl;
        return 0;
    }

    int ans = k * n;
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        int A = 0;
        for (int j = 1; j <= n; j++)
        {
            if (A >= k)
            {
                break;
            }

            if (i == j)
            {
                continue;
            }

            if (played[i][j])
            {
                continue;
            }

            if (played[j][i])
            {
                continue;
            }

            A++;
            played[i][j] = true;
            played[j][i] = true;
            cout << i << " " << j << endl;
        }
    }

    return 0;
}