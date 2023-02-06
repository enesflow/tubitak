#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;

int main()
{

    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int x;

    list<int> a[200005] = {};
    int b[200005];
    int k;
    int A = 0;
    int B = 0;

    int arr[n];
    bool decrease = true;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i != 0 && arr[i] < arr[i - 1])
            decrease = false;
    }

    if (decrease)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        x = arr[i];
        k = INT_MAX;
        for (int i = 0; i < B; i++)
        {
            if (b[i] < x)
            {
                k = i;
                break;
            }
        }
        if (k != INT_MAX)
        {
            a[k].push_back(x);
            b[k] = x;
        }
        else
        {
            a[A] = list<int>{x};
            b[B] = x;
            A++;
            B++;
        }
    }

    for (int i = 0; i < A; i++)
    {
        for (auto j : a[i])
            cout << j << " ";
        cout << endl;
    }

    return 0;
}