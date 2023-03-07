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
// #define int long long

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

inline void solve()
{

    int n, q;
    cin >> n >> q;
    int a[n];
    int res[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        res[i] = a[i];
    }
    vector<pair<int, int> > b;
    int idx = 0;
    for (int i = 0; i < q; ++i)
    {
        int t, x;
        cin >> t >> x;
        while (sz(b) > 0 && (b.back().f <= x))
            b.pop_back();
        b.pb(mp(x, t));
    }
    b.pb(mp(0, 0));
    int l = 0;
    int r = b[0].f - 1;
    sort(a, a + r + 1);
    for (int i = 1; i < sz(b); ++i)
    {
        for (int j = b[i - 1].f; j > b[i].f; --j)
        {
            if (b[i - 1].s == 1)
            {

                res[j - 1] = a[r];
                r--;
            }
            else
            {
                res[j - 1] = a[l];
                l++;
            }
        }
    }

    coutarr(res, n);

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
