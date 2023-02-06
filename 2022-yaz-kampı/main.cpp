#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout.precision(11);
    double d;
    double a;
    double b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        a = (-d + sqrt(pow(d, 2) - 4 * d)) / -2;
        // b = (-d - sqrt(pow(d, 2) - 4 * d)) / -2;
        b = d - a;
        if (isnan(a))
        {
            cout << "N" << endl;
            continue;
        }
        cout << "Y " << a << " " << b << endl;
    }

    return 0;
}