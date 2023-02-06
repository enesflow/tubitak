#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int a;
    cin >> a;

    bool turn = true; // true: Alice, false: Bob
    int current = 1;
    int alicewhite = 0, aliceblack = 0, bobwhite = 0, bobblack = 0;
    bool begin = true; // 1: white, 0: black
    while (a >= 0)
    {
        if (a < current)
        {
            if (turn)
            {
                alicewhite += a / 2;
                aliceblack += a / 2;

                if (begin)
                    alicewhite += a % 2;
                else
                    aliceblack += a % 2;
            }
            else
            {
                bobwhite += a / 2;
                bobblack += a / 2;

                if (begin)
                    bobwhite += a % 2;
                else
                    bobblack += a % 2;
            }
            break;
        }

        if (turn)
        {
            alicewhite += current / 2;
            aliceblack += current / 2;

            if (begin)
                alicewhite += current % 2;
            else
                aliceblack += current % 2;
        }
        else
        {
            bobwhite += current / 2;
            bobblack += current / 2;

            if (begin)
                bobwhite += current % 2;
            else
                bobblack += current % 2;
        }

        a -= current;
        current += 4;

        turn = !turn;
        begin = !begin;
    }

    cout << alicewhite << " " << aliceblack << " " << bobwhite << " " << bobblack << endl;
}

int32_t main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
        solve();
    return 0;
}