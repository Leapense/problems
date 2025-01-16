#include <bits/stdc++.h>
using namespace std;

struct Glass {
    int index;
    long long Ti;
    long long Zi;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Glass> glasses(N);

    long long total_liquid = 0;
    for (int i = 0; i < N; i++) {
        cin >> glasses[i].Ti >> glasses[i].Zi;
        glasses[i].index = i;
        total_liquid += glasses[i].Ti;
    }

    sort(glasses.begin(), glasses.end(), [&](const Glass &a, const Glass &b) -> bool {
        if (a.Zi != b.Zi) {
            return a.Zi > b.Zi;
        }
        return a.index < b.index;
    });

    vector<long long> final_amounts(N, 0);
    long long remaining_liquid = total_liquid;
    for (auto &glass : glasses) {
        if (remaining_liquid == 0) {
            break;
        }

        long long assign = min(glass.Zi, remaining_liquid);
        final_amounts[glass.index] = assign;
        remaining_liquid -= assign;
    }

    int used_glasses = 0;
    for (int i = 0; i < N; i++) if (final_amounts[i] > 0) used_glasses++;
    int empty_glasses = N - used_glasses;

    cout << empty_glasses << "\n";
    for (int i = 0; i < N; i++) {
        cout << final_amounts[i];
        if (i != N - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}