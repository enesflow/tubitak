#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int a, b, c;
    int first, second;
    for (int i = 0; i < t; i++)
    {
        cin >> a;
        cin >> b;
        cin >> c;

        first = abs(a - 1);
        second = abs(b - c) + abs(c - 1);

        if (first == second)
        {
            cout << 3 << endl;
        }
        else if (first > second)
        {
            cout << 2 << endl;
        }
        else if (first < second)
        {
            cout << 1 << endl;
        }
    }
    return 0;
}