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

        int n;
        cin >> n;
        int a[n];
        int toplam = 0;
        int negatif = 0;
        bool zero = false;
        int minimum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            toplam += abs(a[i]);
            if (a[i] < 0)
                negatif++;
            if (a[i] == 0)
                zero = true;
            minimum = min(minimum, abs(a[i]));
        }
        toplam = abs(toplam);

        if (zero || negatif % 2 == 0)
        {
            cout << toplam << endl;
        }
        else

        {
            cout << toplam - 2 * minimum << endl;
        }
    }
    return 0;
}