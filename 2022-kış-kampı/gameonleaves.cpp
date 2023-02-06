// unrooted tree
// find degree of each node
// if degree is 1, it is a leaf

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int qq; // number of test cases
    cin >> qq;

    int n, x; // number of nodes, special node

    while (qq--)
    {
        cin >> n >> x;
        int deg[n + 1] = {0};    // degree of each node
        int parent[n + 1] = {0}; // parent of each node
        int t;
        int a, b; // nodes

        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b;
            t = 1 + deg[b] + deg[a];
            deg[b] += 1 + deg[a];
            deg[a] = t;
        }

        if (deg[x] % 2)
        {
            cout << "Ayush";
        }
        else
        {
            cout << "Ashish";
        }
        cout << endl;
    }
}