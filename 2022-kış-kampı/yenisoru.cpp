#include <bits/stdc++.h>
using namespace std;

int main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    string s;
    int n;

    while (q--)
    {
        cin >> n;
        char str[n + 2];
        char default_str[n + 2];
        str[0] = 'R';
        str[n + 1] = 'L';
        default_str[0] = 'R';
        char str_odd[n + 2];
        char str_even[n + 2];
        str_odd[0] = 'R';
        str_even[0] = 'R';
        str_odd[n + 1] = 'L';
        str_even[n + 1] = 'L';

        default_str[n + 1] = 'L';
        for (int i = 1; i < n + 1; i++)
        {
            cin >> str[i];
            default_str[i] = str[i];
            str_odd[i] = str[i];
            str_even[i] = str[i];
        }

        for (int l = 1 - 1; l > 0; l -= 2)
        {
            if (str[l] == 'R')
                str_odd[l] = 'L';
            else
                str_odd[l] = 'R';
        }
        for (int r = 1 + 1; r < n + 1; r += 2)
        {
            if (str[r] == 'R')
                str_odd[r] = 'L';
            else
                str_odd[r] = 'R';
        }

        for (int l = 2 - 1; l > 0; l -= 2)
        {
            if (str[l] == 'R')
                str_even[l] = 'L';
            else
                str_even[l] = 'R';
        }
        for (int r = 2 + 1; r < n + 1; r += 2)
        {
            if (str[r] == 'R')
                str_even[r] = 'L';
            else
                str_even[r] = 'R';
        }

        // print str_odd and str_even
        for (int i = 0; i <= n + 1; i++)
        {
            cout << str_odd[i];
        }
        cout << "\n";
        for (int i = 0; i <= n + 1; i++)
        {
            cout << str_even[i];
        }
        cout << "\n";

        vector<int> RL_odd;
        for (int i = 0; i < n + 1; i++)
        {
            if (str_odd[i] == 'R' && str_odd[i + 1] == 'L')
            {
                RL_odd.push_back(i);
            }
        }
        vector<int> RL_even;
        for (int i = 0; i < n + 1; i++)
        {
            if (str_even[i] == 'R' && str_even[i + 1] == 'L')
            {
                RL_even.push_back(i);
            }
        }
        int l;
        int f;
        for (int i = 1; i <= n + 1; i++)
        {
            if (i % 2)
            {
                auto L = lower_bound(RL_even.begin(), RL_even.end(), i - 1);
                if (L == RL_even.end())
                {
                    // get last element of vector
                    cout << n + 1 - RL_even[RL_even.size() - 1];
                    cout << " ";
                    continue;
                }
                l = L - RL_odd.begin();
                if (RL_odd[l] == i)
                {
                    cout << "1";
                    cout << " ";
                    continue;
                }
                else
                {
                    cout << "not equal: " << RL_odd[l] << " " << i << "\n";
                    if (l == 0)
                    {
                        cout << RL_odd[l + 1];
                        cout << " ";
                    }
                    else
                    {
                        cout << RL_odd[l] - RL_odd[l - 1];
                        cout << " ";
                    }
                }
            }
        }
    }
    return 0;
}