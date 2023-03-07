// Codeforces 1725M : nice
// No bits/stdc++.h because clang

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <cassert>
#include <random>
#include <type_traits>
#include <list>
#include <tuple>
#include <climits>
#include <limits>

// I don't know how any of these work, but its nice to have them
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline,unsafe-math-optimizations")
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

#define vint vector<int>
#define pint pair<int, int>
#define mint map<int, int>
#define sint set<int>
#define msint multiset<int>
#define qint queue<int>
#define pqint priority_queue<int>
#define lint list<int>
#define stint stack<int>
#define gint greater<int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define guv int u, v; cin >> u >> v
#define sz(x) (int)x.size()
#define cinarr(x, n) for (int i = 0; i < n; i++) cin >> x[i]
#define coutarr(x, n) for (int i = 0; i < n; i++) cout << x[i] << " "; cout << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define _reset(x, y) memset(x, y, sizeof(x))
#define _mid (l + r) / 2
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
/******************* Uncomment this for long long (TLE) *******************/
// #define int long long
#define ll long long

inline void swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

inline int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

/*
 _____ ____  ____  ____    _     _     ____  _  __
/  __//  _ \/  _ \/  _ \  / \   / \ /\/   _\/ |/ /
| |  _| / \|| / \|| | \|  | |   | | |||  /  |   /
| |_//| \_/|| \_/|| |_/|  | |_/\| \_/||  \_ |   \
\____\____/\____/\____/  \____/\____/\____/\_|\_\
*/

vector<pair<int, ll> > adj[200005];
#define inf 1e15
ll dist[200005]; // can use vector instead (faster?)
bool vis[200005];

signed main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    FILEIO;
    #endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
        adj[v + n].pb(mp(u + n, w));
    }
    for (int i = 1; i <= n; ++i) {
        dist[i] = inf;
        dist[i + n] = inf;
        adj[i].pb(mp(i + n, 0));
    }
    dist[1] = 0;

    // omfg i submitted 26 f'ing times and got tle because i created pairs like this: (node, dist or <int, ll>) i f'ing feel ashamed
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;

    // IT WOULD ALL BE FINE IF I F'ING PUSHED 0, 1 INSTEAD OF 1, 0
    pq.push(mp(0, 1));
    while (!pq.empty()) {
        int u = pq.top().s;
        ll d = pq.top().f;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto v : adj[u]) {
            if (dist[v.f] > dist[u] + v.s) {
                dist[v.f] = dist[u] + v.s;
                pq.push(mp(dist[v.f], v.f));
            }
        }
    }


    for (int j = 2; j <= n; ++j) {
        ll d = dist[j + n];
        if (d == inf) cout << -1 << " ";
        else cout << d << " ";
    }
    cout << endl;

    return '0' ^ '0';
}
