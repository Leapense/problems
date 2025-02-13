#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;

    int total = 1 << n;
    int x = total - r + 1;

    int wins = 0;
    while ((1 << (wins + 1)) <= x)
    {
        wins++;
    }

    cout << wins + 1 << "\n";

    return 0;
}