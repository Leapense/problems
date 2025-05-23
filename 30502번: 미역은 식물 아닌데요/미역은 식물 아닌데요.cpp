#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int N, M;
    cin >> N >> M;

    vector<bool> P_specified(N + 1, false);
    vector<int> P_value(N + 1, 0);
    vector<bool> M_specified(N + 1, false);
    vector<int> M_value(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int a;
        char b;
        int c;

        cin >> a >> b >> c;
        if (b == 'P') {
            P_specified[a] = true;
            P_value[a] = c;
        }
        else if (b == 'M') {
            M_specified[a] = true;
            M_value[a] = c;
        }
    }

    int min_count = 0, max_count = 0;

    for (int a = 1; a <= N; a++) {
        if (P_specified[a] && P_value[a] == 1 && M_specified[a] && M_value[a] == 0) {
            min_count++;
        }

        bool can_P1 = !P_specified[a] || P_value[a] == 1;
        bool can_M0 = !M_specified[a] || M_value[a] == 0;
        if (can_P1 && can_M0) {
            max_count++;
        }
    }
    cout << min_count << " " << max_count;

    return 0;
}