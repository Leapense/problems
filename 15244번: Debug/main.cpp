#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> freq(N, 0);
    int x;

    for (int i = 0; i < K; i++)
    {
        cin >> x;
        freq[x]++;
    }

    vector<int> seq(N, 0);
    for (int jump = 1; jump < N; jump++)
    {
        if (freq[jump] == 0)
        {
            continue;
        }
        for (int j = 0; j < N; j += jump)
        {
            seq[j] += freq[jump];
        }
    }

    vector<long long> prefix(N, 0);
    prefix[0] = seq[0];
    for (int i = 1; i < N; i++)
    {
        prefix[i] = prefix[i - 1] + seq[i];
    }

    int Q;
    cin >> Q;

    while (Q--)
    {
        int L, R;
        cin >> L >> R;

        long long ans = prefix[R] - (L > 0 ? prefix[L - 1] : 0);
        cout << ans << "\n";
    }

    return 0;
}