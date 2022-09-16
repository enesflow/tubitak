
#include <iostream>
#include <vector>

using namespace std;

vector<long long int> cache;

long long int f(int x)
{
    if (x <= 1)
    {
        if (cache.size() <= 2)
            cache.push_back(1);
        return 1;
    }
    if (cache.size() >= x)
    {
        long long int newvalue = cache[x - 1] + cache[x - 2];
        cache.push_back(newvalue);
        return newvalue;
    }
    long long int newvalue = f(x - 1) + f(x - 2);
    cache.push_back(newvalue);
    return newvalue;
}

int main()
{
    int i = 0;
    while (i < 100)
    {
        cout << i + 1 << " - " << f(i) << endl;
        i++;
    }

    return 0;
}