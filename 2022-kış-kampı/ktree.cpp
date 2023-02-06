#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

int dp[100][2];

void add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

int main(int argc, char **argv)
{
    int n, k, d;
    cin >> n >> k >> d;
    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i = 1; i <= n; ++i) // go through each node in the tree and calculate the number of ways to reach it
    {
        dp[i][0] = dp[i][1] = 0; // set the number of ways to reach the node to 0 initially

        for (int j = 1; j <= k; ++j) // consider each node and the parent has k ways to reach it
                                     // in this loop we are going through each way to reach the node
        {
            if (i - j < 0)
                break; // if the node is not reachable, break

            if (j < d)
            {
                add(dp[i][0], dp[i - j][0]); // add no ds
                add(dp[i][1], dp[i - j][1]); // add ways with ds
            }
            else
            {
                add(dp[i][1], dp[i - j][0]); // we already have ways with ds, so we can add ways without ds
                add(dp[i][1], dp[i - j][1]); // and the ways with ds
            }
        }
    }
    cout << dp[n][1] << "\n";
    return 0;
}