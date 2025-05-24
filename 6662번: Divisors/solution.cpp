#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

class DivisorCalculator
{
private:
    static constexpr int MAX_N = 431;
    vector<int> primes;

    void generatePrimes()
    {
        vector<bool> isPrime(MAX_N + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i <= MAX_N; ++i)
        {
            if (isPrime[i])
            {
                primes.push_back(i);
                for (int j = i * i; j <= MAX_N; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }

    [[nodiscard]] int calculatePrimeExponent(int n, int prime) const noexcept
    {
        int exponent = 0;
        int power = prime;

        while (power <= n)
        {
            exponent += n / power;
            if (power > n / prime)
                break;
            power *= prime;
        }

        return exponent;
    }

public:
    DivisorCalculator()
    {
        generatePrimes();
    }

    [[nodiscard]] uint64_t countDivisors(int n, int k) const
    {
        if (k == 0 || k == n)
            return 1;
        uint64_t divisorCount = 1;

        for (const int prime : primes)
        {
            if (prime > n)
                break;

            const int exponentN = calculatePrimeExponent(n, prime);
            const int exponentK = calculatePrimeExponent(k, prime);
            const int exponentNMinusK = calculatePrimeExponent(n - k, prime);
            const int finalExponent = exponentN - exponentK - exponentNMinusK;

            if (finalExponent > 0)
            {
                divisorCount *= (finalExponent + 1);
            }
        }

        return divisorCount;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const DivisorCalculator calculator;
    int n, k;

    while (std::cin >> n >> k)
    {
        std::cout << calculator.countDivisors(n, k) << '\n';
    }

    return 0;
}