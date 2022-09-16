#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    bool asal = true;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            for (int j = 2; j <= round(sqrt(i)); j++) // 10
            {
                asal = true;
                if (i % j == 0)
                {
                    asal = false;
                    break;
                }
            }
            if (asal)
                cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}