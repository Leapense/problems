#include <iostream>
#include <vector>
using namespace std;

using ull = unsigned long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<ull> subjects(N, 0);

    for (int i = 0; i < N; i++)
    {
        int k;
        cin >> k;

        ull mask = 0;
        for (int j = 0; j < k; j++)
        {
            int t;
            cin >> t;
            mask |= (1ULL << (t - 1));
        }

        subjects[i] = mask;
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int p;
        cin >> p;

        ull studentMask = 0;

        for (int j = 0; j < p; j++)
        {
            int q;
            cin >> q;
            studentMask |= (1ULL << (q - 1));
        }
        int cnt = 0;
        for (auto s : subjects)
        {
            if ((studentMask & s) == s)
                cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}