#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    long long total_score = 0;
    vector<pair<int, long long>> tasks;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        if (s == "1") {
            int A;
            long long T;
            cin >> A >> T;

            tasks.emplace_back(A, T);
        }

        if (!tasks.empty()) {
            tasks.back().second -= 1;
            if (tasks.back().second == 0) {
                total_score += tasks.back().first;
                tasks.pop_back();
            }
        }
    }

    cout << total_score << endl;
    return 0;
}