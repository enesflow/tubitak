#include <iostream>

using namespace std;

int add(int arr[], int start, int end)
{
    int total = 0;
    for (int i = start; i < end; i++)
    {
        total += arr[i];
    }
    return total;
}

void isdivisable(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (add(arr, i, n) == add(arr, 0, i))
        {
            cout << "YES: " << i << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    int arr[] = {1};
    isdivisable(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}