#include <bits/stdc++.h>
// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;

map<int, map<int, int>> trie;
long long int pointer = 1;

// add a binary string to the trie (use recursion)
void add(string s, int node = 0, int i = 0)
{
    if (i == s.length())
    {
        return;
    }
    int bit = s[i] - '0';
    if (trie[node][bit] == 0)
    {
        trie[node][bit] = pointer;
        pointer++;
    }
    add(s, trie[node][bit], i + 1);
}

// remove a binary string from the trie (use recursion)
void remove(string s, int node = 0, int i = 0)
{
    if (i == s.length())
    {
        return;
    }
    int bit = s[i] - '0';
    remove(s, trie[node][bit], i + 1);
    if (trie[trie[node][bit]][0] == 0 && trie[trie[node][bit]][1] == 0)
    {
        trie[node][bit] = 0;
    }
}

// function to find the maximum xor of a binary string with the strings in the trie
int Xor(string s)
{
    int node = 0;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int bit = s[i] - '0';
        if (trie[node][bit ^ 1] != 0)
        {
            ans += pow(2, 31 - i);
            node = trie[node][bit ^ 1];
        }
        else
        {
            node = trie[node][bit];
        }
    }
    return ans;
}

int main()
{

    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    char operation;
    int x;
    string s;
    auto S = bitset<32>(x);

    while (t--)
    {
        cin >> operation >> x;
        S = bitset<32>(x);
        s = S.to_string();

        if (operation == '+')
        {
            add(s);
        }
        else if (operation == '-')
        {
            remove(s);
        }
        else if (operation == '?')
        {
            cout << Xor(s) << endl;
        }
    }

    return 0;
}