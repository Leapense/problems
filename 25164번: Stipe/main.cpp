#include <bits/stdc++.h>
using namespace std;

struct Person {
    int age_days;
    int pos;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<Person> people(N);
    for (int i = 0; i < N; ++i) {
        int G, M, D;
        cin >> G >> M >> D;
        int total_days = G * 360 + M * 30 + D;
        people[i] = {total_days, i};
    }

    vector<int> sorted_ages;
    for (const auto& p : people) {
        sorted_ages.push_back(p.age_days);
    }

    sort(sorted_ages.rbegin(), sorted_ages.rend());

    int age_limit = sorted_ages[K - 1];
    int vaccinated = 0, sent_home = 0;

    for (const auto& p : people) {
        if (vaccinated >= K) break;
        if (p.age_days >= age_limit) {
            vaccinated++;
        } else {
            sent_home++;
        }
    }

    cout << sent_home << "\n";

    return 0;
}
