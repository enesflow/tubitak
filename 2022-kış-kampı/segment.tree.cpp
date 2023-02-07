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

// update a single leaf node and propagate the changes up
void update(int idx, int start, int end, int val, int type)
{
    if (start == end)
    {
        // Leaf node
        if (type == 0)
            tree[idx] += val;
        else
            tree[idx] = 0;
    }
    else
    {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2 * idx, start, mid, val, type);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2 * idx + 1, mid + 1, end, val, type);
        }
        // Internal node will have the sum of both of its children
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
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

void print()
{
    // print the tree nicely
    int level = 1;
    int count = 0;
    cout << "printing : " << 1 << 2 * n - 1 << endl;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        cout << tree[i] << " ";
        count++;
        if (count == level)
        {
            cout << endl;
            level *= 2;
            count = 0;
        }
    }

    cout << endl;
}

void solve()
{
    memset(tree, 0, sizeof(tree));
    int k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(1, 0, n - 1, arr);

    int a, b, c;

    for (int i = 0; i < k; i++)
    {
        print();
        cout << "i: " << i << endl;
        cin >> a;
        if (a == 1)
        {
            cin >> b; // index of the element in the array
            // update the element at index b to 0
            update(b, 0, n - 1, 0, 1);
        }
        else if (a == 2)
        {
            cin >> b >> c;
            // update the element at index b to c
            update(b, 0, n - 1, c, 0);
        }
        else
        {
            cin >> b >> c;
            cout << "->>" << query(b, c, 0, n - 1, 1) << endl;
        }
    }
    print();
}

int main()
{
    int q;
    cin >> q;
    while (q--)
        solve();
}