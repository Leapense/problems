#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned long long N;
    cin >> N;
    unsigned long long total = 0, prevTotal = 0;
    int d = 0;
    while (true)
    {
        d++;
        unsigned long long count = 4;
        for (int i = 1; i < d; i++)
            count *= 5;
        total += count;
        if (total >= N)
            break;
        prevTotal = total;
    }
    unsigned long long offset = N - prevTotal - 1;
    unsigned long long result = 0;
    unsigned long long base = 1;
    int firstDigitVal = offset;
    for (int i = 1; i < d; i++)
    {
        base *= 5;
    }
    int digits[100];
    for (int i = 0; i < d; i++)
    {
        int cur = offset / base;
        offset %= base;
        if (i == 0)
        {
            int mapArr[4] = {2, 4, 6, 8};
            digits[i] = mapArr[cur];
        }
        else
        {
            int mapArr[5] = {0, 2, 4, 6, 8};
            digits[i] = mapArr[cur];
        }
        if (base)
            base /= 5;
    }
    for (int i = 0; i < d; i++)
    {
        result = result * 10 + digits[i];
    }
    cout << result;
    return 0;
}