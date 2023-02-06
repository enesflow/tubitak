// palindrome

#include <bits/stdc++.h>

using namespace std;

int T(int t)
{
    if (t == 1)
        return 2;
    else
        return 1;
}

int play(int e, int o, int t)
{
    // e: even
    // o: odd
    // t: turn 1, 2
    if (o < 2)
        return t;
    else
    {
        if (e)
        {
            return play(--e, ++o, T(t));
        }
        else
        {
            return play(e, --o, T(t));
        }
    }
}

int main()
{
    // read string
    string s;
    cin >> s;

    map<char, int> m;
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }
    int even = 0;
    int odd = 0;

    for (auto i : m)
    {
        if (i.second % 2)
            odd++;
        else
            even++;
    }

    int result = play(even, odd, 1);
    if (result == 1)
        cout << "First";
    else
        cout << "Second";

    return 0;
}