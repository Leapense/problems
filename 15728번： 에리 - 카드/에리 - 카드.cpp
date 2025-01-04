#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> shared(N);
    for (auto &x : shared) cin >> x;

    vector<int> team(N);
    for (auto &x : team) cin >> x;

    int s_max = *max_element(shared.begin(), shared.end());
    int s_min = *min_element(shared.begin(), shared.end());

    vector<long long> C;

    for (auto t : team) {
        if (t > 0) {
            C.push_back((long long)t * s_max);
        } else if (t < 0) {
            C.push_back((long long)t * s_min);
        } else {
            C.push_back(0);
        }
    }

    sort(C.begin(), C.end(), greater<long long>());

    if (K >= N) {
        cout << 0;
        return 0;
    }

    cout << C[K];
    return 0;
}