#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> desks(N);

    for (auto &p : desks) cin >> p.first >> p.second;

    int max_count = 0;
    int best_grade = 1;

    for (int grade = 1; grade <= 5; grade++) {
        int current = 0;
        int local_max = 0;

        for (int i = 0; i < N; i++) {
            if (desks[i].first == grade || desks[i].second == grade) {
                current += 1;
                if (current > local_max) local_max = current;
            } else {
                current = 0;
            }
        }

        if (local_max > max_count || (local_max == max_count && grade < best_grade)) {
            max_count = local_max;
            best_grade = grade;
        }
    }
    cout << max_count << " " << best_grade << "\n";

    return 0;
}