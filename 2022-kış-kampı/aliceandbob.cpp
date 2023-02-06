#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    int m = 0;

    int g = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        g = __gcd(g, x);
        m = max(m, x);
    }

    if ((m / g - n) % 2)
        cout << "Alice";
    else
        cout << "Bob";

    return 0;
}
