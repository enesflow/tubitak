#include <bits/stdc++.h>
#include <math.h>
#define int long long
using namespace std;

map<int, int> p;
bool P(int n)
{

    if (p[n] != 0)
        return p[n];

    if (n == 1)
    {
        p[n] = -1;
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            p[n] = -1;
            return false;
        }
    }
    return p[n] = 1;
}

int f(int n)
{
    if (P(n) || n == 1)
    {
        return -1;
    }
    int a = INT_MAX;
    int b = INT_MAX;
    vector<int> s;
    int t = t;

    // find 2 smallest prime factors
    // cout << "wwwwwwwwww " << (long long)sqrt(n) + 1 << endl;

    int sq = min(n, (long long)sqrt(n) * 3);

    for (int i = 2; i <= sq; i++)
    {
        while (n % i == 0)
        {
            s.push_back(i);
            n /= i;
        }
    }

    if (P(n)) // if n is still prime
    {
        s.push_back(n);
    }

    // print smallest prime factors
    if (s.size() <= 1)
    {
        return false;
    }
    if (s.size() == 2)
        return false;
    return s[0] * s[1];
}
int32_t main()
{

    int q;
    cin >> q;
    int r = f(q);
    if (r)
    {
        cout << 1 << endl
             << max(r, (long long)0) << endl;
    }
    else
    {
        cout << 2 << endl;
    }

    return 0;
}