#include <bits/stdc++.h>
using namespace std;

int hexDistance(int x, int y)
{
    int X = x;
    int Z = y;
    int Y = -X - Z;
    return max({abs(X), abs(Y), abs(Z)});
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        cout << hexDistance(x, y) << "\n";
    }

    return 0;
}