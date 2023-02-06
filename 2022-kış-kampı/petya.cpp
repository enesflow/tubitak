#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;

#define int long long

int f(int a[], int in)
{
    if (in >= in) // n
        return 0;

    int dif = a[in] - a[in + 1];

    return abs(dif) + f(a, in + 1);
}

int32_t main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int total = 0;
    bool locked[n + 1] = {false};

    for (int i = 0; i < n - 1; i++)
    {

        if (a[i] > a[i + 1])
        {
            if (locked[i])
            {
                total += abs(a[i] - a[i + 1]);
            }
            else
            {
                locked[i + 1] = true;
                total += abs(a[i] - a[i + 1]);
            }
        }
    }

    cout << total;

    return 0;
}