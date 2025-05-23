#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    string buffers;
    string line;

    while (cin >> line)
    {
        buffers += line;
    }

    if (N < K)
    {
        cout << 0;
        return 0;
    }

    vector<int> sum(N + 1, 0), lock(N + 1, 0);

    for (int i = 0; i < N; i++)
    {
        sum[i + 1] = sum[i];
        lock[i + 1] = lock[i];
        if (buffers[i] == '*')
        {
            lock[i + 1]++;
        }
        else
        {
            sum[i + 1] += buffers[i] - '0';
        }
    }

    int ans = 0;
    int best = INT_MAX;
    for (int i = 0; i <= N - K; i++)
    {
        if (lock[i + K] - lock[i] == 0)
        {
            int s = sum[i + K] - sum[i];
            if (s < best)
            {
                best = s;
                ans = i + 1;
            }
        }
    }

    cout << (best == INT_MAX ? 0 : ans);
    return 0;
}