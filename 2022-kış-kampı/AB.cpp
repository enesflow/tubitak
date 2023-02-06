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
#define INT long long
#define vi vector<int>
#define endl '\n'

// FUNCTIONS
#define INIT(x) \
    int x;      \
    GET(x);

#define GET(x) cin >> x;

#define INITALL(x, n) \
    int x[n];         \
    GETALL(x, n);

#define GETALL(x, n)            \
    for (int i = 0; i < n; i++) \
        cin >> x[i];

#define print(x) cout << x << endl;

#define PRINT(x, c) cout << x << c;

#define PRINTALL(x, c)  \
    for (auto i : x)    \
        cout << i << c; \
    cout << endl;

#define PREFIXSUM(x, n, p)      \
    int p[n];                   \
    p[0] = x[0];                \
    for (int i = 1; i < n; i++) \
        p[i] = p[i - 1] + x[i];

using namespace std;

vector<pair<int, bool>> children[200005];
int parent[200005];
int dp[200005];
bool visited[200005];

int main()
{

    // FASTIO;
    INIT(n);

    int u, v;
    for (int i = 1; i < n; i++)
    {
        GET(u);
        GET(v);

        children[u].push_back(make_pair(v, true));
        children[v].push_back(make_pair(u, false));

        parent[v] = u;
    }

    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front();
        visited[node] = true;
        q.pop();

        for (auto child : children[node])
        {
            if (visited[child.first])
                continue;
            if (child.second == false)
            {
                dp[1]++;
            }

            q.push(child.first);
        }
    }

    int MINIMUM = dp[1];
    set<int> FFF = {1};
    memset(visited, false, sizeof(visited));
    q.push(1);
    while (!q.empty())
    {
        int node = q.front();
        visited[node] = true;
        q.pop();

        for (auto child : children[node])
        {
            if (visited[child.first])
                continue;
            dp[child.first] = dp[node];
            if (child.second == false)
            {
                dp[child.first]--;
            }
            else
            {
                dp[child.first]++;
            }
            if (MINIMUM > dp[child.first])
            {
                FFF.clear();

                MINIMUM = dp[child.first];
                FFF.insert(child.first);
            }
            else if (MINIMUM == dp[child.first])
            {
                FFF.insert(child.first);
            }
            q.push(child.first);
        }
    }

    print(MINIMUM);
    PRINTALL(FFF, " ");

    return 0;
}