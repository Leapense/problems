#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    int n = S.size();

    vector<vector<int>> pref(26, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        pref[S[i] - 'a'][i + 1] = 1;
    }

    for (int c = 0; c < 26; c++)
    {
        for (int i = 1; i <= n; i++)
        {
            pref[c][i] += pref[c][i - 1];
        }
    }

    int Q;
    cin >> Q;

    while (Q--)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        if (B - A != D - C)
        {
            cout << "NE\n";
            continue;
        }

        bool ok = true;

        for (int c = 0; c < 26; c++)
        {
            int cnt1 = pref[c][B] - pref[c][A - 1];
            int cnt2 = pref[c][D] - pref[c][C - 1];

            if (cnt1 != cnt2)
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "DA" : "NE") << "\n";
    }

    return 0;
}