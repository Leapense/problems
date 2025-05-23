#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> charge(m + 1, 0);
    vector<int> current_trip(m + 1, 0);

    for (int event = 0; event < k; event++) {
        int p, c;
        cin >> p >> c;

        if (current_trip[c] == 0) {
            current_trip[c] = p;
        } else {
            int start_pier = current_trip[c];
            if (start_pier == p) {
                charge[c] += 100;
            } else {
                charge[c] += abs(start_pier - p);
            }

            current_trip[c] = 0;
        }
    }

    for (int c = 1; c <= m; c++) {
        if (current_trip[c] != 0) {
            charge[c] += 100;
        }
    }

    for (int c = 1; c <= m; c++) {
        cout << charge[c] << (c == m ? '\n' : ' ');
    }

    return 0;
}