#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int index;
    long long V, P, S, totalStats;
};

bool compare(const Student& a, const Student& b) {
    return a.totalStats > b.totalStats;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    long long V0, P0, S0;
    cin >> V0 >> P0 >> S0;

    long long totalStats0 = V0 + P0 + S0;

    vector<Student> students;
    students.push_back({0, V0, P0, S0, totalStats0});

    for (int i = 1; i <= N; ++i) {
        long long V, P, S;
        cin >> V >> P >> S;
        long long totalStats = V + P + S;
        if (totalStats <= totalStats0) {
            students.push_back({i, V, P, S, totalStats});
        }
    }

    sort(students.begin() + 1, students.end(), compare);

    int teamSize = min(M, static_cast<int>(students.size()));
    vector<int> result;

    for (int i = 0; i < teamSize; ++i) {
        result.push_back(students[i].index);
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << "\n";

    return 0;
}