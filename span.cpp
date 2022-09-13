#include <iostream>

using namespace std;

int isin(int arr[], int n, int t)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == t)
        {
            return i;
        }
    }
    return -1;
}

int maxspan(int arr[], int n)
{
    int n_i[n], n_j[n];
    int j = n - 1;
    int potmaxspan = 0;
    for (int i = 0; i < n; i++, j--)
    {
        int potmaxspan2 = 0;
        if (isin(n_i, n, arr[i]) < 0)
        {
            n_i[i] = arr[i];
        }
        if (isin(n_j, n, arr[j]) < 0)
        {
            n_j[j] = arr[j];
        }
        int is_j_in_i = isin(n_i, n, arr[j]);
        int is_i_in_j = isin(n_j, n, arr[i]);
        if (is_i_in_j >= 0)
        {
            potmaxspan2 = abs(is_i_in_j - i) + 1;
        }
        if (is_j_in_i >= 0)
        {
            if (abs(is_j_in_i - j) + 1 > potmaxspan2)
            {
                potmaxspan2 = abs(is_j_in_i - j) + 1;
            }
        }
        if (potmaxspan2 > potmaxspan)
        {
            potmaxspan = potmaxspan2;
        }
    }
    return potmaxspan;
}

int main()
{

    int arr[] = {1, 0, 5, 2, 1, 9, 5, 9, 9, 9, 9, 9, 9, 9};
    cout << maxspan(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    return 0;
}
