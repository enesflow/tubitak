#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;

#define int long long

int32_t main()
{

    string s;
    cin >> s;
    int n = s.size();
    int islem = 0;
    bool comp = false;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            if (!comp)
            {
                islem++;
                s[i] = '0';

                if (i != 0)
                {
                    if (s[i - 1] == '1')
                    {
                        comp = true;
                    }
                }
            }
            else if (comp)
            {
                s[i] = '0';
            }
        }
        else
        {
            if (comp)
            {
                comp = false;
                s[i] = '1';
                i++;
            }
        }
        /* cout << "i = " << i << endl;
        cout << "s[i] = " << s[i] << endl;
        cout << "islem = " << islem << endl;
        cout << "comp = " << comp << endl;
        cout << "s = " << s << endl;
        cout << endl; */
    }

    if (comp)
    {
        islem++;
    }

    // cout << s << endl;

    cout << islem;

    return 0;
}