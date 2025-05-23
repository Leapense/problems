#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    if (N == 1)
    {
        cout << 1 << "\n"
             << 1 << " " << 1 << "\n";
        return 0;
    }

    long long M = 2 * N - 2;
    cout << M << "\n";
    for (long long j = 1; j < N; j++)
    {
        cout << 1 << " " << j << "\n";
    }

    for (long long j = 1; j < N; j++)
    {
        cout << N << " " << j << "\n";
    }

    return 0;
}