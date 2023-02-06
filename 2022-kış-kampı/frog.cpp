#include <iostream>
#include <math.h>

#define int long long

using namespace std;

int32_t main()
{
    int n, c;
    cin >> n >> c;
    int h[n + 1];
    h[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i + 1];
    }

    int d[n + 1];
    // init dp
    for (int i = 0; i <= n; i++)
    {
        d[i] = 0;
    }

    for (int i = 2; i <= n; i++)
    {
        int t = 9223372036854775807;
        int prev = 0;

        for (int j = 1; j <= i - 1; j++)
        {
            prev = t;
            t = min(t, d[i - j] + (h[i] - h[i - j]) * (h[i] - h[i - j]));
            // cout << "before t: " << t << endl;
            // cout << "option: " << d[i - j] + (h[i] - h[i - j]) * (h[i] - h[i - j]) << endl;
            // cout << "i: " << i << " j: " << j << " t: " << t << endl;
        }
        // cout << "t: " << t << endl;
        //  convert to for loop
        d[i] = t + c;

        // 0 0 7 10 17 20
    }
    cout << d[n] << endl;

    return 0;
}