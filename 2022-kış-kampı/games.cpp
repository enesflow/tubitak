#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        a[i] = s.size();
    }
    int m = *max_element(a, a + n);

    int res = 0;

    res = m % 2; // 1 -> First, 0 -> Second
    if (res == 1)
    {
        if (k % 2)
        {
            cout << "First" << endl;
        }
        else
        {
            cout << "Second" << endl;
        }
    }
    else
    {
        if (k % 2)
        {
            cout << "Second" << endl;
        }
        else
        {
            cout << "First" << endl;
        }
    }

    return 0;
}