#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    vector<long long> divisors;

    for (long long i = 1; i * i <= C; i++)
    {
        if (C % i == 0)
        {
            divisors.push_back(i);
            if (i != C / i)
            {
                divisors.push_back(C / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end());

    for (auto n : divisors)
    {
        if (n % A == 0 && n % B != 0 && D % n != 0)
        {
            cout << n << "\n";

            return 0;
        }
    }

    cout << -1 << "\n";

    return 0;
}