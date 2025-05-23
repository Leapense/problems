#include <iostream>

using namespace std;
class Solution
{
public:
    void solve()
    {
        int a, b, c, d, e;
        cin >> a >> b >> c;
        cin >> d >> e;

        long long A = (long long)a * d * (d - 1);
        long long B = 2LL * a * d * e;
        long long C = (long long)a * e * e + b * e + c - (long long)c * d - e;

        if (A == 0 && B == 0 && C == 0)
        {
            cout << "Nice";
            return;
        }
        if (A == 0)
        {
            if (B != 0)
            {
                cout << "Remember my character";
            }
            else
            {
                cout << "Head on";
            }

            return;
        }

        long long D = B * B - 4LL * A * C;
        if (D > 0)
            cout << "Go ahead";
        else if (D == 0)
            cout << "Remember my character";
        else
            cout << "Head on";
    }
};

int main()
{
    Solution sol;
    sol.solve();

    return 0;
}