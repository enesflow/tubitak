#include <iostream>
#include <math.h>

#define int long long

using namespace std;

int32_t main()
{
    int n, m;
    cin >> n >> m;
    int d[n + 3];
    // init dp
    for (int i = 0; i <= n + 2; i++)
    {
        d[i] = 0;
    }

    int a[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        d[a[i]] = -1;
    }

    d[n] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (d[i] == -1)
        {
        }

        else if (d[i + 1] == -1)
        {
            d[i] = d[i + 2];
        }
        else if (d[i + 2] == -1)
        {
            d[i] = d[i + 1];
        }
        else
        {
            d[i] = d[i + 1] + d[i + 2];
        }
        d[i] %= 1000000007;
    }

    // print
    /* for (int i = 0; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl; */
    d[0] = max(d[0], 0LL);
    cout << d[0] << endl;

    return 0;
}