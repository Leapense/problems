#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> perm(n);

    for (auto &x : perm) cin >> x;

    vector<int> swaps;

    bool changed = true;
    while (changed && swaps.size() <= n) {
        changed = false;
        for (int i = 0; i <= n - 3; i++) {
            if ((perm[i] < perm[i + 1] && perm[i + 1] < perm[i + 2]) || (perm[i] > perm[i + 1] && perm[i + 1] > perm[i + 2])) {
                swap(perm[i + 1], perm[i + 2]);
                swaps.push_back(i + 2);
                changed = true;
                if (swaps.size() > n) break;
            }
        }
    }

    bool chaotic = true;

    for (int i = 0; i <= n - 3; i++) {
        if ((perm[i] < perm[i + 1] && perm[i + 1] < perm[i + 2]) || (perm[i] > perm[i + 1] && perm[i + 1] > perm[i + 2])) {
            chaotic = false;
            break;
        }
    }

    if (chaotic && swaps.size() <= n) {
        cout << swaps.size() << "\n";
        for (auto x : swaps) cout << x << " ";
    } else {
        cout << -1;
    }

    return 0;
}