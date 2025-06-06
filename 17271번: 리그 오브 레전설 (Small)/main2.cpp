#include <iostream>
#include <vector>
#ifdef UNIT_TEST
#include <sstream>
#include <cassert>
#include <string>
#endif

const int MOD = 1'000'000'007;

long long modExp(long long base, long long exp, int mod)
{
    long long result = 1;
    base %= mod;

    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }

    return result;
}

void precomputeFactorials(int n, std::vector<long long> &fact, std::vector<long long> &invFact)
{
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[n] = modExp(fact[n], MOD - 2, MOD);

    for (int i = n - 1; i >= 0; --i)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r, const std::vector<long long> &fact, const std::vector<long long> &invFact)
{
    if (r < 0 || r > n)
        return 0;
    return ((fact[n] * invFact[r]) % MOD * invFact[n - r]) % MOD;
}

void solve()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    int maxFactorial = N;

    std::vector<long long> fact(maxFactorial + 1), invFact(maxFactorial + 1);
    precomputeFactorials(maxFactorial, fact, invFact);

    long long answer = 0;

    for (int y = 0; y <= N / M; ++y)
    {
        int x = N - M * y;
        int total = x + y;
        answer = (answer + nCr(total, y, fact, invFact)) % MOD;
    }

    std::cout << answer << "\n";
}

#ifdef UNIT_TEST
void runTest(const std::string &input, const std::string &expectedOutput)
{
    std::streambuf *origCin = std::cin.rdbuf();
    std::istringstream iss(input);
    std::cin.rdbuf(iss.rdbuf());

    std::ostringstream oss;
    std::streambuf *origCout = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    solve();

    std::cout.rdbuf(origCout);
    std::cin.rdbuf(origCin);

    assert(oss.str() == expectedOutput);
}

void runAllTests()
{
    runTest("1 2\n", "1\n");
    runTest("4 2\n", "5\n");
    runTest("3 2\n", "3\n");
    runTest("10 2\n", "89\n");
    runTest("10 3\n", "28\n");
    std::cout << "All test cases passed.\n";
}
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef UNIT_TEST
    runAllTests();
#else
    solve();
#endif

    return 0;
}