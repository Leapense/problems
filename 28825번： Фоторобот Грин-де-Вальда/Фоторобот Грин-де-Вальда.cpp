#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int n, m;
    cin >> n >> m;

    vector<string> p(n);
    vector<string> c(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    bool correct = true;

    for (int i = 0; i < n && correct; ++i) {
        for (int j = 0; j < m && correct; ++j) {
            char desired = p[i][j];
            int constraint = c[i][j] - '0';
            if (constraint == 0) {
                if (desired != '.') {
                    correct = false;
                }
            } else {
                if (desired == '.') {
                    continue;
                } else if (desired == 'R') {
                    if ((constraint & 1) == 0) {
                        correct = false;
                    }
                } else if (desired == 'G') {
                    if ((constraint & 2) == 0) {
                        correct = false;
                    }
                } else if (desired == 'B') {
                    if ((constraint & 4) == 0) {
                        correct = false;
                    }
                } else {
                    correct = false;
                }
            }
        }
    }

    if (correct) {
        cout << "correct\n";
    } else {
        cout << "incorrect\n";
    }

    return 0;
}