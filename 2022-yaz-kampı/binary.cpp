#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n - 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int m;
    int q;
    cin >> q;
    int middle;
    for (int i = 0; i < q; i++)
    {
        cin >> m;
        if (m < arr[0])
        {
            cout << 0 << endl;
        }
        else
        {
            int start = 0, end = n - 1;
            while (start <= end)
            {
                middle = (start + end) / 2;
                if (end - start == 1)
                {
                    if (m >= arr[end])
                    {
                        cout << end + 1 << endl;
                        break;
                    }
                    else
                    {
                        cout << start + 1 << endl;
                        break;
                    }
                }
                if (end == start)
                {
                    cout << start + 1 << endl;
                    break;
                }
                if (arr[middle] > m)
                {
                    end = middle - 1;
                }
                else
                {
                    start = middle;
                }
            }
        }
    }

    return 0;
}