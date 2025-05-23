#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> current(n);
    for (int i = 0; i < n; i++) cin >> current[i];

    int count = 0;
    const int LIMIT = 1000;
    bool stabilized = false;

    while (count < LIMIT) {
        vector<long long> next(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (current[j] > current[i]) next[i]++;
            }
        }

        count++;

        bool same = true;

        for (int i = 0; i < n; i++) {
            if (current[i] != next[i])
            {
                same = false;
                break;
            }
        }

        if (same) {
            stabilized = true;
            break;
        }

        current = next;
    }

    if (stabilized) {
        cout << count;
    } else {
        cout << "-1";
    }

    return 0;
}