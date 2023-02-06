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

using namespace std;

string s = "";
string w = "";

void bruteForce(string s, string w)
{

    int W = 0;
    for (int i = 0; i < w.size(); i++)
        W += (int)w[i];

    bool found = true;
    int S = 0;
    for (int i = 0; i < s.size() - w.size() + 1; i++)
    {
        found = true;
        S = 0;

        for (int j = 0; j < w.size(); j++)
            S += (int)s[i + j];

        if (S == W)
        {
            for (int k = 0; k < w.size(); k++)
            {
                if (s[i + k] != w[k])
                {
                    found = false;
                    break;
                }
            }
        }
        else
        {
            found = false;
        }

        if (found)
        {
            cout << " B+";
            // cout << "Brute Force: Found at index: " << i;
            break;
        }
        else if (i == s.size() - w.size())
        {
            cout << " B-";
            // cout << "Brute Force: Not found";
        }
    }
}

void rabinKarp(string s, string w)
{

    int W = 0;
    for (int i = 0; i < w.size(); i++)
        W += (int)w[i];

    bool found = true;
    int S = 0;
    for (int i = 0; i < w.size(); i++)
        S += (int)s[i];
    for (int i = 0; i < s.size() - w.size() + 1; i++)
    {
        if (i != 0)
            S = S - (int)s[i - 1] + (int)s[i + w.size() - 1];

        found = true;

        if (S == W)
        {
            for (int k = 0; k < w.size(); k++)
            {
                if (s[i + k] != w[k])
                {
                    found = false;
                    break;
                }
            }
        }
        else
        {
            found = false;
        }

        if (found)
        {
            cout << " R+";
            // cout << "Rabin Karp: Found at index: " << i;
            break;
        }
        else if (i == s.size() - w.size())
        {
            cout << " R-";
            // cout << "Rabin Karp: Not found";
        }
    }
}

void random(int S, int W, int MAX = 26, int START = 97)
{
    for (int i = 0; i < S; i++)
        s += (char)(rand() % MAX + START);
    for (int i = 0; i < W; i++)
        w += (char)(rand() % MAX + START);
}
int main()
{

    srand(time(NULL));
    int TIME = 0;
    int q = 30;

    clock_t start, end;

    // fastio
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int S_SIZE = 1e6;
    int W_SIZE = 30;
    int MAX = 2;

    for (int QQQ = 0; QQQ < q; QQQ++)
    {

        //  random seed

        cout << QQQ + 1 << "/" << q;
        random(S_SIZE, W_SIZE, MAX);
        start = clock();
        bruteForce(s, w);
        end = clock();
        cout << " " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms\n";
        TIME += (end - start) / (double)(CLOCKS_PER_SEC / 1000);
        s = "";
        w = "";
    }
    int BruteForceTime = TIME;
    TIME = 0;
    for (int QQQ = 0; QQQ < q; QQQ++)
    {

        //  random seed

        cout << QQQ + 1 << "/" << q;
        random(S_SIZE, W_SIZE, MAX);
        start = clock();
        rabinKarp(s, w);
        end = clock();
        cout << " " << (end - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms\n";
        TIME += (end - start) / (double)(CLOCKS_PER_SEC / 1000);
        s = "";
        w = "";
    }

    cout << "Brute Force: Average time: " << BruteForceTime / q << " ms\n";
    cout << "Rabin Karp: Average time: " << TIME / q << " ms\n";

    return 0;
}