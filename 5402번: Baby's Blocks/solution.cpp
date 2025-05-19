#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

static ull fact[21];

ull solve_case(const string &W)
{
    int n = W.size();
    ull rank = 0;

    array<int, 26> freq{};
    for (char c : W)
        freq[c - 'A']++;

    for (int i = 0; i < n; i++)
    {
        int curr = W[i] - 'A';

        for (int c = 0; c < curr; c++)
        {
            if (freq[c] == 0)
                continue;
            freq[c]--;
            ull ways = fact[n - i - 1];
            for (int k = 0; k < 26; k++)
            {
                if (freq[k] > 1)
                    ways /= fact[freq[k]];
            }

            rank += ways;

            freq[c]++;
        }

        freq[curr]--;
    }

    return rank;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i <= 20; i++)
        fact[i] = fact[i - 1] * i;

    int T;
    cin >> T;

    while (T--)
    {
        string W;
        cin >> W;
        cout << solve_case(W) << "\n";
    }

    return 0;
}