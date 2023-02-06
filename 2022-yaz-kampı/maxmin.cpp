#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<long long int> arr;
    long long int n = 0;
    long long int x = 0;
    long long int i = 0;
    while (true)
    {
        cin >> x;
        if (x == 0)
        {
            break;
        }
        arr.push_back(x);
        n++;
    }

    long long int minimum = 0;
    long long int maximum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if ((arr[i]) < minimum || minimum == 0)
            minimum = arr[i];
        else if ((arr[i]) > maximum || maximum == 0)
            maximum = arr[i];
    }

    cout << maximum << " " << minimum << endl;

    return 0;
}
