#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int rounds = N - M + 1;
    vector<int> V(rounds);
    for (int i = 0; i < rounds; i++) {
        cin >> V[i];
    }

    deque<pair<int, int>> queue;
    deque<int> remaining;

    for (int i = 0; i < M; i++) {
        queue.push_back({i, a[i]});
    }

    for (int i = M; i < N; i++) {
        remaining.push_back(a[i]);
    }

    for (int v : V) {
        sort(queue.begin(), queue.end(), compare);

        int eliminate_index = v - 1;
        queue.erase(queue.begin() + eliminate_index);

        if (!remaining.empty()) {
            queue.push_back({N - remaining.size(), remaining.front()});
            remaining.pop_front();
        }
    }

    vector<int> result;

    for (auto& participant : queue) {
        result.push_back(participant.second);
    }

    sort(result.begin(), result.end());

    for (int skill : result) {
        cout << skill << " ";
    }

    return 0;
}