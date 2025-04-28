#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    if (!(cin >> N >> M))
        return 0;

    vector<long long> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    long long sum = 0;
    int left = 0, best = N + 1;

    for (int right = 0; right < N; ++right)
    {
        sum += a[right];

        while (sum >= M && left <= right)
        {
            best = min(best, right - left + 1);
            sum -= a[left++];
        }
    }

    if (best == N + 1)
    {
        cout << "NEPAVYKS\n";
    }
    else
    {
        cout << best << "\n";
    }

    return 0;
}