#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    const int pLimit = 20000000;
    const int sieveLimit = 40000001;

    vector<bool> isPrime(sieveLimit, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < sieveLimit; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < sieveLimit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    int answer = 0;

    for (int p = 2; p <= pLimit; p++)
    {
        if (isPrime[p])
        {
            long long q = 2LL * p + 1;

            if (q < sieveLimit && isPrime[q])
            {
                count++;
                if (count == k)
                {
                    answer = p;
                    break;
                }
            }
        }
    }

    cout << answer << "\n";

    return 0;
}