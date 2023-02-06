#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int i = 0;
    cin >> i;
    if (i <= 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int j = 2; j <= round(sqrt(i)); j++) // 10
    {
        if (i % j == 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}