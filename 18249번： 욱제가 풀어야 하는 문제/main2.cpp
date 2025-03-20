#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
using namespace std;
constexpr long long MOD = 1000000007;

void solve()
{
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
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= maxN + 1; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
    for (auto n : tests)
        cout << fib[n + 1] << "\n";
}

#ifdef UNIT_TEST
void runTests()
{
    {
        string input = "2\n1\n2\n";
        string expected = "1\n2\n";
        stringstream in(input), out;
        streambuf *cinbuf = cin.rdbuf();
        streambuf *coutbuf = cout.rdbuf();
        cin.rdbuf(in.rdbuf());
        cout.rdbuf(out.rdbuf());
        solve();
        cin.rdbuf(cinbuf);
        cout.rdbuf(coutbuf);
        assert(out.str() == expected);
    }
    {
        string input = "1\n1\n";
        string expected = "1\n";
        stringstream in(input), out;
        streambuf *cinbuf = cin.rdbuf();
        streambuf *coutbuf = cout.rdbuf();
        cin.rdbuf(in.rdbuf());
        cout.rdbuf(out.rdbuf());
        solve();
        cin.rdbuf(cinbuf);
        cout.rdbuf(coutbuf);
        assert(out.str() == expected);
    }
}
#endif
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef UNIT_TEST
    runTests();
#else
    solve();
#endif
    return 0;
}