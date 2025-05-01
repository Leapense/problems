#include <bits/stdc++.h>
using namespace std;

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    array<int, 10> freq{};

    int distinct = 0;
    int left = 0;
    int best = 0;

    for (int right = 0; right < N; right++)
    {
        if (freq[S[right]]++ == 0)
        {
            distinct++;
        }
        while (distinct > 2)
        {
            if (--freq[S[left]] == 0)
            {
                distinct--;
            }
            left++;
        }
        best = max(best, right - left + 1);
    }

    cout << best << "\n";
    return 0;
}
#endif