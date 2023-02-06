#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w_n;
    cin >> w_n;

    char c;
    int x_sum = 0, y_sum = 0;
    int X[w_n];
    int Y[w_n];
    for (int i = 0; i < w_n; i++)
    {
        cin >> c;

        if (c == 'U')
        {
            y_sum++;
        }
        else if (c == 'D')
        {
            y_sum--;
        }
        else if (c == 'L')
        {
            x_sum--;
        }
        else if (c == 'R')
        {
            x_sum++;
        }
        X[i] = x_sum;
        Y[i] = y_sum;
    }
    int l, r, m;
    l = 0;
    r = 1e18;
    int whole;
    int x_wind, y_wind;
    int left_distance = 0;
    int x, y;
    while (l < r - 1)
    {
        m = (l + r) / 2;
        whole = m / w_n;
        x_wind = whole * x_sum * 1LL;
        y_wind = whole * y_sum * 1LL;

        if (m % w_n != 0)
        {
            x_wind += X[m % w_n - 1];
            y_wind += Y[m % w_n - 1];
        }
        x = x1 + x_wind;
        y = y1 + y_wind;

        left_distance = abs(x - x2) + abs(y - y2);
        // cout << "distance: " << left_distance << endl;

        if (left_distance <= m)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }

    if (r > 1e15)
    {
        cout << -1;
        return 0;
    }
    else
    {
        cout << r << endl;
    }

    return 0;
}