#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXP = 1000;
    vector<bool> isPrime(MAXP + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= MAXP; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAXP; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= MAXP; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }

    while (true)
    {
        long long n;
        cin >> n;

        if (!cin || n == -1)
            break;
        long long temp = n;
        bool valid = true;

        for (int p : primes)
        {
            if ((long long)p * p > temp)
                break;

            while (temp % p == 0)
            {
                if ((p % 10 != 3) && (p != 3))
                {
                    valid = false;
                    break;
                }

                temp /= p;
            }
            if (!valid)
                break;
        }

        if (valid && temp > 1)
        {
            if (((temp % 10) != 3) && (temp != 3))
                valid = false;
        }

        cout << n << (valid ? " YES" : " NO") << "\n";
    }

    return 0;
}