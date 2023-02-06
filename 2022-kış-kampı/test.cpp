#include <iostream>

using namespace std;
int a()
{
    int x = 2;
    return ++x;
}
int main()
{
    cout << a();
    return 0;
}