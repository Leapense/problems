#include <bits/stdc++.h>
using namespace std;

struct Fish {
    long long mass;
    long long age;
    int idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<Fish> fishes(n);
    for (int i = 0; i < n; i++) {
        cin >> fishes[i].mass >> fishes[i].age;
        fishes[i].idx = i;
    }

    sort(fishes.begin(), fishes.end(), [](const Fish &a, const Fish &b) {
        if (a.mass == b.mass) return a.age < b.age;
        return a.mass < b.mass;
    });

    vector<int> death_day(n, -1);

    vector<Fish> current = fishes;

    int day = 0;

    while ((int)current.size() > 1) {
        day++;
        int count = (int)current.size();
        int half = count / 2;
        bool odd = (count % 2 == 1);

        for (int i = 0; i < half; i++) {
            death_day[current[i].idx] = day;
        }

        int start_pred;

        if (odd) {
            start_pred = half + 1;
            death_day[current[half].idx] = day;
        } else {
            start_pred = half;
        }

        int pred_count = (int)current.size() - start_pred;

        for (int i = 0; i < half; i++) {
            int pred_idx = start_pred + i;
            long long gain = current[i].mass / 2;
            current[pred_idx].mass += gain;
        }

        vector<Fish> next_gen;
        next_gen.reserve(pred_count);
        for (int i = 0; i < pred_count; i++) {
            next_gen.push_back(current[start_pred + i]);
        }

        sort(next_gen.begin(), next_gen.end(), [](const Fish &a, const Fish &b) {
            if (a.mass == b.mass) return a.age < b.age;
            return a.mass < b.mass;
        });

        current.swap(next_gen);
    }

    if (current.size() == 1) {
        death_day[current[0].idx] = day + 1;
    }

    if (current.empty()) {

    }

    int z; cin >> z;

    while(z--)
    {
        int r; long long x;

        cin >> r >> x;

        r--;

        if (death_day[r] == -1) {
            if (x >= 0) {
                cout << "NIE\n";
            } else {
                cout << "TAK\n";
            }
        } else {
            if (death_day[r] <= x) cout << "NIE\n";
            else cout << "TAK\n";
        }
    }

    return 0;
}