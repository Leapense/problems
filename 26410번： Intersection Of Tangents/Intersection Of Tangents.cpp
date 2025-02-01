#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    long long x, y;
    long long xmin = 1e9, ymin = 1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        xmin = min(xmin, x);
        ymin = min(ymin, y);
    }

    cout << xmin << " " << ymin;

    return 0;
}