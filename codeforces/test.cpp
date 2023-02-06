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
        map<char, int> mp1, mp2;
        vector<int> v1(n, 0), v2(n, 0);
        v1[0] = 1;
        mp1[s[0]]++;
        for (int i = 1; i < n; i++)
        {
            if (mp1.find(s[i]) == mp1.end())
            {
                v1[i] = 1 + v1[i - 1];
            }
            else
            {
                v1[i] = v1[i - 1];
            }
            mp1[s[i]]++;
        }
        v2[n - 1] = 1;
        mp2[s[n - 1]]++;
        for (int i = n - 2; i >= 0; i--)
        {
            if (mp2.find(s[i]) == mp2.end())
            {
                v2[i] = 1 + v2[i + 1];
            }
            else
            {
                v2[i] = v2[i + 1];
            }
            mp2[s[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, v1[i] + v2[i]);
        }
        if (ans > n)
            ans = n;
        cout << ans << endl;
    }
    return 0;
}