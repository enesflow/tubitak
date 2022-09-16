#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    int n = 0;
    int moves = 0;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int a[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        int b[n];
        for (int j = 0; j < n; j++)
        {
            cin >> b[j];
        }

        int min_a = 0;
        int min_b = 0;

        cout << endl;
        for (int j = 0; j < n; j++)
            cout << a[j] << " ";
        cout << endl;
        for (int j = 0; j < n; j++)
            cout << b[j] << " ";

        for (int j = 0; j < n; j++)
        {
            if (min_a == 0 || a[j] < min_a)
                min_a = a[j];
            if (min_b == 0 || b[j] < min_b)
                min_b = b[j];
        }
        for (int j = 0; j < n; j++)
        {
            while (a[j] != min_a && b[j] != min_a)
            {
                moves++;
                a[j]--;
                b[j]--;
            }
            while (a[j] != min_a)
            {
                moves++;
                a[j]--;
            }
            while (b[j] != min_b)
            {
                moves++;
                b[j]--;
            }
        }
        cout << moves;
    }
    return 0;
}