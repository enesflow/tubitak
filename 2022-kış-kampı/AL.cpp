/*
                          .^!?J55PPPPPP55YJ?!~:.
                      :7YGB##BBGGGGPPPPPPP555YYJ?!^:
                   ^JG###GPP5PPPPGGGGGGGGPPP555YYJJ?7~:
                .7G##BP5Y555PPPGGGGGGGGGGGGPPP55YYJJ?77!^.
              .7B&#BGBB######BGPPPPPPPPPPPPB#######BBPY?77!.
             ^P#B#&&&&###BBGGG&#5YYYYYYYYP&&########B###GJ?J:
            ^G&G#&####BBBBGGPYY&B????????B@GB####BBGGPPP##J?5^
           :7Y5G@B###BBGP5555Y?##?~7777~?&&GBBBBBGPP55Y55&G7Y5:
           7JJ?#&GGBBP5YYYJJJJ7#B7^?YY?^?#&J5PPPYYYYYJJJYB#??G?
          :YG5?##Y55J????????7J&P~^7??7^~P&J?JJ????????7JBB??5P:
          !PG57P&J7!7777777!7Y#G?:::^^:::?G#Y7!!7777777!J&P7JYG!
      .:::?PG5J7GB5J?777?J5PBGP5J!JPPPPJ!J5PGBP5J??7??JPBG7?JJG?.::.
    .!?J?^JGG55?!7J5PPPPP55YYYPPJ5&&@@&&5JPPYYY55PPPPP5J7!7YJJPJ^?J?!.
   ~JYGG7^YGG5PP?^~~~~~~~~~7???YB&@@@@@@&BY???7~~~~~~~~~:75YJ?5Y:?GPYJ~
  ?GG&#P7~5GGPPBJ^PY?77777?J5G#&&@@@@@@@@&&#G5J?7777?J5G^7PYJ?5Y^7G&&GP?
  7J5#YJ~~5GGPPB?~#&BBBBBB#&&&&@@@@@@@@@@@@&&&&#&BBB##&&^!PYJ?JJ:~JY#5J7
  ~7?5?!:~?YPPGB?!&######&&&P?!~J@@@@@@@@PJ7!Y&&&######&~!5J?7!~::!?5?!^
  ^75B5!:~Y55PGB?!&&&###&&@#!?7~^@@@@@@@@7??~.#@&&#####&~!5?7!7?::!5B5!^
  ^!7?7~.~GBGPGB?!&&&&#&&&@#?5??~&@@@@@@&7Y?J~B@&&###BB#~~Y7!!7?:.^!?!^:
  .~~~~^.~YPP5PB?!&&&&&&&&@&~^::~@@@@@@@@!^:::#&&#&BBBB#!~J7~^~!..:::::.
    .:~~:!PGY?J5!!&&&&##&&&@&GPG&@@@@@@@@&GPG&&&##BBGGGB~^7^^^~!.....
       ..~5G5JJ5?!#&&&&#&&&&&@@@@@@@@@@@@@@@@&&&##BBGGGG!~!^^:^^.
          .^~!7?5GG5GBBB##&&&&@@@@@@@@@@@@@@&&&##BGGGPYYJ!::...
              ..^!!!5PGBBB####&&&@@@@@@@@&&&###BBGP5J7::..
                    .:^~7?Y5PGGBB#######BBGP5YJ7~^:..
                          ....::^^^^^^^^:::...

*/

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

// MACROS
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define int long long
#define vi vector<int>
#define endl '\n'

// FUNCTIONS
#define INIT(x) \
    int x;      \
    GET(x);
#define INITTWO(x, y, k)        \
    int x[k], y[k];             \
    for (int i = 0; i < k; i++) \
        cin >> x[i] >> y[i];

#define GET(x) cin >> x;

#define INITALL(x, n) \
    int x[n];         \
    GETALL(x, n);

#define GETALL(x, n)            \
    for (int i = 0; i < n; i++) \
        cin >> x[i];

#define PRINTALL(x, c)  \
    for (auto i : x)    \
        cout << i << c; \
    cout << endl;

#define ARR(x, n)               \
    int x[n];                   \
    for (int i = 0; i < n; i++) \
        x[i] = i;

#define print(x) cout << x << endl;

#define WHILE(t) \
    int t;       \
    cin >> t;    \
    while (t--)
using namespace std;

vi children[100005];
int ans = 1;
int N;
map<int, int> dp;
// get number of ways to get to node n

int dfs(int node)
{
    if (node == N)
    {
        return 1;
    }

    if (dp.find(node) != dp.end())
        return dp[node];

    int A = 0;
    for (int i = 0; i < children[node].size(); i++)
    {
        A += dfs(children[node][i]);
    }
    A %= 1000000007;
    dp[node] = A;
    return A;
}

void solve()
{
    INIT(n);
    INIT(m);
    N = n;
    int u, v;

    for (int i = 0; i < m; i++)
    {
        GET(u);
        GET(v);
        children[u].push_back(v);
    }

    cout << dfs(1) << endl;
}

int32_t main()
{
    FASTIO;

    solve();

    return 0;
}