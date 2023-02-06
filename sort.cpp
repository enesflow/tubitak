// counting sort

#include <iostream>
#include <cstring>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define double long double

// set random seed

double t()
{
    // return current time in the most precise unit
    return duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
}

int main()
{
    cout.precision(13);
    int S;
    cin >> S;

    while (S--)
    {

        srand(time(NULL));
        // generate random array of size n and range [0, k]
        int n, k;
        cin >> n >> k;

        int a[n];

        for (int i = 0; i < n; i++)
            a[i] = rand() % (k + 1);

        double TIME = t();

        // counting sort
        int c[k + 1];
        memset(c, 0, sizeof(c));

        for (int i = 0; i < n; i++)
            c[a[i]]++;

        cout << endl;

        int INDEX = 0;
        int ans[n];

        for (int i = 0; i <= k; i++)
        {
            if (c[i] > 0)
            {
                for (int j = 0; j < c[i]; j++)
                {
                    ans[INDEX] = i;
                    INDEX++;
                }
            }
        }
        cout << "----------- Done -----------" << endl;
        cout << "Time: " << (t() - TIME) / 10e9 << " seconds" << endl;
        cout << endl;
    }
    return 0;
}