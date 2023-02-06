#include <bits/stdc++.h>
using namespace std;
#define int long long
int find(int n, int x)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += min(n, x / i);
    }
    return ans;
}
int32_t main()
{
    int n;
    cin >> n;
    int l = 1, r = n * n;
    int m = (l + r) / 2;
    int left;
    int d = (n * n + 1) / 2;
    while (l < r)
    {
        m = (l + r) / 2;
        left = find(n, m);
        if (left >= d)
        {
            r = m;
        }
        else if (left < d)
        {
            l = m + 1;
        }
    }
    cout << r << endl;
    return 0;
}