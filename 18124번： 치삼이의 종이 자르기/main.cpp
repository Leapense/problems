#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    unsigned long long N;
    cin >> N;

    if (N == 1)
    {
        cout << 0;
        return 0;
    }

    int d = 0;

    while ((1ULL << d) < N)
        d++;
    unsigned long long optA = (1ULL << d) - 1;
    unsigned long long half = (N + 1) / 2;
    int d2 = 0;
    while ((1ULL << d2) < half)
        d2++;
    unsigned long long optB = ((1ULL << d2) - 1) + half;
    cout << min(optA, optB) << "\n";

    return 0;
}