#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define int long long
#define endl '\n'

using namespace std;

int32_t main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R = 0;
    int G = 0;
    int B = 0;

    int n;

    cin >> n;
    char c;

    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c == 'R')
        {
            R++;
        }
        else if (c == 'G')
        {
            G++;
        }
        else
        {
            B++;
        }
    }

    set<char> s;

    if ((R && G && B) || (R > 1 && G > 1) || (R > 1 && B > 1) || (G > 1 && B > 1))
    {
        s.insert('R');
        s.insert('G');
        s.insert('B');
    }

    if (R && !G && !B)
    {
        s.insert('R');
    }
    else if (!R && G && !B)
    {
        s.insert('G');
    }
    else if (!R && !G && B)
    {
        s.insert('B');
    }

    if (R && G)
    {
        s.insert('B');
    }
    if (R && B)
    {
        s.insert('G');
    }
    if (G && B)
    {
        s.insert('R');
    }

    if (R >= 2 && B == 1)
    {
        s.insert('G');
        s.insert('B');
    }
    if (R >= 2 && G == 1)
    {
        s.insert('G');
        s.insert('B');
    }
    if (B >= 2 && R == 1)
    {
        s.insert('G');
        s.insert('R');
    }

    if (G >= 2 && B == 1)
    {
        s.insert('R');
        s.insert('B');
    }
    if (G >= 2 && R == 1)
    {
        s.insert('R');
        s.insert('B');
    }
    if (B >= 2 && G == 1)
    {
        s.insert('R');
        s.insert('G');
    }
    for (auto i : s)
    {
        cout << i;
    }

    return 0;
}