#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, M;
    cin >> N >> K >> M;

    list<int> people;

    for (int i = 1; i <= N; i++) people.push_back(i);
    vector<int> result;

    int direction = 1;
    int removed = 0;

    auto it = people.begin();
    for (int i = 1; i < K; i++) {
        if (it == people.end()) it = people.begin();
        ++it;
    }

    while (!people.empty()) {
        result.push_back(*it);
        it = people.erase(it);
        removed++;
        if (people.empty()) break;
        if (removed % M == 0) {
            direction *= -1;
        }
        if (direction == 1) {
            if (it == people.end()) it = people.begin();
            for (int i = 1; i < K; i++) {
                if (it == people.end()) it = people.begin();
                ++it;
            }
        } else {
            if (it == people.begin()) it = people.end();
            for (int i = 1; i < K; i++) {
                if (it == people.begin()) it = people.end();
                --it;
            }

            if (it == people.end()) it = people.begin();
        }
    }

    for (auto num : result) cout << num << "\n";

    return 0;
}