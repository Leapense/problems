#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> D(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> D[i];
    }

    vector<long long> prefix(N);
    prefix[0] = 0;
    for (int i = 1; i < N; i++)
    {
        prefix[i] = prefix[i - 1] + D[i - 1];
    }

    long long minPrefix = *min_element(prefix.begin(), prefix.end());
    long long maxPrefix = *max_element(prefix.begin(), prefix.end());

    long long L = 1 - minPrefix;
    long long R = N - maxPrefix;

    if (L != R)
    {
        cout << -1;
        return 0;
    }

    long long x = L;
    for (int i = 0; i < N; i++)
    {
        cout << x + prefix[i] << (i + 1 == N ? "\n" : " ");
    }

    return 0;
}