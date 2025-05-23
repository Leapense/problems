#include <iostream>
#include <vector>

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

int main()
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
    return 0;
}