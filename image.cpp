#include <bits/stdc++.h>
#include <chrono>
#include <thread>

using namespace std;

void draw(int x, int y, int bob[])
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (i == bob[0] && j == bob[1])
                cout << "O";
            else
                cout << "_";
        }
        cout << endl;
    }
}

int main()
{
    int bob[] = {0, 0};
    int x = 10;
    int y = 10;
    while (true)
    {
        draw(x, x, bob);
        bob[0]++;
        if (bob[0] > y)
        {
            bob[0] = 0;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}