#include <iostream>
using namespace std;

int main()
{
    unsigned long long k;
    cin >> k;

    unsigned long long n = k - 1;
    int cnt = 0;

    while (n)
    {
        cnt += n & 1;
        n >>= 1;
    }
    cout << (cnt & 1 ? 1 : 0);
    return 0;
}