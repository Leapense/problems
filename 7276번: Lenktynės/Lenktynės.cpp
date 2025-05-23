#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> current_order(N+1);
    for (int i = 1; i <= N; ++i) {
        cin >> current_order[i];
    }

    vector<int> pos(N + 1);
    for (int i = 1; i <= N; ++i) {
        pos[current_order[i]] = i;
    }

    int L;
    cin >> L;

    bool valid = true;
    int invalid_index = -1;

    for (int i = 1; i <= L; ++i) {
        int a, b;
        cin >> a >> b;

        if (pos[a] == pos[b] + 1) {
            current_order[pos[a]] = b;
            current_order[pos[b]] = a;

            pos[a] = pos[b];
            pos[b] = pos[b] + 1;
        } else {
            valid = false;
            invalid_index = i;

            for (int j = i + 1; j <= L; ++j) {
                int tmp1, tmp2;
                cin >> tmp1 >> tmp2;
            }
            break;
        }
    }

    if (valid) {
        cout << "TAIP\n";
        for (int i = 1; i <= N; ++i) {
            cout << current_order[i] << (i == N ? "\n" : " ");
        }
    } else {
        cout << "NE\n" << invalid_index;
    }

    return 0;
}