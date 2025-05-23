#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, A, B;
    cin >> N >> K >> A >> B;

    vector<int> pots(N, K);
    int groups = N / A;

    vector<vector<int>> groupList(groups, vector<int>());
    for (int i = 0; i < N; i++) groupList[i / A].push_back(i);

    int day = 0;

    while (1) {
        day++;
        int currentGroup = (day-1) % groups;
        for (auto &idx : groupList[currentGroup]) pots[idx] += B;
        for (auto &pot : pots) pot -= 1;
        bool dead = false;
        for (auto &pot : pots) if (pot <= 0) {dead = true; break;}
        if (dead) {
            cout << day;
            break;
        }
    }

    return 0;
}