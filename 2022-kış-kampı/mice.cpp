#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;

map<pair<int, int>, double> dp;

double win = 0;
double f(int w, int b)
{

    pair<int, int> p = make_pair(w, b);

    if (dp.find(p) != dp.end())
        return dp[p];

    if (w <= 0.0)
        return 0;

    if (b <= 0.0)
        return 1;

    double ret = 0;
    double cont = 0;
    ret = w * 1.0 / (w + b);
    cont = b * 1.0 / (w + b);
    b--;

    cont *= b * 1.0 / (b + w);
    b--;

    if (cont > 1e-13)
    {
        double black = f(w, b - 1) * (b * 1.0 / (b + w)); // winning probability if black mouse runs away
        double white = f(w - 1, b) * (w * 1.0 / (b + w)); // winning probability if white mouse runs away

        ret += cont * (black + white);
    }
    dp[p] = ret;
    return ret;
}

int main()
{

    double w, b;
    cin >> w >> b;
    cout.precision(9);
    cout << f(w, b) << endl;
}