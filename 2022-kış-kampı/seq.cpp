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

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        // if the current element is smaller than the top of the priority queue
        if (!pq.empty() && pq.top() > a[i])
        {
            // then we have to remove the top element and add the current element
            ans += pq.top() - a[i];
            pq.pop();
            pq.push(a[i]);
        }
        pq.push(a[i]);
    }

    cout << ans << endl;

    return 0;
}