#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x_s, y_s, x_t, y_t, x_p, y_p;
    cin >> x_s >> y_s;
    cin >> x_t >> y_t;
    cin >> x_p >> y_p;

    const int EXT = 1000000000;

    if ((x_s - x_p) * (x_t - x_p) > 0)
    {
        int Y;
        if (y_s > y_p)
            Y = EXT;
        else
            Y = -EXT;
        cout << 2 << "\n";
        cout << x_s << " " << Y << "\n";
        cout << x_t << " " << Y << "\n";
    }
    else if ((y_s - y_p) * (y_t - y_p) > 0)
    {
        int X;
        if (x_s > x_p)
            X = EXT;
        else
            X = -EXT;
        cout << 2 << "\n";
        cout << X << " " << y_s << "\n";
        cout << X << " " << y_t << "\n";
    }
    else
    {
        int X;
        if (x_s < x_p)
            X = -EXT;
        else
            X = EXT;
        cout << 3 << "\n";
        cout << X << " " << y_s << "\n";
        cout << X << " " << y_t << "\n";
        cout << x_t << " " << y_t << "\n";
    }

    return 0;
}