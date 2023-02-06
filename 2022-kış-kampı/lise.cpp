#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define int long long
#define endl '\n'

using namespace std;

int A[5005];
int B[5005];

int32_t main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int n;
    int x;
    bool yes = true;
    int spare = 0;

    while (t--)
    {
        cin >> n;
        spare = 0;
        memset(A, false, sizeof(A));
        memset(B, false, sizeof(B));
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            A[x]++;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            B[x] = true;
            if (!A[x])
                yes = false;
        }

        if (yes)
        {

            for (int i = 0; i < n; i++)
            {
                if (A[i])
                {
                    if (!B[i])
                    {
                        spare += A[i];
                    }
                    else
                    {
                        if (A[i] + spare <= B[i])
                        {
                            yes = false;
                        }
                    }
                }
            }

            if (yes)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
            cout << "No" << endl;
    }

    return 0;
}