#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    unsigned long long ans = 1;

    if (N % 2 == 0)
    {
        for (int i = 1; i <= N / 2; i++)
        {
            ans *= (2 * i - 1);
        }
    }
    else
    {
        ans = N;
        for (int i = 1; i <= (N - 1) / 2; i++)
        {
            ans *= (2 * i - 1);
        }
    }

    cout << ans;

    return 0;
}