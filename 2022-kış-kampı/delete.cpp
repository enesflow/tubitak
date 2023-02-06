#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int b;
    while (n--)
    {
        cin >> b;

        if (b % 2)
            cout << "Bob";
        else
        {
            int c = 0;
            while (b % 2 == 0)
            {
                b /= 2;
                c++;
            }

            if (b > 1)
                cout << "Alice";
            else
                cout << (c % 2 ? "Bob" : "Alice");
        }
        cout << endl;
    }

    return 0;
}