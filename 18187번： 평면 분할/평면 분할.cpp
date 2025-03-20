#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int k = N / 3;
    int r = N % 3;
    long long ans = 0;

    if (r == 0)
        ans = 3LL * k * k + 3LL * k + 1;
    else if (r == 1)
        ans = 3LL * k * k + 5LL * k + 2;
    else
        ans = 3LL * k * k + 7LL * k + 4;

    cout << ans << "\n";

    return 0;
}