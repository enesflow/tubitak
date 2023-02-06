#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board = {
    {1, 8, 0},
    {4, 3, 2},
    {5, 6, 7}};

// check if the board is in the goal state
bool check()
{
    int j = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 2 && j == 2 && board[i][j] == 0)
                return true;
            if (board[i][j] != j)
                return false;
        }
    }
    return true;
}

// print the board
void print()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// use dfs to find the solution
void dfs(int level = 0, pair<int, int> prev = {-1, -1})
{
}

int main()
{
    dfs();
    print();
    cout << check() << endl;
    return 0;
}
