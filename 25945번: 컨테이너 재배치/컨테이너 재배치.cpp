#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> containers(n);
    long long total = 0;

    for (int i = 0; i < n; ++i) {
        cin >> containers[i];
        total += containers[i];
    }

    int base = total / n;
    int r = total % n;

    sort(containers.begin(), containers.end(), greater<int>());

    long long moves = 0;

    for (int i = 0; i < r; ++i) {
        if (containers[i] > base + 1) {
            moves += containers[i] - (base + 1);
        }
    }

    for (int i = r; i < n; ++i) {
        if (containers[i] > base) moves += containers[i] - base;
    }

    cout << moves;
    return 0;
}