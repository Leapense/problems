#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MAX = 200000;
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }
    int T;
    cin >> T;
    while (T--)
    {
        int K;
        cin >> K;
        int n = K;
        while (true)
        {
            bool found = false;
            for (int d = 2; d * d <= n; d++)
            {
                if (n % d == 0)
                {
                    int other = n / d;
                    if (d != other && isPrime[d] && other <= MAX && isPrime[other])
                    {
                        found = true;
                        break;
                    }
                }
            }
            if (found)
            {
                cout << n << "\n";
                break;
            }
            n++;
        }
    }
    return 0;
}