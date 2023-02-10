int lazy[0];
int tree[0];

int max(int a, int b)
{
    return a > b ? a : b;
}

void push(int node, int start, int end)
{
    if (lazy[node] == 0)
        return; // if we want to set the value of the node the == -1

    // if max range segment tree
    tree[node] += lazy[node];
    // if total range segment tree:
    // -> tree[node] += lazy[node] * start - end + 1;

    if (start != end) // if we didnt reach the bottom
    {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, int val)
{
    push(node, start, end);
    if (start > r || end < l || start > end || l > r)
        return;
    if (start >= l && end <= r)
    {
        lazy[node] += val;
        push(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, l, r, val);
    update(node * 2 + 1, mid + 1, end, l, r, val);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int start, int end, int l, int r)
{
    if (start > r || end < l || start > end || l > r)
        return 0;
    push(node, start, end);
    if (start >= l && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    return max(query(node * 2, start, mid, l, r), query(node * 2 + 1, mid + 1, end, l, r));
}