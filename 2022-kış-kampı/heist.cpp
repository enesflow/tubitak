#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int index = a[0];
    int lost = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != index)
        {
            lost += a[i] - index - 1;
            index = a[i];
        }
    }

    cout << lost;
}