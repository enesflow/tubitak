// CSES: Coin Collector - really teaches you scc

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

// I don't know how any of these work, but its nice to have them
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline,unsafe-math-optimizations")
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

template <typename T>
void debug(T &x, std::string name = "")
{
    if (name == "")
        std::cerr << ":= " << x << "\n";
    else
        std::cerr << name << " = " << x << "\n";
}
template <typename T>
void debugArr(T &arr, int n = -1, std::string name = "")
{
    if (n == -1)
        n = sizeof(arr) / sizeof(arr[0]);
    if (name == "")
        std::cerr << ":= ";
    else
        std::cerr << name << " = ";
    std::cerr << "[";
    for (int i = 0; i < n; i++)
        std::cerr << arr[i] << ","[i == n - 1];
    std::cerr << "]"
              << "\n";
}
template <typename T>
void debugArr(std::vector<T> &arr, int n = -1, std::string name = "")
{
    if (n == -1)
        n = arr.size();
    if (name == "")
        std::cerr << ":= ";
    else
        std::cerr << name << " = ";
    std::cerr << "[";
    for (int i = 0; i < n; i++)
        std::cerr << arr[i] << ","[i == n - 1];
    std::cerr << "]"
              << "\n";
}
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
#define guv   \
    int u, v; \
    cin >> u >> v
#define sz(x) (int)x.size()
#define cinarr(x, n)            \
    for (int i = 0; i < n; i++) \
    cin >> x[i]
#define coutarr(x, n)           \
    for (int i = 0; i < n; i++) \
        cout << x[i] << " ";    \
    cout << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define _reset(x, y) memset(x, y, sizeof(x))
#define _mid (l + r) / 2
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FILEIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
/******************* Uncomment this for long long (TLE) *******************/
#define int long long

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


bool vis[100005];
int coins[100005];
int comp[100005];
int cg[100005];
int dp[100005];
vint g1[100005];
vint g2[100005];
sint g[100005];
stint ord;
sint components;
int compsize = 1;

int dfs(int u)
{
    if (dp[u])
        return dp[u];
    int ret = cg[u];
    for (auto c : g[u])
    {
        ret = max(ret, dfs(c) + cg[u]);
    }
    return dp[u] = ret;
}

void dfs1(int u)
{
    vis[u] = true;
    for (auto c : g1[u])
    {
        if (!vis[c])
            dfs1(c);
    }
    ord.push(u);
}

void dfs2(int u, int cur)
{
    vis[u] = true;
    comp[u] = cur;
    for (auto c : g2[u])
    {
        if (!vis[c])
        {
            dfs2(c, cur);
        }
    }
}

inline void solve()
{

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> coins[i];

    for (int i = 0; i < m; ++i)
    {
        guv;
        g1[u].pb(v);
        g2[v].pb(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
            dfs1(i);
    }

    memset(vis, 0, sizeof(vis));

    while (!ord.empty())
    {
        int u = ord.top();
        ord.pop();
        if (!vis[u])
        {
            dfs2(u, u);
            components.insert(u);
            compsize++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cg[comp[i]] += coins[i];
        for (auto c : g1[i])
        {
            if (comp[i] != comp[c])
            {
                g[comp[c]].insert(comp[i]);
            }
        }
    }

    int ans = 0;

    for (auto c : components)
    {
        ans = max(ans, dfs(c));
    }

    cout << ans << endl;

    // My code is not working!!! Try these fixes:
    // 1. Check for overflow (uncommenct #define int long long)
    // 2. Check for array bounds
    // 3. Check for array indexes, 1-indexed or 0-indexed?
    // 4. Check for special cases (n=1?)
    // 5. Check for multiple test cases (remember to clear global variables)
    // 6. Check the limits of your data types maybe l <= r, maybe 0 <= n...

    // Getting TLE? Try these fixes:
    // 1. Delete the line: #define int long long
    // 2. Use array instead of vector

    // Getting WA? Good luck, you're on your own
}

signed main()
{
    int t = 1;
    FASTIO;
    /******************* Uncomment this if you want to read from input.txt ********************/
#ifndef ONLINE_JUDGE
    FILEIO;
#endif

    /***************** Uncomment this if you want to test multiple test cases *****************/
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        /**************** Uncomment this if you want to print the case number ****************/
        // cout << "Case " << i << ":";
        solve();
    }

    return '0' - '0'; // OwO
}
