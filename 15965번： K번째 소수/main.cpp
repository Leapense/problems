#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    int maxVal = 8000000;

    vector<bool> isPrime(maxVal + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= maxVal; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxVal; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= maxVal; i++)
    {
        if (isPrime[i] && ++count == K)
        {
            cout << i;
            break;
        }
    }

    return 0;
}