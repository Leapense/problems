#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 1; i < N; i++)
    {
        cout << i << " ";
    }

    long long S = (long long)N * (N - 1) / 2;

    cout << -S << " ";
    cout << 0 << "\n";

    return 0;
}