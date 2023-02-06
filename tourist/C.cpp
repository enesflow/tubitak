#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int start = 1;

    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == start)
        {
            start++;
        }
        else if (a[i] < start)
        {
            continue;
        }
        else
        {
            cost += a[i] - start;
            start++;
        }
    }

    cout << cost << endl;
}

int32_t main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
        solve();
    return 0;
}