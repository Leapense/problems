#include <bits/stdc++.h>
using namespace std;

struct Person {
    long long f;
    long long d;
    int idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<Person> people(n);
    for (int i = 0; i < n; i++) cin >> people[i].f >> people[i].d, people[i].idx = i;
    sort(people.begin(), people.end(), [&](const Person& a, const Person& b) -> bool {
        return a.f < b.f;
    });

    vector<long long> counts(n, 0);
    long long prev_d = -1;

    for (auto &p : people) {
        long long start = max(p.f, prev_d);
        long long end = p.d;

        if (start < end) counts[p.idx] += end - start;
        prev_d = max(prev_d, end);
    }

    for (auto c : counts) cout << c << "\n";

    return 0;
}