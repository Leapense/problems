#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        long long N;
        cin >> N;
        // Special case: center
        if (N == 1)
        {
            cout << "(0,0)\n";
            continue;
        }
        // Find the smallest odd m such that m^2 >= N
        long long m = ceil(sqrt((long double)N));
        if (m % 2 == 0)
            m++; // Ensure m is odd
        long long k = (m - 1) / 2;
        long long d = m * m - N;
        long long r, c;
        long long edge = m - 1;
        if (d < edge)
        {
            r = -k;
            c = k - d;
        }
        else if (d < 2 * edge)
        {
            r = -k + (d - edge);
            c = -k;
        }
        else if (d < 3 * edge)
        {
            r = k;
            c = -k + (d - 2 * edge);
        }
        else
        {
            r = k - (d - 3 * edge);
            c = k;
        }
        cout << "(" << r << "," << c << ")\n";
    }
    return 0;
}
