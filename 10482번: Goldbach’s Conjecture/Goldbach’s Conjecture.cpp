#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MAX = 32000;

    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= MAX; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }

    int T;
    cin >> T;
    while (T--)
    {
        int x;
        cin >> x;

        vector<pair<int, int>> representations;
        for (auto p : primes)
        {
            if (p > x)
                break;
            int q = x - p;
            if (p <= q && q <= MAX && isPrime[q])
            {
                representations.push_back({p, q});
            }
        }

        cout << x << " has " << representations.size() << " representation(s)\n";

        for (auto &pr : representations)
        {
            cout << pr.first << "+" << pr.second << "\n";
        }
        cout << "\n";
    }

    return 0;
}