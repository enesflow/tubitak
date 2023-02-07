#include <bits/stdc++.h>
using namespace std;

int tree[1000000];
int n;
// segment tree
void build(int node, int start, int end, int arr[])
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

// update
void update(int node, int start, int end, int value, int isReset)
{
    if (node == start && start == end)
    {
        if (isReset)
        {
            tree[node] = 0;
        }
        else
        {
            tree[node] += value;
        }
    }
    else
    {
        if (node < start || end < node)
            return;
        int mid = (start + end) / 2;
        if (node <= mid)
            update(2 * node, start, mid, value, isReset);
        else
            update(2 * node + 1, mid + 1, end, value, isReset);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

// query range
int query(int l, int r, int start, int end, int node)
{
    if (r < start || end < l)
        return 0;
    if (l <= start && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(l, r, start, mid, 2 * node);
    int p2 = query(l, r, mid + 1, end, 2 * node + 1);
    return (p1 + p2);
}
void solve()
{
    memset(tree, 0, sizeof(tree));
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(1, 0, n - 1, arr);

    int a, b, c;

    for (int i = 0; i < k; i++)
    {
        cout << "i: " << i << endl;
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            cout << "->>" << query(b, b, 0, n - 1, 1) << endl;
            update(1, 0, n - 1, 0, 1);
        }
        else if (a == 2)
        {
            cin >> b >> c;
            update(1, 0, n - 1, c, 0);
        }
        else
        {
            cin >> b >> c;
            cout << "->>" << query(b, c, 0, n - 1, 1) << endl;
        }
    }
}

int main()
{
    int q;
    cin >> q;
    while (q--)
        solve();
}