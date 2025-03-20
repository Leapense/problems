#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100000;

vector<bool> sieveOfEratosthenes(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
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
    cin.tie(0);

    vector<bool> isPrime = sieveOfEratosthenes(MAX_N);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        int count = 0;

        for (int p = 2; p <= N / 2; p++)
        {
            if (isPrime[p] && isPrime[N - p])
            {
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}