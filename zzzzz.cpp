#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;

#define int long long
int32_t main()
{

    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        int x, l, r;
        int total = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int L = 0; L < m; L++)
        {
            cin >> x;
            if (x == 1)
            {
                cin >> l >> r;

                for (int j = l - 1; j <= r - 1; j++)
                {
                    total = 0;

                    // sum digits of a[j]
                    while (a[j] > 0)
                    {
                        total += a[j] % 10;
                        a[j] /= 10;
                    }

                    a[j] = total;
                }
            }
            else
            {
                cin >> l;
                cout << a[l - 1] << endl;
            }
        }
    }
    return 0;
}