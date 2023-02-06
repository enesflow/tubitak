#include <bits/stdc++.h>

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define int long long
#define endl '\n'

using namespace std;

int C[100005];
int A[100005];
int B[100005];

int32_t main()
{
    // fastio
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;
    int n;
    cin >> t;

    for (int T = 0; T < t; T++)
    {
        memset(C, 0, sizeof(C));
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        cin >> n;
        int ans = 0;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> C[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
            // if (B[i] < A[i])
            //     swap(A[i], B[i]);
        }

        int c = 0;
        int l = 0;

        for (int i = 1; i <= n; i++)
        {
            c = C[i] + 1 + (abs(A[i] - B[i]));
            if (A[i] != B[i])                                // not meeting at the same point
                c = max(c, C[i] + l + 1 - abs(A[i] - B[i])); // subtracting our length and continuing
            ans = max(ans, c);
            l = c;
        }

        cout << ans << endl;
    }

    return 0;
}