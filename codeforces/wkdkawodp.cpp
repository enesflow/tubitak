#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;

int main()
{

    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        string s;
        cin >> n;
        cin >> s;

        int l = 0;
        int r = n - 1;

        int N = n;

        while (l < r)
        {
            if (s[l] != s[r])
            {
                N -= 2;
            }
            else
            {
                break;
            }
            l++;
            r--;
        }
        cout << N << endl;
    }
    return 0;
}