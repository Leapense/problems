#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string frac1, frac2, frac3;
    cin >> frac1 >> frac2 >> frac3;

    int p1, q1, b, p2, q2;

    size_t pos = frac1.find('/');
    p1 = stoi(frac1.substr(0, pos));
    q1 = stoi(frac1.substr(pos + 1));

    pos = frac2.find('/');
    b = stoi(frac2.substr(pos + 1));

    pos = frac3.find('/');
    p2 = stoi(frac3.substr(0, pos));
    q2 = stoi(frac3.substr(pos + 1));

    int start = (p1 * b) / q1 + 1;

    bool found = false;
    int ans = -1;

    for (int a = start; a <= p2 * b; a++)
    {
        if (p1 * b < a * q1 && a * q2 < p2 * b)
        {
            ans = a;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << -1;
    }
    else
    {
        cout << ans << "/" << b;
    }

    return 0;
}