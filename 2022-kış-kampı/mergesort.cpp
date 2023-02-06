#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> arr;

// binary search to find the largest smaller number of the last elemenets of the arrays in arr

int binarySearch(vector<int> &v, int x)
{
    int l = 0, r = v.size(), ans = v.size();
    r--;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] > x)
        {
            l = mid + 1;
        }
        else
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
    }
    return ans;
}

int32_t main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> ans;
    int n;
    cin >> n;
    vector<int> v;
    int SIZE = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int index = binarySearch(v, x);
        if (index == (int)v.size())
        {
            ans.push_back({x});
            v.push_back(x);
        }
        else
        {
            ans[index].push_back(x);
            v[index] = x;
        }
    }
    for (auto &v : ans)
    {
        for (auto &x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}