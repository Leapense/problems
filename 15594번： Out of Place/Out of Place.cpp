#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> current(N);
    for (auto &x : current) cin >> x;
    vector<int> sorted = current;

    sort(sorted.begin(), sorted.end());
    int cnt = 0;
    for (int i = 0; i < N; i++) if (current[i] != sorted[i]) cnt++;
    cout << (cnt == 0 ? 0 : cnt - 1);

    return 0;
}