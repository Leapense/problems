#include <iostream>
#include <vector>
using namespace std;
constexpr long long MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<int> tests(T);
    int maxN = 0;

    for (int i = 0; i < T; i++)
    {
        cin >> tests[i];
        if (tests[i] > maxN)
            maxN = tests[i];
    }

    vector<long long> fib(maxN + 2, 0);
    fib[1] = 1;
    fib[2] = 1;

    for (int i = 3; i <= maxN + 1; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    for (auto n : tests)
        cout << fib[n + 1] << "\n";
    return 0;
}