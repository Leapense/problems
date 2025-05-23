#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<long long> b(n);
    for (auto &x : b) cin >> x;

    vector<vector<long long>> jobs(k + 1, vector<long long>());

    for (int i = 0; i < n; ++i) {
        int job = a[i];
        jobs[job].push_back(b[i]);
    }

    int missing_jobs = 0;
    vector<long long> extra_idlers;

    for (int j = 1; j <= k; ++j) {
        if (jobs[j].empty()) {
            missing_jobs += 1;
        } else {
            if (jobs[j].size() > 1) {
                sort(jobs[j].begin(), jobs[j].end(), greater<long long>());

                for (int m = 1; m < jobs[j].size(); ++m) {
                    extra_idlers.push_back(jobs[j][m]);
                }
            }
        }
    }

    if (missing_jobs == 0) {
        cout << "0\n";
        return 0;
    }

    sort(extra_idlers.begin(), extra_idlers.end());

    long long total_persuasion_time = 0;
    for (int i = 0; i < missing_jobs; ++i) {
        total_persuasion_time += extra_idlers[i];
    }

    cout << total_persuasion_time;

    return 0;
}