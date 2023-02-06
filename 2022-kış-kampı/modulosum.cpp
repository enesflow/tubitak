

#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[1000005];

int32_t main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n > m)
    {
        cout << "YES" << endl;
    }
    else
    {
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            set<int> temp;
            for (auto it = s.begin(); it != s.end(); it++)
            {
                temp.insert((a[i] + *it) % m);
            }
            s.insert(a[i] % m);
            s.insert(temp.begin(), temp.end());
        }

        // print set
        /* for (auto it = s.begin(); it != s.end(); it++)
        {
            cout << *it << " ";
        }
        cout <<  endl; */
        if (s.find(0) != s.end())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        // 4 5 1 1 1 1
    }

    return 0;
}