#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int N, L;
        cin >> N >> L;
        vector<string> outlets(N), devices(N);
        for (int i = 0; i < N; i++)
        {
            cin >> outlets[i];
        }

        unordered_set<string> deviceSet;
        for (int i = 0; i < N; i++)
        {
            cin >> devices[i];
            deviceSet.insert(devices[i]);
        }

        int best = L + 1;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                string mask(L, '0');
                for (int k = 0; k < L; k++)
                {
                    mask[k] = (outlets[i][k] == devices[j][k]) ? '0' : '1';
                }

                unordered_set<string> transformed;

                for (int k = 0; k < N; k++)
                {
                    string s = outlets[k];
                    for (int pos = 0; pos < L; pos++)
                    {
                        if (mask[pos] == '1')
                        {
                            s[pos] = (s[pos] == '0') ? '1' : '0';
                        }
                    }
                    transformed.insert(s);
                }

                if (transformed == deviceSet)
                {
                    int flips = 0;
                    for (char c : mask)
                        if (c == '1')
                            flips++;
                    best = min(best, flips);
                }
            }
        }

        cout << "Case #" << t << ": ";
        if (best == L + 1)
            cout << "NOT POSSIBLE";
        else
            cout << best;
        cout << "\n";
    }

    return 0;
}