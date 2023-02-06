#include <bits/stdc++.h>

/*
                ..  ...:::::::...  ..
              ....:^~~~!!!!!!~~~~^:.....
             ...:~!!!~~~~!!~~~~~~~~~^:....
            ...:~!~~~~!~~^^^::::::::::::::::..
           ....^~~~~~~~^:::~!!777777?JJ??7!~:::.
           ...:^~~~~~~:::!?PGGGGGGGB@@@@@@@&G!:::
          ....^^~~~~~:::!?YGGGGGGGGGGBB##&&&#P^:::
     ........:^^~~~~~:::7??YPGGGGGGGGGGGGGGGGP~:::
  ..:^~~~^...:^~~~~~~:::!J???JY55PPPPPPPPP55YJ~:::
  ..~~~~~^...^^~~~~~~^::^7???????????JJJJ???7!:::.
 ...^^^^^:...^^~~~~~~~^:::^!77????????777!~^^:::.
 ..:^^^^^:...^^~~~~~~~~~^::::::^^^^^^^:::::::..
 ..:^^^^^:...^^^~~~~~~~!~~~~~^^^^^^^^^^^~~~~...
 ..:^^^^^:...^^^~~~~~~~~~~~!!!!!!!!!!!!!!!!~...
...:^^^^^:...^^^~!~~~~~~~~~~~~~~~~~~~~~~~~!~...
...:^^^^^:...^^^^~~~~~~~~~~~~~~~~~~~~~~~~~~^...
...:^^^^^:...^^^^^~!~~~~~~~~~~~~~~~~~~~~!~^^...
 ..:^^^^^:...^^^^^^~~~~~~~~~~~~~~~~~~~~~~^^:...
 ...^^^^^:...^^^^^^^^^~~~~~~~~~~~~~~~~~^^^^:...
 ...:^^^^:...:^^^^^^^^^^^^^^~~~~~^^^^^^^^^^...
  ...^^^^^...:^^^^^^^^^^^^^^^^^^^^^^^^^^^^^...
   ..........:^^^^^^^^^^^:::::::::::::^^^^:...
          ...:^^^^^^^^^^: .........::^^^^^...
           ..:^^^^^^^^^^:..  ...:^^^^^^^^^...
           ...^^^^^^^^^^:... ...:^^^^^^^^:..
          ....^^^^^^^^^^...:~:...:^^^^^^:....
      .:^^^...^^^^^^^^^^...:~^.......... ..:~^^^:.
     :~~~~~:...::::::......^~~~^:::::::::^^~~~~~~^
      .:^^^~^:.........::^~~~~~~~~~~~~~~~~~~^^^:.
          ...:::::^^^^^~~~^^^^^^^^^^^^^:::...

*/

// optimize for speed
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
int ans = 0;
#define int long long

// fastpow
int fastpow(int a, int b)
{

    int res = 1;
    while (b > 0)
    {
        if (b & 1) // b % 2 == 1
            res = res * a;
        a = a * a;
        b >>= 1; // b /= 2
    }
    return res;
}

void rabinKarp(string s, string w)
{
    // Copilot yazdı anlatamam nasıl çalıştığını ama genel mantığı şu olmalı
    // s = "abcabcabc"
    // w = "abc"
    // h = [0, 1, 5, 14, 14, 15, 19, 28, 37]
    // h_w = 14
    // h[0 + 3] - h[0] = 14
    // h[1 + 3] - h[1] = 15
    // h[2 + 3] - h[2] = 19
    // ...
    // böyle prefix sum gibi bişey yapıyor
    // aslnıda evet prefix sum yapıyor
    // daha hızlsını yazmıştım ben nasıl çalışmadı ya

    int n = s.size();
    int m = w.size();

    int p = 31;
    int p_pow = 1;
    vector<int> h(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        h[i + 1] = h[i] + (s[i] - 'a' + 1) * p_pow;
        p_pow *= p;
    }

    int h_w = 0;
    for (int i = 0; i < m; i++)
        h_w += (w[i] - 'a' + 1) * fastpow(p, i);

    for (int i = 0; i + m - 1 < n; i++)
    {
        int cur_h = h[i + m] - h[i];
        if (cur_h == h_w * fastpow(p, i))
            ans++;
    }
}
int32_t main()
{
    // fastio
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    string w;
    cin >> s >> w;

    if (w.size() > s.size())
    {
        cout << 0;
        return 0;
    }

    rabinKarp(s, w);

    cout << ans;
    return 0;
}