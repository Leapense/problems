#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long x, y;
    cin >> x >> y;

    while (x > 0 || y > 0)
    {
        int rx = x % 3;
        int ry = y % 3;
        if (rx == 1 && ry == 0)
        {
        }
        else if (rx == 0 && ry == 1)
        {
        }
        else
        {
            cout << 0;
            return 0;
        }
        x /= 3;
        y /= 3;
    }

    cout << 1;
    return 0;
}