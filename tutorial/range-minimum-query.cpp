
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define int long long

using namespace std;

const int N = 500005;
const int LOG = 17;

int lookup[N][LOG];

int query(int l, int r)
{
    int length = r - l + 1; // the reason we add 1 is because we want the length of the subarray and not the index of the last element

    //    //int k = 0;
    //    //while ((1<< k + 1) <= length) // we are finding the largest power of 2 that is less than or equal to the length of the subarray
    //    //    k++;
    // we can also do this in O(1) time using the log function
    int k = log2(length);

    // a step by step example for the while loop
    // lets say the length of the subarray is 7
    // now we will loop over all powers of 2
    // 1: 2^1 = 2, its less than 7 so we will increment k
    // 2: 2^2 = 4, its less than 7 so we will increment k
    // 3: 2^3 = 8, its greater than 7 so we will break out of the loop
    // we are essentially finding the largest power of 2 that is less than or equal to the length of the subarray
    // log2(7) = 2.807
    // so the largest power of 2 that is less than or equal to 7 is 2^2 = 4

    // an example to make it clear
    // lets say the length of the subarray is 7
    // 7 = 2^2 + 2^1 + 2^0
    // so the largest power of 2 that is less than or equal to 7 is 2^2
    // so we will use the precomputed values for the subarrays of size 2^2
    // and we will find the minimum of these two subarrays
    // and that will be the minimum of the subarray of size 7

    // what we are doing here can be illustrated by this example:
    // lets say the length of the subarray is 7
    // k = 2 (2^2 = 4)
    // so the segment we are looking at is:
    // ||||||| (7 elements)
    // we first look at the first part of the segment:
    // -||||- |||  find the minimum of these two subarrays
    // and then we look at the second part of the segment:
    // ||| -||||-  find the minimum of these two subarrays
    // and then we take the minimum of these two values
    // and that will be the minimum of the subarray of size 7
    // there are some overlapping parts but they don't matter because we are just finding the minimum
    // so minimum 5,5 = 5
    // we counted 5 twice but that doesn't matter because we are just finding the minimum

    return min(lookup[l][k], lookup[r - (1 << k) + 1][k]);
}

int32_t main()
{

    // fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;

    int n, q;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        lookup[i][0] = arr[i];
    }

    // precomputation
    for (int k = 1; k <= LOG; k++)
    {                                           // essentially looping over powers of 2
        for (int i = 0; i + (1 << k) <= n; i++) // looping over all possible subarrays of size 2^k
        {
            lookup[i][k] = min(lookup[i][k - 1], lookup[i + (1 << (k - 1))][k - 1]);
            // lets say we have a subarray of size 2^k
            // we can split it into two subarrays of size 2^(k-1)
            // we can find the minimum of these two subarrays
            // and store it in the lookup table
            // for example if k = 3
            // |||||||| so there are 8 elements
            // we can split it into two subarrays of size 4 like this:
            // |||| ||||
            // and we can find the minimum of these two subarrays
            // and store it in the lookup table for the subarray of size 8
        }
    }
    cin >> q;
    int a, b;

    while (q--)
    {
        cin >> a >> b;
        cout << query(a, b) << endl;
    }
    return 0;
}