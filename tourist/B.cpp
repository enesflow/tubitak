#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n, w, h;
    cin >> n >> w >> h;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int maxdiff = INT_MIN;
    int mindiff = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int diff = a[i] - b[i];
        maxdiff = max(maxdiff, diff);
        mindiff = min(mindiff, diff);
    }

    int diffdiff = maxdiff - mindiff;

    if (diffdiff > (w - h) * 2)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int32_t main()
{
    // fastio
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
        solve();
    return 0;
}