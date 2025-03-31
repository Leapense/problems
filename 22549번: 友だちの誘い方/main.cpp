#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int maxGroup = N + 1;
    const int SIZE = 100002;

    vector<int> diff(SIZE, 0);

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        diff[a]++;
        if (b + 1 < SIZE) diff[b + 1]--;
    }

    vector<int> count(SIZE, 0);

    count[0] = diff[0];
    for (int i = 1; i < SIZE; i++) {
        count[i] = count[i - 1] + diff[i];
    }

    int ans = 0;
    for (int x = 0; x <= N; x++) {
        int groupSize = x + 1;
        if (groupSize < SIZE && count[groupSize] >= x) {
            ans = x;
        }
    }

    cout << ans << "\n";
    return 0;
}
