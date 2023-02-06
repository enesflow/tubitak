

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans[n + 1][3];
    int a[n + 1][3];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    // init ans
    for (int i = 0; i <= n; i++)
    {
        ans[i][0] = 0;
        ans[i][1] = 0;
        ans[i][2] = 0;
    }

    ans[0][0] = a[0][0];
    ans[0][1] = a[0][1];
    ans[0][2] = a[0][2];

    for (int i = 1; i < n; i++)
    {
        ans[i][0] = max(ans[i - 1][1], ans[i - 1][2]) + a[i][0];
        ans[i][1] = max(ans[i - 1][0], ans[i - 1][2]) + a[i][1];
        ans[i][2] = max(ans[i - 1][0], ans[i - 1][1]) + a[i][2];
    }

    cout << max(ans[n - 1][0], max(ans[n - 1][1], ans[n - 1][2])) << endl;
}
