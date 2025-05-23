#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> levels(n);

    for (int i = 0; i < n; ++i) {
        cin >> levels[i];
    }

    int max_level = *max_element(levels.begin(), levels.end());
    long long total_gold = 0;
    for (int level : levels) {
        total_gold += level;
    }

    if (n == 1) {
        cout << 0 << endl;
    } else {
        total_gold += max_level * (n - 2);
        cout << total_gold << endl;
    }

    return 0;
}