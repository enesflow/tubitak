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

    int n;
    cin >> n;
    int x;

    int a[n];

    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
    }

    sort(a, a + n);

    int sum = 0;

    for (auto i : a)
    {
        if (sum + 1 < i)
        {
            cout << sum + 1;
            return 0;
        }
        else
        {
            sum += i;
        }
    }

    cout << sum + 1;

    return 0;
}