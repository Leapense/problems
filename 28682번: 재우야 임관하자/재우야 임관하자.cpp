#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int n;
    cin >> n;

    vector<string> subjects = {"swimming", "bowling", "soccer"};
    vector<string> initial_choices(n, "swimming");

    for (int i = 0; i < n; ++i) {
        cout << initial_choices[i];
        if (i != n - 1) cout << ' ';
    }

    cout << "\n";
    cout.flush();

    vector<string> revealed_Fs(n);

    for (int i = 0; i < n; ++i) {
        cin >> revealed_Fs[i];
    }

    vector<string> final_choices(n);

    for (int i = 0; i < n; ++i) {
        for (const string& subj : subjects) {
            if (subj != initial_choices[i] && subj != revealed_Fs[i]) {
                final_choices[i] = subj;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << final_choices[i];
        if (i != n - 1) cout << ' ';
    }

    cout << "\n";
    cout.flush();

    return 0;
}