#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> A(N), B(M);

    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    vector<long long> d_list;

    for (auto a : A) {
        for (auto b : B) {
            if (b >= a) {
                d_list.push_back(b - a);
            }
        }
    }

    if (d_list.empty()) {
        cout << 0;
        return 0;
    }

    sort(d_list.begin(), d_list.end());
    long long current_d = d_list[0];
    int current_count = 1;
    long long best_d = current_d;
    int max_count = 1;

    for (int i = 1; i < d_list.size(); i++) {
        if (d_list[i] == current_d) {
            current_count++;
        } else {
            if (current_count > max_count || (current_count == max_count && current_d < best_d)) {
                max_count = current_count;
                best_d = current_d;
            }

            current_d = d_list[i];
            current_count = 1;
        }
    }
    if (current_count > max_count || (current_count == max_count && current_d < best_d)) {
        best_d = current_d;
    }

    cout << best_d;

    return 0;
}