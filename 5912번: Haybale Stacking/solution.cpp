#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    // Difference array D[1..N+1]
    vector<int> diff(N + 2, 0);
    for (int i = 0; i < K; i++)
    {
        int A, B;
        cin >> A >> B;
        diff[A] += 1;
        diff[B + 1] -= 1;
    }

    // Since max height ≤ K, we use a counting array of size K+1
    vector<int> cnt(K + 1, 0);
    int current = 0;
    for (int i = 1; i <= N; i++)
    {
        current += diff[i];
        // current is between 0 and K inclusive
        cnt[current]++;
    }

    // Find the median: the (N+1)/2-th height in sorted order
    int target = (N + 1) / 2;
    int cumulative = 0;
    for (int h = 0; h <= K; h++)
    {
        cumulative += cnt[h];
        if (cumulative >= target)
        {
            cout << h << "\n";
            break;
        }
    }

    return 0;
}
