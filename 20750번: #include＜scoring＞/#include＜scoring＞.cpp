#include <bits/stdc++.h>
using namespace std;

struct Contestant {
    int s;
    long long p;
    int f;
    int o;
    int index;
    int score;
};

int main() {
    int n;
    cin >> n;
    vector<Contestant> contestants(n);
    for (int i = 0; i < n; i++) {
        cin >> contestants[i].s >> contestants[i].p >> contestants[i].f >> contestants[i].o;
        contestants[i].index = i;
    }

    sort(contestants.begin(), contestants.end(), [&](const Contestant &a, const Contestant &b) -> bool {
        if (a.s != b.s) return a.s > b.s;
        if (a.p != b.p) return a.p < b.p;
        return a.f < b.f;
    });

    int score_table[31] = {0,100,75,60,50,45,40,36,32,29,26,24,22,20,18,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int rank = 1;
    int i = 0;

    while (i < n) {
        int j = i + 1;
        while (j < n && contestants[j].s == contestants[i].s && contestants[j].p == contestants[i].p && contestants[j].f == contestants[i].f) {
            j++;
        }

        int group_size = j - i;
        int starting_rank = rank;
        long long sum_scores = 0;

        for (int k = 0; k < group_size; k++) {
            int current_rank = starting_rank + k;
            if (current_rank <= 30) {
                sum_scores += score_table[current_rank];
            }
        }

        double average = (double)sum_scores / group_size;
        int ceil_avg = ceil(average);

        for (int k = i; k < j; k++) {
            contestants[k].score = ceil_avg;
        }

        rank += group_size;
        i = j;
    }

    vector<int> final_scores(n, 0);
    for (auto &c : contestants) {
        final_scores[c.index] = c.score + (c.o == 1 ? 1 : 0);
    }

    for (int i = 0; i < n; i++) cout << final_scores[i] << "\n";

    return 0;
}