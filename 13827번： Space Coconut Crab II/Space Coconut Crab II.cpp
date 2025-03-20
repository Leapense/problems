#include <iostream>
#include <vector>

using namespace std;

vector<bool> sieve(int N)
{
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX_T = 30000;
    auto isPrime = sieve(MAX_T);

    vector<int> primes;

    for (int i = 2; i <= MAX_T; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }

    int T;

    while (cin >> T && T != 0)
    {
        int count = 0;
        int n = primes.size();

        for (int i = 0; i < n; ++i)
        {
            int p = primes[i];
            if (p * 3 > T)
                break;
            for (int j = i; j < n; ++j)
            {
                int q = primes[j];
                if (p + q * 2 > T)
                    break;
                int r = T - (p + q);

                if (r >= q && r < MAX_T + 1 && isPrime[r] && p + q > r)
                {
                    count++;
                }
            }
        }

        cout << count << "\n";
    }

    return 0;
}